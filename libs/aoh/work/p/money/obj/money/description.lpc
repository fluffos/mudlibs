/*--------------------------------------------------------------------------
 * /p/money/obj/money/description -- part of the money object
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * Description of the money
 */

#include <money.h>
#include <secure/wizlevels.h>
inherit "std/thing/description";

nosave mixed  money;

string QueryVersion() { return 0; }

/* Converts an oldstyled MoneyArray into a mapping */

mixed MakeMapping(mixed *arr)
{
  int   i,j;
  mixed map;

  if(!arr) return 0;
  map = ([]);
  for(i=0, j=sizeof(arr);i<j;i+=2)
    map[arr[i],0] = arr[i+1];
  return map;
}

/* Remains from the old money... */

string valuestring(string type)
{
  string str;
  mapping m = ({mapping})MONEY_D->QueryCoinTypes();

  return sprintf("%-24s- %5i CU",
		 ((str = m[type,MONEY_COINTYPE])?
		  type + " " + str:type) + " [" +
		 ((str = m[type,MONEY_SHORT])?
		  str:type[0..1]) + "]",
                 ({int})MONEY_D->QueryCoinValue(type));
}

/* Converts a mapping into an oldstyled moneyarray */

mixed MakeMoneyArray(mixed map)
{
  int   i,j;
  mixed arr;
  mixed ind;

  if(!mappingp(map)) return 0;
  arr = ({});
  for(i = 0, j = sizeof(ind = m_indices(map));i<j;++i)
    arr += ({ind[i],map[ind[i]]});
  return arr;
}

object QueryMoneyObject() { return this_object(); }

int SetWeight(mixed arg) { return 0; }
/* The weight is calculated from the amount of coins, you can't set it! */

varargs string QuerySmell()
{
  switch(QueryValue()) {
  case 0..100: return "It doesn't smell.\n";
  case 101..1000: return "It smells a little bit.\n";
  case 1001..10000: return "It smells very strong.\n";
  case 10001..100000: return "It stinks.\n";
  case 100001..1000000: return "It stinks very strongly.\n";
  default: return
    "It fills the air with the terrible smell of capitalism and the unholy\n\
greed for richness.\n";
  }
  return
  "It fills the air with the terrible smell of capitalism and the unholy\n\
greed for richness.\n";
}

int SetValue(mixed arg) { return 0; }
/* The value is determined by the variable money, so you can't set it */

string SetShort(mixed arg) { return 0; }
/* The short is determined by the carried money, so you can't set it */

/* I hope, there are no objects left which need the oldstyled money
 * arrays
 * mixed *QueryMoney() { return MakeMoneyArray(money); }
 */

mixed QueryMoney() { return copy(money); }

mixed QueryMoneyMap()
{
  log_file(MONEY_ERRORLOG,sprintf("--\n%s: QueryMoneyMap() called by %O\n",
				  ctime(time()),previous_object()));
  return copy(money);
}

mixed QueryAutoObject()
{
  return (money && sizeof(m_indices(money)))?
	({QueryVersion(),copy(money)}):0;
}

mixed SetAutoObject(mixed arr)
{
  int oldval, new_version;

  oldval = QueryValue();
  if(pointerp(arr)) {
    if(sizeof(arr) > 1) {
      if(intp(arr[1])) {
	new_version = 1;
	money = MakeMapping(arr);
      } else {
	if(!mappingp(arr[1])) return 0;
	if(arr[0] != QueryVersion())
	  new_version = 1;
	money = arr[1];
      }
    }
  } else {
    new_version = 1;
    money = arr;
  }
  if(new_version && IS_IMMORTAL(this_player()))
    tell_object(this_player(),
		sprintf("New version of money: %s\n",QueryVersion()));
  MONEYLOG_D->new_money("SetAutoObject",QueryValue()-oldval);
  return money;
}

int QueryWeight()
{
  return ({int})MONEY_D->QueryMoneyWeight(copy(money));
}

varargs string Smell() {
  if(!money || !sizeof(money)) return "You smell nothing.\n";
  if(this_player() && environment() != this_player() &&
     environment() != environment(this_player()) &&
     lower_case(({string})this_player()->QueryGuild()||"") != "thief" &&
     ({string})this_player()->QueryRace() != "dwarf")
    return "You smell nothing.\n";
  return QuerySmell();
}

varargs int QueryValue()
{
  int i,j,val;
  string *types;

  if(!money || !sizeof(types = m_indices(money))) return 0;
  /* Empty? We are worthless :)! */

  for(i =0, j = sizeof(types); i < j; ++i)
    val += ({int})MONEY_D->QueryCoinValue(types[i]) * money[types[i]];
  return val;
}

/* returns the number of the coins */

int QueryCoinNumber()
{
  int i,j,num;
  string *types;

  if(!money || !sizeof(types = m_indices(money))) return 0;
  /* Empty? We have mo coins! */

  for(i =0, j = sizeof(types); i < j; ++i)
    num += money[types[i]];
  return num;
}

varargs string QueryShort()
{
  if(!money || !sizeof(money = ({mixed})MONEY_D->CleanMoney(money))) return 0;
  return ({int})(this_player()||previous_object())->QueryBrief()?
          ({string})MONEY_D->QueryMoneyShort(money,
		 (!this_player() || (this_player() == environment()))?0:
				       (({int})this_player()->QueryInt()+3)):
          ({string})MONEY_D->QueryMoneyString(money,
		 (!this_player() || (this_player() == environment()))?0:
		  (({int})this_player()->QueryInt()+3));
}

varargs string QueryLong()
{
  if(!money || !sizeof(money = ({mixed})MONEY_D->CleanMoney(money))) return 0;
  return ({string})MONEY_D->QueryMoneyLong(money,(this_player() == environment())?0:
				     (({int})this_player()->QueryInt()+3));
}
