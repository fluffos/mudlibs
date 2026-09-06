/*
  New store room to be inherited (or cloned?) for all shops.
  (Add for native: test for "NO_DESTRUCT" in object and move elsewhere)

  New: handle criminals. //Graah

  Updated: Elena, Apr 20, 1995

  Last change 7-Jul-97 / Graah: Very slightly bigger max buying value
  for objects that are _really_ valuable.

*/
/***********************
NEW:

15-Jan-98, Doomdark:
	Enhanced list-command.
17-Jan-98, Doomdark:
	And now try to fix it...

***********************/

#include <room.h>



#define MAX_AT_ONCE 5
#define MAX_LISTED  40
#define MAX_ITEMS   45
#define VALUE_HIDE  5000
// Was 2000. Changed, Doomdark.
// Was 4000. Changed a bit / Graah
#define VALUE_MAX   1050
#define MONEY_RESET 100000000
#define	me		this_player()

/*
To be defined in inheriting file:
int    count_value(object ob);      0 = prevent sell, other = money given
*/

int    destr_flag;  /* destruct_flag for valuable items (count_value()) */
int    Money;       /* Amount of money the shop has */

int    min_value;   /* "The cheap item is thrown away" */

void
reset_room()
{
    Money = MONEY_RESET;
    min_value = 0;
    this_object()->reset_store();
}

void
create_room()
{
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set_short("Store room");
    set_long("This is a store room of a shop.");
    this_object()->create_store();
}

int  query_money()    { return Money; }
void set_money(int m) { if (m > 0) Money = m; }

int query_min_value() { return min_value; }
void set_min_value(int v) { if (v < 500) min_value = v; }

/* Accept everything by default - redefine if needed. //Graah */
int accept_object(object ob) { return 1; }

/* Default buy value adjustment */
int adjust_buy_value(int v) {
    int c;

    if (!(c = (int)this_player()->query_crime_level()))
	return (2 * v + 1) / 3;
    else
	/* Note that most shops don't trade with crime > 1 */
	return ((2 * v + 1) / (3 + c));
}

/* Default sale value adjustment */
varargs int adjust_sale_value(int v, object ob) {
    int c;

    if (!(c = (int)this_player()->query_crime_level()))
	return v * 5 / 4;	// Was v * 2. Changed by Doomdark.
    else
	/* Note that most shops don't trade with crime > 1 */
	return v * (5 + 2 * c) / 4;	// Was v * (2 + c).
}

int
count_value(object ob)
{
    int value, max;

    if (!accept_object(ob)) return 0;

    if (value = (int)ob->query_value()) {
	destr_flag = (value > VALUE_HIDE);

	// New formula
	max = (VALUE_MAX + (value > 1000 ? (value - 1000) / 15 : 0));

	// Prevent immensely valuable cheat objects
	if (max > (VALUE_MAX * 2)) max = (VALUE_MAX * 2);

	if (value > max) value = max;
	value = adjust_buy_value(value);
    }

    return value;
}


/*
  !item : List all items in store
  item  : List items ob->id(item), Exception: armours & weapons
  ....
  Destroy all invaluable items.
  (For native: test for "NO_DESTRUCT" in object and move elsewhere)
*/

int
list_item(string item)
{
    int    i, value,count,list_type, val;
    string str, old_str;
    mixed obs;

    /* preprocess items variable */
    if(item && item != "all") {
	list_type = 1;
	if (item=="armours") list_type = 2; else
	if (item=="weapons") list_type = 3; else
	if (item[<1]=='s')
	    item = item[0..<2];
    }
    obs = all_inventory();

    for (i = count = 0; i < sizeof(obs); i++) {
	if(((val = (int)obs[i]->query_value()) < min_value) ||
	  !(value = adjust_sale_value(val, obs[i]))) {
	    /*** destroy invaluable items from store ***/
	    if(interactive(obs[i]))
		move_object(obs[i],"/room/church");
	    else destruct(obs[i]);
	    obs[i] = 0;
	    continue;
	}
	/* can't use switch because of continue command */
	if(    (list_type==1 && (!obs[i]->id(item)))
	  || (list_type==2 && (!obs[i]->is_armour()))
	  || (list_type==3 && (!obs[i]->is_weapon())) ) {
	    obs[i] = 0;
	    continue;
	}

	if (!(str = (string)obs[i]->short())) {
	    obs[i] = 0;
	    continue;
	}
	obs[count++] = sprintf("%d\t%-24s", value, str);
    }

    if (!count) {
	if (!list_type)
	    me->tell_me("Shopkeeper says: Sorry, I don't have any items\
 on sale right now... Bad times, admins tuning and all.");
	else
	    me->tell_me("Shopkeeper says: Sorry, I don't have any of\
 those on sale.");
	return 1;
    }

    if (count < sizeof(obs))
	obs = obs[0..count - 1];

    for (i = 0; i < count; i += 2) {
	if ((i + 1) < count) {
	    obs[i / 2] = sprintf("%d\t%s%d\t%s", i + 1, obs[i],
	      i + 2, obs[i+1]);
	} else {
	    obs[i / 2] = sprintf("%d\t%s", i + 1, obs[i]);
	}
    }

    me->tell_me("Num\tCost\tItem\t\t\tNum\tCost\tItem");
    me->more(obs[0..i / 2 - 1]);

    return 1;
}

int
buy_item(string item)
{
    object ob;
    string str;
    int i, value;

    if (!item) {
	me->tell_me("Shopkeeper tells you: Perhaps you should buy <item>.");
	return 1;
    }

    if (sscanf(item,"%d%s",i,str)==2 && str=="" && i>0 && i<=MAX_LISTED)
    {
	object *list;
	list = all_inventory();
	if(sizeof(list)>=i) ob = list[i-1];
    }

    if (!ob && !(ob=present(item))) {
	me->tell_me("Shopkeeper says: Sorry, I'm out of that item.");
	return 1;
    }

    value = adjust_sale_value((int)ob->query_value(), ob);

    if (this_player()->query_money() < value) {
	me->tell_me("Shopkeeper exclaims: \
It would cost you "+value+" gold coins, which you don't have!");
	return 1;
    }

    i = (int)ob->query_weight();
    if (!this_player()->add_weight(i)) {
	me->tell_me("Shopkeeper tells you: \
You don't seem to be able to carry that much.\n");
	return 1;
    }
    this_player()->add_money(-value);
    Money += value;
    move_object(ob, this_player());
    me->tell_me("Shopkeeper says: Ok. Here's your order.");
    environment(me)->tell_here(sprintf("%s buys %s.",
	(string) this_player()->query_name(),
	(string) ob->short()), me);
    return 1;
}


/*
  Destructs the items over MAX_ITEMS count in store.
  Returns how many items was sold.
*/
varargs int
sell_items_in_list(object *item_list,object from_what)
{
    mixed  *store_list;
    object ob;
    string desc, seller;
    int i, value, count;
    object *keeped;

    if (interactive(me) && (keeped = (object *) me->query_keep_items())
      && sizeof(keeped)) {
	i = sizeof(item_list);
	item_list -= keeped;
	if ((count = sizeof(item_list)) < i) {
	    if (!count) {
		me->tell_me(
		  "[All items you specified are the ones you've specified to be keeped!]");
		return 1;
	    }
	    else me->tell_me(sprintf(
		    "[Keeping %d items othewise sold]", i - count));
	}
    }

    for(i = count = 0; i < sizeof(item_list); ++i) {

	/* Avoid too long evaluation */
	if (count >= MAX_AT_ONCE) {
	    me->tell_me("Shopkeeper says: Hey, You are selling a lot of \
stuff! Let's slow down a bit.");
	    break;
	}

	ob = item_list[i];
	if(!(value = count_value(ob)) || !(desc = (string)ob->short())
	  || ob->drop() || !ob)
	    continue;
	if(!count++) {
	    seller = (string)this_player()->query_name();
	}

	if(value>Money) {
	    me->tell_me("Shopkeeper says: I can't afford any more right now.");
	    environment(me)->tell_here("Shopkeeper says: \
I wish I had my tax refund, I'm quite low on money.",me);
	    if(count) break; else return 1;
	}
	Money -= value;

	environment(me)->tell_here(seller+" sells "+desc+".",me);
	me->tell_me("Shopkeeper gives you "+value+" coins for "+desc+".");
	this_player()->add_money(value);

	if(destr_flag) {
	    me->tell_me("Shopkeeper exclaims: Ooh, this is really nice!");
	    destruct(ob); /* the weight is automatically updated */
	} else {
	    if(!store_list) { /* collect shorts from all items */
		int i2;
		store_list = all_inventory();
		i2=sizeof(store_list);
		while(i2--)
		    store_list[i2] = (string)store_list[i2]->short();
	    }
	    if(member(store_list, desc)!=-1) {
		/* destruct automatically updates the weight */
		destruct(ob);
	    } else {
		environment(ob)->add_weight(-((int)ob->query_weight()));
		move_object(ob,this_object());
		store_list += ({ desc });
	    }
	}
    }
    if (from_what)
	from_what->recount_weight();

    if(count) {
	store_list = all_inventory();
	for(i=MAX_ITEMS; i<sizeof(store_list); ++i)
	    destruct(store_list[i]);
    } else {
	me->tell_me("Shopkeeper says: I'm not interested in "
	  +((sizeof(item_list)==1) ? "it" : "them")
	  +".");
	return 1;
    }
    return count;
}


int
sell_item(string item)
{
    object *item_list;
    object env,ob;
    string str;

    if(!item) {
	me->tell_me("Shopkeeper says: Are you trying to sell <item(s)>?");
	return 1;
    }

    /** Sell from... **/
    env = this_player();
    if(sscanf(item,"%s from %s",item,str)==2) {
	if(!(env = present(str,env))) {
	    me->tell_me("Shopkeeper frowns and says: \
You don't have any "+str+".");
	    return 1;
	}
	if(!env->can_put_and_get()) {
	    me->tell_me("Shopkeeper says: I can't get anything from that.");
	    return 1; } }

    /** Sell what... **/
    if(item=="all") {
	item_list = all_inventory(env);
	if(!sizeof(item_list)) {
	    me->tell_me("Shopkeeper scratches his head: \
There seems to be nothing to sell" + (str ? (" in "+str) : "") +".");
	    return 1;
	}
    } else {
	if(!(ob = present(item, env))) {
	    me->tell_me(
	      "Shopkeeper says: You don't have any " + item
	      +(str ? (" in "+str) : "")
	      +".");
	    return 1;
	}
	// Let's check if this was an item player wanted to keep!
	if (this_player()->query_keep_items(ob)) {
	    me->tell_me(sprintf("Won't sell the %s as you have specified\
 it to be kept from selling!", (string) ob->query_name()));
	    return 1;
	}
	item_list = ({ ob });
    }

    return sell_items_in_list(item_list,env);
}

int
value_item(string item)
{
    object item_ob;
    int    value;

    if(!item) {
	me->tell_me("Shopkeeper asks: Are you trying to find value <item>?");
	return 1;
    }
    if(!(item_ob=present(item)))
	if(!(item_ob=present(item,this_player()))) {
	    me->tell_me("Shopkeeper says: You don't have item ("+item+").");
	    return 1;
	}

    if(value=count_value(item_ob)) {
	me->tell_me("Shopkeeper says: I'll give you "+value+" gold coins.");
	if(value>Money)
	    me->tell_me("...but I have " + (Money ? ("only "+Money) : "no")
	      +" coins left.\n");
    } else
	me->tell_me("Shopkeeper says: "+capitalize(item)+" is worthless to me.");
    return 1;
}
