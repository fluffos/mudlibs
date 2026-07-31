// music yangzhou' °ü×Ó

inherit ITEM;
inherit F_FOOD;

void create()
{       string *name= ({"¿¾Ñò¸á", "ºìÉÕÖâ×Ó", "ÈıÏÊ»âÈâ", "ÇåÕô·Ê¼¦", "Ñ¬Óã´®"});
        set_name( name[random(5)],({"food"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Íë");
		set("value", 50);
		set("food_remaining", 10);
		set("food_supply", 40);
	}
}
