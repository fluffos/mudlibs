// lcm : experimental
// m_seller.c
// start 03/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// what to inherit?

string mGoodToSell;
int mCanSell;

int isUser(object obj)
{
    return 1;
}

// check?
void canSellGood(object buyer, object seller, string reply)
{
    if ((reply == "y") || (reply == "yes"))
        mCanSell = 1;
    else
        mCanSell = 0;
}

int hasGood(mixed good, object buyer)
{
    string sellerid;
    string buyerid;
    if (!(stringp(good)))
        return 0;
    if (!(isUser(this_object())))
        return 0;
    mGoodToSell = good;
    sellerid = (this_object()->query_id())[0];
    buyerid = (buyer->query_id())[0];
    buyer->targetted_action
      ("$N对$T说道：你可否卖"+mGoodToSell+"给我？
可以卖就请输入 answer <y|yes> to "+buyerid+"\n", this_object());
    buyer->set_answer(sellerid, (:canSellGood:) );
    return mCanSell;
}
