// ROOM: mushi.c
// Created by Numa 19990910

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"墓中圹室"NOR);
	set("long",@LONG
这里就是墓中圹室。圹室中壁间案头尽是古物珍玩、名画法书，没
一件不是价值连城的精品。墙头有一盏翡翠灯，只见那些明珠美玉、翡
翠玛瑙之属在灯光下发出淡淡光芒。墙上挂着一副青年少妇的画像，旁
边有一张毡帷，后面有一具玉棺。
LONG);
	set("exits", ([
        "up" : __DIR__"mudao4",
	]));
	set("no_clean_up",0);
	setup();
}

void init()
{
      if (!this_player()->query_temp("thd/dojob") && userp(this_player()))
	{
		tell_object(this_player(),"突然，冲出来一个守墓弟子，把你赶了出去。\n");
        this_player()->move(__DIR__"tomb");
	}
}
