//by dewbaby@sk_sjsh
//九剑·情绝

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
	string msg;
	int extra;
	int i;
	object weapon;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;
        int ap, dp, fp, pp,count;

        weapon = me->query_temp("weapon");

      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
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

       if( !wizardp(me) &&(int)me->query_skill("daya-sword", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("wuzheng-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通梅庄武学，使出了梅庄的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("请使用无争心法!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
		
     
        lvl = me->query_skill("wuyun-jian", 1);
     message_vision(WHT"$N神情轻蔑地看着$n。\n\n"NOR,me,target);
     message_vision(WHT"$N凝神定气，突然手中"+ weapon->name() +HIY"化为九道金色剑气朝$n射去！\n"NOR,me, target);
 

        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",2800);
        //me->add_temp("apply/sword", 800);

        message_vision(HIY"$N身形如风，手中剑气影射不断！\n"NOR,me,target);
msg = WHT"$n"+WHT"被被迎面而来的剑气逼得连连后退，似乎颇为吃力。"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY "$N咬紧牙关，一刀又劈了过来！" NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"一剑                  "+BLINK+HIC+"泪洒西厢月"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"二剑             "+BLINK+WHT+"迢迢银汉隔"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"三剑             "+BLINK+HIB+"囚来高塔倾"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"四剑             "+BLINK+HIW+"哭到长城裂"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"五剑             "+BLINK+BLU+"百宝影无寻"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"六剑             "+BLINK+HIR+"红楼梦难歇"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"七剑             "+BLINK+HIC+"不如抛此情"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"八剑             "+BLINK+HIM+"去做花间蝶"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"九剑             "+BLINK+WHT+"情绝情难了"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);


        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2800);



                msg = HIY "只见$N" HIY "一声暴喝，单手迅速在" + weapon->name() +
                      HIY "上拨动数下，顿时琴音铮铮大响，只听“啵”的\n一声破空"
                      "之响，一束无形剑气澎湃射出，直贯$n" HIY "而去。\n" NOR;


        ap = me->query_skill("force");
        dp = target->query_skill("force");


if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

        {
                
                damage = me->query_skill("daya-sword",1);
                target->receive_damage("qi", damage*5,me);
                target->receive_wound("qi", damage*5,me);
                msg += HIR "$n" HIR "只觉得$N" HIR "内力激荡，琴"
                                           "音犹如一柄利剑穿透鼓膜，“哇”的喷出一口"
                                           "鲜血。\n" NOR;


        } else
        {

                msg += CYN "可是$n" CYN "急忙凝神聚气，努力使自己"
                       "不受琴音的干扰，终于化解了这一招。\n" NOR;


        }
        message_combatd(msg, me, target);





                msg = HIM "只见$N" HIM "一声冷哼，以内劲催动" + weapon->name()
                      + HIM "，激荡出无形琴音，铮然大响，只听“啵”的\n一声破空"
                      "之响，一束无形剑气澎湃射出，直贯$n" HIM "而去。\n" NOR;


if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

        {
                
                damage = me->query_skill("daya-sword",1);
                target->receive_damage("qi", damage*5,me);
                target->receive_wound("qi", damage*5,me);
                msg += HIR "$n" HIR "只觉得$N" HIR "内力激荡，琴"
                       "音犹如一柄利剑穿透鼓膜，“哇”的喷出一口"
                       "鲜血。\n";
        } else
        {
                msg += CYN "可是$n" CYN "急忙凝神聚气，努力使自己"
                       "不受琴音的干扰，终于化解了这一招。\n" NOR;
        }
        message_combatd(msg, me, target);



                msg = HIW "只见$N" HIW "双目微闭，单手在" + weapon->name() +
                      HIW "上轻轻拨动，顿时只听“啵啵啵”破空之声连续不断"
                      "，数股破\n体无形剑气激射而出，直奔$n" HIW "而去。\n" NOR;



if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                msg += HIR "$p" HIR "只感到$P" HIR "内力澎湃，汹涌而至，霎"
                       "时心神惧碎，呆立当场！\n" NOR;
                damage = me->query_skill("wuzheng-xinfa",1);
                target->receive_damage("qi", damage*6,me);
                target->receive_wound("qi", damage*6,me);
                
        } else
        {
                msg += HIC "$n" HIC "只感到$P" HIC "内力澎湃，汹涌而至，急"
                       "忙凝神聚气，小心应付。\n" NOR;

               
        }

        message_combatd(msg, me, target);

        //me->add_temp("apply/sword", -lvl/3);
        me->start_busy(4);
        return 1;
}