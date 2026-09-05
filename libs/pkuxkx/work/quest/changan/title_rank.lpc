/*
  长安城爵位任务头衔管理公共函数
  爵位分别是：
    1-开国县男
    2-开国县子
    3-开国县伯
    4-开国县侯
    5-开国县公
    6-开国郡公
    7-国公
    8-郡王
    9-亲王
*/
#include <ansi.h>

string *trank=
({"开国县男","开国县子","开国县伯","开国县侯","开国县公","开国郡公","国公","郡王","亲王"});

//爵位升级所需要的积分
int *prank=
({100, 300, 900, 3000, 9000, 30000, 90000, 300000, 90000});

//查询对应的爵位头衔名称
string query_rank(int level)
{
	return HIC"〖唐朝爵位〗"HIM+trank[level-1]+NOR;
}

//查询可领取的俸禄
int query_salary(object pl)
{
  int rk, stime;
  
  if ( !objectp(pl) )
    return 0;
  
  rk=pl->query("changan/level");
  if ( !rk )
    return 0;
    
	if ( !pl->query("changan/lvup_time") )
	  pl->set("changan/lvup_time", time()-86400 ); //如果没有登记爵位升级时间，提供当前时间-1天作为补偿
	
	if ( pl->query("changan/sal_time")>pl->query("changan/lvup_time") )
	  stime=pl->query("changan/sal_time");
	else
	  stime=pl->query("changan/lvup_time");
  
  return (time()-stime)/3600*rk;
}

//查询当前爵位提升到下一个爵位还差多少积分
int query_points(object pl)
{
	int rk, pt;
  int extp;
  	
	if ( !objectp(pl) )
	  return -1;
	
	rk=pl->query("changan/level");
	pt=pl->query("changan/points");
	if ( rk && !pl->query("changan/lvup_time") )
	  pl->set("changan/lvup_time", time()-86400 ); //如果没有登记爵位升级时间，提供当前时间-1天作为补偿
	
	if ( rk==9 )
	{
		tell_object(pl, "你已经是亲王了。\n");
		return -1;
	}
	
	extp=prank[rk]-pt;
	if ( extp>0 )
	  tell_object(pl, "你距离下一个爵位："+query_rank(rk+1)+"还差"+chinese_number(extp)+"点贡献。\n");
	else
	{
		tell_object(pl, "你已经可以提升到下一个爵位："+query_rank(rk+1)+"。\n");
		extp=0;
	}
	
	if ( rk>0 )
	{
		tell_object(pl, "你在本爵位上积累额外兑奖积分"+chinese_number(pl->query("changan/ext_points"))+"点，请赶紧去户部兑换。\n"); 
		tell_object(pl, "你在本爵位上积累俸禄"+chinese_number(query_salary(pl))+"点积分，请赶紧去户部领取。\n");
	}
	
	return extp;
}

//提升爵位
void add_level(object pl)
{
	int rk,extp;
	
	if ( !objectp(pl) )
		return;
	
	rk=pl->query("changan/level");
	extp=query_points(pl);
	if ( extp!=0 )
		return;
	
	tell_object(pl, "你将被提升到爵位："+query_rank(rk+1)+"，爵位贡献将被清零，兑换奖励用的额外积分将被折半处理。\n");
	pl->add("changan/level",1);
	pl->set("changan/lvup_time", time());
	pl->delete("changan/points");
	if ( pl->query("changan/ext_points") >0 )
		pl->set("changan/ext_points", pl->query("changan/ext_points")/2);
}

//领取当期俸禄
void get_salary(object pl)
{
  int sal;
  
  if ( !objectp(pl) )
    return;
  
  sal=query_salary(pl);
  if ( !sal )
  {
    tell_object(pl, "你没有任何俸禄可以领取。\n");
    return;
  }
  else
  {
    pl->add("changan/ext_points", sal);
    pl->set("changan/sal_time", time() );
    tell_object(pl, "你从户部那里领取了"+chinese_number(sal)+"点奖励积分。\n");
  }
}