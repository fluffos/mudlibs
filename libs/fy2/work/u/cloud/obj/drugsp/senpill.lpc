// senpill.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("提神丸", ({ "senpill", "pill" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗提神丸, 可以用来提神。\n");
		set("unit", "颗");
		set("value", 1500);
		set("drugmark", 3);
		set("sen_supply", 50);
	}
}
