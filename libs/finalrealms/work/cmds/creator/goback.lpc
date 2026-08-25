/* 
 * Externalize by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

position = 1;
}

/* added by Dank Mar 3 '93.  also added query_prev() to move.c */
protected int cmd(string foo, object me) {
    object ob;
    if (!(ob = me->query_prev()))
	write("Previous location is not valid.\n");
    else
	me->move_player("X",ob);
    me->set_trivial_action();
    return 1;
}

