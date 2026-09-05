// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIB"湖泊"NOR);
        set("long", @LONG
这里是一处高原湖泊，湖水碧绿得就像一颗宝石一般。湖边却是一阵寒意
逼人。路尽头松林下一位壮汉正在长啸练功。
LONG
        );
        set("exits", ([
            "northdown" : __DIR__"xxh1",
            "south" : __DIR__"xxgate",
            "northup" : __DIR__"xxroad4",
]));
        set("objects", ([
                "/kungfu/class/xingxiu/shihou" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));
        set("couldfish",1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

