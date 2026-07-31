// File(/data/room/luoyuna/zoudao.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "走道");
	set("long", "这是连接正厅和大门的一条走道，两旁都是木制墙板，前面就是
迎客厅。
");

	set("exits", ([
		"north"  : __DIR__"yingke",
		"south"  : __DIR__"qianting",
	]));

	set("gate", "close");

        set("objects", ([
    	    "/d/room/roomnpc/yahuan" : 1,
        ]));

	set("no_sleep_room", 1);
	setup();

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}

void init()
{
	add_action("do_push", "push");
	add_action("do_close", "close");
}

int do_push(string arg)
{
	object me;
	object room;

	if (query("gate") == "open")
		return notify_fail("大门开着呢，你还推什么？\n");

	me = this_player();
	message_vision("$N用力推了推大门，就听大门“吱呀呀”的被人推开了。\n", me);
    
	room = get_object(__DIR__"qianting");
	message("vision", "大门“吱呀呀”的被人推开了。\n", room);
	set("gate", "open");
	set("exits/south", __DIR__"qianting");
	room->set("exits/north", __FILE__);
	room->set("gate", "open");
	remove_call_out("do_close");
	call_out("do_close", 10, 0, 1);
	return 1;
}

int do_close(string arg, int n)
{
	object me;
	object room;

	if (query("gate") == "close")
		return notify_fail("大门关着呢，你还再关一遍？\n");

	if (! n)
	{
		me = this_player();
		message("vision", me->name() + "走上前去，用力合上大门。\n",
			this_object());
	} else
	{
		message("vision", "大门“吱呀呀”的被人关上了。\n",
			this_object());
	}

	room = get_object(__DIR__"qianting");
	message("vision", "大门“吱呀呀”的被人关上了。\n", room);
	set("gate", "close");
	delete("exits/south");
	room->set("gate", "close");
	room->delete("exits/north");
	return 1;
}

