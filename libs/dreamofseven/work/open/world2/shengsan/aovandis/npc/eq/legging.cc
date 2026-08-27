
#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("制式綁腿",({"typical leggings","leggings"}) );
	set("long",@LONG
這是奧凡迪斯守衛所裝備的戰鞋。
LONG
);
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "雙");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
