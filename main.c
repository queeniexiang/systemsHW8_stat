#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>


int main() {
  int num = 10101010;  

  int fd = open("stat_file", O_CREAT | O_EXCL | O_RDWR);
  write(fd, &num, sizeof(int));
  close(fd); 

  struct stat ab; 
  stat("stat_file", &ab);

  long value = ab.st_size;

  printf("Printing file size: \n"); 
  printf("File Size: %ld\n\n", value);

  printf("Printing permissions: \n"); 
  int mode = ab.st_mode;
  //NOTE %o NOT %d
  printf("Permissions: %o\n\n", mode);

  printf("Printing time: \n"); 
  long * time = &ab.st_mtime; 
  printf("Last accessed time: %s", ctime(time)); 
}


		
