#include <ansi.h>
inherit F_CLEAN_UP;

string status_color(int current, int max);

int main(object me, string arg)
{
	object ob;
	mapping my;
	int pp,dao,x,i,f,w,p;
	string str;
	seteuid(getuid(me));
        
	if ( !arg ) ob = me;
	else if (wizardp(me)) 
        { 
        	ob = present(arg, environment(me));
        	if ( !ob ) ob = find_player(arg);
        	if ( !ob ) ob = find_living(arg);
        	if ( !ob )       
                	return notify_fail("您要察看谁的状态？\n");
        } 
	else    return notify_fail("只有巫师才可以察看别人的状态。\n");

	my = ob->query_entire_dbase();
	if( !me->query("env/hp_msg") )
	{
		printf(NOR CYN"┏━━━━━━━━━━━━━━"NOR HIM"小"HIG"雨"HIR"·"HIW"西"HIY"游"NOR CYN"━━━━━━━━━━━━━━┓\n"NOR,);
		printf(NOR CYN"┃"NOR CYN"  姓 名："NOR WHT"%-12s "NOR CYN" 性别："NOR WHT"%-10s "NOR CYN"I D："NOR WHT"%-21s"NOR CYN"┃\n"NOR,ob->name(),ob->query("gender"),"["+capitalize(ob->query("id"))+"]");
		printf(NOR CYN"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"NOR);
	}
	else	printf("\n%s\n",ob->short());
		
	if( my["eff_kee"]<100000 )
		pp = my["eff_kee"]*100/ob->query_maxkee();
	else	pp = my["eff_kee"]*10/ob->query_maxkee()*10;	
	
	if( !me->query("env/hp_msg") )
	{
		printf(NOR CYN"┃"NOR WHT"〖 气血 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],ob->query_maxkee()),pp);
		printf(NOR WHT"  〖 内力 〗%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["force"], ob->query_maxforce()), my["force"], ob->query_maxforce(),my["force_factor"]);
		printf(NOR CYN"┃"NOR WHT"〖 精神 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],ob->query_maxsen()),my["eff_sen"]*100/ob->query_maxsen());
		printf(NOR WHT"  〖 法力 〗%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["mana"], ob->query_maxmana()), my["mana"], ob->query_maxmana(),my["mana_factor"]);
	}	
	else
	{
		printf(NOR"〖 气血 〗%s%12d/%12-d%s[%3d%%]"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],ob->query_maxkee()),pp);
		printf(NOR"  〖 内力 〗%s%d/%d(+%4d)\n"NOR,status_color(my["force"], ob->query_maxforce()), my["force"], ob->query_maxforce(),my["force_factor"]);
		printf(NOR"〖 精神 〗%s%12d/%12-d%s[%3d%%]"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],ob->query_maxsen()),my["eff_sen"]*100/ob->query_maxsen());
		printf(NOR"  〖 法力 〗%s%d/%d(+%4d)\n"NOR,status_color(my["mana"], ob->query_maxmana()), my["mana"], ob->query_maxmana(),my["mana_factor"]);
	}
	f = my["food"]*100/ob->max_food_capacity();
	if ( f>100 )            str=HIC+"很饱";
	else if ( f>90 )        str=HIG+"正常";
	else if ( f>60 )        str=HIY+"缺食";        
	else if ( f>30 )        str=CYN+"缺食";
	else if ( f>10 )        str=HIR+"缺食";
	else                    str=RED+"饥饿";
	printf(NOR CYN"┃"NOR WHT"〖 食物 〗%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        printf(NOR WHT"  〖 等级 〗%s%18-d    "NOR CYN"┃\n"HIG,HIY,(int)ob->query_level());
        
	w = my["water"]*100/ob->max_water_capacity();
	if ( w>100 )            str=HIC+"很饱";
	else if ( w>90 )        str=HIG+"正常";
	else if ( w>60 )        str=HIY+"缺水";
	else if ( w>30 )        str=CYN+"缺水";
	else if ( w>10 )        str=HIR+"缺水";
	else                    str=RED+"饥渴";
	printf(NOR CYN"┃"NOR WHT"〖 饮水 〗%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        
        p=(int)ob->query("combat_exp");
        if( p<10000000 )
        	p = p*100/ob->query_max_exp();
        else	p = p/10000*100/(ob->query_max_exp()/10000);
        if( p>100 ) p = 100;	
        
printf(NOR WHT"  〖 经验 〗%s%18-d%3d%%"NOR CYN"┃\n"HIG,HIY,(int)ob->query("combat_exp")>0?(int)ob->query("combat_exp"):1,p);
printf(NOR CYN"┃"NOR WHT"〖 潜能 〗%s%10-d/%10-d "NOR,HIG,(int)ob->query("potential")-(int)ob->query("learned_points"),ob->query_level()*5000);
printf(NOR WHT"  〖 杀气 〗%s%20-d "NOR CYN" ┃\n"HIG,HIR,(int)ob->query("bellicosity"));
printf(NOR CYN"┃"NOR WHT"〖 活力 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["gin"],ob->query_maxgin()),my["gin"],ob->query_maxgin(),status_color(ob->query_maxgin(),ob->query_maxgin()),ob->query_maxgin()*100/ob->query_maxgin());
printf(NOR WHT"  〖 境界 〗%s%20-s "NOR CYN" ┃\n"HIG,HIR,ob->level_name(1));
    
dao=(int)ob->query("daoxing");    
if( dao>0 )   
	printf(NOR CYN"┃"NOR WHT"〖 道行 〗%s%52-s    "NOR CYN"┃\n"NOR,HIM,COMBAT_D->chinese_daoxing(dao));    
else	printf(NOR CYN"┃"NOR WHT"〖 道行 〗%s%52-s    "NOR CYN"┃\n"NOR,HIM,"未入道途");    	
/*
if (ob->query("degree"))
        printf(NOR CYN"┃"NOR WHT"〖 官拜 〗%s%52-s    "NOR CYN"┃\n"NOR,HIW,ob->query("degree"));
else    printf(NOR CYN"┃"NOR WHT"〖 官拜 〗%s%52-s    "NOR CYN"┃\n"NOR,HIW,"未入仕途");
*/
printf(NOR CYN"┃"NOR WHT"〖 物防 〗%s%21-d "NOR,HIY,ob->query_combat_def());
printf(NOR WHT"  〖 物攻 〗%s%20-d "NOR CYN" ┃\n"NOR,HIY,ob->query_combat_damage());
printf(NOR CYN"┃"NOR WHT"〖 法防 〗%s%21-d "NOR,HIY,ob->query_spells_def());
printf(NOR WHT"  〖 法攻 〗%s%20-d "NOR CYN" ┃\n"NOR,HIY,ob->query_spells_damage());

if( !userp(ob) )
	printf(NOR CYN"┃"NOR WHT"〖最大经验〗%s%52-d  "NOR CYN"┃\n"NOR,HIR,ob->query_max_exp());    

printf(NOR CYN"┗━━━━━━━━━━━━━━"HIY"X"HIR"·"HIY"Y"HIR"·"HIY"X"HIR"·"HIY"Y"NOR CYN"━━━━━━━━━━━━━━┛\n"NOR);
printf("\n");   
return 1;
}

string status_color(int current, int max)
{
        int percent;
        if( max>0 ) 
        {
        	if( current>=10000 )
        		percent = current * 10 / max * 10;
        	else	percent = current * 100 / max;
        }	
        else	percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return CYN;
        if( percent >= 10 ) return HIR;
        return RED;
}



int help(object me)
{
        write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}

