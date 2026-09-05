// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("面饼", ({"mian bing", "mianbing","bing"}));
	set_weight(80);
	set("zjk_food",2);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一摞香喷喷的面饼。\n");
		set("unit", "摞");
		set("value", 0);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
