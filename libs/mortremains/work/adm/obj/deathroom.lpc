/*
** File: /adm/obj/deathroom.c
** Purpose: Where players go during the death stuff.
** Credits: 
**    12 Jun 97    Cyanide@Nightfall's Keep created the file.
*/

#include "/u/c/cyanide/debug.h"
#include <mudlib.h>
#include <config.h>
#include <uid.h>
#include <daemons.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "Death's Workroom");
    set("long", "This is where the dead face judgement.\n");
    set("light", 1);
}


// When somebody enters the room, this function determines if they
// belong in the room - and if they do, it moves the death object to
// them and starts it all off...

int receive_object (object judged) {
    object ob;

    if ((!judged->query("dying")) && (!adminp(judged)) ) {
	tell_object(judged, "Death tells you: "+
	  "I'll see you in due time...\n");
	return 0;
    }

    judged->set("hit_points", (int)judged->query("max_hp"));

    if (present("__DEATH_OB__", judged)) return 1; 

    if (userp(judged) && !adminp(judged)) {
	ob = clone_object(DEATH_OB);     //Defined in config.h
	ob->save_data();
	ob->move(judged);
	ob->begin_sequence(judged);
    }
    return 1;
}

/* EOF */
