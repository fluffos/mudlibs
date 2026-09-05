// Room: /shenlongjiao/xiangtang.c
// kiden 06/08/25
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", HIY"香堂"NOR);
        set("long", @LONG
这里就是香堂，空空荡荡的厅内就正北方向摆了一个香案。
香案上放著五只黄金盘子，每只盘子中都盛著一条小蛇，共分青、黄、赤、白、黑五色。
五条小蛇昂起了头，舌头一伸一伸，身子却盘著一动。
LONG
        );
//        set("outdoors", "shenlongdao");
        set("exits", ([
                "south" : __DIR__"qianlongtang",                      
        ]));

   set("objects", ([
//         __DIR__"npc/dizi":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

