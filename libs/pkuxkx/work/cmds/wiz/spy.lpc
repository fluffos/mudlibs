// spy.c
// by ReyGod  in  12/16/1996  in BUPT
// modified by whuan@pkuxkx 
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{       
        object ob;
        mapping mine;
        string line;
        string marks;
        string exp;
        int basic_data;
//      me = this_player();
        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
        } else
                return notify_fail("只有巫师能察看别人的状态。\n");
        mine = ob->query_entire_dbase();
        line = sprintf("\n-------先天资质-------\n");
        line += sprintf(
                        " 膂力：[%s] 悟性：[%s] 根骨：[%s] 身法：[%s] 容貌：[%s] 福缘：[%s]：灵性：[%s]\n\n", 
                        sprintf("%3d",mine["str"]),
                        sprintf("%3d",mine["int"]),
                        sprintf("%3d",mine["con"]),
                        sprintf("%3d",mine["dex"]),
                        sprintf("%3d",mine["per"]),
                        sprintf("%3d",mine["kar"]),
                        sprintf("%3d",30));
        line += sprintf("-------后天资质-------\n");
        line += sprintf(
                        " 膂力：[%s] 悟性：[%s] 根骨：[%s] 身法：[%s] 容貌：[%s] 福缘：[%s]：灵性：[%s]\n\n", 
                        sprintf("%3d",ob->query_str()),
                        sprintf("%3d",ob->query_int()),
                        sprintf("%3d",ob->query_con()),
                        sprintf("%3d",ob->query_dex()),
                        sprintf("%3d",ob->query_per()),
                        sprintf("%3d",ob->query_kar()),
                        sprintf("%3d",ob->query_spi()));
        line += sprintf(HIC"-------魔法提升先天根骨：%s\n\n"NOR, sprintf("%3d",ob->query("con_improve_time")));
        basic_data = mine["str"] + mine["int"] + mine["con"] + mine["dex"];
        if(basic_data > (80 + (int)ob->query("con_improve_time")))
          line += sprintf(HIY "先天资质异常, %3d - 80 = %3d\n\n" NOR,basic_data,(basic_data-80));
        marks=sprintf("\n-------各项MARK-------\n");
        marks += sprintf("侠客岛  :[%d]\n左右互搏:[%d]\n仙丹    :[%d]\n一灯大师:[%d]\n欧阳锋  :[%d]\n任督二脉:[%d]\n",
                        ob->query("xkdling"),        //侠客岛
                        ob->query("zyhb"),           //左右互搏
                        ob->query("gift/xiandan"),   //仙丹
                        ob->query("task_duan3"),     //一灯任务
                        ob->query("oyf_son"),       //欧阳锋任务
                        ob->query("renduermai"));       //任督二脉
        exp=sprintf("\n-------成长速度-------\n");
        exp += sprintf("经验：[%10d]/小时\n潜能：[%10d]/小时\n\n",
                        ob->query("combat_exp")/(ob->query("mud_age")/3600+1),
                        ob->query("potential") /(ob->query("mud_age")/3600+1));
        exp += sprintf("task：[%5d]次\n护镖：[%5d]次\n萧峰：[%5d]次\n护送：[%5d]次\n胡一刀：[%5d]次\n韩员外:[%5d]次\n刺杀：[%5d]次\n公孙止:[%5d]次\n韩世忠:[%5d]次\n\n",
                        ob->query("jobs/completed/task"),
                        ob->query("jobs/completed/hubiao"),
                        ob->query("jobs/completed/xiaofeng"),
                        ob->query("jobs/completed/husong"),
                        ob->query("jobs/completed/huyidao"),
						ob->query("newjobs/completed/hyw"),
						ob->query("newjobs/completed/mzj"),
						ob->query("jobs/completed/gongsun"),
						ob->query("jobs/completed/hansz"),
						);
        if ((mine["int"] - mine["kar"] / 4) * 480 <= 9999 ) 
            exp +="\n可以学习左右互搏。\n";    
        else
            exp +="\n太聪明，不可以学习左右互搏。\n";  
        write(line); 
        write(marks);
        write(exp);        
        return 1;
}
