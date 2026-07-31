// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"风味小吃店"NOR);
        set("long", @LONG
这是一家有名的风味小吃店，专卖各种地方名小吃，虽然就开在云仙楼旁
边，可是生意一样很兴隆，这里到处坐满了人，有些客人就站在一旁端个碗吃
的津津有味。
LONG
);
        set("exits", ([ 
            "west" : __DIR__"xijie1",
            "north" : __DIR__"beijie2",
            "east" : __DIR__"dalics",
	]));

        set("objects", ([
                        __DIR__"npc/zhangqian" : 1 
        ]));
        set("coor/x",-320);
  set("coor/y",-390);
   set("coor/z",-20);
   setup();
}
