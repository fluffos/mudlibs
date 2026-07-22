// music yangzhou' 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("黄精", ({"huang", "jing"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一种山中的野山药,有明目,强健筋骨之效。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 80);
	}
}
