// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "吏部侍郎值房");
	set("long", @LONG
这里是吏部侍郎的值房。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","libu");
	set("exits", ([
		"southeast" : __DIR__+query("yamen")+"court",
	
	]));
	set("objects", ([
          __DIR__"npc/li_shilang" : 1,
        ])); 
	setup();
}