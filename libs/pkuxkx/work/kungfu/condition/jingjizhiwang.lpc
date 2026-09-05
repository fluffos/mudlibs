#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1)
        {
      write(HIW"随着时间的流逝，似乎已经没有人记得，你就是曾经的竞技之王了....\n"NOR);
        if(me->query("title_bak")) me->set("title",me->query("title_bak"));
         me->delete("title_bak");
         return 0;
         }
        me->apply_condition("jingjizhiwang", duration - 1);
        return 1;
}
