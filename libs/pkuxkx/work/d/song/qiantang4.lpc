// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", WHT"钱塘江入海口"NOR);
	set("long", @LONG
这里是钱塘江的入海口。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"shuishi",
		"west" : __DIR__"qiantang2",
		//"southwest" : __DIR__"qiantang",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	/*set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
	*/
	set("at_hangzhou",1);
	setup();
}