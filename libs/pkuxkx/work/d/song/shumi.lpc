// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
string look_notice();
void create()
{
	set("short", "枢密院大门");
	set("long", @LONG
这里就是大宋军事的中枢——枢密院了。几个禁军军士在巡弋着，门前贴着一
张告示(notice)。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"south" : __DIR__"streetn4",//吏部
		"enter" : __DIR__"shumicourt",//礼部
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
	if (DASONG_D->query("military_detail"))
	return DASONG_D->query("military_detail")+"\n";
	else
	return "最新一期的军报正在制作当中。\n";
}