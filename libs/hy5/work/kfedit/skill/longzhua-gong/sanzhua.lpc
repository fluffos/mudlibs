// tie@fengyun
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
        int skill;
        int damage, ap, dp, p;
        float at;
        string dodge_skill;        
        
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("longzhua-gong");
       if( (int)me->query_skill("longzhua-gong", 1) < 100 )
		return notify_fail("你的龙爪功不够娴熟!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「三爪功」只能空手使用。\n");		
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力不足！\n");     

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［三爪］只能对战斗中的对手使用。\n");
//	me->add("force_factor",extra/3);
//	orforce = (int) me->query("force");
//	me->add("force",extra/3*100);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出龙爪功独步天下的［三爪］，身形加快！\n" NOR;
	message_vision(msg,me,target);
	msg = HIB  "左攻，第一爪-！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "右攻，第二爪---！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "跃起，第三爪------！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//	me->set("force_factor",0);
//	/me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);
	me->start_busy(2);
        me->add("neili", -50);

if (me->query_skill("longzhua-gong",1)>200 && me->query("neili")>500)
{
 msg = HIY "\n$N双手合十互击，陡然向外一分，双掌顿时变得轻灵飘逸，灵动异常，霎时幻起漫天的掌影。\n" NOR;
        message_vision(msg, me, target);

        msg = HIR "$n只觉得四周都是$N的身影，不由得慌乱起来。\n" NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 )
	{
		msg +=  HIG "结果$p被$P攻了个措手不及! \n" NOR;
		target->start_busy(5);
			}
	else
	{
		msg += HIM "可是$p看破了$P的企图，并没有上当。\n" NOR;
	}
	message_combatd(msg, me, target);	
	
}


if (me->query_skill("longzhua-gong",1)>300 && me->query("neili")>500)
{
   msg = MAG "\n只见$N面显庄严，一式「"HIY"佛光普照"MAG"」，提一口真气，飘身而上，半空中手掌交错，一股内劲狭带着热
浪，如风如火，似雷似电，这一招拍出，击向$n，招式平平淡淡，一成不变，但却挡无可挡，避无可避！\n"NOR;
        ap = (int)me->query_skill("longzhua-gong") * (int)me->query("neili") * (int)me->query_str();
        dp = (int)target->query_skill("force", 1) * (int)target->query("neili") * (int)target->query_con();
        ap *= (int)me->query("combat_exp")/200;
        dp *= (int)target->query("combat_exp")/200;    
        ap /= 1000;
        dp /= 1000;

        me->start_busy(3);        
        if(random(ap) > dp/2 || random(3)==0){
                target->start_busy(random(3));
                damage = me->query_skill("yijinjing",1) + me->query_skill("longzhua-gong", 1);
                damage *= 3;
                if(target->query("neili") < 1) at = 5;
                else at = me->query("neili") / target->query("neili");
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                damage -= target->query_temp("apply/armor")*2;
                if (damage < 0) damage = 0;
                if (damage > 35500) damage = 35500;
                damage = damage + random(damage / 2)+100;
                if (target->query_skill_mapped("force") == "yijinjing" &&
                    target->query_skill("yijinjing", 1) > 100){
                      tell_object(me, HIY"\n哪知你一掌打在"+target->name()+"身上，却犹如江河入海，又如水乳交融，劲力登时无影无踪！\n"NOR);
                      msg += "猛听得砰然一声大响，$N已打中在$n胸口，只道$p定然全身骨骼粉碎。哪知一掌过去，
$n脸露讶色，竟好端端的站着，$N却是脸如死灰，手掌微微发抖！\n";
                      target->start_busy(2);
                      message_vision(msg, me, target);

                      return 1;
                      }
                if ((target->query_skill_mapped("force") == "yijinjing" 
                     || target->query_skill_mapped("force") == "yinyun-ziqi" )
                     && target->query_temp("fanzhen")) 
                        damage /= 2;
                target->add("qi", -damage);
                target->receive_wound("qi", damage/3);
                target->add("neili", -damage/5);
                me->add("combat_exp", (int)me->query_int()*2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "瘀伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                }
        else {
//              msg += CYN"\n$p急忙飞身向后跃出数丈，才勉强躲闪过这致命一击！\n"NOR;
                dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }

        message_vision(msg, me, target);
}	

if (me->query_skill("longzhua-gong",1)>500 && me->query("neili")>500)
{
  damage = (int)me->query_skill("longzhua-gong", 1);
      damage = (int)me->query_skill("yijinjing", 1)+damage;
      
      
        switch(random(4)) {
        case 0:
           { msg = GRN"
$N突然面带微笑，手掌微张，掌中涌出一股劲风，恍忽是一片片嫩绿的"CYN"「芳草」"GRN"，直向$n的面颊飞去！\n"NOR;
                damage = damage/3 + random(damage/3);               
                me->set_temp("nl", -120);} break;
          
        case 1:        
          { msg = MAG"
只听$N“哎呀”一声，身行象前跌去，突然一道蓝光闪现，破空之声中几朵"WHT"「清兰」"MAG"向$n的胸前飞去！\n"NOR;             
                damage = damage/3 + random(damage/2);                
                me->set_temp("nl", -180);} break;

        case 2:        
          { msg = HIY"
突然$N双手莫念经文，$n忽然觉得眼前人影如山，忽而排山倒海，忽而忽而高山流水，
觉得一切都在离$n远去，跟着一股醉人的"GRN"「秋菊」"HIY"清香扑鼻而来。。。\n"NOR;           
                damage = damage/2 + random(damage/3);                                
                me->set_temp("nl", -220);} break;
        
        case 3:
         { msg = HIW"
突然$N大吼一声，顿时把$n瞎了一个激灵，之间$N在眉宇之间布满了一层薄霜，
双目冷冷的瞪着$n，接着僧袍一卷，一朵朵绽开的"MAG"「寒梅」"HIW"向$n满面扑来！\n"NOR;          
                damage = damage/2 + random(damage/2);               
                me->set_temp("nl", -300);} break;
        }
    if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2 ||
        random(3)==0)
            {
            	damage=damage+500;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);

                me->delete_temp("nl");
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                } 
            else 
               {       
                me->start_busy(3);

                me->delete_temp("nl");
                message_vision(msg, me, target);               
                msg = CYN" 可是$p一个巧云翻身，远远的躲了开去。\n"NOR;
               }
            message_vision(msg, me, target);	
}		
	return 1;
}
