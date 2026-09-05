// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "/d/hangzhou/to_song.h"
#include <ansi.h>
void create()
{
	set("short", WHT"御道"NOR);
	set("long", @LONG
这里是一段白石铺就的御道，南面是垂拱殿。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"northeast" : __DIR__"yuchu",
		"southeast" : __DIR__"yujiu",
		"south" : __DIR__"qinrui",
		"northwest" : __DIR__"yuyao",
		"southwest" : __DIR__"zaozuo",
		"north" : __DIR__"xueshiyuan",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/hangzhou/npc/songbing_y" : 1,
        ])); 
	set("song_palace","south");
	set("dirs_to_song",(["enter":({"hanlin","里","翰林院"}),]));
   setup();
   make_entrance();
}