inherit"std/object";

void init() {
    add_action("eat_me","eat");
    ::init();
}

void setup()
{
    this_object()->add_property("MOSS",1);
    set_name("moss");
    add_alias("blue moss");
    set_main_plural("mosses");
    add_plural("blue mosses");
    set_short("Blue moss");
    set_long("This is some stringy blue moss.\n");
    set_weight(2);
    set_value(0);
}


int eat_me(string str) {
    if(str == "moss" || str == "blue moss")
    {
        say(this_player()->query_cap_name() + " eats some blue moss.\n");
        write("That tasted good.  You feel better.\n");
        this_player()->adjust_hp(1);
        this_object()->dest_me();
        return 1;
    }
}

