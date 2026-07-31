// 2002-8-10

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
         int str, dex, skill;
        string weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「连环三招」只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("「连环三招」需空手才能施展！\n");

        if( me->query_skill_mapped("strike") != "xiaohun-zhang" )
                return notify_fail("你所用的并非黯然销魂掌，不能施展连环三招！\n");

        if( me->query_skill_prepared("strike") != "xiaohun-zhang" )
                return notify_fail("你所备的并非黯然销魂掌，不能施展连环三招！\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" )
                return notify_fail("你所用的并非玉女心经，施展不出连环三招！\n");

        if( me->query_skill("force") < 140 )
                return notify_fail("你的玉女心经火候未到，无法施展连环三招！\n");

        if( me->query_skill("strike") < 135 )
                return notify_fail("「连环三招」需要精湛的黯然销魂掌方能有效施展！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够使用连环三招！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够使用连环三招！\n");

        message_vision(HIG "$N退步避开，跟着「魂不守舍」、「倒行逆施」、「若有所失」连出三招！\n\n" NOR, me, target);
            message_vision(HIW "紧跟着是一招「行尸走肉」，这一脚发出时恍恍惚惚，隐隐约约，若有若无，$n那里避得过了？\n\n" NOR, me, target);
            message_vision(HIR "$n只觉$N的内力如排山倒海一般袭来，$n挡无可挡，避无可避!\n\n" NOR, me, target);

        str = me->query_str();
      me->add_temp("apply/strength", str*3);
        me->add_temp("apply/attack",100);
        me->set_temp("lianhuan",1);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

      me->delete_temp("apply/strength", -str*3);
       me->delete_temp("apply/attack",-100);
        me->delete_temp("lianhuan");

        me->add("neili", -150);
       me->add("jingli", -150);
       me->start_busy( 1+random(3) );

        return 1;
}
