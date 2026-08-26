// _bug.c
// Originally by Sulam@TMI, though the concept is older than that.
// Pallando hacked it to tiny pieces on 2-11-93.
// Mobydick went into damage repair mode on 3-22-93, although he's still
// not sure why it broke. It needs to have comments added anyway.

#include <commands.h>

inherit CMD_PRAISE;
int cmd_bug (string a) {
	return cmd_report(a) ;
}

void create() {
	::create() ;
	report_type = "bug";
	report_file = "BUGS";
}

string help()
	{
	return(@HELP
Syntax: bug

This command allows you to file a bug report to the admins of the
MUD. The bug should include the error you may receive, and a general
description of where you are in the MUD. The bug will be fixed as
soon as possible.

See also: typo, praise, idea, query
HELP
  );
	}
