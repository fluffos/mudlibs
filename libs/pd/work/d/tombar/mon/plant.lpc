#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("evil plant");
    set_short("a hellish plant");
    set_long("This plant looks extremly strong.  It's mouth opens as you look "
      "at it.");
    set_level(48);
    set("race", "plant");
    set_body_type("plant");
    set_id(({"plant", "hellish plant"}));
    set_class("fighter");
    set_subclass("paladin");
    set_spells(({"rush", "jab"}));
    set_spell_chance(90);
}

void init() {
    ::init();
    add_action("kill", "kill");
}

int kill(string str) {
    if(!str) return 0;
    if(str != "plant" && str != "hellish plant") return 0;
    say(this_player()->query_cap_name()+" attackes Evil Plant.");
    say("The plant opens its mouth and launches a huge ball "
      "of fire at "+this_player()->query_cap_name());
    write("The plant launches a huge ball of fire at you.\n");
    this_player()->add_hp(random(-100));
    message("info", "The plant's fire ball hits and it hurts.\n"
      "hp: "+this_player()->query_hp()+"    sp: "+this_player()->query_sp()+""
      "    mp: "+this_player()->query_mp(), this_player());
    return 0;
}
