#pragma once
class Matrix
{
public:
	Matrix();
	Matrix(int , int);
	~Matrix();
	bool operator==(const Matrix &)const;
	Matrix  operator+(const Matrix&)const;
	Matrix  operator-(const Matrix&)const;
	Matrix  operator*(const Matrix&)const;
	void m_print_mat() const;
	void m_saisire_val_mat();


private:
	int lig, col;
	float ** mat;


};

