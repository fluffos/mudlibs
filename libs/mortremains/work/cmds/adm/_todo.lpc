// _bug.c
// Originally by Sulam@TMI, though the concept is older than that.
// Pallando hacked it to tiny pieces on 2-11-93.
// Mobydick went into damage repair mode on 3-22-93, although he's still
// not sure why it broke. It needs to have comments added anyway.
// Leto turned it into a todo command ;)

#include <commands.h>

inherit CMD_PRAISE;
int cmd_todo (string a) {
	return cmd_report(a) ;
}

void create() {
	::create() ;
	report_type = "todo";
	report_file = "TODO";
}
