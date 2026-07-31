// /u/beyond/mr/duchuan3.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公
手持长竹篙，正在船尾吃力地撑着船。
LONG
	);
	set("exits",([
		"out"  :  __DIR__"xiaodao",
	]));
        set("no_fight",1);

	setup();
}
void init()
{
// mapping fam;
       object me,room;
       me=this_player();
       room=this_object();
       message_vision(
               YEL "\n终于到了小岛边，船夫把小舟靠在岸边，快下船吧。\n\n"NOR,me);
}
