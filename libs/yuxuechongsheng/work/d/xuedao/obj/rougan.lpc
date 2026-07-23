
// mitao.c 肉干
// By Marz

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("肉干", ({"gan", "rou gan"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘红红的肉干，好象没熟。\n");
		set("unit", "盘");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}

