 inherit ITEM;
#include <ansi.h>
inherit F_LIQUID; 
void create()
{
        set_name(HIG"盘龙杯"NOR, ({ "dragon cup", "cup" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long", "一个碧玉雕成，盛满了太行美酒的盘龙杯。\n");
                set("unit", "个");
                set("value", 20000);
                set("max_liquid", 1000);
        } 
        set("liquid", ([
                "type": "alcohol",
                "name": "太行美酒",
                "remaining": 1000,
                "drunk_apply": 1000,
        ]) );
}

