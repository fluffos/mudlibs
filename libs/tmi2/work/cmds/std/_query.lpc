// _query.c
// Originally by Sulam@TMI, though the concept is older than that.
// Pallando hacked it to tiny pieces on 2-11-93.
// Mobydick added ::create(); and comments on 93-03-22, then spaced out the
// code so his comments wern't longer than the program. 8-)

#include <commands.h>

inherit CMD_PRAISE;

int cmd_query (string a) {
	return cmd_report(a) ;
}

void create() {
	::create() ;
	report_type = "query";
	report_file = "QUERIES";
}
