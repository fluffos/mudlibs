// Room: /hangzhou/shanlu3.c
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
                "northeast" : __DIR__"shanlu2",
                "west" : __DIR__"road1",    
]));
          
   set("dirs_to_song",(["southeast":({"tianwuwei","东南","天武卫驻地"}),]));
   setup();
   make_entrance();
}
