
#include <mudlib.h>
inherit MONSTER;
#include "area.h";

void create() {
    ::create();
    set_name ("living corpse");
    set("undead" , 1);
    set("prevent_summon" , 1);
    set("id" , ({"corpse" , "living corpse"}) );
    set("short" , "a living corpse");
    set("author" , "enzyme");
    set("long" , wrap(
	"A large lumbering being now stands before you. "+
	"Though long laid to rest here "+
	"this corpse still seems moist and sticky to the touch. "+
	"Something truly evil must have kept this poor soul "+
	"from eternal rest, but for what purpose... "
      ));
    set("gender" , "male");
    set("race" , "undead");
    wear(PATH+"armour/rags.c");
    set("weapon_name" , "hands");
    set_verbs(({"scratch" , "claw" , "pummel" , "hit"}) );
    set_verbs2( ({"scratches" , "claws" , "pummels" , "hits"}) );
    set("damage" , ({1,5}) );
    set_level(random(15)+2);
}
