// qunmo.c  群魔乱舞

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


int perform(object me,object target)
{
//          object weapon = me->query_temp("weapon");
        int attack, defense;
 	string msg;
	int extra;
	int i,a;
	object weapon;
	       
        if (!target) target = offensive_target(me);
        if (!target || !me->is_fighting(target))
                return notify_fail("只能对战斗中的对手使用『群魔乱舞』。\n");                

        if (me->query_skill("kongming-quan", 1) < 70)
                return notify_fail("你的空明拳尚不纯熟还是不要乱用『群魔乱舞』。\n");        
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用『群魔乱舞』！\n");  
        if (me->query("neili") < 100)
                return notify_fail("你现在内力不足，不能使用拼命打法！\n");
        if (me->query_temp("kongming_berserk"))
                return notify_fail("你目前正在使用『群魔乱舞』！\n");      

        if ((int)me->query_skill("xiantian-qigong", 1) <  100 )
                return notify_fail("你的先天气功火候不到。\n");

        message_vision(HIR"\n$N突然如痴如狂，挥舞着双臂，四周笼罩着拳风。\n"NOR, me);
        me->add("neili", -80); 
        me->add("jing", -30);      
        me->set_temp("kongming_berserk", me->query_skill("kongming-quan", 1) / 5);
        attack = me->query_temp("apply/attack");
        defense = me->query_temp("apply/defense") / 2;
if (attack <= 100) attack=100;
	if (defense <= 100) defense=100;
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/defense", -defense);

	extra = me->query_skill("kongming-quan",1) / 20;
	extra += me->query_skill("xiantian-qigong",1) /20;


	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIG "空明拳 ! 虚虚实实，变化莫测！．．．．\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 12) a=12;
	for(i=0;i<a;i++)
	{
	msg = HIW "$N一拳打出,虚虚实实，变化莫测！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add("neili", - 50 * i);
	me->start_busy(3);


        call_out("remove_effect", 1, me, target, attack, defense);
        return 1;
}

void remove_effect(object me, object target, int attack, int defense)
{
        if (objectp(me)) {
                if (objectp(target) && me->query_temp("kongming_berserk") && me->is_fighting(target)) {
                        me->add_temp("kongming_berserk", -1);
                        call_out("remove_effect", 1, me, target, attack, defense);
                        return;
                }
                me->add_temp("apply/attack", - attack);
                me->add_temp("apply/defense", defense);
                me->delete_temp("kongming_berserk");
                tell_object(me, "你发狂般地乱打了一阵后，决定先歇一歇。\n");
        }
}

