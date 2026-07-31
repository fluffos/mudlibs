// 无上大力杵法
// by liu 2002

/*

金轮法王眼见徒儿武功明明高于这少年，只是存了怯意，不断遭到对方抢攻，以致处境
窘迫，当下厉声喝道：“快使无上大力杵法！”
    达尔巴应道：“是！”只手握住杵柄，挥舞起来。他单手舞杵，已是神力惊人，此时双
手用劲，连腰力也同时使上了，金刚杵上所发呼呼风声更加响了一倍。这“无上大力杵法”
无甚变化，只是横挥八招，直击八招，一共二八一十六招，但一十六招反覆使将出来，横挥
直击，只逼得杨过远远避开，别说正面交锋，连杵风也是不敢碰上。

*/

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void checking(object me);

int perform(object me, object target)
{
        object weapon;
        int skill, org;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("无上大力杵法只能在战斗中使用。\n");

        skill = me->query_skill("jingang-chu",1);
        weapon = me->query_temp("weapon");

        if( me->query_skill("force") < 100 )
                return notify_fail("你的内功修为不够。\n");

        if( me->query_skill("staff") < 120 )
                return notify_fail("你的杖法修为不够。\n");

        if( me->query_skill_mapped("force") != "longxiang-banruo")
                return notify_fail("你现在所用内功并非龙象般若功！\n");

        if( me->query("neili", 1) < skill*4 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli", 1) < skill*2 )
                return notify_fail("你的精力不够！\n");

        if( (int)me->query_temp("wushang") )
                return notify_fail("你已经发动了无上大力杵法！\n");

        org = me->query_str();

        me->add("neili", -skill*4);
        me->receive_damage("jingli", skill);

        message_vision(HIY "\n$N当下只手握住杵柄，挥舞起来，此时双手用劲，连腰力也同时使上了，"NOR + weapon->name() + HIY"上所发呼呼风声更加响了一倍\n\n这“无上大力杵法”无甚变化，只是横挥八招，直击八招，一共二八一十六招。\n" NOR, me);

        me->add_temp("apply/strength", org*3);

        me->set_temp("wushang", skill/20);

        if ( me->query_skill("staff") < 200 )
        { 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
        else if ( me->query_skill("staff") < 300 )
        {
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
        else
        {
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }

        remove_call_out("checking");
        call_out("checking", 1, me);

        return 1;
}

void checking(object me)
{
        int skill = me->query_skill("staff");

        if(me->query_skill_mapped("staff") != "jingang-chu" || me->query_skill_mapped("force") != "longxiang-banruo" 
        || !objectp(me->query_temp("weapon")) || !me->is_fighting()  || me->query_temp("wushang") <= 0 )
        {
                message_vision(HIG"\n$N将内劲收归丹田，杵劲也渐渐弱了下来。\n"NOR, me);
                me->delete_temp("wushang");
                me->add("neili", skill*2);      //将内劲收归丹田，就该还些内力
                me->add("jingli",-skill);
                me->delete_temp("apply/strength");
                return ;

        }

        if( !living(me) || me->is_ghost() )
        {
                me->delete_temp("wushang");
                me->delete_temp("apply/strength");
                return ;
        }

        me->add_temp("wushang",-1);
        call_out("checking", 1, me);

        return;
}
