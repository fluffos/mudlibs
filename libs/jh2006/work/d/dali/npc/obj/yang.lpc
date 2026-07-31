
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("东山羊", ({"dong shanyang", "dong", "shanyang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗铁板烧出来的羊崽肉，海南特产。\n");
		set("unit", "碗");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
