// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "国子监大门");
	set("long", @LONG
这里是国子监的大门。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"south" : __DIR__"streets1"
		"enter" : __DIR__"guozijian2",//吏部
		"southwest" : "/d/hangzhou/fengbo",//礼部
	]));
	/*set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
	*/
	set("at_hangzhou",1);
	setup();
}