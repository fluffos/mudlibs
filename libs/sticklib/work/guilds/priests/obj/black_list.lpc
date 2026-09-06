#include "../priest.h"
#include <bboard_defs.h>

inherit BBOARD_FILE;

void long(string str, object plr)
{
    object me;

    me = this_player();
    if(IS_PRIEST(me) || me->query_coder_level())
	::long(str, plr);
    return;

    me->tell_me("The board's notes are in an ancient script which you \
cannot understand.");
}

int board_cmd(string str, object plr)
{
    object me;

    me = this_player();
    if(IS_PRIEST(me) || me->query_coder_level())
	return ::board_cmd(str, plr);

    me->tell_me("The board's notes are in an ancient script which you \
cannot understand.");
    return 1;
}

varargs string 
query_short(int mode, object who) 
{ 
    if (_message) { 
	return sprintf("Black list with %d notes", sizeof(_message[1]));
    } 
    return "Black list";
}
