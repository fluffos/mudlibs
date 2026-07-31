// shuimitao.c 水蜜桃


inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("水蜜桃", ({"tao", "mi tao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟水灵新鲜的水蜜桃，是唐门在龙泉山“百果山庄”的特产。\n");
		set("unit", "碟");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
