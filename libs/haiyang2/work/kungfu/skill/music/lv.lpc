#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
         extra = me->query_skill("music",1);
        if ( extra < 180) return notify_fail("你的琴道还不够纯熟！\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");

    if( (int)me->query_skill("xuantian-wuji", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");
                
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［乐律十二律］只能对战斗中的对手使用。\n");

        tmp=tmp/2;       
        if (extra> 200) extra=200;
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra*3);
    msg = HIW "\n\n$N大喝一声，赫然使出『--乐律十二律--』!!\n$N发出12道音波 由缓至快向$n"+HIW"袭来！\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR  "★大吕★见★太簇★\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "★夹钟★破★姑洗★\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG  "★中吕★参★蕤宾★\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "★林钟★附★夷则★\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIC  "★南吕★射★无射★\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = CYN  "★应钟★赶★黄钟★\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "\n$N"+HIC"轻拨琴弦，琴声清丽，平正中和，隐隐有王者之意！\n" NOR;
		msg += HIC "忽听得空中振翼之声大作，各处飞来无数雀鸟，或止歇树巅，或上下翱翔，毛羽缤纷，蔚为奇观。\n\n"NOR;
        message_vision(msg, me);
 if (random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) {
            message_vision(HIY"一阵鸟凤和鸾的琴音，令$N"+HIY"痛苦地捂着双耳，脚步漂浮，神智亦开始变得迷糊。\n"NOR, target); 
			target->receive_wound("qi", me->query_skill("music",1)*3+800);
            target->start_busy(3);
}            
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra*3);

me->add("neili",-380);
                me->start_busy(3);
        return 1;
}   
