#include<mpi.h>
#include<stdio.h>
int main(int argc,char *argv[ ])
{
int size,myrank,i;
int x[5]={1,2,3,4,5};
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
int dest=myrank;

if(myrank==0)
{
printf("Process %d of %d, Value of x is sending the value x: ",myrank,size);
for(int i=0;i<5;i++) {  printf("%d ",x[i]);}
MPI_Send(&x,1,MPI_INT,1,55,MPI_COMM_WORLD);
}



else if(myrank==1)
{
printf("\nValue of x is before receive: ");
for(int i=0;i<5;i++) {  printf("%d ",x[i]);}
MPI_Recv(&x,1,MPI_INT,0,55,MPI_COMM_WORLD,&status);
printf("\nProcess %d of %d, Value of x is ",myrank,size);
for(int i=0;i<5;i++) {  printf("%d ",x[i]);}
printf("\nSource %d Tag %d \n",status.MPI_SOURCE,status.MPI_TAG);
}
MPI_Finalize();
return 0;
}