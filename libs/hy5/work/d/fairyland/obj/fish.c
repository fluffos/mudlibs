// fish.c 大白鱼
// By jpei

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大白鱼", ({ "white fish", "da baiyu", "baiyu", "fish", "yu" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条足有一尺多长的大白鱼。\n");
		set("unit", "条");
		set("value", 500);
		set("food_remaining", 5);
		set("food_supply", 20);
		set("material", "fish");
	}
	setup();
}

int finish_eat()
{
	set_name("鱼骨", ({ "fish bone", "yu gu", "bone", "gu" }) );
	set_weight(150);
	set("long", "一根啃得精光的鱼骨头。\n");
	set("unit", "根");
	set("value", 0);
	set("material", "bone");
	return 1;
}
