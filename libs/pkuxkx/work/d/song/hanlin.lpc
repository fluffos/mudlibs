// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是翰林院的大厅，几个高品级的内侍正在忙碌着。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		"west" : __DIR__"shuhua",
		"out" : "/d/hangzhou/palace/yudao1",
		"east" : __DIR__"tianwen",
		//"enter" : __DIR__"bingbucourt",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/hanlin" : 1,
	//	__DIR__"npc/hl_npc3" : 1,
        ])); 
	set("at_hangzhouplace",1);
	setup();
}