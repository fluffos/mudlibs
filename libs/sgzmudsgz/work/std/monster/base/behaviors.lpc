// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <combat.h>
void dispatch_opponent();
varargs void stop_fight(object who);
object query_target();
/* Override flee() and surrender() to define or modify the behaviour
 * of your monster.  Return 1 of the monster shouldn't take a swing.
 * Return 2 if the monster should stop attacking. (useful for
 * surrender() */
//:FUNCTION flee
//Try to run away.
void flee() {
}

//:FUNCTION flee
//Try to run surrender
void surrender() {
	object t;
	t=query_target();
	if(!objectp(t)) // strange
		return;
	this_object()->targetted_action(
		"$N脸色一变，跳出战圈，对$T道：$R武艺高强，$s不是对手，佩服，佩服。\n",t);
	stop_fight(0);
}

//:FUNCTION panic
//Do something intelligent when we are about to die
/* Override this function to have your monster do something else when it's
 * hp's get low. */
void panic() {
	string id;
	int type;
	id=this_object()->query_id()[0];
	type=FIGHT_D->get_fight_type(id);
	switch(type) {
	case  COMBAT_FIGHT:
		surrender();
		break;
	default: 
		if(this_object()->query_cur_hp()<0)
			this_object()->die();
	}

}

//:FUNCTION target_is_asleep
//Called with the person we are attacking is asleep or unconscious.  Default
//behavior is to finish them off.

/* Override this function if you want your monster to do something other
 * than killing unconscious victims.  Rob them, etc ...
 */
void target_is_asleep()
{
    dispatch_opponent();
}
