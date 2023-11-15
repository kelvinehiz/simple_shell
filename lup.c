#include "main.h"

/**
 * _lup - Returns a pointer to a newly allocated space in memory
*/

void _lup(void)
{
	char *input;
	char **args;
	int status;
	int inter = 1, len;

	if (isatty(STDIN_FILENO) != 1)
		inter = 0;

	signal(SIGINT, sigint_handl);

	do {
		if (inter != 0)
		{
			/* Print prompt line. */
			len = _strnlen("$ ");
			/*printf("#cisboring$ ");*/
			write(STDOUT_FILENO, "$ ", len);
		}

		/*Read from promt line (input) */
		input = _readln();
		if (input == NULL)
			return;

		/* Split readed input into arguments. */
		args = _splitln(input);
		if (args == NULL)
		{
			free(input);
			return;
		}

		/* Execute according to arguments. */
		status = _exqte(args, input);

		/* Free input and arguments. */
		free(input);
		free(args);

	} while (status == 0);
}
