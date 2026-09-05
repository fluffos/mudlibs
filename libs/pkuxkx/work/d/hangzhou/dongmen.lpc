// Room: /hangzhou/dongmen.c
// hubo 2008/4/19
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
        set("short", "东青门");
        set("long", @LONG
这里是临安城的东城门，城墙上贴着几张官府告示，几个官兵昼夜在此把守，
冷酷的看着来往的每一个人。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "west" : __DIR__"dongdajie2",       
                "east" : __DIR__"road1",  
                //"north" : __DIR__"datiepu"     
]));
     
     set("objects", ([
		__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing" : 2,
        ]));     
   set("dirs_to_song",(["north":({"bujun","北","步军都驻地"}),]));
   set("is_GaTe",1);
	setup();
	make_entrance();
}
