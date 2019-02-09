#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Matrix{
private:
	vector<vector<int>> Matrica;
public:
	Matrix(){

	}

	Matrix(int NumRows, int NumCols){
		if ((NumRows < 0) || (NumCols < 0)){
			cout << "Error";
		}
		vector<int> Cols(NumCols);
		for (int i = 0; i < NumRows; i++){
			Matrica.push_back(Cols);
		}
	}

	void Reset(int NumRows, int NumCols){
		if((NumRows < 0) || (NumCols < 0)){
			cout << "Error";
		}
		Matrica.clear();
		vector<int> Cols(NumCols);
		for (int i = 0; i < NumRows; i++){
			Matrica.push_back(Cols);
		}
	}

	 int At(int NumRow, int NumCol)const {
		return Matrica[NumRow][NumCol];
	}
	int& At(int NumRow, int NumCol){
		int& a = Matrica[NumRow][NumCol];
		return a;
	}

	int GetNumRows()const {
		return Matrica.size();
	}

	int GetNumColums()const {
		return Matrica[0].size();
	}
};


istream& operator >>(istream& stream, Matrix& Matrica){
	int Rows, Cols, Element;
	cout << "Vvedite Matricu" << endl;
	stream >> Rows >> Cols;
	Matrica.Reset (Rows, Cols);
	for (int i = 0; i < Rows; i++){
		for (int m = 0; m < Cols; m++){
			stream >> Element;
			Matrica.At(i,m) = Element;
		}
	}
	return stream;
}

ostream& operator <<(ostream& stream, Matrix& Matrica){
	stream << Matrica.GetNumRows()<< " " << Matrica.GetNumRows() << endl;
	for (int i = 0; i < Matrica.GetNumRows(); i++){
		for(int m = 0; m < Matrica.GetNumColums(); m++){
			stream << Matrica.At(i,m) <<" ";
		}
		stream << endl;
	}
	return stream;
}

bool operator ==(Matrix& Matrica1, Matrix& Matrica2){
	if ((Matrica1.GetNumRows() == Matrica2.GetNumRows()) && (Matrica1.GetNumColums() == Matrica2.GetNumColums())){
		for (int i = 0; i < Matrica1.GetNumRows(); i++){
			for (int m = 0; m < Matrica1.GetNumColums(); m++){
				if (Matrica1.At(i,m) != Matrica2.At(i,m)){
					return false;
				}
			}
		}
		return true;
	}
	else{
		return false;
	}
}

Matrix operator +(Matrix& Matrica1, Matrix& Matrica2){
	if ((Matrica1.GetNumRows() != Matrica2.GetNumRows()) || (Matrica1.GetNumColums() != Matrica2.GetNumColums())){
		cout << "Error" << endl;
	}
	Matrix Matrica(Matrica1.GetNumRows(), Matrica1.GetNumColums());
	for (int i = 0; i < Matrica.GetNumRows(); i++){
		for (int m = 0; m < Matrica.GetNumColums(); m++){
			Matrica.At(i,m) = Matrica1.At(i,m) + Matrica2.At(i,m);
		}
	}
	return Matrica;
}


int main(){
	Matrix Matrica1;
	Matrix Matrica2;
	cin >> Matrica1 >> Matrica2;
	Matrix Matrica3 = Matrica1 + Matrica2;
	cout << Matrica3;
}
