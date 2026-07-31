// TIE@fy3
#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
	set_name(HIW"银甲"NOR, ({ "yinjia", "jia" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "silver");
		set("value", 9000);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", -20);
	}
	setup();
}
