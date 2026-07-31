// Last Modified by winder on Sep. 12 2001
// zhuihun.c 一剑追魂

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "百鸟追魂"
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

        int ap, dp, fp, pp,count;
      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail(PNAME "只能在战斗中对对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("baniao-jian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("honghua-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通红花会武学，使出了红花会的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
	

	//damage = (int)me->query_skill("force", 1);
	damage = (int)me->query_skill("bainiao-jian", 1);

			
	msg = CYN "$N微微一笑，猛吸一口气，飞身跃起，"+weapon->name()+CYN"如无常索命索，绞向$n。\n"NOR;
         damage += 200;
	if (random(me->query_skill("force")) > target->query_skill("force")/3 || random(3)==0)
	{
		target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
		target->start_busy(3);
		//me->add("neili", -200);
		msg += HIR "$n只觉剑势如夜幕般铺天盖地般压来，一时间眼前一花，两耳轰鸣，无从招架！！\n"NOR;
		//me->start_busy(1);
	} else 
	{
		msg += CYN"可是$p见机极快，飞身跃出了$P的剑网。\n"NOR;
		//me->add("neili", -200);
		//me->start_busy(1+random(1));
	}
	message_combatd(msg, me, target);


 
 

         damage = random((int)me->query_skill("bainiao-jian"));
 message_vision(HIC"$N使出百鸟剑法的要旨「名可名 非常名」，连续几剑，浑无招式痕迹可循向$n刺去！\n"NOR,me,target, "");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                target->receive_damege("qi", damage,me);
        target->receive_wound("qi", damage,me);
     message_vision(HIC"$N酣畅淋漓地使了这招，剑意舒展.\n"NOR,me,target, "");   





                msg = HIW "$N陡然出招变慢，手中的"+ weapon->query("name")+ HIW"竟画出一个太极，由中分成阴阳两极！           
         $N默默念道：“太极分两仪！\n"NOR;

                message_vision(msg, me, target);
        
 	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                        msg = HIR "$n只觉得阴阳两极之势直逼过来，不知道如何躲闪，顿时被$N的"+ weapon->query("name")+ HIR"击了个正着！\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "只见$n成竹在胸，轻松将其化解！\n\n"NOR;
                        message_vision(msg, me, target);

                }




                msg = HIW "阴阳两极又随手中的"+ weapon->query("name")+ HIW"生出四象，从四个方向攻来！           
         $N默默念道：“两仪生四象！\n"NOR;

                message_vision(msg, me, target);

	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                        msg = HIR "$n一不留神，被$N打的无还手之力！\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n镇定自若，将$N的攻势一一化解！\n\n"NOR;
                        message_vision(msg, me, target);

                }





                msg = HIW "四象随即又生变化化为八卦！           
         $N默默念道：“四象化八卦！\n"NOR;
       
                message_vision(msg, me, target);
        
	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                        msg = HIR "只见剑影从乾、坤、震、坎、艮、离、巽、兑八方而至，$n立刻手忙脚乱，八个方位不能兼顾！\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n左挡右闪，毫不容易将其化解！\n\n"NOR;
                        message_vision(msg, me, target);

                }




                msg = HIW "八卦又渐渐合而为一，形成一个太极！           
         $N默默念道：“八卦合太极！\n"NOR;
       
                message_vision(msg, me, target);
        
                	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                                               msg = HIR "一个巨大的太极向$n罩了过来，$n刚喘口气，又立刻被罩了个正着！\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
 
                }
                else
                {
                        msg = HIG "$n一招正中太极中心将其化解！\n\n"NOR;
                        message_vision(msg, me, target);

                }

      me->add_temp("apply/attack", 180);    
        me->add_temp("apply/damage", 2800);

 if(!target->is_busy()) target->start_busy(2);
        message_vision(RED  "$N腾空跃起，变换身形，瞬移北斗七星位，手中的"+ weapon->name() +RED"划出森然剑气，剑剑逼向$n ！\n" NOR, me, target);
        
        msg =  HIC  "「妖气冲天」，$N手中"+ weapon->name() +HIC"带着一阵寒意直刺$n！" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIR  "\n「魂飞魄散」，$N手中"+ weapon->name() +HIR"带着冷冷的剑气斜刺$n！"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIY  "\n「妖兽噬天」，$N手中"+ weapon->name() +HIY"落叶般横扫$n！"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIW  "\n「十万神魔」，$N手中"+ weapon->name() +HIW"闪电般猛劈$n！"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=MAG  "\n「群魔乱舞」，$N手中"+ weapon->name() +MAG"携阵阵妖气直扑$n！"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIY  "\n「妖极天世」，$N手中"+ weapon->name() +HIY"迅雷般刺向$n！"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIG  "\n「鬼魅人间」，$N手中"+ weapon->name() +HIG"猛然化为一团紫气冲向$n！"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIC  "\n「魔影幢幢」，$N手中"+ weapon->name() +HIC"随道道寒光飞向$n！"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIM  "\n「魔光魅影」，$N手中"+ weapon->name() +HIM"化为万千幻影刺向$n！" NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);


       me->add_temp("apply/attack", -180);    
        me->add_temp("apply/damage", -2800);


me->start_busy(4);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

