// chuniang.c



void auto_cook(object me)
{
	if(!me||!interactive(me)) return;
	if(!me->query_temp("pending/auto_cook"))
		return;
	if(me->is_busy())
		call_out("auto_cook",1,me);
	else if( (int)me->query("jing") < me->query("eff_jing"))
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < me->query("eff_jing"))
			{
				tell_object(me,"精力不足，等待恢复中。。。\n");
				call_out("auto_cook",1,me);
			}
			else
			{
				call_out("auto_cook",1,me);
			}
		}
		else
		{
			tell_object(me,"精力不足，等待恢复中。。。\n");
			call_out("auto_cook",1,me);
		}
	}
	else
	{
		tell_object(me,"托管中，继续工作。。。。。。\n");
		tell_object(me,ZJFORCECMD("ask "+this_object()->query("id")+" about 工作"));
	}
}

string ask_job()
{
	object me;
 

	me = this_player();

	if (me->query("combat_exp") < 1000)
		return "呦，你这点本事啊，端得动盘子么？";

	if (me->query("jing") < 50) 
		return "你还是休息会儿吧，小心把身子累垮了！";
	
	if (!query("max_exp"))
		return "我无法提供服务，可能管理没给我指派任务，请联系管理！";
	//炒菜经验上限
	if (me->query("combat_exp") > query("max_exp"))
		return "这位女侠，你这不是折杀小的吗！你还是去前面用餐吧！饭菜马上就好！";

	if (me->query_skill("cooking") < 60)
		return "你的炒菜手艺那么差，那里能帮我？";

	if (me->query_skill_mapped("cooking") != "chuancai-jiyi")
		return "我说你知不知道来的客人可都是吃川菜的，亮出你川菜的活儿再说！";

	if (! interactive(me))
		return "...";
/*
	obs = filter_array(all_inventory(environment()),
			   (: interactive($1) &&
			      $1 != $(me) &&
			      $1->query_temp("job/cook") &&
			      query_ip_number($1) == query_ip_number($(me)) :));*/
	//if (sizeof(obs) > 0)
	//	return "这儿有" + obs[0]->name() + "呢，你还是别费心了。";

	me->set_temp("job/cook", 1);
	tell_object(me,ZJFORCECMD("cook"));
	tell_object(me,ZJEXIT"northwest:"RED"中断工作"NOR":halt\n");
	return "好吧，你就帮我"ZJURL("cmds:cook")ZJSIZE(15)"炒菜"NOR"(cook)吧！菜在这儿，灶台在那边。";
}

int recognize_apprentice(object ob, string skill)
{
	if ((int)ob->query_temp("mark/厨娘") < 1)
		return 0;

	if (skill != "cooking" && skill != "chuancai-jiyi")
	{
		command("say 你打住...我可只会做菜烧饭。");
		return -1;
	}

	ob->add_temp("mark/厨娘", -1);
	return 1;
}

int accept_object(object who, object ob)
{
 

	if ((int)who->query_temp("mark/厨娘") < 1)
		who->set_temp("mark/厨娘", 0);

	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision("厨娘同意指点$N一些关于炒菜的常识和技巧。\n", who);
		who->add_temp("mark/厨娘", ob->value() / 50);
		destruct(ob);
		return 1;
	}

	command("say 虽说炒菜对闯荡江湖没什么用，我也不能白白教你"
		"啊！拿来，辛苦费纹银二十两，童叟无欺！");
	return 0;
}

int do_cook(string arg)
{
	object me;

	me = this_player();
	if (me->is_busy())
		return notify_fail("你正忙着呢，别着急。\n");

	if (! me->query_temp("job/cook"))
	{
		tell_object(me, "厨娘喝道：你要干什么？不要来捣乱，我忙着呢！\n");
		return 1;
	}

	me->set_temp("job/step", 1);
	me->set_temp("pending/auto_cook", 1);
	me->start_busy(bind((: call_other, __FILE__, "cooking" :), me),
		       bind((: call_other, __FILE__, "halt_cooking" :), me));
	tell_object(me, "你拿起蔬菜，走到一边坐下，开始拣菜。\n");
	return 1;
}

int cooking(object me)
{
	string msg;
	int finish;
	int gain_exp, gain_pot, gain_money;
	mixed *local;
	
	if (! me->query_temp("job/step"))
		me->set_temp("job/step", 1);

	if (! living(me))
	{
		me->delete_temp("job/cook");
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("jing", 8);
	switch (me->query_temp("job/step"))
	{
	case 1:
		msg = "$N看看菜差不多够了，站起身来走到水盆边开始洗菜。";
		break;
	case 2:
		msg = "哗----，$N将水盆中的污水倒掉，菜也洗干净了。";
		break;
	case 3:
		msg = "$N走到灶台前开始切菜，嚓----嚓-----。";
		break;
	case 4:
	case 6:
		msg = "$N将油到入锅中，继续切菜。";
		break;
	case 5:
		msg = "油热了，冒出阵阵清烟，$N将切好的菜到入锅中！滋------";
		break;
	case 7:
		msg = "$N不断翻动锅中的菜，慢慢的，一阵香味散发出来。";
		break;
	default:
		msg = "$N在锅中加入调料，又翻动了几下，将炒好的菜铲到盘中，拿给$n。";
		finish = 1;
		break;
	}
	msg += "\n";

	if (finish)
	{
		object ob;
		msg += "$n看了$N炒的菜，又夹了两片尝了尝，满意的点点头"
		       "这是给你的报酬！你可以在我这里学点炒菜技术。\n";
		me->delete_temp("job/cook");
		me->delete_temp("job/step");
		gain_money = 2+random(6);
		me->add_temp("mark/厨娘", random(30));
		me->improve_skill("cooking", 10 + random(10));

		// 奖励的经验为10加20的随机数（较多）， money为100加炒菜技
		// 术的等级取随机数（较多），潜能为不超过3点，主要还是以加
		// silver为主。
		ob = new("/clone/money/coin");
		ob->set_amount(gain_money);
		ob->move(me, 1);
		call_out("auto_cook",2,me);
	}

	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

	if (finish)
	{
		if (me->query("combat_exp") >= 50000)
		{
			write(MAG "你隐隐约约的发现炒菜居然和武功有一些相通之处，真是奇妙。"NOR"\n");
			gain_exp = 15 + random(11);
			gain_pot = (gain_exp * 4) / 3;
			
			local = localtime(time());
			if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 ) {
				gain_exp *= 2;//开服挂机奖励翻倍。一周?还是？
				gain_pot *= 2;//开服挂机奖励翻倍。一周?还是？
			}
			me->add("combat_exp", gain_exp);
			me->improve_potential(gain_pot);
			msg = HIC "你获得了"+chinese_number(gain_money)+"个铜板、" + chinese_number(gain_exp) + "点经验";
			if (gain_pot)
				msg += "和" + chinese_number(gain_pot) + "点潜能。"NOR"\n";
			else
				msg += "。"NOR"\n";
			tell_object(me,  msg);
		}
		return 0;
	}

	me->add_temp("job/step", 1);
	return 1;
}

int halt_cooking(object me)
{
	message_vision("$N揉揉腰部，又扭了扭，叹到：这也太难了，我还是去闯荡江湖吧！\n", me);
	me->delete_temp("job/cook");
	me->delete_temp("pending/auto_cook");
	me->delete_temp("job/step");
	return 1;
}