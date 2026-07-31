// hp cmds (Mon  09-04-95)
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
string status_color(int current, int max);
 
int main(object me, string arg)
{
	object ob;
	mapping my;
        string str;
int i;
	seteuid(getuid(me));
 
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");
if (ob->query("jingli") <0)
ob->set("jingli",0);

if (ob->query("neili") <0)
ob->set("neili",0);

    i=(ceil(pow(ob->query("combat_exp")*10.0, 0.444444)) + 100)*500;	
	my = ob->query_entire_dbase();
    printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);
    printf(HIW"  · 精 气 · %s%4d/ %4d %s(%3d%%)" + HIW"    · 精 力 · %s%4d / %4d (+%d)\n" NOR,
		status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
		status_color(my["eff_jing"], my["max_jing"]),	my["eff_jing"] * 100 / my["max_jing"],
		status_color(my["jingli"], my["max_jingli"]),	my["jingli"], my["max_jingli"],
		my["jiajing"] );
    printf(HIW"  · 气 血 · %s%4d/ %4d %s(%3d%%)" + HIW"    · 内 力 · %s%4d / %4d (+%d)\n" NOR,
		status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
		status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
		status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],
		my["jiali"] );
    write(sprintf("  %s %s%10d    " NOR HIW"       ·内力上限·%s%d     \n" NOR,
                my["shen"] < 0?HIR"· 戾 气 ·":HIC"· 正 气 ·", HIW,
                (my["shen"] < 0?-1:1) * my["shen"],
                HIC,
            
        ob->query_skill("force")*15 + (ob->query("szj/passed")?ob->query_skill("shenzhao-jing",1)*4:0)));

//    printf(" 神　： %s%4d
        if(my["food"]*100/ob->max_food_capacity()>100) str=HIC+"很饱";
        else if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"正常";
        else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"缺食";        
		else if(my["food"]*100/ob->max_food_capacity()>30) str=CYN+"缺食";
        else if(my["food"]*100/ob->max_food_capacity()>10) str=HIR+"缺食";
        else str=RED+"饥饿";
    printf(HIW"  『 食 物 』 %s%4d/ %4d[%4s] " HIW "     『 潜 能 』 %s%d %s上限[%d]\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,
        HIY,
        (int)ob->query("potential") - (int)ob->query("learned_points"),
        HIW,i);
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"很饱";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"正常";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"缺水";
        else str=RED+"饥渴";
    printf(HIW"  『 饮 水 』 %s%4d/ %4d[%4s] " HIW "     『 经 验 』 %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,
        HIM,
        my["combat_exp"] );
/*
if ( (int)me->query_condition("bonze_drug" ) > 0 || (int)me->query_condition("putizi_drug" ) > 0)
    	write(HIC"  『 灵药 』:尚在"); 
else
    	write(HIC"  『 灵药 』:无有"); 

if ( (int)me->query_condition("medicine" ) > 0)
    	write(HIG"  『 药性 』:尚在"); 
else
    	write(HIG"  『 药性 』:无有"); 
    	
if ( (int)me->query_condition("killer" ) > 0)
    	write(HIR"  『 通缉 』:尚在"); 
else
    	write(HIR"  『 通缉 』:无有"); 
    	
if ( (int)me->query_condition("psgc" ) > 0)
    	write(HIW"  『 判师 』:尚在\n"); 
else
    	write(HIW"  『 判师 』:无有\n");     	    	*/
	    printf(HIC"≡"HIY"───────────────────────────海 洋 IV───"HIC"≡\n"NOR);
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
