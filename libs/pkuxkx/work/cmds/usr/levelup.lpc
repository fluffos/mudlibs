#include <ansi.h>
inherit F_CLEAN_UP;
string* gifts =({"str","int","dex","con","kar","per","spi",	});
int exp_require(int lv_from,int lv_to)
{
	int lv,result=0;
	if (lv_from>=lv_to)	return 0;
	for (lv=lv_from+1;lv<=lv_to;lv++)
	{
		if (lv<=100)
		result+=lv*lv*120;
		else
		result+=lv*lv*2000;
	}
	return result;
}
int level_query(string arg,object me)
{
	int level,exp,gold,repute;
	string str;
	if(!arg)
	{
		tell_object(me,WHT"你输入了一个无效的参数！\n"NOR);
		return 1;
	}
	if (sscanf(arg,"%d",level)!=1)
	{
		tell_object(me,WHT"你输入了一个无效的参数！\n"NOR);
		return 1;
	}
	if (level>0 && level<=100 ) 
	{
		exp=level*level*level*400;
		repute=level*20000;
		gold=level*10;
		tell_object(me,HIY"升级到"+HIC+level+NOR+HIY"级，需要经验值达到"+HIC+exp+NOR+
        			               HIY",需要声望达到"+HIC+repute+NOR+HIY"，需要缴纳存款"+HIC+gold+HIY"两黄金!\n"NOR);
		tell_object(me,HIY"同时，此次升级需要消耗经验"HIC+level*level*120+
		HIY"点，声望"HIC+level*200+HIY"点，存款"HIC+level*10+HIY"两黄金。\n"NOR);
	}
	else if ( level>100 )
	{
        			exp=400+(level-100)*(level-100)+10;
        			repute=level*200000;
        			tell_object(me,HIY"升级到"+HIC+level+NOR+HIY"级，需要经验值达到"+HIC+exp+NOR+"M"
        			               HIY",需要声望达到"+HIC+repute+NOR+HIY"，需要缴纳存款"+HIC+level+HIY"块金块!\n"NOR);
              tell_object(me,HIY"同时，此次升级需要消耗经验"HIC+level*level*2000+
                             HIY"点，声望"HIC+level*5000+HIY"点，存款"HIC+level+HIY"块金块。\n"NOR);
	}
	else
	{
		tell_object(me,WHT"你输入了一个无效的级别！\n"NOR);
	}
	return 1;	
}
int level_up(string arg,object me)
{
	int level=(int)me->query("level")+1;
	int exp,repute,gold;
	string gift, *tgift;
	string cgift;
	if (arg!="yes"&&arg!="y")
	{
		tell_object(me,"你放弃了升级的打算。\n");
		return 1;
	}
	if ( level>0 && level <= 100 )
	{
		exp=level*level*120;
		repute=level*200;
		gold=level*10*10000;
		me->add("balance",-gold);
	}
	else if ( level>100 )	
	{
		exp=level*level*2000;
		repute=level*5000;
		me->add("advance_balance",-level);
	}
	if (me->query("myVeins/LevelupDiscount")>0)
	{
		exp-=1100000;
		exp-=random(100000);
		if (exp<0) exp=0;
		me->add("myVeins/LevelupDiscount",-1);
		tell_object(me,HIR+"因为贯通第四层经脉，你本次升级只需消耗"+exp+"点经验。\n"+NOR);
	}
	me->add("combat_exp",-exp);
	if(me->query("combat_exp") < 1100)
	{
		me->set("combat_exp",1100);
	}
	me->add("repute",-repute);
	me->add("level",1);
	tell_object(me,HIY"恭喜你，你升到了"+chinese_number(level)+"级！\n"NOR);
	if ( (level>me->query("upgrade_no_reward") && level <= 100 && random(5)==3) ||level>100 )
	{
		gift=gifts[random(sizeof(gifts))];
		if ( me->query(gift) > 50 && (gift == "str" || gift == "int" || gift == "con" || gift == "dex") )
		{
			tgift=gifts-({gift});
			gift=gifts[random(sizeof(gifts))];
		}	
		if ( level > 100 )
		{
			me->add(gift,2);
			me->add("xiantian/"+gift+"/level",2);
		}
		else
		{
			me->add(gift,1);
			me->add("xiantian/"+gift+"/level",1);
		}
		if (gift=="str") cgift="膂力";
		if (gift=="int") cgift="悟性";
		if (gift=="con") cgift="根骨";
		if (gift=="dex") cgift="身法";
		if (gift=="per") cgift="容貌";
		if (gift=="kar") cgift="福缘";
		if (gift=="spi") cgift="灵性";

		if ( me->query(gift) > 50 && (gift == "str" || gift == "int" || gift == "con" || gift == "dex") )
		{
			tell_object(me,HIY"你的先天"+cgift+"已臻绝顶，无法再次提升！\n"NOR);
			me->set(gift,50);
		}
		else
		{
			tell_object(me,HIY"你的先天"+cgift+"增加了！\n"NOR);
		}
	}
	//增加升级后等同于fullme的效果，By Zine 2013/1/7
	me->fullme();
	//内力加倍
	if(me->query("neili") < 2*me->query("max_neili"))
	{
		me->set("neili",2*me->query("max_neili"));
	}
	//精力加倍
	if(me->query("jingli") < 2*me->query("max_jingli"))
	{
		me->set("jingli",2*me->query("max_jingli"));
	}
	message_vision(HIG+"$N周身一震，瞬时达到了巅峰的状态。\n"+NOR,me);
	me->start_busy(5);
	return 1;
}
int main(object me,string arg)
{
	int level=(int)me->query("level")+1;
	if (arg=="-q")
	{
		tell_object(me,"请用阿拉伯数字输入你需要查询的级别：");
		input_to( (: level_query :),me);
		return 1;
	}
	if (arg)
	{
		tell_object(me,arg+"是一个无效的参数，请使用levelup -q查询级别或直接输入levelup升级。\n");
		return 1;
	}
	if ( level>0 && level <= 100 && me->query("combat_exp")<level*level*level*400 )
	{
		tell_object(me,HIY"你的经验不够升到下一级，至少需要"+level*level*level*400+"点经验！\n"NOR);	
		return 1;
	}
	if ( level>100 && me->query("combat_exp")/1000000<400+(level-100)*(level-100)+10 )
	{
		tell_object(me,HIY"你的经验不够升到下一级，至少需要"+chinese_number(400+(level-100)*(level-100)+10)+"兆经验！\n"NOR);	
		return 1;
	}
	if ( level>0 && level <= 100 && me->query("repute")<level*20000)
	{
		tell_object(me,HIY"你的声望太低了，至少需要"+level*20000+"点声望！\n"NOR);
		return 1;	
	}
	if ( level > 100 && me->query("repute")<level*200000)
	{
		tell_object(me,HIY"你的声望太低了，至少需要"+level*200000+"点声望！\n"NOR);
		return 1;	
	}
	if ( level>0 && level <= 100 && me->query("balance")<level*10*10000)
	{
		tell_object(me,HIY"你的存款不够，至少需要"+level*10+"gold的存款！\n"NOR);
		return 1;	
	}
	if ( level > 100 && me->query("advance_balance")<level)
	{
		tell_object(me,HIY"你的存款不够，至少需要"+level+"块金块的存款！\n"NOR);
		return 1;	
	}
	if (me->is_busy() || me->is_fighting())
	{
		tell_object(me, HIY"你现在腾不出手来提升自己的等级。\n"NOR);
		return 1;	
	}
	tell_object(me,"你确定要升级吗？升级将"+HIR+BLINK+"消耗"+NOR+"经验，声望以及金钱，如需查询具体消耗，请使用levelup -q命令，如确定升级请输入yes or y：");
	input_to( (: level_up :),me);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式：levelup

升级获得高的级别可以让自己的气血和精神更长，可以让部分工夫的绝招成功率
更高，可以让功夫的有效等级更高，影响部分perform 的效果。在升级的同时有
几率获得先天属性。100级以后升级必定增加先天属性。

HELP
    );
    return 1;
}

