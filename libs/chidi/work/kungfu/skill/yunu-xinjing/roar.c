// roar.c 黯然销魂吟

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if( (int)me->query("neili") < 500 )
                return notify_fail("你长叹一声，大家吓了一跳。\n");
 
        if((string)me->query("family/family_name") != "古墓派" )
                return notify_fail("你又不是古墓弟子，怎么能用如此高深的玉女心经? \n");

        if((int)me->query_skill("yunu-xinjing", 1) < 180)
                return notify_fail("你的玉女心经修为还不够深! \n");        

        skill = me->query_skill("force");

        me->add("neili", -150);
        me->receive_damage("qi", 30);

        me->start_busy(3);
        message_vision(
   BLINK MAG "\n $N右手抚胸，低声长吟出一曲「黯然销魂」,但见一阵寒意扑面而来，人的心神朦胧中竟然漂移不定。\n" NOR, me);
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

                damage = skill - ((int)ob[i]->query("max_neili") / 11);
                if( damage > 0 ) {
                        ob[i]->receive_damage("jing", damage);
                        if( (int)ob[i]->query("neili") < skill * 2 )
                                ob[i]->receive_wound("jing", damage);
                tell_object(ob[i], "你忽然觉得一阵寒意扑面而来，心神朦胧中漂移不定。\n");
                }
        }

return 1;
}

