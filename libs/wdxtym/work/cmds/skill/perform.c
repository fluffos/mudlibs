// perform.c

#include <ansi.h>

inherit F_CLEAN_UP;

private int do_perform(object me, string arg);

int main(object me, string arg)
{
	mapping smap, pmap, pfms,skips;
	string force_ski,parry_ski,weapon_ski,and,*pfm,ski_type,uski_type;
	int result;
	int busy;
	int lvl,i,j,k,flag;
	string msg,*valid_types,*skis,msgg;
	object env,weapon;

	seteuid(getuid());

	if (me->is_busy())
		return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");

	env = environment(me);
	if(env&&env->is_comb_ob()&&env->query("first")!=me)
		return notify_fail("别急，等轮到你再说！\n");

	smap = me->query_skill_map();

	pmap = me->query_skill_prepare();

	if(objectp(weapon = me->query_temp("weapon")))
		ski_type = weapon->query("skill_type");

	if (!arg)
	{
		valid_types = ({"finger","hand","cuff","claw","strike","unarmed","spells"});
		skips = ([]);
		j = 3;
		msg = ZJBTSET"b1:内力"ZJBR"回血:exert recover"ZJSEP"b2:内力"ZJBR"回精:exert regenerate"ZJSEP"b3:怒气"ZJBR"爆发:burning"ZJSEP;
		if(!mapp(smap)||smap==([]))
		{
			while(j<11)
			{
				j++; if(j>11) continue;
				msg += "b"+ j + ":暂未"ZJBR"设定:look"+ZJSEP;
			}
			write(msg+"\n");
			return 1;
		}

		if(force_ski=smap["force"])
		{
			pfms = SKILL_D(force_ski)->query_pfm();
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					j++; if(j>11) continue;
					msg += "b"+ j + ":" + pfms[pfm[i]]+" "+pfm[i]+ZJSEP;
				}
			}
			skips[force_ski]=1;
		}

		if(objectp(weapon))
		{
			if(stringp(weapon_ski=smap[ski_type])&&!skips[weapon_ski])
			{
				pfms = SKILL_D(weapon_ski)->query_pfm();
				if(mapp(pfms)&&pfms!=([]))
				{
					pfm = sort_array(keys(pfms), (: strcmp :) );
					for(i=0;i<sizeof(pfm);i++)
					{
						j++; if(j>11) continue;
						msg += "b"+ j + ":" + pfms[pfm[i]]+" "+ski_type+"."+pfm[i]+ZJSEP;
					}
				}
				skips[weapon_ski]=1;
			}
		}
		else if(!objectp(weapon))
		{
			if(mapp(pmap)&&pmap!=([]))
			{//首先推送准备技能
				skis = sort_array(keys(pmap), (: strcmp :) );
				for(k=0;k<sizeof(skis);k++)
				{
					if(skips[pmap[skis[k]]]) continue;
					pfms = SKILL_D(pmap[skis[k]])->query_pfm();
					if(mapp(pfms)&&pfms!=([]))
					{
						pfm = sort_array(keys(pfms), (: strcmp :) );
						for(i=0;i<sizeof(pfm);i++)
						{
							j++; if(j>11) continue;
							msg += "b"+ j + ":" + pfms[pfm[i]]+" "+skis[k]+"."+pfm[i]+ZJSEP;
						}
					}
					skips[pmap[skis[k]]]=1;
				}
			}

			skis = sort_array(keys(smap), (: strcmp :) );
			for(k=0;k<sizeof(skis);k++)
			{
				flag = 1;
				for(i=0;i<sizeof(valid_types);i++)
				{
					if(SKILL_D(smap[skis[k]])->valid_enable(valid_types[i]))
					{
						uski_type = valid_types[i];
						flag = 2;
					}
				}
				if(!skips[smap[skis[k]]]&&flag==2)
				{
					pfms = SKILL_D(smap[skis[k]])->query_pfm();
					if(mapp(pfms)&&pfms!=([]))
					{
						pfm = sort_array(keys(pfms), (: strcmp :) );
						for(i=0;i<sizeof(pfm);i++)
						{
							j++; if(j>11) continue;
							msg += "b"+ j + ":" + pfms[pfm[i]]+" "+skis[k]+"."+pfm[i]+ZJSEP;
						}
					}
				}
				skips[smap[skis[k]]]=1;
			}
		}
		while(j<11)
		{
			j++;
			msg += "b"+ j + ":暂未"ZJBR"设定:look"+ZJSEP;
		}
		write(msg+"\n");
		return 1;
	}

	if (! mapp(smap) || sizeof(smap) == 0)
		return notify_fail("你现在没有使用任何有效特殊技能，没有外功绝技可用。\n");

	if (sscanf(arg, "%s and %s", arg, and) == 2 || sscanf(arg, "%s twice", arg) == 1 && (and = arg))
	{
		lvl = me->query_skill("zuoyou-hubo", 1);
		if (! lvl)
			return notify_fail("你要干什么？以为自己有三头六臂啊！\n");

		if (me->query_skill("count", 1)&&(me->query("id") != "sword_1"))
			return notify_fail("你杂学太多，心头烦乱，难以分心二用。\n");

		if (lvl <= 100)
			return notify_fail("你的左右互搏修为太浅，难以分心二用。\n");

		if (! me->is_fighting())
			return notify_fail("只有战斗中才能施展左右互搏。\n");

		if (strsrch(and,"zs_")!=-1||strsrch(arg,"zs_")!=-1)
			return notify_fail("宗师类技能必须专心致志施展,不能分心二用。\n");

		if (lvl < 360 && random(lvl) < 100)
		{
			me->start_busy(1);
			write("你试图分心二用，但是手就是不听使唤。\n");
			return 1;
		}
	}

	result = do_perform(me, arg);
	if (! and)
		return result;

	if(result && (arg==and))
		me->set_temp("clear_pfm_mark",1);
	if (! result)
		write(query_notify_fail());
	else
	{
		switch (random(4))
		{
		case 0:
			msg = HIY "$N" HIY "大喝一声，双手分使两招，一起攻出。"NOR"\n";
			break;

		case 1:
			msg = HIY "$N" HIY "双手齐出，分使不同招式，令人眼花缭乱。"NOR"\n";
			break;

		case 2:
			msg = HIY "$N" HIY "左右手分使两招，毫不停滞，宛如两人同时攻出。"NOR"\n";
			break;

		case 3:
			msg = HIY "$N" HIY "左手一招，右手一招，两招来路各异，令人难以抵档！"NOR"\n";
			break;
		}

		message_combatd(msg, me);
	}
	
    if(me->query_skill("sanfen-shengong"))
	{
					msgg = HIY "$N" HIY "身兼三分神功之术，似有三头六臂一般，奇出一招。"NOR"\n";
		result = do_perform(me, arg);
		message_combatd(msgg, me);
	}
	
	busy = me->query_busy();
	me->interrupt_busy(0);

	result = do_perform(me, and);
	if (! result)
		write(query_notify_fail());

	if (intp(busy) && intp(me->query_busy()) && busy > me->query_busy())
	{
		me->interrupt_busy(0);
		me->start_busy();
	}

	return 1;
}

private int do_perform(object me, string arg)
{
	object env,weapon;
	string martial, skill;
	int result;

	if (sscanf(arg, "%s.%s", martial, arg) != 2)
	{
		if (weapon = me->query_temp("weapon"))
			martial = weapon->query("skill_type");
		else
			martial = "unarmed";
	}

	me->clean_up_enemy();
	if (stringp(skill = me->query_skill_mapped(martial)))
	{
		if(me->query_temp("clear_pfm_mark"))
		{
			SKILL_D(skill)->clear_pfm_cd(me, arg);
			SKILL_D(martial)->clear_pfm_cd(me, arg);
			me->delete_temp("clear_pfm_mark");
		}
		notify_fail("技能CD中或你所使用的外功中没有这种功能。\n");
		env = environment(me);
		if (SKILL_D(skill)->perform_action(me, arg))
		{
			if (random(120) < (int)me->query_skill(skill))
				me->improve_skill(skill, 1, 1);
			if(env&&env->is_comb_ob()&&env->query("first")==me)
			{
				me->set_temp("pfm_cmd",1);
				env->delete("first");
			}
			return 1;
		} else
		if (SKILL_D(martial)->perform_action(me, arg))
		{
			if (random(120) < (int)me->query_skill(martial, 1))
				me->improve_skill(martial, 1, 1);
			if(env&&env->is_comb_ob()&&env->query("first")==me)
			{
				me->set_temp("pfm_cmd",1);
				env->delete("first");
			}
			return 1;
		}
		return 0;
	}

	return notify_fail("你现在的" + to_chinese(martial)[4..7] + "(" + martial + ")中并没有这种外功。\n");
}

int help (object me)
{
	write(@HELP
指令格式：perform | yong [<武功种类>.]<招式名称> [<施用对象>]
	  perform | yong 招式1 [<对象1>] and 招式2 [<对象2>]
	  perform | yong 招式1 [<对象1>] twice

如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或
招式，可以用这个指令来使用，你必须先用 enable 指令指定你使用
的武功，不指定武功种类时，空手的外功是指你的拳脚功夫，使用武
器时则是兵刃的武功。

若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳脚
跟武器技能的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，
如：

perform sword.chan

换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指
令使用。

如果你精通左右互搏，可以同时使用两个招式攻击同一对手或则分别
攻击两人。左右互搏修炼的越是精深，则成功率越高。

使用 twice 参数表示左右手使用同样的招式。
HELP );
	return 1;
}
