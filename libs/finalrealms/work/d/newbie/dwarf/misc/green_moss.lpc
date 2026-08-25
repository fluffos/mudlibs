inherit"std/object";
 
void init() {
    add_action("eat_me","eat");
     ::init();
}
 
void setup()
{
this_object()->add_property("MOSS",3);
set_name("moss");
add_alias("green moss");
set_main_plural("mosses");
add_plural("green mosses");
   set_short("Green moss");
   set_long("This is some stringy green moss.\n");
set_weight(2);
set_value(0);
}
 
 
int eat_me(string str) {
if(str == "moss" || str == "green moss")
{
   say(this_player()->query_cap_name() + " eats some green moss.\n");
   write("That tasted good.\n");
	this_object()->dest_me();
    return 1;
}
 
}
