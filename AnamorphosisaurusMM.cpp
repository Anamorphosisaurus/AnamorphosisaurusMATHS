#include <iostream>
#include <fstream>


int main()
{
	int sizeA, sizeB, sizeC;
	int rows;
	int * startA;
	int * startB;
	int * startC;
	int * holdA;
	int count = 0;

	
	std::fstream myfileSA("Asize.txt", std::ios_base::in);
	int AL, AH;
	myfileSA >> AL;
	myfileSA >> AH;
	sizeA = AL * AH;


	std::fstream myfileSB("Bsize.txt", std::ios_base::in);
	int BL, BH;
	myfileSB >> BL;
	myfileSB >> BH;
	sizeB = BL * BH;


	rows = BL;
	sizeC = AL * BH;
	

	int * A = new int[sizeA];
	int * B = new int[sizeB];
	int * C = new int[sizeC];
	startA = A;
	startB = B;
	startC = C;



	std::fstream myfileA("A.txt", std::ios_base::in);
	int a;
	while (myfileA >> a)
	{
		*A = a;
		*A++;
	}

	std::fstream myfileB("B.txt", std::ios_base::in);
	int b;
	while (myfileB >> b)
	{
		*B = b;
		*B++;
	}
			

	for (int i = 0; i < sizeC; i++)
	{
		*C = 0;
		*C++;
	}


	A = startA;
	B = startB;
	C = startC;
	holdA = startA;
	
	

	for (int k = 0; k < rows; k++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int i = 0; i < rows; i++)
			{
				*C = *A * *B + *C;
				*A++;
				B = B + rows;
			}
			std::cout << *C << " ";
			count++;
			B = startB + count;
			A = holdA;
			*C++;
		}
		B = startB;
		A = startA + rows;
		holdA = holdA + rows;
		count = 0;
	}

	std::cin.get();
}

