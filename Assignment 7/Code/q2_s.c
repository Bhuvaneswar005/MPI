#include<mpi.h>
#include<stdio.h>
int main(int argc,char *argv[ ])
{
int size,myrank,i;
char x[5]="PCLAB";
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
int dest=myrank;

if(myrank==0)
{
printf("Process %d of %d, Value of x is %s sending the value x\n",myrank,size,x);
MPI_Send(&x,1,MPI_INT,1,55,MPI_COMM_WORLD);
}



else if(myrank==1)
{
printf("Value of x is : %s before receive\n",x);
MPI_Recv(&x,1,MPI_INT,0,55,MPI_COMM_WORLD,&status);
printf("Process %d of %d, Value of x is %s\n",myrank,size,x);
printf("Source %d Tag %d \n",status.MPI_SOURCE,status.MPI_TAG);
}
MPI_Finalize();
return 0;
}