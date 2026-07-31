//Cracked by Kafei
//wzfeng@xkx 2000 6
// job_menpai.c  门派控制核心文件：
#include <ansi.h>
inherit F_SAVE;
inherit ITEM;
#include "lpc_math.h"
mapping family;
mapping *familys;//各个门派的数据
mapping family_assess_number;


mapping *query_familys()
{
	return familys;
}
void create()
{
	 set_name("门派控制器",  ({"menpai_system"}));
	seteuid(getuid());
}
string query_save_file()
{
        return DATA_DIR + "job_system/menpai"; 
}
//Set a new family data in familys.
void set_default()
{
	familys=({});

}
void set_familys(mapping family)
{
        if( !pointerp(familys) )
        {
         familys = ({ family });
        }
        else familys += ({ family });

}

//门派名称中英文转换 string name,要转换的名称，int mode 转换方式 1=中文到英文 2=英问到中文
string con_name(string name,int mode)
{
	string con_name;
	if(mode==1)
	{
		switch(name) {
		case "武当派": con_name = "wudang"; break;
		case "星宿派": con_name = "xingxiu"; break;
		case "华山派": con_name = "huashan"; break;
		case "桃花岛": con_name = "taohua"; break;
		case "丐帮": con_name = "gaibang"; break;
		case "峨嵋派": con_name = "emei"; break;
		case "白驼山": con_name = "baituo"; break;
		case "全真教": con_name = "quanzhen"; break;
		case "雪山派": con_name = "xueshan"; break;
		case "大理段家": con_name = "dali"; break;
		case "少林派": con_name = "shaolin"; break;

		default:
				return ("门派转换错误\n");

		}
		return con_name;
	}
	if(mode==2)
		{
		switch(name) {
		case "wudang": con_name = "武当派"; break;
		case "xingxiu": con_name = "星宿派"; break;
		case "huashan": con_name = "华山派"; break;
		case "taohua": con_name = "桃花岛"; break;
		case "gaibang": con_name = "丐帮"; break;
		case "emei": con_name = "峨嵋派"; break;
		case "baituo": con_name = "白驼山"; break;
		case "quanzhen": con_name = "全真教"; break;
		case "xueshan": con_name = "雪山派"; break;
		case "dali": con_name = "大理段家"; break;
		case "shaolin": con_name = "少林派"; break;

			default:
				return ("英文-〉中文门派转换错误\n");

		}
		return con_name;
	}

	return ("mode error3\n");
}
int query_luck(string name)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(familys[i]["family_name"]==name)
			return familys[i]["family_luck"];
		return 0;


}
int do_set_luck(string name,int luck)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_luck"]=luck;
			save();
			return 1;
		}
		return notify_fail ("set luck error。\n");
}
int do_set_assess_num(string name,int num)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_assess_num"]=num;
			save();
			return 1;
		}
		return notify_fail ("set family_assess_num error。\n");
}

int do_set_rate(string name,int luck)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_rate"]=luck;
			save();
			return 1;
		}
		return notify_fail ("set rate error。\n");
}

int do_set_money(string name,int luck)
{
	int i;
		for(i=0;i<sizeof(familys);i++)
		if(con_name(familys[i]["family_name"],1)==name)
		{
			familys[i]["family_money"]=luck;
			save();
			return 1;
		}
		return notify_fail ("set money error。\n");
}

int have_menpai(string name)
{
	int i;
	for(i=0;i<sizeof(familys);i++)
	{
		if(con_name(familys[i]["family_name"],1)==name)
		{
			return 1;
		}
	}
		return 0;
}

//num修改相应的strategy
int have_strategy(string menpai,string strategy,int num)
{
	int i,j;
	string *strategy_name;

	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==con_name(menpai,2))
		{

			if(!sizeof(familys[i]["family_strategy"]))
				return notify_fail ("这个门派没有制定策略。\n");
			else
			{

				strategy_name=keys(familys[i]["family_strategy"]);
				for(j=0;j<sizeof(familys[i]["family_strategy"]);j++)
				{
					if(strategy_name[j]==strategy)
						{
						if(num)
						{
							familys[i]["family_strategy"][strategy_name[j]]=num;
							save();
						}

						return familys[i]["family_strategy"][strategy_name[j]];
						}
				}
				
			}
		return notify_fail ("这个门派没有制定这种策略。\n");
		}

	}
		return notify_fail ("没有这个门派。\n");

}
//num修改相应的area power
int have_power(string menpai,string area,int num)
{
	int i,j;
	string *area_name;
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==con_name(menpai,2))
		{
			if(!sizeof(familys[i]["family_power"]))
				return notify_fail ("这个门派没有这个区域范围内的势力。\n");
			else
			{
				area_name=keys(familys[i]["family_power"]);
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				{
					if(area_name[j]==area)
						{
						if(num)
						{
							familys[i]["family_power"][area_name[j]]=num;
							save();
						}

						return familys[i]["family_power"][area_name[j]];
						}
				}
				
			}
		return notify_fail ("这个门派没有这个地区的势力。\n");
		}

	}
		return notify_fail ("没有这个门派。\n");

}



//Add a new family data. 
//parameter explain:
//string family_name  门派的名称
//mapping strategy      门派发展策略(用一个mixed来表示，其中可以详细说明策略各种参数)
//int luck			  门派幸运值(影响门派任务和各种随机参数，越大表示对门派越有利)
//int money           门派的财政数值(影响门派策略和门派成员的俸禄)
//mapping power         门派的势力(影响整个游戏环境和任务系统)


int add_orgdata(string family_name,mapping strategy,int luck,int money,int rate,mapping power,int assess_num)
{
	int i,j;

	if(!sizeof(familys))
	{
			family = ([
    		"family_name":family_name,
			"family_strategy":strategy,
			"family_luck":luck,
			"family_money":money,
			"family_power":power,
			"family_rate":rate,
			"family_assess_num":assess_num,
      
        ]);
			write(family_name+"数据添成功（第一个门派)。\n");
			set_familys(family);
			save();
			return 1;

	}

	j=sizeof(familys);
	
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==family_name)
		{
			//printf("%s\n",familys[i]["family_name"]);
			return notify_fail ("已经有这个门派了，请使用change_orgdata来修改。\n");
		}
			family = ([
    				"family_name":family_name,
					"family_strategy":strategy,
					"family_luck":luck,
					"family_money":money,
					"family_power":power,
					"family_rate":rate,
					"family_assess_num":assess_num,
      
				]);
		write(family_name+"数据添加成功。\n");
		set_familys(family);
		save();
		return 1;

		}
	
	
	return 1;

}
// change familys data.
int change_orgdata(string family_name,mapping strategy,int luck,int money,int rate,mapping power,int assess_num)
{
	int i,j;

	if(!sizeof(familys))
		return 0;
	j=sizeof(familys);
	
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==family_name)
		{
			
			familys[i] = ([
			"family_name":family_name,
			"family_strategy":strategy,
			"family_luck":luck,
			"family_money":money,
			"family_power":power,
			"family_rate":rate,
			"family_assess_num":assess_num,
      
        ]);
			
			save();
			return 1;
		}
	}
		return notify_fail ("没有这个门派了，请使用add_orgdata来增加新的门派数据。\n");

}
mapping query_assess_basenum(string family)
{
	mapping family_map;
	family_map=get_mapping(family,"family_name",familys);
	return family_map;
}
//query_orgdata
int query_full_menpaidata(string menpai_name)
{
	int i,j;
	string *strategy_name;
	if(!sizeof(familys))
		return notify_fail ("现在没有任何江湖门派信息，请使用setorg_default来设置缺省参数。\n");
		
	
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==con_name(menpai_name,2))
		{
			write(HIC+con_name(menpai_name,2)+"详细列表:\n"NOR);
			write("门派幸运点数\t\t"+familys[i]["family_luck"]+"\n"NOR);
			write("门派金钱系数\t\t"+familys[i]["family_money"]+"\n"NOR);
			write("门派的评定基数\t\t"+familys[i]["family_assess_num"]+"\n"NOR);
			if(!sizeof(familys[i]["family_strategy"]))
				write("门派策略无\n"NOR);
			else
			{
				strategy_name=keys(familys[i]["family_strategy"]);
				write("门派策略详细表：\n");
				for(j=0;j<sizeof(familys[i]["family_strategy"]);j++)
					printf("\t%-20s\t%d\n",strategy_name[j],familys[i]["family_strategy"][strategy_name[j]]);
			}

			if(!sizeof(familys[i]["family_power"]))
				write("门派势力无\n"NOR);
			else
			{
				strategy_name=keys(familys[i]["family_power"]);
				write("门派势力详细表：\n");
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				printf("\t%-20s\t%d\n",strategy_name[j],familys[i]["family_power"][strategy_name[j]]);
			}


		}
	}

	return 1;

}
int query_strategy_list(int mode)
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("现在没有任何江湖门派信息，请使用setorg_default来设置缺省参数。\n");
		
	write(HIC"目前江湖各派的主要策略为:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(familys[i]["family_name"]+"\n");
	}

	return 1;
}

int query_menpai_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("现在没有任何江湖门派信息，请使用setorg_default来设置缺省参数。\n");
		
	write(HIC"目前武林幻境控制的门派有:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(HIW+familys[i]["family_name"]+"\n"NOR);
	}

	return 1;
}

int query_luck_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("现在没有任何江湖门派信息，请使用setorg_default来设置缺省参数。\n");
		
	write(HIC"目前江湖各派的幸运点数为:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(familys[i]["family_name"]+"\t\t");
		write(familys[i]["family_luck"]+"\n");
	}

	return 1;
}
int query_money_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("现在没有任何江湖门派信息，请使用setorg_default来设置缺省参数。\n");
		
	write(HIC"目前江湖各派的金钱分配系数为:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(familys[i]["family_name"]+"\t\t");
		write("百分之"+familys[i]["family_money"]+"\n");
	}

	return 1;
}

string random_get_menpai_strategy(string menpai)
{
	int i,j,strategy_random,strategy_sum;
	string *strategy_name,random_strategy_name;
	strategy_random=1+random(99);
	if(!(i=sizeof(familys)))
		return "error";
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==menpai)
		{
			

			if(!sizeof(familys[i]["family_strategy"]))
				return ("这个门派没有制定策略。\n");
			else
			{

				strategy_name=keys(familys[i]["family_strategy"]);
				//printf("随机产生的策略数值=%d\n",strategy_random);
				for(j=0;j<sizeof(familys[i]["family_strategy"]);j++)
					{
					strategy_sum +=familys[i]["family_strategy"][strategy_name[j]];
					if(strategy_random<strategy_sum)
					return strategy_name[j];
				}
			}
		return ("这个门派没有制定这种策略。\n");
		}
	}
		return ("没有这个门派(restore())。\n");
}

string random_get_menpai_areapower(string menpai)
{
	int i,j,menpai_area_power_sum,power_sum,power_random;
	string *area_name;
	for(i=0;i<sizeof(familys);i++)
	{
		if(familys[i]["family_name"]==menpai)
		{
			if(!sizeof(familys[i]["family_power"]))
				return ("这个门派没有区域范围内的势力。\n");
			else
			{
				area_name=keys(familys[i]["family_power"]);
				
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				{
					menpai_area_power_sum +=familys[i]["family_power"][area_name[j]];
				}
				//printf("区域势力的总和=%d\n",menpai_area_power_sum);
				
				power_random=1+random(menpai_area_power_sum-1);
				//printf("随即产生的区域势力值=%d\n",power_random);
				for(j=0;j<sizeof(familys[i]["family_power"]);j++)
				{
					power_sum +=familys[i]["family_power"][area_name[j]];
					if(power_random<power_sum)
					return area_name[j];
				}
			}
		return ("这个门派没有这个地区的势力。\n");
		}
	}
		return ("没有这个门派。\n");
}
string get_random_menpai()
{
		int i,j,all_num,random_num,temp_num;
	string menpai;
	if(!(i=sizeof(familys)))
		return "error";
	for(j=0;j<i;j++)
		all_num+=familys[j]["family_rate"];
	//printf("门派比率的总和为:\t%d\n",all_num);
	random_num=1+random(all_num-1);
	//printf("随即产生的门派比率值=%d\n",random_num);
	for(j=0;j<sizeof(familys);j++)
		{
		
		//printf("%s的比率为:\t%d\n",familys[j]["family_name"],familys[j]["family_rate"]);
		temp_num +=familys[j]["family_rate"];
		if(random_num<temp_num)
		{
			return familys[j]["family_name"];
		}
		}


	
return ("没有这个门派。\n");

}
int query_rate_list()
{
	
	int i;
	if(!sizeof(familys))
		return notify_fail ("现在没有任何江湖门派信息，请使用setorg_default来设置缺省参数。\n");
		
	write(HIC"目前各门派产生任务的比率为:\n"NOR);
	for(i=0;i<sizeof(familys);i++)
	{
		write(HIW+familys[i]["family_name"]+":\t\t"NOR);
		write(HIW+familys[i]["family_rate"]+"\n"NOR);
	}

	return 1;
}


