// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("麻婆豆腐", ({"mapo doufu", "doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
               set("long", "一块麻辣的大豆腐，辣得来又好味，令人再想吃一块。\n");
		set("unit", "块");
                set("value", 80);
		set("food_remaining", 1);
               set("food_supply", 80);
	}
}
