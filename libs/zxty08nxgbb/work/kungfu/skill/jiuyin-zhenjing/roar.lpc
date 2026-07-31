#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if( ((int)me->query("neili") < 600 ) || ( (int)me->query_skill("jiuyin-xinjing",1) < 800) )
            return notify_fail("你鼓足真气「喵」的叫了一声, 结果吓走了几只老鼠。\n");  

        skill = me->query_skill("force");

        me->add("neili", -150);
        me->receive_damage("qi", 30);

        me->start_busy(3);
   message_vision( HIR "$N猛的两眼一亮，运起体内存积的九阴真气发出一声惊天动地的巨吼！！\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me )
                        continue;

                if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
                        continue;

                if( !ob[i]->is_killing(me) )
                        ob[i]->kill_ob(me);
                if( !me->is_killing(ob[i]) )
                        me->fight_ob(ob[i]);
if (userp(ob[i]))
{
ob[i]->set_temp("zjb_roar",""+me->query("id")+"");
}


                damage = skill - ((int)ob[i]->query("max_neili") / 11);
                if( damage > 0 ) {
                        ob[i]->receive_damage("jing", damage);
                        if( (int)ob[i]->query("neili") < skill * 2 )
                                ob[i]->receive_wound("jing", damage);
                tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样。\n");
                }
        }

return 1;
}

