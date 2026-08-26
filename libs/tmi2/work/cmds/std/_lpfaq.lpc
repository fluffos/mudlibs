// Rust modified the faq command for this, Jul 25, 1994

#include <mudlib.h>

inherit DAEMON ;

#define TMI_FAQ_FILE "/adm/news/lpfaq"

int cmd_lpfaq(string unused) {
	string p;

	previous_object()->more(TMI_FAQ_FILE, 1);
	return 1;
}

string help() {
	return ("Syntax: lpfaq\n\n"+
  "This command will show you the FAQ for the rec.games.mud.lp newsgroup.\n"
"It contains the answers to a lot of frequently asked questions about LP\n"
"muds in general.  It should be consulted before bothering a wizard\n"
"or admin with questions.\n"+
"\nSee also: faq\n");
}
