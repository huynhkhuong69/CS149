#ifndef ContactNode_h
#define ContactNode_h

struct ContactNode{

    char ContactName[50];
    char ContactPhone[50];
    struct ContactNode* nextNodePtr;
};

// create a new node
struct ContactNode* CreateContactNode(struct ContactNode* p, char name[], char phone[]);

// insert a new node after node
struct ContactNode* InsertContactAfter(struct ContactNode* p,char name[], char phone[]);

// Return Location Pointed by nextNodePtr
struct ContactNode* GetNextContact(struct ContactNode* p);

// print a node
void PrintContactNode(struct ContactNode* p);

#endif