#include <armor.h>
inherit SHIELD;

void create()
{
	set_name("防暴盾牌",({"riot shield","shield"}) );
	set("long",@LONG
這是奧凡迪斯守衛所裝備的防暴盾牌。
LONG
);
	set_weight(6600);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "面");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
