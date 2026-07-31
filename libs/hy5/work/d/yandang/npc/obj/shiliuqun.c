#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("石榴裙", ({ "skirt", "shiliuqun" }) );
      set("long","一件红色的石榴裙.\n");
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/dodge", 11);
	}
	setup();
}
