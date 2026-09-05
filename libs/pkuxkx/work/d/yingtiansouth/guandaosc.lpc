// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", CYN"青石官道"NOR);
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
北面就是建康府了，西面经由清水塘通往无想山。
LONG );
	set("outdoors", "yingtianfu");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"guandaosd1",
        "east" : __DIR__"guandaosd2",
		"northwest" : __DIR__"guandaosb",
		"westup" : __DIR__"wuxiange2",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
	if (dir=="westup"&&!userp(me))
	return 0;
	return ::valid_leave(me,dir);
}