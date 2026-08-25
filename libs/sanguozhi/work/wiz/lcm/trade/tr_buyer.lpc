// lcm : experimental
// tr_buyer.c
// start 20/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// what to inherit?


int isUser(object obj)
{
    return 1;
}

// check?
void wantGood(object seller, object buyer, string good)
{
    string buyerid;
    string sellerid;
    int tid;
    string dbg;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    dbg = buyerid + "," + sellerid;
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    printf(dbg + " : " + tid + "\n");
    if (tid == -1)
    {
      seller->targetted_action
      ("$N对$T迷惑的说道：你有跟我做生意吗？\n", buyer);
      return;
    }
    seller->clear_answer();
    (DATA_TRADE)->setTrade(tid, "good", good);
    (TR_SELLER)->hasGood(tid);
}

void requestGood(int tid)
{
    object buyer;
    object seller;
    string buyerid;
    string sellerid;
    buyer = (DATA_TRADE)->getTrade(tid, "buyer");
    seller = (DATA_TRADE)->getTrade(tid, "seller");
    if (!objectp(buyer) || !objectp(seller))
        return;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    seller->targetted_action
      ("$N对$T笑着说道：你想交换什么？
想好了就请输入 answer <物品> to "+sellerid+"\n", buyer);
    seller->set_answer(buyerid, (:wantGood:) );
}

void negotiate(object seller, object buyer, string good)
{
    string buyerid;
    string sellerid;
    int tid;
    string dbg;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      seller->targetted_action
      ("$N对$T迷惑的说道：你有跟我做生意吗？\n", buyer);
      return;
    }
    seller->clear_answer();
    (DATA_TRADE)->setTrade(tid, "buynegotiate", good);
    (GEN_TRADE)->replyResponse(tid, good);
}

void response(int tid)
{
    object buyer;
    object seller;
    string buyerid;
    string sellerid;
    string egood;
    buyer = (DATA_TRADE)->getTrade(tid, "buyer");
    seller = (DATA_TRADE)->getTrade(tid, "seller");
    if (!objectp(buyer) || !objectp(seller))
        return;
    egood = (DATA_TRADE)->getTrade(tid, "exchange");
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    seller->targetted_action
      ("$N对$T笑着说道：用"+egood+"来交换，可以吗？\n
可以就请输入 answer accept to "+sellerid+"\n
想要终止交易的话请输入 answer abort to "+sellerid+"\n
不然你可以输入你可以交换的物品\n
想好了就请输入 answer <物品> to "+sellerid+"\n", buyer);
    seller->set_answer(buyerid, (:negotiate:) );
}
