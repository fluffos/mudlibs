// Room: /d/emei/chufang.c 厨房
// create by host dec,15 1997

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string);
int do_sit(string);
void delete_served(object);

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里满屋的饭香和茶香混合在一起，散发出的阵阵味道沁人心脾。只见
屋内有两个峨嵋的俗家女弟子正在忙着煮茶、做饭。由于峨嵋广种花草因而
创出了一套独特的作茶方法，每年开春采茶季节，弄来上好的茶叶。然后从
园中采摘上好的杜鹃和菊花的花瓣捣碎放入茶中，听说喝了能提神补气，跟
具有养颜的做用，亦十分的珍贵。屋内摆设了些桌子(table)和椅子(chair)，
坐满了许多峨嵋弟子。
LONG
	);

	set("exits", ([
                "south" :__DIR__"zoulang3",
	]));
	
    set("item_desc", ([
	    "table" : "一张典雅的桃木小桌，上面放着水果盘和饮茶器具。\n",
	    "chair" : "一只青竹打制的靠椅，躺上去摇摇晃晃，好舒服耶！\n",
	]));
	                                

	set("objects",([
              __DIR__"npc/fangbilin" : 1
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
	object fang;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("你要敲什么？\n");	
	}
		
	me = this_player();	
	if( !objectp(fang = present("fang bi lin", environment(me))) )
	 	return notify_fail("你敲了敲桌子，却还是没人理你。你突然感觉自己很无聊。\n");
	 			
	if( !me->query_temp("marks/sit") )  
		return notify_fail("你敲了敲桌子，却没想到有对年轻人从桌底下钻出来，愕然地看着你，"
	 		+"\n你突然感觉自己很愚蠢。\n");
	
    if( me->query_temp("marks/served") )
    {
        message_vision("方碧琳不耐烦地对$N说道：刚给你上过茶你接着就要，"+
				"你是个Ｒｏｂｏｔ我可不是啊！\n", me);
        return notify_fail("");
    }

	message_vision("$N端坐在桌前，轻轻扣了下桌面，方碧琳莞尔一笑，过来招呼。\n", me);
	
	fang->serve_tea(me) ;

    me->set_temp("marks/served", 1);
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

	if (  (dir == "south")
	   && ( present("xiang cha", this_player())
	        || present("mi tao", this_player()) ) 
	   && objectp(present("fang bi lin", environment(me))) )
       switch ( random(2) ) 
	{
	case 0: 
	 return notify_fail
		("方碧琳把嘴一撇：吃饱了喝足了还不够，临走怀里还揣上一些，小女子也替您脸红呢！\n");
	 break;
	case 1:
	 message_vision("方碧琳对$N道了个万福：静玄师伯吩咐过，饮食不得带出茶房。", me);
	 return notify_fail("\n");
	 break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
