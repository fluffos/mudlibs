// zhutou.c 猪头

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("猪头肉", ({ "zhu tourou", "tourou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一片血淋淋的猪头肉。\n");
		set("unit", "片");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
	setup();
}

