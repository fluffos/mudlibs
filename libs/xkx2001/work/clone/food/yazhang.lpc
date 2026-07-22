//Cracked by Roath
// yazhang.c 鸭掌

inherit ITEM;
inherit F_FOOD;

void init();

void create()
{
	set_name("鸭掌", ({"ya zhang", "yazhang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只肥鸭的鸭掌。\n");
		set("unit", "只");
		set("value", 30);
		set("food_remaining", 1);
		set("food_supply", 60);
	}

	setup();
}

