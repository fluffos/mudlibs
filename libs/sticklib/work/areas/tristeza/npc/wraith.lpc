#include <npc.h>

void
create_monster()
{
    set_name("wraith");
    set_short("A horrible wraith");
    set_long(
      "It's a large (7' tall) dark, semi-ethereal shadowy figure, and \
VERY frightening to look at! Two spots of red light look back \
at you.");
    set_level(24);
    set(LIV_UNDEAD);
    set_wimpy(10);
    // set(NPC_NOT_AGGRESSIVE);
    set_alignment(AL_QUITE_EVIL);
    set(NPC_NO_CORPSE, 1); // Incorporeal; this won't leave a corpse
    set_hp(2000);
}

attack()
{
    string n;
    int loss;
    object att2;

    if (!::attack()) return 0;
    if (!is_fighting()) return 0;
    if (!(att2 = query_attack())) return 0;
    if (random(8) || att2->query_level() < 2) return 1;

    n = att2->query_name(); if (!n) n = "Someone";

    environment()->tell_here(
      "The wraith tries to touch " + n + ".", ({ att2 }));
    att2->tell_me(
      "The wraith tries to use its deadly touch upon you!");

    if (random(30) > att2->query_ac()) {
	tell_object(att2,"You barely manage to avoid it.\n");
	return 1;
    }

    att2 -> tell_me(
      "The wraith's deadly cold fingers reach your heart!");

    att2 -> add_stat(ST_STR, - (random(3)));
    att2 -> add_stat(ST_CON, - (random(3)));

    att2 -> tell_me(
      "\nTerrible coldness makes you very weak...");
    environment()->tell_here(n + " looks deathly pale.",
      ({ att2, this_object() }));

    return 1;
}

/* Redefine random_move(): don't wander out of own level */
random_move()
{
    command(({"north","south","east","west",
	"northwest","southwest","northeast","southwest"})[random(8)]);
}
