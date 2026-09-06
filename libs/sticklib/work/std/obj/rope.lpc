#include <daemons.h>
#include <living_defs.h>
#include <treasure.h>

string tied_to;
object tied_to_ob;

void create_treasure()
{
    set_name("rope");
    set_id( ({ "rope" }) );
    set_short("a rope");
    set_long("You see nothing special about the rope.");
    set_weight(1);
    set_value(100);
}

string query_short() {
    if (tied_to) return ::query_short()+" tied to " + tied_to;
    return ::query_short();
}

void init() {
    add_action("tie_cmd",   "tie");
    add_action("untie_cmd", "untie");
}

status get() {
    if (!tied_to) return 1;
    this_player()->tell_me("But the rope is tied to " + tied_to + ".");
    return 0;
}

status tie_cmd(string str)
{
    object env, me;
    if ( !str || !(me=this_player()) || !(env=environment(me))) return 0;
    if (tied_to) {
	return notify_fail("It is already tied to " + tied_to + ".\n" );
    }
    string t1, t2;
    if (sscanf(str, "%s to %s", t1, t2) != 2) return 0;
    if (!id(t1)) return 0;
    if (t2 == "me") {
	return notify_fail( "Why would you do that?\n" );
    }
    object ob = present(t2, me);
    if (!ob) ob = present(t2, env);
    if (!ob && env->id(t2)) ob = env;
    if (!ob) {
	return notify_fail( "Tie rope to where?\n" );
    }
    if (!ob->tie(t2)) {
	return notify_fail("You can't tie the rope to " + t2 + ".\n");
    }
    // Is he carrying the rope?
    if (environment() == me) {
	move_object(this_object(), env);

	if (me->query(LIV_IS_PLAYER) && me->query_env("gmcp")) {
	    TELOPT_D->send_char_items_remove(me, "inv", this_object());
	}

	me->add_weight(-query_weight());
    }
    tied_to = t2;
    tied_to_ob = ob;
    me->tell_me("Ok.");
    env->tell_here((string)me->query_name()+" ties rope to " + t2 + ".", me);
    return 1;
}

status untie_cmd(string str)
{
    object me;
    if (!str || !id(str) || !(me=this_player())) return 0;
    if (!tied_to || !tied_to_ob) {
	me->tell_me("It is not tied to anything.");
	return 1;
    }
    if (!tied_to_ob->untie()) {
	me->tell_me("You fail.");
	return 1;
    }
    me->tell_me("Ok.");
    environment(me)->tell_here((string)me->query_name()
      +" unties the rope.",me);
    tied_to = 0;
    tied_to_ob = 0;
    return 1;
}

