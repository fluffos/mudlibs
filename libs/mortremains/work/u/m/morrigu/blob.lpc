/*File: blob.c
Purpose: Blob template for metamorph
Author: Morrigu
Date 9/97
Other stuff: It's cold out.
*/

#include <mudlib.h>
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "a giant blob");
set("long", @Slime
This thing looks like a giant aemoeba!  What the heck
is it doing here?
Slime
);
set("id", ({"blob"}));
set_level(15);
set_size(10);
set_living_name("a blob");
set_name("a blob");
set("gender", "neuter");
set("race", "aemoebatta");
set("damage", ({4,16}));
set_verbs(({"smack", "thud", "bonk"}));
set_verbs2(({"smacks", "thuds", "bonks"}));
set("weapon_name","giant psuedopod");
set("natt", 8);
}
