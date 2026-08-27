/*
  This merchant will act like a shop; selling stuff in his inventory.
*/

#include "macros.h"
#include "stdproperties.h"
#include "language.h"
#include "composite.h"
#include "money.h"

#define BS(x)    break_string(x, 77)
#define MAXLIST  30
#define TP       this_player()
#define TO       this_object()
#define STORE_ROOM TO
#define NF(x)	 notify_fail(x)
#define NUM	 4

inherit "/std/monster";
inherit "/lib/trade";

/*
  Mudlib functions.
*/

create_monster() {
    if (IS_CLONE) {
	set_name("bert");
	set_living_name("bert");
	default_config_npc(100);
	config_default_trade();
	set_money_give_reduce( ({ 0, 2, 3, 3 }) );

	seq_new("foo");
	seq_addfirst("foo", ({ "@@do_give" }) );
    }
}

init_living() {
    add_action("do_list", "list");
    add_action("buy", "buy");
    add_action("sell", "sell");
    add_action("value", "value");
}

/*
  Give the handler some money
*/

do_give() {
    if (environment()) {
	tell_room(environment(), "Suddenly, money starts raining over " +
		  TO->short() + ".\n");
    }
    seteuid(getuid(TO));
    give(5000, TO);
    command("get all");
}

/*
  The code for LIST.
*/

/*
 * Function name:   do_list
 * Description:     Provide a list of objects in the store room
 * Returns:         0 if not recognised
 *                  1 otherwise
 * Arguments:       str - the name of the objects to search for
 */

do_list(string str)
{
    object *item_arr;
    int i, price, *arr;

    STORE_ROOM->short();

    item_arr = all_inventory(STORE_ROOM);

    if (!sizeof(item_arr))
    {
        NF("There store room is currently empty.\n");
        return 0;
    }

    if (str == "weapons")
        item_arr = filter(item_arr,"weapon_filter", TO);
    else
        if (str == "armours")
            item_arr = filter(item_arr,"armour_filter", TO);
    else
        if (str)
            item_arr = filter(item_arr,"string_filter", TO, str);

    item_arr = filter(item_arr, "remove_coins_from_arr", TO);
    if (sizeof(item_arr) < 1)
    {
        NF("No match found.\n");
        return 0;
    }

    for (i = 0; i < sizeof(item_arr); i++)
        if (i < MAXLIST)
        {
            price = 2 * item_arr[i]->query_prop(OBJ_I_VALUE) *
                 query_money_greed_buy() / 100;

            arr = my_split_values(price);
            str = sprintf("%-25s",
                 capitalize(LANG_ADDART(item_arr[i]->short())));

            if (!text(arr))
                write(str + "That item wouldn't cost you much.\n");
            else
                write(BS(str + text(arr) + ".\n"));
        }
        else
        {
            write("Truncated: " + i + ".\n");
            break;
        }

    return 1;
}

/* Function to identify a weapon */

weapon_filter(object ob)
{
    return (function_exists("create_object", ob) == "/std/weapon");
}

/* Function to identify an armour */

armour_filter(object ob)
{
    return (function_exists("create_object", ob) == "/std/armour");
}

/* Function to identify the string in list command */

string_filter(object ob, string str)
{
    return ob->id(str);
}

/* Function to get rid of the coins in the inventory, they are not for sale */

remove_coins_from_arr(object ob)
{
    return !ob->id("coin");
}


/*
  The code for BUY.
*/


buy(string str) {
    object  buy_ob;
    string  what, for_c, get_c;
    string  change;
    int     *result, m_res;
    int     price;

    if (!str) {
	NF("Buy what?\n");
	return 0;
    }
    if (sscanf(str, "%s with %s and get %s", what, for_c, get_c) != 3)
	if (sscanf(str, "%s with %s", what, for_c) != 2)
	    what = str;

    buy_ob = present(what, STORE_ROOM);
    if (!buy_ob)
    {
	NF("I have no such thing to sell to you.\n");
	return 0;
    }
    price = (int)2 * buy_ob->query_prop(OBJ_I_VALUE);

    set_money_give_out(my_what_coins(TO));

    result = pay(price, this_player(), for_c, 0, this_object(), get_c);
    if (sizeof(result) == 1)
	return 0; /* Pay() handles notify_fail if we want to. */

    if ((int)buy_ob->move(TP))
    {
        write("You drop the " + buy_ob->short() + " on the floor.\n");
        say(BS(QCTNAME(TP) + " drops one " + buy_ob->short() +
            " on the floor.\n"));
        buy_ob->move(environment(TP));
    }
    else
    {
        write("You get your " + buy_ob->short() + ".\n");
        say(QCTNAME(TP) + " buys the " + buy_ob->short() + ".\n");
    }

    write ("You pay " + text(result[0 .. NUM - 1]) + ".\n");
    change = text(result[NUM .. 2 * NUM - 1]);

    if (change) {
	write("You get, " + change + " as change.\n");
    }
    return 1;
}

/*
  The code for SELL.
*/


sell(string what) {
    object  item;
    string  get_c;
    int    *result, tot_price;

    if (!what) {
	NF("Sell what?\n");
	return 1;
    }

    sscanf(what, "%s for %s", what, get_c);

    if (!(item = present(what, TP)))
    {
        NF("You don't have no " + what + ".\n");
        return 0;
    }

    tot_price = item->query_prop(OBJ_I_VALUE);
    set_money_give_out(my_what_coins(TP));

    result = pay(tot_price, TO, get_c, 1, TP);

    if (sizeof(result) > 1) {
	int i;
	string change;

	if (my_money_merge(result[0 .. NUM - 1]) <= ( tot_price + 
		my_money_merge(result[NUM .. 2 * NUM - 1])))
	{
	    item->query_auto_load();
	    if (item->move(STORE_ROOM))
		return 0;

	    result = pay(tot_price, TO, get_c, 0, TP);
	    if (sizeof(result) == 1)
		return 0;

	    write("I pay you " + text(result[0 .. NUM - 1]) + ".\n");
	    if (change = text(result[NUM .. NUM * 2 - 1]))
	        write("You give me change, " + change + ".\n");
	}
	else 
	{
            set_money_give_out(my_what_coins(TO));

	    item->query_auto_load();
	    if (item->move(STORE_ROOM))
		return 0;

            result = give(tot_price, TP, get_c);

            write(BS("You sell your " + item->short() + " and get " +
                text(result[NUM .. 2 * NUM - 1]) + ".\n"));
	}

        say(QCTNAME(TP) + " sells " + TP->query_possessive() + " "
            + item->short() + ".\n");

    } 
    else if (result[0] == 2 || result[0] == 3)
    {
	return 0;
    }

    return 1;
}

/* 
    Value
*/

/*
 * Function name:   value
 * Description:     Let the player value an item, carry or in shop
 * Returns:         1 on success
 */

value(string str)
{
    object item;
    int *arr, price, i;
    string change;

    if (!str || str =="")
    {
        NF("Value what?\n");
        return 0;
    }

    if (item = present(str, TP))
    {
	write("A sell would result in:\n");

        price = item->query_prop(OBJ_I_VALUE);
        set_money_give_out(my_what_coins(TP));

        arr = pay(price, TO, "", 1, TP);

        if (sizeof(arr) > 1)
	{
	    if (my_money_merge(arr[0 .. NUM - 1]) <= ( price +
		my_money_merge(arr[NUM .. 2 * NUM - 1])))
	    {
	        arr = pay(price, TO, "", 1, TP);
	        if (sizeof(arr) == 1)
		    return 0;

	        write("I pay you " + text(arr[0 .. NUM - 1]) + ".\n");
	        if (change = text(arr[NUM .. 2 * NUM - 1]))
	            write("You give me change, " + change + ".\n");
	    }
	    else 
	    {
                set_money_give_out(my_what_coins(TO));

                arr = give(price, TP, "", 1);

                write(BS("You sell your " + item->short() + " and get " +
                    text(arr[NUM .. 2 * NUM - 1]) + ".\n"));
	    }

        } 
	else if (arr[0] == 2 || arr[0] == 3) 
	{
  	    NF("I cannot pay that much.\n");
	    return 0;
        } 
	return 1;
    }

    if (item = present(str, STORE_ROOM));
    {
	write("To buy would result in:\n");

        set_money_give_out(my_what_coins(TO));

        price = 2 * item->query_prop(OBJ_I_VALUE) *
            query_money_greed_buy() / 100;

        arr = pay(price, TP, "", 1, TO);
        if (sizeof(arr) == 1)
	    return 0; /* Pay() handles notify_fail if we want to. */

    	write ("You pay " + text(arr[0 .. NUM - 1]) + ".\n");
    	change = text(arr[NUM .. 2 * NUM - 1]);

    	if (change)
	    write("You get, " + change + " as change.\n");

        say(BS(QCTNAME(TP) + " asks about the value of the " +
            item->short() + ".\n"));

        return 1;
    }

    NF("Couldn't find any " + str + ".\n");
    return 0;
}
