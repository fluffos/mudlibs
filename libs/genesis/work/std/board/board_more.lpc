/*
 * /std/board/board_more.c
 *
 * This object can be cloned in order to let people read something with
 * more. Note that you have to clone this file every time you want
 * someone to read something:
 *
 * #define MORE_OBJ "/std/board/board_more"
 * seteuid(getuid());
 * clone_object(MORE_OBJ)->more(args);
 *
 * You can call the function more in two ways, depending on whether
 * you want the player to read in file or in whether you want him/her to
 * read a text you have stored in a variable.
 *
 * Reading text from a file:
 *     clone_object(MORE_OBJ)->more(string filename, int start_line);
 *
 *     filename  : the filename of the file to read
 *     start_line: the first line to read in the file (starting with 1)
 *                 WARNING: If start_line == 0, then only the filename
 *                 will be printed to the player.
 *
 * Reading text from a variable:
 *     clone_object(MORE_OBJ)->move(string text);
 *
 *     text      : the text to read, separated by \n
 *                 NOTE that text is a single string with all the lines
 *                 to read concatenated, separated by \n, example:
 *                 line1\nline2\nline3
 *
 * It is possible to let this object generate a call to the object that
 * initially created us. Therefore, you have to add a THIRD argument to
 * the call to more(). If you read text from a variable, the second
 * argument must be 0. The third argument has the following format:
 *     string function_name[|argument 1[|argument 2]]
 *     clone_object(MORE_OBJ)->more(arg1, arg2, string return_function);
 *
 * WARNING: The function more() operates on this_player().
 *
 * Revision history:
 * /Mercade, May 24 1994, Complete revision of this object.
 */

#pragma strict_types
#pragma save_binary

inherit "/std/object";

#include <stdproperties.h>

#define PAGESIZE 20
#define PROMPT   ("-- More -- " + lineno +            \
		 (numlines ? ("/" + numlines) : "") + \
		 " -- (<cr> t b r <num> q x !<cmd> h ?) -- ")

private string *lines;    /* the text if it is printed from memory          */
private string  filename; /* the name of the file to print                  */
private string  funct;    /* the function to call when finished reading     */
private object  previous; /* the object to call when finished reading       */
private int     numlines; /* the number of lines in the variable lines      */
private int     first;    /* the first line to read in a file               */
private int     lineno;   /* the current line number within the text        */
private int     pagesize; /* the number of lines the player reads at a time */

/*
 * Observe that the variable lineno will contain the number to the last
 * printed line in the terminology of the player. For the player, the
 * first line will be line 1, whereas in the text from memory, the first
 * line is line 0 and in the file, the first line is line 1. Confusing
 * neh?
 */

/*
 * Function name: done
 * Description  : When the player is done reading it will destruct the
 *                more-reader and if wanted, it calls a function in the
 *                object that generated us.
 */
void
done()
{
    if (objectp(previous))
    {
	string *args = explode(funct, "|");

	call_otherv(previous, args[0], args[1..]);
    }

    remove_object();
}

/*
 * Function name: qmore
 * Description  : After the some part of the text has been printed, the
 *                next command of the player is fed into this function.
 *                It controls what the player wants to read next.
 * Arguments    : answer - the command by the player
 * Returns      : 1      - always, meaning that this function always acts.
 */
int
qmore(string answer)
{
    int i;

    answer = lower_case(answer);

    if (stringp(answer) && sscanf(answer, "%d", i) == 1)
    {
	lineno = i + pagesize - 1;
	answer = "Goto";
    }

    switch (answer)
    {
    case "":
	lineno += pagesize;
	break;

    /* Since we use the lower case of answer, this can never be triggered
     * by the command of a player, so we can use it as a flag to check on
     * numerical input.
     */
    case "Goto":
	break;

    case "q":
    case "quit":
    case "x":
    case "exit":
	done();
	return 1;

    case "?":
    case "h":
    case "help":
	write(
"\nAvailable commands:\n\n" +
"   <cr>         display next page\n" +
"   t(op)        go to top of document\n" +
"   b(ack)       go back one page\n" +
"   r(edisplay)  display the same page again\n" +
"   <number>     go to line <number>\n" +
"   h(elp) or ?  display this help message\n" +
"   !<command>   escape and execute <command>, then continue reading\n" +
"   q(uit)       quit reading document (x or exit idem)\n\n");
	write(PROMPT);
	input_to("qmore");
	return 1;

    case "t":
    case "top":
	lineno = first;
	break;

    case "r":
    case "redisplay":
	break;

    case "b":
    case "back":
    case "p":
    case "previous":
	lineno -= pagesize;
	break;

    default:
	write(PROMPT);
	input_to("qmore");
	return 1;
    }	

    if (lineno < (pagesize + first))
    {
	lineno = pagesize + first;
    }

    if (filename)
    {
	/* Cat will return the number of lines that are actually read.
	 * If you read beyond the EOF, the reading will stop. This means
	 * that if the last chunk is exactly one page, you still have to
	 * read the EOF sign.
	 */
	if (cat(filename, (lineno - pagesize + 1), pagesize) < pagesize)
	{
	    write("EOF\n");
	    done();
	    return 1;
	}
    }
    else
    {
	for (i = (lineno - pagesize); ((i < lineno) && (i < numlines)); i++)
	{
	    write(lines[i] + "\n");
	}

	if (lineno >= numlines)
	{
	    done();
	    return 1;
	}
    }

    write(PROMPT);
    input_to("qmore");
    return 1;
}

/*
 * Function name: more
 * Description  : Call this function in a clone like explained in the
 *                header of this file in order to let someone read
 *                something with more.
 * Arguments    : arg   - either the filename of the text to read or
 *                        the text to read itself, concatenated with \n
 *                start - the first line to read, if equal to 0 zero it
 *                        means that arg contains the text to print.
 *                name  - the function to call in previous_object when
 *                        the player is done reading with more.
 * Returns      : int   - 1 - always, I don't know why.
 */
varargs int
more(string arg, int start, string name)
{
    seteuid(getuid());

    pagesize = this_player()->query_prop(PLAYER_I_MORE_LEN);

    if (pagesize < 5)
    {
	pagesize = PAGESIZE;
    }

    if (start)
    {
	filename = arg;
	first    = --start;
	numlines = 0;
    }
    else
    {
	lines    = explode(arg, "\n");
	numlines = sizeof(lines);
	first    = 0;
    }

    if (strlen(name))
    {
	previous = previous_object();
	funct = name;
    }
    else
    {
	previous = 0;
    }

    lineno = first;
    qmore("");
    return 1;
}
