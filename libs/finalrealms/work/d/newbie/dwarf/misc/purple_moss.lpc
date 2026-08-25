inherit"std/object";
 
void init() {
    add_action("eat_me","eat");
     ::init();
}
 
void setup()
{
this_object()->add_property("MOSS",5);
set_name("moss");
add_alias("purple moss");
set_main_plural("mosses");
add_plural("purple mosses");
   set_short("Purple moss");
   set_long("This is some stringy purple moss.\n");
set_weight(2);
set_value(0);
}
 
 
int eat_me(string str) {
if(str == "moss" || str == "purple moss")
{
   say(this_player()->query_cap_name() + " eats some purple moss.\n");
	write("That tased good.  You feel better.\n");
	this_player()->adjust_hp(1);
	this_object()->dest_me();
    return 1;
}
 
}
