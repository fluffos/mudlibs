// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string bunch, someone;
        int amount;
        int money;
        object ob;
        object area;
        
        if (! arg) return notify_fail("请使用help tisheng，查看此命令。\n");

        if (! stringp(bunch = me->query("bunch/bunch_name")))
                return notify_fail("你没有参加任何帮会，无法提升任何ＮＰＣ。\n");
                        
        if (sscanf(arg, "%d %s", amount, someone) != 2)
                return notify_fail("请使用help tisheng，查看此命令。\n");                

        if (amount < 0 || amount > 10)
                return notify_fail("每次提升的值不能小于零也不能大于十点。\n");
                                
        if (! ob = present(someone, environment(me)))
                return notify_fail("这儿没有这么个人。\n");
                                
        if (! ob->is_character())
                return notify_fail("看清楚，它不是生物。\n");
                
        if (playerp(ob))
                return notify_fail("你只能提升本帮ＮＰＣ帮众的技能。\n");
                
        if (! living(ob))
                return notify_fail("你得先把" + ob->query("name") + "弄醒再说。\n");
             
        if (me->is_fighting() || me->is_busy())
                return notify_fail("你正忙着呢。\n");
                
        if (ob->is_fighting() || ob->is_busy())
                return notify_fail(ob->query("name") + "正忙着呢。\n");

        if (bunch != (string)ob->query("bunch/bunch_name"))
                return notify_fail("你只能提升本帮会内的ＮＰＣ帮众。\n");
                
        if (! ob->is_bunch_npc())
                return notify_fail(ob->query("name") + "似乎现在不接受你的提升命令。\n");
                
        area = environment(ob);

        if (! area->is_area_room() || 
            area->query("bunch/bunch_name") != bunch ||
            area->query("bunch/npc_file") != base_name(ob))                                                           
                return notify_fail(ob->query("name") + "似乎现在不接受你的提升命令。\n");

        if ((int)area->query("bunch/zhongcheng") >= (int)ob->query("bunch/max_zhongcheng"))
                return notify_fail(ob->query("name") + "的忠诚度已经达到最大，不需要进行提升了。\n");

        money = amount * 10000;
                
        if ((int)me->query("balance") < money)     
                return notify_fail("你帐上的钱不够，" + ob->query("name") +
                                   "的忠诚度每提升一点需要一两黄金！\n");
                                
        me->add("balance", -money);
        me->save();
                
        if ((int)area->query("bunch/zhongcheng") + amount >= (int)ob->query("bunch/max_zhongcheng"))
        {
                area->set("bunch/zhongcheng", (int)ob->query("bunch/max_zhongcheng"));
                ob->set("bunch/zhongcheng", (int)ob->query("bunch/max_zhongcheng"));
        } else    
        {
                area->add("bunch/zhongcheng", amount);
                ob->add("bunch/zhongcheng", amount);
        }
                
        area->save();
        me->start_busy(1);
        write("你花了 " + money / 10000 + " 两黄金，将" + ob->query("name") + "的忠诚度提升了" + amount + "点！\n");

        return 1;
}


int help(object me)
{
        write(@HELP

指令格式：tisheng <amount> <id>

这条指令可用来提升所属帮会中NPC的忠诚度(zhongcheng)。当你征招了某个
NPC后，为了提高它的战斗力及忠诚度，需要经常花钱对其进行提升。
HELP
        );
        return 1;
}



