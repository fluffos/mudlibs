// roar.c 一笑顷城
// by Lonely

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够。\n");
                
        if (environment(me)->query("no_fight")) 
                return notify_fail("这里不能攻击别人! \n"); 

        skill = me->query_skill("force", 1);

        me->add("neili", -100);
        me->receive_damage("qi", 10);

        me->start_busy(3);
        message_combatd(
                HIG "$N必除杂念，心神合一，嫣然一笑，"HIM"$N"HIG"靓丽四射，所有人都为之一振,顿时全场春意黯然！\n" NOR, me);
        ob = all_inventory(environment(me));
        
        for (i = 0; i < sizeof(ob); i++) 
        {
                if (! ob[i]->is_character() || ob[i] == me) 
                        continue;
                        
                if (! living(ob[i]) || wizardp(ob[i]) ||  
                    (ob[i]->query("age") < 17 && userp(ob[i]))) 
                        continue; 

                if (skill/2 + random(skill/2) < (int)ob[i]->query_skill("force", 1))
                        continue;
                
                me->want_kill(ob[i]); 
                me->fight_ob(ob[i]); 
                ob[i]->kill_ob(me); 

                damage = skill - ((int)ob[i]->query("max_neili") / 15);
                if (damage > 0)
                {
                        ob[i]->set("last_damage_from", me);    
                        ob[i]->receive_damage("jing", damage * 2, me);
                        if ((int)ob[i]->query("neili") < skill * 2)
                                ob[i]->receive_wound("jing", damage, me);
                        tell_object(ob[i], HIY "你只觉得眼前一片模糊，朦胧中似乎有无数的美女在对你甜甜的笑,让你魂飞九霄\n" NOR);
                }
        }
        return 1;
}
