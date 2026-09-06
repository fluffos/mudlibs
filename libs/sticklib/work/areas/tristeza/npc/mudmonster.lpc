#include <npc.h>

void
create_monster()
{
    set_level(10 + random(4));
    set_name("mudmonster");
    set_id(({ "monster", "mud" }));
    set_short("Mudmonster");
    set_long(
      "A monstrous, vaguely humanoid figure made of mud. It looks like it "+
      "had some player for lunch and is now going to have a player for dinner.");
    set(NPC_AGGRESSIVE);
    set(NPC_NO_CORPSE, 1);
    set_wander(4);

    set_spell_chance(15);
    set_spell_mess1(
      "Mudmonster sprays it's acrid secretion all over the place!");
    set_spell_mess2("Mudmonster sprays its acrid secretion upon you!");
    set_spell_dam(20);
}

/* Redefine random_move(): don't wander out of own level */
random_move()
{
    command(({"north","south","east","west",
	"northwest","southwest","northeast","southwest"})[random(8)]);
}
