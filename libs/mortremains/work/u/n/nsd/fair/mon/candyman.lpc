/*
** File: candyman.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "candy man");
    set ("long", @EndText
Just a young man that will sell you all the food you want.
EndText);
    set("id", ({ "man", "candy man" }) );
    set_size(6);
    set_name("candy man");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({8,15}) );
    set("damage_type", "bludgeoning");
    set_verbs( ({"?"}) );
    set("weapon_name", "?");
    set("chat_chance", 10);
    set ("chat_output", ({
      "candy man says: If you're hungry or thirsty, this is the spot!\n",
      "candy man says: Come and buy your junk food here!!!\n",
    }) );
    set_level(8);
    set("no_attack", 1);
    set("prevent_summon", 1);
}
/* EOF */
