/**
 * Description:
 * Regarding the timer info for each process: you can use the timer.h library to record the start time of spawning each child process in the parent (see time_demo.c).
 * Upon finish of an exec (either a successful finish or termination via a signal), the parent process should record the finish runtime in the data structure,
 * and it should write to the output file the string "Finished at FIN, runtime duration DUR" where FIN is the finish time and DUR is the duration of the execution.
 * You will need the data structures proposed in order to record the start time of each process and compute its run duration.
 *The parent will re-start the executable if the command took more than two seconds (>2) to complete; it will also open new .out and .err files for the new PID and print "RESTARTING" at the top of those files.
 *Therefore, a process restarts as long as its last execution took more than 2 (>2) seconds.
 *For example, in the example below the sleep 5 command will restart (unless someone kills sleep early with 'killall' or 'kill -9').
 *If a process completed in 2 or less (<=2) seconds after starting, proc_manager will not restart it and will print a message "spawning too fast" to the error file for the process.
 *If it was terminated (e.g. by a kill signal) right after it started, or it had some other failure that caused it to exit immediately, it won't restart, since it exited immediately.
 *In those cases proc_manager will also not restart it and will print a message "spawning too fast" to the error file for the process.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Last modified date: 04/27/2023
 * Creation date: 04/17/2023
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

/*

    * MAX_ARGS:     an integer constant that represents the maximum number of arguments per command.
    * struct nlist: a structure that defines a linked list node to store process information.
    * pid_t:        a data type used to represent process IDs.
    * hash:         a function that takes a process ID as input and returns an unsigned integer value
                    representing the hash value of the input process ID.
    * lookup:       a function that takes a process ID as input and searches the hash table for the
                    corresponding node.Returns a pointer to the node if found, otherwise returns NULL.
    * insert:       a function that inserts a new process node into the hash table. Takes the process
                    ID, command string, index, and start time of the process as input parameters.
                    Returns a pointer to the newly inserted node.
    * delete:       a function that removes a process node from the hash table. Takes the process ID
                    as input parameter. Returns 0 if successful, otherwise returns -1.
    * parse_command:a function that takes a command string as input, tokenize it into an array of
                    arguments, and returns an array of char.

*/

// maximum number of arguments per command,
#define MAX_ARGS 10

// Definition of a linked list node to store process information
struct nlist
{
    struct nlist *next; // pointer to the next node in the linked list
    pid_t pid;          // process ID
    char *command;      // command string
    int index;          // index of the command
    time_t starttime;   // start time of the process
    time_t finishtime;  // finish time of the process
};

// Size of the hash table
#define HASHSIZE 101

// Hash table to store linked list nodes
static struct nlist *hashtab[HASHSIZE];

// Function to compute the hash value
unsigned hash(int pid)
{
    return pid % HASHSIZE;
}

// Function to look up a process ID in the hash table
struct nlist *lookup(pid_t pid)
{
    struct nlist *np;
    for (np = hashtab[hash(pid)]; np != NULL; np = np->next)
        if (pid == np->pid)
            return np;
    return NULL;
}

// Function to insert a new process node into the hash table
struct nlist *insert(pid_t pid, char *command, int index, time_t starttime)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(pid)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->command = strdup(command)) == NULL)
            return NULL;
        np->pid = pid;
        np->index = index;
        np->starttime = starttime;
        np->next = hashtab[hashval = hash(pid)];
        hashtab[hashval] = np;
    }
    return np;
}

// delete: remove a name and definition from the table
int delete(pid_t pid)
{
    struct nlist *np, *prev;
    prev = NULL;
    for (np = hashtab[hash(pid)]; np != NULL; prev = np, np = np->next)
    {
        // Search for the node with given pid
        if (pid == np->pid)
        {
            // Delete the node by linking the previous and next nodes
            if (prev == NULL)
                hashtab[hash(pid)] = np->next; // If the node is the head of the linked list
            else
                prev->next = np->next; // If the node is not the head of the linked list
            // Free memory allocated for the command and node
            free(np->command);
            free(np);
            return 0;
        }
    }
    return -1; // Return -1 if the node is not found in the linked list
}

// Parse the command into an array of arguments
// Returns an array of strings
char **parse_command(char *command)
{
    char **args = (char **)malloc(MAX_ARGS * sizeof(char *));
    char *arg = strtok(command, " ");
    int i = 0;
    while (arg != NULL)
    {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

int main()
{
    int i = 1;
    char command[1024];
    time_t start_time;
    time(&start_time);

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        // Read the user input
        if (fgets(command, sizeof(command), stdin) == NULL)
            break;

        // Remove the newline character from the input
        command[strlen(command) - 1] = '\0';

        // Check for end-of-file (EOF)
        if (feof(stdin))
            break;

        // Fork a new process to execute the command
        pid_t pid = fork();

        if (pid == 0) // Child process
        {
            // Initialize child start time and print message
            time_t child_start_time;
            time(&child_start_time);
            printf("Starting command: child %d pid of parent %d\n", getpid(), getppid());
            char **args = parse_command(command);
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }
        else if (pid > 0) // Parent process
        {
            // Insert the process node into the hash table
            struct nlist *np = insert(pid, command, i++, start_time);

            // Wait for the child process to finish
            int status;
            waitpid(pid, &status, 0);

            // Update the process node with the finish time
            time_t end_time;
            time(&end_time);
            np->finishtime = end_time;

            // Print the completion message
            printf("Command %s (pid %d) completed in %d seconds.\n", np->command, pid, (int)(end_time - np->starttime));

            // Check the exit status of the child process
            if (WIFEXITED(status))
            {
                // Child process exited normally
                printf("%s exited with exitcode = %d\n", np->command, WEXITSTATUS(status));
                // Check for error output from the child process
                if (WEXITSTATUS(status) != 0)
                {
                    // Print the error message to stderr
                    fprintf(stderr, "%s failed with error code %d.\n", np->command, WEXITSTATUS(status));

                    // Create an error output file
                    char err_filename[32];
                    sprintf(err_filename, "%d.err", np->pid);
                    FILE *err_file = fopen(err_filename, "a+");

                    if (err_file != NULL)
                    {
                        fprintf(err_file, "Command : %s\n", np->command);
                        fprintf(err_file, "Exited with exit code = %d\n", WEXITSTATUS(status));
                        fclose(err_file);
                    }
                    else
                    {
                        perror("fopen");
                    }
                }
                printf("===============================================%s", "\n");
            }
            else if (WIFSIGNALED(status))
            {
                // Child process terminated by a signal
                printf("%s killed with signal %d\n", np->command, WTERMSIG(status));

                // Create an error output file
                char err_filename[32];
                sprintf(err_filename, "%d.err", np->pid);
                FILE *err_file = fopen(err_filename, "a+");

                if (err_file != NULL)
                {
                    fprintf(err_file, "Command : %s\n", np->command);
                    fprintf(err_file, "Killed with signal %d\n", WTERMSIG(status));
                    fclose(err_file);
                }
                else
                {
                    perror("fopen");
                }
            }

            // Check if the command is 'sleep'
            if (strstr(command, "sleep") != NULL)
            {
                // Create an output file
                char out_filename[32];
                sprintf(out_filename, "%d.out", np->pid);
                FILE *out_file = fopen(out_filename, "a+");

                if (out_file != NULL)
                {
                    // Print the output to the file
                    fprintf(out_file, "Starting command %d: child %d pid of parent %d\n", np->index, np->pid, getpid());
                    fprintf(out_file, "Finished child %d pid of parent %d\n", np->pid, getpid());
                    fprintf(out_file, "Finished at %ld, runtime duration %d\n", end_time, (int)(end_time - np->starttime));
                    fclose(out_file);
                }
                else
                {
                    perror("fopen");
                }

                // Sleep for 5 seconds
                sleep(5);

                // Restart the command
                printf("RESTARTING\n");
                fflush(stdout);

                execlp(command, command, NULL);
            }

            // Remove the process node from the hash table
            delete (np->pid);
        }
        else
        {
            // Fork failed
            perror("fork");
            exit(1);
        }
    }

    return 0;
}
