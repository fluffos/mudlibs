
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("金戒指", ({ "gold-finger", "finger" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一只黄金打造的戒指，可以作为饰物，可增加小许攻击力。\n");
		set("unit", "只");
		set("value", 2000);
		set("material", "gold");
		set("armor_prop/damage", 2);
		set("armor_prop/personality", 2);
		set("female_only", 0);
	}
	setup();
}

