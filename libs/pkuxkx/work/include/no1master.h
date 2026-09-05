int query_other_family_force(object me)
{
	mapping sks;
	string *sname;
	int i;
	string sk, fam;
	mapping family_force_skills = ([
		"明教": ({"guangming-shenghuogong",}),
		"全真派": ({"xiantian-gong",}),
		"少林派": ({"yijin-jing","hunyuan-yiqi",}),
		"峨嵋派": ({"linji-zhuang",}),
		"丐帮": ({"huntian-qigong",}),
		"雪山派": ({"xueshan-neigong",}),
		"华山派": ({"zixia-shengong","huashan-neigong",}),
		"天龙寺": ({"beiming-shengong","kurong-shengong","shanjue",}),
		"武当派": ({"taiji-shengong",}),
		"日月神教": ({"xixing-dafa","riyue-shengong","kuihua-shengong",}),
		"古墓派": ({"yunu-xinfa","jiuyin-shengong",}),
		"姑苏慕容": ({"shenyuan-gong",}),
		"桃花岛": ({"bihai-shengong",}),
		"白驼山": ({"hamagong",}),
		"大轮寺": ({"longxiang-boruo",}),
		"灵鹫宫": ({"bahuang-gong","xiaowuxiang-gong","beiming-shengong",}),
		"神龙教": ({"shenlong-xinfa",}),
		"天地会": ({"cangming-gong",}),
		"星宿派": ({"huagong-dafa","xiaowuxiang-gong",}),
		"朝廷": ({"bixue-xinfa","jiuyin-shengong",}),
	]);
	sks = me->query_skills();
	if (sizeof(sks)<=0) return 0;
	fam = this_object()->query("family/family_name");
	if (!fam || undefinedp(family_force_skills[fam])) return 0;
	sname = sort_array( keys(sks), (: strcmp :) );
	for (i=0;i<sizeof(sname);i++)
	{
		sk = sname[i];
		if ( !find_object(SKILL_D(sk)) && file_size(SKILL_D(sk)+".lpc") < 0 ) 
			continue;
		if ( SKILL_D(sk)->valid_enable("force") && member_array(sk, family_force_skills[fam])==-1 )
			return 1;
	}
	return 0;
}

int ask_ningshen()
{
	object pl, me;
	int pflv, lv, pot1, pot2, pot3, pot4, fami;
	mapping add;
	mapping purefamily_ningshen = ([
		"明教": (["qi":80,"jing":80,]),
		"全真派": (["qi":110,"jing":150,]), 
		"少林派": (["qi":110,"jing":50,]),
		"峨嵋派": (["qi":150,"jing":120,]),
		"丐帮": (["qi":120,"jing":100,]),
		"雪山派": (["qi":140,"jing":120,]),
		"华山派": (["qi":90,"jing":110,]),
		"天龙寺": (["qi":70,"jing":130,]),
		"武当派": (["qi":50,"jing":150,]),
		"日月神教": (["qi":120,"jing":110,]),
		"古墓派": (["qi":100,"jing":120,]),
		"姑苏慕容": (["qi":120,"jing":110,]),
		"桃花岛": (["qi":140,"jing":120,]),
		"白驼山": (["qi":130,"jing":100,]),
		"大轮寺": (["qi":120,"jing":110,]),
		"灵鹫宫": (["qi":150,"jing":130,]),
		"神龙教": (["qi":160,"jing":110,]),
		"天地会": (["qi":180,"jing":140,]),
		"星宿派": (["qi":110,"jing":120,]),
		"朝廷": (["qi":130,"jing":130,]),
	]);
	pl = this_player();
	me = this_object();
	if(pl->query("family/family_name") != query("family/family_name"))
	{
		command("kick");
		command("say 你一个" + pl->query("family/family_name") +"的弟子，来我们" + query("family/family_name") + "捣什么乱？");
		return 1;
	}
	pflv = (int)pl->query("purefamily/level");
	if (pflv>0 && pl->query("purefamily/family_name") != query("family/family_name"))
	{
		command("say 你一个" + pl->query("purefamily/family_name") + "的内门弟子，来我们" + query("family/family_name") + "捣什么乱？");
		return 1;
	}
	if (pl->query_temp("purefamily/ningshen"))
	{
		command("say 你已经领会了凝神入静，不要捣乱！");
		return 1;
	}
	if (pflv<4)
	{
		command("say 在你融会贯通本派的内功精义之前，我无法引导你进入凝神入静的忘我状态。");
		return 1;
	}
	fami = FAMILY_D->get_family_order(query("family/family_name"));
	if (fami<0) fami = 0;
	
	command("nod");
	message_vision("$n在$N跟前盘膝坐下，$N伸出一掌抵在$p后心「灵台穴」，运气引导$p进入凝神入静的忘我状态。\n"NOR, me, pl);
	pl->start_busy(5);
	pl->set_temp("purefamily/ningshen", 1);

	lv = (int)pl->query("level");
	add = purefamily_ningshen[query("family/family_name")];

	pot1 = lv*lv;
	if (add["jing"]) pot1 = pot1*add["jing"]/100;
	if (pflv>=5) pot1 += pot1*5/10;
	pot1 += (pot1*fami/20);
	pl->add_temp("apply/max_jing", pot1);
	pl->set_temp("purefamily/max_jing", pot1);
	pl->set("max_jing", pl->query_max_jing());
	pl->add("eff_jing", pot1);
	pl->add("jing", pot1);
	
	pot2 = lv*lv;
	if (add["qi"]) pot2 = pot2*add["qi"]/100;
	if (pflv>=5) pot2 += pot2*5/10;
	pot2 += (pot2*fami/20);
	pl->add_temp("apply/max_qi", pot2);
	pl->set_temp("purefamily/max_qi", pot2);
	pl->set("max_qi", pl->query_max_qi() );
	pl->add("eff_qi", pot2);
	pl->add("qi", pot2);
	pl->set_temp("active_force_buffer/ningshenrujing/name", "凝神入静");              //buff名称
	pl->set_temp("active_force_buffer/ningshenrujing/effect1", "最大气血+"+pot2+"点");//效果描述1   
	pl->set_temp("active_force_buffer/ningshenrujing/effect2", "最大精神+"+pot1+"点");//效果描述2
	
	pot3 = (pflv>4)?15:5;
	pl->set_temp("purefamily/weekinjure", pot3);
    pl->add_temp("apply/kf_def_wound", pot3);
    pl->add_temp("apply/week_injure", pot3);
	pl->set_temp("active_force_buffer/ningshenrujing/effect3", "伤害抗性提高+"+pot3+"%");//效果描述2
	return 1;
}

int ask_purefamily()
{
	object pl, me, drug;
	int pflv, exp;
	pl = this_player();
	me = this_object();
	exp = pl->query("combat_exp");
	if (pl->query_temp("purefamily_confirm"))
		message_vision(HIC"$N紧握双拳，对$n斩钉截铁地说道：「我意已决，绝无更改！」\n"NOR, pl, me);
	else
	{
		if (me->query("family/family_name") == "朝廷")
			message_vision(HIC"$N单膝下跪，对着$n说道：「我发誓，永远效忠吾皇陛下，忠贞不二，此心可昭日月、至死不移！」\n"NOR, pl, me);	
		else
			message_vision(HIC"$N对着$n慷慨激昂地说道：「我生于斯，长于斯，将来也必长眠于斯，愿在本门终老！」\n"NOR, pl, me);		
	}
	if(pl->query("family/family_name") != query("family/family_name"))
	{
		command("applaud");
		command("say 好听好听，说得真好听！不过嘛……这跟我们" + query("family/family_name") + "有啥关系啊？");
		command("say 你还是回你们" + pl->query("family/family_name") +"去表忠心吧！");
		return 1;
	}
	if (pl->query("chushi") || pl->query("betrayer") || pl->query("betrayer_history") )
	{
		message_vision(HIY"结果$n只鄙夷地瞥了$N一眼，就把头扭了过去，呸地一声往地上啐了一口！\n"NOR, pl, me);
		command("say 抛弃师门之人，竟也有脸面说这等话，简直是恬不知耻！");
		return 1;
	}
	if ( exp < 50000000 ) // 50m
	{
		command("kick");
		command("say 说得比唱得还好听，还不赶紧去练功！等你有点真本事了再来表忠心！");
		return 1;
	}
	pflv = (int)pl->query("purefamily/level");
	if (pflv>0 && pl->query("purefamily/family_name") != query("family/family_name"))
	{
		if (pl->query("family/family_name") == "朝廷")
			command("say 你一个朝廷命官，来我们" + query("family/family_name") + "捣什么乱？");
		else
			command("say 你一个" + pl->query("purefamily/family_name") + "的内门弟子，来我们" + query("family/family_name") + "捣什么乱？");
		return 1;
	}
	if (query_other_family_force(pl))
	{
		command("shake");
		if (me->query("family/family_name") == "朝廷")
			command("say 你兼修歪门邪道的内功心法，心境不纯，我如何放心让你效忠朝廷、承领重任？");
		else
			command("say 你兼修外派内功心法，心境不纯，我如何放心引你入门成为内门弟子？");
		return 1;
	}
	if ( pflv < 1 )  // 提升记名弟子 lv=1
	{
		if (!pl->query_temp("purefamily_confirm"))
		{
			pl->set_temp("purefamily_confirm", 1);
			message_vision(HIW"$n看着$N赞许地点了点头，流露出满怀欣慰的神情！\n"NOR, pl, me);
			if (me->query("family/family_name") == "朝廷")
				command("say 我煌煌天朝可不是那些江湖草莽，一旦确定，便没有反悔之途！");
			else
				command("say 终老本门可不是闹着玩的，一旦确定，便没有反悔之途！");
			command("say 如果你心意已决，就把刚才的话再重复一遍！");
		}
		else 
		{
			pl->delete_temp("purefamily_confirm");
			message_vision(HIW"$N双掌一拍，十分欣慰地说道：「好！」\n"NOR, me);
			if (me->query("family/family_name") == "朝廷")
			{
				command("say 圣上有旨："+pl->query("name")+"素有贤名，可堪重用，授任" HIR "团练使" NOR + CYN "一职！");
				command("say 从今日起，你便是真正的朝廷命官了！待你学武有成，再奏请圣上予以擢升！");
				pl->set("title" ,HIR + "大宋" + NOR + MAG " 御封" + CYN "团练使" NOR);
			}
			else
			{
				command("say 既然如此，从今日起，你便是本门的心腹弟子了！");
				command("say 看你一片忠心，就先收你作个内门" HIR "记名弟子" NOR + CYN "吧！待你学武有成，再行擢升！");
				pl->set("title" ,HIR + query("family/family_name") + NOR + MAG " 内门" + CYN "记名弟子" NOR);
			}
			tell_object(pl, HIY"你获得了一个新头衔！\n"NOR);
			pl->set("purefamily/level", 1);
			pl->set("purefamily/family_name", query("family/family_name"));
			pl->set_title(TITLE_FAMILY, pl->query("title"));
			if (!pl->query("purefamily/xisui"))
			{
				drug=new("/obj/remedy/drug/xisuidan");
				if (objectp(drug))
				{
					drug->set("owner", pl->query("id"));
					drug->move(pl);
					message_vision("$N郑重其事地从怀中掏出一个小瓷瓶，递给了$n。\n", me, pl);
					command("say 这里有一颗灵丹妙药，助你强身健体，要尽快服下。遗失不补，切记切记！");
				}
			}
		}
		return 1;
	}
/*	if (!pl->query("purefamily/xisui")) // 没正常吃到伐毛洗髓丹的，遗失是否要补？
	{
		drug=new("/obj/remedy/drug/xisuidan");
		if (objectp(drug))
		{
			drug->set("owner", pl->query("id"));
			drug->move(pl);
			message_vision("$N郑重其事地从怀中掏出一个小瓷瓶，递给了$n。\n", me, pl);
			command("say 这里有一颗灵丹妙药，助你强身健体，要尽快服下。");
			return 1;
		}
	}  */
	if ( exp < 100000000 )  // 50-100m
	{
		if (me->query("family/family_name") == "朝廷")
			command("say 说得好！你已是御封团练使，还要多加努力，为朝廷忠心效命！");
		else
			command("say 说得好！你已是内门记名弟子，还要多加努力，为光大本门多多出力！");
		return 1;
	}
	if ( pflv < 2 )  // 记名弟子 提升为 入门弟子
	{
		if((int)pl->query("reborn/all")>=1) //过劫难
		{
			if((int)pl->query("myVeins/level")<1)
			{
				if (me->query("family/family_name") == "朝廷")
					command("say 看你武功不错，但经脉修为还不够。至少需要打通一条经脉，才能让你升任处置使！");
				else
					command("say 看你武功不错，但经脉修为还不够。至少需要打通一条经脉，才能让你成为本门入门弟子！");
			}
			else
			{
				if ((int)pl->query("score") < 20000)
				{
					if (me->query("family/family_name") == "朝廷")
						command("say 看你武功修为不错，但还需多为朝廷尽心效命，才能让你担当更大的责任！");
					else
						command("say 看你武功修为不错，但还需多为本门尽心出力，才能让你担当更大的责任！");
				}
				else if( (int)pl->query("potential") - (int)pl->query("learned_points") < 200000 )
				{
					command("say 你的武学潜能不足，还要多加努力才是！");
				}
				else
				{
					if (me->query("family/family_name") == "朝廷")
					{
						command("say 圣上有旨："+pl->query("name")+"御侮折冲，朝寄尤切，可领" HIR "防御使" NOR + CYN "一职，馀并如故！");
						pl->set("title" ,HIR + "大宋" + NOR + MAG " 御封" + HIY "防御使" NOR);
					}else{
						command("say 看你武功修为不错，这便擢升你为内门" HIR "入门弟子" NOR + CYN "吧！");
						pl->set("title" ,HIR + query("family/family_name") + NOR + MAG " 内门" + HIY "入门弟子" NOR);
					}
					tell_object(pl, HIY"你获得了一个新头衔！\n"NOR);
					pl->set("purefamily/level", 2);
					pl->add("score", -10000);
					pl->add("potential", -200000);
					pl->add("combat_exp", -500000);
					pl->set_title(TITLE_FAMILY, pl->query("title"));
					tell_object(pl, HIW + query("name") + HIW"为你解说了一番本派轻功的武学精义，令你顿觉豁然开朗！\n"NOR);
				}
			}
		}
		else 
		{
			command("say 看你武功修为不错，但还需经过劫难考验，才能让你担当更大的责任！");
		}
		return 1;
	}
	if ( exp < 200000000 )  // 100-200m
	{
		if (me->query("family/family_name") == "朝廷")
			command("say 说得好！你已是御封防御使，还要多加努力，为朝廷忠心效命！");
		else
			command("say 说得好！你已是内门入门弟子，还要多加努力，为光大本门多多出力！");
		return 1;
	}
	if ( pflv < 3 )  // 入门弟子 提升为 入室弟子
	{
		if(pl->query("laxiang/done")) //做蜡像
		{
			if((int)pl->query("myVeins/level")<2)
			{
				if (me->query("family/family_name") == "朝廷")
					command("say 看你武功不错，但经脉修为还不够。需要打通第二层经脉，才能让你升任观察使！");
				else
					command("say 看你武功不错，但经脉修为还不够。需要打通第二层经脉，才能让你成为本门入室弟子！");
			}
			else
			{
				if ((int)pl->query("score") < 30000)
				{
					if (me->query("family/family_name") == "朝廷")
						command("say 看你武功修为不错，但还需多为朝廷尽心效命，才能让你担当更大的责任！");
					else
						command("say 看你武功修为不错，但还需多为本门尽心出力，才能让你担当更大的责任！");
				}
				else if( (int)pl->query("potential") - (int)pl->query("learned_points") < 1000000 )
				{
					command("say 你的武学潜能不足，还要多加努力才是！");
				}
				else
				{
					if (me->query("family/family_name") == "朝廷")
					{
	// 节度使（爰始缔构，功参鼎业），承宣使（宇量凝邈，志识明劭），观察使，防御使，团练使
						command("say 圣上有旨："+pl->query("name")+"任惟勋德，实伫亲贤，可领" HIR "观察使" NOR + CYN "一职，馀并如故！");
						pl->set("title" ,HIR + "大宋" + NOR + MAG " 御封" + HIC "观察使" NOR);
					}else{
						command("say 看你武功修为不错，这便擢升你为内门" HIR "入室弟子" NOR + CYN "吧！");
						pl->set("title" ,HIR + query("family/family_name") + NOR + MAG " 内门" + HIC "入室弟子" NOR);
					}
					tell_object(pl, HIY"你获得了一个新头衔！\n"NOR);
					pl->set("purefamily/level", 3);
					pl->add("score", -15000);
					pl->add("potential", -1000000);
					pl->add("combat_exp", -2000000);
					pl->set_title(TITLE_FAMILY, pl->query("title"));
					tell_object(pl, HIW + query("name") + HIW"为你解说了一番本派外功的武学精义，令你顿觉豁然开朗！\n"NOR);
				}
			}
		}
		else 
		{
			command("say 看你武功修为不错，但还需完成蜡像制作，在江湖上扬名立万，才能让你担当更大的责任！");
		}
		return 1;
	}
	if ( exp < 400000000 )  // 200-400m
	{
		command("say 说得好！你已是内门入室弟子，还要多加努力，为光大本门多多出力！");
		return 1;
	}
	if ( pflv < 4 )  // 入室弟子 提升为 嫡传弟子
	{
		if((int)pl->query("safari_credit")>=20) //铜雀积分
		{
			if((int)pl->query("myVeins/level")<3)
			{
				command("say 看你武功不错，但经脉修为还不够。需要打通第三层经脉，才能让你成为本门嫡传弟子！");
			}
			else
			{
				if ((int)pl->query("score") < 40000)
				{
					command("say 看你武功修为不错，但还需多为本门尽心出力，才能让你担当更大的责任！");
				}
				else if( (int)pl->query("potential") - (int)pl->query("learned_points") < 2000000 )
				{
					command("say 你的武学潜能不足，还要多加努力才是！");
				}
				else
				{
					command("say 看你武功修为不错，这便擢升你为内门" HIR "嫡传弟子" NOR + CYN "吧！");
					tell_object(pl, "你花费了20点铜雀台积分！\n");
					tell_object(pl, HIY"你获得了一个新头衔！\n"NOR);
					pl->set("purefamily/level", 4);
					pl->add("score", -20000);
					pl->add("safari_credit", -20);
					pl->add("potential", -2000000);
					pl->add("combat_exp", -4000000);
					pl->set("title" ,HIR + query("family/family_name") + NOR + MAG " 内门" + HIG "嫡传弟子" NOR);
					pl->set_title(TITLE_FAMILY, pl->query("title"));
					tell_object(pl, HIW + query("name") + HIW"为你解说了一番本派内功的武学精义，令你顿觉豁然开朗！\n"NOR);
				}
			}
		}
		else 
		{
			command("say 看你武功修为不错，但江湖历练还不够。至少需要耗费20点铜雀积分，才能让你成为本门嫡传弟子！");
		}
		return 1;
	}
	if ( exp < 800000000 )  // 400-800m
	{
		command("say 说得好！你已是内门嫡传弟子，还要多加努力，为光大本门多多出力！");
		return 1;
	}
	if ( pflv < 5 )  // 嫡传弟子 提升为 真传弟子
	{
		if((int)pl->query("safari_credit")>=60) //铜雀积分
		{
			if((int)pl->query("myVeins/level")<5)
			{
				command("say 看你武功不错，但经脉修为还不够。需要打通第五层经脉，才能让你成为本门真传弟子！");
			}
			else
			{
				if ((int)pl->query("score") < 60000)
				{
					command("say 看你武功修为不错，但还需多为本门尽心出力，才能让你担当更大的责任！");
				}
				else if( (int)pl->query("potential") - (int)pl->query("learned_points") < 5000000 )
				{
					command("say 你的武学潜能不足，还要多加努力才是！");
				}
				else
				{
					command("say 看你武功修为不错，这便擢升你为内门" HIR "真传弟子" NOR + CYN "吧！");
					tell_object(pl, "你花费了60点铜雀台积分！\n");
					tell_object(pl, HIY"你获得了一个新头衔！\n"NOR);
					pl->set("purefamily/level", 5);
					pl->add("score", -30000);
					pl->add("safari_credit", -60);
					pl->add("potential", -5000000);
					pl->add("combat_exp", -10000000);
					pl->set("title" ,HIR + query("family/family_name") + NOR + MAG " 内门" + HIW "真传弟子" NOR);
					pl->set_title(TITLE_FAMILY, pl->query("title"));
					tell_object(pl, HIW + query("name") + HIW"为你解说了一番本派武学总纲，你顿觉融会贯通，完全掌握了本派武学的全部奥秘！\n"NOR);
				}
			}
		}
		else 
		{
			command("say 看你武功修为不错，但江湖历练还不够。至少需要耗费60点铜雀积分，才能让你成为本门真传弟子！");
		}
		return 1;
	}
	command("say 说得好！你已是内门真传弟子，乃是本门精英中的精英，光大本门的重任就全靠你了！");
	return 1;
}
	
int ask_score()
{
	object pl = this_player();
	if(pl->query("family/family_name") != query("family/family_name"))
	{
		command("?");
		command("say 阁下非本派中人，不知因何有此一问？");
	}
	else if(pl->query("combat_exp") > 10000000 && !pl->query("buchang_score") && time() < 1261371791+86400*5)
	{
		command("say 你对门派多年忠心耿耿，为师这些年一直看在眼里。");
		tell_object(pl,"你的师门忠诚度提高了500点！\n" );
		pl->add("score",500);
		pl->set("buchang_score",1);
	}
	return 1;
}
int ask_dadizi()
{
	object pl = this_player();
	string dadizi = FAMILY_D->get_dadizi(query("family/family_name"));
	int sc;
	if (find_player(dadizi))
		sc = find_player(dadizi)->query("score");
	if (sc>5000)
		sc = 5000; 
	if(pl->query("family/family_name") != query("family/family_name"))
	{
		command("?");
		command("say 阁下非本派中人，不知因何有此一问？");
	}
	else
	{
		if (pl->query("betrayer")>0)
		{
			command("say 你是屡次判师之人，担任掌门大弟子，恐怕难以服众。！");
			return 1;
		}
//		if (pl->query("id") != dadizi && !find_player(dadizi) && pl->query("score") > 2000)
//  修改：如果大弟子已经离开原门派，则询问时换新大弟子。by lordstar@2017-10-10
		if (pl->query("id") != dadizi && (!find_player(dadizi) || (find_player(dadizi)->query("family/family_name") != query("family/family_name"))) && pl->query("score") > 2000)
			{
			command("haha");
			CHANNEL_D->do_channel(this_object(), "jh", query("family/family_name")+"今日任命新的掌门大弟子:"+pl->query("name"));
			pl->set_temp("apply/title",pl->query("title")+ " " + HIY"掌门大弟子"NOR);
			pl->set_title(TITLE_MASTER, "『"HIM+query("family/family_name")+NOR"』"HIY"掌门大弟子"NOR);
			FAMILY_D->set_top_score(query("family/family_name"), pl->query("score"));
			FAMILY_D->set_dadizi(query("family/family_name"), pl->query("id"),pl->query("name"));
		  }
		else if (pl->query("id") != dadizi && find_player(dadizi) && pl->query("score") > sc && pl->query("combat_exp") > find_player(dadizi)->query("combat_exp")*0.75)
		{
			command("haha");
			CHANNEL_D->do_channel(this_object(), "jh", query("family/family_name")+"今日任命新的掌门大弟子:"+pl->query("name"));
			pl->set_temp("apply/title",pl->query("title")+ " " + HIY"掌门大弟子"NOR);
			pl->set_title(TITLE_MASTER, "『"HIM+query("family/family_name")+NOR"』"HIY"掌门大弟子"NOR);
			FAMILY_D->set_top_score(query("family/family_name"), pl->query("score"));
			FAMILY_D->set_dadizi(query("family/family_name"), pl->query("id"),pl->query("name"));
		}
		else if (pl->query("id") != dadizi && find_player(dadizi) && pl->query("score") > sc*0.75 && pl->query("combat_exp") > find_player(dadizi)->query("combat_exp")*1.5)
		{
			command("haha");
			CHANNEL_D->do_channel(this_object(), "jh", query("family/family_name")+"今日任命新的掌门大弟子:"+pl->query("name"));
			pl->set_temp("apply/title",pl->query("title")+ " " + HIY"掌门大弟子"NOR);
			pl->set_title(TITLE_MASTER, "『"HIM+query("family/family_name")+NOR"』"HIY"掌门大弟子"NOR);
			FAMILY_D->set_top_score(query("family/family_name"), pl->query("score"));
			FAMILY_D->set_dadizi(query("family/family_name"), pl->query("id"),pl->query("name"));
		}
		else
		{
			if(pl->query("id") != dadizi)
			{
				command("say 你还不够资格，扪心自问，你对师门做了多少？");
				command("say 现在的掌门大弟子是"+FAMILY_D->get_dadizi_name(query("family/family_name")));
			}
			else
			{
				command("say 乖徒儿，你就是掌门大弟子啊！");
			}
		}
	}
	return 1;
}

int ask_suicong()
{
	//门忠3000以上就可以有随从。但是随从等级受门派威望排行的控制
	object pl = this_player();
	object suicong;
	int factor;
	int number;

	if(pl->query("family/family_name") != query("family/family_name"))
	{
		command("?");
		command("say 阁下非本派中人，不知因何有此一问？");
		return 1;
	}

	if(pl->query("score") < 3000)
	{
		command("say 你在本门资历太浅，没有资格获得随从。\n");
		return 1;
	}

	if(objectp(pl->query("suicongdizi/npc")))
	{
		command("say 你把你的随从派到哪里去了？是不是死了！?\n");
		return 1;
	}
	
	if(time() - pl->query("suicongdizi/last_ask") < 3600)
	{
		command("say 本派目前人手不够。\n");
		return 1;		
	}
	
	number = FAMILY_D->get_family_order(pl->query("family/family_name"));
	if(number < 0)
	{
		command("cry");
		command("本派破败弱小，根本无人可派！");
	}
	else
	{
		//factor 是1到10，第一名的是10
		factor = 10/number;
		if(factor == 0) factor = 1;

		suicong = new("/clone/npc/dizi");
		suicong->set_up_dizi(pl,factor);
		suicong->move(environment(pl));

		command("say 这是我指派给你的随从，你要好好对待。\n");
		pl->set("suicongdizi/npc",suicong);
		
		pl->set("suicongdizi/last_ask",time());
	}
	return 1;
}

void setup_no1master()
{
	mapping inquiry = query("inquiry");
	if(!mapp(inquiry)) inquiry = ([]);
	inquiry["掌门大弟子"] =  (: ask_dadizi :);
	inquiry["门忠"] =  (: ask_score :);
	inquiry["随从"] =  (: ask_suicong :);
	if (query("family/family_name") == "朝廷")
		inquiry["宣誓效忠"] =  (: ask_purefamily :);
	else
		inquiry["终老师门"] =  (: ask_purefamily :);
	inquiry["凝神入静"] =  (: ask_ningshen :);
	set("inquiry",inquiry);
}

int no1master()
{
	return 1;
}