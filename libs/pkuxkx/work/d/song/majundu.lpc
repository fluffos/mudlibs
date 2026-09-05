// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "马军都指挥使司");
	set("long", @LONG
这里是三衙中的马军都指挥使司的大门，几个马军都的士兵正打量着过往的
行人。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"east" : __DIR__"streetn6",
		"enter" : __DIR__"majunducourt",
		//"north" : __DIR__"streetn7",//吏部
		//"west" : __DIR__"majundu",//礼部
	]));
	set("objects", ([
    __DIR__"npc/songbing_m" : 2,
        ]));  
	setup();
}