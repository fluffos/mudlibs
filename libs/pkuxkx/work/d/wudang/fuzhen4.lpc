// fuzhen4.c 复真观四层
//seagate@pkuxkx 2010/10/21
#include <ansi.h>
inherit ROOM;

int inc(object me);

void create()
{
  set("short", "复真观四层");
  set("long", 
"这里是复真观四层，是武当收藏道教典籍的地方。靠墙是一排书架，\n"
"摆满了道教的典籍。中央有一个长方形的大桌子，上面也堆满了书。书架\n"
"上放着许多高深典籍(dianji)，张真人偶来也来此钻研太极真意。\n"
  );

  set("exits", ([
    "down" : __DIR__"fuzhen3",
  ]));

  set("item_desc", ([
    "dianji" : "许多道家的高深典籍，可以通过这些典籍研习(yanxi)道家太极真意，提高对沾衣十八跌的理解。\n",
  ]));


  set("objects", ([
    __DIR__"obj/taobook-"+(string)(random(100)%3+1) : 1,
    __DIR__"obj/taobook-"+(string)(random(100)%4+4) : 1
  ]));

  set("no_perform",1);
  set("no_exert",1);
  set("no_fight",1);

  setup();
}

void init()
{
  add_action("do_yanxi","yanxi");
}

int do_yanxi()
{  
  object me=this_player();
  mapping fam;
  int skill = me->query_skill("zhanyi-18die",1);
  
  if ( skill>me->query_skill_limit() )
    return notify_fail("你受到自身经验和悟性的影响，无法继续钻研太极了。\n");
  
  if (!(fam=me->query("family")) || fam["family_name"]!="武当派")
    return notify_fail("你又不是牛鼻子老道，在这里凑什么热闹！\n");

  if( me->query_skill("zhanyi-18die",1)<500 ||
      me->query_skill("taiji-shengong",1)<800 ||
      me->query_skill("taiji-quan",1)<800 )
    return notify_fail("你对太极的理解尚且达不到可以无师自通的地步！\n");

  if((int)me->query("jing")<(int)me->query("max_jing"))
    return notify_fail("你心神无法专一，怎能参悟道学至理？\n");
  
  if((int)me->query("qi")<(int)me->query("max_qi"))
    return notify_fail("你气血亏缺，无法静下心来参悟道学至理！\n");

  if (me->is_busy())
    return notify_fail("你现在无法静下心来钻研太极！\n");

  if ( me->query("score") < 1000 )
    return notify_fail("你对师门贡献不足，无法在此研习太极思想。\n");

  if (time()-me->query_temp("wudao") < 10)
    return notify_fail("你刚刚钻研完太极真意，需要休息一会儿！\n");

  tell_object(me,"你拿起一本道家经典，开始钻研张三丰的道家太极思想。\n"+
        WHT"渐渐的你心如止水，开始神游太虚。\n"NOR);
  me->set_temp("wudao",time());
  me->add("score", -2);
  me->set_temp("duration",6);
  inc(me);

  return 1;
}

int inc(object me)
{  
  int dur, inc;
  int pflv;
  
  if ( !objectp(me) )
    return 1;
    
  dur=me->query_temp("duration");
  inc=(int)me->query_skill("zhanyi-18die",1)*1*(int)me->query("int")/25;
  
  if (dur==6){
    message("vision", 
      me->name() + "走到墙边，盘膝坐下，口中仿佛念念有词。\n",environment(me),me);
    me->add_temp("duration",-1);
    me->start_busy(30);
    call_out("inc",5,me);
    return 1;
  }

  if (dur<6 && dur>0) {
    tell_object(me,HIW"你闭目冥想道学中的真谛，心中的疑惑逐渐释然，对太极的理解也更进了一步。\n"NOR);

	pflv = (int)me->query("purefamily/level");
    if (pflv>0 && me->query("purefamily/family_name") != "武当派") 
      pflv=0;
    if (pflv)
	  inc += inc*pflv/50;
  
    me->improve_skill("zhanyi-18die",inc);
    me->add_temp("duration",-1);
    me->start_busy(30);
    call_out("inc",5,me);
    return 1;
  }
  
  if (dur==0) {
    message_vision("$N修行完毕，收心定神，满心释然的站了起来。\n",me);
    me->start_busy(0);
    return 1;
  }
}