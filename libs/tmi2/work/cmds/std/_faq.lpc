// _faq.c
// Print the MUD's FAQ list.
// Rather old. Probably originally authored in late 1991, and probably by
// Sulam. No header was written at that time.
// Mobydick added this header and the help on 11-14-92.
// Lucas@Avatar added the 1 flag to remove the more header
// 	5May96

#include <mudlib.h>

inherit DAEMON ;

#define TMI_FAQ_FILE "/adm/news/faq"

int cmd_faq(string unused) {
	string p;

	previous_object()->more(TMI_FAQ_FILE, 1);
	return 1;
}

string help() {
	return ("Syntax: faq\n\n"+
"This command will show you the FAQ file. FAQ stands for frequently\n"+
"asked questions, and the file contains the answers. It is good to read\n"+
"this before bothering a wizard or admin with questions.\n"+
"\nSee also: help, lpfaq\n");
}
