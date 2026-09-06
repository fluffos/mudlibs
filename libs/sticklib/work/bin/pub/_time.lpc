#include <cmd.h>

nomask int
time_cmd(string str, object me)
{
    if (!me && !(me = this_player())) return 0;

    me->tell_me((string)nature()->query_date_b());
    if (me -> query_coder_level())
	me -> tell_me(
	  "Real System Time: " + time() + ".");
    return 1;
}
