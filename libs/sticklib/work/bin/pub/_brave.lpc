#include <cmd.h>
#include <player_defs.h>

varargs nomask status
brave_cmd(string str, object me)
{
    if (!me && !(me = this_player())) return 0;
    me->set(PLR_USED_WIMPY, 0);
    me -> tell_me("Brave mode (wimpy set to 0%).");
    return 1;
}
