// noodles.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        string *name = ({"刀削面","阳春面","龙须面","鸡丝面","牛肉拉面",
			"肉丝面","排骨面","海鲜面","鸡蛋面"});
	set_name( name[random(9)], ({ "noodles" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的面条。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 6);
		set("food_supply", 20);
	}
	setup();
}