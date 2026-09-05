// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "步军都指挥使司");
	set("long", @LONG
这里是三衙中的步军都指挥使司的大门，几个步军都的士兵正打量着过往的
行人。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"south" : __DIR__"streetn5",
		"enter" : __DIR__"bujunducourt",
		//"north" : __DIR__"streetn7",//吏部
		"east" : __DIR__"streetn7",//礼部
	]));
	set("objects", ([
    __DIR__"npc/songbing_b" : 2,
        ]));  
	setup();
}