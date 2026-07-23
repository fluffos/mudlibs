//fumo.c 袈裟伏魔功
//By Xuanyuan  16/3/2002

/*
        鸠摩智微笑道：“不敢，还请玄生大师指教。”身形略侧，左掌突然平举，
右拳呼的一声直击而出，如来佛座前一口烧香的铜鼎受到拳劲，镗的一声，跳了起
来，正是大金刚拳法中的一招“洛钟东应”。拳不着鼎而铜鼎发声，还不算如何艰
难，这一拳明明是向前击出，铜鼎却向上跳，可见拳力之巧，实已深得“大金刚拳”
的秘要。

    鸠摩智不等铜鼎落下，左手反拍出一掌，姿势正是般若掌中的一招“慑伏外道”，
铜鼎在空中转了半个圈子，拍的一声，有什么东西落下来，只是鼎中有许多香灰跟
着散开，烟雾弥漫，一时看不清是什么物件。其时“洛钟东应”这一招余力已尽，
铜鼎急速落下，鸠摩智伸出大拇指向前一捺，一股凌厉的指力射将过去，铜鼎突然
向左移开了半尺。鸠摩智连捺三下，铜鼎移开了一尺又半，这才落地。少林众高僧
心下叹服，知他这三捺看似平凡无奇，其中所蕴蓄的功力实已到了超凡入圣的境地，
正是摩诃指的正宗招数，叫做“三入地狱”。那是说修习这三捺时用功之苦，每捺
一下，便如入了一次地狱一般。

    香灰渐渐散落，露出地下一块手掌大的物事来，众僧一看，不禁都惊叫一声，
那物事是一只黄铜手掌，五指宛然，掌缘闪闪生光，灿烂如金，掌背却呈灰绿色。

    鸠摩智袍袖一拂，笑道：“这‘袈裟伏魔功’练得不精之处，还请方丈师兄指
点。”一句话方罢，他身前七尺外的那口铜鼎竟如活了一般，忽然连打几个转，转
定之后，本来向内的一侧转而向外，但见鼎身正中剜去了一只手掌之形，割口处也
是黄光灿然。辈份较低的群僧这才明白，鸠摩智适才使到般若掌中“慑伏外道”那
一招之时，掌力有如宝刀利刃，竟在鼎上割下了手掌般的一块。

虹：按原著看来此功只有最后一拂，此pfm特意加上前3种武功攻击。
*/
#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        int force, jiali, jiajin, amount;
        object weapon;
/*
        if (! wizardp(me)) 
                return notify_fail("目前这功能还不开放！\n");
*/
        if( target == me)target=offensive_target(me);

        if( !target )target = offensive_target(me);
        if( !target )target = me->select_opponent();

        if( !target || !me->is_fighting(target) || !living(target) )
                return notify_fail("袈裟伏魔功只能在战斗中使用。\n");

		if( environment(target)->query("no_fight") )
				return notify_fail("在这里你不能施展袈裟伏魔功！\n");

        if( me->query_temp("shaolin/fumo") )
                return notify_fail("你已经在使用袈裟伏魔功！\n");

        if( me->query_temp("weapon") )
                return notify_fail("你只能在空手时使用袈裟伏魔功！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 300)
                return notify_fail("你的混元一气功火候未到，无法施展袈裟伏魔功！\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("你所用的并非混元一气功，无法施展袈裟伏魔功！\n");

        if( me->query_skill("banruo-zhang", 1) < 300 )
                return notify_fail("你的般若掌火候未到，无法施展袈裟伏魔功！\n");

        if( me->query_skill_mapped("strike") != "banruo-zhang" )
                return notify_fail("你所激发的掌法并非般若掌，无法施展袈裟伏魔功！\n");

		if( me->query_skill_prepared("strike") != "banruo-zhang" )
                return notify_fail("你所备的并非般若掌，无法施展袈裟伏魔功！\n");

		if( me->query_skill("yizhi-chan", 1) < 300 )
				return notify_fail("你在一指禅火候未到，无法施展袈裟伏魔功！\n");

        if( me->query_skill_mapped("finger") != "yizhi-chan" )
                return notify_fail("你所激发的指法并非一指禅，无法施展袈裟伏魔功！\n");

		if( me->query_skill_prepared("finger") != "yizhi-chan" )
                return notify_fail("你所备的并非一指禅，无法施展袈裟伏魔功！\n");

		if( me->query_skill("jingang-quan", 1) < 300 )
				return notify_fail("你在大金刚拳火候未到，无法施展袈裟伏魔功！\n");

        if( me->query_skill_mapped("cuff") != "jingang-quan" )
                return notify_fail("你所激发的拳法并非大金刚拳，无法施展袈裟伏魔功！\n");

        if( me->query_skill("buddhism", 1) < 300 )
                return notify_fail("你的佛学修为不够，无法施展袈裟伏魔功！\n");

		if( me->query_str() < 30 )
				return notify_fail("你在臂力上先天禀赋不足，无法施展袈裟伏魔功！\n");

        if( me->query("max_neili") <= 5000 )
                return notify_fail("你的内力修为不足，劲力不能运发，无法施展袈裟伏魔功！\n");

        if( (int)me->query("neili") < 2000  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("jingli") < 1000  )
                return notify_fail("你的精力不够。\n");

		force = me->query_skill("force");
        jiali = me->query("jiali",1);
		jiajin= me->query("jiajin",1);
		amount = force / 4;

		if ( amount < 100 ) amount = 100;
		if ( amount > 200 ) amount = 200;

		me->set_temp("shaolin/fumo", 1);

		message_vision(WHT"\n$N袍袖一拂，双手合什说道：“阿弥陀佛！”一句话方罢竟然施展出少林七十二绝技之一的‘袈裟伏魔功’！\n\n" NOR, me, target);

		if( me->query_skill_prepared("finger") == "yizhi-chan" || me->query_skill_prepared("strike") == "banruo-zhang")
		{
			me->set_temp("restore_strike", 1);
			me->prepare_skill("finger");
			me->prepare_skill("strike");
            me->prepare_skill("cuff", "jingang-quan");
		}

		me->add_temp("apply/attack", amount);
		me->add_temp("apply/dodge", amount);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/dodge", -amount);

		if( me->query_temp("restore_strike") )
		{
			me->prepare_skill("cuff");
			me->prepare_skill("strike", "banruo-zhang");
			me->prepare_skill("finger", "yizhi-chan");
			me->delete_temp("restore_strike");
		}
		me->start_busy(1);
		target->start_busy(1);
		me->add("neili", - force/2 - jiali );
		me->add("jingli", - force/3 - jiajin );   

		if( !target || !living(target)|| !living(me) || me->is_ghost()
			||environment(me) != environment(target) || !me->is_fighting()) {
			me->delete_temp("shaolin/fumo");
			return 1;
		}
		
		call_out("strike", 1, me, target);   

        return 1;
}

int strike(object me, object target)
{
        int ap, dp, force, jiali, jiajin, damage;
		string *limb, type, result, str;

		force = me->query_skill("force");
        jiali = me->query("jiali",1);
		jiajin= me->query("jiajin",1);

		ap = (me->query_skill("strike")*2
			+ me->query_skill("buddhism")
			+ me->query("combat_exp")/3000);

		dp = (target->query_skill("dodge")
			+ target->query_skill("parry")
			+ me->query("dex")*20
			+ target->query("combat_exp")/3000);

		damage = (me->query("jiali") + me->query("jiajin")) * (int)me->query_skill("force")/50 + 
					(random((int)me->query_skill("hunyuan-yiqi", 1)) + (int)me->query_skill("force", 1))*3 + 
					me->query_temp("apply/damage");
		damage = damage + random(damage/2);

		if(damage > force * 10 ) damage = force * 10;
		if(damage < force * 2 ) damage = force * 2;

		if( !target || !living(target)|| !living(me) || me->is_ghost()
			||environment(me) != environment(target) || !me->is_fighting()) {
			me->delete_temp("shaolin/fumo");
			return 1;
		}
        if( (int)me->query("neili", 1) < force*3 + jiali ){
			me->delete_temp("shaolin/fumo");
			tell_object(me, HIR"\n你待要出掌，却发现自己的内力不够了！\n"NOR);
			return 1;
		}
		message_vision(YEL"\n$N不等$n喘息，左手反拍出一掌，姿势正是般若掌中的一招“慑伏外道”！\n\n" NOR, me, target);

		if ( ap + random(ap) > dp + dp / 2 ){      
                message_vision(HIR "结果拍的一声，$n中掌处五指宛然，掌缘如金，掌背却呈青绿色！\n" NOR, me, target);

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);    
				limb = target->query("limbs");
				type = "内伤";
				result = COMBAT_D->damage_msg(damage, type);
				result = replace_string( result, "$l", limb[random(sizeof(limb))]);
				result = replace_string( result, "$p", target->name() );
				message_vision(result, me, target);
				target->start_busy(2);

				COMBAT_D->report_status(target);
                me->start_busy(2);
				me->add("neili", - force*3 - jiali );
				me->add("jingli", - force/3 - jiajin );   
				me->set_temp("shaolin/fumo_finger", 3);
				if( !target || !living(target)|| !living(me) || me->is_ghost()
					||environment(me) != environment(target) || !me->is_fighting()) {
					me->delete_temp("shaolin/fumo_finger");
					me->delete_temp("shaolin/fumo");
					return 1;
				}
				call_out("finger", 2, me, target);   
		} 
		else 
		{
                me->start_busy(4);
				me->add("neili", - force*2 - jiali );
				me->add("jingli", - force/4 - jiajin );    
				message_vision(HIY"不料$n眼疾身快，身形一飘，躲开了$N的攻击。\n" NOR, me, target);
				me->set_temp("shaolin/fumo_finger", 3);
				me->set_temp("strike_failed",1);
				if( !target || !living(target)|| !living(me) || me->is_ghost()
					||environment(me) != environment(target) || !me->is_fighting()) {
					me->delete_temp("shaolin/fumo_finger");
					me->delete_temp("strike_failed");
					me->delete_temp("shaolin/fumo");
					return 1;
				}
                call_out("finger", 4, me, target);   
		}
        return 1;
}
int finger(object me, object target)
{
        int force, jiali, jiajin,i, highhand, amount;
		object *all, *all1, room;
		string highname, highname1, name1;

		force = me->query_skill("force");
        jiali = me->query("jiali",1);
		jiajin= me->query("jiajin",1);
		amount = force / 3;
		if ( amount < 100 ) amount = 100;
		if ( amount > 200 ) amount = 200;

		if( !target || !living(target)|| !living(me) || me->is_ghost()
			||environment(me) != environment(target) || !me->is_fighting()) {
			me->delete_temp("shaolin/fumo_finger");
			me->delete_temp("strike_failed");
			me->delete_temp("shaolin/fumo");
			return 1;
		}

        if( (int)me->query("neili", 1) < force*3 + jiali ){
			me->delete_temp("shaolin/fumo_finger");
			me->delete_temp("strike_failed");
			me->delete_temp("shaolin/fumo");
			tell_object(me, HIR"\n你待要出掌，却发现自己的内力不够了！\n"NOR);
			return 1;
		}

		if( me->query_skill_prepared("strike") == "banruo-zhang" )
		{
			me->set_temp("restore_brz", 1);
			me->prepare_skill("strike");
		}
		me->add_temp("apply/attack", amount);
		me->add_temp("apply/dodge", amount);

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->set_temp("shaolin/fumo_finger", 2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->set_temp("shaolin/fumo_finger", 1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->delete_temp("shaolin/fumo_finger");

		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/dodge", -amount);

		if( me->query_temp("restore_brz") )
		{
			me->prepare_skill("strike", "banruo-zhang");
			me->delete_temp("restore_brz");
		}

		message_vision(YEL"\n这三捺看似平凡无奇，正是摩诃指的正宗招数，叫做“三入地狱”！\n\n" NOR, me, target);

		if (me->query_temp("strike_failed"))
		{
			me->delete_temp("strike_failed");
		}

//偷用lbc的xumi部分code，嘿嘿嘿嘿
////////////////////////////////////少林僧人表情////////////////////////////////////////
	room=environment(me);
	all = all_inventory(room);
	all1 = allocate(sizeof(all));	
	
	highhand=0;
	highname="";
	highname1="";
	name1="";

	for (i=0; i<sizeof(all); i++)
	{
		if (all[i]->query("family/family_name")=="少林派" 
			&& (all[i]->query_skill("hunyuan-yiqi",1) >= 200) 
			&& (all[i]->query("id") != me->query("id")) 
			&& (living(all[i])))
			
		{
			if (highhand == 0 )
			{	
				highhand=highhand+1;
				highname=highname + all[i]->query("name");
			}
			else 
			{
				highhand=highhand+1;
				highname=highname + "、" + all[i]->query("name");
			}
		}
	}
	for (i=0; i<sizeof(all); i++)
	{
		if (all[i]->query("family/family_name")=="少林派" 
			&& (all[i]->query_skill("hunyuan-yiqi",1) >= 200) 
			&& (all[i]->query("id") != me->query("id")))
		{
			highname1 = replace_string(highname, all[i]->query("name") + "、", "");
			printf("name1= %s",name1);
			highname1 = replace_string(highname1, "、" + all[i]->query("name"), "");
			if (highhand>1) 
				tell_object(all[i], HIY"\n你和" + highname1 + "等一齐“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
			else tell_object(all[i], HIY"\n你“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
		}

		if (all[i]->query("family/family_name")=="少林派" && all[i]->query_skill("strike",1) < 200)
		{
			if(highhand)
			{
				if(highhand > 1)
				{	
					tell_object(all[i],HIY"\n周围的" + highname + "等一齐“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
					tell_object(all[i],HIY"\n你见众长老齐声惊噫，心知"+ me->query("name") + "这三捺功力实已到了超凡入圣的境地，无奈自己修为尚浅，无法得知其中奥妙。\n"NOR);
				}
				else 
				{
					tell_object(all[i],HIY"\n" + highname + "“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
					tell_object(all[i],HIY"\n你见" + highname + "出声惊噫，心知"+ me->query("name") + "这三捺功力实已到了超凡入圣的境地，无奈自己修为尚浅，无法得知其中奥妙。\n"NOR);
				}
			}
			else 
				tell_object(all[i],HIY"\n你见" + me->query("name") + "这三捺凌厉无比，不由的暗自惊叹。\n"NOR);
		}
	
		if (all[i]->query("family/family_name")!="少林派")
			if(highhand)
			{
				if(highhand > 1)
				{
					tell_object(all[i],HIY"\n周围的" + highname + "等一齐“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
					tell_object(all[i],HIY"\n你见少林众长老齐声惊噫，心知"+ me->query("name") + "这三捺功力实已到了超凡入圣的境地，可惜自己的武功和少林并非一脉，无法得知其中奥妙。\n"NOR);
				}
				else 
				{
					tell_object(all[i],HIY"\n" + highname + "“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
					tell_object(all[i],HIY"\n你见" + highname + "出声惊噫，心知"+ me->query("name") + "这三捺功力实已到了超凡入圣的境地，可惜自己的武功和少林并非一脉，无法得知其中奥妙。\n"NOR);
				}
			}
	}

	if (highhand) 
	{
		if(highhand > 1)
			tell_object(me, HIY"\n周围的" + highname + "等一齐“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
		else
			tell_object(me, HIY"\n" + highname + "“噫”了一声，声音中充满了惊讶佩服之情。\n"NOR);
	}
/////////////////////////////////////////////////////////////////////////////////////////////

		me->add("neili", - force*3 );
		me->add("jingli", - force/3 );   
		if( me->query("neili") < 0 ) me->set("neili", 0);
		if( me->query("jingli") <= 0 ) me->set("jingli", 1);
		me->start_busy( 3 + random(2) );
		me->delete_temp("shaolin/fumo");

        return 1;
}