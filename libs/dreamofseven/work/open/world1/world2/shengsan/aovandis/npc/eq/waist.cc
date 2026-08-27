#include <armor.h>
inherit WAIST;

void create()
{
	set_name("腰帶",({"belt"}));
	set("long",@LONG
這條項鍊是由許多的美麗琉璃珠所串成的，到現在為止這種美麗的珠子
已經很少人會做了。
LONG
	);
	set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "串");
	}
	set("auto_set",2);
	setup();
}
// int query_autoload() { return 1; }

