/*


 * Joey Xiong
 * Wednesday, April 4, 2018
 *
 * not complete --> continued on sage


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

long int powerFuction(long int base, long int exponent, long int modulusN);
long int computeC_Multiple(long int bSmoothNumber, long int modulusN);
bool checkB_Smooth(long int *primeFactorizationArray, long int primeArraySize, long int modulusN, long int bSmoothNumber);
long int factorial(long int bSmoothNumber);
long int *getPrimeFractorization(long int* primeFactorizationArray, long int modulusN);
long int getGCD(long int c_MultipleOfP, long int n_MultipleOfP);
long int getNewBSmooth(long int modulusN, long int bSmoothNumber);
long int calculateInverseMod(long int phi, long int encryptionPublicKeyE);
long int calculateInverseMod(long int phi, long int encryptionPublicKeyE, long int *sValue, long int *tValue);

//int gcd(int n, int n2);

int main()
{
	bool checkBSmooth;
	long int bSmoothNumber = 100;
	long int modulusN = 4060081;
	long int bFactorialTotal = 0;
    long int c_MultipleOfP = 0;
    long int primeP = 0;
	long int encryptionPublicKeyE = 23;
	long int decryptionPrivateKeyD = 0;
    long int *primeFactorizationArray;
	long int primeArraySize = 0;


//	//prompt user input
//	printf("%s", "Enter B-smooth number: ");
//
//	//user input bSmoothNumber
//	fflush(stdout);
////	scanf("%li", &bSmoothNumber);
//
//	//prompt user input
//	printf("%s", "Enter number for modulus N: ");
//
//	//user input for modulus N
//	fflush(stdout);
////	scanf("%li", &modulusN);
//
//	//prompt user input
//	printf("%s\n", "Enter number for public key 'e': ");
//
//	//user input for public key 'e'
//	fflush(stdout);
////	scanf("%li", &encryptionPublicKeyE);

	const long int datacount = 50;
	primeFactorizationArray = malloc(sizeof(long int) * datacount);  allocate memory for 50 int's
	if (!primeFactorizationArray) {  If primeFactorizationArray == 0 after the call to malloc, allocation failed for some reason
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
	//printf("%s%li%s\n", "-----primeFactorizationArray size: ", primeArraySize, " \n");


	printf("%s%li%s", "   THE Prime Factorization Array of ", modulusN, ": ");
	for(long int i=0; i < primeArraySize; i++)
	{
		printf("%li%s", primeFactorizationArray[i], " ");
	}
	printf("\n");

	long int tempLargeBSmooth = bSmoothNumber;

	//compute C to find P by finding a good bSmoothNumber (where c > 1)
	do
	{
		//verify if BSmoothNumber is a b-smooth number (i.e. BSmoothNumber > modulusN's prime factors)
		//checkBSmooth = checkB_Smooth(primeFactorizationArray, primeArraySize, modulusN, bSmoothNumber);
		//printf("%s%d\n", "BSMOOTH CHECK: ", checkBSmooth);

		//BSmoothNumber is a b-smooth number
		//if(checkBSmooth == 1)
		{
//		bFactorialTotal = factorial(bSmoothNumber);
//		printf("%s%li\n", "\nFactorial of bSmooth Total: ", bFactorialTotal);
//		long int c_MultipleOfP = (powl(2.0, bFactorialTotal) - 1.0);

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

//			if(primeP == modulusN)
//			{
//
//			}
		}
	//	else	//bSmoothNumber is not a b-smooth number
		{
//			printf("%s%li%s%li\n", "Modulus N: ", modulusN, " is not a B-Smooth Number of ", bSmoothNumber);
//
//			bSmoothNumber = bSmoothNumber;
//			printf("%s%li%s\n","   NEW B-Smooth Number ", bSmoothNumber);
//			break;
//			}
//			else
//			{
//				printf("%s%li%s\n","   B-Smooth Number of ", bSmoothNumber, " needs to be less");
//			}
		}

	}while(primeP <= 1);

	long int primeQ = modulusN / primeP;

	long int phi = (primeP - 1) * (primeQ - 1);

	//decryptionPrivateKeyD = (1/encryptionPublicKeyE) % phi;

	printf("%s%d\n","phi: ", 1/encryptionPublicKeyE);

	printf("%s%li\n","Decryption Private Key: ", decryptionPrivateKeyD);

	calculateInverseMod(phi, encryptionPublicKeyE);

	//free memory when done
	free(primeFactorizationArray);

	return 0;
}

long int powerFuction(long int base, long int exponent, long int modulusN)
{
	long int powerTotal = base;
//	long int temp = 0;
	for(int i=1; i < exponent; i++)
	{
		//temp = powerTotal;
		powerTotal = (powerTotal % modulusN) * (base % modulusN);

//		if(powerTotal*base < LONG_MAX  )
//		{
//			printf("%s%li\n", "POWER TOO BIG ",  1921610945333886976*37232);
//		}

//		printf("%s%li%s%li%s%i\n", "     powerTotal = ", powerTotal, " base = ", base, " i = ", i+1);

	}
//	printf("%s%li\n", "     powerTotal = ", powerTotal);

	return powerTotal;
}

long int computeC_Multiple(long int bSmoothNumber, long int modulusN)
{
	int count = 1;
	long int cTotal = 2;

//	long int tempCTotal = 0;
//	long int tempCount = 0;

	while(bSmoothNumber >= 1)
	{

//		if(count)
//		{
//			tempCTotal = cTotal;
//			tempCount = count;
//		}

//		printf("%s%li%s%i\n", "old cTotal = ", cTotal, " COUNT: ", count);

		cTotal = powerFuction(cTotal, count, modulusN) % modulusN;
		count++;
		bSmoothNumber = bSmoothNumber - 1;


		if(cTotal < -1)
		{
			//while(cTotal > LONG_MAX)
			{

				cTotal = tempCTotal;
				count = tempCount;
			//	printf("%s%li\n", " new tempCTotal = ", tempCTotal);

		//	printf("%s%li\n", "new powerFuction(cTotal, count-1) % modulusN) = ", (powerFuction(cTotal, count-1) % modulusN));
//				printf("%s%li\n", "new powerFuction(cTotal, count%count) % modulusN) = ", (powerFuction(cTotal, count/count) % modulusN));

				cTotal = (powerFuction(cTotal, count-1, modulusN)) * (powerFuction(cTotal, count/count, modulusN));
				printf("%s%li\n", "new cTotal!!!!!!!!!!!!!!!!! = ", cTotal);

			}

			//break;
		}

	//	printf("%s%li\n", "new cTotal = ", cTotal);

	//printf("%s%li\n", "(powerFuction(27216, 5)) = ", 1921610945333886976*37232);


	}

	return cTotal;
}

//B-Smooth number: a number > prime factors
bool checkB_Smooth(long int *primeFactorizationArray, long int primeArraySize, long int modulusN, long int bSmoothNumber)
{
	bool bSmooth = false;

	for(long int i = 0; i < primeArraySize; i++)
	{
//		printf("%s%d", "\npfArray: ", primeFactorizationArray[i]);

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

 factorial function using recursion
long int factorial(long bSmoothNumber)
{
	if(bSmoothNumber <= 1)
	{

		return 1;

	}

	printf("%s%d%s%d%s%d", "\nbSmoothNumber ",bSmoothNumber, " * factorial(bSmoothNumber - 1) ", factorial(bSmoothNumber - 1), " Factorial Total: ", bSmoothNumber * factorial(bSmoothNumber - 1));

	return bSmoothNumber * factorial(bSmoothNumber - 1);
}

long int factorial(long int bSmoothNumber)
{
	long int factorialTotal = 1;

	for(int i = 1; i <= bSmoothNumber; i++)
	{

		factorialTotal =  factorialTotal * i;
		//printf("%s%d%s%li", "\ni ",i, " Factorial Total: ", factorialTotal);

	}
	return factorialTotal;
}

long int *getPrimeFractorization(long int* primeFactorizationArray, long int modulusN)
{
	//create new array
	//long int *primeFactorizationArray = sizePrimeFactorArray;

	//primeFactorizationArray = malloc(100* sizeof(int));
	long int index = 0;

	if(modulusN % 2 == 0)
	{
		primeFactorizationArray[0] = 2;
		while(modulusN % 2 == 0)
		{
			modulusN = modulusN / 2;

//			printf("%s%li%s\n", "Prime Factorization of 2: ", modulusN, " ");
		}
		printf("%s", "\nADD 2 to primeFactorizationArray \n");

	}

	if(modulusN >= 3)
	{
		for(long int i = 3; modulusN > 1; i = i + 2)
		{
		//	printf("%s%li%s%li%s", "i2=", i, " modulusN= " , modulusN, "\n");

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

//				printf("%s%li%s\n", "ADD ", i, " to primeFactorizationArray\n");

			}

			while(modulusN % i == 0)
			{
				modulusN = modulusN / i;
//				printf("%s%li%s%li%s", "     i=", i, " modulusN = " , modulusN, "\n");

			}
		}
	}

	return primeFactorizationArray;
}

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
//		printf("%s%li", "\ngcd = ", gcd);

	}
	else if(c_MultipleOfP > n_MultipleOfP )
	{
		//105 > 100
		int nMultiple = n_MultipleOfP;
		int cMultiple = c_MultipleOfP;
		bool gcdFound = false;

		for(int i=1; i < n_MultipleOfP; i++)
		{
			if(n_MultipleOfP % i == 0)
			{
				nMultiple = n_MultipleOfP / i;
			//	printf("\n%d%s%d\n", i, " nMultiple=", nMultiple);

				for(int j=1; j < c_MultipleOfP; j++)
				{
					cMultiple = c_MultipleOfP / j;

					if(c_MultipleOfP % j == 0)
					{
			//			printf("%d%s%d%s", j, " cMultiple=", cMultiple, "  ");

						if(nMultiple == cMultiple)
						{
							gcd = nMultiple;
							//printf("%s%li\n", "gcd=", gcd);
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

		//printf("%s%li", "\nshould be 1 gcd= ", gcd);

	}
		return gcd;
}

long int getNewBSmooth(long int modulusN, long int bSmoothNumber)
{



	return bSmoothNumber;
}

//Extended Euclidean Algorithm
long int calculateInverseMod(long int phi, long int encryptionPublicKeyE)
{
	long int inverseMod = 0;
	long int sStartValue = 0;
	long int tStartValue = 1;
//	long int remainder = phi % encryptionPublicKeyE;
//	long int multipler = phi / encryptionPublicKeyE;

	long int remainder = 12345 % 11111;
	long int quotient = 12345 / 11111;
	long int product = phi;
	long int rValue = encryptionPublicKeyE;

	printf("%s%li", "remainder ", quotient);

	//getGCD(phi, encryptionPublicKeyE) == 1 ||
	if( (phi*sStartValue) - (encryptionPublicKeyE*sStartValue) == 1)
	{

		return inverseMod;
	}
//	else{
//		printf("%s%li", "GCD of phi and encryption key is not 1. It is ", getGCD(phi, encryptionPublicKeyE));
//
//	}
	do
	{


	}while(remainder <= 0);

	return phi*sStartValue + tStartValue;
}

//Extended Euclidean Algorithm
long int calculateInverseMod(long int phi, long int encryptionPublicKeyE, long int *sValue, long int *tValue)
{
	long int inverseMod = 0;
	long int sStartValue = 0;
	long int tStartValue = 1;
//	long int remainder = phi % encryptionPublicKeyE;
//	long int quotient = phi / encryptionPublicKeyE;
//	long int product = phi;						//x
//	long int rValue = encryptionPublicKeyE;		//y

	long int product = 1914;	//x
	long int rValue = 899;		//y
	long int quotient = 1914 / 899;
	long int remainder = 1914 % 899;


	int tempX = product;
	int gcd = rValue;

	long int *productArray;
	long int *rValueArray;
	long int *quotientArray;
	long int *remainderArray;

	long int index = 1;
	long int arraySize = 0;

	const long int datacount = 50;
	productArray = malloc(sizeof(long int) * datacount); /* allocate memory for 50 int's
	if (!productArray) {  If array == 0 after the call to malloc, allocation failed for some reason
		perror("Error allocating memory");
		abort();
	}
    memset(productArray, 0, sizeof(long int)*datacount);

	rValueArray = malloc(sizeof(long int) * datacount);  allocate memory for 50 int's
	if (!rValueArray) {  If array == 0 after the call to malloc, allocation failed for some reason
		perror("Error allocating memory");
		abort();
	}
    memset(rValueArray, 0, sizeof(long int)*datacount);

    quotientArray = malloc(sizeof(long int) * datacount);  allocate memory for 50 int's
	if (!quotientArray) {  If array == 0 after the call to malloc, allocation failed for some reason
		perror("Error allocating memory");
		abort();
	}
    memset(quotientArray, 0, sizeof(long int)*datacount);

    remainderArray = malloc(sizeof(long int) * datacount);  allocate memory for 50 int's
	if (!remainderArray) {  If array == 0 after the call to malloc, allocation failed for some reason
		perror("Error allocating memory");
		abort();
	}
    memset(remainderArray, 0, sizeof(long int)*datacount);

    //Initialize array at index 0
    productArray[0] = product;
	rValueArray[0] = rValue;
	quotientArray[0] = quotient;
	remainderArray[0] = remainder;

	for(int i = remainder; i > 0; i = product % rValue)
	{

		product = quotient * rValue + i;

		//swap values
		product = rValue;
		rValue = i;

		productArray[index] = product;
		rValueArray[index] = rValue;
		quotientArray[index] = product/rValue;
		remainderArray[index] = product%rValue;

		gcd = rValue;
		tempX = product;
		index++;


	}
	printf("%s%li\n", "tempY ",gcd);

	arraySize =	index;
	long int temp1;
	long int temp2;
	for(int i = arraySize-1; i >= 0; i--)
	{


//		printf("%s%li\n", "   productArray ", i);
		printf("%s%li\n", "   productArray ", productArray[i]);
	//	printf("%s%li\n", "   rValueArray ", rValueArray[i]);
	//	printf("%s%li\n", "   quotientArray ", quotientArray[i]);
	//	printf("%s%li\n", "   remainderArray ", remainderArray[i]);
	}

	//free(array);

	return 0;
}
*/


