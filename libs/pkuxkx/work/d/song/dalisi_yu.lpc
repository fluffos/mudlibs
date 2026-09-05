// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "监狱");
	set("long", @LONG
这里是大理寺的监狱，关押的都是重犯。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"south" : __DIR__"streets1",
		//"out" :"/d/hangzhou/fengbo",
		"north" : __DIR__"dalisi",//吏部
		//"south" : __DIR__"dalisi_yu",//礼部
	]));
	set("objects", ([
          "/d/hangzhou/npc/yayi" : 2,
        ])); 
	set("at_hangzhou",1);
	setup();
}