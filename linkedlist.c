#include <stdio.h>
#include <stdlib.h>
//very basic linked list implimentation in C. 
//basic node structure. No typedef.
struct node
{
  int val;
  struct node *next;
};

struct node *deleteNode(struct node *first, int num)
{
  struct node *prev=NULL;
  struct node *root = first;
  while (root != NULL)
  {
    if (root->val == num)
    {
      if (prev != NULL && root->next != NULL) //middle elements
      {
        prev->next = root -> next;
        free(root);
      }
      else if (prev == NULL) //first element
      {
        free(first);
        first = root->next;
        root = root->next;
      }
      else if (root->next == NULL) //last element
      {
        prev->next = NULL;
        free(root);
      }
    }
    prev = root;
    root = root -> next;
  }
  return first;
}

struct node *reverseList(struct node *root)
{
  struct node *temp= NULL;
  struct node *prev= NULL;

  while (root!= NULL)
  {
    temp = root->next;
    root->next = prev;
    prev = root;
    root = temp;
  }
  return prev;
}

void printList(struct node *root)
{
 while (root!= NULL)
 {
   printf("Value: %d\n", root -> val);
   root = root -> next;
 }
}
int main()
{
 struct node *root = NULL, *tail = NULL;

 int i=1;
 for (;i<=20; ++i)
 {
     struct node *current = malloc(sizeof(struct node));
     current -> val = i;
     current -> next = NULL;
     
     if (root==NULL) root = current;
     else tail -> next = current;

     tail = current;
 }

 //delete first,last and middle element 
 root = deleteNode(root, 20);
 root = deleteNode(root, 1);
 root = deleteNode(root, 10);
 root = reverseList(root);
 printList(root);

 return 0;
}
