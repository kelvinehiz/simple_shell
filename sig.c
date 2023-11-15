#include "main.h"

/**
  * sigint_handl - Signal handler.
  * @sig: signal.
  */

void sigint_handl(int sig)
{
	(void)sig;
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);

}
