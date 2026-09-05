// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "都水监");
	set("long", @LONG
这里是都水监的衙门。
LONG
	);
       // set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"heningdong",
		//"north" : __DIR__"streetn4",
		//"enter" : __DIR__"bingbucourt",//吏部
		"south" : __DIR__"qiantang5",//礼部
	]));
	set("objects", ([
          __DIR__"npc/dushui_npc1" : 1,
        ])); 
	set("at_hangzhou",1);
	setup();
}