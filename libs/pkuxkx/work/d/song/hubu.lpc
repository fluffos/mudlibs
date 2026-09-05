// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "户部大门");
	set("long", @LONG
这里是户部衙门的大门，有几个军士在站岗。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"north" : __DIR__"streetn5",
		//"north" : "/d/hangzhou/heningnan",
		"enter" : __DIR__"hubucourt",//吏部
		"west" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 

	setup();
}