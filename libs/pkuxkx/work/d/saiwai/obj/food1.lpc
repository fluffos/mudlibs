// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("熟牛肉", ({"shu niurou", "niurou","rou"}));
	set_weight(80);
	set("zjk_food",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一叠卤牛肉。\n");
		set("unit", "叠");
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
}
