// LINEAR QUEUE
#include<stdio.h>
int queue[100], N, front=-1, rear=-1;
void enqueue(int item){
    if(rear==N-1) printf("\n Queue is full");
    else{
        rear++;
        queue[rear] = item;
        if(front==-1) front = 0;
        printf("\n Insertion successfull.");
    }
}
int dequeue(){
	int item;
    if(front==-1) return -1;
    else{
    	item = queue[front];
    	if(front==rear) front=rear=-1;
    	else front++;
    	return item;
    }
}
void showQueue(){
    int i;
    printf("\n Showing Queue: Front->");
    for(i=front; front>-1 && i<=rear; i++){
        printf(" %d |", queue[i]);
	}
	printf(" <- Rear");
}
int main(){
    int ch, x;
    printf("\n Enter size of queue: ");
    scanf("%d", &N);
    while(1){
    	system("cls");
        printf("\n Linear Queue using Array");
        printf("\n Menu: 1. Enqueue 2. Dequeue 3. Display 0. Exit");
        printf("\n Enter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                printf("\n Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                printf("\n Item removed: %d", dequeue());
                break;
            case 3:
                showQueue();
                break;
            case 0:
                exit(0);
                break;
            default: printf("\n Wrong choice.");
        }
        printf("\n Enter any key to continue...");
        scanf("%d", &ch);
    }
    return 0;
}
