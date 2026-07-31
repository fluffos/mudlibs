// made by lks
 
#include <ansi.h>

 string query_name() { return "血雾"; }

inherit F_SSERVER;
 
int exert(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp,damage;


        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("huaxue-dafa",1);

        if( !me->is_fighting())
                return notify_fail("「血雾」只能在战斗中用在对手身上。\n");
 
        if( skill < 80)
                return notify_fail("你的化血大法不够纯熟, 不能使用「血雾」！\n");

        if( me->query("neili") < 300 )
                return notify_fail("你的内力不够，无法运用「血雾」！\n");
 
                
        msg = HIC "$N气贯丹田，咬破舌尖，吐出一口血雾。罩向$n。\n"NOR;

        ap = (me->query_skill("force") + skill)/2;
        dp = target->query_skill("force") / 2 + target->query_skill("lonely-sword") / 10;
        if( random(ap) > dp / 2)
        {
                if(userp(me))
            me->add("neili",-200);
		me->start_call_out((: call_other, __FILE__, "remove_effect",
				   me, skill :), skill);
		me->receive_damage("qi", me->query("max_qi") / 2000);

		           me->receive_damage("qi", me->query("max_qi") / 20);
                  msg += WHT"$n一个不防，被血雾笼罩了全身。只听见$n在血雾中惨叫连连!\n"NOR;

                damage = (int)me->query_skill("force", 1);
                damage += (int)me->query_skill("huaxue-dafa", 1);                
                target->receive_damage("qi", damage * 3);
                target->receive_wound("qi", damage);
                me->start_busy(2);
        }
        else
        {
                if(userp(me))
                 me->add("neili",-100);
                 msg += YEL"可是$p向旁边侧身一闪,躲过了血雾。\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

