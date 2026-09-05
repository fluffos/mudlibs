// Room: /hangzhou/nanmen.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "/d/hangzhou/to_song.h"
void create()
{
        set("short", "嘉会门");
        set("long", @LONG
这里是临安府的南城门，城墙上贴着几张官府告示，几个官兵昼夜在此把守，
冷酷的看着来往的每一个人。东南面是著名的钱塘江。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "north" : __DIR__"lizhengmen",       
                "southup" : __DIR__"shanlu4",
				"west" : __DIR__"tidufu/tidufu",
]));
     
     set("objects", ([
		__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing" : 2,
        ])); 
	set("dirs_to_song",(["southeast":({"qiantang","东南","龙卫驻地，水师驻地"}),"east":({"huangzhuang","东","临安府治下军屯"}),]));
	set("is_GaTe",1);
   setup();
   make_entrance();
}
