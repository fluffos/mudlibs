#include "ocean.h"

inherit MONSTER;

void create() {
    ::create();
    set("author", "gasman");
    set("prevent_summon" , 1);
    set("short", "Rydon the wicked");
    set("long", wrap(
	"This is Rydon the wicked. He has a scarred face from many battles."+
	"He is a very strong, bitter man and would enjoy seeing your demise."
      ));
    set("id", ({ "rydon" }) );
    set_name("rydon");
    set("race", "human");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at", "pound", "pummel" }) );
    set("damage", ({ 3, 25 }) );
    credit(random(140) + 10);
    set("gender", "male");
    set_level(15);
}

