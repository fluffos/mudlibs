// honghua.c 红花 by hubo

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"大红花"NOR, ({"hong hua", "hua"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一朵鲜艳的大红花\n");
                set("unit", "朵");
                set("value", 1);
                set("no_pawn",1);
                set("no_sell",1);
        }
}
