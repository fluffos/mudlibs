// Room: /d/heifeng/maowu.c

inherit ROOM;

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间宽敞的茅草屋，屋子里的陈设非常简陋，中间一张
桌子，几把椅子(table)都是一尘不染，看样子屋子里毫无生气，
不像有人住的样子，但四处却都打扫的干干净净。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shanya",
]));
	set("objects", ([
		__DIR__"npc/wolfdog" : 3,
	]));

	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(!arg || (arg != "table" && arg != "椅子"))
		return 0;

	message_vision("$N把椅子推到了一边",me);

	if(undefinedp(query("exits/down")))
	{
		set("exits/down",__DIR__"midao1");
		tell_room(__FILE__,"露出了一个向下的出口。\n");
	}
	else
		tell_room(__FILE__,"。\n");

	call_out("do_close",8);
	return 1;
}

void do_close()
{
	if(!undefinedp(query("exits/down")))
	{
		tell_room(__FILE__,"有人从下面将向下的出口关上。\n");
		delete("exits/down");
	}
}
