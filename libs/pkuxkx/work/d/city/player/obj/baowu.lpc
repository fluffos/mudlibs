#pragma save_binary
inherit ITEM;
#include <ansi.h>

void create()
{
        string *order = ({HIM"紫烟含珠"NOR,HIY"万象金佛"NOR, HIG"翡翠观音"NOR, HIR"火玲珑"NOR, HIC"碧海沉砂"NOR, HIY"百鸟朝凤图"NOR, HIC"千手观音"NOR});
        set_name( (order[random(7)]), ({ "bao wu", "baowu" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件宝物。\n");
                set("unit", "件");
                set("value", 1);
             set("no_pawn",1);
             set("no_store",1);
        set("treasure", 1);
           }
        setup();
}
