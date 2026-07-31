// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name(HIY"九爪龙袍"NOR, ({ "longpao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
set("armor_prop/armor", 50);
set("long","这是件黄色龙袍，用金丝绣上九条金龙，威风无比。\n");
	}
	setup();
}
