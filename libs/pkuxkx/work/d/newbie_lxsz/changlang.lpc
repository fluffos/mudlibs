// D:\xkx\d\liuxiu-shanzhuang\changlang.c长廊
// labaz  2012/10/21
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void init();
void close_gate();
int do_open(string);
int do_close(string);

void create()
{
    set("short", "长廊");
    set("long", 
"你到了柳秀山庄的长廊。长廊南头是大门"+YEL"(gate)"NOR+",大门的对面是一面
“龙凤呈祥”的青石影壁，绕过影壁便是长长的回廊。回廊两侧柳树和竹子
交映，廊檐雕着儒释道三家的古老故事，画风是粗线条的大写意。长廊的
北头似乎有淡淡的岩桂花香飘了过来。面对着那气势恢宏的大门，你不禁想
仔细的看看。(l gate)\n"
	);

    set("indoors","liuxiu-shanzhuang");

    set("exits", ([
        "north" : __DIR__"yangui-huayuan",
        ])
     );

    set("item_desc", ([
        "gate":"一扇宏伟的"+HIR"红漆大门"NOR+",出了这扇门就能离开山庄了，你可以打开大门。"+HBBLU+WHT"(open gate)\n"NOR,
        ]));

	 
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
		]));

    setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("show_quest", "quest");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"shanzhuang-damen")) )
		room = load_object(__DIR__"shanzhuang-damen");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision", "丫鬟上前把大门关了起来。\n", this_object());
		room->delete("exits/north");
		message("vision", "乒地一声，里面的丫鬟把大门关上了。\n", room);
	}
}

// int do_close(string arg)
// {
	// if (!query("exits/south"))
		// return notify_fail("大门已经是关着的了。\n");

	// if (!arg || (arg != "gate" && arg != "south"))
		// return notify_fail("你要关什么？\n");

	// message_vision("$N朝家丫鬟点了点头。\n", this_player());

	// remove_call_out("close_gate");
	// call_out("close_gate", 2);

	// return 1;
// }

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "gate"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"shanzhuang-damen")) )
		room = load_object(__DIR__"shanzhuang-damen");
	if(objectp(room))
	{
		set("exits/south", __DIR__"shanzhuang-damen");
		message_vision("$N使劲把大门打了开来。\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "吱地一声，里面有人把大门打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 15);
	}

	return 1;
}

void attempt_apprentice(object ob)
{
        command("shake");
        command("say 我只是个小婢女，不能收徒。");
        return;
}

