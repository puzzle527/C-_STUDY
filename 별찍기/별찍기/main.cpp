#include <iostream>

using namespace std;

int main(void)
{
	char arr[6];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = '*';
	}
	arr[5] = NULL;

	for (int i = 4; i >  -1; i--)
	{
		cout << arr + i << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << arr + i << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j < i)
				cout << ' ';
			else
				cout << arr[0];
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 4; i > -1; i--)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j < i)
				cout << ' ';
			else
				cout << arr[0];
		}
		cout << endl;
	}

 //    *
 //   **
 //  ***
 // ****
 //*****

 //*****
 // ****
 //  ***
 //   **
 //    *

 //*
 //**
 //***
 //****
 //*****

 //*****
 //****
 //***
 //**
 //*

	return 0;
}