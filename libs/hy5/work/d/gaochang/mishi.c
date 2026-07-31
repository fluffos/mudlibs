// Room: /d/gaochang/shulin13.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "高昌后殿");
	set("long", @LONG
大厅里有几具白骨骷髅 只见大半宫室已然毁圯，殿堂中堆满了黄沙;
往北边似乎还有路，在阴暗处站有一人正好挡住了去路。

LONG   
	);

	set("exits", ([
		"south" : __DIR__"zoulang2",
		"north" : __DIR__"mishi2"
	]));

	set("outdoors", "gaochang");
	setup();
}

void init()
{

	object ob, room;
	ob = this_player();
	room = this_object();
	if (!ob) return;
	if (!userp(ob)) return;

	if (!ob) return;
	if (!userp(ob)) return;

	if (ob->query("id") == "ghost" || !living(ob)) return;
    else if	( present("shou juan", ob) || present("bai shoujuan", ob)){
	message_vision(HIW"\n突然之间，前面一个阴森森的声音说道：
「果然是有胆之士!怎么你有高昌迷宫的地图,难道是天意？\n
高昌迷宫真的有敌国的财富吗？哈。。哈哈。。」 \n
笑声中透着无限的凄凉和悲状。\n\n" NOR, ob);
	}
    else {
   	message_vision(HIW"\n突然之间，前面一个阴森森的声音说道：
擅闯高昌迷宫者死! 只见一点光向你袭来，你想躲也躲不开了.
原来是一根毒针插入你的身体。\n\n" NOR, ob);
	this_player()->die();
	}

}