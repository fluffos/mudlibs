// music yangzhou' 包子

inherit ITEM;
inherit F_FOOD;

void create()
{       string *name= ({"烤羊羔", "红烧肘子", "三鲜烩肉", "清蒸肥鸡", "熏鱼串"});
        set_name( name[random(5)],({"food"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "碗");
		set("value", 50);
		set("food_remaining", 10);
		set("food_supply", 40);
	}
}
