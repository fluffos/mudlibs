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
        if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄ×´Ì¬£¿\n");
	} else
		return notify_fail("Ö»ÓĞÎ×Ê¦ÄÜ²ì¿´±ğÈËµÄ×´Ì¬¡£\n");
if (ob->query("jingli") <0)
ob->set("jingli",0);
    i=(ceil(pow(ob->query("combat_exp")*10.0, 0.333333)) + 100)*500;	
	my = ob->query_entire_dbase();
    printf(HIC"¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIC"¡Ô\n"NOR);
    printf(HIW"  ¡¤ ¾« Æø ¡¤ %s%4d/ %4d %s(%3d%%)" + HIW"    ¡¤ ¾« Á¦ ¡¤ %s%4d / %4d (+%d)\n" NOR,
		status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
		status_color(my["eff_jing"], my["max_jing"]),	my["eff_jing"] * 100 / my["max_jing"],
		status_color(my["jingli"], my["max_jingli"]),	my["jingli"], my["max_jingli"],
		my["jiajing"] );
    printf(HIW"  ¡¤ Æø Ñª ¡¤ %s%4d/ %4d %s(%3d%%)" + HIW"    ¡¤ ÄÚ Á¦ ¡¤ %s%4d / %4d (+%d)\n" NOR,
		status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
		status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
		status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],
		my["jiali"] );
    write(sprintf("  %s %s%10d    " NOR HIW"       ¡¤ÄÚÁ¦ÉÏÏŞ¡¤¤ %s%d / %d    \n" NOR,
                my["shen"] < 0?HIR"¡¤ ìå Æø ¡¤":HIC"¡¤ Õı Æø ¡¤", HIW,
                (my["shen"] < 0?-1:1) * my["shen"],
                HIC,
            ob->query_skill("force")*12 + (ob->query("szj/passed")?ob->query_skill("shenzhao-jing",1)*4:0),
        ob->query_skill("force")*15 + (ob->query("szj/passed")?ob->query_skill("shenzhao-jing",1)*4:0)));

//    printf(" Éñ¡¡£º %s%4d
        if(my["food"]*100/ob->max_food_capacity()>100) str=HIC+"ºÜ±¥";
        else if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"Õı³£";
        else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"È±Ê³";        
		else if(my["food"]*100/ob->max_food_capacity()>30) str=CYN+"È±Ê³";
        else if(my["food"]*100/ob->max_food_capacity()>10) str=HIR+"È±Ê³";
        else str=RED+"¼¢¶ö";
    printf(HIW"  ¡º Ê³ Îï ¡» %s%4d/ %4d[%4s] " HIW "     ¡º Ç± ÄÜ ¡» %s%d %sÉÏÏŞ[%d]\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,
        HIY,
        (int)ob->query("potential") - (int)ob->query("learned_points"),
        HIW,i);
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"ºÜ±¥";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"Õı³£";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"È±Ë®";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"È±Ë®";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"È±Ë®";
        else str=RED+"¼¢¿Ê";
    printf(HIW"  ¡º Òû Ë® ¡» %s%4d/ %4d[%4s] " HIW "     ¡º ¾­ Ñé ¡» %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,
        HIM,
        my["combat_exp"] );
if ( (int)me->query_condition("bonze_drug" ) > 0 || (int)me->query_condition("putizi_drug" ) > 0)
    	write(HIC"  ¡º ÁéÒ©Ò©ĞÔ ¡»:ÉĞÔÚ     \n"); 
else
    	write(HIC"  ¡º ÁéÒ©Ò©ĞÔ ¡»:ÎŞ       \n"); 

if ( (int)me->query_condition("medicine" ) > 0)
    	write(HIG"  ¡º ÆÕÍ¨Ò©ĞÔ ¡»:ÉĞÔÚ      \n"); 
else
    	write(HIG"  ¡º ÆÕÍ¨Ò©ĞÔ ¡»:ÎŞ        \n"); 
	    printf(HIC"¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤º£ Ñó II©¤©¤©¤"HIC"¡Ô\n"NOR);
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
Ö¸Áî¸ñÊ½ : hp
           hp <¶ÔÏóÃû³Æ>                   (Î×Ê¦×¨ÓÃ)
 
Õâ¸öÖ¸Áî¿ÉÒÔÏÔÊ¾Äã(Äã)»òÖ¸¶¨¶ÔÏó(º¬¹ÖÎï)µÄ¾«, Æø, ÉñÊıÖµ¡£
 
see also : score
HELP
    );
    return 1;
}
