// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
string look_notice();
void create()
{
	set("short", "三司使大门");
	set("long", @LONG
这里是三司使衙门大门，内里就是大宋的财政中枢。几个禁军军士在巡弋着，
门前贴着一张告示(notice)。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : __DIR__"streetn6",
		"enter" : __DIR__"sansishicourt",
		//"west" : __DIR__"streetn3",//吏部
		//"east" : __DIR__"libu2",//礼部
	]));
	set("item_desc", ([
		"notice" : (:look_notice:),
	]));
	set("objects", ([
    "/d/hangzhou/npc/songbing_y" : 2,
        ]));  
	setup();
}

string look_notice()
{
	if (DASONG_D->query("balance_detail"))
	return DASONG_D->query("balance_detail")+"\n";
	else
	return "最新一期的财报还没有出炉。\n";
}