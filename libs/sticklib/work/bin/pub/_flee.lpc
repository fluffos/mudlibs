/* RUN AWAY!!! */

#include <cmd.h>

int
flee_cmd(string arg, object me)
{

    if (!me && !(me = this_player())) return 0;

    if (!me -> query_can_move()) return 0;

    /* TODO: More msgs... */
    me -> tell_me("PANIC!!!");
    me -> run_away();
    return 1;
}
