// shantong.c 后山山洞
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后山山洞");
        set("long", @LONG
这里是全真教开山祖师王重阳真人静修的山洞。洞不大，但
里面布置得很雅致，象大户人家的客厅一样。洞壁上挂着一副画
(hua)，桌椅茶几都很精致。
LONG
        );
        set("exits", ([
                "out" : __DIR__"xiaolu12",
        ]));
        set("item_desc", ([
        "hua": "画中是一个中年道士的背影，看不出什么相貌，画中人一手指天，画角题
着‘"+MAG"活死人像"NOR+"’几个大字。\n"
        ]) );

        set("objects", ([
                __DIR__"npc/wang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

