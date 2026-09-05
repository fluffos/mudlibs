//Created by whuan@pkuxkx
//投名状任务之红货
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"红货"NOR, ({ "hong huo","prize" }));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "一包从来往镖队那里抢来的红货。\n");
                set("value", 100000);
                set("no_put", 1);
                set("no_steal", 1);
                set("no_sell", 1);
        }
}