// Room: /d/city/jiangbei1.c

#include <ansi.h>

#define SHIP_TO __DIR__"jiangnan1"
#define BOAT __DIR__"boat1"

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();

void create()
{
	set("short", "长江北岸");
	set("long", @LONG
面前是一条波涛翻滚的大江(river)。 浊流滚滚，万舟竞发。两岸渡船来
来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸边，支一块木板，板上摆
满了活蹦乱跳的鲤鱼。不远处是一个摆渡，不少过江客都在这里等待渡船。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiangbei",
	]));

	set("item_desc", ([
		"river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
	]));

	set("outdoors", "扬州");
	set("coor/x",90);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_yell", "yell");
	add_action("du_jiang", "dujiang");
}

int do_yell(string arg)
{
	object room, me;
	me = this_player();

	if (arg == "boat") arg = "船家";
	if (arg != "船家") arg = "哇";
	if (me->query("age") < 16  )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", me);
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", me);
	if (arg == "船家")
	{
		if (room = load_object(BOAT))
		if (!room->query("start"))
			room->arrive("jiangbei1");
		else if (query("exits/enter"))
			message_vision("岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n", me);
		else message_vision("江面上远远传来一声：“等等啊，这就来了～～～”\n", me);
	} else message_vision("江面上远远传来一阵回声：“" + arg + "～～～”\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir =="enter") {
		if (me->query("can_ride")) return 0;
		if (me->query_temp("ride_horse"))
			return notify_fail("骑马上船，你不怕船翻了？\n");
		me->set_temp("side", "jiangbei1");
	}

	return ::valid_leave(me, dir);
}

int du_jiang()
{
	object me = this_player();

	if (!living(me)) return 0;

	write("这里的水太深太急，你渡不过去。\n");
	return 1;

}
