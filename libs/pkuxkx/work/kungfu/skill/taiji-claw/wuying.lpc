// taijizhao.c 太极爪----无影爪
// by male
//seagate@pkuxkx 2010/11/03 修改了无影爪的算法

#include <ansi.h>
#include <combat.h>
#include "/newbiequest/combat.h"

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    int damage;
    int coefficient;

    if( !target ) target = offensive_target(me);
    if( !target ||      !target->is_character() ||      !me->is_fighting(target) )
        return notify_fail("「无影爪」只能对战斗中的对手使用。\n");
    if( (int)me->query_skill("taiji-claw", 1) <300 )
        return notify_fail("你的太极爪不够火候, 使不出无影爪\n");
    msg="";
    
    if((int)me->query("neili")<3000)
      return notify_fail("你的内力不够,难以驾驭无影爪!\n");
    
    if((int)target->query("max_qi")<3000||
    	 (int)target->query("combat_exp")<(int)me->query("combat_exp")*3.0/5.0)
      return notify_fail(HIY"无影爪乃高手过招时才能使用，非迫不得已不得滥用！\n"NOR);
    
    if( me->query_temp("sl_wuying") )
        return notify_fail("你刚使完「无影爪」绝招，目前气血翻涌，无法再次运用！\n");
          

    me->start_busy(1+random(4));
    if( combat_ratio(combat_coef(me->query("combat_exp"),0),combat_coef(target->query("combat_exp"),0),450) )
    {    
        me->set_temp("sl_wuying",1);
        if(!me->query("jiali"))
        	damage = (int)me->query_skill("taiji-claw", 1);
        else
          damage = (int)me->query_skill("taiji-claw", 1)+me->query("jiali")*2;

        if(me->query("qi")<me->query("max_qi")/8&&
        	 me->query("eff_qi")<me->query("max_qi")*4/5) {
    	    msg += HIR "$N一声长啸，双手幻化为千万爪影, 霎那间,爪影遍布$n周身,$n那里见过这种阵势？马上就被惊呆了\n";
        	coefficient=((int)me->query_skill("taiji-claw", 1)-200)/100;
        	if (coefficient>5) 
        		coefficient=5;
        	coefficient=coefficient+random(coefficient*2)/3;
        	damage=(damage*coefficient*4)/5+random(damage*coefficient*2)/4;
        	target->receive_damage("qi", damage, me);
        	target->receive_wound("qi", damage/2, me);
        	me->add("neili",-3000);
        	call_out("remove_effect", 8+random(8), me);
        }
        else if(me->query("qi")<me->query("max_qi")/4&&
        	 me->query("eff_qi")<me->query("max_qi")*9/10) {
    	    msg += HIM "$N一声长啸，双手幻化为千万爪影, 霎那间,爪影遍布$n周身,$n那里见过这种阵势？马上就被惊呆了\n";
        	coefficient=((int)me->query_skill("taiji-claw", 1)-400)/100;
        	if (coefficient>5) 
        		coefficient=5;
        	damage=(damage*coefficient*4)/5+random(damage*coefficient*2)/4;
        	target->receive_damage("qi", damage, me);
        	target->receive_wound("qi", damage/2, me);
        	me->add("neili",-2000);
        	remove_call_out("remove_effect");
        	call_out("remove_effect", 8+random(6), me);
        } 
        else {
        	msg += HIW "$N一声长啸，双手幻化为千万爪影, 霎那间,爪影遍布$n周身,$n那里见过这种阵势？马上就被惊呆了\n";
        	damage=damage*2+random(damage*2)/4;
        	target->receive_damage("qi", damage, me);
        	target->receive_wound("qi", damage/2, me);
        	me->add("neili",-1*(450+me->query("jiali")/2));
        	remove_call_out("remove_effect");
       		call_out("remove_effect", 11-me->query("con")/10, me);
        }
        msg += HIY"结果$p竟然忘了防御,被抓了个正着。\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    } else {
        me->start_busy(2+random(2));
        msg += MAG"可是$p一凝神,回过神来看破了$P的企图，并没有上当。\n" NOR;
        message_vision(msg, me, target);
        me->add("neili",-1*(300+random(300)));
    }
    return 1;
}

void remove_effect(object me)
{
    if (!me) return;
    me->delete_temp("sl_wuying");
    tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「无影爪」绝招了。\n"NOR); 
}
