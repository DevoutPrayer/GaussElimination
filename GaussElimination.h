#pragma once

class GaussElimination {
public:
	~GaussElimination();
	GaussElimination();
	/*
	@author DevoutPrayer
	@param	matrixA		线性方程组的系数方阵
			matrixb		线性方程组的b矩阵
			dimensions	线性方程组的维度
	@return void
	*/
	void inputMatrix(double*, double*, int);
	/*
	@author DevoutPrayer
	@param	matrixx		线性方程组的解
	@return void
	*/
	void run(double*);
private:
	double* matrixA;
	double* matrixb;
	int		dimensions;
};
