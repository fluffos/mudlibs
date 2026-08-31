//  Created by Whit
#include <std.h>
inherit OBJECT;
int p = 0;
int look_fern();

void create() {
    ::create();
    set_name("red fern");
    set_short("red fern");
    set_long((: look_fern() :));
    set_id(({"fern", "red fern"}));
    set_prevent_get("Its roots are stuck in the ground.");
    p = 0;
}

void init() {
    ::init();
    //    add_action("look_fern", "look");
}

void reset() {
    ::reset();
    if(p>10) p = 0;
}

int look_fern() {
    if(p>10) {
         write("The red fern grows along the path here. It looks to be very poisonous.");
     return 1;
    }
    say(this_player()->query_cap_name()+" gets too close to the "
      "fern and is poisoned.");
    this_player()->add_poisoning(6);
    p++;
     write("You get too close to the fern and are poisoned.");
    return 1;
}

