// Room: /u/poq/sdxl/dongkou.c 洞口
// by poq@jyqx 97/7
// alter dubei
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "洞口"NOR);
    set("long", @LONG
四下长草齐膝，一片寂静。你面前是一个大山洞。东南方是幽暗的
深谷。
LONG
    );

    set("exits", ([
        "southeast" : __DIR__"xiaolu3",
        "enter" : __DIR__"shandong",
    ]));

    set("outdoors", "xiangyang");

    set("item_desc", ([
        "dong" : "山洞里面黑黝黝的，你看不到任何东西。\n",
	]));

    setup();
   replace_program(ROOM);
}

 
