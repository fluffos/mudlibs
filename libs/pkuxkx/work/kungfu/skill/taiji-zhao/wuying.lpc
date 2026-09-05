// taijizhao.c 太极爪----无影爪
// by male
//seagate@pkuxkx 2010/11/03 修改了无影爪的算法

#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int damage, pflv;
    int coefficient;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「无影爪」只能对战斗中的对手使用。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&  
       me->query_skill_mapped("force")!="taiji-shengong" )
        return notify_fail("必须激发太极神功才能使出「无影爪」！\n");

    if( (int)me->query_skill("taiji-zhao", 1) < 300 )
        return notify_fail("你的太极爪不够火候, 使不出无影爪\n");

    if((int)me->query("neili")<2000)
      return notify_fail("你的内力不够,难以驾驭无影爪!\n");
    
    if((int)target->query("max_qi")<1500||
    	 (int)target->query("combat_exp")<(int)me->query("combat_exp")*1.0/5.0)
      return notify_fail(HIY"无影爪乃高手过招时才能使用，非迫不得已不得滥用！\n"NOR);
    
    if( me->query_temp("sl_wuying") )
        return notify_fail("你刚使完「无影爪」绝招，目前气血翻涌，无法再次运用！\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "武当派")
		pflv = 0;
          
    me->start_busy(1+random(4));
	if (me->query_skill("taiji-zhao",1)>600)
	msg = HIC"只见$N"+CYN+"提起手来，五指微曲，行气如九曲珠，运劲似百炼钢，曲中求直，蓄而后发。\n这一爪形如搏兔之鹘，神似扑鼠之猫，若是细看时又全无踪迹可寻。\n"+NOR;
	else
    msg = CYN "$N"+CYN+"运气如九曲珠，运劲似百炼钢，曲中求直，蓄而后发。\n猛然间形如搏兔之鹘，神似捕鼠之猫，随手一抓，着实无踪迹可循。\n"+NOR;
//命中率A级
    if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 2, me, target) )
    {    
        me->set_temp("sl_wuying",1);
        if(!me->query("jiali"))
        	damage = (int)me->query_skill("taiji-zhao", 1);
        else
          damage = (int)me->query_skill("taiji-zhao", 1)+me->query("jiali")*2;

        if( me->query("eff_qi")<me->query("max_qi")/5 ) {
        	coefficient=((int)me->query_skill("taiji-zhao", 1)-200)/100;
        	if (coefficient>5) 
        		coefficient=5;
        	coefficient=coefficient+random(coefficient*2)/3;
        	damage=(damage*coefficient*4)/5+random(damage*coefficient*2)/4;
			if (pflv==4) damage += damage/10;
			else if (pflv>=5) damage += damage/5;
        	F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        	me->add("neili",-1500);
        	call_out("remove_wuying", 6+random(6), me);
        }
        else if( me->query("eff_qi")<me->query("max_qi")/3 ) {
        	coefficient=((int)me->query_skill("taiji-zhao", 1)-400)/100;
        	if (coefficient>5) 
        		coefficient=5;
        	damage=(damage*coefficient*4)/5+random(damage*coefficient*2)/4;
			if (pflv==4) damage += damage/10;
			else if (pflv>=5) damage += damage/5;
        	F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        	me->add("neili",-1000);
        	call_out("remove_wuying", 6+random(6), me);
        } 
        else {
        	damage=damage*2+random(damage*2)/4;
			if (pflv==4) damage += damage/10;
			else if (pflv>=5) damage += damage/5;
			F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        	if ( me->query("jiali") > 900 )
        		me->add("neili",-700);
        	else
        	  me->add("neili",-1*(400+me->query("jiali")/3));
       		call_out("remove_wuying", 10-me->query("con")/10, me);
        }
        
        msg += HIY"没等$p反应过来，这一爪已经狠狠抓在了他周身要害。\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    } else {
        me->start_busy(2+random(2));
        msg += MAG"$p大惊之下，全力往后一挣，一道劲风几乎是紧擦着他的身子掠了过去。\n" NOR;
        message_vision(msg, me, target);
        me->add("neili",-1*(300+random(200)));
    }
    return 1;
}

void remove_wuying(object me)
{
    if (!me) return;
    me->delete_temp("sl_wuying");
    tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「无影爪」绝招了。\n"NOR); 
}
