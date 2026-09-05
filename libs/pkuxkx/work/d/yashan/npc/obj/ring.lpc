//贝壳戒指
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIB"贝壳戒指"NOR, ({ "beike ring", "ring" }));
	set_weight( 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 5);
		set("material", "stone");
		set("armor_prop/armor", 1);
	}
	setup();
}	
