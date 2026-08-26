/*
** File: dog.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid() );
    enable_commands();
    set("author", "nsd");
    set("short", "a hairless dog");
    set("long", @EndText
This is a genetically manipulated dog. He's born hairless.
It's creator designed it to not leave hair balls on your
furniture and rugs. Nice for you, but what about him?
Hair is an important element on any animal....
Science has done it again. >:-(
EndText);
    set("id", ({"dog", "hairless", "hairless dog"}) );
    set_size(5);
    set_name("hairless dog");
    set("gender", "male");
    set("race", "dog");
    set("undead", 0);
    set("damage", ({ 8, 15 }) );
    set_verbs( ({ "fist", "slash", "swing at", "attack" }) );
    set_verbs2( ({ "fists", "slashes", "swings at", "attacks" }) );
    set("natt", 2);
    set("chat_chance", 15);
    set("chat_output", ({
      "the dog shivers, shivers, and shivers. He's cold...\n",
      "the dog moans sadly because he's cold.\n",
      "the dog stares at you with his sad rounded eyes.\n",
      "the dog shivers uncontrolably...\n",
    }) );
    set_level(10);
    set("prevent_summon", 1);
}
/* EOF */
