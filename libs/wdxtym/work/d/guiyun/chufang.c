// Room: /guiyun/.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是归云庄的厨房，一个乡下妇人正在灶边忙来忙去，看来
她就是这里的厨娘了。如果肚子饿了，就赶快找厨娘要 (serve)些
吃的吧。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"huayuan",
	]));
	set("ricewater", 5);
	setup();
}

void init()
{
	add_action("do_serve","serve");
}

int do_serve()
{
	object me;
	object food;
	object water;
	me=this_player();
	if (me->query("family/family_name") != "桃花岛")
		return notify_fail("厨娘道：你不是桃花岛弟子，不能拿取食物。\n");
	if(present("zongzi",this_player()) || present("tea",this_player())) 
		return notify_fail("厨娘道：吃完了再拿，别浪费食物。\n");
	if(present("zongzi",this_object()) || present("tea",this_object())) 
		return notify_fail("厨娘道：吃完了再拿，别浪费食物。\n");
	if (query("ricewater")>0)
	{
		message_vision("厨娘连声答应，给$N一杯香茶和一个粽子。\n",me);
		food=new(__DIR__"obj/zongzi");
		water=new("/d/wudang/obj/xiangcha");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("厨娘对$N歉声道: 嗨，吃的喝的都没了。\n",me);
	return 1; 
}

int valid_leave(object me,string dir)
{
	me=this_player();
	if(dir=="south" && (present("zongzi",this_player()) || present("tea",this_player()))) 
	     return notify_fail("厨娘说道：吃了就别带走。\n");
	return ::valid_leave(me,dir);
}

void reset()
{
	::reset();
	set("ricewater", 5);
}

