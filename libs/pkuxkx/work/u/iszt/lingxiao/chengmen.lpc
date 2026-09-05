// File		: chengmen.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", BCYN""HIW"凌霄城门"NOR);
	set("long", @LONG
好一座构制雄伟的城门！青砖筑的城楼威严的注视着面前的深谷，城门之上
连接着数丈宽的吊桥。两旁各有三名雪山派弟子掌握着升降吊桥的机关，一有人
呼喊便开动机关，并仔细盘查来人的身份。凌霄城守卫严密，奸恶之徒是不受欢
迎的。如果守城弟子放恶人入内，将面临十分严厉的处罚。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"bingjie1",
		"westup" : __DIR__"chengtouw1",
		"eastup" : __DIR__"chengtoue1",
	]));
	set("objects", ([
		__DIR__"npc/dizi_chengmen" : 6,
	]));

	setup();
}

void init()
{
	add_action("do_down", "jiang");
	add_action("do_up", "sheng");
}

void up_bridge()
{
	object room;

	if(!( room = find_object(__DIR__"bridgew")) )
		room = load_object(__DIR__"bridgew");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "六名雪山弟子一齐转动机关，吊桥便又升了起来。\n", this_object());
		room->delete("exits/north");
		message("vision", "只听一阵吱呀乱响，吊桥又升了起来。\n", room);
	}
}

int do_up(string arg)
{
	if (!query("exits/south"))
		return notify_fail("吊桥已经升起来了。\n");

	if (!arg || (arg != "bridge" && arg != "south"))
		return notify_fail("你要升什么？\n");

	message_vision("$N朗声道：请诸位师兄将吊桥升上来，以防奸恶之徒混入城中！\n", this_player());

	remove_call_out("up_bridge");
	call_out("up_bridge", 1);

	return 1;
}

int do_down(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("吊桥已经放下来了，快走吧。\n");

	if (!arg || (arg != "bridge" && arg != "south"))
		return notify_fail("你要放什么？\n");

	if(!( room = find_object(__DIR__"bridgew")) )
		room = load_object(__DIR__"bridgew");
	if(objectp(room))
	{
		set("exits/south", __DIR__"bridgew");
		message_vision("$N对雪山弟子一拱手：请帮我放下吊桥，多谢！\n", this_player());
		message_vision("六名雪山弟子一齐转动机关，吊桥便架在了深谷之上。\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "只听得轧轧声响，吊桥缓缓放下。\n", room);
		remove_call_out("up_bridge");
		call_out("up_bridge", 10);
	}

	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir != "south")
		if (query("exits/south")) 
			return notify_fail("吊桥还没有升起来，你就这样走了，可能会给外敌可乘之机的。\n");

	if (dir == "south" || dir == "north")
		if (me->id("xueshan dizi"))
			return 0;

	return ::valid_leave(me, dir);
}