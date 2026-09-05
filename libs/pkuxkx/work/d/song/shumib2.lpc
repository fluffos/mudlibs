// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include "/d/song/transfer.h"
#include <ansi.h>
void create()
{
	set("short", "值房");
	set("long", @LONG
这里是枢密院长官的值房。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
//		"north" : __DIR__"shumia2",
		"south" : __DIR__"shumib",
//		"east" : __DIR__"shumi2",//吏部
		//"out" : __DIR__"shumi",//礼部
	]));
	set("objects", ([
          __DIR__"npc/qianshumi" : 1,
		__DIR__"npc/tongqianshumi" : 1,
        ]));
	set("pro_trans","武");
	set("pin_range",({4,5,6,7}));
	setup();
}