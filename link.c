#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>

struct linked_list{
	char data;
	struct linked_list *link;
};

void add_node(char str);
void print_list();
struct linked_list *head;

int main() {
	int count = 0;
	char key;
	
	head = (struct linked_list*)malloc(sizeof(struct linked_list));
	head->link = NULL;
	
	do {
		count++;
		printf("%d번 입력: ", count);
		key = getch();
		add_node(key);
		printf("아무키나 누르시오. 종료: esc\n");
	}while(key!=27);
	
	print_list();
	
	return 0;
}

void add_node(char str) {
	struct linked_list *new_node;
	new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
	new_node->data = str;
	new_node->link = NULL;
	
	if(head == NULL) {
		head = new_node;
	} else {
		struct linked_list *tmp;
		tmp = head;
		while(tmp->link != NULL) {
			tmp = tmp->link;
		} 
		tmp->link = new_node;
	} 
}

void print_list() {
	struct linked_list *tmp;
	tmp = head->link;
	
	while(tmp->link != NULL) {
		printf("%c", tmp->data);
		tmp = tmp->link;
		if (tmp->link != NULL) {
			printf(", ");
		}
	}
}
