// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "武学院广场");
	set("long", @LONG
这里是武学院的广场，北面是武学院长官的官厅，东西两面是两个大的演武
场。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : __DIR__"yw_1",
		"east" : __DIR__"yw_2",
		"out" : __DIR__"wuxue",//吏部
		"north" : __DIR__"wuxue3",//礼部
	]));
/*	set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
*/
	set("at_hangzhou",1);
	setup();
}