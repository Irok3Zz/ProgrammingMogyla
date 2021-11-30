#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#define SIGN_FUNC(f, x) ((f(x) > 0)? 1 : (f(x) < 0)? -1 : 0)
#define CHECK_DIFF_SIGN(s1, s2) s1 != s2
#define CHECK_ROOT_TOL(f, x, e)\
if (fabs(f(x)) <= (e))\
{\
 return x;\
}

typedef double(*func_t)(double);
double f(double)
{
	return pow(x, 3) + 5,5*x - 2;
}

int localize_root(double, double, func_t)
{
	return SIGN_FUNC(f, a) != SIGN_FUNC(f, b);
}

double bisect(double a, double b, func_t f, double eps) // Бисекция
{
	while (fabs(a - b) > eps)
	{
		double c = (a + b) / 2;//Обчислюємо середню точку
		int sgn1 = SIGN_FUNC(f, a); //Обчислюємо знак в т. a
		int sgn2 = SIGN_FUNC(f, b); //Обчислюємо знак в т. b
		int sgn3 = SIGN_FUNC(f, c); //Обчислюємо знак в т. c

#ifdef PRINT_MID_STAGE
		printf("%.5f\t%.5f\t%.5f\n", a, c, b);
		printf("%d\t%d\t%d\n", sgn1, sgn3, sgn2);
#endif

		CHECK_ROOT_TOL(f, a, eps);
		CHECK_ROOT_TOL(f, c, eps);
		CHECK_ROOT_TOL(f, b, eps);

		if (CHECK_DIFF_SIGN(sgn1, sgn3))
		{
			b = c;
		}
		else {
			if (CHECK_DIFF_SIGN(sgn3, sgn2))
			{
				a = c;
			}
		}
	}
	return (a + b) / 2;
}



int main() {

	double eps = 1e-6;
	double a = -5, b = 5, h = 0.2;

	double x;
	//Локалізація коренів
	for (x = a; x < b; x += h)
	{
		if (localize_root(x, x + h, f))
		{
			printf("Root interval [%.3f, %.3f]\n", x, x + h);
			double x0 = bisect(x, x + h, f, eps);
			printf("Root value >>> %.7f\n", x0);
		}
	}


	printf("\n\n");
}