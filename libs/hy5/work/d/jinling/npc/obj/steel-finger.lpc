
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("铁戒指", ({ "steel-finger", "finger" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一只生铁铸成的戒指，上面有锋利的菱角，是一件不错的武器。\n");
		set("unit", "只");
		set("value", 500);
		set("material", "steel");
		set("armor_prop/damage", 8);
		set("armor_prop/armor", 1);
		set("armor_prop/personality", -1);
		set("female_only", 0);
	}
	setup();
}

