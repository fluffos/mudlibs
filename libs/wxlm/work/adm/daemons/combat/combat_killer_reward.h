// called when winner hit the victim to unconcious
void winner_reward(object winner, object victim)
{
	object owner;
	int temp;
	int td;
	mapping today;

	owner = winner->query_temp("owner");
	if (objectp(owner))
		winner = owner;

	winner->defeated_enemy(victim);

	if (! playerp(winner) || wizardp(victim) && 0)
		return;

	if (! winner->is_want_kill(victim->query("id")))
		// only if I want kill ob, I will record it.
		return;

	winner->add("combat/DPS", 1);
	if (victim->is_not_bad())  winner->add("combat/DPS_NOTBAD", 1);
	if (victim->is_not_good()) winner->add("combat/DPS_NOTGOOD", 1);
	if (victim->is_bad())      winner->add("combat/DPS_BAD", 1);
	if (victim->is_good())     winner->add("combat/DPS_GOOD", 1);

	if (victim->query_condition("killer"))
		return;

	if (victim->query("combat_exp") < 150)
		return;

	log_file("nosave/killrecord",
		 sprintf("%s %s defeat %s\n",
			 log_time(), log_id(winner), log_id(victim)));

	td = time() / 86400;
	today = winner->query("combat/today");
	if (! mapp(today) || today["which_day"] != td)
	{
		today = ([ "which_day" : td,
			   "total_count" : 1,
			   victim->query("id") : 1, ]);
	} else
	{
		// count how many times that winner hit the victim to unconcious
		temp = ++today[victim->query("id")];
		if (temp == query("pk_perman"))
		{
			// reach limit
			tell_object(winner, BLINK HIR "\n今天你已经打晕" +
				    victim->name() + chinese_number(temp) +
				    "次了，手下留"
				    "情吧，否则麻烦可要找上门了。"NOR"\n");
		} else
		if (temp > query("pk_perman"))
			// too many times
			winner->set("combat/need_punish", "这厮逼人太甚，真是岂有此理！");

		// count how many users that winner hit to unconcious
		temp = ++today["total_count"];
		if (temp == query("pk_perday"))
		{
			// reach limit
			tell_object(winner, BLINK HIR "\n今天你已经打晕" +
				    chinese_number(temp) + "次玩家了，手下留"
				    "情吧，否则麻烦可要找上门了。"NOR"\n");
		} else
		if (temp > query("pk_perday"))
			// too many users
			winner->set("combat/need_punish", "丧尽天良，大肆屠戮，罪无可恕！");
	}
	winner->set("combat/today", today);
}

void killer_reward(object killer, object victim)
{
	object owner;
	string vmark;
	object box,*inv;
	string msg = "莫名其妙地死了";
	string follow_msg = 0;
	object weapon;
	mapping actions;
	int i,shen_delta;
	mapping ks, vs, kcombat;
	int win_exp;
	if (! objectp(victim))
		return;

	if (objectp(killer))
	{
		owner = killer->query_temp("owner");
		if (objectp(owner))
			killer = owner;
	}

	// This while is only to enable "break"
	vs = victim->query_entire_dbase();
	while (1)
	{
		if (! objectp(killer))
			break;

		// call the killer's override function
		killer->killed_enemy(victim);

		if (! objectp(killer) || ! playerp(killer))
			break;

		// assure the killer's dbase
		ks = killer->query_entire_dbase();
		if (! mapp(kcombat = ks["combat"]))
		{
			kcombat = ([ ]);
			ks["combat"] = kcombat;
		}

		// adjust the "shen" & "experience" of the killer
		if (ks["combat_exp"] < vs["combat_exp"])
		{
			win_exp=1;

			if(random(20)==1)
			{
				tell_object(killer,"\n"HIM"<恭喜>:"NOR"  你"HIR"杀死了"NOR+victim->query("name")+HIG", 奖励:"GRN"【初级宝箱】"NOR"... "HIY"  <额外经验>: "NOR+HIG+win_exp+YEL+" ↑" NOR"\n");
				box=new("/clone/box/chuji_box"); 
				box->move(environment(killer));
			}

			ks["combat_exp"]+=win_exp;
			
			if (ks["combat_exp"] >= 100000 && ks["combat_exp"] >= vs["combat_exp"] * 2 / 3)
			{
				// adjust experience
				if (! intp(ks["experience"]))
					ks["experience"] = 0;
				killer->improve_experience(1 + random(5));
			}

			// adjust shen
			shen_delta = -vs["shen"] / 10;
			if (shen_delta > 100)
			{
				// 非线性校正获得的正神
				shen_delta = (shen_delta - 100) / 3 + 100;

				if (shen_delta > 200)
					shen_delta = (shen_delta - 200) / 3 + 200;

				if (shen_delta > 300)
					shen_delta = (shen_delta - 300) / 3 + 300;
			} else
			if (shen_delta < -100)
			{
				// 非线性校正获得的负神
				shen_delta = (shen_delta + 100) / 3 - 100;

				if (shen_delta < -200)
					shen_delta = (shen_delta + 200) / 3 - 200;

				if (shen_delta < -300)
					shen_delta = (shen_delta + 300) / 3 - 300;
			}
					
			ks["shen"] += shen_delta;
		}

		// weapon get the bonus
		if ((weapon = killer->query_temp("weapon")) ||
		    (weapon = killer->query_temp("armor/hands")))
			weapon->killer_reward(killer, victim);

		// record the user's killing
		if (userp(victim))
		{
			if (! intp(kcombat["PKS"]))
				kcombat["PKS"] = 1;
			else
				kcombat["PKS"]++;

			// do family action
			FAMILY_D->family_kill(killer, victim);

			// do league action
			LEAGUE_D->league_kill(killer, victim);

			if (victim->query_condition("killer"))
			{
				follow_msg = "听说杀人凶手" + victim->name(1) + "被" + killer->name(1) + "在" +
					     environment(victim)->short() + HIM"就地正法了。";
				break;
			}

			if (! killer->is_want_kill(vs["id"]))
				break;

			if (! intp(kcombat["WPK"]))
				kcombat["WPK"] = 1;
			else
				kcombat["WPK"]++;

			if (! killer->query_condition("killer"))
			{
				follow_msg = "听说官府发下海捕文书，缉拿杀人凶手" + killer->name(1) + "。";
				killer->apply_condition("killer", 900);
			} else
			{
				follow_msg = "听说官府加紧捉拿累犯重案的暴徒" + killer->name(1) + "。";
				killer->apply_condition("killer", 900 + (int)killer->query_condition("killer"));
			}

			// assure data of kcombat
			if (! intp(kcombat["WPK_NOTBAD"])) kcombat["WPK_NOTBAD"] = 0;
			if (! intp(kcombat["WPK_NOTGOOD"])) kcombat["WPK_NOTGOOD"] = 0;
			if (! intp(kcombat["WPK_GOOD"])) kcombat["WPK_GOOD"] = 0;
			if (! intp(kcombat["WPK_BAD"])) kcombat["WPK_BAD"] = 0;

			// record the combat info.
			if (victim->is_not_bad())  kcombat["WPK_NOTBAD"]++;
			if (victim->is_not_good()) kcombat["WPK_NOTGOOD"]++;
			if (victim->is_good())     kcombat["WPK_GOOD"]++;
			if (victim->is_bad())      kcombat["WPK_BAD"]++;
			break;
		}

		if (vs["can_speak"])
			if (! intp(kcombat["MKS"]))
				kcombat["MKS"] = 1;
			else
				kcombat["MKS"]++;

		break;
	}

	// die penalty & message of victim
	if (playerp(victim)&&victim->query("combat_exp")<5000000)
	{
		int is_killer = victim->query_condition("killer");
		// clear punish info.
		if (objectp(killer) && killer->is_punisher())
			victim->delete("combat/need_punish");

		// 清除所有状态
		victim->clear_condition();
		// 如果之前是通缉犯，恢复通缉状态
		if (is_killer > 0)
			victim->apply_condition("killer", is_killer);

		// remove vendetta
		map_delete(vs, "vendetta");

		// generate message of die reason
		if (objectp(killer) && killer->is_character())
		{
			msg = "在与" + filter_color(killer->name(1)) + "的交战中";
			actions = killer->query_action();
			switch (mapp(actions) ? actions["damage_type"] : "杀伤") {
			case "擦伤":
			case "割伤":
				msg+="败亡了（擦伤）";
				break;
			case "刺伤":
				msg+="败亡了（刺伤）";
				break;
			case "震伤":
			case "瘀伤":
				msg+="败亡了（震伤）";
				break;
			case "内伤":
				msg+="败亡了（内伤）";
				break;
			default:
				msg+="败亡了";
			}
		}
		if (stringp(victim->query_temp("die_reason")))
			msg = filter_color(victim->query_temp("die_reason"));

		victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + msg + "。", victim->name(1)));

		// show the follow msg after victim die
		if (follow_msg)
			CHANNEL_D->do_channel(this_object(), "rumor", follow_msg);

		tell_object(victim,HIM + "新手保护期[<20万经验]免去了你的死亡惩罚" + NOR"\n");
		victim->start_busy(15);
		victim->set("combat/last_die", filter_color(msg));
		if (objectp(killer) && playerp(killer) && playerp(victim))
		{
   
   

			log_file("nosave/killrecord",
				 sprintf("%s %s killed %s\n",
					 log_time(),
					 log_id(killer), log_id(victim)));

			killer->remove_killer(victim);
		}
	}
	else if (playerp(victim)&&victim->query_temp("kuilei_used"))
	{

		int killer_level;

		killer_level = victim->query_condition("killer");
		// clear punish info.
		if (objectp(killer) && killer->is_punisher())
			victim->delete("combat/need_punish");

		// clear all condition
		victim->clear_condition();


		//恢复通缉状态
		if (killer_level > 0)
		{
			victim->apply_condition("killer",killer_level);
		}

		// remove vendetta
		map_delete(vs, "vendetta");

		// generate message of die reason
		if (objectp(killer) && killer->is_character())
		{
			msg = "被" + filter_color(killer->name(1));
			actions = killer->query_action();
			switch (mapp(actions) ? actions["damage_type"] : "杀伤") {
			case "擦伤":
			case "割伤":
				msg+="砍死了";
				break;
			case "刺伤":
				msg+="刺死了";
				break;
			case "震伤":
			case "瘀伤":
				msg+="击死了";
				break;
			case "内伤":
				msg+="震死了";
				break;
			default:
				msg+="杀死了";
			}
		}
		if (stringp(victim->query_temp("die_reason")))
			msg = filter_color(victim->query_temp("die_reason"));

		victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + msg + "。", victim->name(1)));

		// show the follow msg after victim die
		if (follow_msg)
			CHANNEL_D->do_channel(this_object(), "rumor",
					      follow_msg);

		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + "使用了替身傀儡免去了死亡惩罚。", victim->name(1)));

		victim->set("combat/last_die", filter_color(msg));
		if (objectp(killer) && playerp(killer) && playerp(victim))
		{
   
   

			log_file("nosave/killrecord",
				 sprintf("%s %s killed %s\n",
					 log_time(),
					 log_id(killer), log_id(victim)));

			killer->remove_killer(victim);
		}
	}
	else if (playerp(victim))
	{
		// clear punish info.
		if (objectp(killer) && killer->is_punisher())
			victim->delete("combat/need_punish");

		// clear all condition
		victim->clear_condition();

		// adjust shen
		vs["shen"] -= vs["shen"] / 10;

		// adjust combat exp.
		vs["combat_exp"] -= vs["combat_exp"] * 2 / 100;

		// adjust weiwang
		vs["weiwang"] -= vs["weiwang"] / 10;

		// adjust score
		vs["score"] -= vs["score"] / 10;

		// remove vendetta
		map_delete(vs, "vendetta");

		// lost half of potential
		if (vs["potential"] > vs["learned_points"] && vs["combat_exp"] > 337500)
			vs["potential"] += (vs["learned_points"] - vs["potential"]) / 1;

		// lost half of experience
		if (vs["experience"] > vs["learned_experience"])
			vs["experience"] += (vs["learned_experience"] - vs["experience"]) / 1;

		victim->skill_death_penalty();
		inv = all_inventory(victim);
		for(i=0;i<sizeof(inv);i++)
		{
			if(inv[i]->is_item_make()&&inv[i]->query("equipped"))
				inv[i]->owner_death_penalty();
		}

		// generate message of die reason
		if (objectp(killer) && killer->is_character())
		{
			msg = "被" + filter_color(killer->name(1));
			actions = killer->query_action();
			switch (mapp(actions) ? actions["damage_type"] : "杀伤") {
			case "擦伤":
			case "割伤":
				msg+="砍死了";
				break;
			case "刺伤":
				msg+="刺死了";
				break;
			case "震伤":
			case "瘀伤":
				msg+="击死了";
				break;
			case "内伤":
				msg+="震死了";
				break;
			default:
				msg+="杀死了";
			}
		}
		if (stringp(victim->query_temp("die_reason")))
			msg = filter_color(victim->query_temp("die_reason"));

		victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + msg + "。", victim->name(1)));

		// show the follow msg after victim die
		if (follow_msg)
			CHANNEL_D->do_channel(this_object(), "rumor",follow_msg);

		victim->set("combat/last_die", filter_color(msg));
		if (objectp(killer) && playerp(killer) && playerp(victim))
		{
			string cname;
			object couple;

			log_file("nosave/killrecord",
				 sprintf("%s %s killed %s\n",
					 log_time(),
					 log_id(killer), log_id(victim)));

			killer->remove_killer(victim);

			// check sadly
			cname = victim->query("couple/id");
			if (cname &&
			    victim->query("gender") == "女性" &&
			    victim->query("combat_exp") >= 970000 &&
			    objectp(couple = find_player(cname)) &&
			    couple != killer &&
			    couple->query("nosave/marry") <= 1 &&
			    victim->query("nosave/marry") <= 1)
			{
				couple->add("nosave/sadly", 1);
				tell_object(couple, "你的妻子死在了" +
					    killer->name(1) + "的手下" +
					    "，你感到了一阵深深的哀伤。\n");
			}
		}
	}

	if (stringp(vmark = victim->query("vendetta_mark")) && objectp(killer))
		killer->add("vendetta/" + vmark, 1);
}