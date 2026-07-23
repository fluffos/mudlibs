// bkeepill.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("回气丸", ({ "keepill", "pill" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗回气丸, 可以用来恢复体力。\n");
		set("unit", "颗");
		set("value", 7500);
		set("drugmark", 2);
		set("drug_remaining", 5);
		set("kee_supply", 50);
	}
}
