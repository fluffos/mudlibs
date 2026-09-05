//打狗棒法转字决
// by advent 06-07-29

#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
        object weapon,ob;
        int skill;
        int i;
        string *style = ({
           HIR"「棒打双犬」－$N"HIR"舞动手中$w"HIR"，直指$n"HIR"强间穴！"NOR,
           HIY"「拨草寻蛇」－$N"HIY"棒交左手，手中$w"HIY"探出，弹向$n"HIY"风府穴！"NOR,
           HIG"「打草惊蛇」－$N"HIG"似是舞了一个棒花，$w"HIG"尾端直戳$n"HIG"大椎穴！"NOR,
           HIB"「拨狗朝天」－$N"HIB"手中$w"HIB"一垂一挑，棒头似是长了眼睛一般，直刺$n"HIB"悬枢穴！"NOR,
           HIW"「天下无狗」－$N"HIW"心中微怒，手中$w"HIW"化作一道绿光，劈头盖脸劈向$n"HIW"灵台穴！"NOR });
        int extra;
        string msg;
        int count;//出的招数
        mapping attack_val = ([
            "base" : ([ "weapon" : "staff", ]),//基本功夫类型
            "skill" : ([ "weapon" : "dagou-bang", ]),//高级技能名称
            ]);

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
            !me->query("dagou-bang/zhuan"))
            return notify_fail("你还没有学会「转字决」!\n");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「转字决」只能在战斗中使用。\n");

        if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff" )
                return notify_fail("你右手没拿棒,还想使棒法的绝招?别作梦了!\n");

/*        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "staff")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("必须用棒才能施展打狗棒法「转字决」。\n"); */

        if( (int)me->query_skill("dagou-bang", 1) < 100 )
                return notify_fail("你的打狗棒法不够娴熟，不会使用打狗棒法「转字决」。\n");

        if( (int)me->query_skill("huntian-qigong", 1) < 100 )
                return notify_fail("你的混天气功还没到家，无法使用打狗棒法「转字决」。\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("dagou-bang");
        extra = me->query_skill("dagou-bang",1) / 8;
        extra += me->query_skill("huntian-qigong",1) /4;

        if(me->query("betrayer") > 0)
        {
            extra = extra/(me->query("betrayer")+1);
        }

        me->add_temp("apply/attack", extra);      
        me->add_temp("apply/damage", extra);
        me->add("neili", -200);
        count=skill/100;
        if (count<5) count=3+random(3);
        else count=5;
        
        //显示perform具体情况
        //me->set_temp("combat_env",me->query("env/skip_combat"));
        //me->set("env/skip_combat",0);
        //target->set_temp("combat_env",target->query("env/skip_combat"));
        //target->set("env/skip_combat",0);                
        message_vision(HIG "$N"HIG"棒法一变，使出了「转字诀」！但见"+weapon->query("name")+HIG"成了一团棒影，连绵不绝猛点"+target->query("name")+HIG"后心各大要穴！\n"NOR,me);
        for(i=0;i<count;i++)
        {
                msg = style[i];
                if ( !objectp(me->query_temp("weapon")) ) break;
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }
        //恢复combat设置                                                  
        //me->set("env/skip_combat",me->query_temp("combat_env"));        
        //target->set("env/skip_combat",target->query_temp("combat_env"));
        
        me->start_busy(2+random(2));
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        return 1;
}

