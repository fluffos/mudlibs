// hat.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "白缨冠", ({ "white hat", "hat" }) );
	set_weight(1100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "一顶素面白布缝成的冠戴，缀著一条两尺长的白缨。\n");
		set("value", 4000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/composure", 5);
	}
	setup();
}
