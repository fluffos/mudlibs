///kungfu/skill/chunyang-quan/lianhuan.c 连环三招
// sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        string weapon;
        int damage;
        string *limb, type, result, str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("连环三招只能对战斗中的对手使用。\n");


        if( objectp(me->query_temp("weapon")) )
                return notify_fail("连环三招需空手才能施展！\n");

        if( (int)me->query_skill("haotian-zhang", 1) < 120 )
                return notify_fail("你的昊天掌不够娴熟，不会使用连环三招。\n");

        if( (int)me->query_skill("xiantian-qigong", 1) < 100 )
                return notify_fail("你的先天功不够娴熟，不会使用连环三招。\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("你现在内力太弱，不能使用连环三招。\n");

        if( me->query("neili") <= 200 )
                return notify_fail("你的内力不够使用连环三招！\n");


        message_vision(HIR "$N怒喝一声，拚尽全力，突然闪电般攻出拳、掌、腿连环三招！\n\n" NOR, me, target);

        me->add_temp("apply/attack",80);
        me->set_temp("lianhuan",1);

        message_vision(HIW"第一招！\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIM"第二招！\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack",-80);

        message_vision( HIC"\n紧跟着$N突然腾空飞起，使出一招鸳鸯连环腿，两腿风驰电掣连环踢向$n\n",me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
        {
                if( ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("cuff") + me->query_skill("force"))*2/3) )
                {
                        message_vision(HIR"只听$N一声惨叫，这连环二腿正中心口。但见$n一个身躯突然平平飞出，腾的一响，尘土飞扬，跌在丈许之外，直挺挺的躺在地下，再也不动。\n\n"NOR, target,target );
                        target->receive_wound("qi", (int)me->query_skill("strike")*2, me);
                        target->receive_damage("qi", (int)me->query_skill("strike")*2,  me);
                        me->add("neili", -me->query("jiali"));
                }
                else
                {
                        damage = random(((int)me->query_skill("cuff"))+me->query("jiali"))*( 1 + random(me->query("jiajin")/5) ) ;
                        if(damage > 2500) damage = 2500;
                        if(damage < 300) damage = 300;
                        me->add("neili", -me->query("jiali")/2);

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", (int)me->query_skill("strike"), me);

                        limb = target->query("limbs");
                        type = "瘀伤";
                        message_vision(HIY"只听$N一声惨叫，这连环二腿正中$P"+limb[random(sizeof(limb))]+"，结果把$P踢摔了个跟头。\n"NOR,target);

                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                }
                me->start_busy(1+random(2));
        }
        else if( ( random( target->query_skill("dodge") ) >  me->query_skill("unarmed")*2/3) && random(5) == 1 )
        {
                message_vision(HIR"$N猛觉得劲风罩来，心知不妙，慌忙闪开，结果$n踢了个空，白白自己重重跌了一跤。\n\n"NOR, target,me );
                me->receive_damage("qi", 30+random(50),  me);
                me->start_busy(1+random(2));
                str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
                message_vision("($N"+str+")\n", me);
        }
        else
        {
                message_vision( HIG"$N眼见这一腿来势凶猛，当下双足一点，跃高四尺，躲开了$n这一招，不过也出了一身冷汗。\n\n" NOR,  target,me);
                target->start_busy(1+random(2));
                me->start_busy(1);
        }

        me->delete_temp("lianhuan");

        me->add("neili", -200);
        me->start_busy( 1+random(2) );

        return 1;
}


