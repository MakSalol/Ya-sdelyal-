#include <iostream>
using namespace std;

/*
 * Написать программу вычисления стоимости покупки с учётом скидки
 * . Скидка в X процентов предоставляется,если сумма покупки больше A рублей,
 *  в Y процентов - если сумма больше B рублей.
 *  В стандартном вводе содержится пять вещественных чисел, разделённых пробелом: N, A, B, X, Y (A < B)
 *  - где N - исходная стоимость товара. Выведите стоимость покупки с учётом скидки.
 */

int main() {
	double N,A,B,X,Y;
	cout << "Vvedite stoimost' pokupki" << endl;
	cin >> N;
	cout << "Vvedite A" << endl;
	cin >> A;
	cout << "Vvedite B" << endl;
	cin >> B;
	cout << "Vvedite X" << endl;
	cin >> X;
	cout << "Vvedite Y" << endl;
	cin >> Y;
	if (A < B){
		if (N > A && N < B) {
			cout << N-(N*(X/100));
		}
		else if (N < A) {
			cout << N;
		}
		else if (N > B) {
			cout << N-(N*(Y/100));
		}
	}
	else  cout << "Error";
}
