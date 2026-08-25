// lcm : experimental
// tr_seller.c
// start 20/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// what to inherit?


int isUser(object obj)
{
    return 1;
}

void exchangeGood(object buyer, object seller, string reply)
{
    string buyerid;
    string sellerid;
    int tid;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      buyer->targetted_action
      ("$N对$T迷惑的说道：你有跟我做生意吗？\n", seller);
      return;
    }
    buyer->clear_answer();
    (DATA_TRADE)->setTrade(tid, "exchange", reply);
    (GEN_TRADE)->start(tid);
}

// check?
void canSellGood(object buyer, object seller, string reply)
{
    string buyerid;
    string sellerid;
    int tid;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      buyer->targetted_action
      ("$N对$T迷惑的说道：你有跟我做生意吗？\n", seller);
      return;
    }
    buyer->clear_answer();
    if ((reply == "y") || (reply == "yes"))
    {
        (DATA_TRADE)->setTrade(tid, "status", TRADE_START);
        buyer->targetted_action
      ("$N对$T笑着说道：你要我用什么来交换？\n", seller);
        buyer->set_answer(sellerid, (:exchangeGood:) );
    }
    else
    {
      seller->targetted_action
      ("$N对$T说道：对不起，我没有你所想要的东西。\n", buyer);
      (DATA_TRADE)->removeTrade(tid);
    }
}

void hasGood(int tid)
{
    object buyer;
    object seller;
    string sellerid;
    string buyerid;
    string good;
    buyer = (DATA_TRADE)->getTrade(tid, "buyer");
    seller = (DATA_TRADE)->getTrade(tid, "seller");
    good = (DATA_TRADE)->getTrade(tid, "good");
    if (!objectp(buyer) || !objectp(seller))
        return;
    if (!(stringp(good)))
        return;
    sellerid = (seller->query_id())[0];
    buyerid = (buyer->query_id())[0];
    buyer->targetted_action
      ("$N对$T说道：你可否卖"+good+"给我？
可以卖就请输入 answer <y|yes> to "+buyerid+"\n", seller);
    buyer->set_answer(sellerid, (:canSellGood:) );
}

void negotiate(object buyer, object seller, string good)
{
    string buyerid;
    string sellerid;
    int tid;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      buyer->targetted_action
      ("$N对$T迷惑的说道：你有跟我做生意吗？\n", seller);
      return;
    }
    buyer->clear_answer();
    (DATA_TRADE)->setTrade(tid, "exchange", good);
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
    egood = (DATA_TRADE)->getTrade(tid, "buynegotiate");
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    buyer->targetted_action
      ("$N对$T笑着说道：用"+egood+"来交换，可以吗？\n
可以就请输入 answer accept to "+buyerid+"\n
想要终止交易的话请输入 answer abort to "+buyerid+"\n
不然你可以输入你可以交换的物品\n
想好了就请输入 answer <物品> to "+buyerid+"\n", seller);
    buyer->set_answer(sellerid, (:negotiate:) );
}
