/*
** /std/shop/trading.c
*/

#include <money.h>		// MONEY_DEMON, MONEY_LIB and such
#include <moving.h>
#include <properties.h>
#include <stdrooms.h>
#include <search.h>

inherit MONEY_LIB;	// money-functions

#define MIN_BUY_FACTOR   250

// shops with endless money
// remove the SHOP from the array - this define is obsolete! - Magictcs
//#define SSHOPS ({SHUTSHOP, SHOP})
#define SSHOPS ({SHUTSHOP})

#define TS_NOMONEY -1  // TestSell - Return-Values
#define TS_NOBUY   -2
#define TS_NOTRADE -3
#define TS_NOMOVE  -4
#define CALC_FEE(x) (x/3)||1

// general defines
#define ME this_object()
#define TP this_player()
#define INSURANCE(x) (x*4/5)
#define P_PRICE "shopprice" // the price a player wants for an item
#define P_OWNER "shopowner" // the player who sold this item
// P_PRICE and P_OWNER are just used for markets
#define P_LASTLIST "shoplist"
#define STR	"/lib/string"	// for formatting of strings
#define NMB     "/lib/number"
#define SF(x)  #'x //'
#define CL_PROGN #', //'
#define P_SELL_MUTEX (to_string(this_object())+":is selling")
#define D(x,y) "/players/thragor/lib/debug"->debug("thragor",x,y)

public mapping Powner_list;
// ([<uid of owner of items in the market>:<amount to pay to bank>])

private nosave int Pcash;
private nosave int Pbuy_factor, Pdynamic, Pmin_cash;
private nosave object *Pcurrentobjects;

/*
** Prototypes
** ==========
**
** /std/shop.c
*/

public status CheckTrade(object ob);
public int ModifyPrice(object ob, int price, string verb);
public varargs int GetCutPrice(object ob);
protected status CheckLivingTrade(object ob);
public int QueryNoShopkeeper();
public string QueryBuy();
public string QueryList();
public string QueryAppraise();
public string QueryIdentify();
public string QuerySell();
public string QueryMarket();
protected void list_done(string str);

/*
** /std/shop/comm.c
*/

public object QueryShopkeeper();
public varargs string CustomerName(int cap);
public varargs string SkShort(int cap);
public int SkSay(string str);
public int SkEmote(mixed str);
public varargs void Write(mixed str,status ignlight);
public varargs void Say(mixed str,object *exclude,status ignlight);

/*
** /std/shop/articles.c
*/

public object GetStore();
public int PutInStore(object ob);

/*
** Prototypes End
** ==============
*/

public varargs string *QueryFValuta(int force)
{
  if (!force)
    return (QueryValuta());
  else
    return m_indices(({mapping})MONEY_DEMON->QueryCoinTypes()||([]));
}

protected string ValueString(int x)
{
  return ({string})MONEY_DEMON->QueryValueString(x,QueryValuta());
}

protected string get_min_coin()
// Eval-time: 0
// Return the minimal coin (as string) to be used e. g. in the 'list'.
{
  object mdemon;
  int *vals,minval,i;
  string *mincoins;
  mdemon = load_object(MONEY_DEMON);
  vals = map(QueryValuta()||({}),
                   symbol_function("QueryCoinValue",mdemon));
  minval = ({int})NMB->min(vals);
  mincoins = ({});
  for (i=0;i<sizeof(vals);i++)
    if (vals[i]==minval)
      mincoins+=({QueryValuta()[i]});
  if (member(mincoins,"copper")!=-1
      ||!sizeof(mincoins))
    return "copper";
  return mincoins[0];
}

protected int convert_value(int copper)
// Convert the value (in copper) of an object to a value with the
// minimal coin (i. e. lowest value).
{
  int c,new;
  c = ({int})MONEY_DEMON->QueryCoinValue("copper");
  if (!new = ({int})MONEY_DEMON->QueryCoinValue(get_min_coin()))
    return 0;
  return ((copper*c)/new+(copper*c%new!=0))||1;
}

protected int round_value(int copper)
// Return the value in copper coins, rounded so that it fits into
// the minimal coin.
{
  int c,new;
  c = ({int})MONEY_DEMON->QueryCoinValue("copper");
  if (!new = ({int})MONEY_DEMON->QueryCoinValue(get_min_coin()))
    return 0;
  return ((copper*c)/new+(copper*c%new!=0))*new;
}

protected int modify_on_amount(object ob,int price)
// If we already have too much of these items, we'll buy them for much
// less money only.
{
  int i;
  if (!i = sizeof(({object *})GetStore()->GetEqual(ob)))
    return price;
  if (i>6) i = 6;	// put a limit to the decrease of value
  if (!price = price/(((i*i)/4)+1))
    price = 1;
  return price;
}

public varargs int GetPrice(object ob,int price,status force)
// Returns the price for an object depending on the command. Modifications are
// done in here (e. g. ModifyPrice is called).
{
  string verb;

  if (!ob) return 0;

  verb = query_verb();

  if ( ({int})ob->QueryLastAmount() )
    price = price||({int})ob->QueryValuePerUnit()*({int})ob->QueryLastAmount();
  else
    price = price||({int})ob->QueryValue();

  if (  verb==(QuerySell()||"sell")
      ||verb==(QueryAppraise()||"appraise")
      ||force)
    verb = "sell";
  else if (  verb==(QueryBuy()||"buy")
           ||verb==(QueryList()||"list"))
    verb = "buy";
  else
    verb = "none";

  if (!QueryMarket()||force)
    {
      price = ModifyPrice(ob, price, verb);
      if (verb=="sell")	// only modify if the customer sells this item
        price = modify_on_amount(ob,price);
      // modify the price refering to the stack
      // of this item in the store
      if (verb == "buy") price = (price * Pbuy_factor) / 100;
    }
  else
    if (verb=="buy")
      price = ({int})ob->Query(P_PRICE);
  if (price <= 0)
    price = 1;	// security
  else
    price = round_value(price)||1;
  return price;
}

public mapping SetOwnerList(mapping o)
{
  Powner_list = o;
  save_object(QueryMarket());
  return Powner_list;
}

public mapping QueryOwnerList()
{
  if (file_size(QueryMarket()+".o")>0)
    restore_object(QueryMarket());
  return Powner_list;
}

public mapping AddInsurance(object ob)
{
  string owner;
  if (!Powner_list)
    Powner_list = ([]);
  owner = ({string})ob->Query(P_OWNER);
  Powner_list[owner] = Powner_list[owner]+INSURANCE(GetPrice(ob,0,1));
  if (Powner_list[owner]<1)
    m_delete(Powner_list,owner);
  save_object(QueryMarket());
  return Powner_list;
}

public mapping RemoveInsurance(object ob)
{
  string owner;

  if (!owner = ({string})ob->Query(P_OWNER))
    return Powner_list;
  BANK_D->AddAccount(owner,({int})ob->Query(P_PRICE));
  if (!Powner_list)
    Powner_list = ([]);
  Powner_list[owner] = Powner_list[owner]-INSURANCE(GetPrice(ob,0,1));
  if (Powner_list[owner]<1)
    m_delete(Powner_list,owner);
  save_object(QueryMarket());
  return Powner_list;
}

public void PayInsurances()
{
  mapping list;
  string *owner;
  int i;
  if (list = QueryOwnerList())
    {
      for (i = sizeof(owner = m_indices(list));--i>-1;)
        BANK_D->AddAccount(owner[i],list[owner[i]]);
      rm(QueryMarket()+".o");
    }
}

/*
** SELLING ITEMS
** ============
*/

protected int TestSell(object ob,int price)
// Returns either:
// TS_NOMONEY: The shopkeeper ran out of money
// TS_NOBUY:   The shopkeeper won't buy such items
// TS_NOTRADE: The shopkeeper doesn't trade with this items
// or the calculated value, the player will get for this item
{
  int hi,
      float_price;	// the price of ob after modifications depending on
			// the verb and ModifyPrice

  if (Pcash < 1 && member(SSHOPS, object_name(ME)) < 0)
    return TS_NOMONEY;

  if (({int})ob->Query(P_NOBUY))
    return TS_NOBUY;

  if (!CheckTrade(ob) || !CheckLivingTrade(ob))
    return TS_NOTRADE;

  if (({int})ob->QueryNoDrop()||({int})ob->QueryNoGive())
    return TS_NOMOVE;

  if (({mixed})ob->QueryAutoObject())
    return TS_NOBUY;

  float_price = GetPrice(ob,price);	// calculate the price the customer
					// would get
  if (float_price < 1
      ||(  !QueryMarket()
         &&({int})ob->QueryValue()<({int})MONEY_DEMON->QueryCoinValue(get_min_coin())))
                // don't buy worthless things
    return 0;
  if (hi = ({int})ob->QueryLastAmount()) float_price/=hi;
  if (   !QueryMarket()
      && float_price > (hi = GetCutPrice(ob))
     )
    float_price = hi;
  if (hi = ({int})ob->QueryLastAmount()) float_price*=hi;
  return float_price;
}

private string check_sell_notify (int res, object ob, string cname)
{
  switch(res) {
  case TS_NOMONEY:
    SkSay("Sorry "+cname+", I've run out of money! The shop in"
          "Silvere might be able to help you, though. I've heard "
          "that they have a contract with the local money lenders.\n"
         );
    break;
  case TS_NOBUY:
  {
    mixed nobuy;

    nobuy = funcall(ob ? ({int})ob->Query(P_NOBUY) : 0);
    if (stringp(nobuy))
        SkSay(nobuy);
    else
        SkSay("Sorry "+cname+", I don't buy such items!\n");
    break;
  }
  case TS_NOTRADE:
    SkSay("Sorry "+cname+", I don't buy such items!\n");
    break;
  case TS_NOMOVE:
    SkSay("Sorry "+cname+", this item won't move.\n");
    break;
  default: /* was: 'if (!res)' */
    SkSay("Sorry "+cname+", this item has no value!\n");
  }

  /* Return an empty string so that notify_fail() is happy */
  return "";
}
protected varargs int check_sell(object ob,int price)
{
  int res;
  res = TestSell(ob,price);
  if (res > 0) return 1;
  notify_fail(lambda(0, ({ #'check_sell_notify /*'*/, res, ob, CustomerName() }))
             , NOTIFY_NOT_VALID);
  return 0;
}

public string print_list(mixed *l)
{
  object *obs;
  string *strs;
  obs = filter(l,SF(objectp));
  strs = filter(l-obs,SF(stringp));
  strs += map_objects(obs,"Short")-({0});
  if (!sizeof(strs)) return "";
  return implode(strs[0..<2],", ")+
    (sizeof(strs[0..<2])?" and ":"")+strs[<1];
}

public object* QueryCurrentObjects()
{
  return Pcurrentobjects||({});
}

public object* SetCurrentObjects(object *co)
{
  return Pcurrentobjects = co;
}

protected varargs void continue_sell(object *items,object env,int price)
{
  object *ok,*too_heavy,*not_empty,
         *too_expensive,*not_take,*not_trade,
         *to_destruct,*no_value;
  int amount,rc,i;
  mixed m_array;

  if (!TP || environment(TP) != ME) return;

  ok = ({});
  too_heavy = ({});
  not_empty = ({});
  too_expensive = ({});
  not_take = ({});
  not_trade = ({});
  to_destruct = ({});
  no_value = ({});
  amount = 0;
  items-=({0});
  if (!({int})env->QueryIsPlayer())
    items+=({env});

  i = sizeof(items);
  while(i--)
    {
      if (sizeof(all_inventory(items[i])||({}))
          &&items[i]!=env)
        {
          not_empty+=({items[i]});
          continue;
        }
      if (!({int})GetStore()->MayAddWeight(({int})items[i]->QueryWeight()))
	{
	  too_heavy+=({items[i]});
	  continue;
	}
      switch(rc = TestSell(items[i],price))
	{
	 case TS_NOMONEY:
	  too_expensive+=({items[i]});
	  break;
         case TS_NOBUY:
	 case TS_NOTRADE:
	  not_trade+=({items[i]});
	  break;
	 case TS_NOMOVE:
	  not_take+=({items[i]});
	  break;
	 case 0:
	  no_value+=({items[i]});
	  break;
	 default:
	  if (TP)
	    {
	      items[i]->Set(P_PRICE,rc);
              items[i]->Set(P_OWNER,getuid(TP));
	    }
	  if (ME_OK != PutInStore(items[i]))
          {
	    not_take+=({items[i]});
            notify_fail(
              lambda(0,
                ({ #', /*'*/,
                  ({ SF(SkSay),
                  "Sorry "+CustomerName()+", this item won't move.\n"}), ""
                }) ),
              NOTIFY_NOT_VALID);
	    break;
          }
	  if (!QueryMarket())
	    {
	      amount+=rc;
              if (member(SSHOPS,object_name(ME))==-1)
                Pcash -= rc;
	    }
	  else if (TP)
	    AddInsurance(items[i]);
	  if (({int})items[i]->Query(P_NOSELL)
              ||!QueryBuy())
	    to_destruct+=({items[i]});
          ok+=({items[i]});
	}
    }

  if (!QueryMarket())
    {
      if (sizeof(ok))
        {
          Pcurrentobjects = ok;
          AdjustMoney(TP,m_array = ({mixed})MONEY_DEMON->CreateMoney(amount,
                                                           QueryValuta()),0);
          Pcurrentobjects = 0;
          Write(
            SkShort(1)+" takes "+print_list(ok)+
            " from you and gives "+({string})MONEY_DEMON->QueryMoneyString(m_array)+
            " to you.\n",1);
          Say(
            ({SkShort(1)+" takes "+print_list(ok)+
              " from "+CustomerName()+" and gives "+
              ({string})MONEY_DEMON->QueryMoneyString(m_array,10)+" to "+
              ({string})TP->QueryObjective()+".\n",
              "Something happens.\n"
            }),({TP}));
	}
    }
  else
    {
      Write(
        SkShort(1)+" takes "+print_list(ok)+" from you.\n",1);
      Say(
        ({SkShort(1)+" takes "+print_list(ok)+" from "+CustomerName()+".\n",
          "Something happens.\n"
        }),({TP}));
    }

  if (sizeof(too_heavy))
    SkSay("Sorry "+CustomerName()+". "+
      capitalize(print_list(too_heavy))+" "+
      (sizeof(too_heavy)>1?"do":"does")+"n't fit into my store.\n");
  if (sizeof(too_expensive))
    SkSay("I don't have enough money to pay "+print_list(too_expensive)+
              ", "+CustomerName()+".\n");
  if (sizeof(not_trade))
    SkSay("I don't trade with "+print_list(not_trade)+", "+
              CustomerName()+".\n");
  if (sizeof(not_take))
    SkSay("I can't take "+print_list(not_take)+" from you, "+
              CustomerName()+".\n");
  if (sizeof(no_value))
    SkSay(capitalize(print_list(no_value))+" "+
      (sizeof(no_value)>1?"do":"does")+"n't have any value, "+
      CustomerName()+".\n");
  if (i = sizeof(to_destruct))
    while(i--)
      {
	to_destruct[i]->remove();
	if (to_destruct[i]) destruct(to_destruct[i]);
      }

  rc = 0;
  if (i = sizeof(not_empty))
    {
      SkSay("Oh, "+CustomerName()+". "+
        capitalize(print_list(not_empty))+" "+
        (i>1?"are":"is")+" not empty. Let's see if I'll buy some of the "+
	    "contents.\n");
      while(i--)
      {
        call_out(SF(continue_sell),i+1,all_inventory(not_empty[i]),
                 not_empty[i],price);
	rc = 1;
      }
    }
  TP->Set(P_SELL_MUTEX, rc);
}

protected varargs int sell_items(object *items,int price)
// Sell all items given in the array and do the checks if we may
// buy the items or not.
{
  if (!items || (sizeof(items) < 1))
    return notify_fail(
      lambda(0,
        ({#', /*'*/ ,
          ({ SF(SkSay),
          "Sorry "+CustomerName()+", but you don't have that.\n"}), ""
        }) ),
      NOTIFY_NOT_VALID),0;

  if (!sizeof(filter(items,SF(check_sell),price)))
    return 0;

  if (({int})TP->Query(P_SELL_MUTEX))
  {
    notify_fail(
      lambda(0,
        ({#', /*'*/,
          ({ SF(SkSay),
          "Sorry "+CustomerName()+", we already are inmidst of a transaction!\n" }), ""

        }) ),
      NOTIFY_NOT_VALID);
    return 0;
  }
  TP->Set(P_SELL_MUTEX, 1);
  call_out(SF(continue_sell),1,items,TP,price);
  // to prevent Too long evaluation
  return 1;
}

/*
** BUYING ITEMS
** ============
*/

/* protected */ varargs int check_money(int amount, status no_action,status force)
// Checks the player for the amount of money and reduces the money if enough
// is present. Otherwise the player will get an error message.
// If 'force' is !=0, the player accepted to pay a fee, if (s)he hasn't the
// correct money.  (Haeh??)
{
  mixed paying;

  if (!TP || (!QueryShopkeeper()&&!QueryNoShopkeeper())) return 0;
	// Program error

  if (force) amount+=CALC_FEE(amount);
  if (QuerySomeonesValue(TP) < amount)
    return notify_fail(
      lambda(0,
        ({#', /*'*/,
          ({ SF(SkSay),
          "Sorry "+CustomerName()+", but you don't have enough money!\n" }), ""
        })),NOTIFY_NOT_VALID),0;

  if (QuerySomeonesValue(TP,QueryFValuta(force)) < amount)
    return notify_fail(
      lambda(0,
        ({ #', /*'*/,
          ({ SF(SkSay),
          "Sorry "+CustomerName()+", you don't have enough money of "
          "the right currency!\n"
          "If you want to "+QueryBuy()+" anyway, i. e. if you want to pay\n"
          "it in another currency but with a small fee, just type:\n"+
          QueryBuy()+" really 'what you want to "+QueryBuy()+"'.\n" }), ""
        })),NOTIFY_NOT_VALID),0;

  if (no_action) return 1;

  if (member(SSHOPS,object_name(ME))==-1)
    Pcash += amount;
  paying = PayValue2(TP, amount,QueryFValuta(force));
  if (paying == MONEY_CANT_PAY)
    return notify_fail(
      lambda(0,
        ({#', /*'*/,
          ({ SF(SkSay),
          "Sorry "+CustomerName()+", you can't afford the money!\n"}), ""
        })),NOTIFY_NOT_VALID),0;
  if (paying == MONEY_NEGATIVE)
    return notify_fail(
      lambda(0,
        ({#', /*'*/,
          ({ SF(SkSay),
          "Sorry "+CustomerName()+", your money doesn't look good today!\n" }), ""
        })),NOTIFY_NOT_VALID),0;

  if (amount)
    {
      Write("You pay "+paying[0] +
         (paying[1] ? " and receive "+paying[1] : "")+
         ".\n",1);
      Say(SkShort(1)+" takes some money from "+CustomerName()+".\n",({TP}));
    }
  else
    Write("You pay nothing.\n");
  return 1;
}

protected varargs int buy_routine(object ob,int force)
// In this function the player will receive the object he wanted to buy, if he
// can afford it, and if he can carry it.
{
  if (!CheckTrade(ob) || !CheckLivingTrade(ob))
    return notify_fail(
      lambda(0,
        ({CL_PROGN,
          ({
            CL_PROGN,
            ({
              SF(SkSay),
              "Oh, I don't trade with "+({string})ob->QueryShort()+"!\n"
            }),
            ({
              SF(Say),
              SkShort(1)+" removes "+({string})ob->QueryShort()+" from the store.\n"
            })
          }),
          ({
            SF(destruct),
            ob
          }), ""
	  })),NOTIFY_NOT_VALID),0;

  // Test coins of customer.
  if (!check_money(GetPrice(ob), 1,force))
    return 0;

  // Check if player can carry the item.
  if(!({int})TP->MayAddWeight(ob->QueryWeight()))
    return notify_fail(
      lambda(0,
        ({ #', /*'*/, ({ SF(SkSay),
          CustomerName()+", you can't carry that much.\n" }), ""
        })),NOTIFY_NOT_VALID),0;

  // Get coins from customer.
  Pcurrentobjects = ({ob});
  if(!check_money(GetPrice(ob),0,force))
    return 0;
  Pcurrentobjects = 0;

  // Handle item.
  if (QueryMarket())
    {
      RemoveInsurance(ob);
      ob->Set(P_PRICE,0);
      ob->Set(P_OWNER,0);
    }

  ob->move(TP, M_SILENT);
  Write(SkShort(1)+" gives "+({string})ob->Short()+" to you.\n",1);
  Say(SkShort(1)+" gives "+({string})ob->Short()+" to "+CustomerName()+".\n",({TP}));
  return 1;
}

protected varargs object *buy_string(string str, int force)
// Buy an item refering to its id.
{
  object *sold;
  int i;
  mixed found, tmp;
  string msg, msg2;
  found = searchm(GetStore(), str,
                  SM_LOCATE|SM_CMULTI|WizSearch(),
                  symbol_function("CheckList",GetStore()));
  found = sort_findings(found, sort_f_prop());

  msg = found[-FOUND_SINGLE]
        ? "I don't have that many in stock."
        : "";

  if (i = sizeof(tmp = found[FOUND_IDS]))
    {
      if (i == 1)
        msg2 = tmp[0];
      else
        msg2 = implode(tmp[0..<2], ", ")+" or "+tmp[<1];
      msg += "I don't have "+msg2+" to sell.\n";
    }

  if (!(sizeof(found[FOUND_SINGLE])))
    return notify_fail(
      lambda(0,
        ({#', /*'*/, ({SF(SkSay),
          msg }), ""
        })),NOTIFY_NOT_VALID),0;

  if (msg != "")
    SkSay(msg);

  if (!sizeof(sold = filter(found[FOUND_SINGLE], SF(buy_routine),force)))
    return 0;
  return sold;
}

protected varargs object *buy_number(int number,int force)
// Buy item <number> from store. But take care if someone already bought an item
// in the meantime, to ensure, that our customer really gets what he wants to
// have and not something completely different.
{
  string *idx;
  mapping last_list;
  // ([<number>:({<objectp>})])
  object *items,ob;
  int i;

  if (!TP) return 0;
  if (!last_list = ({mapping})TP->Query(P_LASTLIST))
    return notify_fail(
      lambda(0,
        ({ #', /*'*/,
          ({ SF(SkSay),
          "I didn't show you my list of items.\n"}), ""
        })),NOTIFY_NOT_VALID),0;

  if (!member(last_list,number))
    return notify_fail(
      lambda(0,
        ({#', /*'*/,
          ({ SF(SkSay),
          CustomerName(1)+", there was no number "+to_string(number)+
          " on the list I showed to you!\n" }), ""
        })),NOTIFY_NOT_VALID),0;

  i = sizeof(items = last_list[number]);

  while(i--&&!ob)
    if (items[i]
        &&environment(items[i])==GetStore())
      ob = items[i];

  if (!ob)
    return notify_fail(
      lambda(0,
        ({#', /*'*/,
          ({ SF(SkSay),
           "Sorry "+CustomerName()+", but I don't have that item anymore, "
           "I've sold them all.\n"}), ""
        })),NOTIFY_NOT_VALID),0;


  if ( ({int})ob->QueryAmount() )
  {
    idx = ({string *})ob->QueryIds();
    if ( sizeof( idx ) )
      ob->id(idx[0]);
    ob->SetLastAmount(1);
  }

  return buy_routine(ob,force)?({ob}):0;
}

protected void list_evaluated(object *items,string str)
{
  object store;
  mapping list,inv;
  int i;

  // list: ([<number>:({<objectp>})])
  // inv:  ([<short>#<value>#<size>:({<objectp>})])])])
  string *shorts;

  store = GetStore();
  inv = ({mapping})store->GroupInventory(items);
  shorts = sort_array(m_indices(inv),SF(>));
  list = ([]);
  for (i=1;i<sizeof(shorts)+1;i++)
    list[i]=inv[shorts[i-1]];
  if (TP)
    TP->Set(P_LASTLIST,list);
  list_done(str);
}

protected void get_list(string str)
{
  object store;
  mixed *storeinv;
  if (!TP) return;
  store = GetStore();
  storeinv = ({mixed *})store->SearchObjects(str)||({});
  if (sizeof(storeinv) && pointerp(storeinv[0]))
    storeinv = storeinv[0];
  list_evaluated(storeinv,str);
}

public int SetBuyFactor(int factor)
// Percentage how much more you have to pay for an item you sold in here.
{
  if (factor < MIN_BUY_FACTOR)
    return Pbuy_factor = MIN_BUY_FACTOR;
  else
    return Pbuy_factor = factor;
}

public int QueryBuyFactor()
{
  return Pbuy_factor;
}

public int SetDynamic(int dy)
// This handles how fast the cash will be restored for the shop.
{
  if (dy < 0 || dy > 100)
    return Pdynamic;
  else
    return Pdynamic = dy;
}

public int QueryDynamic()
{
  return Pdynamic;
}

public int SetMinCash(int c)
// Minimum amount of cash for the shop.
{
  return Pmin_cash = c;
}

public int QueryMinCash()
{
  return Pmin_cash;
}

public int SetCash(int i)
{
  return Pcash = i;
}

public int QueryCash()
{
  return Pcash;
}

public void reset_cash()
{
  int add_cash;

  if (member(SSHOPS,object_name(ME))==-1)
    if (Pcash < Pmin_cash)
      {
        add_cash = Pmin_cash * Pdynamic / 100;
        Pcash += add_cash;
      }
}
