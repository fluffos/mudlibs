// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
string look_notice();
void create()
{
	set("short", "尚书省衙门大门");
	set("long", @LONG
这里是尚书省衙门大门，内里就是大宋的中枢所在——政事堂。几个禁军军士
在巡弋着，门前贴着一张告示(notice)。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"south" : __DIR__"streetn2",
		"enter" : __DIR__"shangshucourt",
		//"west" : __DIR__"streetn3",//吏部
		//"east" : __DIR__"libu2",//礼部
	]));
	set("objects", ([
    "/d/hangzhou/npc/songbing_y" : 2,
        ])); 
	set("item_desc", ([
		"notice" : (:look_notice:),
	]));
	setup();
}

string look_notice()
{
	if (DASONG_D->query("gov_detail"))
	return DASONG_D->query("gov_detail")+"\n";
	else
	return "最近一期的政务公告正在制作当中。\n";
}