#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

struct list {
	int field;
	struct list* next;
	struct list* prev;
};

struct list* init(int a) {
	struct list* lst;
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = NULL;
	lst->prev = NULL;
	return(lst);
}

struct list* addelem(list* lst, int number) {
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next;
	lst->next = temp;
	temp->field = number;
	temp->next = p;
	temp->prev = lst;
	if (p != NULL)
		p->prev = temp;
	return(temp);
}

struct list* deletelem(list* lst) {
	struct list* prev, * next;
	prev = lst->prev;
	next = lst->next;
	if (prev != NULL)
		prev->next = lst->next;
	if (next != NULL)
		next->prev = lst->prev;
	free(lst);
	return(prev);
}

void listprint(list* lst) {
	struct list* p;
	p = lst;

	if (lst->field != NULL)
		do {
			printf("%d ", p->field);
			p = p->next;
		} while (p != NULL);
	else std::cout << "Empty!\n\n";
}

void find(list* lst, int number) {
	struct list* p;
	p = lst;

	if (lst->field != NULL)
		do {
			if (p->field == number) 
			{
				std::cout << "List have " << number << "\n\n";
				return;
			}			
			p = p->next;
		} while (p != NULL);
	else std::cout << "Empty!\n\n";

	std::cout << "Coincidences wasn't searched!!!" << "\n\n";
}

int minimalAblosute(list* lst) {
	struct list* p;
	p = lst;
	int Min = abs(lst->field);
	int i = 0;

	if (lst->field != NULL)
		do {
			if (abs((p->field)) < Min)
			{
				Min = abs((p->field));				
			}
			p = p->next;
		} while (p != NULL);
	else { std::cout << "Empty!\n\n"; return NULL; }
	
	return Min;
}

int GetSize(list* lst) {
	int i = 0;
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field);
		p = p->next;
		i++;
	} while (p != NULL);

	return i;
}

bool isEmpty(list* lst)
{
	if (lst == NULL) return false;
	else return true;
}

void clear(list* lst) {
	struct list* p, * temp;
	p = lst;

	do {
		temp = p->next;
		delete p;
		p = temp;
		
	} while (p != NULL);

	lst->field = NULL;

	std::cout << "\nCleanning successfull" << std::endl;
}

struct list* swap(struct list* lst1, struct list* lst2, struct list* head)
{
	struct list* prev1, * prev2, * next1, * next2;
	prev1 = lst1->prev;
	prev2 = lst2->prev;
	next1 = lst1->next;
	next2 = lst2->next;
	if (lst2 == next1)  // обмениваются соседние узлы
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		if (next2 != NULL)
			next2->prev = lst1;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else if (lst1 == next2)  // обмениваются соседние узлы
	{
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		if (next1 != NULL)
			next1->prev = lst2;
		if (lst2 != head)
			prev2->next = lst1;
	}
	else  // обмениваются отстоящие узлы
	{
		if (lst1 != head)
			prev1->next = lst2;
		lst2->next = next1;
		if (lst2 != head)
			prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		if (next2 != NULL)
			next2->prev = lst1;
		lst1->prev = prev2;
		if (next1 != NULL)
			next1->prev = lst2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}

int main() {
	list* head = NULL, * cur = NULL;
	int num, size, elem;
	char userAnswer;

	printf("a = ");
	scanf("%d", &num);
	head = init(num);
	std::cout << "isEmpty -  " << isEmpty(cur) << "\n";
	cur = head;

	std::cout << "isEmpty -  " << isEmpty(cur) << "\n";;
	do 
	{
		std::cout << "Chose size list: "; std::cin >> size;
	} while (size < 1);

	std::cout << "Do you want fill by yourself? (Y/y): "; std::cin >> userAnswer;

	if(userAnswer == 'Y' || userAnswer == 'y')
	for (int i = 0; i < size; i++) {
		printf("a = ");
		scanf("%d", &num);
		cur = addelem(cur, num);
	}
	else
	{
		for (int i = 0; i < size; i++) {
			cur = addelem(cur, rand() % 50 - 25);
		}
	}
	
	std::cout << "Size -  " << GetSize(head) << "\n\n";
	listprint(head);

	std::cout << "\nChose elem fo find it: "; std::cin >> elem;
	find(head, elem);

	printf("\n");

	std::cout << "\nMinimal abs elem -  " << minimalAblosute(head) << "\n\n";

	// Меняем местами первый и второй элементы
	cur = head->next;
	head = swap(head, cur, head);
	listprint(head);
	printf("\n");
	// Удаляем третий элемент списка
	cur = head->next->next;
	deletelem(cur);
	listprint(head);

	clear(head);
	listprint(head);

	printf("\n");
	getchar(); getchar();
	return 0;
}