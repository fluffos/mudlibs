//Zine 2012/12/12
//处理一些lpc不带的数学公式
int max(int *numbers)
{
	int max=numbers[0];
	for (int i=0;i<sizeof(numbers);i++)
	if (numbers[i]>max)
	max=numbers[i];
	return max;
}
int min(int *numbers)
{
	int min=numbers[0];
	for (int i=0;i<sizeof(numbers);i++)
	if (numbers[i]<min)
	min=numbers[i];
	return min;
}
int ave(int *numbers)
{
	int total=0;
	if (sizeof(numbers)==0)
	return 0;
	for (int i=0;i<sizeof(numbers);i++)
	total+=numbers[i];
	return total/sizeof(numbers);
}
float f_max(float *numbers)
{
	float max=numbers[0];
	for (int i=0;i<sizeof(numbers);i++)
	if (numbers[i]>max)
	max=numbers[i];
	return max;
}
float f_min(float *numbers)
{
	float min=numbers[0];
	for (int i=0;i<sizeof(numbers);i++)
	if (numbers[i]<min)
	min=numbers[i];
	return min;
}
float f_ave(float *numbers)
{
	float total=0.0;
	if (sizeof(numbers)==0)
	return 0.0;
	for (int i=0;i<sizeof(numbers);i++)
	total+=numbers[i];
	return total/to_float(sizeof(numbers));
}