// Room: /hangzhou/shanlu2.c
// hubo 2008/4/19

inherit ROOM;
#include "/d/hangzhou/to_song.h"
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在一条山路上，不时有些农民和猎户从你身边经过，他们唱着山歌，逍遥
快活，这条路向西通往临安府。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "southwest" : __DIR__"shanlu3",
                "east" : __DIR__"shanlu1",    
]));
          
   setup();
   set("dirs_to_song",(["north":({"xing_prison","北","刑部大牢"}),]));
   setup();
   make_entrance();
}
