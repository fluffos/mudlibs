// suji.c ËØ¼¦

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("½´ÏãÅ£Èâ", ({"niu rou", "niurou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»½ï×ö¹¤¿¼¾¿½´ÏãÅ£Èâ¡£\n");
		set("unit", "½ï");
		set("value", 350);
		set("food_remaining", 10);
		set("food_supply", 90);
	}
}
