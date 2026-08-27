// prints query_verb()

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

string query_usage() { return "verb"; }
string query_short_help() { return "Prints the typed verb."; }

#ifdef CMD_AURORA
int cmd(string str)
#else
int cmd(string str, object thisob)
#endif
{
        write("Verb: "+query_verb()+"\n");
        return 1;
}
