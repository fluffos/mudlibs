// jinpill.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("益精丸", ({ "ginpill", "pill" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗益精丸, 可以用来恢复精力。\n");
		set("unit", "颗");
		set("value", 1500);
		set("drugmark", 1);
		set("gin_supply", 50);
	}
}
