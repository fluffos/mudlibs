/*
** File: pixie.c
** Date: August 25, 1999
** Purpose: a pixie
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {

::create();
seteuid(getuid());
enable_commands() ;

     set("author", "minx");
     set("short", "a pixie");
     set("long", @EndText
You see a small pixie, with tiny butterfly wings. She has
a disturbingly mischevious look in her wide green eyes.
EndText
     );
     set("id", ({ "pixie", "monster" }) );
     set_size(2);
     set_name("pixie");
     set("gender", "female");
     set("race", "pixie");
     set("live", 0);
     set("damage", ({ 1,3 }) );
     set("weapon_name", "hands");
     set_verbs( ({ "attack", "claw at", "scratch at" }) );
     set_verbs2( ({ "attacks", "claws at", "scratches at" }) );
     set("natt", 1);
     set("chat_chance", 10);
     set("chat_output", ({
"The pixie flutters about you, watching you curiously.\n",
     }) );
     set("att_chat_output", ({
"The pixie dives at you, green eyes twinkling malavolently.\n",
     }) );
     set_level(1);

}

/* End of File */
