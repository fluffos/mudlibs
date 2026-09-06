#include "../priest.h"

#define SHOWLINES 20
#define MAX_SIZE 40000 // dunno what the max size is, that can be read at a
// time using read_file, but this should be enough

status
joinlog_cmd(object who, object sym, string s) {
    string *tmp;
    int lines, currentline;

    if(sym->query_rank()<2) {
	who->tell_me("You have no access to that.");
	return 1;
    }
    if(!s) {
	if(file_size(JOINLOG) <= 0)
	    return notify_fail("The join log is empty.\n"),0;
	lines = file_lines(JOINLOG);
	if(lines > SHOWLINES)
	    tmp = explode(read_file(JOINLOG,lines-SHOWLINES+1,SHOWLINES),"\n");
	else
	    tmp = explode(read_file(JOINLOG),"\n");
	lines = sizeof(tmp);
	who->tell_me(sprintf("The last %d events in join log:",lines));
	while(currentline < lines)
	    who->tell_me(tmp[currentline++]);
	return 1;
    }

    if(sscanf(s, "-%s", s) !=1)
	return notify_fail("Usage: joinlog [-full]\n"),0;

    switch(s) {
    case "full":
	if(file_size(JOINLOG) > MAX_SIZE)
	    return notify_fail("The log is too big.\n"),0;
	who->more(explode(read_file(JOINLOG),"\n"));
	break;
    default:
	return notify_fail("No such switch.\n"),0;
    }
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
