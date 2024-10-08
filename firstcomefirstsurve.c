#include<stdio.h>
struct process{
	int pid;
	int arrivalTime;
	int burst_Time;
	int completion_Time;
	int waiting_time;
	int turnaround_Time;	
};


void completion(struct process aman[], int n) {
    int i, sum = 0;
    
    for(i = 0; i < n; i++) {
        sum += aman[i].burst_Time;  
        aman[i].completion_Time = sum; 
    }
}


void TAT(struct process aman[], int n){
	int i;
	for(i=0;i<n;i++){
	aman[i].turnaround_Time=aman[i].completion_Time - aman[i].arrivalTime;	
	}
}
 
void waiting(struct process aman[],int n){
	int i;
	for(i=0;i<n;i++){
		aman[i].waiting_time=aman[i].turnaround_Time - aman[i].burst_Time;
	}
}

 
int avgTAT(struct process aman[], int n){
	int i,sum=0;
	for(i=0;i<n;i++){
		sum+=aman[i].turnaround_Time;
	}
	return sum;
}



int avgWT(struct process aman[], int n){
	int i,sum=0;
	for(i=0;i<n;i++){
		sum+=aman[i].waiting_time;
	}
	return sum;
}

int main(){
	int n,i;
	printf("\nEnter the number of processes\n");
	scanf("%d",&n);
	struct process aman[n];  
	for(i=0;i<n;i++){
	aman[i].pid=i;
	printf("Enter the Arrival and Burst time for %dth process \n",aman[i].pid);
	scanf("%d%d",&aman[i].arrivalTime, &aman[i].burst_Time);	
	}
	completion(aman, n); 
	TAT(aman,n);  
	waiting(aman,n);  
	
	printf("\n pid\t Arrival time \tBurst time\t Completion time\t TurnAround Time\t Waiting time \n");
	for(i=0;i<n;i++){
	printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d \t\t\t%d \n",aman[i].pid, aman[i].arrivalTime,aman[i].burst_Time,aman[i].completion_Time, aman[i].turnaround_Time,aman[i].waiting_time);	
	}
	float a=avgTAT(aman,n)/n;
	float b=avgWT(aman,n)/n;  
	printf("\nThe average turn Aroud time is = %.2f \n",a);
	printf("\nThe average waiting time is = %.2f \n",b);
	
}
