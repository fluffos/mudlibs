#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("羊皮靴" ,({"yangpi xue","xue"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
	set("long","一双藏人常穿的靴子。\n");
	set("value",1500);
		set("material", "boots");
		set("armor_prop/dodge", 3);
	}
	setup();
}
