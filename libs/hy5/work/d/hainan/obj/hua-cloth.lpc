// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("花短褂", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "小女孩穿的花褂子,上面点缀着一些小碎花\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 34);
	}
	setup();
}
