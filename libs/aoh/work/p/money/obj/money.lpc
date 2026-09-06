/*--------------------------------------------------------------------------
 * /p/daemons/obj/money -- The money object
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <daemons.h>
#include <moving.h>
#include <money.h>
#include <properties.h>
#include <classes.h>
#include <secure/wizlevels.h>

#define VERSION "2.1b7"

nosave object too_much, new_env;

inherit "/std/base";
inherit "/std/thing/moving";
inherit "/p/money/obj/money/description";
inherit "/p/money/obj/money/smallfuns";

varargs object NewMoneyObject(mixed amnt, string type);

public int clean_up(int i) { return moving::clean_up(i); }

public void create()
{
  ::create();
  if(!is_clone()) return;
  seteuid(getuid());
  AddClassId(C_MONEY);
  money = ([]);
  Set(P_NOBUY, "Are you trying to exchange currencies?");
}

public void init()
{
  add_action("do_help","help");
  if(IS_WIZARD(this_player())) add_action("mmm","money");
}

public varargs int remove()
{
  money_rearrange(1);
  if(!this_object()) return 1;
  MONEYLOG_D->remove_money("remove",QueryValue());
  return ::remove();
}

string QueryHelpMsg()
{
  return "Money values:\n" +
	  implode(map(sort_array(m_indices(IS_WIZARD(this_player())?
						 ({mixed})MONEY_DEMON->QueryCoinTypes():
						 money)
				       ,#'compare_value)
			    ,#'valuestring),"\n") + "\n";
}

int do_help(string str)
{
  if(!str || (present(str) != this_object())) return 0;

  if(str == "money" || str == MONEY_NAME) {
    write(QueryHelpMsg());
    return 1;
  }
  notify_fail(QueryHelpMsg());
  return 0;
}

string QueryVersion() { return VERSION; }

/* Used in subid */

private void get_types(string type, mixed m_array)
{
  if(m_array[1] <= 0) return;
  if(money[type] > m_array[1]) {
    m_array[0][type] = m_array[1];
    m_array[1] = 0;
  } else {
    m_array[0][type] = money[type];
    m_array[1] -= money[type];
  }
}

/* subid() gets the id of a single money type (without 'and' or ',') and tries
 * to parse it.
 */

public mapping subid(string str)
{
  mixed  count;
  string tmp, *types, *strs;
  mixed  m_array;

  if(!str || str == "") return ([]);
  str = implode(strs = explode(str," ")-({""})," ");
  if(tmp = ({string})MONEY_DEMON->SingularCoin(str,money) ||
     (QueryRemaining() &&
      tmp = ({string})MONEY_DEMON->SingularCoin(str, ({mixed})QueryRemaining()->QueryMoney())))
    return ([tmp:1]);
  /* First we look, if the string means a single coin */

  tmp = 0;
  if(strs[0] == "all") {
    tmp = str[4..];
    count = -1;
    /* Then we look if the string means all coins of a specified type */
  } else {
    count = atoi(strs[0]);
    if(!intp(count)) {
      count = -1;
      tmp = str;
    } else {
      if (count <= 0)
	return 0;
      if(sizeof(strs) > 1)
	tmp = implode(strs[1..], " ");
    }
    /* Last possibility: It means a specified amount */
  }
  if(!(str = ({string})MONEY_DEMON->PresentMoney(tmp,money))) {
    if(!sizeof(types = ({string *})MONEY_DEMON->PresentTypes(tmp,money))) return 0;
    if(count == -1) {
      m_array = ([]);
      filter(types,lambda(({'type}),({#'= /*'*/,({#'[ /*'*/,m_array,'type}),
						({#'[ /*'*/,money,'type /*'*/})})));
    } else {
      m_array = ({([]),count});
      filter(types,#'get_types /*'*/,&m_array);
      if(m_array[1]) return 0;
      m_array = m_array[0];
    }
  } else {
    if(count > money[str]) return 0;
    m_array = ([str:(count == -1)?money[str]:count]);
  }
  m_array = ({mixed})MONEY_DEMON->CleanMoney(m_array);
  if(!sizeof(m_array)) return 0;
  return m_array;
}

/* The id() has to parse the given string and to split the money, if
 * necessary */

public int id(string str)
{
  mapping m_array;
  //  object  new_money;

  if(!str) return 0;
  if(str == "money" || str == MONEY_NAME) {
    if (QueryRemaining()) {
      remove_call_out("money_rearrange");
      insert_other_money(QueryRemaining());
      SetRemaining(0);
    }
    return 1;
  }

  /* Check, if there is money in the environment of the player.
   * So you use the money in the environment by default */
/*
   if(query_verb() != "drop" && this_player() == environment() &&
     environment(this_player()) &&
     (new_money = present(str,environment(this_player()))) &&
     new_money->id(str)) return 0;
 */
  // Parse the (remaining) money for the amount of coins demanded.
  if (QueryRemaining())
    m_array = ({mapping})QueryRemaining()->subid(str);
  else
    m_array = subid(str);
  if (!m_array || !sizeof(m_array = ({mapping})MONEY_DEMON->CleanMoney(m_array)))
    return 0;

  if (QueryRemaining()) {
    walk_mapping(m_array, #'subtract_from_remaining /*'*/);
    AdjustMoney(m_array);
  } else {
    walk_mapping(money,#'subtract_from_value /*'*/,&m_array);
    if(m_array && sizeof(m_array))
      SetRemaining(NewMoneyObject(m_array));
  }
  if(this_player())
    this_player()->RegisterCmdFun("money_rearrange",0);
  else
    call_out("money_rearrange",1);
  SetMoveTo(environment());
  return 1;
}

/* This is the fun that does the whole work inside the money */

varargs int AdjustMoney2(string type, int amnt, int flag)
{
  int    wei;
  object oldenv;

  if((wei = ({int})MONEY_DEMON->QueryCoinWeight(type)) && environment()) {
    /* We have to take care about the moneyweight! */
    if(({int})environment()->MayAddWeight(wei * amnt))
      environment()->AddIntWeight(wei * amnt);
    /* We can add it without problems, ok */
    else {
      int small_amount;

      if(!(new_env = find_environment(oldenv = environment(),wei * amnt))) {
	object *prev;
	int i;

	prev = ({});
	while(previous_object(i)) prev += ({previous_object(i++)});
	log_file(MONEY_ERRORLOG,
		 sprintf("--\n%s: No room for money. Value: %d Command: %s\n\
List of previous objects:\n%s\n",
			 ctime(time()),
			 amnt * ({int})MONEY_DEMON->QueryCoinValue(type),
			 query_verb() || "",
			 implode(map(prev,#'object_name),"\n")));
	return 0;
      } /* We don't find any environment we can put the money into.
	 * Log it as an error. */

      if(small_amount = get_max_number(wei)) {
	amnt -= small_amount;
	money[type] += small_amount;
	environment()->AddIntWeight(small_amount * wei);
	/* We add the amount of coins we can carry and correct the weight */
      }

      /* We try to find out the amount of coins we can still carry */
      if(!too_much) {
        /* Are we already saving the money? */
        too_much = clone_object(MONEY);
        too_much->AdjustMoney(money);
        environment()->AddIntWeight(-QueryWeight());
        money = ([type: amnt]);
        /* Save the current money in a new object and move the new one into
         * ourself */
      } else
        money[type] += amnt;
      /* We are already storing the old money, so just add the new */

      if(!flag) /* We aren't called by AdjustMoney() */
        move_too_much(&too_much, new_env, oldenv);
      /* We add the weight we just set by changing the money mapping */
      oldenv->AddIntWeight(wei * amnt);
      return 1;
    }
  }
  if(money[type] < -amnt) return 0;
  money[type] += amnt;
  if(!money[type]) money = m_delete(money,type); /* Erasing empty coins */

  MONEYLOG_D->new_money("AdjustMoney2",
			  amnt * ({int})MONEY_DEMON->QueryCoinValue(type));
  return 1;
}

varargs int AdjustMoney(mixed amnt, string type)
{
  if(!amnt && !type) return 0;
  /* Oops? No arguments? */

  if(pointerp(amnt))
    amnt = MakeMapping(amnt);
  /* First convert them to a mapping! */

  if(mappingp(amnt)) {
    walk_mapping(amnt,#'AdjustMoney2 /*'*/,1);
    if(too_much) move_too_much(&too_much, new_env, environment());
    return 1;
  }
  /* Ah! A moneymapping! */

  if(stringp(amnt) && intp(type))
    return AdjustMoney2(amnt, (int)type);

  if(!stringp(type))
    return 0;
  /* No string? Sorry! */

  if(!amnt) return 1;
  /* No amount of coins? Ready! */

  return AdjustMoney2(type, amnt);
}

/* The "money <type> <amount>" could be a 'xalias' *shrug* */

public int mmm(string str)
{
  int    amnt;
  string type;

  if(!str || environment() != this_interactive()) return 0;
  if(str == "update")
    return update_money();
  if(2 != sscanf(str, "%s %d", type, amnt)) {
    notify_fail("** Usage: money <kind> <amount> to create new money\n\
          money update          to update the money objects\n");
    return 0;
  }
  if(!({int})MONEY_DEMON->QueryCoinValue(type)) {
    notify_fail("** Money without value.\n");
    return 0;
  }
  if(!amnt) {
    write("Ok.\n");
    return 1;
  }
  if(!AdjustMoney2(type, amnt)) {
    if(amnt < 0)
      notify_fail("You haven't enough " +
		  (({string})MONEY_DEMON->QueryMoneyString(([type:2])))[2..] + ".\n");
    else
      notify_fail("Strange things happened. Ask Sique to fix it.\n");
    return 0;
  }
  write("Ok.\n");
  return 1;
}

/* Gets the difference between the given value and the stored value */

private int new_value(mixed type, mixed mon)
{
  if(!stringp(type) || !mappingp(mon)) return 0;
  return mon[type] - money[type];
}

/* SetMoney() only for compatibility */

varargs int SetMoney(mixed newmoney, string type)
{
  MONEYLOG_D->remove_money("SetMoney",QueryValue());
  if(intp(newmoney) && stringp(type))
    newmoney = ([type:newmoney]);
  if(!mappingp(newmoney))
    return 0;
  if(money) {
    AdjustMoney(map_indices(money,#'new_value /*'*/, newmoney));
    newmoney = map_indices(newmoney,#'new_value /*'*/, newmoney);
  }

  return AdjustMoney(newmoney);
}

/* NewMoneyObject() clones a new money object, adjusts its value and the value
 * of this_object(), and returns it. */

varargs object NewMoneyObject(mixed amnt, string type)
{
  object new;
  mixed  tmp;

  if(intp(amnt)) {
    if(amnt < 0) return 0;
    if(money[type] < amnt) return 0;
    money[type] -= amnt;
    if(environment())
      environment()->AddIntWeight(- ({int})MONEY_DEMON->QueryCoinWeight(type) * amnt);
  } else {
    if(pointerp(amnt)) amnt = MakeMapping(amnt);
    if(!mappingp(amnt)) return 0;
    tmp = ({money + ([]),0});
    walk_mapping(amnt,#'subtract_value /*'*/,&tmp);
    if(tmp[1]) return 0;
    money = tmp[0];
    if(environment())
      environment()->AddIntWeight(- ({int})MONEY_DEMON->QueryMoneyWeight(amnt));
  }
  new = clone_object(MONEY);
  new->AdjustMoney(amnt, type);
  MONEYLOG_D->move_money("NewMoneyObject",({int})new->QueryValue());
  return new;
}

/* The moving... maybe the most complicate thing in the moneyobject,
 * at least it causes several inconsistencies :) */

varargs int move(mixed dest, int method, mixed extra)
{
  int    res;
  object oldenv;

  oldenv = environment();
  if(this_player()) this_player()->RegisterCmdFun("money_rearrange",0);
  else call_out("money_rearrange",0);
  /* We try to let the player do the money_rearrange() call.
   * Otherwise we need an asynchronous call in some cases */

  if((res = ::move(dest, method, extra)) == ME_OK)
    MONEYLOG_D->move_money("move",QueryValue(),oldenv,environment());

  return res;
}
