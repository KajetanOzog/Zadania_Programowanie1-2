//Kajetan Ozog
#include <iostream>
using namespace std;
int numofel(int array[])
{
	int number = 0;
	while (array[number] != -1)
	{
		number++;
	}
	number++;
	return number;

}


void Sort(int size, int array[]) 
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int x = 0;
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
		}
	}

}


void Add(int number, int array[])
{
	if ((number < 4096) && (number > 0))
	{
		bool belongs = true;
		bool notstop = true;
		int i = 0;
		while (notstop) {
			if (array[i] == number)
			{
				belongs = false;
				notstop = false;
			}
			if (array[i] == -1)
			{
				notstop = false;
				if (belongs) {
					array[i + 1] = -1;
					array[i] = number;
					Sort(i+1, array); //Do sprawdzenia
				}
			}
			i++;
		}
	}
}


void Create(int number, int oldarray[], int array[])
{
	array[0] = -1;
	for (int i = 0; i < number; i++)
	{
		Add(oldarray[i], array);
	}
}


void Complement(int array1[], int array2[])
{
	int index = 0;
	int num1 = numofel(array1) - 1;
	for (int i = 1; i < 4096; i++)
	{
		bool belongs = true;
		for (int j = 0; j < num1; j++)
		{
			if (i == array1[j])
			{
				belongs = false;
			}
		}
		if (belongs)
		{
			array2[index] = i;
			index++;
		}
	}
	array2[index] = -1;
}


void Union(int array1[], int array2[], int array[])
{
	int num1 = numofel(array1) - 1;
	int num2 = numofel(array2) - 1;
	int numofelem = 0;
	for (int i = 0; i < num1; i++)
	{
		array[i] = array1[i];
		numofelem++;
	}
	for (int i = 0; i < num2; i++)
	{
		bool belongs = true;
		for (int j = 0; j < numofelem; j++)
		{
			if (array2[i] == array[j])
			{
				belongs = false;
			}
		}
		if (belongs)
		{
			array[numofelem] = array2[i];
			numofelem++;
		}
	}
	array[numofelem] = -1;
	Sort(numofelem, array);
}


void Intersection(int array1[], int array2[], int array[])
{
	int num1 = numofel(array1) - 1;
	int num2 = numofel(array2) - 1;
	int numofelem = 0;
	for (int i = 0; i < num1; i++)
	{
		bool belongs = false;
		for (int j = 0; j < num2; j++)
		{
			if (array1[i] == array2[j])
			{
				belongs = true;
			}
		}
		if (belongs)
		{
			array[numofelem] = array1[i];
			numofelem++;
		}
	}
	array[numofelem] = -1;
	Sort(numofelem, array);
}


void Difference(int array1[], int array2[], int array[])
{
	int num1 = numofel(array1) - 1;
	int num2 = numofel(array2) - 1;
	int numofelem = 0;
	for (int i = 0; i < num1; i++)
	{
		bool belongs = true;
		for (int j = 0; j < num2; j++)
		{
			if (array1[i] == array2[j])
			{
				belongs = false;
			}
		}
		if (belongs)
		{
			array[numofelem] = array1[i];
			numofelem++;
		}
	}
	array[numofelem] = -1;
	Sort(numofelem, array);
}


void Symmetric(int array1[], int array2[], int array[])
{
	int num1 = numofel(array1) - 1;
	int num2 = numofel(array2) - 1;
	int numofelem = 0;
	for (int i = 0; i < num1; i++)
	{
		bool belongs = true;
		for (int j = 0; j < num2; j++)
		{
			if (array1[i] == array2[j])
			{
				belongs = false;
			}
		}
		if (belongs)
		{
			array[numofelem] = array1[i];
			numofelem++;
		}
	}
	for (int j = 0; j < num2; j++)
	{
		bool belongs = true;
		for (int i = 0; i < num1; i++)
		{
			if (array2[j] == array1[i])
			{
				belongs = false;
			}
		}
		if (belongs)
		{
			array[numofelem] = array2[j];
			numofelem++;
		}
	}
	array[numofelem] = -1;
	Sort(numofelem, array);
}


bool Subset(int array1[], int array2[])
{
	int points = 0;
	int num1 = numofel(array1) - 1;
	int num2 = numofel(array2) - 1;
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			if (array1[i] == array2[j])
			{
				points++;
				break;
			}
		}
	}
	bool result = false;
	if (points == num1)
	{
		result = true;
	}
	return result;
}


bool Equal(int array1[], int array2[])
{
	int num1 = numofel(array1) - 1;
	int num2 = numofel(array2) - 1;
	if (num1 != num2)
	{
		return false;
	}
	int points = 0;
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			if (array1[i] == array2[j])
			{
				points++;
				break;
			}
		}
	}
	bool result = false;
	if (points == num1)
	{
		result = true;
	}
	return result;
}


bool Empty(int array1[])
{
	if (array1[0] == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Nonempty(int array1[])
{
	if (array1[0] == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool Element(int number, int array1[])
{
	int num1 = numofel(array1) - 1;
	for (int i = 0; i < num1; i++)
	{
		if (number == array1[i])
		{
			return true;
		}
	}
	return false;
}


double Arithmetic(int array1[])
{
	double num1 = numofel(array1) - 1;
	if (num1 == 0)
	{
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < num1; i++)
	{
		double cos = array1[i];
		cos = cos/1;
		sum = sum + cos;
	}
	double result = sum / num1;
	return result;
}


double Harmonic(int array1[])
{
	double num1 = numofel(array1) - 1;
	if (num1 == 0)
	{
		return 1;
	}
	double sum = 0;
	for (int i = 0; i < num1; i++)
	{
		double cos = array1[i];
		cos = 1/cos;
		sum = sum + cos;
	}
	double result = 0;
	result = num1/sum;
	return result;
}


void MinMax(int array1[], int *min, int& max)
{
	int minimum = 4095;
	int maximum = 0;
	int num1 = numofel(array1) - 1;
	for (int i = 0; i < num1; i++)
	{
		if (array1[i] > maximum)
		{
			maximum = array1[i];
		}
		if (array1[i] < minimum)
		{
			minimum = array1[i];
		}
	}
	if (num1 != 0)
	{
		*min = minimum;
		max = maximum;
	}

}


void Cardinality(int array1[], int* power)
{
	int number = 0;
	while (array1[number] != -1)
	{
		number++;
	}
	*power = number;
}


void Properties(int array1[], char operations[], double& arithmetic, double* harmonic, int& min, int* max, int& power)
{
	char mark = 'f';
	int i = 0;
	while (operations[i] != '\0')
	{
		mark = operations[i];
		if (mark == 'a')
		{
			double avga = Arithmetic(array1);
			arithmetic = avga;
		}
		if (mark == 'h')
		{
			double avgh = Harmonic(array1);
			*harmonic = avgh;
		}
		if (mark == 'm')
		{
			if ((numofel(array1) - 1) > 0)
			{
				int minimum = 0;
				int *pmin = &minimum;
				int maksimum = 0;
				MinMax(array1, pmin, maksimum);
				min = minimum;
				*max = maksimum;
			}
		}
		if (mark == 'c')
		{
			int po_wer = 0;
			int *ppo_wer = &po_wer;
			Cardinality(array1, ppo_wer);
			power = po_wer;
		}
		i++;
	}
}