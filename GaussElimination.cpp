#include "GaussElimination.h"
#include <stdlib.h>
#include <math.h>
GaussElimination::~GaussElimination()
{
}

GaussElimination::GaussElimination()
{
}

void GaussElimination::inputMatrix(double* matrixA, double* matrixb, int dimensions)
{
	this->matrixA		= matrixA;
	this->matrixb		= matrixb;
	this->dimensions	= dimensions;
}

void GaussElimination::run(double* matrixx)
{
	int				*index=NULL;
	bool			*occupyStatus = NULL;
	int				maxIndex;
	index		 = (int*)malloc(sizeof(int) * dimensions);
	occupyStatus = (bool*)malloc(sizeof(bool) * dimensions);
	for (int i = 0; i < dimensions; i++)
		* (occupyStatus + i) = false;
	for (int i = 0; i < dimensions; i++)
	{
		maxIndex = -1;
		//Search for maxIndex
		for (int j = 0; j < dimensions; j++)
		{
			if (!*(occupyStatus+j))
			{
				if (maxIndex == -1)
				{
					maxIndex = j;
				}
				else if (fabs(*(matrixA + i * dimensions + j)) > fabs(*(matrixA + i * dimensions + maxIndex)))
				{
					maxIndex = j;
				}
			}
		}
		*(index + i) = maxIndex;
		*(occupyStatus + maxIndex) = true;
		double divisor = *(matrixA + i * dimensions + maxIndex);
		for (int j = 0; j < dimensions; j++)
		{
			*(matrixA + i * dimensions + j) /= divisor;
		}
		*(matrixb + i) /= divisor;	
		for (int j = i + 1; j < dimensions; j++)
		{
			divisor = *(matrixA + j * dimensions + maxIndex);
			for (int k = 0; k < dimensions; k++)
			{
				*(matrixA + j * dimensions + k) -= *(matrixA + i * dimensions + k) * divisor;
			}
			*(matrixb + j) -= *(matrixb + i) * divisor;
		}
	}
	for (int j = dimensions - 1; j >= 0; j--)
	{
		double sum = 0;
		for (int k = dimensions - 1; k > j; k--)
		{
			sum += *(matrixA + (*(index + k) + j * dimensions)) * *(matrixx + *(index + k));
		}
		*(matrixx + *(index + j)) = *(matrixb + j) - sum;
	}
	free(index);
	free(occupyStatus);
}
