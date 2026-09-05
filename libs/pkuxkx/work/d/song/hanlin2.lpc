// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "后堂");
	set("long", @LONG
这里是翰林院的后堂，翰林院长官办公的地方。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"out" : "/d/hangzhou/palace/yudao1",
		"south" : __DIR__"hanlin",
		//"enter" : __DIR__"bingbucourt",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/hl_npc1" : 1,
		__DIR__"npc/hl_npc2" : 1,
        ])); 
	set("at_hangzhouplace",1);
	setup();
}