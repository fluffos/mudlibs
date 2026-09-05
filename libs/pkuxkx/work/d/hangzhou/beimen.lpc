// Room: /hangzhou/beimen.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
        set("short", "余杭门");
        set("long", @LONG
这里临安是的北城门，城墙上贴着几张官府告示，几个官兵昼夜在此把守，冷
酷的看着来往的每一个人。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "south" : __DIR__"beidajie2",   
                "north" : __DIR__"guandaon1",
]));
     
    set("objects", ([
		__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing" : 2,
        ]));      
   set("dirs_to_song",(["east":({"bingzhan","东","城北兵站"}),"west":({"junqi_zuofang","西","城北作坊"}),]));
	set("is_GaTe",1);	
	setup();
	make_entrance();
}
