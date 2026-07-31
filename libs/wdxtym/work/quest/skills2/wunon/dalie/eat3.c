// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("—º»‚", ({ "liewu3" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "“ªøÈ—º»‚\n");
		set("unit", "øÈ");
		set("value", 450);
		set("food_remaining", 3);
		set("food_supply", 60);


	}
}
