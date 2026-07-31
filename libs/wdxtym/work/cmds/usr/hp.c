#include <ansi.h> 
#include <combat.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int potential_lv(int exp);
int main(object me, string arg)
{
	object ob;
	int craze;
	mapping my;
	string str,skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points;
	
	seteuid(getuid());
	if(!arg) ob = me;
	else if (wizardp(me)) 
	{ 
	     ob = present(arg, environment(me));
	     if (!ob) ob = find_player(arg);
	     if (!ob) ob = find_living(arg);
	     if (!ob) return notify_fail("您要察看谁的状态？\n");
	} 
	else return notify_fail("只有巫师才可以察看别人的状态。\n");
	
	my = ob->query_entire_dbase();

	if (my["max_jing"] < 1 || my["max_qi"] < 1)
		return notify_fail("无法察看" + ob->name(1) + "的状态。\n");

	str = ZJOBLONG;
	str += sprintf("姓名：%s ("HIG"%s"NOR") "NOR,ob->name(),capitalize(ob->query("id")));
	str += (HIY"	Level : "+HIG+ob->query("level")+NOR"\n");
	str += sprintf("一一一一一一一一一一一一一一一一一一一一\n");
	str += sprintf(HIR"〖气血〗：%s%d/%d%s(%d%%)\n"NOR,status_color(my["qi"],my["eff_qi"]),my["qi"],my["eff_qi"],
		status_color(my["eff_qi"],my["max_qi"]),my["eff_qi"]*100/(my["max_qi"]+ob->query_gain_qi()));
	
	str += sprintf(HIR"〖内力〗：%s%d/%d(+%d)"NOR"\n",status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],my["jiali"]);
   
	str += sprintf(HIR"〖精神〗：%s%d/%d%s(%d%%)\n"NOR,status_color(my["jing"],my["eff_jing"]),my["jing"],
		my["eff_jing"],status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"]);
	str += sprintf(HIR"〖精力〗：%s%d/%d(+%d)"NOR"\n",status_color(my["jingli"],my["max_jingli"]),
		 my["jingli"],my["max_jingli"],my["jiajing"]);
	str += sprintf(CYN"〖食物〗：%s%d/%d[%d%%]\n"NOR,status_color(my["food"], ob->max_food_capacity()),
		my["food"], ob->max_food_capacity(),my["food"]*100/ob->max_food_capacity());
	str += sprintf(CYN"〖饮水〗：%s%d/%d[%d%%]\n"NOR,status_color(my["water"], ob->max_water_capacity()),
		my["water"], ob->max_water_capacity(),my["water"]*100/ob->max_water_capacity());
	str += sprintf(CYN"〖潜能（万）〗：%s%d/%d(max)"NOR"\n",HIY,(int)ob->query("potential")/10000  - (int)ob->query("learned_points")/10000 ,(int)ob->query_potential_limit() - (int)ob->query("learned_points")/10000 );
	str += sprintf(CYN"〖修为（万）〗：%s%d/%d(up)"NOR"\n",HIY,my["combat_exp"]/10000 ,F_LEVEL->level_max_exp(ob));
	str += sprintf("一一一一一一一一一一一一一一一一一一一一\n");
//str += sprintf(HIC"≡"HIY"──────────────────────"HIC"≡"NOR"\n");
//str += sprintf(HIR"〖武神魂力〗：" NOR + HIY " %-21d""\n", wsexp);

//str += sprintf(HIR"〖法宝等级〗：" NOR + HIY "%d 级  ""\n", ob->query("fabao/lv"));
//	str += sprintf(HIR"〖元神等级〗：" NOR + HIY "%d 级 / %s""\n", ob->query("yuanshen/level"),ZJURL("cmds:yuanshen up")ZJSIZE(29)""HIW" 升级");
    str += sprintf(HIM"〖元神〗：" NOR + HIY "%d 级 / %d(升级所需)  %s""\n", ob->query("yuanshen/level"),F_LEVELL->levell_max_exp(ob),ZJURL("cmds:yuanshen up")ZJSIZE(30)""HIW" 提升");
    str += sprintf(HIM"〖元神修为〗：" NOR + HIY "%d   ""\n", ob->query("yuanshen/exp"));

//str += sprintf(HIR"〖武神真身〗：" NOR + HIY "%d 阶 / %s""\n", dj,ZJURL("cmds:help wshen")ZJSIZE(25)""HIW" 升阶"+ZJURL("cmds:wushensj")ZJSIZE(25)""HIW" / 提升100阶");

//	str += sprintf("一一一一一一一一一一一一一一一一一一一一\n");
	if (craze = ob->query_craze())
	{
		if (ob->is_most_craze())
		{ 
			str += (HIR"【愤　"+HIY"　怒"+NOR+HIR"】"+NOR);
			str += sprintf("%s", ob->query("character") == "光明磊落" ? MAG"  竖发冲冠  ( burning 燃烧怒气 )"+NOR+"\n"
										    : HIM"  怒火中烧  ( burning 燃烧怒气 )"+NOR+"\n");
		}
		else
		{
			str += sprintf(HIR "【愤　　怒】：%d/%d(+%d)\n",craze, ob->query_max_craze(),
				      ob->query("jianu"));
		}
	} 
      else
	{
		 str += sprintf(MAG "【心平气和】：一一一一一一一一一一一\n"+NOR);
	}
     
	 
	str += sprintf(MAG "【实战体会】：%s%d/%d\n【内精极限（万）】：%s%d/%d"NOR"\n",
		HIM,my["experience"] - my["learned_experience"],ob->query_experience_limit() - my["learned_experience"]/10000  ,HIM,ob->query_neili_limit()/10000 ,ob->query_jingli_limit()/10000 );
  	 
     
	str += sprintf("一一一一一一一一一一一一一一一一一一一一\n");
	str += sprintf(HIG"★"HIY"天赋点"NOR"/"HIM"技能点"HIG"★( "HIY+ob->query("tianfu_point")+NOR"/"HIM+ob->query("skill_point")+NOR+HIG" )"NOR"\n");

	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
	str += "\n";
	message("vision", str, me);
	return 1;
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
int potential_lv(int level)
{
	int grade;
	grade =level/5+1;
	return grade;
}

int help(object me)
{
	write(@HELP
指令格式 : hp
	   hp <对象名称>		   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}

