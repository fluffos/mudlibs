// Room: /hangzhou/td_huayuan4.c
// hubo 2008/4/19

inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/hangzhou/huayuan.h"
void create()
{
        set("short", "花园");
        set("long", @LONG
杭州提督府的花园，种着五颜六色的鲜花，香味扑鼻，另人陶醉。你一走进来，
感觉失去了方向。心里有种不祥的预感。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "east" : __DIR__"td_huayuan"+(random(8)+2),
                "west" : __DIR__"td_huayuan"+(random(8)+2),
                "south" : __DIR__"td_huayuan5",
                "north" : __DIR__"td_huayuan"+(random(8)+2),     
]));
  	set("no_newbie_task",1);   
   setup();
}

