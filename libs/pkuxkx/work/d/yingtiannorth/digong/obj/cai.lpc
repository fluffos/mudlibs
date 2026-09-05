inherit ITEM;
#include <ansi.h>

int is_KARMA_MATERIAL()
{
	return 1;
}
void create()
{
	set_name("木材",({ "mu cai", "mu", "cai"}) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是一根可以用来在河边造船(zaochuan)的木材。\n");
                set("unit", "根");
                set("value", 0);
                set("material", "wood");
			}
	setup();
}

