// Room: /city2/aobai4.c
#include <ansi.h>
inherit ROOM;
void close_gate();
int do_open(string arg);
int do_close(string arg);
void create()
{
	set("short", HIY"鳌府后院"NOR);
	set("long",
HIC"这里是鳌府后院，中心是一个大花园。西边一条长廊走道直
通往鳌拜的卧房，有几个官兵把守。北边是书房。南边是鳌拜私
设的牢房,牢门(men)是锁着的。\n"NOR
	);
	set("item_desc", ([
	"men":"这是一扇很结实的铁门。\n",
	]));
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"aobai6",
		"east" : __DIR__"aobai3",
		"north" : __DIR__"aobai7",
	]));
	set("objects", ([
		__DIR__"npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));
	setup();
}
void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}
void close_gate()
{
	delete("exits/south");
	message("vision","只听乒地一声，暗门自动关了起来。\n",this_object());
}
int do_open(string arg)
{
	object room;
        object ob;
	if (query("exits/south"))
		return notify_fail("暗门已经是开着了。\n");
	if (!arg || (arg != "men" && arg != "south"))
		return notify_fail("你要开什么？\n");
	if (!(ob = present("lfkey", this_player())))
		return notify_fail("你不会撬锁。\n");
	message_vision(
	"$N用一把钥匙打开了秘门，可是钥匙却断了.\n", this_player());
	destruct(ob);
	set("exits/south", __DIR__"aobai8");
	remove_call_out("close_gate");
	call_out("close_gate", 60);
	return 1;
}
int valid_leave(object me, string dir)
{
	if (objectp(present("guan jia", environment(me))) &&
                     (dir == "south")&& living(present("guan jia", environment(me))))
		return notify_fail("女管家挡住了你。\n");
	if (objectp(present("guan jia", environment(me))) && me->query("class") != "officer" &&
                     (dir == "north")&& living(present("guan jia", environment(me))))
		return notify_fail("女管家挡住了你。\n");
	return ::valid_leave(me, dir);
}



