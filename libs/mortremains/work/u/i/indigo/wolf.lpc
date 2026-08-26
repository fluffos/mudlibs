#include <mudlib.h>
inherit MONSTER ;

void create () {
  ::create();
seteuid(getuid());
set ("short", "A Wolf");
set ("long", @FOO
This is a black wolf from McKinzie Forest.
FOO
);
set("id", ({ "wolf" }) );
set_level(15);
set_size(5);
set_name("wolf") ;
set("gender", "male");
set("race", "wolf");
set("undead", 1);
set("damage", ({ 15, 25 }) );
set("weapon_name", "claws","teeth");
set_verbs( ({ "attack", "claw at", "bite at" }) );
set_verbs2( ({ "attacks", "claws at", "bites at" }) );
set("natt", 1);
set ("att_chat_output", ({
"The wolf growls then dives for your throat.\n",
"The wolf snaps at you with blood stained teeth.\n",
}) );
}
