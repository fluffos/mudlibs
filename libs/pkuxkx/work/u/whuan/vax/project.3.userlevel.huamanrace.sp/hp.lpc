#include <ansi.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int main(object me, string arg)
{
        object ob,ob1;
        mapping my;
        string owner;
        seteuid(getuid(me));
        if(!arg)
                ob = me;
		else
        {
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
		if (wizardp(me))
		{
		}
		else if(!ob&&!ob1)
			return notify_fail("只有巫师能察看别人的状态。\n");
		else if(ob!=me&&ob1!=me)
			return notify_fail("只有巫师能察看别人的状态。\n");
        my = ob->query_entire_dbase();
        printf("──────────────────────────────────\n");
        printf(" 【 精 】： %s%4d/ %4d %s(%3d%%)" NOR "        【精力】： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),   my["eff_jing"] * 100 / (my["max_jing"]),
                status_color(my["jingli"], my["max_jingli"]),   my["jingli"], my["max_jingli"],
                my["jiajing"] );
        printf(" 【 气 】： %s%4d/ %4d %s(%3d%%)" NOR "        【内力】： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / (my["max_qi"]),
                status_color(my["neili"], my["max_neili"]), my["neili"], (my["max_neili"]),
                my["jiali"] );
        printf(" 【食物】： %s%4d/ %4d      " NOR "         【潜能】：   %s%d\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIC,
        (int)ob->query("potential") - (int)ob->query("learned_points"));
        printf(" 【饮水】： %s%4d/ %4d      " NOR "         【经验】：   %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIC,
        my["combat_exp"] );
		printf(" 【等级】： %s%6s          " NOR "         【疾病】：   %s%s\n" NOR,
        HIC, chinese_number( (int)my["level"] ), 
        HIG, "无" );
		printf(" 【特别潜能】： %s%s\n" NOR, HIC, chinese_number( (int)my["level"] - (int)my["level_used"] ));
		
if ( (int)me->query_condition("bonze_drug" ) > 0 && me->query("family/family_name") == "少林派")
        write(" 【药性】：    尚在     \n");
else if (me->query("family/family_name") == "少林派")
        write(" 【药性】：    无     \n");
        printf("──────────────────────────────────\n");
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
