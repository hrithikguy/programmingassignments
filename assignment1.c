#include <stdio.h>
#include <math.h>

long int euclid(long int a, long int b) {
	if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}
	else if (a == b) {
		return a;
	}
	else if (a > b) {
		return euclid(b, a - b);
	}
	else {
		return euclid(a, b - a);
	}
}

int isprime (int n) {
	int i;
	for (i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

void exchange(int *a, int *b) {
	*a = *b + *a;
	*b = *a - *b;
	*a = *a - *b;
}

void factorize(int n) {
	int i;
	for (i = 2; i <= n; ++i) {
		if (n % i == 0 && isprime(i) == 1) {
			printf("%d ", i);
			factorize(n/i);
			break;
		}
	}
}

int squarecheck (int n) {
	int i;
	for (i = 1; i <= sqrt(n) + 1; ++i) {
		if (i*i == n) {
			return 1;
		}
	}
	return 0;
}

int triangularcheck (int n) {
	int i;
	for (i = 1; i <= 2*sqrt(n) + 1; ++i) {
		if (i*(i+1)/2 == n) {
			return 1;
		}
	}
	return 0;
}

int squareandtriangular (int n) {
	if (squarecheck(n) == 1 && triangularcheck(n) == 1) {
		return 1;
	}
	return 0;
}

void axplusby (long int a, long int b) {
	long int gcd = euclid(a, b);
	long int i, j;
	for (i = -b; i <= b; ++i) {
		for (j = -a; j <= a; ++j) {
			if (a*i + b * j == gcd) {
				printf("%ld * %ld + %ld * %ld = %ld\n", a, i, b, j, gcd);
				return;
			}
		}
	}
}



void congruence(long int a, long int c, long int m) {
	//printf("%ld\n", euclid(a, m));
	//printf("%ld\n", c % (int) euclid(a,m));
	if (c % (int) euclid (a, m) != 0) {
		printf("Error: value of gcd is %ld\n", euclid(a, m));
		return;
	}
	long int x = 0;
	int counter = 0;
	while (counter <= euclid(a, m) && x <= m) {
		if ((a * x) % m == c % m) {
			printf("%d: %ld\n", counter+ 1, x);
			++counter;
		}
		++x;
	}
}

int removeprime(int n, int p) {
	int k = n;
	while (k % p == 0) {
		k = k/p;
	}
	return k;
}

int highestpower(int n, int p) {
	int k = n;
	int counter = 0;
	while (k % p == 0) {
		k = k/p;
		++counter;
	}
	return counter;
}


int phi(int n) {
	if (n == 1) {
		return 1;
	}
	//printf("phi called on %d\n", n);
	if (isprime(n)) {
		//printf("returned %d\n", n-1);
		return n - 1;
	}
	int i;
	for (i = 2; i <= n; ++i) {
		if (n % i == 0 && isprime(i) == 1) {
			//printf("prime factor: %d\n", i);
			return (pow(i, highestpower(n, i)) - pow(i, highestpower(n, i) - 1)) * phi(removeprime(n, i));
			break;
		}
	}
	return n - 1;
}


void problemsix(int b, int m, int c, int n) {
	if (euclid(m, n) != 1) {
		printf("Error: gcd(m,n) is not equal to 1\n");
		return;
	}
	int i;
	for (i = 0; i <= m*n; ++i) {
		if (i % m == b % m && i % n == c % n) {
			printf("x is %d\n", i);
			return;
		}
	}
}



int main()
{
	int x, y;
	x = 5;
	y = 55;
	printf("x is %d and y is %d\n", x, y);
	exchange (&x, &y);
	printf("x is %d and y is %d\n", x, y);
	
	printf("%d %d\n", isprime(2), isprime(6));
	printf("%ld %ld\n", euclid(5, 7), euclid(6, 9));
	
	factorize(9105293);
	printf("\n");
	//axplusby (19789, 23548);
	//axplusby (31875, 8387);
	printf("\n\n\n");
	int i;
	/*for (i = 1; i <= 100; ++i) {
		printf("%d: %d\n", i, squareandtriangular(i));
	}*/

	printf("\n\n\n");

	/*congruence(3, 5, 4);
	congruence (7, 6, 5);
	congruence (6, 3, 9);*/
	//congruence(893, 266, 2432);
	//printf("%d\n", phi(10));
	//printf("%d", highestpower(54, 3));
	problemsix(8, 11, 3, 19);
	return 0;
}




