// top.c

#include <ansi.h>

inherit F_CLEAN_UP;

// 逆序排列(从高到低)
int sort_family(string f1, string f2, mapping fame)
{
        return fame[f2] - fame[f1];
}

// 逆序排列(从高到低)
int sort_league(string f1, string f2, mapping fame)
{
        return fame[f2] - fame[f1];
}

int main(object me, string arg)
{
        mapping last, fame,t,t2;
        string *fam;
        string msg;
        	string info,name,id,file,infoa,infob;
        int delta;
        int i;
if (wizardp(me))
{
//write("OK");
//FAMILY_D->add_family_fame(me,1);
//return 1;
}
//FAMILY_D->delete("last_check");
//FAMILY_D->save();
        if (! arg || arg == "family")
        {
infoa = read_file("/data/npc/menpai.o");
infob = read_file("/data/npc/menpai1.o");

                fame = FAMILY_D->query_family_fame();
                last = FAMILY_D->query_all_last_family_fame();
        
                fam = keys(fame) - ({ 0 });
                fam = sort_array(fam, (: sort_family :), fame);
        
                msg = WHT "目前江湖上所有名门大派的声望状况\n" NOR
                      HIY "────────────────\n" NOR;
msg += "〖武林争霸〗"+infoa+"对战"+infob+"\n"NOR;
                for (i = 0; i < sizeof(fam); i++)
                {
                        delta = fame[fam[i]] - last[fam[i]];
                        msg += sprintf("%2d. %-12s  %-9d(%s%d%s)\n",
                                       i + 1, fam[i], fame[fam[i]],
                                       (delta > 0) ? HIY "+" :
                                       (delta < 0) ? HIR : WHT,
                                       delta, NOR);
                }
        
                msg += HIY "────────────────\n" NOR
                       WHT "一共是" + chinese_number(i) + "个门派。\n" NOR;
        }
        //write(t);
        //write(t2);
        write(msg);

        return 1;
}

int help(object me)
{
   	write(@HELP
指令格式: top [family | league]

查看目前江湖上大门派排名状况和相比去年变化，玩家互相之间的仇杀。
和武林争霸时玩家与NPC之间的仇杀，会改变排名的程度。
HELP );
   	return 1;
}
