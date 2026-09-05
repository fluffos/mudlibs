// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", HIR"殿前都都指挥使司"NOR);
	set("long", @LONG
这里是拱卫皇城的殿前都都指挥使司。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"out" : "/d/hangzhou/lizhengmen",
		//"north" : __DIR__"dianqiansi2",
		//"enter" : __DIR__"bingbucour",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
        //  __DIR__"npc/songbing_d" : 2,
		//__DIR__"npc/songbing_d2" : 2,
		__DIR__"npc/dianqian_npc1" : 1,
		__DIR__"npc/dianqian_npc2" : 1,
		//__DIR__"npc/_npc3" : 1,
        ])); 
	set("at_hangzhou",1);
	setup();
}