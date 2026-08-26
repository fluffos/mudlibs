// Cy did this real fast

#include <m_spells.h>

int cmd_mhelp(string str) {
    string tmp, *lines;
    int n;

    if (!str) str = "index";

    tmp = read_file(MAGES+"help/"+str,0,100);

    if(!stringp(tmp) || tmp == "") 
	write("The is not an available help option.\n"+
	  "Type 'mhelp index' for a complete list of help files.\n");
    else {
	lines = explode(tmp,"\n");
	for (n=0;n<sizeof(lines);n++)
	    write(lines[n]+"\n");
    }

    return 1;

}

void create() { seteuid(getuid()); }
