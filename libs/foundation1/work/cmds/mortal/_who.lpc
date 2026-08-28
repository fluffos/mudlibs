/*    /cmds/mortal/_who.c
 *    from IdeaExchange
 *    a who command
 *    created by Descartes of Borg 941001
 */

#include <std.h>

inherit DAEMON;

int cmd_who(string str) {
    object *who;
    string tmp;
    int i, screen, maxi, x;

    maxi = sizeof(who = filter_array(users(), (: environment :)));
    screen = (to_int((string)this_player()->getenv("SCREEN")) || 79);
    str=center("There are currently "+maxi+" people on "+mud_name(), screen)+"\n\n";
    for(i=0; i<maxi; i++) {
        x=strlen(tmp=(string)who[i]->query_short())-strlen(strip_colours(tmp));
        str += sprintf("%:-"+(50+x)+"s%%^RESET%%^ %s\n", tmp,
          (tmp = (string)who[i]->query_position()) == "none" ? "" : "("+tmp+")");
    }
    message("my_action", str, this_player());
    return 1;
}
