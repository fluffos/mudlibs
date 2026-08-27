/*
 * /sys/global/money.c
 *
 * This object contains the code for the global money defines.
 */

#pragma no_clone
#pragma no_inherit
#pragma no_shadow
#pragma save_binary

#include <stdproperties.h>
#include <language.h>
#include <money.h>
#include <macros.h>

/*
 * Function name: split_values 
 * Description:   Splits a 'copper' value into pc, gc, sc, cc
 * Argument:      v: value in copper coins
 * Returns:       Array: ({ cc, sc, gc, pc })
 */
int *
split_values(int v)
{
    int *ret, i;
  
    ret = allocate(sizeof(MONEY_VALUES));
    if (v > 0)
    	for (i = sizeof(MONEY_VALUES) - 1; i >= 0; i--)
	{
      	    ret[i] = v / MONEY_VALUES[i];
      	    v %= MONEY_VALUES[i];
    	}

    return ret;
}

/*
 * Function name: merge_values 
 * Description:   Merges different coins into the value in copper coins
 * Argument:      av: Array ({ cc, sc, gc, pc })
 * Returns:       v: value in copper coins
 */
int
merge_values(int *av)
{
    int v, i;

    if (sizeof(av) != sizeof(MONEY_TYPES))
	return 0;

    for (v = 0, i = 0; i < sizeof(av); i++)
	v += av[i] * MONEY_VALUES[i];

    return v;
}

/*
 * Function name: make_coins
 * Description:   Makes a certain number of coins of a certain type
 * Argument:      str: Cointype: copper,silver,gold or platinum
 *                num: Number of coins
 * Returns:       Objectpointer to the coins object or 0.
 */
object
make_coins(string str, int num)
{
    object cn;
  
    if (!str)
	return 0;
  
    cn = clone_object("/std/coins");
    cn->set_heap_size(num);
    cn->set_coin_type(str);
    return cn;
}

/*
 * Function name: move_coins
 * Description:   Moves a certain number of coins.
 * Argument:      str: Cointype: copper,silver,gold or platinum
 *                num: Number of coins
 *		  from: From which inventory or 0 if create new
 *                to: To which inventory or 0 if destruct
 * Returns:       -1 if not found, 0 == moved, >0 move error code
 */
int
move_coins(string str, int num, mixed from, mixed to)
{
    object cn, f, t, cf;
    int max, okflag;
  
    if (!str || (num <= 0)) 
        return -1;
  
    if (stringp(from))
    {
        f = find_object(from);
        if (!f)
  	    f = find_player(from);
    } else if (objectp(from))
        f = from;
    else
        f = 0;

    if (stringp(to))
    {
        t = find_object(to);
        if (!t)
  	    t = find_player(to);
    }
    else if (objectp(to))
        t = to;
    else
        t = 0;

    if (f)
        cf = present("_"+str+" moneta_",f);
    else
        cf = make_coins(str, num);

    if (!cf || !(max = cf->num_heap()))
        return -1;

    if (num > max)
        return -1;

    if (t)
    {
        if (num < max)
  	    cf->split_heap(num);
        return cf->move(t);
    }

    if (!t && num < max)
        cf->set_heap_size(max-num);
    else
        cf->remove_object();

    return 0;
}

/*
 * Function name: what_coins
 * Description:   Finds out what of the normal cointypes a certain object
 *		  contains.
 * Argument:      ob: The object in which to search for coins
 * Returns:       Array: ( num copper, num silver, num gold, num platinum )
 */
int *
what_coins(mixed ob)
{
    object pl, cn;
    int il, *nums;
    string *ctypes;

    if (objectp(ob))
	pl = ob;
    else if (stringp(ob))
    {
	pl = find_object(ob);
	if (!pl)
	{
	    pl = find_player(ob);
	}
    }
    else
	return 0;

    ctypes = MONEY_TYPES;
    nums = allocate(sizeof(ctypes));

    for (il = 0; il < sizeof(ctypes); il++)
    {
	cn = present("_" + ctypes[il] + " moneta_",pl);
	if (!cn)
	{
	    nums[il] = 0;
	    continue;
	}
	else
	    nums[il] = cn->num_heap();
    }
    return nums;
}


#define M_ID(i) "_" + MONEY_TYPES[i] + " moneta_"
#define M_MAX   sizeof(MONEY_TYPES)

/*
 * Prototypes
 */
public int give_money(object who, int amount);
public int take_money(object who, int amount);

/* 
 * Function name: add_money
 * Description:   Gives money to or takes money from a living
 *                smallest possible denominators are taken,
 *                largest possible denominators are given
 * Arguments:     who: Object pointer to a living object
 *                amount: Amount to be given in copper coins
 *                        negative amount means take coins
 * Returns:       1 - success, 0 - fail
 */
public int
add_money(object who, int amount)
{
    return (amount < 0 ? take_money(who, ABS(amount)) : give_money(who, amount));
}

/* 
 * Function name: total_money
 * Description: calculates the total amount of money on a living
 */
public int
total_money(object who)
{
    return merge_values(what_coins(who));
}

/* 
 * Function name: give_money
 * Description: gives a certain sum back to this object
 */
public int
give_money(object who, int amount)
{
    object ob;
    int to_do, i, n_coins, c_flag;
    to_do = amount;
    i = M_MAX - 1;
    c_flag = 0;
    for (i = M_MAX - 1; i >= 0 && to_do; i--)
    {
	n_coins = to_do / MONEY_VALUES[i];
	to_do = to_do % MONEY_VALUES[i];
	if(n_coins > 0)
	{
	    ob = make_coins(MONEY_TYPES[i], n_coins);
	    if((int)ob->move(who))
	    {
		ob->move(environment(who));
		c_flag = 1;
	    }
	}
    }

    if (c_flag)
    {
	who->catch_msg("Nie starczy ci sily, by trzymac jeszcze " +
	    "te pieniadze, wiec odkladasz czesc na ziemie.\n");
	tell_roombb(environment(who), QCIMIE(who, PL_MIA)
	          + " odklada troche pieniedzy na ziemie.\n", ({who}), who);
    }
    return 1;
}

/* 
 * Function name: take_money
 * Description: reduces the money of someone with a given amount
 *              also handles giving back money, if necessary
 * Returns:     0:   player doesn't have enough money  
 *              1:   okay, money subtracted from player's money
 */
public int
take_money(object who, int amount)
{
    int *money_list, i, rest, c_flag;
    object *ob_list, ob;
    
    if(total_money(who) < amount)
	return 0;
    
    money_list = allocate(M_MAX);
    ob_list = allocate(M_MAX);
    
    for (i = 0; i < M_MAX; i++)
    {
	ob = present("_" + MONEY_TYPES[i] + " moneta_", who);
	if (ob)
	{
	    ob_list[i] = ob;
	    money_list[i] = (int) ob->query_prop(OBJ_I_VALUE);
	}
    }
    
    for (i = 0; i < M_MAX; i++)
    {
	if (amount <= money_list[i])
	{
	    money_list[i] -= amount;
	    break;
	}
	else
	{
	    amount -= money_list[i];
	    money_list[i] = 0;
	}
    }
    rest = 0;
    for (i = M_MAX - 1; i >= 0; i--)
    {
	money_list[i] += rest;
	rest = money_list[i] % MONEY_VALUES[i];
	money_list[i] = money_list[i] / MONEY_VALUES[i];
	if (ob_list[i])
	    ob_list[i]->set_heap_size(money_list[i]);
	else
	{
	    if (money_list[i] > 0)
	    {
	        ob = make_coins(MONEY_TYPES[i], money_list[i]);
		if((int)ob->move(who))
		{
		    ob->move(environment(who));
		    c_flag = 1;
		}
	    }
	}
    }

    if (c_flag)
    {
	who->catch_msg("Nie starczy ci sily, by trzymac jeszcze " +
	    "te pieniadze, wiec odkladasz czesc na ziemie.\n");
	tell_roombb(environment(who), QCIMIE(who, PL_MIA)
	          + " odklada troche pieniedzy na ziemie.\n", ({who}), who);
    }
    return 1;
}

/*
 * Nazwa funkcji : money_text
 * Opis          : Generuje string opisujacy podana tablice z monetami.
 * Argumenty     : arr - tablica, zawierajaca monety do opisania
 *		   przyp - w ktorym przypadku ma byc zadany opis
 * Funkcja zwraca: String z opisem monet.
 */
mixed
money_text(int *arr, int przyp)
{
    string *t_arr, coin_str, *monety, *pmonety;
    int i, j, prz, x;
    
    if (sizeof(arr) < M_MAX)  /* Not a valid array. */
	return ;

    t_arr = ({ });
    
    monety = ({ "moneta", "monety", "monecie", "monete", "monetami",
        "monetach" });
    pmonety = ({ "monety", "monet", "monetom", "monety", "monetami",
        "monetach" });

    for (i = M_MAX - 1; i >= 0; i--)
	if (arr[i] > 0)
	{
	    x = i;
	    prz = LANG_PRZYP(arr[i], przyp, PL_ZENSKI);
	    j += arr[i]; /* Total number of coins */
	    t_arr += ({ arr[i] + " " + 
	        oblicz_przym(MONEY_ODM[i][0], MONEY_ODM[i][1],
	             prz, PL_ZENSKI, (arr[i] > 1)) });
	}

    if (arr[x] > 1)
	coin_str = " " + pmonety[prz];
    else
	coin_str = " " + monety[prz];

    j = sizeof(t_arr);

    if (j < 1)
	return;
    
    if (j == 1)
        return t_arr[0] + coin_str;
    else
        return implode(t_arr[0 .. j - 2], ", ") + " i " +
	       t_arr[j - 1] + coin_str;
}
