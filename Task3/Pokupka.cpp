#include <iostream>
using namespace std;

/*
 * �������� ��������� ���������� ��������� ������� � ������ ������
 * . ������ � X ��������� ���������������,���� ����� ������� ������ A ������,
 *  � Y ��������� - ���� ����� ������ B ������.
 *  � ����������� ����� ���������� ���� ������������ �����, ���������� ��������: N, A, B, X, Y (A < B)
 *  - ��� N - �������� ��������� ������. �������� ��������� ������� � ������ ������.
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
