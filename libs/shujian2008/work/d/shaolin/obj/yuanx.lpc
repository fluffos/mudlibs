// mala-doufu.c 麻辣豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("元宵", ({"yuanxiao", "yuan", "xiao"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一碗白嫩柔滑，清香可口的元宵。是为了佳节特地命人赶制的。\n");
                set("unit", "碗");
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
