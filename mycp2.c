#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZ 1024



int my_cp(const char *file1, const char *file2)
{
	int fd1, fd2;
	char buffer[BUF_SIZ];
	int res;
//I am linweiming


//I am xiaoming 
	fd1 = open(file1, O_RDONLY  | O_CREAT, 0666);
	if (-1 == fd1) {
		perror("open file1 failed");
		return -1;
	}
	fd2 = open(file2, O_RDWR  | O_CREAT | O_TRUNC, 0666);
	if (-1 == fd2) {
		perror("open file2 failed");
		return -1;
	}
        memset(buffer,' '  ,BUF_SIZ );
	res = read(fd1, buffer, BUF_SIZ);
	if (-1 == res) {
		perror("file1 read error");
		return -1;
	}
	

		res = write(fd2, buffer, BUF_SIZ);
	if (-1 == res) {
			perror("file2 write failed");
		return -1;
		}
		memset(buffer, 0, BUF_SIZ);
	res = read(fd1, buffer, BUF_SIZ);
		if (-1 == res) {
		perror("file1 read failed");
			return -1;
		}
	}
int main(int argc, char *argv[])
{
	if (3 != argc) {
		printf("correct usage: ./my_cp file1 file2\n");
		exit(EXIT_FAILURE);
	}

	
	
	int res = my_cp(argv[1], argv[2]);
	if (-1 == res) {
		perror("copy failed");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
