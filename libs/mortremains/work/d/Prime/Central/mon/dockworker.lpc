/*
** File: githyanki.c
** Purpose: Creates a random githyanki type.
** Credits:
**   15Nov97  Cyanide created the file.
*/

#include <mudlib.h>
#include <daemons.h>
#include "../central.h"

int level;
object armor, class_ob, weapon, tmp_ob;
string *classes;
string race;

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());

    // set("aggressive", 8);   // It attacks all non-githyanki.
    switch(random(30)) {
    case 1..10 : race = "human"; break;
    case 11..17 : race = "orc"; break;
    case 18..21 : race = "half-orc"; break;
    case 22..24 : race = "dwarf"; break;
    case 25..26 : race = "elf"; break;
    case 27..29 : race = "half-elf"; break;
    }

    set("author", "cyanide");
    set("prevent_summon", 1);
    set("race", race);
    if (!random(10)) set("gender", "female");
    else set("gender", "male");
    set_size(6);
    set_name("worker");
    set("id", ({ "worker", "dock worker", query("race") }) );
    set("short", article(query("race"))+" "+query("race")+
      " dock worker");
    set ("damage", ({ 4,6 }) ) ;
    set ("weapon_name", "fists") ;
    set_verbs( ({ "swing at" }) );
    set("stat/strength", 15+random(5) );
    set("special", 1);
    set("mage_spells", ({}) );
    credit(200+random(200));

    // Cyanide: Let's figure out the thing's level like this:
    switch (random(100)+1) {
    case  1..20 : level = 3; break;
    case 21..30 : level = 4; break;
    case 31..40 : level = 5; break;
    case 41..60 : level = 6; break;
    case 61..80 : level = 7; break;
    case 81..90 : level = 8; break;
    case 91..95 : level = 9; break;
    case 96..98 : level = 10; break;
    default : level = 11; break;
    }
    set_level(level);

    set("chat_chance", 8);
    set("chat_output", ({
      "The worker busts "+possessive(query("gender"))+" ass.\n",
    }) );
}

/* EOF */
