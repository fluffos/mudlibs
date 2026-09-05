//yitianjian.c
#include <weapon.h>

inherit AXE;

void create()
{
    set_name("开山斧", ({ "kaishan fu", "axe", "fu"}) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
                //set("value", 50000);
                set("value", 5000);
//        	set("no_drop", "1");
        	set("material", "iron");
        	set("long", "这是一柄极重的开山斧，看起来很厉害的样子。\n");
        	set("wield_msg","$N抡起一把$n。\n");
        	set("unwield_msg", "$N反手将$n别在背后。\n");
	}
    	init_axe(120, TWO_HANDED);
	setup();
}
