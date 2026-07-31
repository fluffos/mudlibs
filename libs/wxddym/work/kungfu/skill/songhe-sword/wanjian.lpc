#include <ansi.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "万剑决"; }
int perform(object me, object target)
{
        object weapon;
              int i,j,k,u,damage;
              weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");
        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("不是蜀山的不能用「万剑决」！\n");

         if(me->query("shushan/wanjian_perform")!=1)
                return notify_fail("你还没领会「万剑决」！\n");
        
        if((int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力太差。\n");
        
        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");
        
        if((int)me->query("jing") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
	  
        if((int)me->query_skill("zuixian-steps", 1) < 120)
        	    return notify_fail("你的醉仙望月步等级不够，不能使用这一招！\n");
	  k=(int)me->query_skill("sword");
         j=(int)target->query_skill("dodge");
        if(k<100)        
                return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");
u=k/10;
if (u>100) u=100;
//me->delete("env/brief_message");
//target->delete("env/brief_message");
message_vision(HIC"\n$N仰天大喝了一声：\n"NOR,me,target);
message_vision(HIW"\n万～～～～剑～～～～决\n"NOR,me,target);
message_vision(HIC"\n一刹那间千万剑光破空而来，劈面罩向$n\n"NOR,me,target);
for (i=0;i<=u;i++)
{
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR, HIC"\n一刹那间千万剑光破空而来，劈面罩向$n\n"NOR);
if (k / 2 + random(k) > j)
{
message_vision(HIY"\n$n一个不慎，中了一剑\n"NOR,me,target);
damage=k/2+random(k/2);
target->receive_damage("qi",damage);
target->receive_wound("qi",damage/3);
COMBAT_D->report_status(target);
me->receive_damage("jing", 100);
me->add("neili", -100);
}
else {
message_vision(HIY"\n$n左跳右闪，好不容易避开了一轮剑雨\n"NOR,me,target);
me->receive_damage("jing", 100);
me->add("neili", -100);
}
}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
    me->start_busy(3);
return 1;
}
