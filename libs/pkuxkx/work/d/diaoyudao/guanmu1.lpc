// Room: /d/diaoyudao/guanmu1.c 灌木丛
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void init()
{
        add_action("do_kan", "kan");
	add_action("do_zuan","zuan");
}

void create()
{
	set("short", "灌木丛");
	set("long", @LONG
这里是山崖下的一大片灌木丛，灌木(guanmu)密集地生长在一
起，挡住向前的道路。上面还缠绕着藤草，开着鲜艳的牵牛花；哗
哗流淌的溪水从灌木丛下流出。看来是没有路可走了。
LONG
	);

	set("exits", ([
                 "north" : __DIR__"guanmu2",
		 "southeast" : __DIR__"guanmu3",
		 "west" : __DIR__"xiaoxi",
            ]));
	set("item_desc", ([
               "guanmu" : "这是茂盛的灌木，生长得有一人多高，密密麻麻的一大片，
如果你往里钻，肯定会被扎得鲜血淋漓。\n",
       ]));

	set("outdoors", "diaoyudao");
	setup();
}

int do_kan(string arg)
{
	object ob,*inv,obj;
        object me = this_player();
	obj=new("/d/diaoyudao/obj/chaidao");
	
	if( !arg || arg!="guanmu" ) 
	{
	     if ( !arg ) return notify_fail("你要砍什么？\n");
             if ( arg!="zhi" )  return notify_fail("没事瞎砍什么？\n"); 
        }
	if (arg=="guanmu")
	{
	  if (!(me->query_temp("望")==1)) 
		return notify_fail("这里有一大片灌木丛，你砍得完吗！\n");
	  ob = present("chai dao", me);
	  if (!(ob) || !(ob->query("equipped")))
              return notify_fail("你没有配备合适的工具。\n");
	    
	  if (me->query_temp("灌木")>=3 )
	  {	
		me->delete_temp("望1");
		me->delete_temp("灌木");
		destruct(ob);
                tell_object(me,"柴刀已经不能使用了，你随手扔进了灌木丛。\n");
		return 1;
	  }
	  me->add_temp("灌木",1);
	  tell_object(me, HIY"你用柴刀胡劈乱砍一翻，砍出了一条通道，随后钻了进去，
身后的灌木奇迹般的恢复了原状。\n"NOR);
	  message_vision("\n$N从空气中消失了。\n",me);
	  me->move(__DIR__"xiaodao");	
	  return 1;
	}
}

int do_zuan(string arg)
{
     object me=this_player();
     if( !arg || arg!="guanmu" ) 
	{
	     if ( !arg ) return notify_fail("你要干什么？\n");
             if ( arg!="zhi" )  return notify_fail("你要往哪里钻？\n"); 
        }
	if (arg=="guanmu")
	{
	    message_vision("\n$N非常自信地向灌木丛冲了过来，拼命往里钻去......\n",me);
	    message_vision("\n$N被灌木扎得鲜血淋漓，昏倒在地上！\n",me);
	    me->unconcious();
	    return 1;
	}
}