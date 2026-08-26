#include <mudlib.h>
inherit MONSTER ;
 
void create () {
::create();
seteuid(getuid());
set("short", "A jungle Villager");
set ("long", @Foo
This is a villager who lives in the jungle.
Foo
);
set("id", ({ "villager" }) );
set_level(7);
set_size(5);
set_name("villager");
set("gender", "male");
set("race", "Human");
set("aggressive", 1);
set("damage", ({ 1,4 }) );
set("weapon_name", "fists");
set_verbs( ({ "swipes at", "punches at", "smashes at" }) ) ;
enable_commands() ;
set("natt", 2);
set ("chat_chance", 6);
set ("chat_output", ({
"A villager paces about the room.\n",
}) );
set ("att_chat_output", ({
"A villager charges you!\n"
}) );
}

