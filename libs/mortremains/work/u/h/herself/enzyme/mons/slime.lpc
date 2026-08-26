
#include <mudlib.h>
inherit MONSTER;

void create(){
    ::create();
    set("author" , "enzyme");
    set("prevent_summon" , 1);
    set_name("green slime");
    set("id" , ({"slime"}) );
    set("short" , "a foul smelling slime");
    set("long" , wrap(
	"You have inadvertantly disturbed what appears to be nothing "+
	"more than a pile of greenish colored slime. You can "+
	"vaguely make out the remains of its former victims "+
	"still being slowly digested amid its flowing entrails. "+
	"The smell alone is almost enough to make you vomit. "
      ));
    set("race" , "slime");
    set("gender" , "neuter");
    set("agressive" , 1);
    set("weapon_name" , "slimey body");
    set_verbs(({"smother" , "engulf" }) );
    set("damage" , ({2,6}) );
    set("wealth" , (random(300)+300));
    set_level(18);
}
