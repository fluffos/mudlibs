// /d/meizhuang/obj/lingqi.c 五岳令旗

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"五岳令旗"NOR, ({ "wuyue lingqi","wuse lingqi", "lingqi" }));
        set_weight(1000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long","这是一面上等绸缎做成的旗帜，宝光四耀，上面镶满了珍珠宝石。\n");
                set("value", 100000000);
        }
        setup();
}
