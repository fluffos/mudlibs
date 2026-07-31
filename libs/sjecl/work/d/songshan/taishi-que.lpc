// ROOM : taishi-que.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"太室阙"NOR);
	set("long",@LONG
在你眼前赫然耸立着一座太室阙，这是嵩山派的象征性大门，由整
齐的青石块垒砌而成。看上去年代已经久远，上面长满了青苔。
LONG
	);
	set("exits", ([
            "southdown" : __DIR__"shanlu5",
            "north" : __DIR__"kuangdi",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/wan" : 1,
        ]));        
	set("outdoors", "嵩山");
	set("coor/x",40);
  set("coor/y",250);
   set("coor/z",110);
   setup();
}	