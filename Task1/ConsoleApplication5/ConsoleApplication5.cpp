#include <iostream>
#include <math.h>
using namespace std;
void resh(double a, double b);

double func(double x)
{
	return pow(x, 3) * exp(x) * cos(x);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "\na = -10, b = -7" << std::endl;
	resh(-10, -7);
	std::cout << "\na = -6, b = -3" << std::endl;
	resh(-6, -3);
	std::cout << "\na = 0, b = 3" << std::endl;
	resh(0, 3);

	system("pause");
	return 0;
}

void resh(double a, double b) {
	const double eps = pow(10, -5);
	double t, f1, f2, x;
	do
	{
		f1 = func(a);
		t = (a + b) / 2.0;
		f2 = func(t);
		if (f1 * f2 <= 0) b = t;
		else a = t;
	} while (fabs(b - a) > eps);
	x = (a + b) / 2.0;
	f1 = func(x);
	if (fabs(f1) <= pow(10, -5))
	{
		cout << "Корень уравнения с погрешностью "; cout << fixed << eps; cout << ", x = "; cout << x << std::endl;
		cout << "Значение функции F(x)= " << f1 << std::endl;
	}
	else cout << "На данном отрезке уравнение корней не имеет" << std::endl;
}