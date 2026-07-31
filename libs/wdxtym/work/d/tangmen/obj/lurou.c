// lurou.c Ò°Â¹Èâ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Â¹Èâ", ({"lu rou", "rou"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»´ó¿éÏÊÑªÁÜÀìµÄÒ°Â¹Èâ£¬ºÜ²¹µÄ¡£\n");
		set("unit", "¿é");
		set("value", 300);
		set("food_remaining", 5);
		set("food_supply", 60);
	}
}
