#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct linked_list {
	char *data;
	struct linked_list *link;
};

void add_node(char *str);
void print_list();
struct linked_list *head;

int main() {
	int count = 0;
	char key;
	char str[20];
	head = (struct linked_list*)malloc(sizeof(struct linked_list));
	head->link = NULL;
	
	do {
		count++;
		printf("%d번째 학생: ", count);
		scanf("%s", str);
		add_node(str);
		printf("\n계속 입력하실 경우 아무키나 눌러주세요.(종료: esc)");
		key = getch(); 
	}while(key!=27);
	
	print_list();
	
	return 0;
}

void add_node(char str[]) {
	struct linked_list *new_node;
	new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
	new_node->data = (char*)malloc(sizeof(char)*sizeof(str));
	strcpy(new_node->data, str);
	new_node->link = NULL;
	
	if (head == NULL) {
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
		printf("%s", tmp->data); 
		tmp = tmp->link;
		if(tmp->link != NULL) {
			printf(", ");
		}
	}
}
