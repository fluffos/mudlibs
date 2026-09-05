// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "国子监内堂");
	set("long", @LONG
这里是国子监的内堂。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"south" : __DIR__"streets1"
		"out" : __DIR__"guozijian",//吏部
		"north" : __DIR__"kaochang/qianyuan",//礼部
	]));
	set("objects", ([
          __DIR__"npc/gzj_npc1" : 1,
		__DIR__"npc/gzj_npc2" : 1,
		__DIR__"npc/gzj_npc3" : 1,
		__DIR__"npc/gzj_npc4" : 1,
        ])); 
	set("at_hangzhou",1);
	setup();
}