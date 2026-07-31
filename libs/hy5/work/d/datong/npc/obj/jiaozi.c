// jiaozi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("一力蒸饺", ({ "zheng jiao" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "大同府有名的一力蒸饺。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
	setup();
}
