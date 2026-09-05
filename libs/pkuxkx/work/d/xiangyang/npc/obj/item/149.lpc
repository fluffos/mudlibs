// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大麻花", ({"da mahua"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一根又酥又脆的麻花\n");
		set("unit", "根");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
} 
                     
