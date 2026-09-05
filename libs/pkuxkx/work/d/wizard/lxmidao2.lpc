//破庙
//by all
//2012/11/29

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIC"破庙"NOR);
        set("long", @LONG
这里是一座破庙屋内，大门紧闭。墙角地上有一块石板(stone)与别处不同。
LONG
			);
	set("item_desc", ([
	"stone" : "这是一块石板，可以试着拉(pull)一下。\n",
	]));
	set("room_location", "/d/city/");
	setup();
}

void init()
{	
	object me=this_player();
	object ob,room;
	int target_num;
//	room=this_object();

	if(me->query_temp("laxiang/tiaozhan") && interactive(me))
	{
		if (me->query("betrayer")>1||(me->query("betrayer")==1&&me->query("chushi/last_family")))
			target_num=3+random(2);
		else if	(me->query("chushi/last_family")||me->query("betrayer"))
			target_num=2+random(2);
		else 	target_num=2;
    		for (int a=0;a< target_num;a++ )
    		{    	    
    			ob = new(__DIR__"npc/lxdahan");
			ob->set_temp("seeme",me->query("id"));
			ob->do_copy(me);
			ob->move(this_object());
			ob->kill_ob(me);
			me->kill_ob(ob);
    		}
    		me->delete_temp("laxiang/tiaozhan");
	}
	add_action("do_pull", "pull");	
	add_action("do_mingling", "mingling");	
	set("real_dark",1);
	set("no_die",1);
	set("no_sleep_room",1);
}

int do_pull(string arg)
{
        object me, room, env2;
        me = this_player();
	env2 = environment(me);        
  	if ( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
        if (!arg || arg!="stone") return notify_fail("你要拉什么？\n");
	if (env2->query("exits/down")) return notify_fail("石板已经被挪开了。\n");
        if (me->query("neili") < 1000)
        {
		message_vision("$N想运功掀开石板，无奈内力不济始终无法奏效。\n", me);
		message_vision("$N气血翻滚，心神恍惚，一下晕了过去。\n", me);
		me->set("neili", 0);
		me->unconcious();
        	return 1;
	}
	message_vision("$N暗运内功，轻松掀开了石板。\n", me);
	me->add("neili", -1000);
	if(!( room = find_object(__DIR__"lxmidao")) )
        room = load_object(__DIR__"lxmidao");

    	if(objectp(room))
    	{
	        room->set("exits/up", __DIR__"lxmidao2");
        	message("vision", "上面传来一阵响声，有人掀开了地下的石板！！\n", room);
	}
        set("exits/down", __DIR__"lxmidao");
	remove_call_out("close");
	call_out("close", 60, this_object());
	return 1;
}

void close(object room)
{
        object room1;
        message("vision","只见石板自动恢复原位，挡住了向下的入口。\n", this_object());
        delete("exits/down");
	if(!( room1 = find_object(__DIR__"lxmidao")) )
        	room1 = load_object(__DIR__"lxmidao");
    	if(objectp(room1))
    	{
	        room1->delete("exits/up");
		message("vision","只听吱吱声响，头顶的石板自动回到了原位。\n", room1);
	}
}

int valid_leave(object me, string dir)
{
  if ( (dir == "down") && (present("mengmian dahan",environment(me))) )
	{
	return notify_fail("想走，留下性命再说！\n");
	}
  else 
	{
	if (me->query_temp("laxiang/killed")<2)
		return notify_fail("你似乎没有完成任务吧！\n");		
	write("你一纵身，跳入洞口。挑战成功，心里很是得意!\n");
	me->set("laxiang/tiaozhan",1);
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