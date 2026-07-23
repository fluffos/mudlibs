// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("百褶裙", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件丝绸作的漂亮裙子\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 33);
	}
	setup();
}
