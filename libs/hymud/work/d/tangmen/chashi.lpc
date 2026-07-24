// Room: /d/tangmen/chashi.c

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string);
int do_sit(string);
int do_jump(string);
void delete_served(object);

void create()
{
	set("short", "茶室");
	set("long", @LONG
    这是唐门待客的茶室。满屋茶香、果香四溢，茶、果都是唐门“百果山庄”自
产的精品。室内摆设很雅致，有几张精致的檀香木桌(table),以及几把竹椅(chair)四
面是檀香雕花窗(window),可以望见窗外的花园。
LONG
	);

	set("exits", ([
		"north" : __DIR__ "kefang",
		"southeast" : __DIR__ "huayuan9",
	]));
	
    set("item_desc", ([
	    "table" : "一张精致的檀香木桌，上面放着水果盘和饮茶器具。\n",
	    "chair" : "一只青竹打制的靠椅，躺上去摇摇晃晃，非常惬意！\n",
	    "window" : "可以看得见大片繁茂的花丛,五颜六色，很是喜人。\n",
	]));
	                                

	set("objects",([
		__DIR__"npc/tangjing" : 1,
		__DIR__"obj/shuimitao" : 2,
		__DIR__"obj/tea" : 1,
		__DIR__"obj/dawancha" : 1,
	]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_tap(string arg)
{

	object me;
	object jing;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("你要敲什么？\n");	
	}
		
	me = this_player();	
	if( !objectp(jing = present("tang jing", environment(me))) )
	 	return notify_fail("你敲了敲桌子，却还是没人理你。你突然感觉自己很无聊。\n");
	 			
	if( !me->query_temp("marks/sit") )  
		return notify_fail("你敲了敲桌子，突然手指上一疼，原来是停在上面的一只蜜蜂蜇了你一口，"
	 		+"\n你握着自己的手指跳了起来：哎哟！！！\n");
	
    if( me->query_temp("marks/served") )
    {
        message_vision("唐晶不耐烦地对$N说道：刚给你上过茶你接着就要，"+
				"你不累我还觉得累呢！\n", me);
        return notify_fail("");
    }

	message_vision("$N端坐在桌前，轻轻扣了下桌面，唐晶莞尔一笑，过来招呼。\n", me);
	
	jing->serve_tea(me) ;

    me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
    call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("你要坐什么上面？\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经有了个座位了。\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你找了个空位座下，等着上茶。\n");	
}


int valid_leave(object me, string dir)
{

	if (  (dir == "north")
	   && ( present("tea", this_player())
	        || present("shuimitao", this_player()) ) 
	   && objectp(present("jing", environment(me))) )
	switch ( random(2) ) 
	{
	case 0: 
	 return notify_fail
		("唐晶对着$N用手指刮着自己的小脸蛋：吃饱喝足还要拿，羞！羞！羞！\n");
	 break;
	case 1:
	 message_vision("唐晶对$N嘻嘻笑道：老太太说过，饮食不得带出茶房。", me);
	 return notify_fail("\n");
	 break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
