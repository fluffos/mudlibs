// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", "后堂");
	set("long", @LONG
这里是学士院的后堂，学士院长官办公的地方。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"out" : "/d/hangzhou/palace/yudao1",
		"out" : __DIR__"xueshiyuan",
		//"enter" : __DIR__"bingbucourt",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          "/d/song/npc/hl_npc1" : 1,
		"/d/song/npc/hl_npc2" : 1,
		"/d/hangzhou/obj/books/book_leadership_2":1,
		"/d/hangzhou/obj/books/book_leadership_3":1,
        ])); 
	set("WAICHAO",1);
	setup();
}