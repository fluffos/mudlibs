
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("银戒指", ({ "silver-finger", "finger" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一只白银打造的戒指，可以作为饰物，可增加小许攻击力。\n");
		set("unit", "只");
		set("value", 700);
		set("material", "silver");
		set("armor_prop/damage", 2);
//		set("weapon_prop/damage", 2);
		set("armor_prop/personality", 1);
		set("female_only", 0);
	}
	setup();
}

