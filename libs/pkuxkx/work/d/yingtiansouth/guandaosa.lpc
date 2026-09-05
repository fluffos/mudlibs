// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;
#include <ansi.h>
string look_tian();
void create()
{
	set("short", CYN"青石官道"NOR);
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
北面就是建康府了。西面有一大片田垄(tian)。
LONG );
	set("outdoors", "yingtianfu");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"     : __DIR__"guandaosb",
		"north" : __DIR__"zhengyang",
	]));
	set("item_desc", ([
		"tian" : (:look_tian:),
	]));
	setup();
}

string look_tian()
{
	return "那边是一片皇家的田庄。\n";
}
