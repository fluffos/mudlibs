#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("ºµÑÌ¸Ë", ({ "hanyangan", "hanyan" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("value", 70);
		set("material", "wood");
	}
 init_hammer(111);
 setup();
}
