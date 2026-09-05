// File         : wine
// Created By   : iszt@pkuxkx, 2007-05-03

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("酒碗" NOR, ({"jiu wan", "jiuwan", "jiu", "wan", "wine", }));
        set_weight(160);
        set("unit", "个");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set_name("酒" NOR, ({"wine", "jiu", "wan", }));
                set("unit", "碗");
                set("long", "一个青瓷酒碗。\n");
                set("value", 200);
                set("max_liquid", 5);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "酒",
                "remaining": 5,
                "drunk_apply": 40,
        ]));
}
