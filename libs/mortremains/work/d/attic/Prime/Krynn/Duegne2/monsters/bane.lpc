#include <mudlib.h>
inherit MONSTER;

void create(){
::create();
set("short","baneguard");
set("long","An evil looking Baneguard.\n");
set("id", ({"baneguard", "guard", "bane"}) );
set("race","skeleton");
set_name("baneguard");
set_level(5);
set("undead", 1);
set("damage", ({ 1, 5}) );
set("weapon_name", "hand");
set_verbs( ({ "punch", "swipe" }) );
set_verbs2(({"punches", "swipes"}));
enable_commands();
set("wealth", 100+(random(100)));
}
