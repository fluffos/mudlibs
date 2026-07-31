// doudou.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("红兜兜", ({ "doudou" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一件小孩子穿的红兜兜。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}