#include <ansi.h>

int exert(object me)
{
       int i;
       if(me->query_temp("jiuyin/powerup"))
                return notify_fail("你正在运使九阴总诀。\n");
       if ((int)me->query_skill("jiuyin-zhengong", 1) < 200)
                return notify_fail("你的九阴真功修为还不够。\n");
       if ((int)me->query_skill("daode-jing", 1) < 200)
                return notify_fail("你的道学心法修为还不够。\n");
       if( (int)me->query("neili") < 1500 )
                return notify_fail("你的真气不够。\n");
       i = me->query_skill("force")/5;
       i = i*2;
       me->add("neili", -1000);
       me->start_busy(5);
       me->start_exert(8);
       me->add_temp("apply/dodge", i);
       me->add_temp("apply/force", i);
       me->add_temp("apply/sword", i);
       me->add_temp("apply/whip", i);
       me->add_temp("apply/strike", i);
       me->add_temp("apply/cuff", i);
       me->add_temp("apply/claw", i);
       me->set_temp("jiuyin/powerup", 1);
         message_vision(HIY"$N运起九阴总诀，功夫威力陡然大增！\n"NOR, me);
       call_out("remove_effect", (int)me->query_skill("force")/4, me, i);
       return 1;
}

void remove_effect(object me, int i)
{
        if (!me) return;
         me->delete_temp("jiuyin/powerup");
         me->add_temp("apply/dodge", - i);
         me->add_temp("apply/force", - i);
         me->add_temp("apply/sword", - i);
         me->add_temp("apply/whip", - i);
         me->add_temp("apply/strike", - i);
         me->add_temp("apply/cuff", - i);
         me->add_temp("apply/claw", - i);
         message_vision(HIY"$N的九阴总诀运使完毕，吁了一口气。\n"NOR, me);
}

