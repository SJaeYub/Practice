#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h> 
#define BUFSIZE 512 /* 한 번에 읽을 문자열의 크기 */
#define PERM 0644 /* 새로 만든 파일의 사용 권한 */ 

/**
 * 파일을 복사하여 사본을 생성한다.
 * @param name1 원본 파일 이름
 * @param name2 사본 파일 이름
 * @return 처리 결과를 숫자 형태로 반환 (자유롭게 정의하여 사용)
 */
int copy_file(const char *name1, const char *name2); 
void create_holed_file(const char *str);
void fatal(const char *str, int errno);

int main(){
  create_holed_file("file.hole");
  return copy_file("file.hole", "file2.hole");
}

int copy_file(const char *name1, const char *name2) { 
  int name1_fd, n, name2_fd;
  mode_t mode;
  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  if((name1_fd = open(name1, O_CREAT, mode)) == -1) {
    perror("creat");
    exit(1);
  }
  ////////creat complete//////
  char buf[BUFSIZE];
  if((n = read(name1_fd, buf, 512)) == -1) {
    perror("read");
    exit(1);
  }
  buf[n] = '\0';
  //////////read complete///////
  if((name2_fd = open(name2, O_CREAT | O_WRONLY, mode)) == -1) {
    perror("creat2");
    exit(1);
  }

  if(write(name2_fd, buf, n) != n) {
    perror("write");
    exit(1);
  }

  close(name2_fd);
  close(name1_fd);
} 

void create_holed_file(const char *str){
  char buf1[] = "abcdefghij", buf2[] = "ABCDEFGHIJ";
  int fd; 

  if ((fd = creat(str, 0640)) < 0)
    fatal("creat error", 1);

  if (write(fd, buf1, 10) != 10)
    fatal("buf1 write error", 1);
    
  if (lseek(fd, 40, SEEK_SET) == -1) 
    fatal("lseek error", 1);

  if (write(fd, buf2, 10) != 10) 
    fatal("buf2 write error", 1);
}

void fatal(const char *str, int errcode){
     perror(str);
     exit(errcode);
}
