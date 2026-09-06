#include <npc.h>

void
create_monster()
{
    set_level(15 + random(4));
    set_name("big mudmonster");
    set_id(({ "monster", "mud", "big" }));
    set_short("Big Mudmonster");
    set_long(
      "A huge, monstrous, vaguely humanoid figure made of mud. It looks like it "+
      "had some player for lunch and is now going to have a player for dinner. "+
      "This one is much larger than any other mudmonster you've seen so far.");
    set(NPC_AGGRESSIVE);
    set(NPC_NO_CORPSE, 1);
    set_wander(0);
    set_money(400 + random(400) + query_level() * 10);

    set_spell_chance(15);
    set_spell_mess1(
      "Mudmonster sprays it's acrid secretion all over the place!");
    set_spell_mess2("Mudmonster sprays it's acrid secretion upon you!");
    set_spell_dam(30);
}

/* Redefine random_move(): don't wander out of own level */
random_move()
{
    command(({"north","south","east","west",
	"northwest","southwest","northeast","southwest"})[random(8)]);
}
