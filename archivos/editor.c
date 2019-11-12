#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void escribir(int dest, char *text) {
  write(dest, text, strlen(text));
  write(dest, " ", 1);
}

int main(int argc, char **argv) {
  char *fileName = argv[1]; // nombre del archivo
  char word[100];           // buffer para ir guardando las palabras
  char c;                   // para leer caracter
  int fd2 = open("tmp.txt", O_WRONLY | O_CREAT, 0666);
  int i = 0;
  int fd = open(fileName, O_RDONLY);
  while (read(fd, &c, 1)) {
    if (c != ' ') {
      word[i++] = c;
    } else {
      word[i] = '\0';
      i = 0;
      if (!strcmp(word, argv[2])) { // las palabras son iguales, se cambia la palabra
        escribir(fd2, argv[3]);
      } else {                     // las palabras son diferentes, se deja la misma palabra
        escribir(fd2, word);
      }
    }
  }
  word[i] = '\0';
  if (!strcmp(word, argv[2])) { 
    escribir(fd2, argv[3]);
  } else { 
    escribir(fd2, word);
  }

  unlink(fileName);
  link("tmp.txt", fileName);
  unlink("tmp.txt");
  close(fd2);
  close(fd);
  return 0;
}
