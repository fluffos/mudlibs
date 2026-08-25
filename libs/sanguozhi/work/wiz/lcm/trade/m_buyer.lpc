// lcm : experimental
// m_buyer.c
// start 03/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// what to inherit?

string mBuyGood;

int isUser(object obj)
{
    return 1;
}

// check?
void wantGood(object seller, object buyer, string good)
{
    mBuyGood = good;
    write(mBuyGood+" is required\n");
}

mixed requestGood(object seller)
{
    string buyerid;
    string sellerid;
    if (!(isUser(this_object())))
        return 0;
    write("before buyer\n");
//    buyerid = (this_object()->query_id())[0];
    buyerid = (this_body()->query_id())[0];
    write(buyerid+"before seller\n");
    sellerid = (seller->query_id())[0];
    seller->targetted_action
      ("$N对$T笑着说道：你想交换什么？
想好了就请输入 answer <物品> to "+sellerid+"\n", this_body());
    seller->set_answer(buyerid, (:wantGood:) );
    return mBuyGood;
}
