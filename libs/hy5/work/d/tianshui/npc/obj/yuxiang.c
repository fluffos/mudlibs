// yuxiang.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鱼香肉丝", ({ "yuxiang"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "由醉仙阁精心烹制的鱼香肉丝。\n");
		set("unit", "份");
		set("value", 2000);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}