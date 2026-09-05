// File		: guifang.c
// Created By	: iszt@pkuxkx, 2007-01-22

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "闺房");
	set("long", @LONG
这里是白自在最宠爱的孙女的闺房。室内温暖如春，阳光从窗缝里钻进来，
照在女儿家的陈设上，显得一切都是那么可爱。唯一不同于一般大户人家的千金
的是，床头挂着一把长剑，摆着一盆梅花，却更平添了几分不同于寻常女子的气
质。窗(window)外临着足有万丈深的雪谷，遥遥可见几只雄鹰正在峭壁间盘旋。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"huating",
	]));
	set("objects", ([
		__DIR__"npc/baiaxiu" : 1,
	]));
	set("item_desc", ([
		"window" : "木窗紧紧的关着，窗外临着足有万丈深的雪谷。\n",
		"hawk" : "几只雄鹰正在峭壁间盘旋。\n",
	]));
	set("window_closed", 1);


	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
	add_action("do_jump", "jump");
}

int do_open(string arg)
{
	object me = this_player();
	mapping desc = query("item_desc");

	if(arg!="window")
		return notify_fail("你要打开什么？\n");
	if(me->is_busy())
		return notify_fail("先忙完别的事再说吧。\n");
	if(!query("window_closed"))
	{
		write("木窗已经是开着的了。\n");
		return 1;
	}

	message_vision("$N轻轻推开木窗，一股冷风「呼」的灌了进来。\n", me);
	desc["window"] = "木窗大敞着，窗外就是足有万丈深的雪谷，冷风直往窗里灌。\n";
	set("window_closed", 0);
	me->start_busy(1);

	return 1;
}

int do_close(string arg)
{
	object me = this_player();
	mapping desc = query("item_desc");

	if(arg!="window")
		return notify_fail("你要关上什么？\n");
	if(me->is_busy())
		return notify_fail("先忙完别的事再说吧。\n");
	if(query("window_closed"))
	{
		write("木窗已经是关着的了。\n");
		return 1;
	}

	message_vision("$N顶着冷风，上前把木窗关上。\n", me);
	desc["window"] = "木窗紧紧的关着，窗外临着足有万丈深的雪谷。\n";
	set("window_closed", 1);
	me->start_busy(1);

	return 1;
}

int do_jump(string arg)
{
	object me = this_player();
	object room;

	if(arg!="window")
		return notify_fail("你要往哪里跳？\n");
	if(me->is_busy())
		return notify_fail("先忙完别的事再说吧。\n");
	if(query("window_closed"))
	{
		write("木窗正紧紧的关着，先打开(open)它再说吧。\n");
		return 1;
	}

         return notify_fail("没事跳什么跳，你嫌命长啊。\n");
	message_vision("$N看准阿绣坠落的方向，屏息纵出！\n", me);
	me->move(new(__DIR__"kongzhong"), 1);
	me->start_busy(999);
	return 1;
}
