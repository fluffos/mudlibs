// Modified by iszt@pkuxkx, 2007-04-14
// Modified by Zine@pkuxkx, 2013-1-28

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

string status_color(int current, int max);
string get_decimal(int num,string type)
{
	if ( num < 10000 )
	return sprintf(NOR WHT"  【 %s 】 %s%14-d    \n"HIG,type,(type=="潜能")?HIY:HIG, num);
	else if ( num < 100000000 )
	return sprintf(NOR WHT"  【 %s 】 %s%.2f万    \n"HIG,type,HIC, (num*1.0)/10000);
	else 
	return sprintf(NOR WHT"  【 %s 】 %s%.4f亿    \n"HIG,type,HIM, (num*1.0)/100000000);
}
string get_separator(int quotient,string type)
{
	int remainder,q1,q2,q3;
	string Transfer;
	remainder=quotient%1000000000;
	q1=quotient/1000000000;
	quotient=remainder;
	remainder=quotient%1000000;
	q2=quotient/1000000;
	quotient=remainder;
	remainder=quotient%1000;
	q3=quotient/1000;
	if (q1>0)
	Transfer=sprintf("%d%s%03d%s%03d%s%03d",q1,",",q2,",",q3,",",remainder);
	else if (q2>0)
	Transfer=sprintf("%d%s%03d%s%03d",q2,",",q3,",",remainder);
	else if (q3>0)
	Transfer=sprintf("%d%s%03d",q3,",",remainder);
	else
	Transfer=sprintf("%d",remainder);
	if ( quotient < 10000 )
	return sprintf(NOR WHT"  【 %s 】 %s%14-s    \n"HIG,type,(type=="潜能")?HIY:HIG, Transfer);
	else if ( quotient < 100000000 )
	return sprintf(NOR WHT"  【 %s 】 %s%14-s    \n"HIG,type,HIC, Transfer);
	else 
	return sprintf(NOR WHT"  【 %s 】 %s%14-s    \n"HIG,type,HIM, Transfer);
}
string get_classic(int num,string type)
{
	if ( num < 10000 )
	return sprintf(NOR WHT"  【 %s 】 %s%14-d    \n"HIG,type,(type=="潜能")?HIY:HIG, num);
	else if ( num < 100000000 )
	return sprintf(NOR WHT"  【 %s 】 %s%14-d    \n"HIG,type,HIC, num);
	else 
	return sprintf(NOR WHT"  【 %s 】 %s%14-d    \n"HIG,type,HIM, num);
}
int show_hp(object me,object ob)
{
	mapping my,buf;
	string owner, *bufkey, bufprt;
	string str, status, *cond, injure_stat, disease_stat, poison_stat;
	int exp, pot, qipct, lp;
	my = ob->query_entire_dbase();
	if(wizardp(me))
		write(sprintf(NOR HIG"≡━◎个人状态◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR,));
	if(wizardp(me))
                write(sprintf(NOR CYN""NOR WHT" "NOR CYN" 姓名："NOR WHT"%-12s "NOR CYN" 级别："NOR WHT"%-10s "NOR CYN"I D："NOR WHT"%-13s"NOR CYN"\n"NOR,ob->name(),chinese_number(ob->query("level")),"["+capitalize(ob->query("id"))+"]"));
	write(sprintf(NOR HIG"≡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR));
	write(sprintf(NOR CYN""NOR WHT"【 精神 】 %s%6-d/ %7-d%s[%3d%%]"NOR,status_color(to_int(my["jing"]),to_int(my["eff_jing"])),to_int(my["jing"]),to_int(my["eff_jing"]),status_color(to_int(my["eff_jing"]),to_int(my["max_jing"])),to_int(my["eff_jing"])*100/to_int(my["max_jing"])));
	write(sprintf(NOR WHT"  【 精力 】 %s%6-d/ %6-d(+%4d)"NOR CYN"\n"NOR,status_color(to_int(my["jingli"]), to_int(my["max_jingli"])), to_int(my["jingli"]), to_int(my["max_jingli"]),0));
	write(sprintf(NOR CYN""NOR WHT"【 气血 】 %s%6-d/ %7-d%s[%3d%%]"NOR,status_color(to_int(my["qi"]),to_int(my["eff_qi"])),to_int(my["qi"]),to_int(my["eff_qi"]),status_color(to_int(my["eff_qi"]),to_int(my["max_qi"])),to_int(my["eff_qi"])*100/to_int(my["max_qi"])));
	write(sprintf(NOR WHT"  【 内力 】 %s%6-d/ %6-d(+%4d)"NOR CYN"\n"NOR,status_color(to_int(my["neili"]),to_int( my["max_neili"])), to_int(my["neili"]), to_int(my["max_neili"]),to_int(my["jiali"])));
	qipct=to_int(my["eff_qi"])*100/to_int(my["max_qi"]);
	if ( qipct>=95 )
		status=HIW"健康"NOR;
	else if ( qipct>=80 )
		status=CYN"受伤"NOR;
	else if ( qipct>=50 )
		status=YEL"轻伤"NOR;
	else if ( qipct>=20 )
		status=RED"重伤"NOR;
	else
		status=HIR"濒危"NOR;
	if ( ob->query_temp("no_exert") )
		status+="、"+YEL"闭气"NOR;
	if ( ob->query_temp("no_perform") )
		status+="、"+YEL"疯魔"NOR;
	if ( ob->query_temp("apply/disorder_percent") )
		status+="、"+YEL"内息紊乱"NOR;
	cond=keys(cond_def);
	for(lp=0;lp<sizeof(cond);lp++)
	{
		if ( ob->query_condition(cond[lp])>0 )
		{
			if ( cond_def[cond[lp]]["type"]=="poison" )
			{
				if ( !poison_stat )
					poison_stat=GRN+cond_def[cond[lp]]["name"]+NOR;
				else
					poison_stat+="、"+GRN+cond_def[cond[lp]]["name"]+NOR;
			}
			
      if ( cond_def[cond[lp]]["type"]=="injure" )
			{
				if ( !injure_stat )
					injure_stat=RED+cond_def[cond[lp]]["name"]+NOR;
				else
					injure_stat+="、"+RED+cond_def[cond[lp]]["name"]+NOR;
			}
			
      if ( cond_def[cond[lp]]["type"]=="disease" )
			{
				if ( !disease_stat )
					disease_stat=YEL+cond_def[cond[lp]]["name"]+NOR;
				else
					disease_stat+="、"+YEL+cond_def[cond[lp]]["name"]+NOR;
			}
		}
	}
	
	if ( injure_stat )
		status+="、"+injure_stat;
	if ( disease_stat )
		status+="、"+disease_stat;
	if ( poison_stat )
		status+="、"+poison_stat;
	if(my["food"]*100/ob->max_food_capacity()>100) str=HIC+"很饱";
	else if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"正常";
	else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"缺食";        
	else if(my["food"]*100/ob->max_food_capacity()>30) str=CYN+"缺食";
	else if(my["food"]*100/ob->max_food_capacity()>10) str=HIR+"缺食";
	else str=RED+"饥饿";
	write(sprintf(NOR WHT"【 食物 】 %s%6-d/ %6-d [%4s%s]",status_color(my["food"], ob->max_food_capacity()),
	my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity())));
	pot=to_int(ob->query("potential") - (int)ob->query("learned_points"));
	if (me->query("env/custom_hp")==1)
	write(get_classic(pot,"潜能"));
	else if (me->query("env/custom_hp")==2)
	write(get_separator(pot,"潜能"));
	else
	write(get_decimal(pot,"潜能"));
	
	if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"很饱";
	else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"正常";
	else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"缺水";
	else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"缺水";
	else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"缺水";
	else str=RED+"饥渴";
	write(sprintf(NOR WHT"【 饮水 】 %s%6-d/ %6-d [%4s%s]",status_color(my["water"], ob->max_water_capacity()),
	my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity())));
	exp=ob->query("combat_exp");
	if (me->query("env/custom_hp")==1)
	write(get_classic(exp,"经验"));
	else if (me->query("env/custom_hp")==2)
	write(get_separator(exp,"经验"));
	else
	write(get_decimal(exp,"经验"));
	write(sprintf(NOR WHT"【 状态 】 %s\n", status));
	write(NOR HIG"≡━━━━━━━━━━━━━━━━━━━━━━━◎北大侠客行◎━━≡\n"NOR,);
	return 1;
}

int show_neili(object me, object ob)
{
  string force, *kf, tforce;
  mapping bforce;
  int lneili, ltms;
  
  if(wizardp(me))
    write(sprintf(NOR HIG"≡━◎个人状态◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR,));
  if(wizardp(me))
    write(sprintf(NOR CYN""NOR WHT" "NOR CYN" 姓名："NOR WHT"%-12s "NOR CYN" 级别："NOR WHT"%-10s "NOR CYN"I D："NOR WHT"%-13s"NOR CYN"\n"NOR,ob->name(),chinese_number(ob->query("level")),"["+capitalize(ob->query("id"))+"]"));
  write(sprintf(NOR HIG"≡━◎内力显示◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR));
  
  force=ob->query_skill_mapped("force");
  if ( !stringp(force) )
  {
    FORCE->backup_neili(ob, "force");
    tforce="force";
  }
  else
  {
    SKILL_D(force)->backup_neili(ob, force);
    if ( !stringp(tforce=SKILL_D(force)->translate(force)) )
      tforce=force;
  }
  bforce=ob->query("backup_neili");  
  kf=keys(bforce);
  lneili=0;
  ltms=0;
  for(int lp=0;lp<sizeof(kf);lp++)
  {
    if ( !bforce[kf[lp]]["max_neili"] )
      continue;
    
    if ( tforce==kf[lp] )
      write(sprintf(NOR YEL"[1;32m□[37;0m"YEL"%-40s"HIW" - %6d/%6d("HIR"%d"HIW")\n"NOR,  (to_chinese(kf[lp]) + " (" + kf[lp] + ")"), bforce[kf[lp]]["neili"], bforce[kf[lp]]["max_neili"], bforce[kf[lp]]["limit_neili"] ) );
    else
      write(sprintf(NOR YEL"  %-40s"HIW" - %6d/%6d("HIR"%d"HIW")\n"NOR,  (to_chinese(kf[lp]) + " (" + kf[lp] + ")"), bforce[kf[lp]]["neili"], bforce[kf[lp]]["max_neili"], bforce[kf[lp]]["limit_neili"] ) );
    if ( bforce[kf[lp]]["force"] )
      write(sprintf(NOR CYN"....其中优势内功：%-40s\n"NOR, (to_chinese(bforce[kf[lp]]["force"]) + " (" + bforce[kf[lp]]["force"] + ")") ) );
    if ( kf[lp]!="force" &&
         bforce[kf[lp]]["max_neili"]>0 )
    {
      lneili+=bforce[kf[lp]]["limit_neili"];
      ltms++;
    }
  }
  if ( ltms )
    lneili=lneili-(ltms-1)*ob->query_skill("force",1)*5;
  write(sprintf(NOR HIG"≡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR));  
  write(sprintf(NOR WHT"【 走火入魔概率 】 "HIR"%6.2-f%%\n"NOR, F_KUNGFU->kungfu_wrongpct(ob)*100));
  write(sprintf(NOR WHT"【 极限内力总和 】 "HIG"%d\n"NOR, lneili));
  write(NOR HIG"≡━━━━━━━━━━━━━━━━━━━━━━━◎北大侠客行◎━━≡\n"NOR,);
  return 1;
}

int main(object me, string arg)
{
	object ob,ob1;
	string owner, *pars;
	
	seteuid(getuid(me));
    if(time() - me->query_temp("last_hp_time") < 2 && !wizardp(me))
    {
        return notify_fail("你用HP太频繁了，如果是机器人需要，请使用hpbrief命令，节约系统资源，谢谢。\n");
    }
    me->set_temp("last_hp_time",time());
	if(!arg)
		ob = me;
		else
		{
		  pars=explode(arg," ");
      if ( pars[0]=="-neili" )
      {
        if ( sizeof(pars)>=2 )
        {
          ob = present(pars[1], environment(me));
			    if (!ob) ob = find_player(pars[1]);
			    if (!ob) ob = find_living(pars[1]);
			    if (!ob || !me->visible(ob))
				    return notify_fail("你要察看谁的状态？\n");
			    else
			    {
				    owner=ob->query("owner_id");
				    if(owner) ob1=find_player(owner);
			    }
		      if (wizardp(me) || me->query("suicongdizi/npc") == ob)
		      {
		      }
		      else if(!ob&&!ob1)
			      return notify_fail("只有巫师能察看别人的状态。\n");
		      else if(ob!=me&&ob1!=me)
			      return notify_fail("只有巫师能察看别人的状态。\n");
			  }
			  else
			    ob=me;
			  
			  return show_neili(me, ob);
      }
			ob = present(arg, environment(me));
			if (!ob) ob = find_player(arg);
			if (!ob) ob = find_living(arg);
			if (!ob || !me->visible(ob))
				return notify_fail("你要察看谁的状态？\n");
			else
			{
				owner=ob->query("owner_id");
				if(owner) ob1=find_player(owner);
			}
		}
		if (wizardp(me) || me->query("suicongdizi/npc") == ob)
		{
		}
		else if(!ob&&!ob1)
			return notify_fail("只有巫师能察看别人的状态。\n");
		else if(ob!=me&&ob1!=me)
			return notify_fail("只有巫师能察看别人的状态。\n");
	return show_hp(me,ob);
}

string status_color(int current, int max)
{
	int percent;

	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

int help(object me)
{
	write(@HELP
指令格式 : hp [-neili]
	   hp [-neili] <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
恢复和治疗属性的单位是每心跳，也就是说计算有心跳的时候每秒
恢复平均值。hp可以做一些个性化设置，默认设置是以万、亿为单
位的显示，set custom_hp 1 以整数形式显示，set custom_hp 2
以千位分隔符的形式显示。
-neili选项显示的是内力相关的一些更细节的数据，其中内力数值
格式 内力值1/内力值2(内力值3)格式中内力值1是可用内力，内力
值2是最大内力，内力值3是当前该玩家内功水平所能达到的极限内
力。
极限内力总和是显示的各项内功极限内力求和并扣除N-1门内功极限
内力中基本内功对应的内力。当你的内力比极限内力来说小的非常
多的时候走火入魔概率会大幅下降，当你的最大内力之和比极限内
力总和还要高的时候，走火入魔概率就会有一定程度提高。

see also : score
HELP
    );
    return 1;
}
