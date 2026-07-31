
#include <skill.h>

int do_study(string arg)
{
//2018-11-30阿飞改，侠客岛将只作为基本技能或知识型技能的面壁
	string *skill_name = ({
		"strike",			//1赵客缦胡缨
		"sword",			//2吴钩霜雪明
		"dodge",			//3银鞍照白马
		"throwing",			//4飒沓如流星
		"shayi",			//5十步杀一人
		"duji",				//6千里不留行
		"cuff",				//7事了拂衣去
		"poison",			//8深藏身与名
		"unarmed",			//9闲过信陵饮
		"force",			//10脱剑膝前横
		"parry",			//11将炙啖朱亥
		"blade",			//12持觞劝侯嬴
		"axe",				//13三杯吐然诺
		"whip",				//14五狱倒为轻
		"staff",			//15眼花耳热后
		"ninjitsu",			//16竞气素霓生
		"hammer",			//17救赵挥金锤
		"dagger",			//18邯郸先震惊
		"hubo",				//19千秋二壮士
		"spear",			//20亘赫大梁城
		"finger",			//21纵死侠骨香
		"club",				//22不惭世上英
		"hand",				//23谁能书阁下
		"taixuan-gong"		//24白首太玄经
		});		
	object me, where;
	int jineng_exp_add,huiyuan,mianbi_add;
	int jing_cost, learn_pot, item, times, i,add_pot, success=0;		
		
	me = this_player();
	where = environment(me);
	jing_cost = 100 + random(me->query_kar()*me->query("kar",1));
	learn_pot = 100 + random(me->query_kar()*me->query("kar",1));
	if(jing_cost<100) jing_cost=100;
	if(learn_pot<100) learn_pot=100;
	
//	if (!wizardp(me)) 
//		return notify_fail("侠客岛面壁有点问题，暂时先禁止，检查错误。\n");	
	if( !arg ) 
		return notify_fail("你要领悟什么呀？\n");		
	if( sscanf(arg, "%s %d", arg, times)!=2)
		return notify_fail("指令格式：think wall <次数>\n");
	if( ( arg != "wall" ) )
		return notify_fail("指令格式：think wall <次数>\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");		
	if (times < 1 || times > 5)
		return notify_fail("领悟次数最少是一次，最多是五次。\n");
	if ((int)me->query("xyzx_sys/level") < 5000)
		return notify_fail("你的实战能力太低, 没法领悟石壁内容。\n");
	if( me->query("jing") < jing_cost * times)
		return notify_fail("你的精太少了，领悟这么多次也不怕精尽人亡，休息一会儿再来吧。\n");
	if( me->query("neili") < learn_pot * times)
		return notify_fail("你的气太少了，领悟这么多次也不怕噎死，休息一会儿再来吧。\n");	
	if( me->query("potential") < (learn_pot+jing_cost)*times)
		return notify_fail("你的潜能太少了，已经不能在领悟了。\n");
	
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
	if ( time() < me->query("mianbi_add_time") ) mianbi_add=2;
	else mianbi_add=1;
	if(me->query("xyhy_type")==2) huiyuan = 5/4;	//2016.6.20阿飞改，黄金会员自练速度为1.25倍
	else huiyuan = 1;
	if (me->query_temp("jineng_exp_add")) jineng_exp_add = (int)me->query_temp("jineng_exp_add",1);	//处于技能自练提升状态时	
	else jineng_exp_add = 0;
	add_pot = (100+me->query_kar()*me->query("kar",1)*10-me->query_int()*me->query("int",1)*3)*me->query_exp_times()*mianbi_add*huiyuan*(jineng_exp_add+100)/100;
	if(add_pot<100) add_pot=100;
//	if(add_pot>5000000) add_pot=5000000;
	for (i = 1; i<=times; i++)
	{
		if ( me->query_skill(skill_name[item],1) < 5000 )
		{// 不是太玄则要求最低等级5000
			if(item != 23)
			{
				write("你望着石壁冥思苦想了一会，发觉上面的东西对你来说太深奥了。\n");
				return 1;
			}
		}
		// 限制30000为上限
		if ( me->query_skill(skill_name[item],1) > 30000 )
		{
			write("你望着石壁冥思苦想了一会，发觉上面的东西对你来说太浅薄了。\n");
			return 1;
		}
		
		if ( item == 23  )
		{// 限制限制太玄功上限2000级
			if ( me->query_skill("taixuan-gong", 1) > 2000 )
			{
				write("你的太玄功已经无法再提高了。\n");
				return 1;
			}
		} else
		{
			if( !SKILL_D(skill_name[item])->valid_learn(me) )
				return SKILL_D(skill_name[item])->valid_learn(me);
		}
		
		if((me->query("xyzx_sys/level",1)+100)*5 < me->query_skill(skill_name[item],1))
		{
			write("你实战经验不够，对着石壁冥思苦想了一会，毫无收获。\n");
			return 1;
		}

		if (learn_pot > 0 || jing_cost > 0)
		{
			if( item == 23 ) //太玄功
			{
				if ( me->query("kar",1) > 30 && (int)me->query_skill("literate",1) <= 1)
				{
					me->improve_skill(skill_name[item], add_pot*1/10);
//					me->improve_skill(skill_name[item], add_pot*1/10, 1);	//这里的0或1似乎与系统双倍有关系，不清楚哪一种写法是双倍生效
					me->add("neili", -learn_pot);
					me->add("jing",-jing_cost);
					me->add("potential", -(jing_cost+learn_pot)/10);
					success = 1;
				}
			}
			else if ( me->query_skill(skill_name[item], 1) > 15000 )
			{
				me->improve_skill(skill_name[item], add_pot*36/10);
//				me->improve_skill(skill_name[item], add_pot*36/10, 1);	//这里的0或1似乎与系统双倍有关系，不清楚哪一种写法是双倍生效
				me->add("neili",-learn_pot);
				me->add("jing",-jing_cost);
				me->add("potential", -(jing_cost+learn_pot)/25);
				success=1;
			}
			else
			{
				me->improve_skill(skill_name[item], add_pot*30/10);
//				me->improve_skill(skill_name[item], add_pot*30/10, 1);	//这里的0或1似乎与系统双倍有关系，不清楚哪一种写法是双倍生效
				me->add("neili",-learn_pot);
				me->add("jing",-jing_cost);
				me->add("potential", -(jing_cost+learn_pot)/25);
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
