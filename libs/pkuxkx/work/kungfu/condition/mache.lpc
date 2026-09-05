//马车送人 Zine Nov 25 2010
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   object where = environment(me);
   if( duration < 1 ) 
    {
        if (me->query_temp("guche/target-chengdu"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/chengdu/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-dali"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/dalicheng/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-yingtianfu"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/yingtianfu/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-zhenjiang"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/zhenjiang/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-nanchang"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/nanchang/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-kunming"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/kunming/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-putian"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/fuzhou/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-yueyang"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/yueyang/machehang");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        if (me->query_temp("guche/target-riyuejiao"))
        {
            tell_object(me,YEL"迷迷糊糊中，你隐约听到马车夫喊到：到了！\n"NOR);
            me->delete_temp("guche");
            me->move("/d/riyuejiao/rukou");
            tell_room(environment(me),me->query("name")+"迷迷糊糊地下了车。\n",me);
            tell_object(me,"你迷迷糊糊地下了车。\n");
            return 1;
        }
        else
        {
            return 0;
        }
    }
   if(where->query("short")!="马车车厢") return 0; 
   if( !living(me) ) 
   {
      return 0;
   }
   else 
   {
      if (me->query_temp("guche/target-riyuejiao"))
       {tell_object(me,HIW"车外可以听见水声，这马车竟上了船，直接向北驶去。\n"NOR);}
      me->apply_condition("mache", duration - 1);
      tell_object(me,HIW"你看着窗外的景色，不禁昏昏欲睡。\n"NOR);
   }
   return CND_CONTINUE;
}
