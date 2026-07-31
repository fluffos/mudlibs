//modify by Wuyou@Sanjie

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
//object weapon;
        string str;
        int extra;
        object victim;              // 对手的武器
        int i,attack_time,skill,damage,lvl;   
        if( !target ) target = offensive_target(me);
        
             if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "club")
                return notify_fail("你使用的武器不对！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("只能在战斗中对对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("fengbo-cha", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jinghai-force", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "fengbo-cha")
          //      return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "jinghai-force")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通崆峒武学，使出了崆峒的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
                                
                        

        msg = HIW "\n$N突然吞云吐雾，化作一条神龙飞升天际。$N在云中急速穿梭，使出"HIC"龙形搏击"HIW"终极奥义"HIR"云龙九现！" NOR;
        message_vision(msg, me, target);
        damage = 10+(int)me->query_skill("dragonfight",1);
 if (random(2)==0) target->start_busy(2);
me->add_temp("apply/attack", 180);
me->add_temp("apply/damage", 2800);
                                msg = HIY "〓赑屃驮碑〓" NOR;
                                msg += MAG "赑屃身负石碑，缓缓而来！" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIW "〓螭吻望月〓" NOR;
                                msg += HIB "螭吻眼望千里之外，悠然而来！" NOR;
                            	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIG "〓饕餮吞天〓" NOR;
                                msg += HIC "饕餮吃尽天下美食，满意而来！" NOR;
                              	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIR "〓睚眦怒杀〓" NOR;
                                msg += WHT "睚眦杀人无数，双手血腥，忿忿而来！" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIC "〓狴犴憎恶〓" NOR;
                                msg += CYN "狴犴视恶如仇，大公无私，威然而来！" NOR;
                           	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIR "〓金猊吐火〓" NOR;
                                msg += HIM "金猊嗜好烟火，身携真火而来！" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = WHT "〓趴蝮戏水〓" NOR;
                                msg += HIY "趴蝮翻江倒海，隐于水中，携雨而来！" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = MAG "〓椒图守穴〓" NOR;
                                msg += HIW "椒图闭门不出，来去匆匆！" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIB "〓蒲牢长鸣〓" NOR;
                                msg += HIG "蒲牢通晓乐理，边走边唱！" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


me->add_temp("apply/attack", -180);
me->add_temp("apply/damage", -2800); 

     msg = HIR
"\n$N默运靖海神功，身形忽向斜后飞出，$n正要追击，却不料$N手中放出一道绚丽的光环，顿时天空中出现一个大力魔神，只见魔神手举天庭神棒，\n"
"如闪电，如雷火一般直贯$n胸前，仓惶间$n早已六神无主，不知如何是好\n" NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

              msg = HIY "天魔一击顿时从$n的胸口直贯而过，$n的胸口顿时血流如注，大呼"+HIW"天既如此，我耐如何"+HIR"，$n现在已是风中残烛，命在旦夕！\n" NOR;
target->receive_damage("qi", (me->query_skill("fengbo-cha",1)*8),me);
target->receive_wound("qi", (me->query_skill("jinghai-force",1)*8),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
        message_vision(msg, me, target);
        message_vision(HIC"$N挥展开来，左一叉，右一叉，幻出无数大小光环向$n绕去。
虽看起来柔弱无力，却宛若秋波般连绵不绝，实是暗藏杀机！\n\n"NOR,me, target);

message_vision(HIR"$N突然用手在对天一指，出现三道真火，手中"NOR+weapon->name()+
        HIR"顿时间红光上涌，焚天炙地，神龙吐信般飞速向$n舞来。\n"NOR,me,target);
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
        me->add_temp("apply/attack", 200);  
 me->add_temp("apply/damage", 2800); 
	msg =HIR"第一道真火 贪业之火"NOR;    
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =HIR"第二道真火 嗔心之火"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 	msg =HIR"第三道真火 愚痴之火"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_damage("qi", (me->query_skill("fengbo-cha",1)*8),me);
target->receive_wound("qi", (me->query_skill("jinghai-force",1)*8),me); 
        COMBAT_D->report_status(target);
message_vision(HIR"\n只见$n硬生生的接住$N这技绝招，顿感喉头一甜，[噗]的一声吐出一口鲜血。\n\n"NOR,me, target);  
        me->add_temp("apply/attack", -200);
 me->add_temp("apply/damage", -2800); 

        }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        }
//        message_vision(msg, me, target);


me->start_busy(4);
        return 1;
}


