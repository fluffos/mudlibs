// 侠客台
// for Xiake dao
// modified by aiai  98/10/27

#include <ansi.h>

inherit ROOM;
int canwu(object me,int times);

void create()
{
    set("short",HIC"阅览室"NOR);
    set("long", GRN @LONG
这个巨大的房间里面密密麻麻排了几十列书架，书架上放满
了各种典籍，书架之间的过道上放着几把椅子，你可以坐在椅子
上耐心得钻研(study)那些典籍。
LONG NOR
    );

    set("exits", ([
        "northwest"  : __DIR__"cjg1",
    ]));

    set("no_sleep",1);
    setup();
}

void init()
{
        add_action("do_watch","study");
}

int do_watch(string arg)
{
   object me;
   int times;

   me = this_player();

   if( !arg || sscanf(arg, "%d", times)!=1 )
   {
		  tell_object(me,"指令格式：study 次数\n");
		  return 1;
   }
   
   return canwu(me,times);
}

int canwu(object me,int times)
{
	int realtimes,i;
	int imp_skill;
	string fail_msg;
	int sk=me->query_skill("literate",1);	

	if(me->is_busy())
	{
	  tell_object(me, "你正忙着呢。\n" );
		return 1;
  }

	if (times < 1)
	{
	  tell_object(me, "你至少要读一次！\n" );
		return 1;
  }

	if (times > 50)
	{
	  tell_object(me, "你一次最多阅读五十次！\n" );
		return 1;
  }
  
  if ( !me->query_temp("cjg/can_read") )
  {
    tell_object(me, "你并没有在此阅读典籍的资格，被人赶出了阅览室！\n" );
    me->move("/newbiequest/shaolin/cjg/cjg1");
    return 1;
  }
  
  if ( me->query_temp("cjg/can_read") &&
       time()-me->query_temp("cjg/read_time")>3600*4 )
  {
    tell_object(me, "你已经在此呆了四个小时了，被人赶出了阅览室！\n" );
    me->move("/newbiequest/shaolin/cjg/cjg1");
    return 1;
  }
  
	message_vision("$N正专心阅读典籍。\n", me);

	if( (int)me->query("max_jingli")<100)
	{
		write("你精力不够，无法继续钻研典籍。\n");
		return 1;
	}
	
	if( (int)me->query("jing")<150 )
	{
		write("你已经累了，还是休息一会吧。\n");
		return 1;
	}
	
	if ( sk  > me->query_skill_limit() )
	{
		tell_object(me, "也许是缺乏阅历，你对典籍上所说的东西总是无法领会。\n");
		return 1;
	}

	realtimes = times;
	fail_msg = "";
	if ( ((int)me->query("jing")-100)/50 < times )
	{
		realtimes = (me->query("jing")-100)/50;
		fail_msg = "你已经累了，还是休息一会吧。\n";
	}
	
	if ((me->query("neili")-150)/5 < realtimes)
	{
		realtimes = (me->query("neili")-150)/5;
		fail_msg = "你内力不足，无法专心研究典籍。\n";
	}
	
  tell_object(me, "你在阅览室里面专心地阅读典籍。\n");
	me->receive_damage("jing",50*realtimes);
	me->add("neili",-5*realtimes);
	imp_skill = (int)me->query_skill("literate",1)/6+1;
	imp_skill = imp_skill * SPEWEEK_D->query_learn_bonus()/100;//special week
	me->improve_skill("literate",imp_skill*realtimes);
	if (fail_msg != "") tell_object(me,fail_msg);
	return 1;
}