inherit"std/object";
 
void init() {
    add_action("eat_me","eat");
}
 
void setup()
{
set_name("moss");
add_alias("red moss");
set_main_plural("mosses");
this_object()->add_property("MOSS",5);
add_plural("red mosses");
	set_short("Red moss");
   set_long("This is some stringy red moss.\n");
set_weight(2);
set_value(0);
}
 
 
int eat_me(string str) {
if(str == "moss" || str == "red moss")
{
   say(this_player()->query_cap_name() + " eats some red moss.\n");
	write("That tased good.  You feel better.\n");
	this_player()->adjust_hp(1);
	this_object()->dest_me();
    return 1;
}
 
}
