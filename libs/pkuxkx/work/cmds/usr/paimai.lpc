//cmds/usr/auction.c 
// auction.c 
//jason

#include <ansi.h> 
#ifndef BID_D 
#define BID_D       "/adm/daemons/bidd" 
#endif 

#define DEBUG 1

inherit F_CLEAN_UP; 
int help(object me); 
int to_money(string str); 
int main(object me, string arg) 
{ 
        object ob; 
        string name=""; 
        int str;
        int money; 
        if (! arg) return help(me); 
        if (arg == "cancel") 
        { 
                BID_D->cancel_auction(me); 
                return 1; 
        } 
        if (arg == "check") 
        { 
                if (stringp(str = BID_D->check_auction_info())) 
                { 
                        write(str); 
                        return 1; 
                } 
                return notify_fail("目前没有任何东西正在拍卖。\n"); 
        } 
        if (sscanf(arg, "%s for %d", name, str) == 2) 
        { 
                if(!environment(me)->query("auction_room"))
                        return notify_fail("请到拍卖室进行拍卖。\n");
#ifndef DEBUG
                if(wiz_hood(me)!="(player)")
                {
                        return notify_fail("巫师不可以参与拍卖。\n");
                }
#endif
                if (! objectp(ob = present(name, me))) 
                        return notify_fail("你身上没有这个东西。\n"); 
                if (! intp(money = str) || ! money || money <= 0) 
                        return notify_fail("输入价格错误。\n"); 
                  if(money < 1) 
                        return notify_fail("对不起，我们不接受如此低额的拍卖交易。\n");
                BID_D->add_auction(me, ob, money); 
                return 1; 
        } 
        if (sscanf(arg, "%d to %s", str, name) == 2) 
        { 
                if (! intp(money = str) || ! money) 
                        return notify_fail("输入价格错误。\n"); 
                if(me->query("balance") < 100 * money )
                    return notify_fail("你的户头上没有那么多钱。\n");                 
                BID_D->join_auction(me, name, money); 
                return 1; 
        } 
        return help(me); 
} 

int help(object me) 
{ 
        write(@HELP 
指令格式 : paimai <物品> for <价格(两白银)> 
拍卖出一件物品，最低金额为1两白银。这必须在荣昌拍卖行才行。
           
==== 以下任何时候都可以进行 ====
paimai <价格(两白银)> to <玩家> 
参与叫价，每次叫价加额不得少于10%
           
paimai check 
察看目前所有正在拍卖的物品。 
           
paimai cancel 
取消自己物品的拍卖。 
====

当有人出价之后，120s内如果没有其他人出价更高，则该物品归他所有。如果两个小时内无人问津，交易取消。
交易成功后，拍卖者需要支付一定佣金。竞价成功者要去荣昌拍卖行用qu命令取自己的物品。交易如果取消，
也用qu命令取回商品。卖家如果中途quit，则该物品归拍卖行所有；买家如果中途quit，则竞价钱款归拍卖行
所有。

HELP 
); 
    return 1; 

} 


