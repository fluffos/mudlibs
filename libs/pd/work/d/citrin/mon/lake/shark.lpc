#include <std.h>
#include <citrin.h>

inherit MONSTER;

int load_weapon() {
    object ob;

    ob = new(WEAPON);
    ob->set_name("sharks tooth");
    ob->set_short("a serrated sharks tooth");
    ob->set_long("The blade is short and narrow.  It has a serrated side "
      "to tear through unsuspecting victims.");
    ob->set_wc(9);
    ob->set_wield("You feel the urge to tear something apart with "
      "this knife.");
    ob->set_type("knife");
    ob->set_id(({ "serrated knife", "tooth", "sharks tooth", "serrated sharks tooth" }));
    ob->move(this_object());
    force_me("wield knife");
    return 1;
}

void create() {
    ::create();
    set_name("shark");
    set_short("a mean looking shark");
    set_long("The shark looks very mean.  Its teeth are very sharp.");
    if(random(2)) set_level(35); else
	set_level(45);
    if(random(2)) set_gender("male"); else
	set_gender("female");
    set_race("shark");
    set_body_type("fish");
    set_id(({ "shark", "mean shark", "mean looking shark" }));
    if(!random(10)) load_weapon();
}

