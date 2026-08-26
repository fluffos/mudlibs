#include "ocean.h"

inherit MONSTER;


void create() {
    ::create();
    set("author", "gasman");
    set("prevent_summon", 1);
    set("short", "Kyrnad");
    set("long", wrap(
	"This is Master Kyrnad. He is a very wise and powerful man."+
	"You feel that you may be able to learn a lot from him if you"+
	"ask the right questions."
      ));
    set("id", ({ "Kyrnad", "kyrnad", "master" }) );
    set_name("kyrnad");
    set("race", "human");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at", "pummel" }) );
    set("damage", ({ 30, 4 }) );
    credit(random(40) + 10);
    set("gender", "male");
    set("inquiry", ([
      "training" : "You may train with me after you bring me the body of Gzhall.",
      "gzhall"   : "Gzhall is a foul beast who is not to be taken lightly.\nYou may find him about in the city.",
      "Gzhall"   : "Gzhall is a foul beast who is not to be taken lightly.\nYou may find him about in the city.",
      "city"     : "Well hopefully you can find your way to "+CITY_NAME+" from here.",
    ]));
    set("chat_chance", 25);
    set("chat_output", ({
      "Kyrnad says: Do you think you are worthy of my training?\n",
      "Kyrnad contemplates you\n",
    }) );
    set_level(90);
}

void init()
{
}
