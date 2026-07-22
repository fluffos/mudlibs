// cloth3.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(MAG "紫边长袍" NOR, ({ "chang pao", "cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件紫色镶边的长袍。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 10 );
		set("wear_msg","$N拿出一件$n穿在身上。\n");
		set("remove_msg","$N把$n从身上脱了下来。\n");
	}
	setup(); 
}
