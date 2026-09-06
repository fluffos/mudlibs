// This object "evaporates poisonous gases"

#include <treasure.h>
#include <conditions.h>
#include <invis_levels.h>

#define DELAY 5

int duration;


do_damage(object ob) {
    if(!interactive(ob)) return;

    if(ob->query_condition(RESISTANCE(C_POISONED))) return;
    ob->tell_me("You feel poisoned and sick.");
    ob->add_hp(-random(duration));
}

check_room() {
    object *ob;

    call_out(#'check_room, DELAY);
    if(!environment()) return;

    ob = all_inventory(environment());
    filter_array(ob, #'do_damage);
}


create_treasure() {
    set_name("poison-em-all (tm)");
    set_invis(IL_TOTALLY_INVISIBLE);
}


init() {
    if(this_player()->add_condition(C_POISONED, duration/2+random(duration/2)))
	this_player()->tell_me("There's a strange smell in the air, making you feel \
a bit dizzy.");
    else
	this_player()->tell_me("There's a strange smell of poisonous gases in \
the air, but they don't seem to affect you!");
}


void
set_duration(int dur) {
    duration = dur;
    call_out(lambda(0, ({ #'destruct, ({ #'this_object }) }) ), dur);
    call_out(#'check_room, DELAY);
}


debug() {
    printf("duration: %d\n", duration);
}
