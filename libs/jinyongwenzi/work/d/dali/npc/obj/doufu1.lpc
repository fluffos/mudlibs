
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("翡翠豆腐", ({"feicui doufu", "doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块水灵灵的大豆腐，嫩的令人不禁想到老板娘的脸蛋儿。\n");
		set("unit", "块");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 50);
	}
}
