#pragma once

class GaussElimination {
public:
	~GaussElimination();
	GaussElimination();
	/*
	@author DevoutPrayer
	@param	matrixA		���Է������ϵ������
			matrixb		���Է������b����
			dimensions	���Է������ά��
	@return void
	*/
	void inputMatrix(double*, double*, int);
	/*
	@author DevoutPrayer
	@param	matrixx		���Է�����Ľ�
	@return void
	*/
	void run(double*);
private:
	double* matrixA;
	double* matrixb;
	int		dimensions;
};
