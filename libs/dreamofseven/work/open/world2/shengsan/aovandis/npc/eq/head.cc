#include <armor.h>
inherit HEAD;

void create()
{
	set_name("制式頭盔",({"typical helmet","helmet"}) );
	set("long",@LONG
這是奧凡迪斯守衛所穿的頭盔。
LONG
);
	set_weight(3300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "頂");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
