// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "兵部尚书值房");
	set("long", @LONG
这里是兵部尚书的值房。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","bingbu");
	set("exits", ([
		"south" : __DIR__+query("yamen")+"court",
	
	]));
	set("objects", ([
          __DIR__"npc/bing_shangshu" : 1,
        ])); 

	setup();
}