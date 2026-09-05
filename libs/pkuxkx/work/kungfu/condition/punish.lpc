#include <ansi.h>
#include <login.h>
int update_condition(object me, int duration)
{     if (!userp(me))   return 1;
         if (duration < 1) {
                me->move("/d/city/kedian");
                message("vision",
      "只听乒地一声，你吓了一跳，定睛一看，原来是" +me->query("name") +"被巫师协
会的警卫摔了出来！\n" , environment(me), me);
           tell_object(me, HIY "铁门一响，外面的警卫抓住你，一摔，说：“出来吧！
以后老实点啊！”\n" NOR);
                me->set("startroom", START_ROOM);
                return 0;
        }
        me->apply_condition("punish", duration - 1);
        me->set("qi",0);
        me->set("jing",0);
        me->set("neili",0);
        me->set("food",0);
        me->set("water",0);
        tell_object(me,"警卫拿起枪狠狠地敲了你一下：让你不老实。\n");
        return 1;
}
