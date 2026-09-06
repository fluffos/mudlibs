/*  -*- LPC -*-
 *
 * /std/pub should replace all pubs
 *
 * This file defines the functions
 *	AddDrink(string name | string *name,
 *		 int heal, int strength, int soak, int value,
 *		 string drinkmsg);
 *	AddFood(string name | string *name,
 *		int heal, int stuff, int value,
 *		string eatmsg);
 *	AddMenuItem(string name | string *name,
 *		int heal, int strength, int soak, int stuff, int value,
 *		string msg);
 *	SetDiscountFunc(string func_name);	[optional]
 *	SetMenuHeader(string menu_header);		[optional]
 *	SetMenuFooter(string menu_footer);		[optional]
 * These functions are documented in /doc/std/pub.
 * For values of heal, strength, soak and stuff, see /std/drink.c and
 * /std/food.c.
 * The pub does a value check so if you don't know what prices for drinks
 * or meals are allowed, give 0 as value. The item will then be priced in
 * the right fashion automagically.
 * If you use this pub you don't need to tell the AW of Health that you
 * have set up a new pub; the pub will do this by itself.
 *
 * For examples, see the files
 *	/d/archwiz/common/health/exroom2.c and
 *	/d/archwiz/common/health/exroom3.c
 */
#include <properties.h>
#include <money.h>
#include <health.h>

#define STDPUB		"/std/pub"
#define PUBLIST		"/log/PUBLIST"

inherit "/std/room";
inherit "/lib/string";
inherit MONEY_LIB;

/* declarations of some important functions: */
mixed  _test_menu(string item);
int    _serve_item(mixed *item, object pl);

string change_value;
string menu_header, menu_footer;
mixed *menu_list;
string menu;
nosave string mincoin;
nosave int    minvalue;

varargs void create()
{
  room::create();  /* calls the 'create' in /std/room.c */

  SetIntShort("generic pub");
  SetIntLong(
    "The wizard who created this room didn't change the generic long "
    "description.\n");
  AddRoomCmd("read", "_pread");
  AddRoomCmd(({"order", "buy"}), "_porder");
  menu_list = ({ });
  menu_header  = "";
  menu_footer  = "";
  change_value = "_do_pay";
}

/*---------------- Unpublic functions: ---------------------------*/

/**
 **   log into publist
 **/

int log_pub(string me)
{
  string list;

  if (file_size(PUBLIST) > 0)
  {
    list = read_file(PUBLIST);
    if (!sscanf(list,"%~s"+me+"%~s"))
      return write_file(PUBLIST,me+"\n");
  }
  else
    return write_file(PUBLIST,me+"\n");
}

/**
 **  Test the pub
 **/

mixed *query_menu() { return(menu_list); }


/*--------------------- Public functions: ---------------------------*/

/**
 **  Add any item to the menu.
 **/

private int sort_value(string type1, string type2)
{
  return ({int})MONEY_DEMON->QueryCoinValue(type1) >
    ({int})MONEY_DEMON->QueryCoinValue(type2);
}

varargs mixed AddMenuItem(mixed name, int heal, int strength, int soak,
		int stuff, int value, string msg)
{
  int    min_value, n, i;
  string s, *tmp;

  if (!name) return 0;

  min_value = MIN_FOOD_COST(soak,stuff,strength,heal,0);
  if (value < min_value)
    value = min_value;

  if (pointerp(name)) {
    s = name[0];
    n = sizeof(name);
    for (i = 0; i < n; i++)
      name[i] = lower_case(name[i]);
  }
  else if (stringp(name)) {
    s = name;
    name = lower_case(name);
  }
  else
    return 0;

  if(!menu) {
    mincoin =
      sort_array(sizeof(tmp =
			filter(QueryValuta(),
				     lambda(({'coin /*'*/}),
					    ({#'call_other /*'*/,
					      MONEY_DEMON,"QueryCoinValue",
      'coin /*'*/}))))?
	       tmp:({int})MONEY_DEMON->QueryStandard(),
               #'sort_value /*'*/)[0];
    minvalue = ({int})MONEY_DEMON->QueryCoinValue(mincoin);
    /* removed the Prices are in copper coins for now - Tune 07jun97
    menu = "(-- Prices are in " +
      MONEY_DEMON->QueryMoneyString(([mincoin:2]))[2..] + " --)\n";
    */
    menu = "";
  }
  value = minvalue*(value+minvalue-1)/minvalue;

  menu += ladjcut(capitalize(s),50)
    + radjcut(""+value/minvalue,7," ") + "\n";

  menu_list = menu_list + ({ ({name, heal, strength, soak, stuff,
			       value, msg}) });
  return s;
}

/*
 * Add a drink to the menu
 */
varargs mixed AddDrink(mixed name, int heal, int strength, int soak, int value,
		       string drink_msg)
{
  return AddMenuItem(name, heal, strength, soak, 0, value, drink_msg);
}

/*
 * Add some food to the menu
 */
varargs mixed AddFood(mixed name, int heal, int stuff,
		      int value, string eat_msg)
{
  return AddMenuItem(name, heal, 0, 0, stuff, value, eat_msg);
}

string SetDiscountFunc(string funcname) { return change_value = funcname; }
string QueryDiscountFunc(string funcname) { return change_value; }

string SetMenuHeader(string str) { return menu_header = str; }
string QueryMenuHeader() { return menu_header; }
string SetMenuFooter(string str) { return menu_footer = str; }
string QueryMenuFooter() { return menu_footer; }
string SetMenuStr(string str) { return SetMenuFooter(str); }
string QueryMenuStr() { return QueryMenuFooter(); }

/***** Functions defined by add_action() ******/

int _pread(string str)
{
  string tmp;
  if (str != "menu") return 0;
  tmp = QueryMenuHeader();
  if (tmp && sizeof(tmp))
    write(tmp);
  write(menu);
  tmp = QueryMenuFooter();
  if (tmp && sizeof(tmp))
    write(tmp);
  return 1;
}

public string QueryMenu()
{
  string tmp;
  tmp = QueryMenuHeader();
  tmp += menu;
  tmp += QueryMenuFooter();
  if(tmp && sizeof(tmp))
    return tmp;
  return "";
}

int _porder(string str)
{
  object ob;
  string stuff, name;
  mixed  *item;

  if (!str) {
    notify_fail("What do you want to buy?\n");
    return 0;
  }
  if (sscanf(str,"%s for %s",stuff,name) != 2) {
    stuff = str;
    name  = ({string})(this_player()->QueryName());
  }
  stuff = lower_case(stuff);
  name  = lower_case(name);

  if (item = _test_menu(stuff)) {
    if (name == "all") {
      ob = first_inventory(this_object());
      while (ob) {
	if (living(ob))
	  _serve_item(item,ob);
	ob = next_inventory(ob);
      }
    }
    else {
      ob = present(name);
      name = capitalize(name);
      if (!ob)
	return notify_fail(name + " is not here!\n"),0;
      else if (living(ob))
	_serve_item(item,ob);
      else
	return notify_fail("You can't offer something to "+name+"!\n"),0;
    }
    return 1;
  }

  notify_fail("Sorry, we don't serve that here.\n");
  return 0;
}

/***************** internal functions *******************/

/*
 * internal change value function does not change value :-)
 */
int _do_pay(int amount) { return amount; }

/*
 * this function determines if the article to a substantive is "a" or "an"
 * should be coded into some library
 */
string _article(string s)
{
  if (member("aeiou",lower_case(s)[0]) != -1)
    return("an");
  else
    return("a");
}

/*
 * test if ordered drink or food are availabe
 * return 0 for failure, entry in menu_list (i.e. array) for success
 */
mixed _test_menu(string item)
{
  int i, n, found;

  item  = lower_case(item);
  found = -1;
  n = sizeof(menu_list);
  i = 0;
  while (i < n && found < 0) {
    if (pointerp(menu_list[i][0]))
      found = member(menu_list[i][0], item);
    else if (item == menu_list[i][0])
      found = 0;
    i++;
  }
  i--;

  if (found >= 0)
    return menu_list[i];
  else
    return 0;
}

/*
 * Serve drink or food. If the player cannot consume the drink or food, he
 * still has to pay for it.
 */
int _serve_item(mixed *item, object pl)
{
  string name, *coins;
  int    heal, strength, soak, stuff, value, intox, psoak, pstuff;
  object ob;

  if (pointerp(item[0]))
    name = item[0][0];
  else
    name = item[0];
  heal     = item[1];
  strength = item[2];
  soak     = item[3];
  stuff    = item[4];
  value    = item[5];
  if (change_value)
    value = ({int})call_other(this_object(),change_value,value);
  if (QuerySomeonesValue(this_player(),coins = QueryValuta()) < value) {
    if (QuerySomeonesValue(this_player()) >= 2*value) {
      value *= 2;
      coins = 0;
   } else {
    write("You don't have enough money!\n");
    return 1;
    }
  }

  intox  = ({int})pl->Query(P_ALCOHOL);
  psoak  = ({int})pl->Query(P_DRINK);
  pstuff = ({int})pl->Query(P_FOOD);
  if (pl != this_player())
    tell_object(pl,({string})this_player()->QueryName() +
		" has bought " + _article(name) + " " + name +
		" for you!\n");
  /* player.c does not do write here anymore. But it cannot do atomic tests
   * on intoxication, soak and stuff together. So we still must do it
   * ourselves :-(                             -- Pepel.
   * If the test is successful, the drink/food is consumed.
   */
  if ((intox + strength <= ({int})pl->Query(P_MAX_ALCOHOL)) &&
      (soak + psoak <= ({int})pl->Query(P_MAX_DRINK)) &&
      (stuff + pstuff <= ({int})pl->Query(P_MAX_FOOD))) {
    pl->AddAlcohol(strength);
    pl->AddDrink(soak);
    pl->AddFood(stuff);
    pl->Heal(heal);
    ob = first_inventory(this_object());
    while (ob) {
      if (ob == pl) {
	if (item[6])
	  tell_object(pl,item[6]+"\n");
	else
	  tell_object(ob,"You consume " + _article(name) +
		      " " + name + ".\n");
      }
      else
	tell_object(ob,({string})pl->QueryName() + " consumes " +
		    _article(name) + " " + name + ".\n");
      ob = next_inventory(ob);
    }
    write(PayValueString(this_player(),value,coins||
                         (QueryMoneyObject(this_player())?
                          m_indices(({mapping})QueryMoneyObject(this_player())->
                                    QueryMoney()) +
                          QueryValuta():0))||
          "You failed to pay something.\n");
  }
  /* Player can't consume this! */
  else {
    if (intox + strength > ({int})pl->Query(P_MAX_ALCOHOL))
      tell_object(pl,"You fail to reach the drink with your mouth.\n");
    if (soak + psoak > ({int})pl->Query(P_MAX_DRINK))
      tell_object(pl,"You can't possibly drink that much right now!\n" +
		  "You feel crosslegged enough as it is.\n");
    if (stuff + pstuff > ({int})pl->Query(P_MAX_FOOD))
      tell_object(pl, "This is much too rich for you right now! "+
		  "Perhaps something lighter?\n");
    ob = first_inventory(this_object());
    while (ob) {
      if (ob != pl)
	tell_object(ob,({string})pl->QueryName() + " tries " + _article(name) +
		    " " + name + " but fails.\n");
      ob = next_inventory(ob);
    }
  }
  return 1;
}
