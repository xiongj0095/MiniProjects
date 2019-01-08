/*
 * Joey Xiong
 * Wednesday, April 24, 2018
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

long int powerFuction(long int base, long int exponent, long int modulusN);
long int computeC_Multiple(long int bSmoothNumber, long int modulusN);
bool checkB_Smooth(long int *primeFactorizationArray, long int primeArraySize, long int modulusN, long int bSmoothNumber);
long int *getPrimeFractorization(long int* primeFactorizationArray, long int modulusN);
long int getGCD(long int c_MultipleOfP, long int n_MultipleOfP);
long int getPrimeP(long int modulusN, long int bSmoothNumber, long int c_MultipleOfP, long int* primeFactorizationArray);
long int calculateInverseMod(long int phi, long int encryptionPublicKeyE, long int *sValue, long int *tValue);

//int gcd(int n, int n2);

int main(void)
{
	long int bSmoothNumber = 100;
	long int modulusN = 40612127;
    long int c_MultipleOfP = 0;
    long int *primeFactorizationArray;
	long int primeArraySize = 0;

    long int primeP = 0;
	long int encryptionPublicKeyE = 23;
	long int decryptionPrivateKeyD = 0;
	long int primeQ = 0;
	long int phi = 0;
//	long int inverseArray;

	//prompt user input
	printf("%s", "Enter number for modulus N: ");

	//user input for modulus N
	fflush(stdout);
	scanf("%li", &modulusN);

//	//prompt user input
//	printf("%s", "Enter B-smooth number: ");
//
//	//user input bSmoothNumber
//	fflush(stdout);
////	scanf("%li", &bSmoothNumber);
//
//	//prompt user input
	printf("%s\n", "Enter number for public key 'e': ");
//
//	//user input for public key 'e'
	fflush(stdout);
	scanf("%li", &encryptionPublicKeyE);

	const long int datacount = 50;
	primeFactorizationArray = malloc(sizeof(long int) * datacount); /* allocate memory for 50 int's */
	if (!primeFactorizationArray) { /* If primeFactorizationArray == 0 after the call to malloc, allocation failed for some reason */
		perror("Error allocating memory");
		abort();
	}
    memset(primeFactorizationArray, 0, sizeof(long int)*datacount);

	primeFactorizationArray = getPrimeFractorization(primeFactorizationArray, modulusN);

	// Get size--> while array elements are greater than 0
	long int index = 0;
	while(primeFactorizationArray[index] > 0) {
		index++;
		primeArraySize++;
	}

	printf("%s%li%s", "THE Prime Factorization Array of ", modulusN, ": ");
	for(long int i=0; i < primeArraySize; i++)
	{
		printf("%li%s", primeFactorizationArray[i], " ");
	}
	printf("\n");


	primeP = getPrimeP(modulusN, bSmoothNumber, c_MultipleOfP, primeFactorizationArray);
	primeQ = modulusN / primeP;
	phi = (primeP - 1) * (primeQ - 1);


	long int sValue = 0, tValue, inverseMod;

	//gcd = encryptionPublicKeyE*sValue + phi*tValue
	inverseMod = calculateInverseMod(phi, encryptionPublicKeyE, &sValue, &tValue);

	//d = e^-1 mod phi
	decryptionPrivateKeyD = inverseMod % phi;
//printf("%s%li\n","phi: ", 1/encryptionPublicKeyE);

//	printf("%s%li\n","inverseMod: ", inverseMod);
	printf("%s%li\n", "Prime Q = ", primeQ);
	printf("%s%li\n","Decryption Private Key: ", decryptionPrivateKeyD);

	//free memory when done
	free(primeFactorizationArray);

	return 0;
}

//Compute power function to a mod
long int powerFuction(long int base, long int exponent, long int modulusN)
{
	long int powerTotal = base;
	for(int i=1; i < exponent; i++)
	{
		powerTotal = (powerTotal % modulusN) * (base % modulusN);

		//	printf("%s%li%s%li%s%i\n", "     powerTotal = ", powerTotal, " base = ", base, " i = ", i+1);

	}

	return powerTotal;
}

//Compute the C Multiple
long int computeC_Multiple(long int bSmoothNumber, long int modulusN)
{
	int count = 1;
	long int cTotal = 2;


	while(bSmoothNumber >= 1)
	{
		printf("%s%li%s%i\n", "old cTotal = ", cTotal, " COUNT: ", count);

		cTotal = powerFuction(cTotal, count, modulusN) % modulusN;
		count++;
		bSmoothNumber = bSmoothNumber - 1;
	}

	return cTotal;
}

//Check for B-Smooth number: a number > prime factors
bool checkB_Smooth(long int *primeFactorizationArray, long int primeArraySize, long int modulusN, long int bSmoothNumber)
{
	bool bSmooth = false;

	for(long int i = 0; i < primeArraySize; i++)
	{
		if(bSmoothNumber < primeFactorizationArray[i])
		{
			bSmooth = false;
			break;
		}
		else
		{
			bSmooth = true;
		}
	}
	return bSmooth;
}

//Find the prime factors of the a number and put into an array
long int *getPrimeFractorization(long int* primeFactorizationArray, long int modulusN)
{
	long int index = 0;

	if(modulusN % 2 == 0)
	{
		primeFactorizationArray[0] = 2;
		while(modulusN % 2 == 0)
		{
			modulusN = modulusN / 2;
		}
	}

	if(modulusN >= 3)
	{
		for(long int i = 3; modulusN > 1; i = i + 2)
		{
			if(modulusN % i == 0)
			{
				if(primeFactorizationArray[0] == 0)
				{
					primeFactorizationArray[index] = i;

				}
				else
				{

					primeFactorizationArray[index=index+1] = i;
				}

			}

			while(modulusN % i == 0)
			{
				modulusN = modulusN / i;
			}
		}
	}

	return primeFactorizationArray;
}

//Compute gcd of two numbers
long int getGCD(long int c_MultipleOfP, long int n_MultipleOfP)
{
	long int gcd = 1;

	if(c_MultipleOfP < n_MultipleOfP)
	{
		int temp =c_MultipleOfP;
		c_MultipleOfP = n_MultipleOfP;
		n_MultipleOfP = temp;
	}

	if( n_MultipleOfP % c_MultipleOfP == 0)
	{
		gcd = n_MultipleOfP;
	}
	else if(c_MultipleOfP > n_MultipleOfP )
	{
		int nMultiple = n_MultipleOfP;
		int cMultiple = c_MultipleOfP;
		bool gcdFound = false;

		for(int i=1; i < n_MultipleOfP; i++)
		{
			if(n_MultipleOfP % i == 0)
			{
				nMultiple = n_MultipleOfP / i;

				for(int j=1; j < c_MultipleOfP; j++)
				{
					cMultiple = c_MultipleOfP / j;

					if(c_MultipleOfP % j == 0)
					{

						if(nMultiple == cMultiple)
						{
							gcd = nMultiple;
							gcdFound = true;
							break;
						}
					}
				}
				if(gcdFound == true)
				{
					break;
				}
			}
			if(gcdFound == true)
			{
				break;
			}

		}
	}
	else
	{
		gcd = 1;
	}
		return gcd;
}

//Compute prime P by factorization
long int getPrimeP(long int modulusN, long int bSmoothNumber, long int c_MultipleOfP, long int* primeFactorizationArray)
{
	long int primeP = 1;
	long int tempLargeBSmooth = bSmoothNumber;

	//compute C to find P by finding a good bSmoothNumber (where c > 1)
	do
	{
		//check if modulusN is a prime number, break;
		if( primeFactorizationArray[0] == modulusN )
		{
			printf("%s%li\n", "modulusN is a prime number: ", modulusN);
			break;

		}
		printf("%s%li\n", "Current b-smooth number: ", bSmoothNumber);


		//compute C which is a multiple of P (a factor of N)
		c_MultipleOfP = computeC_Multiple(bSmoothNumber, modulusN);
		printf("%s%li\n", "C is a Multiple Of P which C = ", c_MultipleOfP );

		//compute prime P which is a factor of N
		primeP = getGCD(c_MultipleOfP-1, modulusN);
		printf("%s%li\n\n", "Prime P = ", primeP);

		//current bSmoothNumber isn't good-->get new bSmoothNumber
		if(primeP <= 1)
		{
			//if bSmoothNumber too large, find smaller bSmoothNumber
			if(bSmoothNumber > modulusN)
			{
				bSmoothNumber = modulusN/2;
				printf("%s%li\n", "Smaller b-smooth number: ", bSmoothNumber);
			}
			else //if(bSmoothNumber < modulusN)
			{
				bSmoothNumber = bSmoothNumber/2;
				printf("%s%li\n", "New b-smooth number: ", bSmoothNumber);

			}

			if(bSmoothNumber <= 0)
			{
				tempLargeBSmooth = tempLargeBSmooth + 50;

				bSmoothNumber = tempLargeBSmooth;
			}

		}

		//if gcd = N, find smaller B
		if(primeP == modulusN)
		{
			bSmoothNumber = modulusN/2;
			printf("%s%li\n", "Smaller b-smooth number: ", bSmoothNumber);
		}


	}while(primeP <= 1);

	return primeP;
}


//Recursive Extended Euclidean Algorithm
long int calculateInverseMod(long int phi, long int encryptionPublicKeyE, long int *sValue, long int *tValue)
{
	long int tempSValue = 0;
	long int tempTValue = 0;
	long int gcd = 1;

//	long int remainder = phi % encryptionPublicKeyE;
//	long int quotient = phi / encryptionPublicKeyE;
//	long int product = phi;						//x
//	long int rValue = encryptionPublicKeyE;		//y

//	long int inverseMod = 0;
//	long int sStartValue = 0;
//	long int tStartValue = 1;
//	long int product = 1914;	//x
//	long int rValue = 899;		//y
//	long int quotient = 1914 / 899;
//	long int remainder = 1914 % 899;

	//Beginning case
	if(phi == 0)
	{
		*sValue = 0;
		*tValue = 1;
		return encryptionPublicKeyE;

//		printf("%s%li\n","sValue: ", *sValue);
//		printf("%s%li\n","tValue: ", *tValue);
	}

	gcd = calculateInverseMod(encryptionPublicKeyE % phi, phi, &tempSValue, &tempTValue);

	//update recursion
	*sValue = tempTValue - (encryptionPublicKeyE / phi) * tempSValue;
	*tValue = tempSValue;

//	printf("%s%li\n","sValue: ", *sValue);
//	printf("%s%li\n","tValue: ", *tValue);

	return *tValue;
}
