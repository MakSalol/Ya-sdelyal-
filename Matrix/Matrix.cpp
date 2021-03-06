#include <iostream>
#include <vector>
#include <sstream>
#include <exception>
#include <sstream>
using namespace std;

class Matrix{
private:
	vector<vector<int>> Matrica;
	stringstream ss;
public:
	Matrix(){

	}

	Matrix(int NumRows, int NumCols){
		if ((NumRows < 0) || (NumCols < 0)){
			ss << "Error: "  << " error: out_of_range";
			throw out_of_range(ss.str());
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

Matrix operator *(Matrix& Matrica1, Matrix& Matrica2){
	stringstream ss;
	if(Matrica1.GetNumColums() != Matrica2.GetNumRows()){
	//ss << "Error" << endl <<"error: invalid_argument";
	//throw invalid_argument(ss.str());
		//cout << "Error" << endl;
	}
	else{
		Matrix Matrica3(Matrica1.GetNumRows(), Matrica2.GetNumColums());
		for (int j = 0; j < Matrica1.GetNumRows(); j++){
			for (int z = 0; z < Matrica2.GetNumColums(); z++){
				Matrica3.At(j,z) = 0;
				for(int i = 0; i < Matrica2.GetNumRows(); i++){
					Matrica3.At(j,z) += Matrica1.At(j,i) * Matrica2.At(i,z);
				}
			}
		}
		return Matrica3;
	}
}


int main(){
	Matrix Matrica1;
	Matrix Matrica2;
	cin >> Matrica1 >> Matrica2;
	//cout << Matrica1 << endl << Matrica2;
	Matrix Matrica3 = Matrica1 * Matrica2;
	cout << Matrica3;
}
