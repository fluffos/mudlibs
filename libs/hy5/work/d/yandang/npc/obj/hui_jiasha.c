#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("灰色袈裟", ({ "qing_jiasha", "cloth" }) );
      set("long","一件灰色的袈裟.\n");
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 13);
		set("armor_prop/dodge", 12);
	}
	setup();
}
