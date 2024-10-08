#include<stdio.h>
#define size 20

int queue[size];  
int rear=-1, front =-1;


void enqueue(int x){
	if(rear==size-1){
		printf("Queue is full!\n");
	}
	else if(rear==-1 && front==-1){
		rear=front=0;
		queue[rear]=x;
	}
	else{
		rear++;
		queue[rear]=x;
	}
}


void dequeue(){
  if(rear==-1 && front==-1){
  	printf("Queue is empty\n");
  }	
  else if(rear=front=0){
  	printf("Dequed element is %d \n",queue[front]);
  	front=rear=-1;
  }
  else{
  	printf("Dequed element is %d \n",queue[front]);
  	front++;
  }
  
}


void display(){
 if(rear==-1 && front==-1){
 	printf("Queue is empty\n");
 	return;
 }
 int i;
 printf("\n The queue elements are :---\n");
 for(i=front;i<=rear;i++){
 	printf("%d ",queue[i]);
 }
 printf("\n");
}

int main(){
	int ch,val; ;
	do{
		printf("1.Enqueue Operation\n");
		printf("2.Dequeue Operation\n");
		printf("3.Display operation\n");
		printf("4.Quit....\n");
		printf("Enter the choice \n");
	     scanf("%d",&ch);
	     
	switch(ch){
	     case 1:
		
		 printf("Enter the value\n");
		 scanf("%d",&val);
		 enqueue(val);
		 break;
		 
		case 2:
		dequeue();
		break;
		
		case 3:
		display();
		break;
		
		case 4:
		printf("Quit the operation\n");
		break;
		
		default:
		printf("Enter the valid option\n");	
      }
	}while(ch!=4);
}
