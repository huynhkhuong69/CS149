/**
 * Description: Implement a program named mem_tracer.c that reads all lines from stdin
 * read all lines into a dynamically allocated array of type char ** 
 * Thus, you will abandon any previous limitations (such as, only 100 lines of 30 chars each). 
 * Initialize the array memory with malloc to an initial size of 10 char * pointers. 
 * You should use realloc to expand your array if the initial size turns out not to be big enough for the lines in the input. 
 * Your implementation should work with input of up to a few hundred lines (test it with input of a few hundred lines).
 * Implement tracing of memory consumption. Use a stack holding the function names (that get called) and print the memory consumed whenever memory is allocated, reallocated or freed. 
 * Make sure you write separate functions for each case of allocating, reallocating or freeing of memory  (the rubric has some points for breaking up your code into functions). 
 * Your tracing should print messages describing the memory management and usage in each function call.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 04/03/23
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 


#define MAX_LINES 10
#define MAX_LINE 256

// Function stack to keep track of function calls
char func_stack[100][100];
int func_stack_top = -1;

// Function to push function name to stack
void push_func(const char* func_name) {
    strcpy(func_stack[++func_stack_top], func_name);
}

// Function to pop function name from stack
void pop_func() {
    func_stack_top--;
}

// Function to print memory consumption message
void print_mem_consumption(const char* func_name, const char* action, size_t size, const char* file, int line) {
    printf("Memory %s in function=%s, action=%s, size=%zu, file=%s, line=%d\n", action, func_stack[func_stack_top], func_name, size, file, line);
}

int main() {
    // Redirect stdout to memtrace.out file
    FILE *log_file = fopen("memtrace.out", "w");
    if (log_file == NULL) {
        printf("Failed to open log file.\n");
        return 1;
    }
    dup2(fileno(log_file), STDOUT_FILENO);

    int num_lines = 0; // Number of lines read
    int max_lines = MAX_LINES; // Maximum size of char** array
    char line[MAX_LINE]; // Buffer to store each line

    // Dynamically allocate memory for char** array
    char** lines = (char**) malloc(max_lines * sizeof(char*));
    if (lines == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    push_func("main"); // Push main function to stack

    while (fgets(line, MAX_LINE, stdin)) {
        // Remove newline character from the end of line
        line[strcspn(line, "\n")] = '\0';

        // Check if the number of lines exceeds the maximum size of char** array
        if (num_lines >= max_lines) {
            // Resize the char** array using realloc
            size_t new_size = max_lines * 2 * sizeof(char*);
            char** new_lines = (char**) realloc(lines, new_size);
            if (new_lines == NULL) {
                printf("Failed to reallocate memory.\n");
                free(lines);
                return 1;
            }
            lines = new_lines;
            max_lines *= 2;
            print_mem_consumption(__func__, "realloc", new_size, __FILE__, __LINE__);
        }

        // Dynamically allocate memory for each line
        lines[num_lines] = (char*) malloc((strlen(line) + 1) * sizeof(char));
        if (lines[num_lines] == NULL) {
            printf("Failed to allocate memory.\n");
            for (int i = 0; i < num_lines; i++) {
                free(lines[i]);
            }
            free(lines);
            return 1;
        }
        strcpy(lines[num_lines], line);
        num_lines++;

        print_mem_consumption(__func__, "malloc", (strlen(line) + 1) * sizeof(char), __FILE__, __LINE__);
    }

    pop_func(); // Pop main function from stack

   

    // Print the content of all nodes in the linked list
    printf("Linked List:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i+1, lines[i]);
    }

    // Free dynamically allocated memory for each line
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
        print_mem_consumption(__func__, "free", 0, __FILE__, __LINE__);
    }

    // Free dynamically allocated memory for char** array
    free(lines);
    print_mem_consumption(__func__, "free", 0, __FILE__, __LINE__);

    // Close the log file
    fclose(log_file);

    return 0;
}//end main

