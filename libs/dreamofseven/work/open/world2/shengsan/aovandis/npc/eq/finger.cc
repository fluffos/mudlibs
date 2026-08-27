#include <armor.h>
inherit FINGER;

void create()
{
	set_name("銀戒指",({"silver ring","ring"}) );
	set("long",@LONG
由純銀打造的戒子，閃著銀白色傲世的光輝。
LONG
	);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "silver");
		set("unit", "枚");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
