#include <mudlib.h>
inherit MONSTER ;
 
void create () {
::create();
seteuid(getuid());
set("short", "A rabid ape.");
set ("long", @Foo
This ape dosent like like he is right in the head. 
He's foalming at the mouth, and looks at you with at wierd
glint in is eye.
Foo
);
set("id", ({ "ape" }) );
set_level(8);
set_size(5);
set_name("Ape");
set("gender", "male");
set("race", "Ape");
set("aggressive", 1);
set("damage", ({ 1,4 }) );
set("weapon_name", "fists");
set_verbs( ({ "swipes at", "punches at", "smashes at" }) ) ;
enable_commands() ;
set("natt", 2);
set ("chat_chance", 6);
set ("chat_output", ({
"A rabid ape folms at the mouth!.\n",
}) );
set ("att_chat_output", ({
"A ribid ape screams and attacks you!\n",
}) );
}
