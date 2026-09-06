#include <object.h>

/**
 * This object represents a successfully charged warcry action.
 */

int strength;	// how powerful is this effect?
int hb;			// number the heartbeats
int combat;		// flag to switch on once they enter combat
object *victims;// who all have we discharged on?

string query_name() {
	return "warcry_ob";
}

object id(string str) {
	if( str == query_name() ) return this_object();
	else return 0;
}

void do_setup(object who, int check) {
	move(who);
	strength = check;
	hb = combat = 0;
	victims = ({});
	set_heart_beat(1);
}

/**
 * Called when the warcry effect fades - either from having been discharged too
 * many times, or simply by existing for too long.
 */
void do_end() {
	if( environment() ) {
		if( combat )
			msg_object(environment(), "~CACTThe moment lost, the effects of your warcry fade.~CDEF");
		else
			msg_object(environment(), "~CACTYour adrenaline slows down as the initial effects of your warcry fade.~CDEF");
	}
	destruct(this_object());
}

void heart_beat() {
	hb++;
	if( hb > strength / 10 )
		do_end();
	else {
		object player = environment();
		if( !player || !player->query_is_living() )
			do_end();
		else {
			if( combat ) {
				object victim;
				// wimpy rolls don't have any in-combat effects once they've started
				if( strength < 40 )
					return;
				// find victims
				foreach( victim : player->query_targets() ) {
					int resist;
					if( member(victims, victim) != -1 )
						continue;
					// practice
					// only one prac per use, but it gets exponential with additional enemies
					player->practice_skill_conditional("combat.tactics", 30, sizeof(victims));
					// discharge against new victim
					victims += ({ victim });
					set_actor(player);
					set_target(victim);
					if( victim->skill_check("combat.intuition", strength) ) {
						set_listener(victim);
						msg_object(victim, "~CACT~Targ resist the effects of ~npos warcry.~CDEF");
						set_listener(player);
						msg_object(player, "~CACT~Targ ~vertresist ~poss warcry.~CDEF");
						continue;
					} else {
						// slow
						object slow_ob = clone_object("/battle/slow_object");
						slow_ob->set_speed( max(strength, 100) );
						slow_ob->set_strength( strength * 10 );
						slow_ob->set_victim( victim );
						// stun
						if( strength > 80 )
							victim->add_held( strength / 8 );
					}
				}
			} else if( player->query_in_combat() ) {
				combat = 1;
				set_actor(player);
				player->msg_local("~CACT~Name ~verbsurge with energy as ~pron ~verbenter battle!~CDEF");
				// any successful warcry results in readiness charge
				player->add_readiness( min(100, strength * 5) );
				player->practice_skill_conditional("combat.tactics", 20, 1);
				// invigorate
				if( strength >= 20 ) {
					object invig_ob = clone_object("/magic/obj/invigorate_object");
					invig_ob->set_speed( strength / 20 );
					invig_ob->set_duration( strength / 5 );
					invig_ob->set_victim( player );
				}
				// haste
				if( strength >= 60 ) {
					object haste_ob = clone_object("/magic/obj/haste_object");
					haste_ob->set_speed( strength / 5 );
					haste_ob->set_duration( strength / 10 );
					haste_ob->set_victim( player );
				}
			}
		}
	}
}

/**
 * Fade warcry if they go LD
 */
void on_suspend() {
	do_end();
}

/**
 * Dest warcry if moved to a stupid location.
 */
void on_move() {
	if (!environment() || !environment()->query_is_living())
		do_end();
}
