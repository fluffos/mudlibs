/*
** File: mistake.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid() );
    enable_commands();
    set("author", "nsd");
    set("short", "a cow-clone mistake");
    set("long", @EndText
This amorphic mass has no legs, no hair, no tail...
The head is the size of a tenniss ball, with no
horns, no eyes, no nostrills,... Only a mouth large
enough to insert a straw. That's how this thing feeds.
The only hint of life on this creature is the ocasional
convulsions it has. For some strange reason, the image
that comes to mind is a Big Mac... Hmm...
EndText);
    set("id", ({"clone", "cow", "mistake", "clone-cow", "clone cow mistake"}) );
    set_size(5);
    set_name("cloned cow");
    set("gender", "neuter");
    set("race", "cow");
    set("undead", 0);
    set("damage", ({ 8, 15 }) );
    set_verbs( ({ "fist", "slash", "swing at", "attack" }) );
    set_verbs2( ({ "fists", "slashes", "swings at", "attacks" }) );
    set("natt", 2);
    set("chat_chance", 15);
    set("chat_output", ({
      "the cloned cow starts to convulse most disgustingly...\n",
      "the cloned cow barely breathes...\n",
      "You wonder if science will keep on making this kind of.. thing!\n",
    }) );
    set_level(10);
    set("prevent_summon", 1);
}
/* EOF */
