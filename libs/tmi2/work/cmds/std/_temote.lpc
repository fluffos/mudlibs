// file:   temote.c
// mudlib: Basis
// date:   1992/09/06

#include <config.h>
#include <daemons.h>

int
cmd_temote(string str)
{
        string verb, rest;

        if (!str) {
                notify_fail("usage: temote emotion [target] arguments.\n");
                return 0;
        }
        if (sscanf(str, "%s %s", verb, rest) != 2) {
                verb = str;
                rest = 0;
        }
        if ((int)EMOTE_D->parse(verb, rest, 1) == 0) {
                notify_fail("temote: couldn't find " + verb + "\n");
                return 0;
        }
        return 1;
}

int help() {
	write ("Usage: temote <argument>\n"+
"The temote command will show you what you will see, what others will see,\n"+
"and, if relevant, what the target will see if you give the soul command\n"+
"<argument>.\n"+
"\nSee also: semote, edemote.\n") ;
	return 1 ;
}
// EOF
