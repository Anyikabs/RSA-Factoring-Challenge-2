#include <stdio.h>

int check_factor(int num1, int num2)
{

	int product = num1 * num2;

	printf("%d=%d*%d\n", product, num1, num2);

}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}

	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		perror("Error opening file");
		return (1);

	}

	int num;

	while (fscanf(fp, "%d", &num) == 1)
	{

		for (int i = 2; i <= num / 2; i++)
		{

			if (num % i == 0)
			{

				check_factor(i, num / i);

				break;

			}
		}
	}
	fclose(fp);

	return (0);
}
