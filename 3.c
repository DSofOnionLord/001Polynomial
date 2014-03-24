#include <stdio.h>
#include <stdlib.h>

struct item
{
	float coef;
	int exp;
};



void padd(struct item *ponm, int sA, int sB, int eA, int eB, int n, int *sC, int *eC)
{
	int i;
	float conf;
	
	
	*eC = *sC;
	while (sA <= eA && sB <= eB)
	{
		if ( ponm[sA].exp > ponm[sB].exp)
		{
			ponm = (struct item*)realloc(ponm, sizeof(struct item) * ((*eC)+1));
			ponm[*eC].exp = ponm[sA].exp;
			ponm[*eC].coef = ponm[sA].coef;
			(*eC)++;
			sA++;
		}
		else if (ponm[sA].exp == ponm[sB].exp)
		{
			ponm = (struct item*)realloc(ponm, sizeof(struct item) * ((*eC)+1));
			ponm[*eC].exp = ponm[sA].exp;
			ponm[*eC].coef = ponm[sA].coef + ponm[sB].coef;
			(*eC)++;
			sA++;
			sB++;
		}
		else
		{
			ponm = (struct item*)realloc(ponm, sizeof(struct item) * ((*eC)+1));
			ponm[*eC].exp = ponm[sB].exp;
			ponm[*eC].coef = ponm[sB].coef;
			(*eC)++;
			sB++;
		}
	}
	

}

int main()
{
	FILE * Inp;
	FILE * Outp;
	struct item *polynm;
	int n, m, i;
	int point = 0;
	int startA = 0, startB, endA,endB;
	int startC, endC;

	Inp = fopen("input.txt", "r");
	Outp = fopen("output.txt", "w");
	
	fscanf(Inp, "%d %d", &n, &m);

	polynm = (struct item *) malloc (sizeof(struct item) * (n+m));

	while(fscanf(Inp, "%f %d", &polynm[point].coef, &polynm[point].exp) != EOF)
	{
		if(polynm[point].exp > polynm[point-1].exp)
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
		fprintf(Outp, "%5g %5d\n", polynm[i].coef, polynm[i].exp);
	}

	free(polynm);
	fclose(Inp);
	fclose(Outp);

	return 0;
}
