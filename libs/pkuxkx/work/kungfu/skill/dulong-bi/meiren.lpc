// meiren.c  毒龙匕法「美人三招」
// kiden

#include <ansi.h>
#include <char.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int extra,dex;
    string msg,weapname;
    object weap;
    mapping attack_val = ([
        "base" : ([ "weapon" : "dagger", ]),//基本功夫类型
        "skill" : ([ "weapon" : "dulong-bi", ]),//高级技能名称
        ]);

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        !me->query("shenlong/meiren"))
        return notify_fail("你还没学会「美人三招」！\n");

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「美人三招」只能对战斗中的对手使用。\n");

    if ( !objectp(weap = me->query_temp("weapon")) || (string)weap->query("skill_type") != "dagger" )
        return notify_fail("只有拿着匕首才可以使用「美人三招」！\n");

    if( (int)me->query_skill("dulong-bi", 1) < 150 )
        return notify_fail("你的毒龙匕法不够娴熟，还使不出「美人三招」。\n");

    if( me->query("neili") < 50 )
        return notify_fail("你的内力不够，无法使用「美人三招」。\n");

    if( (int)me->query_skill("shenlong-xinfa", 1) < 150 )
        return notify_fail("你的神龙心法火候不够，无法使用「美人三招」。\n");

    //美人三招必须激发神龙心法，保护神龙玩家，whuan,2013-10-8
    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "shenlong-xinfa")
        return notify_fail("激发神龙心法才能使用「美人三招」!\n");

    weap = me->query_temp("weapon");
    weapname=(string)weap->name();

    extra = (int)me->query_skill("dulong-bi",1)/4;
    extra += (int)me->query_skill("shenlong-xinfa",1)/5;

    //根据先天身法对额外增加的连招做加成
    dex = (int)me->query("dex")/4; //先天30的开始有加成，每3点先天身法
    dex = dex-7;
    dex = dex +(int)me->query_skill("zhaosheshu",1)/250;
    if(dex<=1) dex=1;
    if(dex>=5) dex=5;

    message_vision(CYN "$N动作妩媚，朝$n"+CYN"微微一笑,使出了"HIM"[美人三招]"NOR+CYN"！\n"NOR,me,target);
    //第一招[贵妃回眸]
    msg =HIY+"第一招："HIR+BNK"[贵妃回眸]"NOR+HIY"!\n"NOR;
    msg+= HIC "$N身子微曲，纤腰轻扭，右足反踢，向$n"+HIC"小腹踹去。\n"+
          "$n"+HIC"后缩相避，$N"+HIC"顺势反过身来，左手搂住$n"+HIC"的头颈，右手竟已握住了"NOR+weapname+HIC"，剑尖对准了$n。"NOR;

    me->add_temp("apply/attack",extra*4/5);
    me->add_temp("apply/damage",extra*4/5);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    me->add_temp("apply/attack",-extra*4/5);
    me->add_temp("apply/damage",-extra*4/5);

    //whuan增加三招，适用于出师过来神龙的
    if( me->query_skill("dulong-bi",1)>=300 )
    {
        if((!userp(me) && !random(3))||userp(me))
        {
            if( objectp(me->query_temp("weapon")) )
                message_vision(CYN "\n$N使完「贵妃回眸」，想起英雄三招，意犹未尽，又出三招！\n"NOR,me,target);
            me->add_temp("apply/attack",extra*4/5);
            me->add_temp("apply/damage",extra/5);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "$N揉身而上，一招扎向$n！");
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "$N得势不饶人，又是一招扎向$n！");
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "$N意犹未尽，再出一招！");
            me->add_temp("apply/attack",-extra*4/5);
            me->add_temp("apply/damage",-extra/5);
        }
    }

    //第二招[小怜横陈]
    msg =HIY+"第二招："HIR+BNK"[小怜横陈]"NOR+HIY"!\n"NOR;
    msg += HIC "$N"+HIC"突然低头自己胸口钻落，顺势一个筋斗在$n"+HIC"胯下钻过，手中"NOR+weapname+HIC"刺向$n。"NOR;
    me->add_temp("apply/attack",extra);
    me->add_temp("apply/damage",extra);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    me->add_temp("apply/attack",-extra);
    me->add_temp("apply/damage",-extra);

    //whuan增加3招，
    if( me->query("grandmaster") && me->query_skill("zhaosheshu",1)>210 
       && me->query_skill("dulong-bi",1)>=600 )
    {
        if( objectp(me->query_temp("weapon")) )
            message_vision(CYN "\n$N使完「小怜横陈」，想起自己历经劫难已是武学大宗师，不由得豪气干云，又出三招！\n"NOR,me,target);
        me->add_temp("apply/attack",extra*dex/5);
        me->add_temp("apply/damage",extra/5);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "$N哈哈狂笑一声，反手扎向$n！");
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "$N身体狂转，如旋风一般，招招指向$n要害！");
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "$N突然定住，左腿定住，右腿伸展，右手直插$n！");
        me->add_temp("apply/attack",-extra*dex/5);
        me->add_temp("apply/damage",-extra/5);
    }

    //第三招[飞燕回翔]
    msg =HIY+"第三招："HIR+BNK"[飞燕回翔]"NOR+HIY"!\n"NOR;
    msg += HIC "$N"+HIC"右足向前轻踢，那"NOR+weapname+HIC"割断缚住的手帕，脱了出来。\n$N"+HIC"右足顺势一勾，在"NOR+weapname+HIC"柄上一点，那"NOR+weapname+HIC"陡向$n"+HIC"疾射过去。"NOR;
    me->add_temp("apply/attack",extra*6/5);
    me->add_temp("apply/damage",extra*6/5);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    me->add_temp("apply/attack",-extra*6/5);
    me->add_temp("apply/damage",-extra*6/5);
    //whuan增加三招，保护纯神龙id
    if(me->query_skill("zhaosheshu",1)>420
       && me->query("family/master_id")=="hong antong"
       && me->query_skill("dulong-bi",1)>=800
       && !me->query("chushi/done"))
    {
        if( objectp(me->query_temp("weapon")) )
        {
            message_vision(CYN "\n$N使完「飞燕回翔」，想起多年召蛇心得，心血来潮，自创三招！\n"NOR,me,target);
        }
        me->add_temp("apply/attack",extra*dex/5);
        me->add_temp("apply/damage",extra/5);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "第一招：灵蛇出洞！");
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "第二招！杯弓蛇影！");
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, "第三招！飞鸟惊蛇！");
        me->add_temp("apply/attack",-extra*dex/5);
        me->add_temp("apply/damage",-extra/5);
    }
    me->add("neili",-50);
    me->start_busy(2+random(3));
    if ( !target->is_busy() ) target->start_busy(1);
    return 1;
}
