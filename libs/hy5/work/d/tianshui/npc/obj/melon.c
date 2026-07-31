// melon.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("哈密瓜", ({ "melon" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个大哈密瓜。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 6);
		set("food_supply", 10);
	}
	setup();
}