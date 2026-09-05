// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "水师驻地");
	set("long", @LONG
这里是大宋水师的驻地，战船整齐的排列着。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"shuishi",
		"east" : __DIR__"qiantang2",
		//"southwest" : __DIR__"qiantang",//吏部
		"north" : __DIR__"chuanchang",//礼部
	]));
	set("objects", ([
          "/d/hangzhou/npc/songbing_y" : 2,
		__DIR__"npc/shuidu":1,
        ])); 
	set("at_hangzhou",1);
	setup();
}