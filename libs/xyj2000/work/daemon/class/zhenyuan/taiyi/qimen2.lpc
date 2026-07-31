// cracked by vikee 2/09/2002   vikee@263.net

#include <ansi.h>

inherit SSERVER;
nosave string old_long, old_short;
nosave object env;


int do_quit();
int do_finish();

int cast(object me, object target)
{
  string msg,dest,dir;  
  string sname;
  object bagua=present("bagua fu",me);
  env=environment(me);
  
  
  if (me->query_skill("taiyi",1)<60)
     return notify_fail("你的太乙仙法还不够纯熟。\n");
  if (!bagua) 
    return notify_fail("你身上没有八卦符，不能施展奇门遁甲。\n");
  dir=bagua->query("dir");
  if (!dir) return notify_fail("你必须先在八卦符上指定<direct>施法的方向。\n");

  dest = environment(me)->query("exits/"+dir);
  if(!dest) return notify_fail("这个方向没有路径。\n");
  if (!env->valid_leave(me,dir))
     return notify_fail("你不能朝这个方向施展奇门遁甲。\n");
  if( (int)me->query("mana") < 400 )
          return notify_fail("你的法力不够了！\n");

  if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
      return notify_fail("你现在头脑不清醒，哪里使得出奇门遁甲！\n");

  if( random(me->query("max_mana")) < 50 ) {
       write("你失败了！\n");
       return 1;
  }

  if (me->is_busy())
    return notify_fail("你上一个动作还没有完成。\n");
   if (me->query_temp("cast_qimen")   )
    return notify_fail("你的上一个奇门遁甲阵好象还没收!\n");
    
  if(me->is_fighting())
    return notify_fail("你正忙着打架，没空玩奇门遁甲。\n");

   msg =  HIR "$N叽哩咕噜地念了几句咒语，突然间天空白光一闪!\n" NOR;
   message_vision(msg, me);
        
   me->add("mana", -400);
     me->receive_damage("sen", 100);
  
   old_long = env->query("long");
   old_short = env->query("short");  
   
   env->set("long",   @LONG

你突然觉得天旋地转，日月星辰全部消失，再也分不清东西南北。
眼前忽而漆黑一片，忽而亮光四射，忽而金星闪烁，耳边一时万籁
俱寂，一时锣鼓喧天，一股惧意由泥丸升起，直冲天灵，身不由己
地浑身直打颤。

LONG);
   env->set("short","奇门遁甲阵");   
   env->set("host",me);
   env->add_action("quit","do_quit");
   env->add_action("finish","do_finish");   
   
   me->set_temp("cast_qimen",1);   
   me->start_busy(random(3));
   return 1;
}

int do_quit()
{
     write("你心烦意乱，不知道如何才能退出。\n");
     return 1;	
}

int do_finish()
{
  object host=env->query("host");
  object me=this_player();
  if (host!=me) return 0;
 
  if (me->is_fighting()) {
    write("你正忙着打架，没有闲功夫。\n");
    return 1;
  }
  if (me->is_busy()){
  	write("你忙的很，哪儿有功夫收阵？\n");
  	return 1;
  }
  env->set("short",old_short);
  env->set("long",old_long);
  message_vision(HIB"$N手一挥，收起了奇门遁甲术。\n"NOR,me);
  
}
