#include <std.h>
inherit OBJECT;

object interior;

void setup(int nat, string sheltroom, string where) {
  interior = new(sheltroom);
  interior->add_exit(where, "out");
  call_out("collapse", nat);
}

void create() {
    ::create();

    set_name("shelter");
    set_short("a Sturdy Shelter");
    set_long("The shelter has been made out of some wood gathered in"
      " the woods and is held together by strands of sinew.");
    set_id(({"build_shelter_ob","shelter","sturdy shelter"}));
    set_mass(200);
    set_prevent_get("You cannot carry an entire shelter.");
    set_value(0);
}

void init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {
    if(str != "shelter" || !objectp(interior))
	return notify_fail("Enter what?\n");
    this_player()->move_player(interior, "into the shelter");
    return 1;
}

void collapse() {
    message("info","As the shelter begins to collapse, everyone moves outside.", ({ interior, environment(this_object()) }) );
    all_inventory(interior)->move(environment(this_object()));
    interior->remove();
    if(interior)
	destruct(interior);
    this_object()->remove();
}
