/* Name: Eva Stenberg
 * Date: 11/15/2022
 * Title: Lab8 - Memory management
 * Description: This program generates the testInput.txt file.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[sizeof(int)];
	int i;
	fp = fopen("testInput10K.txt", "w");
	for(i = 0; i < 10000; i++)
	{
		sprintf(buffer, "%d\n", rand()%1000);
		fputs(buffer, fp);
	}
	fclose(fp);
	return 0;
}