//modified by Vast

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg, type, mode;
	int damage, kar, level, myexp, youexp, wap, wdp;
	object weapon, myweapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「总诀式」只能对战斗中的对手使用。\n");

        if (!objectp(myweapon = me->query_temp("weapon"))
        || (string)myweapon->query("skill_type") != "sword")
                return notify_fail("你必须使剑才能使用「总诀式」！\n");

        if( (int)(level = me->query_skill("dugu-jiujian", 1)) < 150 )
                return notify_fail("你的独孤九剑不够娴熟，不会使用「总诀式」。\n");
       	if((int)me->query("neili") < 50)
              return notify_fail("你的内力不够呀!\n");

        kar = me->query("kar") / 10;
        level = level /100;
        myexp = me->query("combat_exp");
        youexp = target->query("combat_exp");

        weapon = target->query_temp("weapon");
        if(!weapon) weapon = target->query_temp("secondary_weapon");

        msg = HIC "$N曼声长吟道：" + HIW + "九剑行天下，无招胜有招！\n" + HIC +
      	"$n忽地只觉眼前剑光闪烁，$N的长剑如白龙出洞从$n的招数之中突而抢进，\n" +
         "剑尖已搭在$n脉门，只消轻轻一划，数十年苦功即将毁于一旦！\n\n" + NOR;

        me->start_busy(1);

        if( random(myexp) > youexp / 4 )
	{
		//第一个效果：破兵器
		if(random(2) && weapon)
		{
        		type = weapon->query("skill_type");
        		switch (type)
        		{
        			case "whip":
        			mode = "鞭";
        			break;
        			case "blade":
        			mode = "刀";
        			break;
        			case "sword":
        			mode = "剑";
        			break;
        			case "staff":
        			mode = "杖";
        			break;
        		}
                        if(random(me->query_skill("dodge",1)) > 150)
                        {
                        	if(stringp(mode))
				msg = HIC "$N纵声长啸，声震屋瓦！$n正施展生平所学全力进攻，却听$N清声笑道：“此等招式\n" +
                        	"已尽在我心中，汝奈我何？”话音未落$N剑锋一转，招招抢攻，剑势去处尽是$n之所\n" +
                        	"必救！$n心中大惊，只觉自己浸淫了数十年苦功的这套横行天下" + mode + "法在对方眼中漏洞\n" +
                        	"百出，如同儿戏！ 一时间不由得手忙脚乱，" + mode +"不成招！\n\n" + NOR;
                		wap = 	  (int)myweapon->weight() / 50
                			+ (int)myweapon->query("rigidity")
                			+ (int)me->query_str();
                		wdp = 	  (int)weapon->weight() / 50
                			+ (int)weapon->query("rigidity")
                			+ (int)target->query_str();
                		wap = random(wap);

                		if( wap > 2 * wdp )
                		{
                			weapon->add("rigidity", -50);
                			if(weapon->query("rigidity") < 1)
                			{
                				msg += HIW "只听见「啪」地一声，$n手中的" + weapon->name() + HIW"已经断为两截！\n" NOR;
                                		weapon->unequip();
                                		weapon->move(environment(target));
                				weapon->set("name", "断掉的" + weapon->query("name"));
                				weapon->set("value", 0);
                				weapon->set("weapon_prop", 0);
                                		target->reset_action();
                			}
                			else
        				msg += HIC"$N的" + myweapon->name() + HIC"和$n的" + weapon->name() + HIC"重重交击在一起，发出「铛」地一声巨响。\n"NOR;
                		}
                		else
                		{
                			if(stringp(mode))
        				msg += HIR + "$N看出$n方寸已乱，手上加快攻势，$n越忙越慌，惊骇、恐惧、迷惑、沮丧、\n" +
        				"自卑等数十种滋味一齐涌上心头，突然之间只觉脑中轰的一声," + mode + "法胡缠乱绕完全错乱！\n" +
        				"$N剑尖所指不离$n要害，$n这一路精深" + mode + "法竟这样被$N名传天下的" + HIW + BNK + "『破" + mode +"式』" + NOR + HIR + "完全破去！\n" +
        				"$n只觉手腕一麻，" + weapon->name() + HIR + "脱手飞出！\n\n"NOR;
        				else
                                        msg += HIR + "$n已不及作出任何反应,登时脸如死灰，两行浊泪几欲夺眶而出。\n" +
                                        "$N见状心中不忍，侧过剑锋在$n寸关穴上轻轻一点。\n" +
                                        "$n只觉手腕一麻，" + weapon->name() + HIR + "脱手飞出！\n\n"NOR;
                                	weapon->unequip();
                                	weapon->move(environment(target));
                                        target->apply_condition("cannt_eq", 1 + random(2));
                                        target->reset_action();
                                }
                        }
                        else
        		{
        	        	me->start_busy(4);
        	        	if (stringp(mode))
        	        	{
                	        	if (random(2) == 0)
                                	msg += HIG + "$n滞气上升，" + mode + "势处处受阻。只觉胸中一口闷气无处发泄，忍不住仰天长啸一声！\n" +
                                		"不想这一声过后灵台竟然清明，心气下定，往日的苦修一幕幕回演当下" + weapon->name() + HIG"如风轮使，\n" +
                                		"只将一套" + mode + "法演得滴水不漏，达到了演武的最高境界！$N见到$n这疯狂状态，只得收剑\n" +
                                		"回守，另图它策。\n" + NOR;
                                	else
                                	msg += HIG + "$n临敌经验丰富，临危不乱，对于$N盛气凌人的剑势宛若不见，运气于肩，一霎那\n" +
                                		"肩使臂，臂使肘，肘使腕，腕挺" + mode + ",于$N铺天盖地的剑招中决然反击，只听叮的一声，" + mode + "\n" +
                                		"剑相交，$N只觉虎口矩震，剑势一偏。$n趁此机会暗换真气，庆幸度过一劫。\n" + NOR;
				}
				else
				{
                        	if (random(2) == 0)
                                	msg += HIG + "$n手腕微侧，绕过$N的剑锋向上一抬，$N的剑脊沿着$n脉门斜斜擦过，\n" +
                                	"$n感到手腕酸麻，但凭借巧劲化解了这天下冷兵器的克星\n" +
                                	HIW" 独孤九剑 " + HIG + "，心中竟有些飘飘然。\n" + NOR;
                               	else
                               		msg += HIG + "饶是$n临敌经验丰富，也不禁手忙脚乱，只得运气于臂，大喝一声\n" +
                               		HIR + BNK + "开！\n" + NOR + HIG + "手臂竟然暴粗数寸，以上乘气功硬接了这凌厉无匹\n" +
                               		"的一剑，只震得肩膀脱臼真气翻腾。\n" + NOR;
                                }
                	}

       			me->add("neili", - 50);
        		message_vision(msg, me, target);
			return 1;
		}


                //第二个效果：crushing-blow
                if (random(100) < 1 + kar + level)
                {
                	damage = target->query("max_qi") / 2;
                	if ( damage < 1000 ) damage = 1000;//min damage
                	if ( damage > 2500 ) damage = 2500;//max damage
                	if (random(2) == 0)
                        msg += HIR + "$n突然间感到小腹一凉，继而丹田上一阵刺痛，全身气血倒流，霎那间胸口、\n" +
                        "锁骨、眉心又接连中剑！$n数道伤口中血喷三丈，已受致命外伤，四肢力量也\n"
                        "随真气狂泻而出！$n心中莫名惊骇，口中不禁发出凄厉的惨叫！\n" + NOR;
                        else
                        msg = HIC "$N忽地领悟到了独孤九剑的最高真谛　" + HIW + "『破气式』" + HIC + "，口中大声呼喝，剑法变化\n" +
                        "多端，劈、挑、切、刺，剑尖始终不离$n丹田、气海、澶中、百会四大要穴！\n" +
                        "$n顿觉风雷袭体，呼吸困难，电光石火间，$N宝剑长驱直入，已刺破$n的护体真气！\n" + NOR;

                }
                else//普通damage
                {
               		msg += HIW"$n被剑气所逼，“哇”的喷出一口鲜血！\n"NOR;
			damage = (int)me->query_skill("dugu-jiujian", 1);
	                damage = damage / 2 + random(damage);
		}
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage, me);
        }
        else
        {
		me->start_busy(5);
        	if(weapon)
        	{
            		if (random(2) == 0)
                        	msg += HIG + "$n微一迟疑，小腹上已经感到森森剑意！$n大惊之下两掌虚按，双脚前蹬，\n" +
                        		"整个上身成折叠状拼命后射！$n正绝望时，突觉剑意顿去，却是$N招式用老，\n" +
                        		"挺身收剑。$n双股战栗，只觉一丝斗志也无。\n" + NOR;
                        else	msg += HIG + "$n身经百战，于此性命攸关之际毫不慌乱。左掌猛斫，以排山倒海的攻势\n" +
                        		"将$N身躯格在外门，同时小腹猛向内缩，竟然生生向后吸进两寸！$N情知对方内力\n"
        				"过于雄厚，徒劳无益。只得回剑守势。\n" + NOR;
	 	}
	 	else
	 	{
             		if (random(2) == 0)
                        	msg += HIG + "$n心知空手抵剑难有幸理，当下深吸一口长气，丹田内力霎时奔腾而出\n" +
                        	"直至掌心！$N觉得剑势微微一挫，$n聚掌成球吐气开声，已将长剑荡在一边！！\n" + NOR;
                        else	msg += HIG + "$n于千钧一发之际双掌外翻，化掌为刀，胸前门户大开。同时身形疾向后射！\n" +
                        		"$N剑势堪堪用老，手腕垂剑，回成独孤九剑起手式。$n远远地站着，心中暗想\n" +
                        		"下次这剑再刺过来，我当如何抵挡？\n" + NOR;
       		 }

        }
        me->add("neili", - 50);
        message_vision(msg, me, target);
	return 1;
}





