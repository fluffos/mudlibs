//Cracked by Roath
// byskirt.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIY"明黄锦袍"NOR, ({ "minghuang jinpao","jin pao","pao" }) );
	set("long", "这是一件明黄色的锦袍，只有皇室的成员才能穿上。\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	setup();
}
