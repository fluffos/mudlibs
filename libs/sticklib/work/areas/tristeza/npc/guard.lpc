/* Official City Guard */

/* TODO: Attempt to arrest, capture, punish or slay criminals?
   Making a full alarm: all the guards in city rush to help?
 */

#include <criminal.h>
#include <servers.h>

#include "../DEFS.h"

#include "citymonster.h"

void yell_help();
void check_fight();
object check_rules(object a, object b);

int yelled;

void
create_guard()
{
    object ob;
    string n;

    n = (string) NAMEGEN_C -> random_name();
    set_name("guard"); /* So that the exits etc will recognize us */
    set_race("human");
    set_id (({ n, "city_guard" }));
    n = capitalize(n);
    set_short(n + " the guard");
    set_group("cityguard");
    /* Dumb idea proposed by someone to make the lives of thieves a little
      more annoying.
	    Starks- 01/25/99
      set(NPC_SET_PK_FLAG, 1);
    */
    gender = 1 + random(2);
    set_long(
      "A tough-looking fighter as all of them, " + n + " is a member of the\
 famous City Guards, the bane of all criminals. "+
      capitalize(Pronoun())+" is here to protect the innocent.");

    set_level(6 + random(4));
    set_wander(7);
    set_keep_hb(-300);
    set_hp(400 + query_level() * 20);
    set_money(random(150));

    /* Guards are Good now - because killing them must be Evil. //Graah */
    set_alignment(20 + random(200));

    if (random(100) < 15)
    {
	ob = (object) WEAPON_SERVER->make_weapon("long sword");
	ob->set_long(
	  "A regular long sword of the type used by the City Guards.");
	move_object(ob, this_object());
	wield(ob);
    }

    if (random(100) < 15)
    {
	ob = (object) ARMOUR_SERVER->make_armour("chain mail jerkin");
	ob->set_long(
	  "A regular chain mail of the type used by the City Guards.");
	move_object(ob, this_object());
	wear(ob);
    }

    set_wc(40, 1);
    set_ac(40, 1);

    yelled = 0;
}

void create_monster() { create_guard(); }

/* Let's check if there is a fight here 6.8.1992 //Frobozz */
void
heart_beat()
{
    if (!is_fighting()) {
	check_fight();
	yelled = 0;
    }
    else if (yelled < 3 && !random(10)) { yell_help(); yelled++; }

    ::heart_beat();
}

/* Let's decide who we attack or make flee */
void
join_fight(object f1,object f2)
{
    object target;

    target = check_rules(f1,f2);

    if (!target)
	target = check_rules(f2,f1);

    if (target) {
	environment() -> tell_here("Guard shouts: "+
	  ({"Protect the innocent",
	    "CHARGE",
	    "Right" })[random(3)]+"!", this_object());
	if ((int) target->query_level()>10) attack_object(target);
	else {
	    target -> tell_me(
	      "Guard looks at you in such a way that it makes your legs run.");
	    environment() -> tell_here("Guard makes " + (string) target->query_name() +
	      " run away.", ({target,this_object()}));
	    target->run_away();
	}
    }
}

/* Let's pick the first fighter with opponent in the room for closer look */
void
check_fight()
{
    object fighter1,fighter2,check;
    object x;

    if (!environment()) return;

    check = first_inventory(environment());
    while(check) {
	if (x = (object) check->query_attack()) {
	    if (!fighter1) {
		fighter1 = check;
		fighter2 = x;
		if (!fighter2 || fighter2==this_object() ||
		  /* If the opponent is not here, we don't want to interfere */
		  !present(fighter2,environment()) ||
		  /* We don't have to deal with protecting other guards here */
		  fighter1->id("city_guard") || fighter2->id("city_guard"))
		    fighter1 = fighter2 = 0;
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
object
check_rules(object f1, object f2)
{
    if (!interactive(f1) && interactive(f2)) {
	if (f1 -> query(NPC_AGGRESSIVE))
	    return f1; /* Attack f1 */
	return f2;   /* Attack f2 */
    }

    if (interactive(f1) && !interactive(f2))
	return 0; /* No attack */

    return random(2) ? f1 : f2;
    /* Attack either one randomly. Stupid, eh??? */
}

/* What? Someone is fighting us? Yell help! */
void
yell_help()
{
    string *dd, tmp;
    object *exs, ob;
    object att2;
    int i, j;

    if (!environment() || dead) return;

    dd = (string*) environment()->query_dest_dir();
    if (!dd || sizeof(dd) < 1) return;

    exs = ({});

    for (i = j = 0; i < sizeof(dd); i += 2)
	if (dd[i] && (ob = find_object(dd[i]))) {
	    exs += ({ ob });
	    j++;
	}

    if (j < 1) return;

    tmp = ({ "Help! Alarm! There's a fight going on in here!",
      "Alarm! Reinforcements needed here!",
      "Hey fellows! Come to help me with this criminal!",
      "Guards! An assault going on in here!" })[random(4)];

    environment() -> tell_here("Guard yells: " + tmp, this_object());

    if (!(att2 = query_attack())) return;
    for (i = 0; i < j; i++) {
	if (exs[i]) exs[i]->tell_here("You hear a shout: " + tmp + "\n");
	if ((ob = present("city_guard", exs[i])) &&
	  !ob->is_fighting()) {
	    environment() -> tell_here("You hear a shout: Coming!");
	    exs[i] -> tell_here((string)ob->short() + " shouts: Coming!");
	    ob->move_player("running towards the battle", environment());
	    ob->attack_object(att2);
	}
    }
}
