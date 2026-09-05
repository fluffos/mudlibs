// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "juedi.h"
void create()
{
	set("short", WHT"钱塘江边"NOR);
	set("long", @LONG
这里是钱塘江畔，江水流向内陆，变得宁静起来。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"north" : __DIR__"dushui",
		"east" : __DIR__"qiantang3",
		//"northeast" : __DIR__"qiantang",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	/*set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
	*/
	set("at_hangzhou",1);
	set("juedi_dir","east");
	set("juedi_connect",__DIR__"qiantang3");
	setup();
}