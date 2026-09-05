// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "内厅");
	set("long", @LONG
这里是大理寺主官办公的内厅。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"south" : __DIR__"streets1",
		//"out" :"/d/hangzhou/fengbo",
		"south" : __DIR__"dalisi2",//吏部
		//"north" : __DIR__"dalisi3",//礼部
	]));
	set("objects", ([
         // "/d/hangzhou/npc/yayi" : 2,
		__DIR__"npc/dls_npc3":1,
		__DIR__"npc/dls_npc4":1,
        ])); 
	set("at_hangzhou",1);
	setup();
}