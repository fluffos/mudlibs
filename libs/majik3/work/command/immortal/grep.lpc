
/* -------------------------------------------------------------------------
 * G-LIB v0.0-alpha0                        GENERIC OBJECT LIBRARY FOR LPMUD
 * (see /doc/license before altering the code)
 * -------------------------------------------------------------------------
 * file name   : grep.c
 * description : New grep command.  Now accepts wildcards (i.e. "*")
 * coder(s)    : Mordoc
 * -------------------------------------------------------------------------
 */


grep_dir (string, string);
grep_file (string, string);

int main (string args) {
    string *Args;
    string path, pattern;

    if (!args || args == "") {
	write("Syntax:   grep <pattern> <file(s)>\n");
	return 1;
    }
    Args = explode (args, " ");
    if (sizeof(Args) != 2) {
	write("Syntax:   grep <pattern> <file(s)>\n");
	return 1;
    }

    path = Args[1];
    pattern = Args[0];
    if (path == "*") {
	grep_dir (".", pattern);
    }
    else if (sscanf(path, "%s*", path) == 1) {
	grep_dir(path, pattern);
    }
    else {
	if (!absolute_path(path))
	    path = this_player()->query_cwd()+path;
	path = resolve_path(path);
	grep_file(path, pattern);
    }
    return 1;
}

grep_dir (string path, string pattern) {
    int i;
    mixed *junk;

    if (!absolute_path(path))
	path = this_player()->query_cwd()+path+"/";
    path = resolve_path(path);
    path += "/";

    if (junk = get_dir(path, -1)) {
	for (i=0; i<sizeof(junk); i++) {
	    if (junk[i][1] != -2) {
		grep_file (path+junk[i][0], pattern);
	    }
	}
    }
    else {
	write("No such directory, '"+path+"'\n");
	return 1;
    }

    return 1;
}

grep_file (string path, string pattern) {
    string line;
    int i = 0;
    int flag = 0;

    while (line = read_file(path, i, 1)) {
	i++;
	if (strsrch(line, pattern) != -1) {
	    if (flag == 0) {
		write(path+":\n");
		flag = 1;
	    }
	    write("\t"+line+"\n");
	}
    }
    flag = 0;
    return 1;
}
