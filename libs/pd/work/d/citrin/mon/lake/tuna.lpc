#include <std.h>
#include <citrin.h>

inherit MONSTER;

int pre_death() {
    object ob;
    ob = new(FOOD);
    ob->set_name("some tuna");
    ob->set_short("some tuna fish");
    ob->set_long("This is some yummy looking tuna!");
    ob->set_my_mess("You gobble down the tuna happily.");
    ob->set_your_mess("gobbles down some tuna.");
    ob->set_dis(1);
    ob->set_strength(4);
    ob->set_id(({ "some tuna", "some tuna fish", "tuna" }));
    ob->move(this_object());
    return 1;
}

void create() {
    ::create();
    set_name("tuna fish");
    set_short("a swimming tuna fish");
    set_long("The tuna fish is swimming through the current.  It looks "
      "like it is having some trouble.");
    if(random(2)) set_level(30); else
	set_level(40);
    if(random(2)) set_gender("male"); else
	set_gender("female");
    set_race("tuna fish");
    set_body_type("fish");
    set_id(({ "tuna", "tuna fish" }));
    if(random(2)) set_die((: pre_death() :));
}

