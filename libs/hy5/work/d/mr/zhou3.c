// /u/beyond/mr/zhou3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "小舟");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公手持长竹
篙，正在船尾吃力地撑着船。
LONG
	);
	set("exits",([
		"out"  :  __DIR__"anbian2",
	]));
        set("no_fight",1);

	setup();
}
void init()
{
//  mapping fam;
    object me;
       me=this_player();
//     room=this_object();
       message_vision(
               YEL "\n船夫把小舟靠在岸边，快下船吧。\n\n"NOR,me);
}
