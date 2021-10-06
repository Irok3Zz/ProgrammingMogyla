#include <stdio.h>
#include <math.h>

#define first(x) y = sin(2 * cos(x / 2));
#define second(x) y = fabs(x - pi / 2);
#define third(x) y = (x - 1) / (2 + sqrt(x));

#define xy(x,y) (sqrt(x*(y+1)))/(x-y)

int main() {
	const double pi = 3.14;
	double min, max, h = 0.1, ax = -pi, bx = pi, x = ax, y; // h - шаг, [a,b] - промежуток для h, x - аргумент для функц.
	double hx = 0.25, hy = 0.15, ah = -3, bh = 3, ch = 1, dh = 2; // hx - шаг для х, hy - шаг для у, [ah,bh] - промежуток для х, [ch,dh] - промежуток для у

	for (; x <= bx; x += h)
	{
		if (x <= -pi / 2)
			y = first(x);
		if ((x > -pi / 2) && (x < pi / 2))
			y = second(x);
		if (x >= pi / 2)
			y = third(x);

		if (x == ax) {
			max = y;
			min = y;
		}

		if (y > max)
			max = y;
		if (y < min)
			min = y;
		printf("f( %f ) = %f\n", x, y);
	}
	printf("\nMin of f(x) = %f\nMax if f(x) = %f\n\n", min, max);

	for (double f, x = ah, y = ch; (x <= bh) && (y <= dh); x += hx, y += hy)
	{
		f = xy(x, y);
		if (x == ah) {
			min = f;
			max = f;
		}
		printf("f( %f, %f ) = %f\n", x, y, f);
	}
	printf("\nMin of f(x, y) = %f\nMax of f(x, y) = %f", min, max);

	printf("\n");
	return 0;
}


#pragma region Пример
//#define FUNC(x) cos(pow((x), 1.0/3))
//#define Q(x, n) -pow((x), 2.0/3.0)/2/(n+1)/(2*n+1)

//double x = 1.5, S = 0.0, a = 1.0;
//unsigned int n, N = 5;
//for (n = 0; n < N; ++n) {
//	S += a;
//	a *= Q(x, n);
//}
//double y = FUNC(x), tol = fabs(S - y);
//printf("Sum:\t\t%.7f\nControl:\t%.7f\nTolerance:\t%.7f\n",
//	S, y, tol);
#pragma endregion

#pragma region 3 задание
//#define FUNC(x) (exp(-x)+exp(x))/2
//#define Q(x, n) (4*pow(n,2)+6*n+2)/pow(x,2) 

//double x = 0.5, S = 0.0, a = 1.0;
//unsigned int n, N = 5;
//for (n = 0; n < N; ++n) {
//	S += a;
//	a *= Q(x, n);
//}
//double y = FUNC(x), tol = fabs(S - y);
//printf("Sum:\t\t%.7f\nControl:\t%.7f\nTolerance:\t%.7f\n",
//	S, y, tol);
#pragma endregion