// san.c 一拍两散
/*
玄寂适才所出那一掌，实是毕
生功力之所聚，叫作“一拍两散”，所谓“两散”，是指拍在石上，石屑四“散”、
拍在人身，魂飞魄“散”。这路掌法就只这么一招，只因掌力太过雄浑，临敌时用
不着使第二招，敌人便已毙命，而这一掌以如此排山倒海般的内力为根基，要想变
招换式，亦非人力之所能。
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int org_jiali, jiali;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("一拍两散只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") )
                return notify_fail("你只能在空手时使用一拍两散！\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("你所用的并非混元一气功，无法施展一拍两散！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 180)
                return notify_fail("你的混元一气功火候未到，无法施展一拍两散！\n");

        if( me->query_skill("banruo-zhang", 1) < 200 )
                return notify_fail("你的般若掌火候未到，无法施展一拍两散！\n");


        if( me->query("max_neili") <= 1000 )
                return notify_fail("你的内力修为不足，劲力不能运发，无法施展一拍两散！\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("jing") < 100  )
                return notify_fail("你的精力不够。\n");
        
        org_jiali = me->query("jiali");

        // I tried the original code with no restriction, a 4Kneili player
        // can make 15K damage in this 1 hit.  With the limit, a 4K
        // neili player can still make 4K damage sometimes. -Chu

        jiali = me->query("neili")/5;  
        if (jiali > 600) jiali = 600;
        jiali = jiali/2 + random(jiali/3);

        me->add_temp("attack",100);
        me->add_temp("damage",200);
        me->set("jiali", jiali);
        me->set("neili", me->query("neili")/3);

        message_vision(
        HIW "\n$N双手合十道：阿弥陀佛，罪过罪过！双掌自外向里转了个圆圈，缓缓向$n推了过来。！\n"
        +"$N掌力未到，$n已感胸口呼吸不畅，顷刻之间，$N的掌力如怒潮般汹涌而至！！！\n" NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add_temp("attack",-100);
        me->add_temp("damage",-200);
        me->set("jing", me->query("jing")/5);
        me->set("neili", me->query("neili")/3);
        me->set("jiali", org_jiali);
        me->start_busy(1+random(3));
//        target->kill_ob(me);
        return 1;
}
