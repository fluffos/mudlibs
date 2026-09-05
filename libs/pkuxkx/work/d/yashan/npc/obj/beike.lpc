//贝壳项链
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(HIW"贝壳项链"NOR, ({ "beike necklace", "necklace", "lace" }));
	set_weight( 10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("value", 10);
		set("material", "stone");
		set("armor_prop/armor", 1);
	}
	setup();
}	
