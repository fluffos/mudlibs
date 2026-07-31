// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *bh = ({}), *ulist;
        string banghui;
        int k, count, piece, rest_money, reward_money, reward; 
         
        if (! stringp(banghui = me->query("bunch/bunch_name"))
        ||  me->query("bunch/level") < 9)
                return notify_fail("你无权在帮会内进行发饷。\n");

        if (! arg || ! sscanf(arg, "%d", rest_money) || rest_money < 1 
            || rest_money > 10000)
                return notify_fail("你准备用多少钱(gold)来进行此次发饷？\n");

        rest_money = rest_money * 10000;

        if (BUNCH_D->query(banghui + "/money") < rest_money + 100000000)
                return notify_fail("帮中现在没有这么多钱可供调用。\n");
        
        BUNCH_D->add(banghui + "/money", -rest_money);  
        BUNCH_D->save();
        
        ulist = users();
        
        for (k = 0, piece = 0, count = 0; k < sizeof(ulist); k++)
        {
                if (! environment(ulist[k]) || ! ulist[k]->query("bunch/bunch_name")
                || ulist[k]->query("bunch/bunch_name") != banghui)
                        continue;
                bh += ({ulist[k]});
                count++;
                piece += 1 + ulist[k]->query("bunch/level");
        }

        if( count )
        { 
                rest_money = rest_money / piece; 
                for (k = 0; k < count; k++)
                {
                        reward_money = rest_money * (bh[k]->query("bunch/level") + 1);
                        tell_object(bh[k], "帮派「" + banghui
                                    +"」" + "发饷，你的帐上增加了"
                                    + MONEY_D->money_str(reward_money) + "！\n");

                        if (bh[k]->query("bunch/quest") >= 4)
                        {
                                reward = reward_money / 10000;
                                reward = reward * (random(4) + 1);
                                bh[k]->add("combat_exp", reward);
                                bh[k]->add("potential", reward / 3);
                                bh[k]->add("score", reward / 50);
                                tell_object(bh[k], HIG"由于你积极为帮会振兴"
                                            + "做贡献，「" + banghui + "」" + "奖励你\n"
                                            + chinese_number(reward) + "点经验、"
                                            + chinese_number(reward / 3) + "点潜能和"
                                            + chinese_number(reward / 50) + "点综合评价！\n"NOR);
                                bh[k]->set("bunch/quest", 0);
                        }    
                        reward_money = bh[k]->query("balance") + reward_money;
                        
                        if (reward_money > 2000000000 || reward_money < 0)
                        {
                                bh[k]->set("balance", 2000000000);
                        } else
                                bh[k]->set("balance", reward_money);
                }
        }
        
        for (k = 0; k < sizeof(ulist); k++)    
        {
                if ((int)ulist[k]->query("balance") > 2000000000)  
                {
                        ulist[k]->set("balance", 2000000000);
                        tell_object(ulist[k], RED "你在钱庄的钱已达到二十万两黄金，快点花吧！\n" NOR);
                }
        }

        return 1;
}

int help(object me)
{
        write(@HELP

指令格式：faxiang [黄金数量] 

用于在本帮内发饷，所有在线帮会成员将获得一定的帮会收入。

HELP
        );
        return 1;
}                   

