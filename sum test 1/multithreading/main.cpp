#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <thread>
#include <unistd.h>
#define len 1000
//using namespace std;
void generate_random(int array[],int length)
{
for(int i=0;i<length;i++)
{
    array[i] =(rand() % 100 + 1);
}
}
void sum(int arr1[] , int arr2[] ,int arranswer[] , int lenth , int start_index)
{
    for(int i = 0 ; i< lenth ; i++ )
    {
        arranswer[i+start_index] = arr1[i+start_index] + arr2[i+start_index];
        usleep(10);
    }
}
int main()
{
srand(time(NULL));
int array1[len];
int array2[len];
int answer_sum[len];
generate_random(array1,len);
generate_random(array2,len);

int cores_number = std::thread::hardware_concurrency();
int repartition = len / cores_number;
int start_index_sum=0;
std::thread sumthread[cores_number];
//=======================================================================

for(int i=0 ;i<len;i++)
{
    std::cout<<"array1["<<i<< "]:"<<array1[i]<<"\t";
}
std::cout<<"\n";
std::cout<<"\n";

for(int i=0 ;i<len;i++)
{
    std::cout<<"array2["<<i<< "]:"<<array2[i]<<"\t";
}
std::cout<<"\n";
std::cout<<"\n";
//=============================================================================
for(int i = 0; i < cores_number;i++)
{
    sumthread[i] = std::thread(sum,array1,array2,answer_sum,repartition,start_index_sum);
    start_index_sum += repartition;

}

for(int i=0 ;i<cores_number;i++)
{
    sumthread[i].join();
}
//==============================================================
for(int i=0 ;i<len;i++)
{
    std::cout<<"sum["<<i<< "]:"<<answer_sum[i]<<"\t";
}
std::cout<<"\n";
std::cout<<"\n";
//===============================================================
std::cout<<"number of cores: "<<cores_number<<"\n";

    return 0;
}

