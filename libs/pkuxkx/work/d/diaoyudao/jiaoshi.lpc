// Room: /d/diaoyudao/jiaoshi.c 大礁石
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void init()
{
	add_action("do_climb", "climb");
	add_action("do_bo","bo");
}


void create()
{
	set("short", "大礁石");
	set("long", @LONG
这是一块临海的大礁石(stone)，上面青苔密布，要想上去可不
容易，稍不小心，就可能滑下来。由于有礁石的庇护，旁边生长着旺
盛的野草(cao)。
LONG
	);

	set("item_desc", ([
               "stone" : "这是一块三人多高的礁石，海边上随处可见，你觉得没必要上去。\n",
	       "cao" : "一片旺盛的野草，你无聊得想拨开野草，看看会不会跳出一个美人鱼。\n",	
       ]));


	set("exits", ([
                "southwest" : __DIR__"shiqun",
        "northeast" : __DIR__"jiaoshi1",
	]));


	set("outdoors", "diaoyudao");
	setup();
}

int do_climb(string arg)
{
        object me = this_player();
	if( !arg || arg!="stone" ) 
	{
	     if ( !arg ) return notify_fail("你要往哪儿爬？\n");
             if ( arg!="stone" )  return notify_fail("那里不能爬！\n"); 
        }
	if (arg=="stone")
	{
//	    if (this_player()->query_temp("marks/爬1") ) 
//                 return notify_fail("你刚刚爬上去过，怎么没完没了？\n");
	    message_vision(HIY "$N施展壁虎功，慢慢向上爬去......\n" NOR,me);
	    call_out("climb",10,me);
            if( (int)me->query_skill("dodge") < 50)
		 {
                   me->receive_damage("qi", 10, "从礁石上载下来摔");
                   me->receive_wound("qi",  10, "从礁石上载下来摔");
                   message_vision(HIR"$N一不小心手脚打滑，栽了下来，... 啊...！\n"NOR, me);
                   tell_object(me, HIR"你从礁石上摔了下来，只觉得浑身无处不疼，还受了几点伤。\n"NOR);
                   message("vision", HIR"只见" + me->query("name") + "一个倒栽葱从礁石上摔了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
		   return 1;
		}
	    else {
		write("你轻松地爬上大礁石。\n");
		me->move(__DIR__"diaoyutai");	
                message("vision",me->name()+"突然出现在你的身旁，看样子不怀好意。\n",environment(me),({me}));
//		if (!(me->query_temp("marks/钓")) 
//		   me->set_temp("marks/钓",me->query_skill("force"));
//		this_player()->set_temp("marks/爬1", 1);
          	return 1;
       		 }
	}   
}

int do_bo(string arg)
{
	object ob,obj;
	object me = this_player();
	if( !arg || arg!="cao" ) 
	{
	     if ( !arg ) return notify_fail("你要拨开什么？\n");
             if ( arg!="cao" )  return notify_fail("那个东西不能拨开！\n"); 
        }
	if (arg=="cao")
	{
		if(objectp(obj = present(environment(me)))) 
		   return notify_fail("旁边有人，你拨草不怕被人笑话吗？\n");

		if (this_player()->query_temp("jiao1/拨1") ) 
		{
		   message_vision(HIY "$N小心翼翼地拨开野草......里面没有发现什么东西。\n" NOR,me);
		   return 1;
		}
		   message_vision(HIY "$N小心翼翼地拨开野草......" + HIR +"突然！"+HIY+"跳出两只巨海蟹。\n" NOR,me);
		   this_player()->set_temp("jiao1/拨1", 1);
		   ob = new(__DIR__"npc/haixie2");
           ob->move("/d/diaoyudao/jiaoshi");
           ob->move("/d/diaoyudao/jiaoshi");
		   return 1;
	}
}


void close(object room)
{
	message("vision","只见分开的野草自动收拢，恢复原状了。\n", room);
	room->delete("exits/enter");
}	




