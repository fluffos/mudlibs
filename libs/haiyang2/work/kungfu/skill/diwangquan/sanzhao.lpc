//sanzhao.c 夺命三连招 
//rama@hx
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
string *limbs =
({
        "头顶", "颈部", "胸口", "后心", "左肩", "右肩", "左臂",
        "右臂", "左手", "右手", "两肋", "左脸", "腰间", "小腹",
        "左腿", "右腿", "右脸", "左脚", "右脚", "左耳", "右耳"
});
void chkpfm(object me, object target, int amount);
void remove_effect(object me, object target, int amount);
int perform(object me, object target)
{
        object weapon, weapon1;
        int lvl1, lvl2, amount,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("夺命三连招只能对战斗中的对手使用。\n");


        
        if (!living(target))
                return notify_fail("他已经晕倒了，你可以轻易地杀了他！\n");



        if( me->query_skill_mapped("force") != "shenlong-xinfa"  )
                return notify_fail("你所用的并非神龙心法，无法施展夺命三连招！\n");

        if( (lvl1=me->query_skill("shenlong-xinfa", 1)) < 150 )
                return notify_fail("你的神龙心法火候未到，无法施展夺命三连招！\n");

        if( (lvl2=me->query_skill("diwangquan")) < 200 )
                return notify_fail("你这门武功修为不足，还不会使用夺命三连招！\n");

        if( (lvl2 - lvl1) < lvl2 / 4 && lvl1 < 200)
                return notify_fail("夺命三连招需要更精湛的武艺！\n");

        amount = (lvl1+lvl2) / 5;

        if ( amount < 60 ) amount = 60;
        if ( amount > 200 ) amount = 200;

        if( me->query("neili") <= amount*10 )
                return notify_fail("你的内力不够使用夺命三连招！\n");
        if( me->query("jing") <= amount*5 )
                return notify_fail("你的精力不够使用夺命三连招！\n");

        if(!me->query_temp("sanxianjian")){
                me->add_temp("apply/damage", amount*2);
                me->add_temp("apply/attack", amount);
                me->add_temp("apply/dodge", amount);
                me->add_temp("apply/defense", amount);
                me->set_temp("sanxianjian",1);
                me->start_busy(1);
               me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, amount:), amount/15);
        }
        message_vision(HIW "$n抓住$N的后颈，一把提起。$N左手慢慢反转，在$n左腋底搔了一把，\n$n身子软了下来，$N左手拿住$n腋下，右手慢慢回转，抓住$n领口，缓缓\n举起$n的身子，过了自己头顶，向外摔出。\n"NOR, me, target);
        chkpfm(me, target, amount);
        message_vision(HIW "$N俯伏地上，$n伸右足踏住$N的后腰，$N双腿一缩，似欲跪拜，\n右臂却慢慢横掠而出，突然间一个筋斗，向$n的胯下钻去，只一作势\n左手已抓住$n右脚足踝，右手向$n小腹击去。\n"NOR, me, target);
        chkpfm(me, target, amount);
        me->set_temp("sxj-c" , 3);
        message_vision(HIW"$N双臂反在背后，突然双手十指弯起，各成半球之形，身子向后一撞\n十指便抓向$n的胸部，$n向后一缩，$N突然一个倒翻筋斗，身子跃起\n双腿一分，已跨在$n肩头，同时双手按指压住$n太阳穴，食指按眉，中指按眼！\n"NOR, me, target);
        chkpfm(me, target, amount);
        
        

        if((int)target->query("eff_qi") * 100 /(int)target->query("max_qi") <= 20
         &&(int)target->query("qi") * 100 /(int)target->query("max_qi") <= 5
         && me->query_temp("sxj-c") == 3)
        {
                message_vision(HIR "\n$N"+HIR+"这招内劲所注，力道强横之极，$n便如被凌空飞来的重锤扫到，当下喷出一口鲜血！！\n" NOR, me, target);
                if (wizardp(me))
                        tell_object(me,HIR"super attack!!\n"NOR);
                damage=target->query("eff_qi")/2;
                if (damage > 20000) damage=20000;
                target->add("eff_qi",-damage);
                target->add("qi",-damage);
        }
        
        me->start_busy(2);
        return 1;
}
void chkpfm(object me, object target, int amount)
{
        object weapon2 = target->query_temp("weapon");
        string attack_skill, dodge_skill, parry_skill, result, msg = "";
        int ap, dp, pp, damage, level;

        if( !me->is_fighting(target) || !living(target) ) 
                return;

        level = me->query_skill("diwangquan", 1);
        damage = amount+random(level)*2+800;
        ap = COMBAT_D->skill_power(me, "finger", SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;

        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        if( target->is_busy() ) dp /= 3;
        if( dp < 1 ) dp = 1;
        if( random(ap + dp) < dp )
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg();
        }
        else
        {
                pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
                if( target->is_busy() ) pp /= 2;
                if( pp < 1 ) pp = 1;

                if( random(ap + pp) < pp )
                {
                        parry_skill = target->query_skill_mapped("parry");
                        if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
                                parry_skill = "parry";
                        msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
                }
                else 
                {
                        target->receive_damage("qi", damage);
                        target->receive_wound("qi", damage/2);
                        if (me->query_temp("sxj-c") == 3)
                                result = COMBAT_D->damage_msg(damage, "瘀伤");
                        else result = COMBAT_D->damage_msg(damage, "瘀伤");
                        msg += result;
                        result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
                                (int)target->query("max_qi"));
                        msg += "( $n"+result+" )\n";
                        target->start_busy(1);
                }
        }
        result = limbs[random(sizeof(limbs))];
        msg = replace_string( msg, "$l", result );
        message_vision(msg, me, target);
}
void remove_effect(object me, object target, int amount)
{
        if (!me) return;
        me->delete_temp("sanxianjian");
        if( me->is_fighting() && living(target))
        {
                message_vision(HIY "\n$n慢慢的适应了$P夺命三连招的威力。\n" NOR, me, target);
                target->set_temp("sxj-t",time());
        }
        else message_vision(HIY "\n$N收回内劲,招式也恢复了平常。\n" NOR, me);
        me->add_temp("apply/damage", -amount*2);
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/dodge", -amount);
        me->add_temp("apply/defense", -amount);
}

