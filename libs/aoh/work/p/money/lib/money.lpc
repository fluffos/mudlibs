/*--------------------------------------------------------------------------
 * /p/money/lib/money -- money helpfuns
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

/*  this object provides some money library functions.  */

#include <daemons.h>
#include <money.h>
nosave string *Pvaluta;

void create()
{
  seteuid(getuid());
}


/*
 * SetValuta()
 * Sets the money types we trade with.
 * This wouldn't have any effects, if the /lib/money is used via call_other()
 */

public string *SetValuta(string *str) { return Pvaluta = str; }
public string *QueryValuta()
{
  return Pvaluta||({string *})MONEY_D->QueryCoinTypes(getuid())||
    ({string *})MONEY_D->QueryStandard();
}
public string *AddValuta(string str)
{
  if(!str) return 0;
  if(!pointerp(Pvaluta)) return Pvaluta = ({str});
  return Pvaluta += ({str});
}

/*---------------------------------------------------------------------------*/
varargs int AdjustMoney(object who, mixed i, string type) {
  object ob;
  int j;

  if(!who) return 0;
  ob=present(MONEY_NAME,who);
  if (!ob) {
    ob=clone_object(MONEY);
    ob->move(who);
  }
  j = ({int})ob->AdjustMoney(i,type);
  if (ob && !sizeof(({mixed})ob->QueryMoney()))
    ob->remove();
  return j;
}
/*---------------------------------------------------------------------------*/
object QueryMoneyObject(object who) {
  if(who)
    return present(MONEY_NAME,who);
}

mixed QueryMoney(object who) {
  object ob;

  if(!who) return 0;
  ob=present(MONEY_NAME,who);
  if (!ob) return 0;
  return ({mixed})ob->QueryMoney();
}
/*---------------------------------------------------------------------------*/
varargs int SetMoney(object who, mixed arg, string *types) {
  object ob;

  if(!who) return 0;
  ob=present(MONEY_NAME,who);
  if (!ob) {
    ob=clone_object(MONEY);
    ob->move(who);
  }
  if(intp(arg)) return ({int})ob->SetMoney(MONEY_D->CreateMoney(arg, types));
  else return ({int})ob->SetMoney(arg);
}
/*---------------------------------------------------------------------------*/
varargs int QuerySomeonesValue(object who, string *types) {
  object ob;

  if(!who) return 0;
  if(!(ob=present(MONEY_NAME,who))) return 0;
  if(!types) return ({int})ob->QueryValue();
  return ({int})MONEY_D->QueryMoneyValue(ob->QueryMoney(),types);
}
/*---------------------------------------------------------------------------*/
int PayMoney(object who, mixed m_array) {
  mixed m_a;
  object ob;

  if(!who) return 0;
  if(!(ob = present(MONEY_NAME,who))) return 0;
  if (({int})ob->QueryValue() < ({int})MONEY_D->QueryMoneyValue(m_array))
    return 0;
  m_a = ({mixed})MONEY_D->PayMoney(({object})ob->QueryMoney(),m_array);
  if(!m_a) return 0;
  ob->SetMoney(m_a);
  return 1;
}
/*---------------------------------------------------------------------------*/
varargs int PayValue(object who, int value, string *types)
{
  object ob;
  mixed *m_a;

  if(!who) return 0;
  if (value<=0) return !value;
  if(!(ob=present(MONEY_NAME,who))) return 0;
  if (({int})ob->QueryValue() < value) return 0;
  m_a = ({mixed *})MONEY_D->PayValue(value,({mixed})ob->QueryMoney(),types);
  if(!m_a) return 0;
  if(!pointerp(m_a)) return 0;
  ob->SetMoney(m_a[0]);
  return 1;
}
/*---------------------------------------------------------------------------*/
varargs mixed PayValue2(object who, int value, string *types)
{
  object ob;
  mixed *m_a;
  string *ret;

  if (value<0) return MONEY_NEGATIVE;
  if(!value) return ({"nothing",0});
  if(!(ob=present(MONEY_NAME,who))) return MONEY_NO_MONEY;
  if (({int})ob->QueryValue() < value) return MONEY_NOT_ENOUGH;
  m_a = ({mixed *})MONEY_D->PayValue(value,({mixed})ob->QueryMoney(),types);
  if(!m_a) return MONEY_CANT_PAY;
  if(!pointerp(m_a)) return MONEY_WRONG_RESULT;
  ob->SetMoney(m_a[0]);
  if(!({int})MONEY_D->QueryMoneyValue(m_a[1])) ret = ({0});
  else ret=({({string})MONEY_D->QueryMoneyString(m_a[1])});
  if (!({int})MONEY_D->QueryMoneyValue(m_a[2])) ret+=({0});
  else ret+=({({string})MONEY_D->QueryMoneyString(m_a[2])});
  return ret;
}
/*---------------------------------------------------------------------------*/
private object *get_previous_objects()
{
  int     i;
  object *ob;

  ob = ({});
  while(previous_object(i)) ob += ({previous_object(i++)});
  return ob;
}

varargs string PayValueString(object who, int value, string *types,
			      string extramsg, int width)
{
  mixed result;

  if(pointerp(result = PayValue2(who, value, types))) {
    if(!result[0] && !result[1]) return "Nothing happens.\n";
    return sprintf("%*=-s",width||79,
		   "You " +
		   (result[0]?"paid " + result[0] +
		    (extramsg?" " + extramsg:"") +
		    (result[1]?" and ":""):"") +
		   (result[1]?"got " + result[1] + " back":"") +
		   (result[0] || !extramsg?"":" " + extramsg)
		   + ".\n");
  }
  switch(result) {
  case MONEY_NEGATIVE:
    notify_fail("You can't pay a negative amount.\n");
    return 0;
  case MONEY_NO_MONEY:
    notify_fail("You have no money.\n");
    return 0;
  case MONEY_NOT_ENOUGH:
    notify_fail("You have not enough money.\n");
    return 0;
  case MONEY_CANT_PAY:
    notify_fail("You don't have enough money of the right type.\n");
    return 0;
  default:
    notify_fail("An internal error happened.\n");
    log_file(MONEY_ERRORLOG,sprintf("\n--\n%s: PayValue2() returned\
 MONEY_WRONG_RESULT\nPrevious objects:\n%s\n",
				    ctime(time()),
				    implode(map(get_previous_objects(),
                                                      #'object_name),"\n")));
    return 0;
  } /* end switch() */
  return 0;
}

varargs mapping CreateMoneyFromValue(int value, string *types)
{
  return ({mapping})MONEY_D->CreateMoney(value, types);
}

private mixed parse_single(string money, mapping all_money)
{
  int amnt;
  string coin;

  if(2 != sscanf(money, "%d %s", amnt, coin))
    return 0;

  if(amnt < 0)
    return 0;


  if(!all_money[coin] && !(coin = ({string})MONEY_D->PresentMoney(coin, all_money)))
    return 0;

  return ({coin, amnt});
}

private int true()
{
  return 1;
}

mapping CreateMoneyFromString(string str)
{
  int     i;
  mixed  *parts;
  mapping all_money;

  if(!str)
    return 0;

  all_money = map_indices(({mapping})MONEY_D->QueryCoinTypes(),#'true /*'*/);
  parts = regexplode(str, " *(,|and ) *");
  for(i = 1; i < sizeof(parts); ++i)
    parts = parts[0..i-1] + parts[i+1..];
  parts = map(parts, #'parse_single,all_money);
  if(member(parts, 0) != -1)
    return 0;

  parts = transpose_array(parts);

  return mkmapping(parts[0],parts[1]);
}

/*---------------------------------------------------------------------------*/
int remove() { destruct(this_object()); return 1; }
/*---------------------------------------------------------------------------*/
