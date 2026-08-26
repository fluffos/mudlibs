/*
** File: tkseller.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

int ticket();
int set_giver(string);
int told;
object giver;
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    told = 0;
    set("author", "nsd");
    set("short", "ticket seller");
    set ("long", @EndText
This guy is here to sell you as many tickets as you want.
EndText);
    set("id", ({ "seller", "ticket seller" }) );
    set_size(6);
    set_name("ticket guy");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({8,15}) );
    set("damage_type", "bludgeoning");
    set_verbs( ({"?"}) );
    set("weapon_name", "?");
    set("chat_chance", 10);
    set ("chat_output", ({
      "ticket seller says: Buy your tickets here!!\n",
      "ticker seller says: Come and get your tickets here!!!\n",
    }) );
    set_level(8);
    set("no_attack", 1);
    set("prevent_summon", 1);
}
/* EOF */
