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
        write("this_player() returns: "+sprintf("%O",this_player())+"\n"
           "this_player(1) returns: "+sprintf("%O",this_player(1))+"\n");
        return 1;
}
