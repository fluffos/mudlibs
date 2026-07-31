
#include <armor.h>

inherit NECK;

void create()
{
	set_name("银项链", ({ "silver-neck", "neck" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条白银打造的项链，链坠上刻有如意吉祥四个字。\n");
		set("unit", "条");
		set("value", 1000);
		set("material", "silver");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
		set("female_only", 0);
	}
	setup();
}

