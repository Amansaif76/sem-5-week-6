#include<stdio.h>
#define size 30

int main(){
	int i,j,n,t,p[size],a[size],b[size],tat[size],wt[size];
	float avgwt=0,avgtat=0;
	printf("Enter the number of processes\n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
	    printf("Enter process arrival and the burst time for process %d\n",i);	
	    p[i]=i;
	    scanf("%d%d",&a[i],&b[i]);
	}

	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
		if(b[j]>b[j+1]){
			t=b[j];
			b[j]=b[j+1];
			b[j+1]=t;
			
		
			t=p[j];
			p[j]=p[j+1];
			p[j+1]=t;
		  }	
		}
	}
	

	printf("Process \t Arrival Time \t Burst Time \t waiting Time \t Turn Around Time\n");
	for(i=0;i<n;i++){
		tat[i]=0;
		wt[i]=0;
		for(j=0;j<i;j++){
			wt[i]+=b[j];
		}
		tat[i]=wt[i]+b[i];
		avgwt+=wt[i];
		avgtat+=tat[i];
		printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d\n ",p[i],a[i],b[i],wt[i],tat[i]);
	}
	avgwt=avgwt/n;
	avgtat/=n;
	printf("\nThe average waiting time is %.2f\n",avgwt);
    printf("\nThe average Turn Around Time is  %.2f\n",avgtat);    
}
