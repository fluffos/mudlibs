/* Pirated from Cattt's hunter.c */
/* By Grull */
#include <mudlib.h>
#include "../GenericLib.h"

inherit MONSTER;

void create(){
    ::create();
    seteuid(getuid());
    set("author", "grull");
    set("short", "a rotting zombie");
    set("long", wrap("This zombie seems more an animated corpse than "+
	"a living being. It moves, but seems motivated from some "+
	"outside magicks. It glows slightly with the aura of evil."));
    set("id", ({"zombie", "Zombie"}) );
    set_name("Zombie");
    set("prevent_summon", 1);
    enable_commands();
    set("gender", "male");
    set("undead", 1);
    set("race", "undead");
    set("damage", ({ 3,5 }) );
    set("weapon_name", "fists");
    set("stat/strength", 16);
    set("stat/dexterity", 12);
    set_verbs( ({ "punch at", "shove at", "push at" }) );
    set_verbs2( ({ "punches at", "shoves at", "pushes at" }) );
    set("chat_chance", 5);
    set("chat_output",({
      "The zombie turns to you, but seems to see straight through you.\n",
      "The air seems to crackle with the dark energies of the zombie's magic!\n",
    }));

    set_size(6);
    set_level(random(4)+4);
}
