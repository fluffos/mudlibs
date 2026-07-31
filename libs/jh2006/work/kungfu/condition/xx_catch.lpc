//by cool 98.6 for dalijob
// dali_songxin.c
//改编者caiji@SJ 8/24/2000
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
      int time;
      time = me->query_temp("xx/catch_time");

        if (duration < 5) tell_object(me, HIY "你抓虫的时间快到了，赶紧回去把虫子给守卫吧！\n" NOR);
        if (duration < 1) {

             tell_object(me, HIY "你时间已到，本次抓虫子结束！\n" NOR);
         
              me->delete_temp("xx_zuji",1);
              me->delete_temp("xx_zuji1",1);
              me->clear_condition("xx_catch");
                  return 0;
        }
        if (!duration) return 0;



  if(duration > time/7 && environment(me)->query("short")=="毒虫谷" && living(me)
    && duration < time && !me->query_temp("xx_zuji",1) && random(10)>3 &&(interactive(me)))
       {
       tell_object(me, HIY "你觉的有些不妙，似乎周围还有什么人在，被人盯上了！\n" NOR);
        me->add_busy(1);

       call_out("zuji", 0, me);    
       }

        me->apply_condition("xx_catch", duration - 1);
        return 1;
}


void zuji(object me)
{
          object obj; 
        if (me->query("combat_exp")>100000) {
          obj = new("/d/xingxiu/npc/shashou");
          obj->set("target", me);
          obj->move(environment(me));
          tell_object(me,"你隐约感觉到有人围了过来....!!! \n");
          me->set_temp("xx_zuji",1);

        if (me->query("combat_exp")>1000000)
         call_out("killer_clone", 2, me);
           } else {

 tell_object(me, RED "你一紧张，生怕有人偷袭，远处传来“你捉的虫子小而且毒性弱！我还是找别人去吧！”\n" NOR);

   }
    return;
}
void killer_clone(object me)
{
        object obj;

tell_object(me,"糟糕，又冲上来了个人....!!! \n");
      obj = new("/d/xingxiu/npc/shashou");
obj->set("target", me);
obj->move(environment(me));
return;
}

string query_type(object me)
{
        return "job";
}
