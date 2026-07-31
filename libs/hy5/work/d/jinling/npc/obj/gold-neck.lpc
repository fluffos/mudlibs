
#include <armor.h>

inherit NECK;

void create()
{
	set_name("金项链", ({ "gold-neck", "neck" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条金灿灿的项链，链坠上镶着一粒红宝石。\n");
		set("unit", "条");
		set("value", 5000);
		set("material", "gold");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 5);
		set("female_only", 0);
	}
	setup();
}

