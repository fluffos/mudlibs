// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "东演武场");
	set("long", @LONG
这里是武学院的演武场，经常有学生在这里比武。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"yw_1",
		"west" : __DIR__"wuxue2",
		//"out" : __DIR__"wuxue",//吏部
		//"north" : __DIR__"wuxue3",//礼部
	]));
/*	set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
*/
	set("at_yw",1);
	setup();
}