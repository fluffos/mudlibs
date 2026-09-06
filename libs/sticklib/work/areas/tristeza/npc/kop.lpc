/* Keystone kops */

/* TODO: Attempt to arrest, capture, punish or slay criminals?
   Making a full alarm: all the guards in city rush to help?
 */

#include <criminal.h>
#include <npc_defs.h>

#include "citymonster.h"

int yelled;

void
create_monster()
{
    string tmp1,tmp2;
    object ob;

    set_name("keystone kop");
    set_race("human");
    set_id(({ "guard", "city_guard", "kop", "keystone" }));

    set_short("Keystone Kop");
    set_gender(G_MALE);
    set_long(
      "Every Keystone Kop is equipped with a rubber stick, a whistle and \
 lots of cream pies. They are black and white (no colors), and their \
 actions cause strange sound effects. A piano tune plays constantly \
 when there is a Kop around.");

    set_level(6 + random(4));
    set_wander(30);
    set_keep_hb(-300);
    set_hp(50);
    set_money(random(10));
    set_alignment(AL_QUITE_NICE);

    yelled = 0;
}

/* We want other guards in the room to join in the fight if one is attacked 
   6.8.1992 //Frobozz */
int
attacked_by(object orig, int to_top, int flags)
{
    object *inv;
    int i, s;
    int ret;
    if (!(ret = ::attacked_by(orig, to_top, flags)) || to_top < 0)
	return ret;
    extra_attacked_by(orig); /* Assault? */

    inv = all_inventory(environment());
    s = sizeof(inv);

    for(i = 0; i < s; i++) {
	if (inv[i] != this_object() && living(inv[i]) &&
	  inv[i]->id("city_guard")) {
	    inv[i]->attack_object(orig);
	}
    }
    return ret;
}

/* Let's check if there is a fight here 6.8.1992 //Frobozz */
heart_beat() {
    if (!is_fighting()) {
	check_fight();
	yelled = 0;
    }
    else if (yelled < 3 && !random(10)) { yell_help(); yelled++; }

    ::heart_beat();
}

/* Let's pick the first fighter with opponent in the room for closer look */
check_fight() {
    object fighter1,fighter2,check;

    if (!environment()) return;

    check = first_inventory(environment());
    while(check) {
	if (check->query_attack()) {
	    if (!fighter1) {
		fighter1 = check;
		fighter2 = fighter1->query_attack();
		if (!fighter2)
		    fighter2 = fighter1->query_alt_attack();
		if (!fighter2 || fighter2==this_object() ||
		  /* If the opponent is not here, we don't want to interfere */
		  !present(fighter2,environment()) ||
		  /* We don't have to deal with protecting other guards here */
		  fighter1->id("city_guard") || fighter2->id("city_guard")) {
		    fighter1 = 0;
		    fighter2 = 0;
		}
	    }
	}

	if (fighter1 && fighter2) {
	    join_fight(fighter1,fighter2);
	    return;
	}
	check = next_inventory(check);
    }
}

/* Rules to join fight
   1. Protect monsters, if they are not aggressive
   2. Protect players from aggressive monsters
   3. Protect a random monster in monster-monster fight
*/
check_rules(f1,f2) {
    if (!interactive(f1) && interactive(f2)) {
	if (f1 -> query(NPC_AGGRESSIVE))
	    return f1; /* Attack f1 */
	return f2;   /* Attack f2 */
    }

    if (interactive(f1) && !interactive(f2))
	return 0; /* No attack */

    return ({ f1,f2 })[random(2)]; /* Attack randomly f1 or f2 */
}

/* Let's decide who we attack or make flee */
join_fight(f1,f2) {
    object target;

    target = check_rules(f1,f2);

    if (!target)
	target = check_rules(f2,f1);

    if (target) {
	tell_room(environment(), "Kop blows into his whistle!\n");

	if (target->query_level()>10)
	    attack_object(target);
	else {
	    tell_object(target,
	      "Kop looks at you in such a way that it makes your legs run.\n");
	    tell_room(environment(), "Kop makes " + target->query_name() +
	      " run away.\n",({target}));
	    target->run_away();
	}
    }
}

/* What? Someone is fighting us? Yell help! */
yell_help() {
    string *dd, tmp;
    object *exs, ob;
    int i, j;
    object att2;

    if (!environment() || dead) return;

    dd = environment()->query_dest_dir();
    if (!dd || sizeof(dd) < 1) return;

    exs = ({});

    for (i = j = 0; i < sizeof(dd); i += 2)
	if (dd[i] && (ob = find_object(dd[i]))) {
	    exs += ({ ob });
	    j++;
	}

    if (j < 1) return;

    environment()->tell_here(
      "Kop waves his rubber stick and blows into his whistle!", this_object());

    att2 = query_attack();
    if (!att2) return;
    for (i = 0; i < j; i++) {
	tell_room(exs[i], "You hear a loud whistle from nearby!\n");
	if ((ob = present("city_guard", exs[i])) &&
	  !ob->is_fighting()) {
	    tell_room(environment(),"You hear a shout: Coming!\n");
	    tell_room(exs[i], ob->short() + " shouts: Coming!\n");
	    ob->move_player("running towards the battle", environment());
	    ob->attack_object(att2);
	}
    }
}
