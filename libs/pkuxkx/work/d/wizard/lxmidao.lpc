//密道
//by all
//2012/11/29

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIC"密道"NOR);
        set("long", @LONG
这里是一处密道，不知道通到何处。顶上似乎有一块石板(stone)，不知能否推开。
LONG
			);

	set("item_desc", ([
		"stone" : "这是一块石板，可以试着推(push)一下。\n",
	]));
	set("room_location", "/d/city/");
	set("exits", ([     
	"out" : "/adm/room/lxguan",
	]));
	setup();
}

void init()
{	
	add_action("do_push", "push");
	add_action("do_mingling", "mingling");
	set("real_dark",1);
	set("no_sleep_room",1);
}

int do_push(string arg)
{
        object me, room, env1;
        me = this_player();
	env1 = environment(me);        
  	if ( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
	if(!me->query_temp("laxiang/tiaozhan"))	return notify_fail("你没事儿推它干什么？\n");
        if (!arg || arg!="stone") return notify_fail("你要推什么？\n");
	if (env1->query("exits/up")) return notify_fail("石板已经被挪开了。\n");
        if (me->query("neili") < 1000)
        {
		message_vision("$N想运功推开石板，无奈内力不济始终无法奏效。\n", me);
		message_vision("$N气血翻滚，心神恍惚，一下晕了过去。\n", me);
		me->set("neili", 0);
		me->unconcious();
        	return 1;
	}
	message_vision("$N暗运内功，轻松推开了石板。\n", me);
	me->add("neili", -1000);
	if(!( room = find_object(__DIR__"lxmidao2")) )
        room = load_object(__DIR__"lxmidao2");

    	if(objectp(room))
    	{
	        room->set("exits/down", __DIR__"lxmidao");
        	message("vision", "下面传来一阵响声，有人推开了地下的石板！！\n", room);
	}
        set("exits/up", __DIR__"lxmidao2");
	remove_call_out("close");
	call_out("close", 60, this_object());
	return 1;
}

void close(object room)
{
        object room1;
        message("vision","只见石板自动恢复原位，挡住了向上的出口。\n", this_object());
        delete("exits/up");
	if(!( room1 = find_object(__DIR__"lxmidao2")) )
        	room1 = load_object(__DIR__"lxmidao2");
    	if(objectp(room1))
    	{
	        room1->delete("exits/down");
		message("vision","只听吱吱声响，地上的石板自动回到了原位。\n", room1);
	}
}

int valid_leave(object me, string dir)
{
  	if ( (dir == "up") && me->query("laxiang/tiaozhan") )
	{
	return notify_fail("还是不要上去的好！\n");
	}
  	else 
	{
	write("你一纵身，跳出洞口，来到上面。\n");
        return ::valid_leave(me, dir);
	}
}

int do_mingling()
{
	object me = this_player();
	tell_object(me,HIR"你的随从不知道跑哪去了！\n"NOR);
	me->start_busy(1+random(2));
	return 1;
}