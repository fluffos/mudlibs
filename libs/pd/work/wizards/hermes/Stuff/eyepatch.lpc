#include <std.h>
inherit ARMOUR;
void create() {
::create();
set_name("eyepatch");
set_short("A Pirate's Eyepatch");
set_long("Yar har har! Now you can make everyone walk the plank!");
set_id(({"eyepatch"}));
set_ac(0);
set_weight(0);
set_type("armour");
set_limbs(({"head"}));
}
int query_auto_load() {
if (this_player()->query_name()== "autema" || this_player()->query_name()== "hermes")
return 1; 
}
void init()
{
	::init();
	set_heart_beat(5);
}
void heart_beat()
{
	if(random(100) < 10)
	{
		this_player()->force_me("newbie YAR HAR HAR");
	}
}
