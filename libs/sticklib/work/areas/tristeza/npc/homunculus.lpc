#include <conditions.h>

#include <npc.h>

void
create_monster()
{

    set_level(3);
    set_wc(10);
    set_ac(10);
    set_name("homunculus");
    set_id("homu");
    set_short("Homunculus");
    set_long(
      "A homunculus appears as a man-like figure, about 18'' tall. It has a\n"+
      "greenish, reptilian skin, leathery wings, and a batlike mouth. Its\n"+
      "teeth are dripping with a nasty-looking, sickly gray venom.\n");
    set_race("construct");
    set(NPC_AGGRESSIVE);
    set_wander(11);
    set_money(1 + random(10));
}

/* Redefined attack() for possible sleep spell */
attack() {
    int att;

    att = ::attack();

    if(att && !random(20) && attacker_ob &&
      !attacker_ob->query_condition(C_UNCONSCIOUS)) {
	attacker_ob -> tell_me("Suddenly you feel very drowsy!");
	attacker_ob->set_condition(C_UNCONSCIOUS,2 + random(4));
    }

    return att;
}

/* Redefine random_move(): don't wander out of own level */
random_move()
{
    command(({"north","south","east","west",
	"northwest","southwest","northeast","southwest"})[random(8)]);
}
