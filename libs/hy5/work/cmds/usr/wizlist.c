//modify by sword@fw.2000.07.19
#include <ansi.h>
inherit F_CLEAN_UP;
mapping wizhood=([
        "(root)":       HIY" 创世者 "HIB,    
        "(admin)":      HIW" 天  神 "HIB,
        "(arch)":       HIM" 大  神 "HIB,
        "(wizard)":     HIY" 大巫师 "HIB,
        "(apprentice)": HIC" 天  使 "HIB,
        "(immortal)":   HIB" 精  灵 "HIB,
        "(elder)":      HIB" 荣誉玩家 "HIB,

]);

mapping wizlevel=([
        0:      "(root)",
        1:      "(admin)",
        2:      "(arch)",
        3:      "(wizard)",
        4:      "(apprentice)",
        5:      "(immortal)",
        6:      "(elder)",
]);

int main(object me, string arg)
{

        string *list, ch,job,area;
        int my_level,b, i, j, number,a,mark,lev;
        object ob;

        number = 0;
        job="";
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        write(HIR"★"+HIY+""+MUD_NAME +""HIR"★"HIG"巫师列表：\n"NOR);

        write(HIR"★"HIW"≡"HIB"──────────────────────────────"HIW"≡"HIR"★\n"NOR);
        write(HIB"  【"HIW"巫师等级"HIB"】   【"HIW"巫师ID"HIB"】【"HIW"状态"HIB"】【"HIW"负责区域"HIB"】【"HIW"  目 前 任 务  "HIB"】\n"NOR);

        write(HIR"★"HIW"≡"HIB"──────────────────────────────"HIW"≡"HIR"★"NOR);
        my_level=wiz_level(me);
if (wizardp(me)) {
lev=7;
}
else {
lev=5;
}
        for (b=0;b<lev;b++)
        {
        mark=0;
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])==wizlevel[b]) mark=1;
        if(mark){
        printf(HIB"\n  【"+wizhood[wizlevel[b]]+"】  "NOR);
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])==wizlevel[b])
        {

                ch = HIR"离线"NOR;
                a = 0;
//                 area=JOB_D->job_query(list[i]+"/area");
//                job=JOB_D->job_query(list[i]+"/job");
                if(!area) area="未知区域";
                if(!job) job="动向不明";
                if(ob=find_player(list[i])&&!find_player(list[i])->query("env/invisibility"))

//     if (!find_player(list[i])->query("env/invisibility")||( find_player(list[i])->query("env/invisibility") && wiz_level(find_player(list)
                {
                ch = HIG"在线"NOR ;
//                ch = HIR"离线"NOR;
                a = 1;
                number = number + 1;
                };
                printf(HIY"  %-10s"" %s    "HIC"%-10s"HIW"  %s\n                ",list[i],ch,area,job," " ? "\n  " : " ");

        }
        }
        }
        write(HIR"\n★"HIW"≡"HIB"──────────────────────────"HIG"HY2"HIB"──"HIW"≡"HIR"★\n"NOR);
if (wizardp(me)) {
        printf(HIR"★"+HIY+MUD_NAME+HIG"目前一共有:"BLINK HIR" %s"NOR HIG"个巫师。\n"NOR,chinese_number(sizeof(list)) );
}
        printf(HIR"★"+HIY+MUD_NAME+HIG"的巫师申请请看:"+HIY"help wiz_new "+NOR+"。\n");
        printf(HIR"★"+HIY+MUD_NAME+HIG"目前共有："BLINK HIR"%s"NOR HIG"位巫师在线上。"NOR,chinese_number(number));
        write("\n");
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式：wizlist
指令说明：
           本指令用来查看目前总共有多少个巫师。
HELP
    );
    return 1;
}
