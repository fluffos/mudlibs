#define INFECT_DAMAGE 5+random(5)
inherit "/std/object";

int countdown;
object shifter, victim;

void setup() {
    set_name("");
    set_weight(0);
    reset_drop();
    countdown = 10+random(10);
    set_heart_beat(1);
}

void get_players(object sh, object vic) {
    shifter = sh;
    victim = vic;
}

void heart_beat() {
    if(!victim || victim->query_dead()) {
	shifter->stop_infecting();
	return;
    }
    if(environment(shifter) != environment(victim)) {
	shifter->move(environment(victim));
    }
    switch(countdown--) {
    case -1:
	tell_object(victim, "You feel the effects of the "
	  "parasite that is infecting your body.\n");
	tell_object(shifter, "You begin to spread even more throughout "
	  "your victim's body.\n");
	tell_room(environment(victim), victim->query_cap_name()+" begins "
	  "to look even more ill.\n", ({ shifter, victim }) );
	victim->adjust_hp(-(INFECT_DAMAGE));
	countdown = 10+random(10);
	break;
    }
    return;
}
