//yinfeng.c 阴风刀
//lbc 2002/3

//突然之间，一股阴劲如刀、如剑、如匕、如凿，直插入他胸口的“玉堂穴”中。
//这虽是一股无形无质的阴寒之气，但刺在身上实同钢刃之利。张无忌霎时之间闭气窒息，全身动弹不得，
//张无忌急运内力，冲击胸口被点中了的“玉堂穴”

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao = ({//此等高级内功，当学习之初就应学习攻击人体大穴，而弃手足之穴不攻, laugh
	"百会穴",
	"灵台穴",
	"太阳穴",
	"膻中穴",
	"命门穴",
	"气海穴",
	"京门穴",
	"玉堂穴",
	"迎香穴"
	});
string* lims = ({
	"头顶",
	"头顶",
	"头顶",
	"胸口",
	"小腹",
	"小腹",
	"腰间",
	"胸口",
	"面颊"
	});

void checking(object me, object *targets);

int perform(object me, object target)
{
	string weapon, w_name, xue, lim;
	int ap, dp, yf_target, index, i;
	object *all, *targets;

	if( !target ) 
		target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("“阴风刀”只能对战斗中的对手使用。\n");
	
	if (target->query("race") != "人类")
		return notify_fail("面对这样的对手，你无法准确认穴。\n");

	if( me->query_skill_mapped("force") != "shenghuo-xuanming" )
		return notify_fail("你所用的内功和古波斯武功并非一路，无法施展阴风刀。\n");

	if( (me->query_skill("shenghuo-ling", 1 )) < 150 )
		return notify_fail("你的古波斯武功修为不够，无法使出阴风刀伤人！\n");

	if( (me->query_skill("shenghuo-xuanming", 1)) < 150 )
		return notify_fail("你的内功修为不够，内劲无法穿透穴道。\n");

	if (target->query_temp("bosi/yinfeng"))
		return notify_fail("对手已经中了阴风刀内劲，放胆攻击吧！\n");

	if (!living(target))
		return notify_fail("赶快补上一招，结果对手吧！\n");
	
	
/*	all = all_inventory(environment(me));
	for (i = 0; i < sizeof(all) ;i++ )
	{
		if (all[i]->is_fighting(me))
			if (all[i]->query_temp("bosi/yf_user") == me->query("id"))
			{
				yf_target++;
				last_target = all[i];
			}
	}
	if (yf_target > 0 && target != last_target)
		return notify_fail("对手太多了，这种情况下还是用透骨针吧！\n");
	//由于 call_out 函数的特性，这里不得不如此，谁有更好的方法呢？
	//半个小时后, 我自己想到了用物件数组做参数传给call_out调用的函数的方法....:(
	//教训噢....可见要勤于思考
*/

	if (me->query("neili") < 150)
		return notify_fail("你的内力不够。\n");

	if (me->query("jingli") < 150)
		return notify_fail("你的精力不够。\n");

	ap = random(me->query_skill("shenghuo-ling") + me->query_skill("force"));

	dp = (target->query_skill("dodge") + target->query_skill("force"))*2/7;

	if (wizardp(me))
		printf("ap = %d , dp = %d .\n",ap , dp);

	weapon = me->query_temp("weapon");
	w_name = weapon->query("name");
	index = random(sizeof(xuedao));
	xue = xuedao[index];
	lim = lims[index];
	message_vision(HIB"$N潜运内功，一股阴劲透过" + w_name + "直逼$n"+ lim + xue +"。\n\n" NOR, me, target);
	if (ap > dp)
	{
		message_vision(HIR"突然之间，一股阴劲如刀、如剑、如匕、如凿，直插入$n"+ lim + "的“"+ xue +"”中。\n\n"NOR, me ,target);
		me->add("neili", -ap/2);
		me->add("jingli", -ap/3);
		target->start_busy(1);
		target->set_temp("bosi/yinfeng", ap);
		target->set_temp("bosi/xue", xue);
		
		me->add_temp("yinfeng/targets", ( {target} ));
		targets = me->query_temp("yinfeng/targets");
		remove_call_out("checking");
		call_out("checking", 1, me, targets);
	}
	else
	{
		message_vision(HIW"$n感觉阴劲袭来，心知厉害，不敢硬接，一闪身避了开去。\n"NOR, me, target);
		message_vision(HIW"$N阴劲伤人不成，心下诧异，登时有些踯躅。\n\n"NOR, me, target);
		me->start_busy(2);
	}

	return 1;
}

void checking(object me, object* targets)
{
	string xue;
	int i, neili_power, yinfeng_power;
	
/***********************以下供测试用**********************************/
	if (wizardp(me))											
	{															
		printf("ARRAY大小: %d\n", sizeof(targets));				
		for (i=0;i<sizeof(targets) ;i++ )						
		{														
			if (!targets[i])									
				continue;										
			printf("目标包括:%s\n", targets[i]->query("name"));	
		}														
	}																	
/***********************以上供测试用*********************************/


	if (!me) // 我消失? 所有对手痊愈...
	{
		targets->delete_temp("bosi/yinfeng");
		//targets->die(); //laugh....
		return;
	}

	for (i = 0; i < sizeof(targets); i++)
	{
		if (!targets[i]) // 对手消失? 去掉自身标记....
		{
			targets = targets - ({targets[i]});
			me->set_temp("yinfeng/targets", targets);
			continue;
		}
		
		xue = targets[i]->query_temp("bosi/xue");

		if( !living(targets[i]) ) // 对手昏迷? 去掉自身, 对手标记
			// living() 这函数真tnnd难记，通常人都会认为这个是is_living(), tnnd!!!!
		{
			targets[i]->delete_temp("bosi/yinfeng");
			targets = targets - ({targets[i]});
			me->set_temp("yinfeng/targets", targets);
			continue;
		}
	
		if (targets[i]->query_temp("bosi/yinfeng"))
		{
			targets[i]->start_busy(1);
			
			if (targets[i]->query("neili") > 160 && random(2))
			{
				neili_power = (targets[i]->query("neili") / 2) + random(targets[i]->query("neili")/2);
				if (targets[i]->is_fighting()) //战斗中不能分出全部内力来
					neili_power = neili_power / 2 ;
				yinfeng_power = random(targets[i]->query_temp("bosi/yinfeng") * 40);

				if (wizardp(me))
					printf("neili_power = %d , yinfeng_power = %d .\n", neili_power, yinfeng_power);

				tell_room(environment(targets[i]), WHT + targets[i]->query("name") + "急运内力，冲击被阴寒之气封闭的“" + xue + "”。\n\n"NOR, targets[i]);
				//此处若使用message_vision则会像sanyin一样有描述上的问题, 所以用tell_room和tell_object分开表达
				tell_object(targets[i], WHT + "你急运内力，冲击被阴寒之气封闭的“" + xue + "”。\n\n"NOR);
				if (neili_power < yinfeng_power)
				{
					tell_room(environment(targets[i]), CYN + "不料闭穴的阴寒之内劲穿透穴道，" + targets[i]->query("name") + "这一下未能冲开。\n" + NOR, targets[i]);
					tell_object(targets[i], CYN + "不料闭穴的阴寒之内劲穿透穴道，你这一下未能冲开。\n" + NOR);
					targets[i]->add("neili", -100);
					targets[i]->add_temp("bosi/yinfeng", -75);
					if (targets[i]->query_temp("bosi/yinfeng") < 1)
						targets[i]->set_temp("bosi/yinfeng", 1);
				}
				else
				{
					if ( me->is_fighting(targets[i]) && targets[i]->is_fighting(me) && living(targets[i]) )
					{
						message_vision(HIR"$n全力冲开被封闭的穴道，立时上前抢攻。\n"NOR, me, targets[i]);
						COMBAT_D->do_attack(targets[i], me, targets[i]->query_temp("weapon"));
					}
					else 
					{
						tell_room(environment(targets[i]), HIR + targets[i]->query("name") + "终于冲开被阴寒内力所闭的穴道。\n\n" + NOR, targets[i]);
						tell_object(targets[i], HIR + "你终于冲开被阴寒内力所闭的穴道。\n\n" + NOR);
					}
					
					targets[i]->add("neili", -400);
					targets[i]->delete_temp("bosi/yinfeng");
					targets = targets - ({targets[i]});
					me->set_temp("yinfeng/targets", targets);
					continue;
				}
			}
		
			if (targets[i]->query("neili") <= 160)
			{
				tell_room(environment(targets[i]), HIR + targets[i]->query("name") + "内力涣散，但经络已然畅通，被封闭的穴道已经不解自开。\n\n" + NOR);
				targets[i]->delete_temp("bosi/yinfeng");
				targets = targets - ({targets[i]});
				me->set_temp("yinfeng/targets", targets);
				continue;
			}
		}
	}

	targets = me->query_temp("yinfeng/targets");
	if (targets == ({}))
	{
		remove_call_out("checking");
		if (wizardp(me))
			printf("All effect removed!!!!!\n"); //for test
		return;
	}
	call_out("checking", 1, me, targets);
}