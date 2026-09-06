#include <lord.h>

/*
	Lord command:   lordlog
	Syntax:         lordlog
	Conditions:
		User must be level 28 or higher
	Effects:
		Displays the log file of servants for a log
*/
int lordlog_cmd()
{
    if (((int)TP->query_level() < 28) && !(CODER))
	return 0;

    if (file_size(LOGFILE) < 0)
    {
	TM("Your log is empty.\n");
	return 1;
    }
    TP->more(LOGFILE);

    return 1;
}

