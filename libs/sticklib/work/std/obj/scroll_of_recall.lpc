#include <treasure.h>

#include <conditions.h>
#include <room_defs.h>
#include <generic_rooms.h>

void
create_treasure()
{
    set_short("Scroll of Recall");
    set_long("Read scroll in case of emergency.");
    set_name ("scroll of recall");
    set_id(({ "scroll" }));
    set_value(2000);
    set_weight(1);
}

void
init() {
    add_action("read","read");
    add_action("read","recite");
}

int
read(string str)
{
    if(!str || !id(str))
	return 0;
    if(!this_player()->query_can_move()) {
	this_player()->tell_me("You cannot move a muscle!");
	return 1;
    }
    if(environment(this_player())->query(PREVENT_TELEPORT)) {
	this_player()->tell_me("You cannot use it here.");
	return 1;
    }
    this_player()->tell_me("You recite the Scroll of Recall and you lose your consciousness.");
    this_player()->set_condition(C_UNCONSCIOUS,10);
    this_player()->move_player("X", GENERIC_ROOM_CHURCH);
    this_player()->set_rest(1, 1);
    destruct(this_object());
    return 1;
}
