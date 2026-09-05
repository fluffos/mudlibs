// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "武学院官厅");
	set("long", @LONG
这里是武学院长官的官厅。
LONG
	);
    //    set("outdoors", "hangzhou");

	set("exits", ([
		"south" : __DIR__"wuxue2",//礼部
		"north" : __DIR__"classroom",
		"west" : __DIR__"bedroom",
		"east" : __DIR__"kitchen",
	]));
/*	set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
*/
	set("at_hangzhou",1);
	setup();
}