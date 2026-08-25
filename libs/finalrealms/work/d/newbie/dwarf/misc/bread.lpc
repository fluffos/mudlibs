inherit"std/object";
 
void init() {
    add_action("eat_me","eat");
}
 
void setup()
{
set_name("loaf of bread");
add_alias("loaf");
add_alias("bread");
set_main_plural("loaves of bread");
add_plural("loaves");
	set_short("Loaf of bread");
	set_long("This is a loaf of bread.  It looks a bit stale, "
		"but still tasty.  "
		"\n\n");
 
set_weight(2);
set_value(3000);
}
 
 
int eat_me(string str) {
if(str == "loaf" || str == "bread" || str == "loaf of bread"){
	say(this_player()->query_cap_name() + " eats a loaf of bread.\n");
	write("That tased good.  You feel better.\n");
	this_player()->adjust_hp(1);
	this_object()->dest_me();
    return 1;
}
 
}
