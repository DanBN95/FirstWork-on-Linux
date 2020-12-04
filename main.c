//chen sabban - 205983836
//dan ben natan - 313196966

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {

	int fd1;  /* input file descriptor */
	int fd2;  /* input file descriptor */
	int read1;
	int read2;
	char buf1, buf2;
	int size = argc + 1;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)   /* means file open did not take place */
	{
		perror("after open ");   /* text explaining why */
		exit(-1);

	}


	fd2 = open(argv[2], O_RDONLY);
	if (fd2 < 0)   /* means file open did not take place */
	{
		perror("after open ");   /* text explaining why */
		close(fd1);  /* free allocated structures */
		exit(-1);
	}

	do {
		read1 = read(fd1, &buf1, 1);
		read2 = read(fd2, &buf2, 1);
		if (read1 > 0 && read2 > 0)
		{
			if (buf1 != buf2)
			{
				close(fd1);
				close(fd2);
				return 1;
			}
		}
		else if (read1 == 0 && read2 == 0)
			continue;
		else
		{
			close(fd1);
			close(fd2);
			return 1;
		}
	} while (read1 != 0 && read2 != 0);
	close(fd1);
	close(fd2);
	return 2;

	}
