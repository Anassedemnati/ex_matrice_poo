#include "pch.h"
#include "Matrix.h"
#include<iostream>
using namespace std;

Matrix::Matrix()
{
	this->col = 0;
	this->lig = 0;
	this->mat = new float* [0];

}

Matrix::Matrix(int lig,int col)
{
	this->lig = lig;
	this->col = col;
	this->mat = new float* [this->lig];
	for (int i = 0; i < this->lig; i++)
	{
		this->mat[i] = new float[this->col];
	}
	for (int i = 0; i < this->lig; i++) {
		for (int j = 0; j < this->col; j++)
		{
			this->mat[i][j] = 0;
		}



	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->lig; i++)
	{
		delete [] this->mat[i];
		this->mat[i] = 0;
	}
	delete[] this->mat;
	this-> mat = 0;
}

bool Matrix::operator==(const Matrix & ma)const
{
	int cpt = 0;
	if (this->lig == ma.lig && this->col == ma.col) {
		for (int i = 0; i < this->lig; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				if (this->mat[i][j] == ma.mat[i][j]) {
					cpt++;
				}
			}
		}
		if (cpt==(this->lig*this->col))
		{
			return true;
		}

	}
	else
	{
		cout << "les deux matrice ne sont pas egale" << endl;
	}
	
	return false;
}

Matrix Matrix::operator+(const Matrix & mo)const
{
	
	if (this->lig == mo.lig && this->col == mo.col) {
		Matrix newv(this->lig, this->col);
		for (int i = 0; i < this->lig; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				newv.mat[i][j] = this->mat[i][j] + mo.mat[i][j];
					
				
			}
		}



		return newv;
	}
	else
	{
		cout << "les deux matrice ne sont pas egale" << endl;
	}




	
}

Matrix Matrix::operator-(const Matrix& mo) const
{


	if (this->lig == mo.lig && this->col == mo.col) {
		Matrix newv(this->lig, this->col);
		for (int i = 0; i < this->lig; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				newv.mat[i][j] = this->mat[i][j] - mo.mat[i][j];


			}
		}



		return newv;
	}
	else
	{
		cout << "les deux matrice ne sont pas egale" << endl;
	}


	
}

Matrix Matrix::operator*(const Matrix& mo) const
{
	if (this->lig == mo.lig && this->col == mo.col) {
		Matrix newv(this->lig, this->col);
		for (int i = 0; i < this->lig; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				for (int k = 0; k < this->lig; k++)
				{
					newv.mat[i][j] += (this->mat[i][k] * mo.mat[k][j]);
				}
				


			}
		}



		return newv;
	}
	else
	{
		cout << "les deux matrice ne sont pas egale" << endl;
	}
}

void Matrix::m_print_mat()const
{

	for (int i = 0; i < this->lig; i++)
	{
		cout << "---------------" << endl;
		cout << "|              |" << endl;
		for (int j = 0; j < this->col; j++)
		{
			
			
			cout <<"|"<< this->mat[i][j]<<"|" << endl;
			
			
			



		}
		cout << "|              |" << endl;
		cout << "---------------" << endl;
	}

}

void Matrix::m_saisire_val_mat( )
{

	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			cout << "doner la valeur mat[" << i << "][" << j << "]" << endl;
			cin >> this->mat[i][j];


		}
	}


}
