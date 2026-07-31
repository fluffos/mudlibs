
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("龙抄手", ({"long chaoshoui", "chaoshou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一红油抄手，四川特产，红红颜色真吸引人。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}
