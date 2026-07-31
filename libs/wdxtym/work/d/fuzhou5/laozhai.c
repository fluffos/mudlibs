// room: laozhai.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);

void create()
{
	set("short", "向阳老宅");
	set("long", @LONG
这里是福威镖局总镖头林震南在福建的旧居。室内的家具横七竖
八地倒在地上。房间的一角结着一张蜘蛛网，屋里到处是尘土，显然
是已经很久没有人住了。房间的尽头有一扇门(men)， 但已被坍塌的
砖瓦挡住了。
LONG );

	set("exits", ([
		"south" : __DIR__"xiangyang",
	]));
	set("objects", ([
		"/d/songshan/npc/bo": 1,
	]));

	set("item_desc", ([
		"men" : "这扇门已被挡住无法通行，除非你打破(break)它。\n",
	]));
	setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break(string arg)
{
	int n;

	n = this_player()->query("neili");
	if (! arg || arg != "men")
	{
		write("不要随便打碎别人的东西！\n");
		return 1;
	}

	message_vision("$N走到后门前，拜出骑马蹲裆式，深吸一口"
		       "气，双掌同时拍出。\n", this_player());
	if (n >= 500)
	{
		message_vision("$N只听一声轰响，$N把门震开了！\n",
			       this_player());
		set("exits/north", __DIR__"houyuan");
		this_player()->set("neili",n - 200);
		remove_call_out("close");
		call_out("close", 5);
	} else
	{
		message_vision("$N大吼一声“开！”，结果什么也没发生。看"
			       "来$N的内力不够强。\n", this_player());
		this_player()->set("neili", 0);
	}
	return 1;
}

void close()
{
	message("vision","门上的砖头瓦块稀里哗拉坍塌下来，又挡"
		"住了后门。\n", this_object());
	delete("exits/north");
}
