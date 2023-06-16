#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
	node* curr = head;
	while(curr!=NULL){
		count++;
		curr = curr->next;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int len = length(head);
	char *string = malloc((len+1)*sizeof(char)); 
	int i = 0;
	node* curr = head;
	while(curr != NULL){
		string[i] = curr->letter;
		curr = curr->next;
		i++;
	}
	string[len] = '\0';
	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* new_node = malloc(sizeof(new_node));
	if(new_node == NULL){
		exit(1);
	}
	new_node->next = NULL;
	new_node->letter = c;

	if(*pHead == NULL){
		*pHead = new_node;
		return;
	}

	node* curr = *pHead;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = new_node;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* curr = *pHead;
	node* tmp;
	while(curr != NULL){
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}