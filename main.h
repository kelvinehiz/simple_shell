#ifndef _MAINH_
#define _MAINH_

/* Required libraries */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_SIZE 1024 
/* Environmental variables */
extern char **environ;

/* Function declarations (prototypes) for main functions*/
void _lup(void);
int add(int num1, int num2)
char *_readln(void);
char **_splitln(char *line);
int _exqte(char **args, char *input);
int _launch(char **args);
void sigint_handl(int sig);

/* Function declarations (prototypes for for builtin shell commands */
int hsh_ext(char **args, char *input);
int _cd(char **args, __attribute__((unused)) char *input);
/**
  * _hlp - Help function
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if works.
  */
int _hlp(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input);

/**
  * _envr - Env function
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if works.
  */
int _envr(__attribute__((unused)) char **args,
	__attribute__((unused)) char *input);
int _setenvr(char *name, char *value);

/* Function declarations (prototypes) for auxiliary funtions */
size_t _getln(char **b, size_t *bufsize, FILE *stream);
int _getc(void);

char *_strtok(char *s, const char *delim);
char *_strtok_r(char *s, const char *delim, char **save_str);
int _strncspn(char *s, const char *delim);
int _strnspn(char *s, const char *delim);

void *_realloct(void *ptr, size_t old_size, size_t new_size);

char *_getenvr(const char *name);
char **_pat(char *path);
char **_splt_pat(char *line, char *copy_line);
char **_chek_pat(char **args, int *flag);

int _strnlen(char *s);
char *_strncatn(char *dest, char *src);
int _strncmpr(char *s1, char *s2);
char *_strncpy(char *dest, char *src);
int _strn_byt_cmpr(const char *s1, const char *s2, size_t n);
int _putchar(char c);
void _puts(char *str);
int _atoin(char *s);

#endif
