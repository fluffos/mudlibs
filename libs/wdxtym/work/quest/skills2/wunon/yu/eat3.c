// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大黄鱼", ({ "yu3" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条大黄鱼\n");
		set("unit", "条");

		set("value", 1);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
