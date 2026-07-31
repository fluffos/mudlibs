// 汲取勋章
inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIG"限定汲取勋章"NOR, ({ "jiqu xunzhang" }) );
	        set("long", "一枚限定版汲取勋章，可以加快汲取速度。\n");
                set("yuanbao", 30000); 
				set("unit","枚");
		    set("no_sell", 1);
                set("no_give", 1);
                set("no_steal", 1);
		    set("no_drop", 1);
	setup();
}
int query_autoload() { return 1; }
