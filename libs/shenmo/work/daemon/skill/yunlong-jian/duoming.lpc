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
             urkee=me->query("eff_jing"); 
weapon = me->query_temp("weapon"); 
       extra = me->query_skill("yunlong-jian",1); 
            duosword = (int)me->query_skill("yunlong-jian", 1); 
       if ( extra < 200) return notify_fail("你的云龙剑法还不够纯熟！\n"); 
       if( !target ) target = offensive_target(me); 
       if( !target 
      ||      !target->is_character() 
       ||      !me->is_fighting(target) ) 
               return notify_fail("［夺命连环剑］只能对战斗中的对手使用。\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
//if (!wizardp(me))
//                return notify_fail("测试武功，不开放!\n");
        if( (int)me->query("neili") < 900 )
                return notify_fail("你的内力不够！\n");
	
	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("你的云龙神功不够高。\n");

 if(!objectp(weapon = me->query_temp("weapon"))) return 1; 
msg = HIR  "$N轻描淡写，挥尘如意，一瞬间就已使出夺命十三式，手中的"+ weapon->name()+  "轻灵流动 
，就像是河水般的向$n刺出,天地间彷佛充满了杀气！\n\n" NOR; 
      message_vision(msg,me,target); 
           me->add_temp("apply/attack",extra/3); 
           me->add_temp("apply/damage",extra); 
//lmt=13;
       lmt = random(13)+1; 
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
if(target->is_busy()) 
                        { 
               return notify_fail(target->name()+"不为你的剑势所动！\n"); 
                        } 
             else 
            { 
       message_vision(HIW"结果$N大惊失色,为剑势所困！\n"NOR,target); 
       target->start_busy(random(5)+1); 
       } 
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
          if( random(2) && !wizardp(me) ) 
       { 
       msg = HIB "所有的生命和力量，都已被$N这一剑夺去,$n脸上忽然露出种恐惧之极的表情。"; 
msg +=  "\n$N的眼睛里，忽然也露出种恐惧之极的表情，甚至远比$n更恐惧。"; 
msg +=  "\n然后$N就做出件任何人都想不到，任何人都无法想像的事。$N忽然回转了剑锋，割断了$N自己的咽喉。\n\n"NOR; 
  message_vision(msg, me, target); 
me->delete_temp("can_shiwu"); 
               me->unconcious(); 
                      return 1; 
       } 
       else 
          { 
               msg = HIB "所有的生命和力量，都已被$N这一剑夺去,$n脸上忽然露出种恐惧之极的表情。"NOR; 
msg +=  RED"\n「啪」的一声，$N手中的"+ weapon->name()+  "断了!\n\n"NOR; 
            message_vision(msg, me, target); 
me->delete_temp("can_shiwu"); 
if (target->query("qi") > 30000)
{
target->add("qi",-25000);
target->add("eff_qi",-25000);
}else target->unconcious();
//         weapon->unequip(); 
//         destruct(weapon); 
              return 1;   
              } 
               }               
           me->start_busy(lmt/2+1); 
             return 1; 
} 


 