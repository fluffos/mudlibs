// yaoyuan@sjfy 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 int perform(object me, object target) 
{ 
       string msg; 
       int extra,i,lmt,duosword,urkee; 
       object weapon; 
	int damage;
             urkee=me->query("eff_jing"); 
weapon = me->query_temp("weapon"); 
       extra = me->query_skill("yunlong-jian",1); 
            duosword = (int)me->query_skill("yunlong-jian", 1); 
        if( !target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("yunlong-jian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

       if( !wizardp(me) &&(int)me->query_skill("yunlong-zhua", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("yunlong-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "yunlong-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

        msg = HBWHT "$N贯通云龙武学，使出了云龙的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
me->start_busy(4);
        message_vision(msg, me, target);   


 if(!objectp(weapon = me->query_temp("weapon"))) return 1; 
msg = HIR  "$N轻描淡写，挥尘如意，一瞬间就已使出夺命十三式，手中的"+ weapon->name()+  "轻灵流动 
，就像是河水般的向$n刺出,天地间彷佛充满了杀气！\n\n" NOR; 
      message_vision(msg,me,target); 
           me->add_temp("apply/attack",extra/3); 
           me->add_temp("apply/damage",extra); 
//lmt=13;
       lmt = 13; 
if (random(3)==0) target->start_busy(3);       
       for(i=1;i<=lmt;i++) 
       { 
if(!objectp(weapon = me->query_temp("weapon")) ) continue; 
       msg = HIR "------>>>>>>第"+chinese_number(i)+"剑<<<<<<------" NOR; 
        COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR,msg); 
       } 
       msg = CYN "\n\n$N的第"+chinese_number(i-1)+"剑刺出后，所有的变化都已穷尽，又像是流水已到尽头，剑 
势也慢了，很慢。\n"NOR; 
      message_vision(msg,me,target); 
           me->add_temp("apply/attack",-extra/3); 
           me->add_temp("apply/damage",-extra); 
 me->add("neili", -(lmt*50+50));
if (duosword >300 &&
me->query("neili") > 500
&& lmt < 13
&& (int)me->query_skill("yunlong-shengong", 1)>250 )
{
	weapon = me->query_temp("weapon");
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra*5);
	msg = HIW  "紧跟着$N手中的"+ weapon->name()+  "再次出鞘，就化做一道光华击向$n，一道弧形的光华：灿烂、辉煌、美丽。\n" + HIG"光华在闪动、变幻、高高在上，轻云飘忽，$n只觉得这道光华彷佛就在自己眉睫
间，却又不能确定它在那里？它的变化，几乎已超越了人类能力的极限，几乎已令人无法置信。" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "可是它确实在那里，而且无处不在。可是就在$n已确定它存在时，它忽然又不见
了。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT"又奇迹般忽然出现，又奇迹般忽然消失。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "所有的动作和变化，都已在一刹那间完成，终止。就像是流星，却又像是闪电，却又比
流星和闪电更接近奇迹。因为催动这变化的力量，是由$N发出来的。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",extra/3);
       	me->add_temp("apply/damage",-extra*5);
me->add("neili",-400);
}
if( duosword > 250 && lmt == 13 ) 
           { 
               msg = CYN  "虽然慢，却还是在变，$N忽然一剑挥出，不著边际，不成章法。"; 
msg +=  HIR "\n然后$N就刺出了夺命连环剑的第十四剑------------------------\n" NOR;       
           me->add_temp("apply/attack",extra); 
           me->add_temp("apply/damage",extra*3); 
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
           me->add_temp("apply/attack",-extra); 
           me->add_temp("apply/damage",-extra*3); 
message_vision( RED "$N的剑气和杀气都很重，宛如满天岛云密布。这一剑刺出，忽然间就将满天乌云都拨开了，现出了阳光。\n" NOR ,me,target); 
	message_vision( YEL "\n这一剑刺出，所有的变化才真的已到了穷尽，本已到了尽头的流水，现在就像是已完全枯竭，$N的力也已竭了。\n\n" NOR ,me,target); 
         me->set_temp("can_shiwu",1);   
              } 


if( duosword > 300 && me->query_temp("can_shiwu")) 
           { 
                msg = HIW "\n可是就在这时候，$N手中的剑忽然又起了奇异的震动,天地万物忽然全都静止，绝对静止，\n"; 
                 msg +="没有变化，没有生机!这一剑带来的，只有死!只有「死」，才是所有一切的终结，才是\n"; 
                 msg +="真正的终结!流水乾枯，变化穷尽，生命终结，万物灭亡!这才是「夺命连环剑」真正的精粹!\n"; 
                 msg +="这才是真正夺命的一剑!这一剑赫然已经是第十五剑！\n\n" NOR; 
                                    message_vision(msg, me, target); 
          if( random(10)==0) 
       { 
               msg = HIB "所有的生命和力量，都已被$N这一剑夺去,$n脸上忽然露出种恐惧之极的表情。"NOR; 
msg +=  RED"\n「啪」的一声，$N手中的"+ weapon->name()+  "掉了!\n\n"NOR; 
            message_vision(msg, me, target); 
me->delete_temp("can_shiwu"); 
            target->unconcious(); 
//         weapon->unequip(); 
//         destruct(weapon); 
              return 1;   
       } 
       else 
          { 
me->delete_temp("can_shiwu"); 
    weapon->unequip(); 
    msg = RED "\n$N心里突然明白了这剑的可怕,突然弃剑换掌!! **凝血神抓**，一抓抓来，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 ) {  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(
		target->query_temp("weapon"))->move(environment(target));
		target->start_busy(3);
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
	}
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{

		target->start_busy(random(4)+1);
		
		damage = (int)me->query_skill("yunlong-shengong", 1);
		
		damage = damage*5 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);

        }
       return 1; 

              } 
               }               
me->start_busy(4);
//           me->start_busy(lmt/2+1); 
             return 1; 
} 


 