#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIG  "千年温玉" NOR, ({ "old jade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);   else {
                set("unit", "块");
                set("long", "一块醉人的玉石，绿得醉人呀．．．上书一行小字：黄山派．你似乎可以用它来ｃｕｒｅ\n");
                set("max_cure",10);
                set("material", "stone");
        }
        init_hammer(10);
        setup();
}

