#include <ansi.h>
#include <room.h>
inherit ROOM;

//int do_search();

void create()
{
	set("short", HIY"暗室"NOR);
	set("long",
HIC"这是一个地下的大洞，是专为鳌拜存放从各处收刮来的财宝的。
各种珠宝玉器应有尽有，不过这些都不入你法眼，看来好好搜索一
下肯定会有更大的发现。上方是一块铁板门 (door)。\n"NOR
	);
        set("count", 1);
	set("item_desc", ([
		"door" : "这是一扇极厚的铁板门，看来需要很大的力气才能打开。\n",
		]));
	setup();
}

void init()
{
	object me = this_player();
	add_action("do_search", "search");
        add_action("do_open", "open");
}

int do_open(string arg)
{
        if (!arg || arg!="door") return notify_fail("你要打开什么？\n");
        return notify_fail("你用尽全身力量也无法打开这扇门，看来只能叫人从外面帮忙了。\n");
}

int do_search()
{
	object me = this_player();
	object ob, bb;
	int neili, i, mount;
	mount=random(2)+1;
  if ( me->is_busy() )
  	{write("你上一个动作还没有完成呢。\n");
	return 1;}
  neili = me->query("neili");
  if ( neili < 1000 )
  	{
  	write("你的内力太低了，无法集中力量查看。\n");
	return 1;
	}
  if ( (int)me->query("marks/aobai_search" )+10800 > (int)me->query("mud_age") )
	{
	write("你前不久才来拿过东西，现在又来拿太贪心了吧，至少要过几天.\n");
	return 1;
	}
  if ( objectp(bb = present("bao biao",environment(me))) )
	{
	message_vision("$N对$n大喝一声：“干什么？”\n", bb, me);
	bb->kill_ob(me);
	return 1;
	}
  if ( time()-query("searchtime")>=60*60 )
	{
	message_vision("$N正想搜寻什么，忽然背后冲进来几个保镖．\n" ,me);
 	set("searchtime",time());
 	set("count", 1);
 	for( i=1;i<=mount;++i )
    		{
 		bb=new(__DIR__"npc/baobiao");
   		bb->move(this_object());
   		bb->command("guard up");
   		bb->kill_ob(me);
   		}
	return 1;
    	}
  else
    	{
	message_vision("$N开始仔细查看这里的每一个角落，希望能找到什么。\n",me);
	me->start_busy(10);
	me->add("neili",-1000);
	call_out("end", 10, me);
	return 1;
    	}
}

void end(object me)
{
  object ob;
  if( !objectp(me) || !userp(me) || environment(me) != this_object() )
	{
       	return;
	}  
  if (query("count") < 1)
	{
 	message_vision("$N累了个半死，结果什么都没有找到。\n",me);
 	return;
	}
  add("count", -1);
  me->set("marks/aobai_search", me->query("mud_age"));
  switch(random(11))
	{
 	case 2: ob=new(__DIR__"npc/obj/book42_1");
          	ob->move(me);
          	message_vision("$N找到了一本经书，不禁欣喜若狂。\n",me);
          	break;
 	case 1: ob=new(__DIR__"npc/obj/book42_8");
          	ob->move(me);
          	message_vision("$N找到了一本经书，不禁欣喜若狂。\n",me);
          	break;
 	case 0: message_vision("$N找到一把匕首，不禁欣喜若狂。\n",me);
          	ob=new(__DIR__"npc/obj/bishou");
          	ob->move(me);
          	break;
 	default: message_vision("$N找到一件宝甲，不禁欣喜若狂。\n",me);
          	ob=new(__DIR__"npc/obj/baojia");
          	ob->move(me);
          	break;
	}
}

int valid_leave(object me, string dir)
{
  if ( (dir == "up") && (present("bao biao",environment(me))) )
	{
	return notify_fail("保镖正看守着这个方向，你上不去！\n");
	}
  else 
	{
	write("你纵身一跳，终于冲出了暗室!!!\n");
        return ::valid_leave(me, dir);
	}
}