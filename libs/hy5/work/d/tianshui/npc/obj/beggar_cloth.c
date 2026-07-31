// beggar_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("乞丐服", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一件满是补丁的破衣服。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}