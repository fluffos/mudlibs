// shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIW "冰山靴" NOR, ({ "snow boots", "shoes"}) );
       	set("long", "这是一双专门用来登冰山的靴子,靴底钉满了钉子\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "双");
		set("value", 50000);
		set("armor_prop/armor", 3 );
		set("armor_prop/personality", 3);
		//set("female_only", 1);
	}
	setup();
}
