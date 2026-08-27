
#include <armor.h>
inherit WRISTS;

void create()
{
	set_name("制式護臂",({"typical wrists","wrists"}) );
	set("long",@LONG
這是奧凡迪斯守衛所裝備的護臂。
LONG
);
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "對");
		set("material", "steel");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
