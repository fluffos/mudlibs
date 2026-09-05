/*
  长安城爵位任务的公共函数库以及公共数据存放对象
  by seagate@pkuxkx
  
  所有爵位任务中公共的任务属性如下：
  expiring_time 超时时间，超过这个时间没有被领走的任务或者已经被领走未完成的任务会被自动清除
                   这里被领走任务超时时间含义指的是任务完成的最后截止时间，未领走任务超时时间
                   指的是任务可以被领走的截止时间
  start_time    任务起始时间，指的是创建这个任务的时间，并一定指的是玩家领走任务的时间
  update_time   任务更新时间，每次更新任务状态都会同步更新这个时间
  level         任务级别，主要指的是发布是针对那一级别爵位的任务
  name          任务名称
  status        任务状态，0-创建 1-领取 2-完成 3-失败
  user          用户id，指的是任务处于领取或者以后状态的时候领走该任务的玩家
  
*/
inherit F_TREEMAP;

mapping quest_info=([]);
int quest_index;

void create()
{
	quest_index=100;
	seteuid(getuid());
}

//设置任务信息，keyid为该任务的唯一索引，prop为任务的相关属性，data为属性对应的值
mixed set_quest(string keyid, string prop, mixed data)
{
	if( !mapp(quest_info) ) quest_info = ([]);
	
	if( !keyid )
		error("任务唯一索引不能为空。\n");
	
	if( !mapp(quest_info[keyid]) ) quest_info[keyid] = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( quest_info[keyid], explode(prop, "/"), data );


	return quest_info[keyid][prop] = data;
}

//查询任务信息，keyid为该任务唯一索引
mixed query_quest(string keyid, string prop)
{
	mixed data;

	if( !mapp(quest_info) ) return 0;
		
	if( !keyid )
		error("任务唯一索引不能为空。\n");
	
	if( !mapp(quest_info[keyid]) ) return 0;

	if( undefinedp(quest_info[keyid][prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(quest_info[keyid], explode(prop, "/"));
	else
		data = quest_info[keyid][prop];

	return data;
}

//删除任务信息中某个属性，keyid为该任务唯一索引
int delete_quest(string keyid, string prop)
{
	if( !mapp(quest_info) ) return 0;
		
	if( !keyid )
		error("任务唯一索引不能为空。\n");
	
	if( !mapp(quest_info[keyid]) ) return 0;

	if( strsrch(prop, '/')!=-1 )
		return _delete(quest_info[keyid], explode(prop, "/"));
	else {
		map_delete(quest_info[keyid], prop);
		return 1;
	}
}

//任务属性中某个值做加法运算，keyid为该任务唯一索引
mixed add_quest(string keyid, string prop, mixed data)
{
	mixed old;
	int databonus;

	if( !keyid )
		error("任务唯一索引不能为空。\n");
		
	if( !mapp(quest_info) ) quest_info = ([]);

	if( !mapp(quest_info[keyid]) || !(old = query_quest(keyid, prop)) )
		return set_quest(keyid, prop, data);

	if( functionp(old) )
		error("长安城爵位任务: add_quest() - called on a function type property.\n");

	return set_quest(keyid, prop, old + data);
}

//清理过期的任务数据，任务属性expiring_time决定是否超时，对于超时任务自动清除
//未配置属性expiring_time的任务就不会受到自动清除的影响，需要由具体任务自己决
//定何时清理数据。
//被标记为失败的任务也会被清除（status属性为3的任务）
//当输入任务唯一标志并且该任务处于2（成功）或者3（失败），则会被直接强制清除
varargs void clean_quest(string keyid)
{
	string *klist;
	int lp;
	
	if ( stringp(keyid) )
	{
		if ( query_quest(keyid, "status")>=2 )
			map_delete(quest_info, keyid);
		return;
	}
	
	klist=keys(quest_info);
	for(lp=0;lp<sizeof(klist);lp++)
	  if ( (quest_info[klist[lp]]["expiring_time"] && 
	  	    time()>=quest_info[klist[lp]]["expiring_time"] &&
	  	    quest_info[klist[lp]]["status"]<=1 ) ||                              //超时任务（未领取的任务/已领取未完成任务）
	  	   ( quest_info[klist[lp]]["status"]>=2 &&
	  	     time()>=quest_info[klist[lp]]["update_time"]+600 ) )                //成功/失败任务，任务最后更新时间后保留10分钟 
	  	map_delete(quest_info, klist[lp]);
}

//判断该任务目前是否存在，0表示不存在该任务，1表示存在该任务
int is_quest(string keyid)
{
	if ( !mapp(quest_info) || !mapp(quest_info[keyid]) )
		return 0;
	
	return 1;
}

//判断玩家是否能够操作该任务，返回1表示合法性检查通过，0表示合法性检查失败
//输入值status指的是想要任务达到的状态，不是指的是任务目前的状态，如果该输入值
//为-1则不进行status匹配相关的检查
int valid_quest(string keyid, object player, int status)
{
	if ( !objectp(player) )
		return 0;
	
	if ( !userp(player) )
		return 0;
	
	if ( !is_quest(keyid) )
	{
		tell_object(player, "任务「"+query_quest(keyid, "name")+"」不存在。\n");
		return 0;
	}

  if ( query_quest(keyid, "status")>=1 &&
	     query_quest(keyid, "user")!=player->query("id") )
	{
		tell_object(player, "任务「"+query_quest(keyid, "name")+"」并不是你的任务。\n");
		return 0;
	}
	
	if ( !status )
	  error("不能把任务修改成创建状态，该状态由系统自动产生。\n");
	
	if ( status<0 )
		return 1;
	else
	{
		if ( status==1 &&
			   query_quest(keyid, "status") )
		{
			tell_object(player, "任务「"+query_quest(keyid, "name")+"」已被领取。\n");
			return 0;
		}
		
		if ( status>1 &&
			   query_quest(keyid, "status")!= 1 )
		{
			tell_object(player, "任务「"+query_quest(keyid, "name")+"」未处于已领取未完成状态，不能置完成标志。\n");
			return 0;
		}
	}
	
	return 1;
}

//获得某一种爵位任务的完整的任务列表信息
mapping query_quests(int level)
{
	mapping ret;
	string *klist;
	int lp;
	
	ret=([]);
	klist=keys(quest_info);
	for(lp=0;lp<sizeof(klist);lp++)
	{
		if ( quest_info[klist[lp]]["level"]==level )
			ret[klist[lp]]=quest_info[klist[lp]];
	}
	return ret;
}

//初始化任务信息，输入任务级别level和任务名称name
//返回值是任务唯一索引
string init_quest(int level, string name)
{
	string keyid;
  quest_index++;
	keyid=sprintf("%d_%d", level, quest_index);  //产生任务唯一索引
	set_quest(keyid, "level", level); //设置任务级别信息
	set_quest(keyid, "name", name);   //设置任务名称
	set_quest(keyid, "status", 0);    //设置任务状态，0-创建 1-已领取 2-完成 3-失败
	set_quest(keyid, "start_time", time()); //设置任务起始时间
	set_quest(keyid, "update_time", time()); //设置任务状态变更时间
	return keyid;
}

//领取任务，将该任务状态置为1，记录领取任务玩家
//返回值 -1表示任务不存在，0表示领取失败，1表示领取成功
int get_quest(string keyid, object player)
{
	if ( !is_quest(keyid) )
	{
		tell_object(player, "任务「"+query_quest(keyid, "name")+"」不存在。\n");
		return -1;
	}
	
	if ( !valid_quest(keyid, player, 1) )
		return 0;
		
	set_quest(keyid, "status", 1);
	set_quest(keyid, "update_time", time());
	set_quest(keyid, "user", player->query("id"));
	return 1;
}

//完成任务，分为两种状态，其中flag为0表示任务成功，1表示任务失败
//返回值 -1表示任务不存在，0表示置完成任务失败，1表示置完成任务成功
int complete_quest(string keyid, object player, int flag)
{
	int status;
	
	if ( !flag )
		status=2;
	else
		status=3;
	
	if ( !is_quest(keyid) )
	{
		tell_object(player, "不存在的任务序号「"+keyid+"」。\n");
		return -1;
	}
	
	if ( !valid_quest(keyid, player, status) )
		return 0;
	
	set_quest(keyid, "status", status);
	set_quest(keyid, "update_time", time());
	return 1;
}

//获取奖励，奖励受到爵位影响，高爵位任务完成者爵位不够将不会获得任何奖励
int get_reward(string keyid, object player, int level)
{
	object reward;
	int diff, base, point, cashflag;
	
	//首先检查任务基本合法性，获取奖励的时候不用修改任务信息（任务信息
	if ( !valid_quest(keyid, player, -1) )
		return 0;
	
	//检查任务状态是否处于完成状态，未处于完成状态则不能领取奖励
	if ( query_quest(keyid, "status")!=2 )
	{
		tell_object(player, "任务「"+query_quest(keyid, "name")+"」未完成，不能领取奖励。\n");
		return 0;
	}
	
	//玩家爵位与任务爵位差距大于1的时候不能获得任务奖励
	if ( player->query("changan/level") < level-1 )
	{
		tell_object(player, "这个任务所需要的爵位远比你拥有的爵位高，不能给你任何奖励。\n");
		return 0;
	}
	
	//检查玩家身上的任务完成标志
	if ( !player->query("changan/lv"+level+"/success") )
	{
		tell_object(player, "任务「"+query_quest(keyid, "name")+"」未完成，不能领取奖励。\n");
		return 0;
	}
	
	if ( player->query("combat_exp")<= level*level*1000000 &&
	     player->query("antirobot/deactivity")<=2 &&
	     random(100)<5 )
	{
	  reward=new("/clone/money/thousand-cash");
	  reward->move(player);
	  cashflag=1;
	}
	else
	  cashflag=0;
	
	diff=query_quest(keyid, "difficulty")+1;  //难度系数
	base=player->query("changan/lv"+level+"/success");   //奖励基数
	//奖励计算实例
	//案例一：假设难度系数1，基础奖励1，则获得任务积分2点
	//案例二：假设难度系数2，基础奖励1，则获得任务积分4点
	//案例三：假设难度系数3，基础奖励1，则获得任务积分12点
	//案例四：假设难度系数4，基础奖励1，则获得任务积分24点
	//案例五：假设难度系数5，基础奖励1，则获得任务积分30点
	//基本上可以认为难度1，2属于比较容易的一个档次，难度3属于中间档次，难度4，5则属于极难档次
	//另外有一个设定就是当高爵位玩家完成低爵位任务的时候，奖励减半
	//任务积分分为两种，第一种事当低爵位玩家完成高爵位任务的时候积累在升级积分上，爵位升级就自动清零
	//当完成同等爵位任务或者低爵位任务的时候积累的例外积分上，用来兑换物资
	point=base*2*diff*(1+diff/3+diff/4);
	if ( player->query("changan/level") < level )
	{	
	  player->add("changan/points", point );
	  if ( cashflag )
	    tell_object(player, "由于你的突出贡献，特奖励你一张银票，并奖励任务积分"+chinese_number(point)+"点，用于提升爵位。\n");
	  else
	    tell_object(player, "由于你的突出贡献，特奖励任务积分"+chinese_number(point)+"点，用于提升爵位。\n");
	}
	else
	{
		if ( player->query("changan/level") != level )
			point=point/2;
		
		player->add("changan/ext_points", point );
		if ( cashflag )
		  tell_object(player, "由于你的突出贡献，特奖励你一张银票，并奖励任务积分"+chinese_number(point)+"点，用于兑换本爵位相关的任务奖励。\n");
		else
		  tell_object(player, "由于你的突出贡献，特奖励任务积分"+chinese_number(point)+"点，用于兑换本爵位相关的任务奖励。\n");
	}
		  
	player->delete("changan/lv"+level);
	return 1;
}
