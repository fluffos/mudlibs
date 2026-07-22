// cracked by vikee 2/09/2002   vikee@263.net

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("莲藕", ({"lian ou", "ou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "白嫩的莲藕，散发着诱人的清香。\n");
                set("unit", "颗");
		set("value", 10);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
