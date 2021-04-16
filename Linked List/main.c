#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node {
	int data;
	Node* next;
};

Node* head_insert(Node* head, int data);
Node* tail_insert(Node* head, int value);
Node* reverse_list(Node* head);
//Node* reverse_list(Node* prev, Node* head);
Node* copy_list(Node* head);
Node* remove_node(Node* head, int value);
void print_list(Node* head);
int sum(Node* head);
int number(Node* head);
void destroy_list(Node** head);


int main(int argc, char* argv[]) {
	Node* head = NULL;
	Node* copy = NULL;

	for (int i = 0; i < 10; i++) {
		head = tail_insert(head, i);
	}
	print_list(head);

	copy = copy_list(head);

	print_list(copy);
	destroy_list(&head);
	destroy_list(&copy);

	return 0;
}

Node* head_insert(Node* head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		return NULL;
		exit(1);
	}
	temp->data = data;
	temp->next = head;
	return temp;
}

Node* tail_insert(Node* head, int value) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		exit(1);
	}
	temp->data = value;
	temp->next = NULL;
	
	if (head == NULL) {
		return temp;
	}

	Node* front = head;
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = temp;
	return front;
}

//void print_list(Node* head) {
//	if (head != NULL) {
//		printf("%d\n", head->data);
//		print_list(head->next);
//	}
//}
void print_list(Node* head) {
	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

//void destroy_list(Node** head) {
//	Node* temp = *head;
//	if (temp != NULL) {
//		Node* next = temp->next;
//		free(temp);
//		*head = NULL;
//		destroy_list(&next);
//	}	
//}
void destroy_list(Node** head) {
	while (*head != NULL) {
		Node* next = (*head)->next;
		free(*head);
		*head = NULL;
		head = &next;
	}
}

//int sum(Node* head) {
//	if (head != NULL) {
//		return head->data + number_recursive(head->next);
//	}
//	return 0;
//}
int sum(Node* head) {
	int sum = 0;
	while (head != NULL) {
		sum += head->data;
		head = head->next;
	}
	return sum;
}

//int number(Node* head) {
//	if (head != NULL) {
//		return 1 + number(head->next);
//	}
//	return 0;
//}
int number(Node* head) {
	int number = 0;
	while (head != NULL) {
		number += 1;
		head = head->next;
	}
	return number;
}

Node* reverse_list(Node* head) {
	Node* temp = NULL;
	Node* new = NULL;
	
	if (head == NULL) {
		return NULL;
	}

	while (head != NULL) {
		temp = head;
		head = head->next;
		temp->next = new;
		new = temp;
	}
	return new;
}

Node* copy_list(Node* head) {
	Node* new_list = NULL;
	Node* tail = NULL;

	while (head != NULL) {
		if (new_list == NULL) {
			new_list = (Node*)malloc(sizeof(Node));
			if (new_list == NULL) {
				exit(1);
			}
			new_list->data = head->data;
			new_list->next = NULL;
			tail = new_list;
		}
		else {
			tail->next = (Node*)malloc(sizeof(Node));
			if (tail->next == NULL) {
				exit(1);
			}
			tail = tail->next;
			tail->data = head->data;
			tail->next = NULL;
		}
		head = head->next;
	}
	return new_list;
}

//Node* remove_node(Node* head, int value) {
//	Node* prev;
//	Node* front = head;
//
//	if (head == NULL) {
//		return NULL;
//	}
//
//	while (head->data != value) {
//		prev = head;
//		head = head->next;
//	}
//
//	if (head != front) {
//		prev->next = head->next;
//		free(head);
//	}
//	else {
//		front = head->next;
//		free(head);
//	}
//
//	return front;
//}
Node* remove_node(Node* head, int value) {

	if (head == NULL) {
		return NULL;
	}

	if (head->data == value) {
		Node* temp = head->next;
		free(head);
		return temp;
	}

	head->next = remove_node(head->next, value);
	
	return head;
}