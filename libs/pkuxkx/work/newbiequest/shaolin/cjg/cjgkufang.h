// 库房统一处理头文件 包括 chakan（查看当前房间的奖励物品兑换列表）
// duihuan（兑换奖励物品）
// 库房分为damagebook - 武功秘籍 budbook - 佛经 otherbook - 知识类技能 
//         equip - 装备   lyao - 普通丹药 hyao - 高级丹药
// 六大类。
// by seagate@pkuxkx 2011.02.18

//奖励物品配置列表
#include "cjgreward.h"

mapping filter_reward(mapping, string);
string show_reward(mapping, string, int);

void init()
{
	add_action("do_chakan", "chakan");
	add_action("do_duihuan", "duihuan");
}

int do_chakan()
{
	object me=this_player();
	string family=me->query("family/family_name"), rewsort=query("mark");
	int rewlevel=query("level")-1;
	mapping reward=([]);
	string msg;
	
	switch(rewsort)
	{
		case "damagebook" : 
			reward=filter_reward(kungfu_skill, family);
			msg=show_reward(reward, rewsort, rewlevel);
			break;
		case "budbook" :
		  reward=filter_reward(buddhism_skill, family);
		  msg=show_reward(reward, rewsort, rewlevel);
		  break;
		case "otherbook" :
		  reward=filter_reward(knowledge_skill, family);
		  msg=show_reward(reward, rewsort, rewlevel);
		  break;
		case "equip" :
			msg=show_reward(equip_item, rewsort, rewlevel);
			break;
		case "lyao" :
			msg=show_reward(drug_item, rewsort, rewlevel);
			break;
		case "hyao" :
			msg=show_reward(hdrug_item, rewsort, rewlevel);
			break;
	}
	
	write(msg);
	return 1;
}

int do_duihuan(string arg)
{
	object me=this_player(), ob;
	string family=me->query("family/family_name"), rewsort=query("mark"), gem, itemid;
	int rewlevel=query("level")-1, lp, rewpoint, rewminlevel, rewmaxlevel, sklevel, i, times;
	mapping reward=([]);
	
	if ( rewlevel && 
		   me->query_temp("cjg/level") <= rewlevel )
	  return notify_fail("藏经阁"+chinese_number(rewlevel+1)+"楼由于你的积分未达标，只能查看，不能兑换。\n");
	
	if ( !arg ||
		   sscanf(arg, "%s %d", itemid, times)!=2 )
    return notify_fail("指令格式：duihuan <奖品ID> <次数>\n");
  
  if ( times<1 || times>50 )
  	return notify_fail("兑换次数应该在1-50之间。\n");
  
	switch(rewsort)
	{
		case "damagebook" :
			reward=kungfu_skill[itemid];
			break;
		case "budbook" :
			reward=buddhism_skill[itemid];
			break;
		case "otherbook" :
			reward=knowledge_skill[itemid];
			break;
		case "equip" :
			reward=equip_item[itemid];
			break;
		case "lyao" :
			reward=drug_item[itemid];
			break;
		case "hyao" :
			reward=hdrug_item[itemid];
			break;
	}
	
	if ( !mapp(reward) )
		return notify_fail("输入的兑换物件ID不正确。\n");
	
	switch(rewsort)
	{
		case "damagebook" :
		case "budbook" :
		case "otherbook" :
			if ( ( stringp(reward["family"]) && 
				     reward["family"] != "公共武学" &&
				     reward["family"] != family ) ||
				   ( arrayp(reward["family"]) &&
				     member_array( family, reward["family"] ) < 0 ) )
			  return notify_fail("只能兑换本门武学或者公共武学。\n");
			rewpoint=reward["point"]?reward["point"][rewlevel]:point[rewlevel];
			if ( me->query("cjg/point") < rewpoint*times )
				return notify_fail("你身上的任务积分不足以兑换"+chinese_number(times)+"级"+reward["name"]+"技能。\n");
		  sklevel=me->query_skill(itemid,1);
			if ( reward["preskill"] &&
				   sklevel+times-1>me->query_skill(reward["preskill"], 1) )
				return notify_fail("研习技能"+reward["name"]+"需要技能"+to_chinese(reward["preskill"])+"的支持。\n");
		  if ( reward["mutexskill"] )
		  {
		  	for(lp=0;lp<sizeof(reward["mutexskill"]);lp++)
		  	  if ( me->query_skill(reward["mutexskill"][lp],1)>0 )
		  	  	return notify_fail("研习技能"+reward["name"]+"必须放弃技能"+to_chinese(reward["mutexskill"][lp])+"。\n");
		  }
		  rewminlevel=reward["minlevel"]?reward["minlevel"][rewlevel]:minlevel[rewlevel];
		  rewmaxlevel=reward["maxlevel"]?reward["maxlevel"][rewlevel]:maxlevel[rewlevel];
		  if ( sklevel< rewminlevel )
		  	return notify_fail("要想研习技能"+reward["name"]+"，你至少该技能要达到"+
		  	       chinese_number(rewminlevel)+"级。\n");
		  if ( sklevel+times-1>rewmaxlevel )
		  	return notify_fail("这里的秘笈最多只能让你把技能"+reward["name"]+"研习到"+
		  	       chinese_number(rewmaxlevel)+"级。\n");
		  me->add("cjg/point", -rewpoint*times);
		  me->set_skill(itemid, sklevel+times);
		  me->start_busy(3);
		  message_vision(HIM"$N"HIM"拿起了书架上的"+reward["name"]+"仔细的研习起来，发现对"+reward["name"]+"的理解有进了一步。\n", me);
		  message_vision("研习技能"+reward["name"]+"消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，$N"HIM"还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n"NOR, me);
		  log_file( "user/cjg", ctime(time())+":"+me->query("id")+"研习技能"+itemid+chinese_number(times)+"次，消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n");
		  break;
		case "equip" :
			rewpoint=reward["point"][rewlevel];
			if ( me->query("cjg/point") < rewpoint*times )
				return notify_fail("你身上的任务积分不足以兑换"+chinese_number(times)+"件装备"+reward["name"][rewlevel]+"。\n");
			me->add("cjg/point",-rewpoint*times);
			for (lp=0;lp<times;lp++)
			{
				if ( reward["key"] &&
					   arrayp(reward["key"]) )
				{
					ob=new(__DIR__"equip2/"+reward["file"][rewlevel]);
					if ( ob->query("is_weapon") )
					  ob->set_cjg_weapon(reward["key"][rewlevel]);
					if ( ob->query("is_armor") )
						ob->set_cjg_armor(reward["key"][rewlevel]);
				}
				else
			    ob=new(__DIR__"equip/"+reward["file"][rewlevel]);
			  //藏经阁装备只能兑换者才能穿戴
			  if ( ob->is_gems() )
			    ob->set("unique_owner", me->query("id") );  
			  ob->move(me);
			}
			message_vision(HIC"$N"HIC"偷偷地从架子上拿起了"+reward["name"][rewlevel]+HIC"，看四周无人立刻藏到自己包里。\n", me);
		  message_vision("$N"HIC"得到装备"+reward["name"][rewlevel]+HIC"过程中消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，$N"HIC"还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n"NOR, me);
		  log_file( "user/cjg", ctime(time())+":"+me->query("id")+"得到"+chinese_number(times)+"件装备"+itemid+"过程中消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n");
			break;
		case "lyao" :
			rewpoint=reward["point"][rewlevel];
			if ( rewpoint<0 )
			  return notify_fail("该物品不存在。\n");
			
			if ( me->query("cjg/point") < rewpoint*times )
				return notify_fail("你身上的任务积分不足以兑换"+chinese_number(times)+"瓶丹药"+reward["name"]+"。\n");
		  me->add("cjg/point",-rewpoint*times);
		  for(lp=0;lp<10*times;lp++)
		  {
		  	if ( reward["file"] )
		  		ob=new(reward["file"]);
		  	else
		  	  ob=new(__DIR__"drug/"+itemid);
		  	ob->move(me);
		  }
			message_vision(HIY"$N"HIY"偷偷地从架子上拿起了一瓶"+reward["name"]+HIY"，看四周无人立刻藏到自己包里。\n", me);
		  message_vision("$N"HIY"得到丹药"+reward["name"]+HIY"过程中消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，$N"HIY"还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n"NOR, me);
		  log_file( "user/cjg", ctime(time())+":"+me->query("id")+"得到"+chinese_number(times)+"瓶丹药"+itemid+"过程中消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n");
			break;
		case "hyao" :
			rewpoint=reward["point"][rewlevel];
			if ( me->query("cjg/point") < rewpoint*times )
				return notify_fail("你身上的任务积分不足以兑换"+chinese_number(times)+"件杂物"+reward["name"]+"。\n");
		  me->add("cjg/point",-rewpoint*times);
		  for( lp=0; lp<times; lp++)
		  {
	  	  if ( reward["file"] )
		  	  ob=new(reward["file"]);
		    else
		      ob=new(__DIR__"drug/"+itemid);
	  	  if ( itemid=="randomgem" )
	  	  {
	  		  i = random(34);
			    if (i < 6) 
			  	  gem = "yan";
			    else if (i < 12) 
			  	  gem = "mu";
			    else if (i < 18) 
			  	  gem = "sui";
			    else if (i < 24) 
			  	  gem = "jin";
			    else if (i < 30) 
			  	  gem = "bing";
			    else if (i < 31) 
			  	  gem = "gu";
			    else if (i < 32) 
			  	  gem = "yu";
			    else if (i < 33) 
			  	  gem = "jiao";
			    else 
			  	  gem = "jia";
			  	
			  	switch( random(10) )
			  	{
			  		case 0:
			  	  case 1:
			  	  case 2:
			  	  case 3:
			  	  case 4:
              ob->set_level(4500,9000,gem);
              break;
            case 5:
            case 6:
            case 7:
            case 8:
            	ob->set_level(4500,9985,gem);
            	break;
            default:
            	ob->set_level(4500,9999,gem);
            	break;
           }
        }
	  	  ob->move(me);
	  	  if ( ob->query("limit_eat") )
	  	  {
	  	  	message_vision(HIY"$N"HIY"偷偷地从架子上拿起了"+ob->name()+HIY"放入了口中。\n", me);
	  	  	ob->eat_dan(me);
	  	  }
	  	  else
	  	    message_vision(HIY"$N"HIY"偷偷地从架子上拿起了"+ob->name()+HIY"，看四周无人立刻藏到自己包里。\n", me);
		    if ( itemid == "randomgem" && ob->query("level")>=6 )
		      CHANNEL_D->do_channel(this_object(),"rumor", "听说"+me->query("name")+"得到一"
               		  +ob->query("unit")+ob->name()+"啦。");
	  	}
		  message_vision("$N"HIY"得到杂物"+reward["name"]+HIY"过程中消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，$N"HIY"还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n"NOR, me);
		  log_file( "user/cjg", ctime(time())+":"+me->query("id")+"得到"+chinese_number(times)+"件杂物"+itemid+"过程中消耗了"+chinese_number(rewpoint*times)+
		      "点任务积分，还剩下"+chinese_number(me->query("cjg/point"))+"点积分。\n");
			break;
  }
				   
	return 1;
}

//过滤技能类奖励列表关于门派限制部分
mapping filter_reward(mapping reward_list, string family)
{
	mapping buff;
	mapping single_skill;
	string *del_reward, *key_reward;
	int lp;
	mixed sfam;
	
	buff=([]);
	buff+=reward_list;
	key_reward=keys(buff);
	del_reward=({});
	for(lp=0;lp<sizeof(key_reward);lp++)
	{
		single_skill=buff[key_reward[lp]];
		sfam=single_skill["family"];
		if ( arrayp(sfam) && 
			   member_array( family, sfam ) <0 )
		  del_reward+=({key_reward[lp]});
		else if ( stringp(sfam) &&
			        sfam!=family &&
			        sfam!="公共武学" )
			del_reward+=({key_reward[lp]});
	}
	
	for(lp=0;lp<sizeof(del_reward);lp++)
	  map_delete(buff, del_reward[lp]);
	
	return buff;
}

//计算奖励物件列表的显示内容
string show_reward(mapping reward_list, string reward_sort, int reward_level)
{
	string *key_reward=keys(reward_list), *key_skill, msg;
	int lp, pt;
	mapping reward_skill;
	
	switch(reward_sort)
	{
		case "damagebook" : 
		case "budbook" :
		case "otherbook" :
		  msg=CYN"本库房可供选择的技能列表如下所示：\n";
		  msg+=" 技能id              技能名称            最低等级  最高等级  消耗积分\n";
		  msg+="---------------------------------------------------------------------\n";
		  for(lp=0;lp<sizeof(key_reward);lp++)
		  {
		  	reward_skill=reward_list[key_reward[lp]];
		  	key_skill=keys(reward_skill);
		  	msg +=" ";
		  	msg +=sprintf("%-20s",key_reward[lp]);
		  	msg +=sprintf("%-20s"CYN,reward_skill["name"]);
		  	msg +=sprintf("%8d  ",(member_array("minlevel", key_skill)==-1?minlevel[reward_level]:reward_skill["minlevel"][reward_level]));
		  	msg +=sprintf("%8d  ",(member_array("maxlevel", key_skill)==-1?maxlevel[reward_level]:reward_skill["maxlevel"][reward_level]));
		  	msg +=sprintf("%8d\n",(member_array("point", key_skill)==-1?point[reward_level]:reward_skill["point"][reward_level]));
		  }
		  msg+=NOR;
		  break;
		case "equip" :
			msg=CYN"本库房可供选择的装备列表如下所示：\n";
			msg+=" 装备id              装备名称                      消耗积分\n";
			msg+="-----------------------------------------------------------\n"NOR;
		  for(lp=0;lp<sizeof(key_reward);lp++)
		  {
		  	reward_skill=reward_list[key_reward[lp]];
		  	key_skill=keys(reward_skill);
		  	msg+=" ";
		  	msg +=sprintf("%-20s",key_reward[lp]);
		    if ( strsrch( reward_skill["name"][reward_level], NOR )<0 )
		    	msg +=sprintf("%-30s",reward_skill["name"][reward_level]);
		    else if ( strsrch( reward_skill["name"][reward_level], BLK )>=0 ||
		    	        strsrch( reward_skill["name"][reward_level], RED )>=0 ||
		    	        strsrch( reward_skill["name"][reward_level], GRN )>=0 ||
		    	        strsrch( reward_skill["name"][reward_level], YEL )>=0 ||
		    	        strsrch( reward_skill["name"][reward_level], BLU )>=0 ||
		    	        strsrch( reward_skill["name"][reward_level], MAG )>=0 ||
		    	        strsrch( reward_skill["name"][reward_level], CYN )>=0 ||
		    	        strsrch( reward_skill["name"][reward_level], WHT )>=0 )
		    	msg +=sprintf("%-44s"CYN,reward_skill["name"][reward_level]);
		    else
		  	  msg +=sprintf("%-46s"CYN,reward_skill["name"][reward_level]);
		  	msg +=sprintf("%8d\n",(member_array("point", key_skill)==-1?point[reward_level]:reward_skill["point"][reward_level]));
		  	msg +=sprintf(HIM"        %s"NOR, reward_skill["msg"][reward_level]);
		  }
		  msg+=NOR;
		  switch(reward_level)
		  {
		  	case 0:
		    msg+=HIC"\n金翎套装效果：\n    凑齐二件精神气血+1000\n    凑齐四件精神气血恢复+40内力精力恢复+20\n    凑齐八件精神气血治疗速度+20获得类似日魂效果+10魔法值+50\n"NOR;
		    break;
		    case 1:
		    msg+=HIC"\n雕磐套装效果：\n    凑齐二件精神气血+2000\n    凑齐四件精神气血恢复+60内力精力恢复+30\n    凑齐八件精神气血治疗速度+30获得类似日魂效果+20魔法值+100\n"NOR;
		    break;
		    case 2:
		    msg+=HIC"\n震夙套装效果：\n    凑齐二件精神气血+4000\n    凑齐四件精神气血恢复+80内力精力恢复+40\n    凑齐八件精神气血治疗速度+40获得类似日魂效果+30魔法值+150\n"NOR;
		    break;
		  }
		  break;
		case "lyao" :
		case "hyao" :
			if (reward_sort=="lyao")
			{
			  msg=CYN"本库房可供选择的丹药列表如下所示：（丹药是10个捆绑兑换）\n";
			  msg+=" 丹药id              丹药名称                      消耗积分\n";
			}
			else
			{
				msg=CYN"本库房可供选择的杂物列表如下所示：\n";
			  msg+=" 杂物id              杂物名称                      消耗积分\n";
			}
			msg+="-----------------------------------------------------------\n";
		  for(lp=0;lp<sizeof(key_reward);lp++)
		  {
		  	reward_skill=reward_list[key_reward[lp]];
		  	key_skill=keys(reward_skill);
		  	if ( member_array("point", key_skill)==-1 )
		  	  pt=point[reward_level];
		  	else
		  	  pt=reward_skill["point"][reward_level];
		  	if ( pt < 0 )
		  	  continue;
		  	
		  	msg+=" ";
		  	msg +=sprintf("%-20s",key_reward[lp]);
		  	if ( strsrch( reward_skill["name"], NOR )<0 )
		  	  msg +=sprintf("%-30s",reward_skill["name"]);
		  	else
		  		msg +=sprintf("%-46s"CYN,reward_skill["name"]);
		  	msg +=sprintf("%8d\n",pt);
		  }
		  msg+=NOR;
		  break;
	}
	
	return msg;
}