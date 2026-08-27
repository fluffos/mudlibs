//#pragma save_binary

// _faq.c
// Print the MUD's FAQ list.
// Rather old. Probably originally authored in late 1991, and probably by
// Sulam. No header was written at that time.
// Mobydick added this header and the help on 11-14-92.

#include <mudlib.h>

inherit DAEMON ;

#define TMI_FAQ_FILE "/adm/news/faq"

int cmd_faq(string unused) {
	string p;

	previous_object()->more(TMI_FAQ_FILE);
	return 1;
}

int help() {
	write ("Usage: faq\n\n"+
"This command will show you the FAQ file. FAQ stands for frequently\n"+
"asked questions, and the file contains the answers. It is good to read\n"+
"this before bothering a wizard or admin with questions.\n") ;
	return 1 ;
}
