// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "礼部尚书值房");
	set("long", @LONG
这里是礼部尚书的值房。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","libu2");
	set("exits", ([
		"west" : __DIR__+query("yamen")+"court",
	
	]));
	set("objects", ([
          __DIR__"npc/li2_shangshu" : 1,
        ])); 
	setup();
}
