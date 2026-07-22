// music yangzhou' 包子

inherit ITEM;
inherit F_FOOD;

void create()
{       string *name= ({"富春包子", "生煎馒头", "春卷", "煎饼", "锅贴"});
        set_name( name[random(5)],({"food"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 10);
		set("food_supply", 40);
	}
}
