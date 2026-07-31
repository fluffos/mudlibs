// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit ARMOR;

void create()
{
	set_name(HIR "闯王战甲" NOR, ({ "cw_armor","armor"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\n这是李闯王的盔甲。纯金打治,端的是气派非凡!\n");
		set("unit", "件");
		set("no_put", 1);
//		//set("value", 100000);
		set("material", "金子");
		set("armor_prop/armor", 800);
		set("armor_prop/personality", 10);
		set("armor_prop/defense", 20);	
	}
	setup();
}

