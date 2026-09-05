// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是大理寺内审案的大厅。
LONG
	);
      //  set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"enter" : __DIR__"dalisi_2",
		//"out" :"/d/hangzhou/fengbo",
		"south" : __DIR__"dalisi",//吏部
		"north" : __DIR__"dalisi3",//礼部
	]));
	set("objects", ([
          "/d/hangzhou/npc/yayi" : 2,
		__DIR__"npc/dls_npc1":1,
		__DIR__"npc/dls_npc2":1,
        ])); 
	set("at_hangzhou",1);
	setup();
}