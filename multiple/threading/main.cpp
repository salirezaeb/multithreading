#include <iostream>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <time.h>
using namespace std;
// maximum size of matrix
#define MAX 8

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void* multi(void* arg)
{
	int i = step_i++; //i denotes row number of resultant matC

	for (int j = 0; j < MAX; j++)
	for (int k = 0; k < MAX; k++)
    {


		matC[i][j] += matA[i][k] * matB[k][j];
        usleep(10000);
    }
}
int main()
{
    int MAX_THREAD = MAX; //std::thread::hardware_concurrency();
	// Generating random values in matA and matB
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			matA[i][j] = (rand() % 100 + 1);
			matB[i][j] = (rand() % 100 + 1);
		}
	}

	// Displaying matA
	cout << endl
		<< "Matrix A" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matA[i][j] << " ";
		cout << endl;
	}

	// Displaying matB
	cout << endl
		<< "Matrix B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matB[i][j] << " ";
		cout << endl;
	}

	// declaring four threads
	std::thread threads[MAX_THREAD];

	// Creating threads, each evaluating its own part
	for (int i = 0; i < MAX_THREAD; i++) {
		int* p;
		threads[i] = thread(multi,(void*)(p));
	}

	// joining and waiting for all threads to complete
	for (int i = 0; i < MAX_THREAD; i++)
		threads[i].join();

	// Displaying the result matrix
	cout << endl
		<< "Multiplication of A and B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matC[i][j] << " ";
		cout << endl;
	}
	return 0;
}