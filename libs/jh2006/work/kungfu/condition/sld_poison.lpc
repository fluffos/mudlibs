// sld_poison
// 2/25/2001  by emnil@sj

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int i,j;

        i = (int)me->query("sld_pfm/ptype");
        switch (i) {
                case 1:
                        j = (int)me->query("sld_pfm/pjing");
                        me->receive_wound("jing", j);
                        break;
                case 2:
                        j = (int)me->query("sld_pfm/pqi");
                        me->receive_wound("qi", j);
                        me->add("jingli", -j);
                        me->add("neili", -j);
                        if (me->query("jingli")<0) me->set("jingli",0);
                        if (me->query("neili")<0) me->set("neili",0);
                        break;
        }
        message_vision((string)me->query("sld_pfm/pmsg")+"\n",me);

        if( duration < 1 ) {
                me->clear_condition("sld_poison");
                return 0;
        }
        else {
                me->apply_condition("sld_poison", duration - 1);
                return CND_CONTINUE; 
        }
}

string query_type(object me)
{
        return "poison";
}

