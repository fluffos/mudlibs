// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// bunch.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int sort_bunch(string f1, string f2, mapping fame)
{
        return fame[f2] - fame[f1];
}

int sort_hatred(string id1, string id2, mapping hatred);
int sort_member(string id1, string id2);
int show_bunch_info(object me, string arg);
int show_bunch_area(object me, string arg);
int show_bunch_member(object me, string arg);
int show_bunch_hatred(object me, string arg);
int show_bunch_all(object me, string arg);
int expell_bunch_member(object me, string arg);
int dismiss_bunch(object me, string arg);

int main(object me, string arg)
{
        object *obs;
        string fname;
        string *args;

        if (! arg) arg = "info";
        args = explode(arg, " ");
        if (sizeof(args) > 1)
                arg = implode(args[1..<1], " ");
        else
                arg = 0;

        switch (args[0])
        {
        case "info":
                // 显示同盟的信息
                return show_bunch_info(me, arg);

        case "member":
                return show_bunch_member(me, arg);

        case "dismiss":
                return dismiss_bunch(me, arg);

        case "top":
                return "/cmds/usr/top"->main(me, "bunch");

        case "area":
                return show_bunch_area(me, arg);
                
        case "hatred":
                // 显示同盟的仇人
                return show_bunch_hatred(me, arg);                
                
        case "all":
                return show_bunch_all(me, arg);

        case "out":
                if (! stringp(fname = me->query("bunch/bunch_name")))
                        return notify_fail("你现在还没有加入任何帮派呢。\n");

                if (me->query_temp("pending/out_bunch"))
                {
                        // 同盟的声望下降
                        BUNCH_D->add_bunch_fame(fname, -BUNCH_D->query_bunch_fame(fname) / 10);
                        CHANNEL_D->do_channel(this_object(), "rumor",
                                "听说" + me->name(1) + "(" + me->query("id") +
                                ")义无反顾，已经背离『" + fname + "』而去。");
                        me->delete_temp("pending/out_bunch");

                        // 清除该用户在同盟中的信息
                        UPDATE_D->clear_user_data(me->query("id"), "bunch");
                        return 1;
                }

                write("你真的想要背弃这个帮派吗？这样做会降低" + fname + "的声望。\n"
                      YEL "如果你确定了，就再输入一次 bunch out 命令。\n" NOR);
                me->set_temp("pending/out_bunch", 1);
                return 1;
        }

        write("无效的参数。\n");
        return 1;
}

// 根据玩家和参数选择同盟的名字
mixed select_bunch(object me, string arg)
{
        string fam;
        object ob;

        if (! wizardp(me))
                // only wizard can show every league's list
                fam = 0;
        else
        if (stringp(arg) && arg != "")
        {
                if (! arrayp(BUNCH_D->query("member/" + fam)))
                        fam = 0;
                else
                        fam = arg;

                if (! stringp(fam) && objectp(ob = UPDATE_D->global_find_player(arg)))
                {
                        // 没有 arg 这个同盟，查看是否有该玩家
                        fam = ob->query("bunch/bunch_name");
                        UPDATE_D->global_destruct_player(ob);
                        if (! stringp(fam))
                                return notify_fail("这人现在没有加入任何帮派。\n");
                }

                if (! stringp(fam))
                        return notify_fail("没有这个玩家，不能查阅相关的同盟。\n");
        }

        if (! fam)
        {
                // select my league
                if (! stringp(fam = me->query("bunch/bunch_name")))
                        return notify_fail("你现在还没有加入任何帮派呢。\n");
        }

        return fam;
}


// 显示同盟的仇人
int show_bunch_hatred(object me, string arg)
{
        mapping hatred;
        string fam;
        string *ids;
        mixed *data;
        string msg;
        string st;
        int count;
        int i;

        if (! stringp(fam = select_bunch(me, arg)))
                return 0;

        hatred = BUNCH_D->query_bunch_hatred(fam);
        if (! mapp(hatred) || ! sizeof(hatred))
        {
                write(fam + "现在没有什么仇人。\n");
                return 1;
        }

        ids = keys(hatred) - ({ 0 });
        ids = sort_array(ids, (: sort_hatred :), hatred);

        count = 0;
        msg = WHT "目前" + fam + "在江湖上的仇敌都有\n" NOR
              HIY "────────────────\n" NOR;
        for (i = 0; i < sizeof(ids) && count < 30; i++)
        {
                data = hatred[ids[i]];
                if (! arrayp(data) || sizeof(data) < 2 ||
                    ! stringp(data[0]) || ! intp(data[1]))
                        continue;

                st = sprintf("%s(%s%s%s)", data[0], YEL, ids[i], NOR);
                msg += sprintf("%2d. %-34s  %s%-9d%s\n",
                               ++count, st, HIR, data[1], NOR);
        }

        msg += HIY "────────────────\n" NOR;
        if (i < sizeof(ids))
                msg += WHT "江湖上的敌人太多，难以尽数。\n" NOR;
        else
                msg += WHT "目前一共是" + chinese_number(i) +
                       "人。\n" NOR;
        write(msg);
        return 1;
}

// 显示某一个同盟中的人员
int show_bunch_member(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (! arg)
        {
                if (! stringp(arg = me->query("bunch/bunch_name")))
                        return notify_fail("你现在还没有加入任何一个帮派呢。\n");
        }

        if (! arrayp(member = BUNCH_D->query_members(arg)))
        {
                write("现在江湖上没有(" + arg + ")这个帮派。\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(arg + "现在人丁稀落。\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("你现在精神不济，无法打听这些消息。\n");

                if (me->is_busy())
                        return notify_fail("你现在正忙，没有时间打听这些消息。\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        msg = "";
        n = 0;
        foreach (id in member)
        {
                user = UPDATE_D->global_find_player(id);
                if (! objectp(user))
                        continue;

                n++;
                msg += user->short(1) + "\n";
                UPDATE_D->global_destruct_player(user);
        }

        if (msg == "")
                return notify_fail(arg + "现在人丁稀落。\n");

        write(arg + "目前有以下" + chinese_number(n) + "人：\n" + msg);
        return 1;
}

// 显示某一个同盟中的人员
int show_bunch_all(object me, string arg)
{
        mapping fame;
        string *fam;
        string id, bunch;
        object user;
        string msg;
        int n, npc, area, player;

        if (! mapp(fame = BUNCH_D->query_bunch_fame()))
        {
                write("现在江湖上没有任何有名的帮派。\n");
                return 1;
        }
        
        fam = keys(fame) - ({ 0 });

        if (sizeof(fam) < 1)
                return notify_fail("目前江湖上没有什么有名的帮派。\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("你现在精神不济，无法打听这些消息。\n");

                if (me->is_busy())
                        return notify_fail("你现在正忙，没有时间打听这些消息。\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        fam = sort_array(fam, (: sort_bunch :), fame);
                
        msg = sprintf(WHT "%-12s%-20s%-10s%-10s%-10s%-12s\n" NOR,
                      "帮会名称", "帮会帮主", "玩家数", "ＮＰＣ数", "地盘数", "总资产(黄金)");
        msg += HIY "—————————————————————————————————————\n" NOR;
        
        n = 0;
        foreach (bunch in fam)
        {
                id = BUNCH_D->query(bunch + "/bangzhu");
                npc = sizeof(BUNCH_D->query_npcs(bunch));
                area = sizeof(BUNCH_D->query_areas(bunch));
                player = sizeof(BUNCH_D->query_members(bunch));
                
                user = UPDATE_D->global_find_player(id);
                if (! objectp(user))
                        continue;

                n++;
                msg += sprintf(WHT "%-12s%-20s%-10s%-10s%-10s%-12s\n" NOR,
                               bunch, user->query("name") + "(" + user->query("id") + ")",
                               player + " 人", npc + " 个", area + " 处",
                               BUNCH_D->query(bunch + "/money") / 10000 + " 两");         
               
                UPDATE_D->global_destruct_player(user);
        }

        if (n < 1)
                return notify_fail("现在没有任何帮派信息。\n");

        msg += "\n目前泥潭共有" + HIM + chinese_number(n) + NOR + "个帮派。\n";
        msg += HIY "—————————————————————————————————————\n" NOR;

        write(msg);
        return 1;
}

// 显示同盟中的信息
int show_bunch_info(object me, string arg)
{
        string fam;
        object  ob;
        string  msg;
        string *member;
        string  id;
        int i;

        if (! stringp(fam = select_bunch(me, arg)))
                return 0;

        if (! arrayp(member = BUNCH_D->query_members(fam)))
        {
                write("现在江湖上没有(" + fam + ")这个帮派。\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(fam + "现在没有一个帮派玩家。\n");

        msg = WHT "\n" + fam + "的帮派玩家列表\n" NOR;
        msg += HIY "—————————————————————————————————————\n" NOR;
        member = sort_array(member, (: sort_member :));
        foreach (id in member)
        {
                msg += sprintf(WHT "%-10s  ", id);
                if (objectp(ob = find_player(id)))
                        msg += sprintf(HIY "在线   "        
                                       NOR WHT "职位：" HIM "%-10s "                                                                      
                                       NOR WHT "阅历：" HIW "%-8d "
                                       NOR WHT "威望：" HIY "%-8d "
                                       NOR WHT "等级：" HIR "%-2d\n" NOR,
                                       ob->query("bunch/title"),
                                       ob->query("score"),
                                       ob->query("weiwang"),
                                       ob->query("level"));                                       
                else
                {       ob = UPDATE_D->global_find_player(id);
                        msg += sprintf(HIR "离线   "
                                       NOR WHT "职位：" HIM "%-10s "                                                                      
                                       NOR WHT "阅历：" HIW "%-8d "
                                       NOR WHT "威望：" HIY "%-8d "
                                       NOR WHT "等级：" HIR "%-2d\n" NOR,
                                       ob->query("bunch/title"),
                                       ob->query("score"),
                                       ob->query("weiwang"),
                                       ob->query("level"));                             
                        UPDATE_D->global_destruct_player(ob);
                }
        }

        msg += HIY "\n—————————————————————————————————————\n" NOR;
        msg += WHT "\n" + fam + "的帮派帮众列表\n" NOR;
        msg += HIY "—————————————————————————————————————\n" NOR;
        
        if (arrayp(member = BUNCH_D->query_npcs(fam)))
        {
                i = 0;
                foreach (id in member)
                {
                        i++;
                        ob = get_object(id); 
                        msg += sprintf("%-24.22s%s", ob->query("name") + "(" + ob->query("id") + ")",
                                       (i%3 == 0 && i > 2  ? "\n" : ""));
                }
        } else 
                msg += "无任何帮派ＮＰＣ\n";
        
        msg += HIY "\n\n—————————————————————————————————————\n" NOR;
        msg += WHT "\n" + fam + "的帮派地盘列表\n" NOR;
        msg += HIY "—————————————————————————————————————\n" NOR;             
 
        if (arrayp(member = BUNCH_D->query_areas(fam)))
        {
                i = 0;
                foreach (id in member)
                {
                        i++;
                        ob = get_object(id); 
                        msg += sprintf("%-24.22s%s", ob->short(),
                                       (i%3 == 0 && i > 2  ? "\n" : ""));
                }
        } else        
                msg += "无任何帮派地盘\n";

        msg += HIY "\n\n—————————————————————————————————————\n" NOR;
        msg += WHT "\n" + fam + "上个月收入单表\n" NOR;
        msg += HIY "—————————————————————————————————————\n" NOR;
        i = (int)BUNCH_D->query(fam + "/last_area_money");
        if (! intp(i))   i = 0;
        msg += "地盘收入：" + MONEY_D->money_str(i) + "\n\n";
        i = (int)BUNCH_D->query(fam + "/last_npc_money");
        if (! intp(i))   i = 0;
        msg += "帮众收入：" + MONEY_D->money_str(i) + "\n\n";
        i = (int)BUNCH_D->query(fam + "/last_bangzhu_money");
        if (! intp(i))   i = 0;
        msg += "帮主所得：" + MONEY_D->money_str(i) + "\n\n";
        msg += HIY "—————————————————————————————————————\n" NOR;
                	                                            
        msg += sprintf("现在%s在江湖上具有 %s%d%s 点声望。\n%s现有 %s%s%s 的资金。\n",
                       fam, HIY, BUNCH_D->query_bunch_fame(fam), NOR,
                       fam, HIY, MONEY_D->money_str(BUNCH_D->query(fam + "/money")), NOR);
        write(msg);

        return 1;
}

int show_bunch_area(object me, string arg)
{
        string fam;
        string *member;
        string id;
        object area, npc;
        string msg;
        int n;

        if (! stringp(fam = select_bunch(me, arg)))
                return 0;

        if (! arrayp(member = BUNCH_D->query_areas(fam)))
        {
                write("现在帮派" + fam + "没有任何地盘。\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(fam + "现在没有任何地盘。\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("你现在精神不济，无法打听这些消息。\n");

                if (me->is_busy())
                        return notify_fail("你现在正忙，没有时间打听这些消息。\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        msg = sprintf(HIC "\n%-16s%-20s%-8s%-8s%-14s%-18s%-8s\n" NOR,
                      "地盘名称", "驻守ＮＰＣ", "资金度", "开发度",
                      "资产（黄金）", "上月收入（白银）", "忠诚度");
                      
        msg += HIY "—————————————————————————————————————————————\n" NOR;
                
        n = 0;
        foreach (id in member)
        {
                area = get_object(id);
                if (! objectp(area))
                        continue;
                
                // npc = get_object(area->query("bunch/npc_file"));
                
                n++;
                msg += sprintf(HIC "%-16s%-20s%-8s%-8s%-14s%-18s%-8s\n" NOR, 
                               area->short(), area->query("bunch/npc_name") + "(" + area->query("bunch/npc_id") + ")",
                               area->query("area/ziyuan") ? area->query("bunch/jizhi") + "%" : "----", 
                               area->query("area/ziyuan") ? area->query("bunch/kaifa") + "%" : "----", 
                               area->query("bunch/money") / 10000 + " 两", 
                               area->query("bunch/last_money") / 100 + " 两",
                               area->query("bunch/zhongcheng") + "%");
        }

        if (n < 1)
                return notify_fail(arg + "现在没有任何地盘。\n");

        msg += "\n目前" + HIM + fam + NOR + "共有" + HIM + chinese_number(n) + NOR + "处地盘。\n";
        msg += HIY "—————————————————————————————————————————————\n" NOR;
        // me->start_more(msg);
        write(msg);
        return 1;
}
        
// 显示某一个同盟中的人员
int dismiss_bunch(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (wiz_level(me) < wiz_level("(arch)"))
                return notify_fail("你的权限不够，不能强行解散帮派。\n");

        if (! arg)
                return notify_fail("你要解散哪个帮派？\n");

        if (! arrayp(member = BUNCH_D->query_members(arg)))
        {
                write("现在江湖上没有(" + arg + ")这个帮派。\n");
                return 1;
        }

        write("你强行解散了" + arg + "。\n");
        BUNCH_D->dismiss_league(arg);
        return 1;
}

int expell_bunch_member(object me, string arg)
{
        string fname;
        object ob;
        
        if (! stringp(fname = me->query("bunch/bunch_name")))
        {
                write("你现在还没有加入任何帮派呢。\n");
                return 1;
        }
        
        if (me->query("bunch/level") != 9)
        {
                write("只有帮主才有权利开除某人出帮会！\n");
                return 1;
        }
        
        if (arg == me->query("id"))
        {
                write("开除自己？你还不如解散你的帮派！\n");
                return 1;
        }
           
        if (! objectp(ob = find_player(arg)))
        {
                ob = UPDATE_D->global_find_player(arg);

                if (! objectp(ob))
                { 
                        write("没有这个玩家。\n");
                        return 1;
                } 
        
                if (ob->query("bunch/bunch_name") != fname)
                {
                        UPDATE_D->global_destruct_player(ob);                                                      
                        write("他不是你的帮派中人，你无权开除他！\n");    
                        return 1;                   
                        
                }
                UPDATE_D->global_destruct_player(ob);
                
        }
        
        BUNCH_D->add_bunch_fame(fname, -BUNCH_D->query_bunch_fame(fname) / 20);
       
        if (objectp(ob))
                CHANNEL_D->do_channel(this_object(), "rumor",
                        "听说" + ob->query("name") + "(" + arg + ")" +
                        "被帮派『" + fname + "』给开除了。");

        UPDATE_D->clear_user_data(arg, "bunch");
        
        return 1;
}

// 给所有的仇恨对象排序
int sort_hatred(string id1, string id2, mapping hatred)
{
        mixed *d1, *d2;

        if (! arrayp(d1 = hatred[id1]) || sizeof(d1) < 2 || ! intp(d1[1]))
                return 1;

        if (! arrayp(d2 = hatred[id2]) || sizeof(d2) < 2 || ! intp(d2[1]))
                return -1;

        return d2[1] - d1[1];
}

// 给同盟中的所有结义成员排序
int sort_member(string id1, string id2)
{
        object ob1, ob2;

        ob1 = find_player(id1);
        ob2 = find_player(id2);
        if (! objectp(ob1) && ! objectp(ob2))
                return strcmp(id2, id1);

        if (objectp(ob1) && objectp(ob2))
                return ob2->query("combat_exp") - ob1->query("combat_exp");

        if (objectp(ob1))
                return -1;

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: bunch info [玩家] | hatred [玩家] | member [帮派名字] | top | area

查看目前你所在帮派的各种信息，其中：

info   ：查看帮派中的人物，成员状态，声望。
hatred ：查看帮派的仇恨对象。
member ：查看某个帮派的成员。
top    ：查看帮派的声望排名。
area   : 查看帮派的地盘信息。
all    : 查看所有的帮派信息。

巫师可以查看各个帮派的信息，只需要在命令后面加上帮派的名字或
是帮派中的玩家。另外巫师可以使用 bunch dismiss  命令强行解散
一个帮派。

see also: league (团体同盟)
HELP );
        return 1;
}

