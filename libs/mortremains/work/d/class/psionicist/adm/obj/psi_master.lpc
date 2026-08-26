/*
** FILE:    psi_master.c
** PURPOSE: Controls all psionic powers on the mud.
**     Since it keeps track of timing and PSP usage, the MUD
**     uses FAR fewer call_outs.
** CREDITS:
**   22 Oct 98   Cyanide created this object.
**               Cyanide says, "Heh. This'll be cool."
**
** *IMPORTANT*: DO NOT UPDATE THIS OBJECT DURING GAME PLAY. THE
**      RESULT WOULD BE THAT ALL PSIONICS WOULD BECOME EFFECTIVELY
**      PERMANANT.
*/

#include <psionics.h>
#include "/u/c/cyanide/debug.h"

object *seconds, *minutes;
int count, num, i, flag, any_object = 0;

inherit DAEMON;

void create() { 
    seteuid(getuid());
    minutes = ({});
    seconds = ({});
    DEBUG("CREATE\n");
    call_out("heart_beat", 1);
}

int clean_up() { return 1; }

void heart_beat() {
    flag = 0;
    if (!any_object) return ;
    DEBUG("Psimaster HB.\n");
    num = sizeof(seconds);

    if (num) {
	DEBUG("PM: seconds\n");
	flag = 1;
	for (i=0; i<num; i++) {
	    if (!seconds[i]) continue;
	    seconds[i]->upkeep();
	}
	seconds = filter_array("filter_obs", seconds, TO);
    }

    num = sizeof(minutes);
    if (num) flag = 1;
    if (count >= 60 && num) {
	DEBUG("PM: minute\n");
	flag = 1;
	for (i=0; i<num; i++) {
	    if (!minutes[i]) continue;
	    minutes[i]->upkeep();
	}
	minutes = filter_array("filter_obs", minutes, TO);
    }

    any_object = flag;
    call_out("heart_beat", 1);
}

int add_object(object ob, string time) {
    int flag = 1;

    if (!ob->query_psionic()) return 0;

    switch((lower_case(time))[0..0]) {
    case "m" : minutes += ({ ob }); break;
    case "s" : seconds += ({ ob }); break;
    default: flag = 0; break;
    }

    return flag;
}

int filter_obs(object ob) {
    if (ob) return 0;
    return 1;
}

/* EOF */
