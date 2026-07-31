
#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("白纱裙", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "用轻柔细纱织成的裙子.\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 37);
	}
	setup();
}
