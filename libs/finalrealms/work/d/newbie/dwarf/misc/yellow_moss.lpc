inherit"std/object";

void init() {
    add_action("eat_me","eat");
    ::init();
}

void setup()
{
    this_object()->add_property("MOSS",4);
    set_name("moss");
    add_alias("yellow moss");
    set_main_plural("mosses");
    add_plural("yellow mosses");
    set_short("Yellow moss");
    set_long("This is some stringy yellow moss.\n");
    set_weight(2);
    set_value(0);
}


int eat_me(string str) {
    if(str == "moss" || str == "yellow moss")
    {
	say(this_player()->query_cap_name() + " eats some yellow moss.\n");
	write("That tasted good.\n");
	this_object()->dest_me();
	return 1;
    }

}
