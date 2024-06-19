// CIRCULAR QUEUE
#include<stdio.h>
int queue[100], N, front=-1, rear=-1;
void enqueue(int item){
    if((front==0 && rear==N-1)||(front!=0 && rear==front-1)) printf("\n Queue is full");
    else{
        if(front==-1) front=rear=0;
        else if(front!=0 && rear==N-1) rear=0;
        else rear++;
        queue[rear] = item;
    	printf("\n Insertion successfull.");
    }
}
int dequeue(){
    int item;
    if(front==-1) return -1;
    else{
        item = queue[front];
        if(front==rear) front=rear=-1;
        else if(front==N-1 && rear<front) front=0;
        else front++;
        return item;
    }
}
void showQueue(){
    int i;
    printf("\n Showing queue: Front-> ");
    if(rear>=front){
    	for(i=front; i<=rear; i++)
    		printf(" %d |", queue[i]);
	}else{
		for(i=front; i<=N-1; i++)
			printf(" %d |", queue[i]);
		for(i=0; i<=rear; i++)
			printf(" %d |", queue[i]);
	}
    printf(" <-Rear");
    
    printf("\n Front = %d ; Rear = %d", front, rear);
}
int main(){
    int ch, x;
    printf("\n Enter size of queue: ");
    scanf("%d",&N);
    while(1){
        system("cls");
        printf("\n Circular Queue using Array");
        printf("\n Menu: 1. Enqueue 2. Dequeue 3. Display 0. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\n Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                x = dequeue();
                if(x==-1) printf("\n Queue is empty.");
                else printf("\n Removed Element: %d", x);
                break;
            case 3:
                showQueue();
                break;
            case 0:
                exit(0);
                break;
            default: printf("\n Wrong Choice.");
        }
        printf("\n Enter any key to continue...");
        scanf("%d", &ch);
    }
    return 0;
}
