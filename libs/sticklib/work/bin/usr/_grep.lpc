#include <cmd.h>

private void grep_one_file(string file, string to_find, object me);

int
grep_cmd(string str, object me)
{
    string to_find, *files;
    int i;
    if (!me && !(me = this_player())) return 0;
    if (!CHECK) return 0;
    if (!str ||
      (sscanf(str, "'%s' %s", to_find, str) != 2
	&& sscanf(str,"%s %s", to_find, str) != 2))
	return notify_fail("Usage: grep '<match>' <file1> [<file2> <file3> ..]\n"), 0;

    if (sizeof(to_find) < 2) {
	me->tell_me("The string to be searched for has to be at least\
 2 characters long.");
	return 1;
    }

    files = explode(str, " ");

    for (i = 0; i < sizeof(files); i++) {
	string *dir_list, path;
	int    j;

	path = (string) me->absolute_path(files[i], 0);

	dir_list = get_dir(path);
	if (!dir_list || !sizeof(dir_list)) {
	    me->tell_me("File(s) '"+path+"' not found.");
	    continue;
	}

	j = sizeof(path) - 1;
	while (path[j] != '/') j--;
	path = path[0..j];

	for(j = 0; j < sizeof(dir_list); j++)
	{
	    if (dir_list[j] == "." || dir_list[j] == "..")
		continue;
	    str = path + dir_list[j];

	    /* Skip directories and empty files silently */
	    if (file_size(str) <= 0)
		continue;
	    grep_one_file(str, to_find, me);
	}

    } /* for */
    me->tell_me("Done.");
    return 1;
}

/*
 * The max size of an array is 1000.
 * Explodes needs three additional idexes. -> 997
 */
#define GREP_BLOCK 997

/*
 * Maxinum number of occurrances of the searched string in one block.
 * Can't be greater then 999 for same reasons as GREP_BLOCK.
 */
#define MAXOCCUR 200
private void
grep_one_file(string file, string to_find, object me)
{
    int     i;
    int     rline,
    last_match, /* The latest line that had a match */
    count;      /* The number of last (possible) line in memory */
    string  *exp_buffer, buffer;
    string txt;

    count = 1;
    last_match = 0;

    while (buffer = read_file(file, count, GREP_BLOCK))
    {
	rline = count - 1;
	count += GREP_BLOCK;

	if (catch(exp_buffer = explode("\t\n" + buffer + "\n\t", to_find))
	  || sizeof(exp_buffer) > MAXOCCUR)
	{
	    me->tell_me(txt + "\nToo many occurences. Terminating search in '"
	      + file + "'.");
	    return;
	}

	buffer = 0; /* just freeing some memory */

	for (i = 0; i < sizeof(exp_buffer) - 1; ++i)
	{
	    rline += sizeof(explode("\t\n" + exp_buffer[i] + "\n\t", "\n")) - 3;
	    if (rline != last_match) {
		if (!last_match)
		    txt = "File '"+file+":\n";
		txt += rline+": "+read_file(file, rline, 1);
		last_match = rline;
	    }
	}
    }
    if (txt) me->tell_me(txt);
}

