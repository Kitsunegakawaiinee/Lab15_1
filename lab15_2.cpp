#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A [][N])
{
	for (int i = 0; i<::N; i++)
	{
		cout << "Row " << i+1 << ": ";
		for (int j = 0; j < ::N; j++)
		{
			cin >> A[i][j];
		}
	}
}

void findLocalMax(const double A[][N], bool B[][N])
{

	for (int i = 0; i > N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i == 0 || i == N-1)
			{
				B[i][j] = 0;
			}

			else if(j == 0 || j == N-1)
			{
				B[i][j] = 0;
			}
		}
	}

	for(int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			if(a == 0 || a == N-1 || b == 0 || b == N-1)
			{
				continue;
			}
			
			int fogus = A[a][b];
			bool max = true, up,down,left,right,Result;

			up = (A[a][b] > A[a-1][b]);
			down = (A[a][b] > A[a+1][b]);
			left = (A[a][b] > A[a][b-1]);
			right = (A[a][b] > A[a][b+1]);
			Result = up && down && left && right;

			if(Result) B[a][b] = 1;
			else B[a][b] = 0;


		} 
	}

}

void showMatrix(const bool  Matrix[][N])
{
	for (int i = 0; i< ::N; i++)
	{
		for (int j = 0; j < ::N; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}