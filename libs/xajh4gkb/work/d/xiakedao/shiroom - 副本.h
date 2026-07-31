int do_study(string arg)
{
	string *skill_name = ({
		"strike",          //1赵客缦胡缨
		"sword",           //2吴钩霜雪明
		"dodge",           //3银鞍照白马
		"throwing",        //4飒沓如流星
		"pixie-jian",      //5十步杀一人 sword
		"qiankundanuoyi",	//6千里不留行 dodge
		"lingboweibu",     //7事了拂衣去 dodge
		"qimen-wuxing",   //8深藏身与名 dodge
		"unarmed",         //9闲过信陵饮 cuff or strike or unarmed
		"qimen-flee",      //10脱剑膝前横 sword
		"parry",           //11将炙啖朱亥
		"blade",           //12持觞劝侯嬴
		"axe",              //13三杯吐然诺 force 暂时先count吧
		"whip",            //14五狱倒为轻 cuff or strike or unarmed
		"staff",           //15眼花耳热后   鲁达禅杖
		"taoism",          //16竞气素霓生 cuff or strike or unarmed
		"hammer",          //17救赵挥金锤 sword
		"buddhism",        //18邯郸先震惊 force
		"hubo",            //19千秋二壮士
		"xiaowuxiang",      //20亘赫大梁城 force
		"checking",        //21纵死侠骨香   指法
		"club",            //22不惭世上英   齐眉棍
		"kuihua-xinfa",    //23谁能书阁下
		"taixuan-gong"     //24白首太玄经
		});
	
	object me, where;
	int jing_cost, learn_pot, item, times, i, success=0;		
		
	me = this_player();
	where = environment(me);
	jing_cost = 100 + random(me->query_int())/10;
	learn_pot = 100 + random(me->query_kar())/10;		
//	if (!wizardp(me)) 
//		return notify_fail("哎呀，巫师大人将侠客岛封闭了，现在这里只能观光旅游。\n");	
	if( !arg ) 
		return notify_fail("你要领悟什么呀？\n");		
	if( sscanf(arg, "%s %d", arg, times)!=2)
		return notify_fail("指令格式：think wall <次数>\n");
	if( ( arg != "wall" ) )
		return notify_fail("指令格式：think wall <次数>\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");		
	if (times < 1 || times > 50)
		return notify_fail("领悟次数最少是一次，最多是五十次。\n");
	if ((int)me->query("xyzx_sys/level") < 1000)
		return notify_fail("你的实战能力太低, 没法领悟石壁内容。\n");
	if( me->query("jing") < jing_cost * times)
		return notify_fail("你的精太少了，领悟这么多次也不怕精尽人亡，休息一会儿再来吧。\n");
	if( me->query("qi") < learn_pot * times)
		return notify_fail("你的气太少了，领悟这么多次也不怕噎死，休息一会儿再来吧。\n");	
		
	switch (file_name(where))
	{
		case "/d/xiakedao/shiroom01": item = 0; break;
		case "/d/xiakedao/shiroom02": item = 1; break;
		case "/d/xiakedao/shiroom03": item = 2; break;
		case "/d/xiakedao/shiroom04": item = 3; break;
		case "/d/xiakedao/shiroom05": item = 4; break;
		case "/d/xiakedao/shiroom06": item = 5; break;
		case "/d/xiakedao/shiroom07": item = 6; break;
		case "/d/xiakedao/shiroom08": item = 7; break;
		case "/d/xiakedao/shiroom09": item = 8; break;
		case "/d/xiakedao/shiroom10": item = 9; break;
		case "/d/xiakedao/shiroom11": item = 10; break;
		case "/d/xiakedao/shiroom12": item = 11; break;
		case "/d/xiakedao/shiroom13": item = 12; break;
		case "/d/xiakedao/shiroom14": item = 13; break;
		case "/d/xiakedao/shiroom15": item = 14; break;
		case "/d/xiakedao/shiroom16": item = 15; break;
		case "/d/xiakedao/shiroom17": item = 16; break;
		case "/d/xiakedao/shiroom18": item = 17; break;
		case "/d/xiakedao/shiroom19": item = 18; break;
		case "/d/xiakedao/shiroom20": item = 19; break;
		case "/d/xiakedao/shiroom21": item = 20; break;
		case "/d/xiakedao/shiroom22": item = 21; break;
		case "/d/xiakedao/shiroom23": item = 22; break;
		case "/d/xiakedao/shiroom24": item = 23; break;
		default: break;
	}
		
//	if ((int)me->query_skill("literate",1)<1 && item !=23)	//取消侠客岛面壁要求读书为0的不合理要求
//		return notify_fail("你晕了吧! 还是先去学点文化吧。\n");
			
	message_vision("$N正在钻研石壁上的图案和注释。\n",me);
	me->start_busy(1);
		
	for (i = 1; i<=times; i++)
	{
		me->receive_damage("jing",jing_cost);
		// 不是互搏或太玄则要求最低等级100
		if ( me->query_skill(skill_name[item],1) < 100 )
		{
			if(item != 23 && item != 18)
			{
				write("你望着石壁冥思苦想了一会，发觉上面的东西对你来说太深奥了。\n");
				return 1;
			}
		}
		// 限制20000为上限
		if ( me->query_skill(skill_name[item],1) >= 30000 )
		{
			write("你望着石壁冥思苦想了一会，发觉上面的东西对你来说太浅薄了。\n");
			return 1;
		}
		
		if ( item == 4 || item == 22 )
		{
			//辟邪剑法和葵花心法要求太监
			if ( (string)me->query("gender") != "无性" )
			{
				write("可是壁上是辟邪剑法图谱，欲练神功，必先自宫。\n");
				return 1;
			}
			// 限制辟邪等级上限5000级
			if ( item == 4 && me->query_skill("pixie-jian", 1) >= 5000 )
			{
				write("你的辟邪剑法已经无法再提高了。\n");
				return 1;
			}
		} else
		{
			if( !SKILL_D(skill_name[item])->valid_learn(me) )
				return SKILL_D(skill_name[item])->valid_learn(me);
		}
			
		//if( (int)(me->query_skill(skill_name[item],1) * me->query_skill(skill_name[item],1) * 81 ) >= me->get_levelup_exp()/2*1.0*(me->query("xyzx_sys/level")+1) )
		if(me->query("xyzx_sys/level")*5 < me->query_skill(skill_name[item],1))
		{
			write("你实战经验不够，对着石壁冥思苦想了一会，毫无收获。\n");
			return 1;
		}
			
			
			
		if (learn_pot > 0)
		{				
			if( item == 22 )// 葵花心法
			{
				me->improve_skill(skill_name[item], (me->query_kar()/2000+me->query_int()/2000)+100, 1);
				me->add("qi", -learn_pot);
				success = 1;
			}
			else if( item == 4 || item == 5 ) // 辟邪剑法 | 乾坤大挪移
			{
				me->improve_skill(skill_name[item], (me->query_kar()/2000+me->query_int()/2000)+100, 1);
				me->add("qi", -learn_pot);
				success = 1;
			}
			else if( item == 23 || item == 19 ) // 太玄功 | 小无相
			{
				if ( me->query("kar",1) >= 30 )
				{
					me->improve_skill(skill_name[item], (me->query_kar()/2000+me->query_int()/2000)+100, 1);
					me->add("qi", -learn_pot);
					success = 1;
				}
			}
			else if ( me->query_skill(skill_name[item], 1) > 15000 )
			{
				me->improve_skill(skill_name[item], (me->query_kar()/1500+me->query_int()/1500)+100, 1);
				me->add("qi",-learn_pot);
				success=1;
			}
			else
			{
				me->improve_skill(skill_name[item], (me->query_kar()/1000+me->query_int()/1000)+100, 1);
				me->add("qi",-learn_pot);
				success=1;
			}
		}
	}
		
	if (success == 1)
		write("你对着石壁冥思苦想了"+chinese_number(times)+"回，似乎对"+CHINESE_D->chinese(skill_name[item])+"有些心得。\n");
	else
		write("你对着石壁冥思苦想了一会，可是成见太深，似乎没啥心得。\n");
	success=0;
	
	return 1;
}
