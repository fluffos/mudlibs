/*--------------------------------------------------------------------------
 * /p/money/obj/moneytool -- The moneytool
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <money.h>
#include <config.h>
#include <properties.h>
#include <secure/wizlevels.h>

#define STR "/lib/string"
#define TP this_player()

inherit "/std/thing";
inherit MONEY_LIB;

/*-----------------------------------------------------------------------*/
public void create()
{
  (::create());
  SetIds(({"mtool","moneytool","mt"}));
  SetAds(({"official"}));
  SetLong("This is the official MoneyTool (tm).\n"
          "For information type HELP MTOOL.\n"
          "Misuse will be punished severely!\n");
  SetShort("a MoneyTool (tm)");
  seteuid(getuid());
  Set(P_AUTOOBJECT,1);
  SetNoDrop("Don't drop this powerful tool.\n");
  SetNoGive("The MoneyTool (tm) is stuck to your hands.\n"
            "It seems to be cursed ;-)\n");
}

/*-----------------------------------------------------------------------*/

public void init()
{
  add_action("cmd_help", "help");
  add_action("cmd_mt","mt");
  add_action("cmd_mt","mtool");
}

/*=== FUNCTIONS =========================================================*/

private varargs string format_member(string what,string content,int invis)
{
  return (!invis?({string})STR->ladjust("  "+what+": ",20,"."):({string})STR->mkstr(20))+
          " "+content+"\n";
}

public int cbmember(string str)
{
  object person;
  mapping data;

  if (!str)
    return notify_fail("Syntax: mt member <name>\n",
                            NOTIFY_ILL_ARG);
  str=lower_case(str);
  if (!({int})BANK_D->HasAccount(str))
    return notify_fail(capitalize(str)+" has no account.\n",
                            NOTIFY_NOT_VALID);
  data = ({mapping})BANK_D->QueryFullAccount(str);
  person = find_player(str);
  write(
    "Information on " + capitalize(str) + "'s CityBank account:\n\n"+
    format_member("Balance",to_string(data[str,A_AMOUNT])+" CU")+
    (person
     ?format_member("Money on player",QuerySomeonesValue(person)+" CU")+
      format_member("",({string})MONEY_D->QueryMoneyString(
                    QueryMoney(person)),1)
     :"")+
    format_member("Account created",ctime(data[str,A_CREATED]))+
    format_member("Last deposit",ctime(data[str,A_DEPOSIT]))+
    format_member("Last withdraw",ctime(data[str,A_WITHDRAW])));
  return 1;
}

/*-----------------------------------------------------------------------*/

public string format_output(string name,
                            int money,
                            int plat,
                            int gold,
                            int silver,
                            int copper,
                            int total)
{
  return ({string})STR->ladjust(name+" ",13,".")+
    ({string})STR->radjust(" "+(money==-1?"no account":to_string(money)),13,".")+
    ({string})STR->radjust(to_string(plat),6)+"PC"+
    ({string})STR->radjust(to_string(gold),6)+"GC"+
    ({string})STR->radjust(to_string(silver),6)+"SC"+
    ({string})STR->radjust(to_string(copper),6)+"CC"+" = "+
    ({string})STR->radjust(to_string(total),8)+" CU";
}

public string mt_stats(mixed pl)
{
  mixed *money,p,g,s,c,pos;
  if (stringp(pl))
    return ({string})STR->ladjust(capitalize(pl)+" ",13,".")+
           ({string})STR->radjust(" "+((c = ({int})BANK_D->QueryAccount(pl))==-1
                        ?"no account"
                        :to_string(c)),13,".");
  money = unmkmapping(QueryMoney(pl)||({}));
  p = ((pos = member(money[0],N_PLATIN))==-1
       ?0
       :money[1][pos]);
  g = ((pos = member(money[0],N_GOLD))==-1
       ?0
       :money[1][pos]);
  s = ((pos = member(money[0],N_SILVER))==-1
       ?0
       :money[1][pos]);
  c = ((pos = member(money[0],N_COPPER))==-1
       ?0
       :money[1][pos]);
  return format_output(capitalize(getuid(pl)),
                       ({int})BANK_D->QueryAccount(getuid(pl)),
                       p,g,s,c,QuerySomeonesValue(pl));
}

/*-----------------------------------------------------------------------*/


private varargs int cblist(string str)
{
  string *list,*match;
  int *samnts,*amnts,i;
  mapping accounts;

  if (str=="top")
    {
      accounts = ({mapping})BANK_D->QueryAccounts();
      samnts = sort_array(amnts = m_values(accounts),#'< /*'*/);
      if (sizeof(samnts)>10)
        samnts = samnts[0..9];
      match = m_indices(accounts);
      list = ({});
      for (i=0;i<sizeof(samnts);i++)
        list+=({mt_stats(match[member(amnts,samnts[i])])});
    }
  else if (!str)
    {
      list = ({"CityBank members here today:",
               "------------------CityBank"
               "----Plat----Gold----Silv----Copp-----------Total"})+
             sort_array(map(users(),#'mt_stats),#'>)+
             ({"------------------------------------------------"
               "--------------------------"});
    }
  else
    {
      match = sort_array(regexp(
                 m_indices(({mapping})BANK_D->QueryAccounts()),str),#'> /*'*/);
      if (!sizeof(match))
        return notify_fail("No accounts match this expression.\n",
                                NOTIFY_NOT_VALID);
      list = ({to_string(sizeof(match))+
               " CityBank members matching regexp "+str+":",""})+
               map(match,#'mt_stats /*'*/);
    }
  STR->smore(list,TP->QueryPageSize());
  return 1;
}

/*-----------------------------------------------------------------------*/

private int cbalter(string str, string verb)
{
  string name;
  object person;
  int amount,curr_amount;

  if (!str) return
    notify_fail("What do you want to do with the MoneyTool (tm)?\n",
                     NOTIFY_ILL_ARG);
  if (sscanf(lower_case(str),"%s %d",name,amount)!=2)
    return notify_fail(
      "You have to specify which account you want to change and with what\n"
      "amount of CU.\n",NOTIFY_ILL_ARG);
  if (!IS_WIZARD(TP))
    return notify_fail("You are not allowed to use the MoneyTool (tm).\n",
                            NOTIFY_NOT_VALID);

  curr_amount = 0;

  if (!({int})BANK_D->HasAccount(name))
    write(capitalize(name)+" has no account. It will be created.\n");
  else
    curr_amount = ({int})BANK_D->QueryAccount(name);

  if (verb=="add")
    amount+=curr_amount;
  else if (verb=="sub")
    amount=curr_amount-amount;
  else if (verb!="set")
    return notify_fail("Unknown verb called function 'mt'\n",
                            NOTIFY_ILL_ARG);

  if (amount<0)
    return notify_fail(
       "This would set the account to a negative amount.\n"
       "Function canceled.\n",NOTIFY_NOT_VALID);
  if (!({int})BANK_D->SetAccount(name,amount))
    return notify_fail("The account couldn't be changed.\n",
                            NOTIFY_NOT_VALID);
  write(capitalize(name)+"'s account changed from "+
        to_string(curr_amount)+" to "+to_string(amount)+" CU.\n");
  if (person = find_player(name))
    tell_object(person,capitalize(getuid(TP))+
		" changed your bank-account.\n");
  return 1;
}

/*-----------------------------------------------------------------------*/

private int cbbreak(string name)
{
  object person;

  if (!name)
    return notify_fail("Syntax: mt break <player>\n",
                            NOTIFY_ILL_ARG);

  if (!IS_WIZARD(TP))
    return notify_fail("You are not allowed to use the MoneyTool (tm).\n",
                            NOTIFY_NOT_VALID);
  name=lower_case(name);
  if (!({int})BANK_D->HasAccount(name))
    return notify_fail(capitalize(name)+" doesn't have an account.\n",
                            NOTIFY_NOT_VALID);

  if (({int})BANK_D->CloseAccount(name)==-1)
    return notify_fail("Can't close the account of "+capitalize(name)+
                            ".\n",NOTIFY_NOT_VALID);
  if (person=find_player(name))
    tell_object(person,capitalize(getuid(TP))+
                " cancelled your CityBank acount.\n");
  write("Account removed.\n");
  return 1;
}

/*-----------------------------------------------------------------------*/

private int cbhelp()
{
  write("mt member <name>       - check account of <name>\n"
        "mt list [<regexp>]     - list bank members\n"
        "mt list top            - lists the Top 10 of bank members\n"
        "mt set <name> <amount> - alter <name>'s account\n"
        "mt add <name> <amount> - ...\n"
        "mt sub <name> <amount> - ...\n"
        "mt break <name>        - kick <name> out of CityBank\n"
        "If you alter the account, and the account doesn't exist, it will\n"
        "be created.\n");
  return 1;
}
/*-----------------------------------------------------------------------*/

public int cmd_mt(string str)
{
  string com,par;
  if (!IS_IMMORTAL(TP))
    return notify_fail("The MoneyTool (tm) starts to glow.\n",
                            NOTIFY_NOT_OBJ);
  if (!str)
    return notify_fail("You have to specify what you want to do.\n",
                            NOTIFY_ILL_ARG);
  if (sscanf(lower_case(str),"%s %s",com,par)!=2)
    com=str, par=0;
  switch (com)
    {
      case "info" :
      case "member": return cbmember(par);
      case "list"  : return cblist(par);
      case "set"   :
      case "add"   :
      case "sub"   : return cbalter(par,com);
      case "break" : return cbbreak(par);
      case "help"  : return cbhelp();
      default: return 0;
    }
    return 0;
}

/*-----------------------------------------------------------------------*/

public int cmd_help(string str)
{
  if (!str || this_object()!=present(str)) return 0;
  return cbhelp();
}

/*-----------------------------------------------------------------------*/
