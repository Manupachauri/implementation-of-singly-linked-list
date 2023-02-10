#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_end(struct node *head, int data)
{
    struct node* temp;
    struct node * ptr;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while(ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
}


void insert_beg(struct node *head, int data)
{
    struct node* ptr;
    ptr -> data = data;
    ptr->link = head;
    head = ptr;
}

void insert_pos(struct node *head, int data, int pos)
{
    struct node*ptr;
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    int i = 0;
    while( i<pos) {
        ptr = ptr -> link;
        i++;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

void del_beg(struct node* head)
{
    if (head== NULL) {
        printf("list empty\n");
    }
    struct node *temp = head;
    head = head-> link;
    free(temp);
}

void del_end(struct node* head)
{
    if (head == NULL) {
        printf("list empty\n");
    } else if(head->link == NULL) {
        free(head);
    } else {
        struct node* ptr = head;
        struct node*temp= ptr;
        while(ptr->link!=NULL) {
            temp = ptr;
            ptr=ptr->link;
        }
        temp->link = NULL;
        free(ptr);

    }
}

void del_pos(struct node* head, int pos)
{
    if(head== NULL) {
        printf("list empty\n");
    }
    struct node*ptr;
    struct node*temp;
    int i = 0;
    while(i<pos-1) {
        ptr= ptr->link;
        i++;
    }
    temp = ptr->link;
    ptr->link = ptr->link->link;
    free(temp);
}


void display(struct node *head)
{
    struct node* ptr;
    if (head == NULL) {
        printf("empty list\n");
    }
    ptr = head;
    while(ptr!= NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }

}
int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    int choice, data, pos;

    while (1) {
        printf("1 for insert; 2 for insert at beginning; 3 for insert at  position ;\n4 for del_beg; 5 for delete at end ;6 for delete at position ;7 for display ;8 for exit==>");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("enter data ==>");
            scanf("%d", &data);
            insert_end(head ,data);
            break;
        case 2:
            printf("enter data ==> ");
            scanf("%d", &data);
            insert_beg(head, data);
            break;
        case 3:
            printf("enter data, pos ==> ");
            scanf("%d %d", &data, & pos);
            insert_pos(head, data, pos);
            break;
        // case 2: delet();
        // break;
        case 4:
            del_beg(head);
            break;
        case 5:
            del_end(head);
            break;
        case 6:
            printf("enter pos ==> ");
            scanf("%d", & pos);
            del_pos(head, pos);
            break ;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
            break;
        }
    }
    return 0;
}




































































































































































































































































