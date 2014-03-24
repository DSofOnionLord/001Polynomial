#include <stdio.h>
#include <stdlib.h>

#define COEF 0
#define EXP 1

void padd(float (*ponm)[20], int sA, int sB, int eA, int eB, int n, int *sC, int *eC)
{
	int i;
	float conf;
	
	
	*eC = *sC;
	while (sA <= eA && sB <= eB)
	{
		if ( ponm[EXP][sA] > ponm[EXP][sB])
		{
			ponm[EXP][*eC] = ponm[EXP][sA];
			ponm[COEF][*eC] = ponm[COEF][sA];
			(*eC)++;
			sA++;
		}
		else if (ponm[EXP][sA] == ponm[EXP][sB])
		{
			ponm[EXP][*eC] = ponm[EXP][sA];
			ponm[COEF][*eC] = ponm[COEF][sA] + ponm[COEF][sB];
			(*eC)++;
			sA++;
			sB++;
		}
		else
		{
			ponm[EXP][*eC] = ponm[EXP][sB];
			ponm[COEF][*eC] = ponm[COEF][sB];
			(*eC)++;
			sB++;
		}
	}
	

}

int main()
{
	FILE * Inp;
	FILE * Outp;
	float polynm[2][20];
	int n, m, i;
	int point = 0;
	int startA = 0, startB, endA,endB;
	int startC, endC;

	Inp = fopen("input.txt", "r");
	Outp = fopen("output.txt", "w");
	
	fscanf(Inp, "%d %d", &n, &m);

	while(fscanf(Inp, "%f %f", &polynm[COEF][point], &polynm[EXP][point]) != EOF)
	{
		if(polynm[EXP][point] > polynm[EXP][point-1])
		{
			endA = point - 1;
			startB = point;
		}
		point ++;
	}
	endB = point -1;
	startC = point;

	padd(polynm, startA, startB, endA, endB, point, &startC, &endC);

	//printf("%d %d %d %d\n", startA, endA, startB, endB);

	for ( i = startC ; i < endC ; i ++ )
	{
		fprintf(Outp, "%5g %5.0f\n", polynm[COEF][i], polynm[EXP][i]);
	}

	fclose(Inp);
	fclose(Outp);

	return 0;
}
