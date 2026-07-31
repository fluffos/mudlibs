// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string fam;
        string *member;
        string id;
        object area, npc;
        string msg;
        int n, kaifa, money;
                
        if (me->is_busy()) return notify_fail("你正忙着呢！\n");

        if (! stringp(fam = me->query("bunch/bunch_name")))
                return notify_fail("你没有加入任何帮会，无法开发帮会所属地盘。\n");
                
        if (! arrayp(member = BUNCH_D->query_areas(fam)))
        {
                write("现在帮派" + fam + "没有任何地盘。\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(fam + "现在没有任何地盘。\n");

        if (! arg)
        {
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
                                
                        if (! area->query("area/ziyuan"))
                                continue;
                
                        // npc = get_object(area->query("bunch/npc_file"));
                
                        n++;
                        msg += sprintf(HIC "%-16s%-20s%-8s%-8s%-14s%-18s%-8s\n" NOR, 
                               area->short(), area->query("bunch/npc_name") + "(" + area->query("bunch/npc_id") + ")",
                               area->query("bunch/jizhi") + "%", area->query("bunch/kaifa") + "%",
                               area->query("bunch/money") / 10000 + " 两", 
                               area->query("bunch/last_money") / 100 + " 两",
                               area->query("bunch/zhongcheng") + "%");
                }

                if (n < 1)
                        return notify_fail(arg + "现在没有任何地盘。\n");

                msg += "\n目前" + HIM + fam + NOR + "共有" + HIM + chinese_number(n) + NOR + "处地盘。\n";
                msg += HIY "—————————————————————————————————————————————\n" NOR;
        
                write(msg);
        me->start_busy(2);
                return 1;
        }
        
        area = environment(me);
        
        if (arg != area->short())
                return notify_fail("你必须到实地才能进行开发！\n"); 
                
        if (! area->is_area_room() || ! area->query("area/ziyuan")) 
                return notify_fail("这里不属于帮派可开发地盘！\n"); 
                         
        if (area->query("bunch/bunch_name") != fam) 
                return notify_fail("这里不属于你的帮派地盘，你费什么劲啊！\n"); 

        if (area->query("bunch/npc_id")) 
                npc = present(area->query("bunch/npc_id"), environment(me)); 
                
        if (! objectp(npc) || (string)npc->query("bunch/area_file") != base_name(environment(npc))) 
                return notify_fail("负责" + arg + "开发的ＮＰＣ并未就位，无法进行开发！\n"); 

        kaifa = area->query("bunch/kaifa");
        money = kaifa * 10000;
        
        if ((int)me->query("balance") < money)     
        {
                return notify_fail("你帐上的钱不够，开发" + arg + "至少要" +
                                   MONEY_D->money_str(money) + "！\n");
        }
        
        me->add("balance", -money);
        me->save();
        
        if (kaifa < 100) area->set("bunch/kaifa", kaifa + 1);
        else return notify_fail(arg + "的开发度已达到最大，不需再开发。\n");
     
        area->save();
        me->start_busy(2);
        write("你花费了" + MONEY_D->money_str(money) + "开发" + arg + "，" + arg + "的开发度上升了一点！\n");
        return 1;
}
        
int help(object me)
{
        write(@HELP

指令格式：kaifa [地盘名称]

用于开发帮会中地盘，增加帮会收入。

HELP
        );
        return 1;
}


