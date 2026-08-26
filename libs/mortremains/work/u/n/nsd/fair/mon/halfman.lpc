/*
** File: halfman.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid() );
    enable_commands();
    set("author", "nsd");
    set("short", "a half man");
    set("long", @EndText
A sad-looking half man. This guy is only chest, arms, and head.
The rest of his body from waist to down is missing. You wonder
how a being on these conditions can still be alive...
EndText);
    set("id", ({"man", "half", "half man"}) );
    set_size(3);
    set_name("half man");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({ 8, 15 }) );
    set("weapon_name", "fists");
    set_verbs( ({ "fist", "slash", "swing at", "attack" }) );
    set_verbs2( ({ "fists", "slashes", "swings at", "attacks" }) );
    set("natt", 2);
    set("chat_chance", 15);
    set("chat_output", ({
      "Half man starts to pace his little space with his hands.\n",
      "Half man stares at you sadly.\n",
      "Half man says [to you] : what? \n",
      "Half man wishes this day ends quickly...\n",
      "Half man says [to you] : I'm tired of being observed as an oddity.\n",
      "Half man looks deeply bored...\n",
      "Half man says [to you] : If I could only get the one who did this\n"+
      "to me I would...   And makes a gesture of strangle with his hands.\n",
    }) );
    set_level(10);
    set("prevent_summon", 1);
}
/* EOF */
