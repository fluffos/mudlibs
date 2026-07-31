// yinyu.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("银鱼羹", ({ "yinyu"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由醉仙阁精心烹制的银鱼羹。\n");
		set("unit", "份");
		set("value", 2000);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}