#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        object weapon;
        int mypot, tapot, damage, damage_pot;

        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「戳字诀」只能对战斗中的对手使用。\n");

        if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff" )
                return notify_fail("你右手没拿棒,还想使棒法的绝招?别作梦了!\n");

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) &&
            me->query("family/family_name") != "丐帮" && me->query("chushi/last_family") != "丐帮" )
                return notify_fail("你是哪儿偷学来的武功！\n");

        if((int)me->query("max_neili") < 400 )
                return notify_fail("你的内力太低了。\n");

        if((int)me->query("neili") < 200 )
                return notify_fail("你的内力不足！怎能化他人内力？\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query("qi") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("huntian-qigong", 1) < 100)
                return notify_fail("你的混天气功等级不够，施这招恐怕有困难！\n");

        if((int)me->query_skill("dagou-bang",1) < 300)
                return notify_fail("你的打狗棒法火候还不到，使用这一招会有困难！\n");

        mypot=(int)me->query_skill("staff", "dagou-bang")/10;
        mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));
        if(me->query("betrayer") > 0)
        {
            mypot=mypot/(me->query("betrayer")+1);
        }

        tapot=((int)target->query_skill("dodge")/2+(int)target->query_skill("parry"))/2;
        tapot=tapot/10;
        tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));

        damage_pot=(int)me->query_skill("staff", "dagou-bang");

        message_vision(HIW"\n$N手中"+weapon->name()+HIW"突然往下横扫，向$n递出一着虚招，在$n一愕之际，猛然使出打狗棒法中不传之秘「戳字诀」！\n",me,target);

        me->start_busy(2+random(2));
//命中率B+，但是最低不低于50%
        if ( F_KUNGFU->hit_rate( mypot+tapot, tapot, 9, me, target ) )
        {
                message_vision(HIR"\n$n一招不慎，被$N的棒梢戳中，顿时内息逆转，气血倒流！\n"NOR,me,target);
                damage = damage_pot*2;
                if (damage>2000) damage=2000;
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                COMBAT_D->report_status(target);
                me->add("neili", -damage_pot/10);
                if ((int)me->query("neili")<0) me->set("neili",0);
        }
        else
        {
                message_vision(HIY"\n$n身形一闪，躲过了$N的攻击。\n"NOR,me,target);
        }

        return 1;
}

