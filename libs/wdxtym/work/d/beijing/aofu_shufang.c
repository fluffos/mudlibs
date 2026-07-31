#include <room.h>

inherit ROOM;

void create()
{
	set("short", "鳌拜书房");
	set("long", @LONG
这里是鳌拜书房，却没有一本书。整个屋子异常的空荡，只是有一个
虎皮太师椅(yi)看起来有些不太正常。
LONG );

	set("exits", ([
		"east" : __DIR__"aofu_zoulang3",
	]));

	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	object me;

	if (arg != "yi")
		return notify_fail("什么？\n");

	me = this_player();
	if (query("exits/down"))
		return notify_fail("椅子已经搬开了。\n");

	message_vision("$N奋力将太师椅推到一边，只见下面露出"
		       "了一个黑黝黝的出口。\n", me);
	set("exits/down", __DIR__"aofu_mishi");
	remove_call_out("close");
	call_out("close", 10);
	return 1;
}

void close()
{
	message("vision", "一阵声响过后，太师椅缓缓的将密道出口挡住了。\n",
		this_object());
	delete("exits/down");
}
