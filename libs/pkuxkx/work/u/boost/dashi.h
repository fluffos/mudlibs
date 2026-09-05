//dashi.h   

void give_reward();

void step(object me)
{
	int i, j, k, m, n ;
	mapping exits;
	string *dirs;
	object dashi, killer, env, *envs, *envs2;

	dashi = this_object();

	if(me == query("jobleader") && file_name(environment()) == "/d/wudang/zixiao" && !present("heiyi shashou"))
		return give_reward();


	if(me == query("jobleader") && me->query_temp("sljob/asked") >= 2 && !environment(me)->query("no_fight"))
	{
		if ((add_temp("sljob/go", 1) > 4 && !random(4)) || query_temp("sljob/go") > 6)
		{
			set_temp("sljob/go",0);
			set_heart_beat(0);
			set_heart_beat(1);
			killer = new("/d/shaolin/npc/killer");
			message_vision(HIR "突然从路边冲出一个黑衣杀手，直向$N冲去！\n"NOR, dashi);
			killer->set("dashi", dashi);
			killer->do_copy(query_temp("team" + random(query_temp("teamsize"))));
			killer->move(environment(dashi));
			if(killer)
				killer->set_leader(dashi);

			add_temp("sljob/total",1);
			if (!random(5)) 
			{
				message_vision(HIY"" + query("name")+"纵身奔向远方，杀手立刻提气追了上去！\n"NOR,me);
				envs=({file_name(environment(me))});
				for (m = 0; m < 2; m++) 
				{
					envs2 = envs;
					for (n = 0; n < sizeof(envs); n++) 
					{
						exits = envs[n]->query("exits");
						dirs = keys(exits);
						for (k = 0; k < sizeof(dirs); k++) 
						{
							env = envs[n]->query("exits/" + dirs[k]);
							if (env && !env->query("no_fight") && !env->query("sleep_room")) 
							{
								for (j=0; j < sizeof(envs2); j++)
									if(envs2[j] == env)
										break; 
								if (j == sizeof(envs2)) 
									envs2 = envs2 + ({env});
							}
						}
					}
					envs=envs2;
				}
				me->set_temp("env",envs);
				env = envs[random(sizeof(envs))];
				move(env);
				killer->move(env);
			}
			killer->start_busy(0);
			killer->command("kill " + query("id"));
		}
	}
}


void give_reward()
{
	object leader, dashi, member, dan;
	int i, teamsize, total_killer, total_exp, kill, exp, pot, repute;

	dashi = this_object();
	leader = query("jobleader");
	teamsize = query_temp("teamsize");

	command("nod");
	command("buddhi zhike daozhang");
	command("say 回去告诉方丈，老衲已经平安到达武当。保重！");
	CHANNEL_D->do_channel(dashi, "rumor",
		sprintf("%s护送"HIG"%s"HIM"到达武当！", leader->query("name"), dashi->query("name")));

	leader->delete("shaolin/on_husong");

	total_killer = query_temp("sljob/total");
	total_exp = total_killer * 3000;			//总exp，每个杀手3k
	total_exp = total_exp * teamsize / 2 ;		//teamsize 越大，系数越高, 

	for( i = 0; i < teamsize; i++)
	{
		member = query_temp("team"+i);
		if(member && present(member))
		{
			kill = member->query_temp("sljob/killed");
			//调整奖励算法  boost 2008-10-10

			if (kill > 20 ) kill = 10 + kill / 2;		//超过20，效果减半
			
			exp = total_exp * kill / total_killer;	//按自己杀掉的杀手数占总杀手数的比例分成

			if(member == leader)						//team leader 额外奖励
				exp = exp * 1.3;

			if(kill * teamsize > total_killer * 3 / 2)               //如果超过平均水平的1.5倍，奖励打一定的折扣，鼓励平均发展
				exp = exp / 1.5;

			exp = exp * 2/3 + random(exp*2/3);
			exp = exp * FACTOR_HS;

			if(member->query("combat_exp") < 30000000)
				exp = exp * 0.8;

			pot = exp / 6 + random(exp / 10);

			repute = kill * 400;
			repute = random(repute * 2/3) + repute * 2/3;


			//whuan 特殊周效果
			exp = exp * SPEWEEK_D->query_husong_bonus()/100;
			pot = pot * SPEWEEK_D->query_husong_bonus()/100;
			repute=repute * SPEWEEK_D->query_husong_bonus()/100;

			member->add("combat_exp", exp);
			member->add("exp/husong", exp);
			member->add("potential", pot);
			member->add("pot/husong", pot);
			member->add("repute",repute);

			member->add("sl_job", 1);
			member->add("jobs/completed/husong", 1);        //任务平衡系统，统计所有任务完成的次数  by boost  2008.09.19
			tell_object(member, HIW"好，任务完成，你得到了" 
				+ CHINESE_D->chinese_number( exp ) 
				+ "点实战经验和" 
				+ CHINESE_D->chinese_number( pot )
				+ "点潜能。\n" NOR);
			tell_object(member, HIR"你的声望增加了"+CHINESE_D->chinese_number( repute)+"点！\n"NOR);

			CHANNEL_D->do_channel(this_object(), "sys",
				sprintf("%s在护送任务中获得经验：%d、潜能：%d、声望%d。", member->name(), exp, pot, repute));


			log_file("nosave/husong", sprintf("%s %18s"
				+"，第%5d次，%2d个杀手，死%2d个，"
				+ "奖励%4d点\n", ctime(time())[4..15], 
				member->query("name")+"("+member->query("id")+")",
				member->query("sl_job"),query_temp("sljob/total"),
				member->query_temp("sljob/killed"),exp ) );
			member->set("shaolin/last_husong_exp", member->query("combat_exp"));
		}
		member->delete_temp("sljob"); 
	}
	call_out("leave",1);

	i = random(teamsize);
	member = query_temp("team"+i);
	if (member && present(member) && random(4)==1 ) 
	{
		tell_object(member, HIG"你从" + query("name") + "那里得到了一颗大还丹。\n" NOR);
		dan = new("/d/shaolin/obj/dahuan-dan");
		if (dan)
		{
			dan->set("owner",member->query("id"));
			dan->move(member);
		}
	}
	return;
}
