//modify by kiden
//燥热

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
         object * ob,* inv;
         int i;
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", HIR+me->name() + "满脸通红，浑身大汗，痛苦不堪！\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIY "你突然感到全身燥热无比！\n" NOR );
      message("vision", HIR+me->name() + "突然满脸通红，留下大滴的汗珠！\n"NOR,environment(me), me);
   }
                        ob = all_inventory(me);
                        for(i=0;i<sizeof(ob);i++)
                        {
                                if(ob[i]->query("no_drop"))
                                        continue;
                                inv = all_inventory(environment(me));  
                                if(sizeof(inv)>49)
                                {
                                        if(!ob[i]->is_character())
                                                destruct(ob[i]);
                                }
                                else if(ob[i]->move(environment(me)))
                                {
                                        if(ob[i]->is_character() )
                                                message_vision("$N将$n从背上放了下来，躺在地上。\n", me, ob[i]);
                                        else 
                                        {
                                                message_vision(sprintf("$N丢下一%s$n。\n",ob[i]->query("unit")),me,ob[i]);
           }
         }
        }
                        if(me->query("jingli")>100)
                                me->add("jingli",-100);
                        else
                                me->set("jingli",1);
      me->apply_condition("heat", duration - 1);
                        return 1;
   return CND_CONTINUE;
}

