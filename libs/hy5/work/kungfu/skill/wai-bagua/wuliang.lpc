// wuliang.c 外八卦「乾坤无量」
// Create for Haiyan 2002

#include <ansi.h>


#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count, acter;
        int i, bsy, lvl;
int damage,attack_time,level;
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「乾坤无量」只能对战斗中的对手使用。\n");

        if (me->query_skill_mapped("cuff") != "wai-bagua") 
                return notify_fail("你没有激发外八卦，无法施展「乾坤无量」。\n"); 

        if ((int)me->query_skill("wai-bagua", 1) < 120)
                return notify_fail("你的外八卦不够娴熟，不会使用「乾坤无量」。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail("「乾坤无量」只能空手施展。\n");  



        if (me->query("neili") < 350)
                return notify_fail("你的真气不够，无法使用「乾坤无量」。\n");




        msg = HIY "$N" HIY "掌法忽然变快，使出外八卦法「乾坤无量」，脚下沿八卦方位疾走，双掌虚虚实实地拍向$n。\n" NOR;

        dp = (target->query_skill("force", 1) + 
             target->query_skill("parry", 1) +
             target->query_skill("martial-cognize", 1)) / 3 +
             target->query_skill("count", 1); 


             acter = 3;


        ap = (me->query_skill("bluesea-force", 1) +
             me->query_skill("wai-bagua", 1) +
             me->query_skill("bagua-bu", 1) + 
             me->query_skill("nei-bagua", 1)) / acter; 

        if ( ap / 2 + random(ap) > dp )
        {
                msg += HIR "$n" HIR "被$N" HIR
                       "这一变化攻了个措手不及，“嘭嘭嘭”连中数掌，" HIR
                       "喷出几口鲜血，脸色变得煞白！\n" NOR;
                count = ap / 28; 
                bsy = 2;
                lvl = me->query_skill("wai-bagua", 1) / 60;
        } else
        {
                msg += HIC "$n" HIC "见$N" HIC "忽然变招，不敢大意，连忙屏息凝气，小心应对，将$N"
                       HIC "的招式尽数拆解。\n" NOR;
                count = 0;
                lvl = 0;
                bsy = 5;
        }
                
        message_combatd(msg, me, target);

        me->add("neili", -150);
if (lvl>9) lvl=9;

                me->add_temp("apply/attack", 100);
me->add_temp("apply/damage", 1200);
        for (i = 0; i < lvl; i++)
        {

         msg = HIG "第"+chinese_number(i+1)+"掌！$N脚下沿八卦方位疾走，双掌虚虚实实地拍向$n。" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        }

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1200);
        me->start_busy(2 + random(bsy));

        return 1;
}

