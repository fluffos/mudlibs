/*--------------------------------------------------------------------------
 * DAEMONPATH "money_d" -- The money daemon
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

/*  This object keeps track of how much each type of coin is worth
 *  So be nice to it ;-)
 */

#include <money.h>

#define MIN(x,y) ((x) > (y) ? (y) : (x))
#define DEF_VALUE 0
#define DEF_WEIGHT 8
#define COINS QueryCoinTypes()

mapping materials;
mapping cointypes;
mapping domains;
string *standard;

nosave int count;

/* To be able to 'update' the money_demon */

int remove() { destruct(this_object()); return 1; }

/* We reload the actual configurations of the money demon */

void create()
{
  int flag;

  seteuid(getuid());
  restore_object(MONEY_CONFIG);
  /* If we don't have any configurations, we set the money to standard
   * values */

  if(!materials) {
    materials=([N_COPPER: V_COPPER;0;0,
	        N_SILVER: V_SILVER;0;0,
	        N_GOLD:   V_GOLD  ;0;0,
	        N_PLATIN: V_PLATIN;0;0]);
    flag = 1;
  }
  if(!cointypes) {
    cointypes = (["platinum":(["platinum":64]);"coin";"coins";"pc";
		  "No special description for the platinum coin.\n",
		  "gold":(["gold":32]);"coin";"coins";"gc";
		  "No special description for the gold coin.\n",
		  "silver":(["silver":32]);"coin";"coins";"sc";
		  "No special description for the silver coin.\n",
		  "copper":(["copper":8]);"coin";"coins";"cc";
		  "No special description for the copper coin.\n"]);
    flag = 1;
  }
  if(!standard) {
    standard = ({"platinum","gold","silver","copper"});
    flag = 1;
  }
  if(!domains) {
    domains = ([]);
    flag = 1;
  }
  if(flag) save_object(MONEY_CONFIG);
}

/* Just to export the current settings */

mapping       QueryDomains()   { return copy(domains); }
mapping       QueryMaterials() { return copy(materials); }
string       *QueryStandard()  { return ({}) + standard; }
varargs mixed QueryCoinTypes(string str)
{
  if(!str) return copy(cointypes);
  return (domains||([]))[str];
}

/* Tells us, how much the special type of coins is worth */

int QueryCoinValue(string type)
{
  int i, val;
  mixed coin;

  coin = COINS[type,MONEY_CONTENTS];
  if(!coin) return DEF_VALUE;
  for(i = sizeof(m_indices(coin));i--;)
    val += coin[m_indices(coin)[i]] * QueryMaterials()[m_indices(coin)[i]] / 32;
  /* Looks for every material in the coin for the value in the QueryMaterials()-
   * mapping */
  return val;
}

/* It returns the data entry of the mapping */

private mixed not_zero(mixed ind, mixed map) { return map[ind]; }

/* This function removes every empty entry from the mapping */

mixed CleanMoney(mixed money)
{
  if(pointerp(money)) money = ({mixed})MONEY->MakeMapping(money);
  if(!money) return 0;
  return filter_indices(money,#'not_zero,money /*'*/);
}

/* Tells us the weight of a coin of the specified type */

int QueryCoinWeight(string type)
{
  int i, val;
  mixed coin;

  coin = COINS[type,MONEY_CONTENTS];
  if(!coin) return DEF_VALUE;
  for(i = sizeof(m_indices(coin));i--;)
    val += coin[m_indices(coin)[i]];
  /* Adds for every material in the coin the weight */
  return val?val:DEF_WEIGHT;
  /* A worthless coin has a default weight of 1/4 oz */
}

/* Just an useful subroutine for the next function */

private void add_value(string type, int cnt, int val)
{
  val += QueryCoinValue(type) * cnt;
}

/* Gives us the value of the money mapping (or the oldstyled money array) */

varargs int QueryMoneyValue(mixed m_array, string *types)
{
  int val;

  if(!m_array) return 0;
  if(pointerp(m_array)) m_array = ({mixed})MONEY->MakeMapping(m_array);
  else if(!mappingp(m_array)) return 0;
  if(pointerp(types) && sizeof(types))
    m_array = filter_indices(m_array,
      lambda(({'type,'types}),({#'!=,-1,({#'member,'types,'type})})),
      types);
  /* we filter the money mapping and throw out the not interresting coins */

  walk_mapping(m_array,#'add_value /*'*/,&val);
  /* We add the value of every coin type */
  return val;
}

/* Just an useful subroutine for the next function */

private void add_weight(string type, int cnt, int val)
{
  val += QueryCoinWeight(type) * cnt;
}

/* Gives us the weight of the money mapping (or the oldstyled money array) */

int QueryMoneyWeight(mixed m_array)
{
  int val;

  if(!m_array) return 0;
  if(pointerp(m_array)) m_array = ({mixed})MONEY->MakeMapping(m_array);
  else if(!mappingp(m_array)) return 0;
  walk_mapping(m_array,#'add_weight /*'*/, &val);
  /* We add the weight of every coin type */
  return val;
}

/* Just an useful subroutine for the next function */

private int add_cnt(string dummy, int a, int b) { return b += a; }

/* Returns the number of the coins in the given mapping */

int QueryCoinNumber(mixed money)
{
  int val;

  if(!mappingp(money)) return 0;
  walk_mapping(money,#'add_cnt /*'*/,&val);
  /* We add the number of the coins */
  return val;
}

/* It compares the values of the different coin types */

private int compare_value(string typ1, string typ2)
{
  return QueryCoinValue(typ1) < QueryCoinValue(typ2);
}

private int compare_value_backward(string typ1, string typ2)
{
  return compare_value(typ2, typ1);
}

/* This function has some other rules to determine the order of the
 * coin types. Coins without the "coin" extension have higher priority
 * than the other ones */

private int compare_coin(string typ1, string typ2)
{
  if(COINS[typ1,MONEY_COINTYPE]) {
    if(COINS[typ2,MONEY_COINTYPE]) {
      if(COINS[typ1,MONEY_COINTYPE] < COINS[typ2,MONEY_COINTYPE]) return 0;
      if(COINS[typ1,MONEY_COINTYPE] > COINS[typ2,MONEY_COINTYPE]) return 1;
      return compare_value(typ1, typ2);
    }
    return 1;
  }
  if(COINS[typ2,MONEY_COINTYPE]) return 0;
  return compare_value(typ1, typ2);
}

/* This function filters all coins with one of the given coin types */

private int coin_type(string coin, string type)
{
  return COINS[coin,MONEY_COINTYPE] == type;
}

/* This function converts the money mapping into a nice string */

varargs string QueryMoneyString(mixed m_array, int flag)
{
  string *types,*sh;
  int    i,j;
  mixed tmp;

  if(!m_array) return "0 copper coins";
  if(pointerp(m_array)) m_array = ({mixed})MONEY->MakeMapping(m_array);
  else if(!mappingp(m_array)) return "0 copper coins";

  m_array = CleanMoney(m_array);
  if(!sizeof(types = sort_array(m_indices(m_array),#'compare_coin /*'*/)))
    return "0 copper coins";
  /* Checking for trivial values */

  for(sh = ({}), i = 0, j = sizeof(types); i<j; ++i) {

    /* First we look, if the last money has the same coin type than this one.
     * If not, we can add the cointype to the last coins. This is necessary
     * to create something like 'x silver, y copper coins' where 'coins'
     * is the coin type (also possible: 'chip' or something) */

    if(i && tmp != COINS[types[i],MONEY_COINTYPE]) {
      if(tmp)
        sh = sh[0..<2] + ({sh[<1] + " " +
          ((QueryCoinNumber(filter_indices(m_array,#'coin_type /*'*/,tmp)) == 1)?
            COINS[types[i-1],MONEY_COINTYPE]:
	      (COINS[types[i-1],MONEY_PLURAL]||types[0]))});
        /* we look, if this coin type has its special plural */
    }
    tmp = COINS[types[i],MONEY_COINTYPE];
    /* we register the last accessed coin type */

    sh += ({"" + ((flag && flag <= m_array[types[i]])?
                   (2*flag <= m_array[types[i]]?"lots of":"some"):
                   m_array[types[i]])
            + " " +
            (COINS[types[i],MONEY_COINTYPE]?types[i]:
            ((m_array[types[i]]==1)?types[i]:
	     (COINS[types[i],MONEY_PLURAL]||types[i])))});
    /* we add the coin 'id' (e.g. 'platinum' or 'penny') and look for
     * special plural forms ('penny'->'pence') */
  }
  if(sizeof(sh) == 1)
    return sh[0] + (COINS[types[0],MONEY_COINTYPE]?" " +
           ((m_array[types[0]] == 1)?COINS[types[0],MONEY_COINTYPE]:
            COINS[types[0],MONEY_PLURAL]||types[0]):"");
  return implode(sh[0..<2],", ") + " and " + sh[<1] +
         (COINS[types[<1],MONEY_COINTYPE]?" " +
          ((QueryCoinNumber(filter_indices(m_array,#'coin_type /*'*/,tmp)) == 1)?
           COINS[types[<1],MONEY_COINTYPE]:
           (COINS[types[<1],MONEY_PLURAL]||types[<1])):
          "");
  /* we insert the 'and' before the last cointype, if neccessary and add the
   * missing 'coin' or 'chip' or something similar at the end */
}

/* Tries to find a short description for the money */

private string short_string(string type, mixed money)
{
  return money[type] + (COINS[type,MONEY_SHORT]||type[0..1]);
}

/* This function tries to create a smaller version of the money
 * string (specially for price announcements and such) */

string QueryMoneyShort(mixed money)
{
  if(!money) return "0cc";
  if(pointerp(money)) money = ({mixed})MONEY->MakeMapping(money);
  else if(!mappingp(money)) return "0cc";

  money = CleanMoney(money);
  if(!sizeof(money)) return "0cc";
  return implode(map(sort_array(m_indices(money),#'compare_coin /*'*/),
                           #'short_string /*'*/,money)," ");
}

varargs string QueryMoneyLong(mixed money, int flag)
{
  string type;

  if(sizeof(money) != 1)
    return "You see " + QueryMoneyString(money, flag) + ".\n";
  if(COINS[type = m_indices(money)[0],MONEY_LONG])
    return COINS[type,MONEY_LONG];
  return "You see " + QueryMoneyString(money, flag) + ".\n";
}

/* This is only a small function to support the next one */

private int add_next_count(string type, mixed other)
{
  if(!pointerp(other)) return 0;
  if(!QueryCoinValue(type)) return 0;
  other[1][type] = (other[0]/QueryCoinValue(type));
  other[0] %= QueryCoinValue(type);
  return 0;
}

/* This function creates a money mapping which has the worth of
 * the given value and contains only the given money types or
 * (if not given) the standard money types */

varargs mixed CreateMoney(int value, string *types)
{
  mixed tmp;

  if (!value) return ([]);
  if(!types || !sizeof(types)) types = QueryStandard();
  types = sort_array(types,#'compare_value);
  if((({0}) + (map(types,#'QueryCoinValue)-({0})))[<1] != 1)
    types += ({"copper"});
  /* We need a coin with the value of 1 it to fill up the remaining CU */
  tmp = ({value,([])});
  filter(types,#'add_next_count /*'*/,&tmp);
  return CleanMoney(tmp[1]);
}

/* Creates a string for the given value */

varargs string QueryValueString(int value, string *types)
{
  return QueryMoneyString(CreateMoney(value, types));
}

/* Creates a very short string for the given value */

varargs string QueryValueShort(int value, string *types)
{
  return QueryMoneyShort(CreateMoney(value, types));
}

/* This function adds the given amount of coins of the given type to the
 * given money mapping */

private void add_single_value(string type, int amount, mixed money)
{
  money[type] += amount;
}

/* This function calculates, which money array the player has to
 * give to pay the given value and which money array he would get
 * back */

varargs mixed PayValue(int value, mixed money, string *types)
{
  mixed retval,change,tmp;
  int i,j,num;

  if(!types || !sizeof(types)) types = QueryStandard();
  types = sort_array(types,#'compare_value /*'*/);
  if((map(types,#'QueryCoinValue /*'*/)-({0}))[<1] != 1)
    types += ({"copper"});

  retval=([]);
  if(pointerp(money)) money = ({mixed})MONEY->MakeMapping(money);
  if(!mappingp(money)) return 0;
  money = copy(money);
  tmp = filter_indices(money,
    lambda(({'type,'types}),({#'!=,-1,({#'member,'types,'type})})),
    types);
  /* We filter the given money to receive the part which matches the given
   * money types */

  if(QueryMoneyValue(tmp) < value) return 0;

  /* We now know, the money contains enough coins of the given types to pay
   * the given value */

  for (i=sizeof(types); i--;) {
    if(!QueryCoinValue(types[i])) continue;
    if(value < QueryCoinValue(types[i])) break;
    num=MIN(value/QueryCoinValue(types[i]),money[types[i]]);
    value -= num * QueryCoinValue(types[i]);
    money[types[i]] -= num;
    retval[types[i]] = num;
    if (!value) return ({CleanMoney(money),CleanMoney(retval),0});
  }

  /* Now we have some amount left, we are searching for the next type of
   * coins which is still aviable in money and is more worth than the
   * leftover */

  for(i=sizeof(types); i--; ) {
    if(money[types[i]] && (QueryCoinValue(types[i]) >= value)) {
      ++retval[types[i]];
      --money[types[i]];
      value -= QueryCoinValue(types[i]);
      break;
    }
  }
  /* Now we maybe can return some smaller coins */

  for(j = sizeof(types), ++i; i < j; ++i) {
    if(!QueryCoinValue(types[i])) continue;
    num=MIN((-value)/QueryCoinValue(types[i]),retval[types[i]]);
    value += num * QueryCoinValue(types[i]);
    retval[types[i]] -= num;
    money[types[i]] += num;
    if (!value) return ({CleanMoney(money),CleanMoney(retval),0});
    /* Normally value can't be zero now! */
  }

  /* So, now we have a money mapping which contains the littlest possible
   * value which is realizable with the 'money' variable, and which has a
   * greater value than 'value'
   *
   * We add the change to the money map and return */

  change = CreateMoney(-value,types);
  walk_mapping(change,#'add_single_value /*'*/,&money);
  return ({CleanMoney(money),CleanMoney(retval),change});
}

/* This function just decreases the amount of a specified type of coins */

private void pay_single_type(string type, int amount, mixed special)
{
  if(!pointerp(special)) return;
  if((special[0][type] -= amount) < 0) special[1] = 1;
}

/* This function remains for compatibility. I don't think we need it. */

mapping PayMoney(mixed money, mixed to_pay)
{
  mixed tmp;

  if(!mappingp(money) && !(money = ({mixed})MONEY->MakeMapping(money)) &&
     !mappingp(to_pay)) return 0;
  tmp = ({copy(money),0});
  walk_mapping(to_pay,#'pay_single_type /*'*/,&tmp);
  return tmp[1]?0:tmp[0];
}

/* This function checks, if we have money of the given type in the given
 * money map and returns the associated name */

private void add_vario(string type,
                       mixed  contents,
                       mixed  singular,
                       mixed  plural,
                       mixed  short,
                       mixed  long,
                       mixed  filter)
{
  string str;

  if(str = COINS[type,MONEY_COINTYPE]) {
    filter[type + " " + str] = type;
    filter[type + " " + COINS[type,MONEY_PLURAL]] = type;
  } else {
    filter[type] = type;
    if(COINS[type,MONEY_PLURAL])
      filter[COINS[type,MONEY_PLURAL]] = type;
  }
  filter[COINS[type,MONEY_SHORT] || type[0..1]] = type;
  /* For adding things like '10 cc' */
}

string PresentMoney(string type, mixed money)
{
  mixed filter;

  filter = ([]);
  walk_mapping(COINS,#'add_vario /*'*/,&filter);
  return filter[type];
}

/* This function checks, if we have money of the give 'cointype'
 * e.g. 'chip', 'coin' etc. */

private void add_type(string type, int amnt, mixed filter)
{
  if(type == filter[0]) filter[1] += ({type});
  else if(COINS[type,MONEY_COINTYPE] == filter[0]) filter[1] += ({type});
  else if(COINS[type,MONEY_PLURAL] == filter[0]) filter[1] += ({type});
}

mixed PresentTypes(string type, mixed money)
{
  mixed *filter;

  filter = ({type,({})});
  if(pointerp(money)) money = ({mixed})MONEY->MakeMapping(money);
  if(!money) return 0;
  if(!mappingp(money)) return 0;
  walk_mapping(money,#'add_type /*'*/,&filter);
  return sort_array(filter[1],#'compare_value_backward /*'*/);
}

/* This function checks, if the given string means a singular coin.
 * If yes, it returns the money type. If not, it returns 0. */

private void add_singular(string type,
                          mixed  contents,
                          mixed  singular,
                          mixed  plural,
                          mixed  short,
                          mixed  long,
                          mixed  filter)
{
  string str;

  if(str = COINS[type,MONEY_COINTYPE]) filter[type + " " + str] = type;
  else filter[type] = type;
}

private int check_singular(string type, string str)
{
  return str == COINS[type,MONEY_COINTYPE];
}

string SingularCoin(string str, mixed money)
{
  mixed  filter;
  string *coins;

  filter = ([]);
  walk_mapping(COINS,#'add_singular /*'*/,&filter);
  if(pointerp(money)) money = ({mixed})MONEY->MakeMapping(money);
  if(!money) return 0;
  if(!mappingp(money)) return 0;
  if(money[filter[str]]) return filter[str]; /* First guess */
  coins = filter(sort_array(m_indices(money),#'compare_value /*'*/),
                       #'check_singular /*'*/,str);
  return sizeof(coins)?coins[<1]:0;
}
