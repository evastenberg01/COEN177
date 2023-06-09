/* Name: Eva Stenberg
 * Date: 11/15/2022
 * Title: Lab 9 - File Performance Measurement
 * Description: This program evaluates file system performance during sequential I/O requests
 * by reading and writing to the disk. Step 3 of lab. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc < 3) //error checking
	{
		printf("Error: not enough command line arguments. \n");
		return 0;
	}
	int buf_size = atoi(argv[2]); //converts the cmd line argument to an int
	char buffer[buf_size];
	FILE *fp;
	fp = fopen(argv[1], "rb"); //open file
	while(fread(buffer, sizeof(buffer), 1, fp)) //keeps reading the file until the number of elements read is 0 (end of file)
	{
	}
	fclose(fp); //close file
	return 0;
}