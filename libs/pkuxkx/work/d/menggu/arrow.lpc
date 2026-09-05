// arrow.c 狼牙箭

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("狼牙箭", ({ "langya jian","jian","arrow"}));
    set_weight(30);
	if( clonep() )
                set_default_object(__FILE__);
    else 
		{
			set("unit", "支");
			set("long", "这是一支狼牙箭。\n");
			set("value", 1);
			set("material", "steel");
			init_dagger(random(15));
		}
    setup();
}
