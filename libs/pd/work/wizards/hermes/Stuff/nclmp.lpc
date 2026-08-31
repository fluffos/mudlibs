inherit ARMOUR;
void create() {
::create();
set_name("clamps");
set_short("Nipple Clamps");
set_long("For pleasure and pain");
set_id(({"nipple clamps", "clamps"}));
set_ac(0);
set_weight(0);
set_type("garter");
set_limbs(({"torso"}));
}
int query_auto_load() {
if (this_player()->query_name()== "sugarcandy" || this_player()->query_name()== "hermes")
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
