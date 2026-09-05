// Room: /shenlongjiao/dongxiangfang.c
// kiden 06/08/25
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", "东厢房");
        set("long", @LONG
这是议事大厅东侧的一间厢房。虽说是厢房，却也十分宽敞，陈设雅洁，桌上架上摆满了金玉古玩，壁上悬著字画。
LONG
        );
//        set("outdoors", "shenlongdao");
        set("exits", ([
                "west" : __DIR__"qianlongtang",                        
        ]));

     set("sleep_room", 1);
   set("objects", ([
//         __DIR__"npc/dizi":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

