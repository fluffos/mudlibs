// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "中书省衙门大门");
	set("long", @LONG
这里是中书省衙门大门，内里是中书省各属官办公的官署。几个衙役无精打
采的站着岗。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"south" : __DIR__"streetn1",
		"enter" : __DIR__"zhongshucourt",
		//"west" : __DIR__"streetn3",//吏部
		//"east" : __DIR__"libu2",//礼部
	]));
	set("objects", ([
    "/d/hangzhou/npc/yayi" : 2,
        ])); 
	setup();
}