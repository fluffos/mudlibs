/* Bat Guano - an important spell component... */

#include <treasure.h>

void
create_treasure()
{
    set_id("bat guano");
    set_id("guano");
    set_weight(1);
    set_short("small lump of bat guano");
    set_value(0);
}

void
init_treasure()
{
    add_action("throw","throw");
}

status
throw(string str)
{
    string what,who;
    object target;

    if(sscanf(str,"%s%tat%t%s",what,who)!=2 && sscanf(str,"%s %s",what,who)!=2) {
	notify_fail("Throw what at whom?\n");
	return 0;
    }

    if(!id(what)) return 0;

    if (!this_player()->query_can_move()) {
	notify_fail("You cannot even move, much less throw anything.\n");
	return 0;
    }

    target = present(who,environment(this_player()));
    if(!target) {
	notify_fail("Throw it at whom???\n");
	return 0;
    }
    write("Ok. You throw " + target->short() + " with bat guano.\n");
    tell_object(target,this_player()->query_name() +
      " throws bat guano on your face! Yuk!\n");
    destruct(this_object());
    return 1;
}
