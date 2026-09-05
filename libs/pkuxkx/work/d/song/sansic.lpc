// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "/d/song/sansi_balance.h"
void create()
{
	set("short", "值房");
	set("long", @LONG
这里是三司使佐官的值房。
LONG
	);
       //set("outdoors", "hangzhou");

	set("exits", ([
		"south" : __DIR__"sansishi2",
		//"south" : __DIR__"sansinei",
		//"out" : __DIR__"sansishi",
		//"east" : __DIR__"sansib",//吏部
		//"north" : __DIR__"sansic",//礼部
	]));
	set("objects", ([
    __DIR__"npc/sansi3" : 1,
        ])); 
	setup();
}