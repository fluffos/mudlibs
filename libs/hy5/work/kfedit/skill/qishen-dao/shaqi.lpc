// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        object weapon,ob;
        extra = me->query_skill("qishen-dao",1);
        
        if( (int)me->query("neili") < 300 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("blade") < 150 ||
            me->query_skill_mapped("blade") != "qishen-dao")
                return notify_fail("你的「泣神刀法」还不到家，无法使用「杀气腾腾」！\n");

        if((int)me->query_skill("qishen-dao", 1) < 200)
                return notify_fail("你的此项武功等级不够』！\n");


        dodskill = (string) me->query_skill_mapped("dodge");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「杀气腾腾」只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");

//        me->clean_up_enemy();
        ob = me->select_opponent();
        if( !target->is_killing(me) ) me->kill_ob(target);
        msg = HIW  "$N神气贯通，将泣神刀法八式一气呵成！\n\n"HIY"第一式：面目全非！\n\n$N手中$w斜指，一招「面目全非」，刀劲裹着刀锋，向$n的$l撩去。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第二式：家破人亡！\n\n"HIY"$N一招「家破人亡」，$w被右手反握，交叉挥动，连人卷成尖锥刀网，向$n直射而来。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第三式：血海深仇！\n\n"HIY"$N展身虚步，提腰跃落，一招「血海深仇」，刀锋一卷，拦腰斩向$n。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第四式：骨肉分离！\n\n"HIY"$N一招「骨肉分离」，$w大开大阖，自上而下划出一个闪电，直劈向$n。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第五式：切肤之痛！\n\n"HIY"$N手中$w一沉，一招「切肤之痛」，双手持刃拦腰反切，砍向$n的胸口。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第六式：天愁地惨！\n\n"HIY"$N一招「天愁地惨」，戾气冲天挥舞，人刀卷缠黑云，齐齐罩向$n。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第七式：鬼哭神号！\n\n"HIY"$N一招「鬼哭神号」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第八式：惊天泣神！\n\n"HIY"$N盘身驻地，一招「惊天泣神」，挥出一片流光般的刀影，向$n的全身涌去。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -500);
        me->start_busy(4);
        return 1;
}

