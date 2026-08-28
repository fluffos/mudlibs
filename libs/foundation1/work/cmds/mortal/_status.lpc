//      _status.c
//     created by Descartes for the Nightmare mudlib 141192
 
#include <std.h>
 
inherit DAEMON;
 
int cmd_status() {
  write("hp: "+this_player()->query_hp()+"/"+this_player()->query_max_hp()+"  "
        "sp: "+this_player()->query_sp()+"/"+this_player()->query_max_sp()+"  "
        "mp: "+this_player()->query_mp()+"/"+this_player()->query_max_mp()+"  "
        "experience: "+this_player()->query_exp());
  return 1;
}
 
void help() {
    write("Syntax: <status>\n\n"+
        "Gives you your current physical status.\n"
        "See also: score\n"
    );
}
