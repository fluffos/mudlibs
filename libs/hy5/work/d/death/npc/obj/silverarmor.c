// TIE@fy3
#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
	set_name(HIW"Òø¼×"NOR, ({ "yinjia", "jia" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "silver");
		set("value", 900);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", -20);
	}
	setup();
}
