//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

int dead() {
    this_object()->force_me("say You will regret this!");
    message("", "The guardian seems to float into the sky.", 
      environment(this_object()));
    this_object()->remove();
    return 0;
}

void create() {
    ::create();
    set_name("guardian");
    set_long("The guardian has an evil look on his face.");
    set_short("a forest guardian");
    set_id(({"guardian","forest guardian"}));
    set_race("gnome");
    set_body_type("gnome");
    set_level(60);
    set_gender("male");
    set_die( (: dead() :) );
}

int start() {
    this_object()->move("/d/citrin/rooms/shack1");
    message("", "One of the many forest guardians enters.", environment(this_object()));
    call_out("a", 3);
    return 1;
}

void a() {
    this_object()->force_me("say You have killed the last protector "
      "of the forest.  Soon the armies will raid.", environment(this_object()));
    call_out("b", 3);
}

int b() {
    message("", "The guardian disappears into thin air.", environment(this_object()));
    this_object()->remove();
    return 1;
}

