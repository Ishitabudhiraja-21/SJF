#include <iostream>
using namespace std;
int process[20][6];
void sort(intnum,int process[][6])
{
int temp;
for(int i=0; i<num; i++)
{
for(int j=0; j<num-i-1; j++)
{
if(process[j][1] > process[j+1][1])
{
for(int k=0; k<5; k++)
{
temp=process[j][k];
process[j][k]=process[j+1][k];
process[j+1][k]=temp;
}
}
}
}
}
voidcompletion_time(intnum, int mat[][6])
{
int temp, pos,min;
process[0][3] = process[0][1] + process[0][2];
process[0][5] = process[0][3] - process[0][1];
process[0][4] = process[0][5] - process[0][2];
for(int i=1; i<num; i++)
{
temp = process[i-1][3];
min = process[i][2];
for(int j=i; j<num; j++)
{
if(temp >= process[j][1] && min >= process[j][2])
{
min = process[j][2];
pos = j;
}
}
process[pos][3] = temp + process[pos][2];
process[pos][5] = process[pos][3] - process[pos][1];
process[pos][4] = process[pos][5] - process[pos][2];
for(int k=0; k<6; k++)
{
temp=process[pos][k];
process[pos][k]=process[i][k];
process[i][k]=temp;
}
}
}
int main()
{
intnum,temp;
floataverage_waiting,average_turn_around;
cout<<"Enter number of processes : ";
cin>>num;
for(int i=0; i<num; i++)
{
cout<<endl<<"Enter details of Process "<<i+1<<endl;
cout<<"Enter Process Id: ";
cin>>process[i][0];
cout<<"Enter Arrival Time: ";
cin>>process[i][1];
cout<<"Enter Burst Time: ";
cin>>process[i][2];
}
cout<<"----------------------------------------------------------------------------"<<endl;
cout<<"Processes before Sorting : "<<endl;
cout<<"Process ID\tArrival Time\tBurst Time\n";
for(int i=0; i<num; i++)
{
cout<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<endl;
}
sort(num, process);
completion_time(num, process);
cout<<"----------------------------------------------------------------------------"<<endl;
cout<<"Processes after sorting : "<<endl;
cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
for(int i=0; i<num; i++)
{
cout<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<"\t\t"<<process[i][4]<<"\t\t"<<process[i][5]<<endl;
average_waiting+=process[i][4];
average_turn_around+=process[i][5];
}
average_waiting=average_waiting/num;
average_turn_around=average_turn_around/num;
cout<<"Average Waiting Time = "<<average_waiting<<endl;
cout<<"Average Turn Ar


