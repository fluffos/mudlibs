/* Modified as entry point and portal room for demons */
/* (April 10, 1996 -- Rover) */

#include "/d/archwiz/common/path.h"
#include <properties.h>
#include <config.h>
#include <moving.h>
#include <money.h>
#include <rooms.h>

#define TP this_player()
#define ME this_object()
#define CUSTOMER_NAME ((string)this_player()->QueryName())
#define NO_TRADE_VALUE	5000	// The item would not be sold again.

#define TS_NOMONEY -1  // TestSell - Return-Values
#define TS_NOBUY   -2
#define TS_NOTRADE -3
#define TS_NOMOVE  -4

#include <lock.h>
inherit "/std/shop";
inherit "/lib/raceportal";

public void create()
{
  (::create());

/* --- Portal stuff --- */
  SetPortalRace("demon");
  SetPortalRoom("/d/hell/common/room/bazaar/pit");
  Set("PortalMayPass", #'query_once_interactive);
  SetPortalDetail(
({ "It's a huge furnace, radiating lots of heat.\n"
 , "You see a furnace, radiating lots of heat through its open door.\n"
   "Flames leak out from time to time. This is where all the metal is\n"
   "recycled.\n"
 , "The furnace is cold, and its interior is pitch black, you can't see\n"
   "anything.\n"
 , "The furnace radiates a comfortable warmth, and instead of searing flames\n"
   "you see an open place surrounded by walls of fire.\n"
   "It indeed could be possible to step into the furnace, and perhaps even\n"
   "with other players.\n"
})
                  );
  SetPortalSingle(
({ "Something is definitely wrong, as you can't enter the furnace.\n"
 , "You can't use the furnace right now, as it leads to nowhere.\n"
 , ({ "steps into the furnace", "leaves" })
 , ({ "steps out of the furnace", "arrives" })
 , "step into the furnace and find yourself emerging out of a small gap\n"
   "in the flames"
})
                 );
  SetPortalMulti(
({ "Something is definitely wrong, as you can't enter the furnace.\n"
 , "You can't use the furnace right now, as it leads to nowhere.\n"
 , ({ " steps into the furnace.\n", "Someone leaves.\n" })
 , ({ " leads %% into the furnace.", "Some people leave.\n"})
 , ({ " leads a group of people into the furnace.\n", "Some people leave.\n"})
 , ({ " steps out of the furnace.\n", "Someone arrives.\n"})
 , ({ " leads %% out of the furnace.", "Some people arrive.\n"})
 , ({ " leads a group of people out of the furnace.\n", "Some people arrive.\n"})
 , "You step into the furnace and find yourself emerging "
   "out of a small gap in the flames.\n\n"
 , "You lead %% through the furnace and out of the gap.\n"
 , " leads %% through the furnace and out on an open place surrounded\n"
   "by flames.\n"
 , "You lead a group of people through the furnace and out of the small gap.\n\n"
 , " leads a group of people and you through the furnace and out on an open\n"
   "place sourrounded by flames.\n\n"
})
                );
  /* --- Portal stuff --- */

  SetIntShort("Metallica Recycling Center");
  SetIntLong(
    "You are standing in the Metallica Recycling Center. Here you can "
    "sell all the useless stuff you've gathered while running through the "
    "world. At the side of the room a huge furnace is radiating lots of heat. "
    "A poster of the Green Dot (tm) hangs at the wall.\n");

  AddExit("furnace", PortalExit());
  HideExit("furnace", HIDE_ALWAYS);

  AddRoomCmd( ({"enter", "step"})
            , PortalExit(({"into furnace", "into the furnace",
			   "in to the furnace"}))
            );

  AddDetail(({"furnace","portal","place","flames","open furnace"})
	    , #'PortalDetail);
	      
  AddDetail(({"poster","dot","green dot","Dot","Green Dot","Green dot"}),
    "You see a poster with a very big Green Dot (tm) in the center. "
    "You can read in big letters:\n\n"
    "   RECYCLING LEBT VOM MITMACHEN\n\n"
    "   (C) DSD - Duales System Deutschland\n"
    "   Green Dot (tm) and Yellow Sack (tm)\n"
    "   are trademarks of DSD (Dual System Germany)\n");

  AddDoor("north","./row4","exit",
    "This exit leads out to the Skid row.\n",
    "0",LOCK_OPEN);
  SetList(0);
  SetBuy(0);
  SetIdentify(0);
  ForbidShopkeeper();
  SetMinCash(100000);
}

public int ModifyPrice(object obj,int price,string verb)
{
  return price*2/3;
}

protected varargs void continue_sell(object *items,object env)
{
  object *ok,*too_heavy,*not_empty,
         *too_expensive,*not_take,*not_trade,
         *to_destruct,*no_value,*green_dot;
  int amount,dot_amount,rc,i;
  object pl;
  mixed m_array;

  if (!TP) return;
  
  ok = ({});
  too_heavy = ({});
  not_empty = ({});
  too_expensive = ({});
  not_take = ({});
  not_trade = ({});
  to_destruct = ({});
  no_value = ({});
  green_dot = ({});
  amount = 0;

  if (!env->QueryIsPlayer())
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
      if (!GetStore()->MayAddWeight(items[i]->QueryWeight()))
	{
	  too_heavy+=({items[i]});
	  continue;
	}
      switch(rc = TestSell(items[i]))
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
          if (random(5))
	    {
	      dot_amount+=1;
              SetCash(QueryCash()-1);
	      green_dot+=({items[i]});
	    }
	  else
	    no_value+=({items[i]});
	  if (items[i]->Query(P_NOSELL)
              ||QueryNoBuy())
	    to_destruct+=({items[i]});
          PutInStore(items[i]);
	  break;
	 default:
	  amount+=rc;
          SetCash(QueryCash()-rc);
	  if (items[i]->Query(P_NOSELL)
              ||QueryNoBuy())
	    to_destruct+=({items[i]});
	  PutInStore(items[i]);
          ok+=({items[i]});
	}
    }

  if (sizeof(ok))
    {
      SetCurrentObjects(ok);
      AdjustMoney(TP,m_array = (mixed *)MONEY_DEMON->CreateMoney(amount,
                                                       QueryValuta()),0);
      SetCurrentObjects(0);
      Write(
        SkShort(1)+" takes "+print_list(ok)+
        " from you and gives "+MONEY_DEMON->QueryMoneyString(m_array)+
        " to you.\n",1);
      Say(
        ({SkShort(1)+" takes "+print_list(ok)+
          " from "+CustomerName()+" and gives "+
          MONEY_DEMON->QueryMoneyString(m_array,10)+" to "+
          TP->QueryObjective()+".\n",
          "Something happens.\n"
        }),({TP}));
    }
  if (sizeof(no_value))
    SkSay(capitalize(print_list(no_value))+" "+
        (sizeof(no_value)>1?"do":"does")+"n't have any value and has "
        "no Green Dot (tm). I'll toss it into the garbage collector, "+
	    CustomerName()+".\n");
  if (sizeof(green_dot))
    {
      SkSay(capitalize(print_list(green_dot))+" "+
            (sizeof(green_dot)>1?"do":"does")+" have a Green Dot (tm).\n");
      Say(SkShort(1)+" puts the item"+(sizeof(green_dot)>1?"":"s")+
          " into a Yellow Sack (tm).\n");
      SetCurrentObjects(green_dot);
      AdjustMoney(TP,m_array = (mixed *)MONEY_DEMON->CreateMoney(dot_amount,
                                                       QueryValuta()),0);
      SetCurrentObjects(0);;
      Write(
        SkShort(1)+" takes "+print_list(green_dot)+
        " from you and gives "+MONEY_DEMON->QueryMoneyString(m_array)+
        " to you.\n",1);
      Say(
        ({SkShort(1)+" takes "+print_list(ok)+
          " from "+CustomerName()+" and gives "+
          MONEY_DEMON->QueryMoneyString(m_array,10)+" to "+
          TP->QueryObjective()+".\n",
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
  if (i = sizeof(to_destruct))
    while(i--)
      {
	to_destruct[i]->remove();
	if (to_destruct[i]) destruct(to_destruct[i]);
      }
  if (i = sizeof(not_empty))
    {
      SkSay("Oh, "+CustomerName()+". "+
        capitalize(print_list(not_empty))+" "+
        (i>1?"are":"is")+" not empty. Let's see if I'll buy some of the "+
	    "contents.\n");
      while(i--)
        call_out(#'continue_sell,i+1,all_inventory(not_empty[i]),
                 not_empty[i]);
    }
}

protected int sell_items(object *items)
// Sell all items given in the array and do the checks if we may
// buy the items or not.
{
  if (!items || (sizeof(items) < 1))
    return (int)notify_fail(
      lambda(0,
        ({
          #'SkSay,
          "Sorry "+CustomerName()+", you don't have such item(s)!\n"
        }) ),
      NOTIFY_NOT_VALID)&&0;
  call_out(#'continue_sell,1,items,TP); // to prevent Too long evaluation
  return 1;
}
