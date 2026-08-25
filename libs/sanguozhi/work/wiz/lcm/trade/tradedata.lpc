// lcm : experimental
// tradedata.c
// start 20/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// like tasks .. less object, more data?
private mapping trades=([]);
private mapping rtvtid=([]);
// some way to identify a trade - string to id
void unmapTrade(int id);

int addTrade(int type)
{
  int *list;
  int id = 0;
  list = keys(trades);
  while (member_array(id, list) != -1)
    id++;
  trades[id]=([]);
  trades[id]["type"] = type;
  trades[id]["status"] = TRADE_NO;
  return id;
}

void removeTrade(int id)
{
  if (!trades[id])
    return;
  unmapTrade(id);
  map_delete(trades, id);
}

mixed getTrade(int id, string name)
{
  if (!trades[id])
    return 0;
  if (!trades[id][name])
    return 0;
  return trades[id][name];
}

int setTrade(int id, string name, mixed val)
{
  if (!trades[id])
    return 0;
  trades[id][name] = val;
  return 1;
}

int getTradeId(string tr)
{
  if (!rtvtid[tr])
    return -1;
  return rtvtid[tr];
}

void unmapTrade(int id)
{
  string * list;
  int size, i;
  list = keys(rtvtid);
  size = sizeof(list);
  for (i = 0; i < size; i++)
    if (rtvtid[list[i]] == id)
    {
      map_delete(rtvtid, list[i]);
      return;
    }
}

int mapTrade(string tr, int id)
{
  string * list;
  int size, i;
  if (!trades[id])
    return 0;
  if (getTradeId(tr) != -1)
    return 0;
  list = keys(rtvtid);
  size = sizeof(list);
  for (i = 0; i < size; i++)
    if (rtvtid[list[i]] == id)
      return 0;
  printf("map " + tr + " to " + id + "\n");
  rtvtid[tr] = id;
  return 1;
}
