// lcm : experimental
// m_trade.c
// start 28/9/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// a simple trade involve 2 parties
// we use simply buyer, seller
// buyer initiate, seller response
// go thru negotiate rounds

// initiate trade, buyer,seller
object mbuyer;
object mseller;
int    mstatus = TRADE_NO;

int canTrade();
mixed nextResponse(mixed suggest);
void commit();
void abort();

// methods to call
int initiate(object buyer, object seller);
int trade();

int initiate(object buyer, object seller)
{
    mstatus = TRADE_NO;
    if (!objectp(buyer) || !objectp(seller))
        return 0;
    mbuyer = buyer;
    mseller = seller;
    if (canTrade())
    {
        mstatus = TRADE_START;
        return 1;
    }
    return 0;
}

// ask buyer what he wants
// buyer will have a method requestGood, seller- hasGood
int canTrade()
{
    mixed good;
//    good = mbuyer->requestGood(mseller);
    good = (M_BUYER)->requestGood(mseller);
    write("trade"+good);
    if (!good)
        return 0;
//    return mseller->hasGood(good, mbuyer);
    return (M_SELLER)->hasGood(good, mbuyer);
}

// ask seller what he wants in return
// seller will have exchange
int trade()
{
    mixed reply;
    mixed suggest;
    if (mstatus != TRADE_START)
        return mstatus;
    suggest = mseller->exchange();
    mstatus = TRADE_BUYERTURN;
    while ((mstatus != TRADE_COMPLETE) && (mstatus != TRADE_ABORT))
    {
        reply = nextResponse(suggest);
        suggest = reply;
    }
    return mstatus;
}

// both parties then engage in response
mixed nextResponse(mixed suggest)
{
    mixed reply;
    int status;
    if (mstatus == TRADE_BUYERTURN)
    {
        reply = mbuyer->response(suggest);
        status = TRADE_SELLERTURN;
    }
    else if (mstatus == TRADE_SELLERTURN)
    {
        reply = mseller->response(suggest);
        status = TRADE_BUYERTURN;
    }
    else
        return mstatus; // ?

    if (stringp(reply))
    {
        if (reply == "accept")
        {
            commit();
            mstatus = TRADE_COMPLETE;
        }
        else if (reply == "abort")
        {
            abort();
            mstatus = TRADE_ABORT;
        }
        else
            mstatus = status;
    }
    else
        mstatus = status;

    return reply;
}

// commit transaction
// both parties shd exchange
void commit()
{
    mbuyer->deal(mseller);
    mseller->deal(mbuyer);
}

// inform the other party trade aborted
void abort()
{
    if (mstatus == TRADE_BUYERTURN)
        mseller->aborted(mbuyer);
    else
        mbuyer->aborted(mseller);
}
