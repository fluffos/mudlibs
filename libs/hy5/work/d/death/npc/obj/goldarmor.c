// TIE@fy3
#include <ansi.h>
#include <armor.h>
inherit HEAD;
void create()
{
	set_name(HIY"½ð¿ø"NOR, ({ "jinkui", "kui" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¶¥");
		set("material", "gold");
		set("value", 9000);
		set("armor_prop/armor", 50);
		set("armor_prop/dodge", -20);
	}
	setup();
}
