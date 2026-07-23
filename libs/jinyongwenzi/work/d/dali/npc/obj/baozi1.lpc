
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("狗不理包子", ({"goubuli baozi", "baozi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一笼刚出锅的狗不理包子，香气扑鼻。\n");
		set("unit", "笼");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
