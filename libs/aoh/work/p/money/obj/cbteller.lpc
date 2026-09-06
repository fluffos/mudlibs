/*--------------------------------------------------------------------------
 * DAEMONPATH "money/obj/cbteller" -- The citybank teller
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <secure/wizlevels.h>
#include <properties.h>
#include <daemons.h>
#include <config.h>
#include <money.h>
#include <moving.h>
#include <search.h>
#include <string.h>

inherit "/std/thing";
inherit MONEY_LIB;
inherit L_STRING;

#define TP this_player()
#define JOIN_PRICE 10
#define CALC_FEE(x) (x*2/100)||1

public void create()
{
  (::create());
  seteuid(getuid());
  SetShort("a 24 hour CityBank banking teller");
  SetIds(({"teller","cbteller"}));
  SetAds(({"banking","new","automagic"}));
  SetNoGet("It's too heavy for you.\n");
}

public varargs string QueryLong()
{
  return
    "It's the new automagic banking teller, brought to you by the "
    "CityBank (tm) of Nightfall. The money is absolutely safe here "
    "and you can come here day and night for deposits and withdrawals.\n"
    "If you do not yet have an account, simply enter CREATE ACCOUNT "
    "right here, to receive a banking account for a small fee of "+
		   ({string})call_other(MONEY_DEMON,
			      ({int})(TP||previous_object())->QueryBrief()?
			      "QueryValueShort":"QueryValueString",
			      JOIN_PRICE,QueryValuta()||({"copper"})) +
    ".\nYou may WITHDRAW and DEPOSIT here and ask for your BALANCE, as well.\n"
    "To delete your account, type CLOSE ACCOUNT.\n"
    "If you are interested in our top members just type 'list top members'.\n"
    "To get the value of the coins you're carrying type 'help money'.\n"
   ;
}

public void init()
{
  (::init());
  add_action("cmd_create","create");
  add_action("cmd_create","open");
  add_action("cmd_deposit","deposit");
  add_action("cmd_withdraw","withdraw");
  add_action("cmd_close","close");
  add_action("cmd_kick","kick");
  add_action("cmd_balance","balance");
  add_action("cmd_list",   "list");
}

protected string number2string(int nr)
{
  int hundred,ten,one;
  string *numbers,*tnumbers;
  string res;

  hundred = nr/100;
  ten = (nr-hundred*100)/10;
  one = (nr-hundred*100-ten*10);
  numbers = ({"","one","two","three","four","five",
              "six","seven","eight","nine"});
  tnumbers = ({"","ten","twenty","thirty","fourty","fifty",
               "sixty","seventy","eigthy","ninety"});
  if (hundred>9) return to_string(nr);
  res = "";
  if (hundred)
    res += numbers[hundred]+" hundred";
  if (hundred&&(ten||one))
    res+= " and ";
  if (ten)
    if (ten==1)
      if (!one)
        res+="ten";
      else if (one==1)
        res+="eleven";
      else if (one==2)
        res+="twelve";
      else if (one==3)
        res+="thirteen";
      else if (one==5)
        res+="fifteen";
      else
        res+=numbers[one]+"teen";
    else
      {
        res+=tnumbers[ten];
        if (one)
          res+="-";
      }
  if (one&&ten!=1)
    res+=numbers[one];
  return res;
}

protected string what_am_i(int amount)
{
  amount = amount/1000000;
  if (!amount) return "rich player";
  if (amount>999) return "billionaire";
  if (!IS_HLP(TP)) return "millionaire";
  if (amount<5)
    return
      ({"single","double","triple","quadruple"})[--amount]+" millionaire";
  return number2string(amount)+"fold millionaire";
}

protected string format_list(int pos,string player,int amount)
{
  return radjust(to_string(pos+1),2,"0")+". "+
         ladjust(capitalize(player)+" ",13,".")+
         radjust(" "+what_am_i(amount),30,".");
}

protected string *list_top10()
{
  string *list,*match;
  mapping accounts;
  int *samnts,*amnts,i;

  accounts = ({mapping})BANK_D->QueryAccounts();
  samnts = sort_array(amnts = m_values(accounts),#'< /*'*/);
  if (sizeof(samnts)>10)
    samnts = samnts[0..9];
  match = m_indices(accounts);
  list = ({});
  for (i=0;i<sizeof(samnts);i++)
    list+=({format_list(i,match[member(amnts,samnts[i])],samnts[i])});
  return list;
}

public int cmd_list(string str)
{
  if (lower_case(str||"")!="top members")
    return notify_fail("List what?\n",NOTIFY_NOT_OBJ);
  smore(list_top10(),({int})TP->QueryPageSize());
  return 1;
}

public int cmd_create(string str)
{
  mixed   paying;
  object ob;

  if (str!="account")
    return notify_fail("Usage: create account\n",
                       NOTIFY_ILL_ARG);

  if (({int})BANK_D->HasAccount(getuid(TP)))
    return notify_fail("You are already a member of this bank!\n",
                       NOTIFY_NOT_VALID);
  ob = QueryMoneyObject(this_player());
  if (QuerySomeonesValue(this_player()) < JOIN_PRICE)
    return notify_fail(
      "You can't afford joining the bank. This requires "+
      ({string})MONEY_DEMON->
	QueryValueString(JOIN_PRICE,QueryValuta()||
      (ob?m_indices(({mapping})ob->QueryMoney()):0)) +
      ".\n",NOTIFY_NOT_VALID);
  paying = PayValue2(this_player(),JOIN_PRICE,
		     m_indices(({mapping})MONEY_DEMON->QueryCoinTypes()||([])));
  if(intp(paying))
    {
      write("Oops... Something went wrong while paying your fee.\n"
	    "Please inform the Archwizards about!\n");
      return 1;
    }
  BANK_D->SetAccount(getuid(TP),0);
  write(
	 sprintf("You pay %s%s. Now you are member of the CityBank. Cool!\n",
		 paying[0],paying[1]?" and get " + paying[1] + " back":""));
  say((({string})TP->QueryName() || "Someone")+" just became member of the CityBank (tm).\n");
  return 1;
}

public int cmd_close(string str)
{
  int remaining;

  if (str!="account")
    return notify_fail("Usage: close account\n",
                            NOTIFY_ILL_ARG);
  if (!({int})BANK_D->HasAccount(getuid(TP)))
    return notify_fail(
		  "Sorry, you are not registered in our magic brains.\n",
	          NOTIFY_NOT_VALID);

  remaining = ({int})BANK_D->CloseAccount(getuid(TP));
  AdjustMoney(this_player(),({mixed})MONEY_DEMON->CreateMoney(remaining,
                                                     QueryValuta()));
  write(
"You whisper some words to a magic ear and receive all your remaining coins "
"out from a small hatch. Your account is closed.\n");
  say(({string})this_player()->QueryName() + " operates at the CityBank teller.\n");
  return 1;
}

public int cmd_deposit(string str)
{
  mixed moneyob;
  int money_value,i,amount;
  mapping money_map,temp_map;
  string *ids;

  if(!str || str == "?")
    return notify_fail("Usage: deposit <money>\n"
                            "<money> might be anything like '10 copper'\n"
                            "or '10 copper and 12 platinum coins\n",
			    NOTIFY_ILL_ARG);

  if(!({int})BANK_D->HasAccount(getuid(TP)))
    return notify_fail("You are not a member of this bank. Join first.\n",
			    NOTIFY_NOT_VALID);
  money_map = ([]);
  i = sizeof(ids = explode(implode(explode(str,"and"),","),","));
  if (str=="all")
    {
      if (!moneyob=QueryMoneyObject(TP))
        return notify_fail(
          "You don't have any money.\n",
          NOTIFY_NOT_VALID);
      if (!amount = ({int})moneyob->QueryValue())
        return notify_fail(
          "Your money has no value.\n",
          NOTIFY_NOT_VALID);
      money_map = ({mapping})moneyob->QueryMoney();
    }
  else
    while(i--)
      {
        if (!moneyob = search(TP,ids[i],SEARCH_INV|SM_OBJECT|SM_IGNLIGHT))
          return notify_fail(
            "You don't have "+ids[i]+".\n",
            NOTIFY_NOT_VALID);
        temp_map = ({mapping})moneyob->QueryMoney()||([]);
        // moneyob->SetRemaining(0); // ???
        money_map += filter_indices(temp_map,
                      lambda(({'coin /*'*/}),({#'[,temp_map, /*'*/
                             'coin /*'*/})));
        if (moneyob!=QueryMoneyObject(TP))
          return notify_fail(
            capitalize(ids[i])+" is no money.\n",
            NOTIFY_NOT_VALID);
        if (!money_value = ({int})MONEY_DEMON->QueryMoneyValue(money_map))
          return notify_fail(
	    capitalize(ids[i])+" have no value.\n",NOTIFY_NOT_VALID);
       amount+=money_value;
     }
  BANK_D->AddAccount(getuid(TP),amount-CALC_FEE(amount));
  PayMoney(TP,money_map);
  write(
    "You deposit "+str+" at your bank account and pay a fee of "+
    to_string(CALC_FEE(amount))+" Nightfall Currency Units.\n");
  say((({string})TP->QueryName() || "Someone") + " operates the CityBank teller.\n");
  return 1;
}

public int cmd_withdraw(string str)
{
  int how_much,amnt;
  string type;
  mapping dummy;

  if (!str || str=="?")
    return notify_fail("Usage: withdraw <amount> <type>.\n",
                            NOTIFY_ILL_ARG);
  if (!({int})BANK_D->HasAccount(getuid(TP)))
    return
      notify_fail("Sorry, you are not registered in our magic brains.\n",
		       NOTIFY_NOT_VALID);

  if(sscanf(str,"%d %s",amnt,type)!=2)
    return notify_fail("Usage: withdraw <amount> <type>.\n",
                            NOTIFY_ILL_ARG);

  if (amnt<=0)
    return notify_fail("You must withdraw something.\n",
                            NOTIFY_NOT_VALID);
  /* Now something magically... we want to know, what the player means
     with the type. So we create a fictive money mapping and send it
     to the MONEY_DEMON. */
  dummy = ([]);
  filter(m_indices(({mixed})MONEY_DEMON->QueryCoinTypes()),
	       lambda(({'typ, 'map}), ({#'=, ({#'[, 'map, 'typ}), 1})),
               &dummy);
  if(!(({mixed})MONEY_DEMON->QueryCoinTypes())[type])
    type = ({string})MONEY_DEMON->PresentMoney(type,dummy);
  if(!type)
    return notify_fail("Sorry, we don't handle this currency.\n",
                            NOTIFY_NOT_VALID);

  how_much=amnt*({int})MONEY_DEMON->QueryCoinValue(type);
  if (!({int})BANK_D->AddAccount(getuid(TP),-how_much))
    return notify_fail("You do not have enough money in your account.\n",
                            NOTIFY_NOT_VALID);
  AdjustMoney(this_player(),({mixed})MONEY_DEMON->CreateMoney(how_much,({type})));

  write(
"You whisper some words to a magic ear and receive the coins "
"out from a small hatch.\n");
  say((({string})TP->QueryName() || "Someone") + " operates the CityBank teller.\n");
  return 1;
}

public int cmd_balance(string str)
{
  mixed acc;

  if (str)
    return notify_fail("To check your account just type 'balance'.\n",
                            NOTIFY_ILL_ARG);

  if (!({int})BANK_D->HasAccount(getuid(TP)))
    return notify_fail("You do not have a CityBank (tm) account.\n",
                            NOTIFY_NOT_VALID);

  if (!(acc = ({mixed})BANK_D->QueryFullAccount(getuid(TP))))
    return write("Your account is empty.\n")||1;

  write("You have " +
	 ({string})MONEY_DEMON->QueryValueString(acc[getuid(TP),A_AMOUNT],
				       QueryValuta()) +
	 " at your account.\nCreated:        " +
	 (acc[getuid(TP),A_CREATED]?ctime(acc[getuid(TP),A_CREATED]):
	  "Never accessed") +
	 "\nLast deposit:   " +
	 (acc[getuid(TP),A_DEPOSIT]?ctime(acc[getuid(TP),A_DEPOSIT]):
	  "Never accessed") +
	 "\nLast withdrawl: " +
	 (acc[getuid(TP),A_WITHDRAW]?ctime(acc[getuid(TP),A_WITHDRAW]):
	  "Never accessed") + "\n");
  return 1;
}

public int cmd_kick(string str)
{
  if (this_object()!=present(str)) return 0;

  say((({string})TP->QueryName() || "Someone")+
      " tries to force some money out of the CityBank teller by using\n" +
      "brute force and kicking it. Tsk, tsk, tsk!\n");
  write("You kick the teller in vain. It's magically secured against "
        "thieves.\n");
  return 1;
}

public varargs int move(mixed dest, int method, mixed extra)
{
  int result;

  if((result = ::move(dest, method, extra)) == ME_OK)
    SetValuta(({string *})MONEY_DEMON->QueryCoinTypes(getuid(environment())));

  return result;
}
