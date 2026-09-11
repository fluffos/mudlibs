// lcm : experimental
// tradegen.c
// start 20/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// refer m_trade.c
void end(int tid);
void commit(int tid);
void abort(int tid);

void toTrade(int tid)
{
    (TR_BUYER)->requestGood(tid);
}

int initiate(object buyer, object seller)
{
    int tid;
    string buyerid;
    string sellerid;
    if (!objectp(buyer) || !objectp(seller))
        return 0;
    tid = (DATA_TRADE)->addTrade(TRADECL_GENERIC);
    (DATA_TRADE)->setTrade(tid, "buyer", buyer);
    (DATA_TRADE)->setTrade(tid, "seller", seller);
//        (DATA_TRADE)->setTrade(tid, "status", TRADE_START);
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    if ((DATA_TRADE)->mapTrade(buyerid + "," + sellerid, tid) == 0)
    {
      (DATA_TRADE)->removeTrade(tid);
      return 0;
    }
    toTrade(tid);
    return 1;
}

void nextResponse(int tid)
{
    int status;
    status = (DATA_TRADE)->getTrade(tid, "status");
    if (status == TRADE_BUYERTURN)
    {
        (DATA_TRADE)->setTrade(tid, "status", TRADE_SELLERTURN);
        (TR_SELLER)->response(tid);
    }
    else if (status == TRADE_SELLERTURN)
    {
        (DATA_TRADE)->setTrade(tid, "status", TRADE_BUYERTURN);
        (TR_BUYER)->response(tid);
    }
}

void replyResponse(int tid, string reply)
{
    if (reply == "accept")
        commit(tid);
    else if (reply == "abort")
        abort(tid);
    else
        nextResponse(tid);
}

// buyer will response first
void start(int tid)
{
    if ((DATA_TRADE)->getTrade(tid, "status") != TRADE_START)
        return;
    (DATA_TRADE)->setTrade(tid, "status", TRADE_SELLERTURN);
    nextResponse(tid);
}

void end(int tid)
{
  printf("trade ends.\n");
  (DATA_TRADE)->removeTrade(tid);
}

void commit(int tid)
{
  (DATA_TRADE)->setTrade(tid, "status", TRADE_COMPLETE);
  printf("trade commits.\n");
  end(tid);
}

void abort(int tid)
{
  (DATA_TRADE)->setTrade(tid, "status", TRADE_ABORT);
  printf("trade aborts.\n");
  end(tid);
}
