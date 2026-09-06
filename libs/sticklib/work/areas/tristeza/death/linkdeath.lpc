/* link_death.c */
/* Mr. Link Death, brother of Death G. Reaper */
/* A jolly fellow who likes riddles */

#include <npc.h>

void
create_monster()
{
    set_name("link death");
    set_id(({ "link", "death", "linkdeath" }));
    set_living_name("linkdeath");
    set_level(40);
    set_race("immortal");
    set_short("Link Death");
    set_long(
      "Link Death is a large Red Skeleton. He is a happy fellow, with a constant \
smile on his skeletal face.");

    set_chance(25);
    set_spell_mess2("Link Death casually hurls a deathball upon you.");
    set_spell_mess1("Link Death yawns.");
    set_spell_dam(300);
}

/* Link Death cannot die. So redefine hit_player(). */
int
hit_player(int dam, int dtype, int hc, object enemy)
{
    return ::hit_player(0, dtype, hc, enemy);
}
