// shop.c
// A basic shop with a basic storeroom.
// Written by Mobydick@TMI-2, 8-25-92

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit ROOM ;
inherit COINVALUE ;

object storeroom ;
object ob,ob2 ;

void create() {
	seteuid(getuid()) ;
	::create() ;

/* Force the warehouse to load, if it's not loaded  */

	CENTSTORE->frog() ;
}

void init() {
	add_action ("list", "list") ;
	add_action ("value", "value") ;
	add_action ("buy", "buy") ;
	add_action ("sell", "sell") ;
	add_action ("enter_storeroom", "storeroom") ;
}



int list() {

        int i,j,k ;
	string str, foo;
        string *shorts, *coins ;
        int *number, *price ;
        mixed *value ;
	object *frog ;

	write ("The following objects are for sale:\n") ;

#define NUM_STR ({ "Zero", "One", "Two", "Three", "Four", "Five", "Six", \
	"Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", \
	"Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", \
	"Eighteen", "Nineteen", "Twenty" })

	frog = all_inventory(storeroom) + 
		all_inventory(find_object_or_load(CENTSTORE)) ;

	shorts = ({ }) ;
	coins = ({ }) ;
	number = ({ }) ;
	price = ({ }) ;
        for (i=0;i<sizeof(frog);i++) {
            str = (string)frog[i]->query("short") ;
	    if (str[0..1]=="a ") str=str[2..<1] ;
	    if (str[0..2]=="an ") str=str[3..<1] ;
	    if (str[0..3]=="the ") str=str[4..<1] ;
	    value = (mixed *)frog[i]->query("value") ;
	    if (!value || sizeof(value)!=2) continue ;
            j = -1 ;
            for (k=0;k<sizeof(shorts);k++) {
                if (str==shorts[k] && value[0]==price[k] &&
                       value[1]==coins[k]) {
                    j = k ;
                    continue ;
                }
            }
            if (j==-1) {
                shorts += ({ str }) ;
                number += ({ 1 }) ;
		value = frog[i]->query("value") ;
                price += ({ value[0] }) ;
                coins += ({ value[1] }) ;
            } else {
                number[j] += 1 ;
            }
        }
        for (i=0;i<sizeof(shorts);i++) {
            if (number[i]>20) {
		foo = "Many" ;
            } else {
		foo = NUM_STR[number[i]] ;
            }
	    foo += " " ;
            if (number[i]==1) {
		foo += shorts[i] ;
            } else {
		foo += pluralize(shorts[i]) ;
            }
	    write (sprintf("   %-42s %d %s\n",foo,price[i],coins[i])) ;
        }
	return 1 ;
}

int buy(string str) {

	int number, i, j, k, l, has, res ;
	string type ;
	object ob ;
	string *types ;
	mixed *value ;
	int oldval, newval, newnum, leftnum ;

/* Look for the object, first in central storage then in local storage. */

	if (!str) {
		notify_fail ("What would you like to buy?\n") ;
		return 0 ;
	}
	ob = present(str,find_object(CENTSTORE)) ;
	if (!ob) ob = present (str,storeroom) ;
	if (!ob) {
		notify_fail ("We don't have one of those for sale.\n") ;
		return 0 ;
	}
	value = ob->query("value") ;
	if (!value) {
		notify_fail ("That object should not have been in the shop.\n");
		ob->remove() ;
		return 0 ;
	}
	type = value[1] ;
	number = value[0] ;
	if (number==0) {
                notify_fail ("That object should not have been in the shop.\n");
		ob->remove() ;
		return 0 ;
	}

// Check to see if the player has exact change.

	i = this_player()->query("wealth/"+type) ;
	if (i>=number) {
		this_player()->set("wealth/"+type,i-number) ;
		j = this_player()->query("capacity") ;
		this_player()->set("capacity", j+number) ;
// See if the player can carry the object.
		res = ob->move(this_player()) ;
		if (res==MOVE_OK) {
			write ("The shopkeeper hands you "+(string)ob->query("short")+".\n") ;
			say (this_player()->query("cap_name")+" buys a "+ob->query("short")+".\n") ;
			return 1 ;
		} else {
// Give him his money back.
			this_player()->set("wealth/"+type,i) ;
			this_player()->set("capacity",j) ;
			write ("You cannot carry that object.\n") ;
			return 0 ;
		}
	}

// The rest of the procedure tries to let the player use other combinations
// of coins to buy the object. Clever players can use this to convert coins
// for free, by buying a 50 silver coin object for 5 gold and then selling
// it back for 50 silver. If you don't want this to happen, either have the
// shops return less than exact value on sales, or rip out the following
// code.

// Check to see if this is a convertable type of coin. If it isn't then
// the player cannot buy the object.

	types = cointypes() ;
	j = member_array (type,types) ;
	if (j==-1) {
		notify_fail ("You don't have "+number+" "+type+" and the shop cannot convert that to other coins.\n") ;
		return 0 ;
	}

// Check to see if he has enough total wealth to buy the object. If he
// doesn't we can save a lot of CPU time by giving up now.

	res = this_player()->total_wealth() ;
	k = this_player()->query("wealth/"+type) ;
	oldval = coinvalue(type) ;
	if (res<k*oldval) {
		write ("You can't afford that!\n") ;
		return 0 ;
	}

// First check higher-valued coins, lowest to highest, to see if the player
// can buy the object exactly for some combination of the higher-valued
// coin and the stated coin.

	for (i=j-1;i>=0;i--) {
	newval = coinvalue(types[i]) ;
	newnum = (oldval*number)/newval ;
	leftnum = ((oldval*number)-(newnum*newval))/oldval ;

// If the player has enough of the new type, he buys the item.

	has = this_player()->query("wealth/"+types[i]) ;
	if (has>=newnum && k>=leftnum) {
		this_player()->set("wealth/"+types[i],has-newnum) ;
		this_player()->set("wealth/"+type,k-leftnum) ;
		l = this_player()->query("capacity") ;
		this_player()->set("capacity",l+newnum+leftnum) ;
		res = ob->move(this_player()) ;
		if (res==MOVE_OK) {
			write ("The shopkeeper hands you "+(string)ob->query("short")+".\n") ;
			say (this_player()->query("cap_name")+" buys a "+ob->query("short")+".\n") ;
			return 1 ;
		} else {
			this_player()->set("wealth/"+types[i],has) ;
			this_player()->set("wealth/"+type,k) ;
			this_player()->set("capacity",l) ;
			write ("You cannot carry that object.\n") ;
			return 1 ;
		}
	}

// If that didn't work, try using all the player has of the stated coin, plus
// as many of the new coin type as necessary.

	newnum = (oldval*(number-k))/newval ;
	if ((oldval*number)-(newval*newnum)>(k*oldval)) newnum = newnum + 1 ;
	leftnum = ((oldval*number)-(newnum*newval))/oldval ;

	has = this_player()->query("wealth/"+types[i]) ;
	if (has>=newnum && k>=leftnum) {
		this_player()->set ("wealth/"+types[i],has-newnum) ;
                this_player()->set("wealth/"+type,k-leftnum) ;
                l = this_player()->query("capacity") ;
                this_player()->set("capacity",l+newnum+leftnum) ;
                res = ob->move(this_player()) ;
		if (res==MOVE_OK) {
			write ("The shopkeeper hands you "+(string)ob->query("short")+".\n") ;
			say (this_player()->query("cap_name")+" buys a "+ob->query("short")+".\n") ;
                	return 1 ;
		} else {
			this_player()->set("wealth/"+types[i],has) ;
                        this_player()->set("wealth/"+type,k) ;
                        this_player()->set("capacity",l) ;
                        write ("You cannot carry that object.\n") ;
                        return 1 ;
                }
        }

// If neither of those two worked, give up and try the next coin type.

	}

// Higher types didn't work. Now we try all less valuable coin types and
// see if we can buy it for all he possesses of the stated type plus some
// of the lower-valued type.

	for (i=j+1;i<sizeof(types);i++) {
	newval = coinvalue(types[i]) ;
	newnum = ((number-k)*oldval)/newval ;
	has = this_player()->query("wealth/"+types[i]) ;
	if (has>=newnum) {
		this_player()->set("wealth/"+types[i],has-newnum) ;
		this_player()->set("wealth/"+type,0) ;
		l = this_player()->query("capacity") ;
		this_player()->set("capacity",l+k+newnum) ;
		res = ob->move(this_player()) ;
		if (res==MOVE_OK) {
			write ("The shopkeeper hands you "+(string)ob->query("short")+".\n") ;
			say (this_player()->query("cap_name")+" buys a "+ob->query("short")+".\n") ;
			return 1 ;
		} else {
			this_player()->set("wealth/"+types[i],has) ;
                        this_player()->set("wealth/"+type,k) ;
                        this_player()->set("capacity",l) ;
                        write ("You cannot carry that object.\n") ;
                        return 1 ;
                }
	}

// If that didn't work, try the next coin type.

	}

// OK, it looks like he can't buy it for exact change. Now, try all the
// higher types again, this time giving whatever change is necessary.

	for (i=j-1;i>=0;i--) {
	newval = coinvalue(types[i]) ;
	newnum = (oldval*number)/newval ;
	if ((oldval*number)-(newval*newnum)>0) newnum = newnum + 1 ;
	leftnum = ((newval*newnum)-(oldval*number))/oldval ;
	has = this_player()->query("wealth/"+types[i]) ;
	if (has>=newnum) {
		this_player()->set("wealth/"+types[i],has-newnum) ;
		this_player()->set("wealth/"+type,k+leftnum) ;
		l = this_player()->query("capacity") ;
		this_player()->set("capacity",l+newnum-leftnum) ;
		res = ob->move(this_player()) ;
		if (res==MOVE_OK) {
			write ("The shopkeeper hands you "+(string)ob->query("short")+".\n") ;
			say (this_player()->query("cap_name")+" buys a "+ob->query("short")+".\n") ;
			return 1 ;
		} else {
			this_player()->set("wealth/"+types[i],has) ;
                        this_player()->set("wealth/"+type,k) ;
                        this_player()->set("capacity",l) ;
                        write ("You cannot carry that object.\n") ;
                        return 1 ;
                }
	}

//  That didn't work, so try the next type.

	}

// That's enough of this. We give up: he can't buy it from us.

	notify_fail ("You don't have the right coins to buy that.\n") ;
	return 0 ;
}

int value(string str) {

	object *ob, obj ;
	string word ;
	string *types ;
	int i, number, changenum ;
	string type, changetype ;
	mixed *value ;
	int newval, oldval, newnum, j ;

	if (!str) {
		ob = all_inventory(this_player()) ;
		if (!ob) {
			notify_fail("You don't have any belongings.\n") ;
			return 0 ;
		}
		for (i=0;i<sizeof(ob);i++) {
			value = ob[i]->query("value") ;
			if (!value) {
				write (ob[i]->query("short")+" has no value.\n") ;
				continue ;
			}
			type = value[1] ;
			number=value[0] ;
		 	if (number==0) {
				write (ob[i]->query("short")+" has no value.\n") ;
				continue ;
			}

// If it's a coin we can make change for, we multiply by the sales fraction
// and calculate how much to give back of the stated coin and the lower-
// valued coin. If it's the lowest value coin, or if it's not list with
// coinvalue.c, we just take off the fraction and sell for that.

			types = cointypes() ;
			j = member_array(type,types) ;
			if (j==-1 || j==sizeof(types)-1) {
				newnum = number*SHOP_SALES_FRAC ;
				if (newnum==0) newnum=1 ;
				if (newnum==1) word="coin" ; else word="coins" ;
				write (ob[i]->query("short")+" is worth "+newnum+" "+type+" "+word+".\n") ;
			} else {
				changetype = types[j+1] ;
				oldval = coinvalue(type) ;
				newval = coinvalue(changetype) ;
				newnum = (number*oldval*SHOP_SALES_FRAC)/oldval;
				changenum = ((number*oldval*SHOP_SALES_FRAC)-(newnum*oldval))/newval ;
				if (newnum==1) word="coin" ; else word="coins" ;
				write (ob[i]->query("short")+" is worth "+newnum+" "+type+" "+word) ;
				if (changenum==0) {
					write (".\n") ;
				} else {
					if (changenum==1) word="coin" ; else word="coins" ;
				write (" and "+changenum+" "+changetype+" "+word+".\n") ;
				}
			}
		}
		return 1 ;
	}
	obj = present(str,this_player()) ;
	if (!obj) {
		notify_fail ("You don't have a "+str+".\n") ;
		return 0 ;
	}
	value = obj->query("value") ;
	if (!value) {
		notify_fail ("That object is not worth anything.\n") ;
		return 0 ;
	}
	type = value[1] ;
	number = value[0] ;
	if (number==0) {
		notify_fail ("That object is not worth anything.\n") ;
		return 0 ;
	}
	types = cointypes() ;
	j = member_array(type,types) ;
	if (j==-1 || j==sizeof(types)-1) {
		newnum = number*SHOP_SALES_FRAC ;
		if (newnum==0) newnum=1 ;
		if (newnum==1) word="coin" ; else word="coins" ;
		write (obj->query("short")+" is worth "+newnum+" "+type+" "+word+".\n") ;
	} else {
		changetype = types[j+1] ;
		oldval = coinvalue(type) ;
		newval = coinvalue(changetype) ;
		newnum = (number*oldval*SHOP_SALES_FRAC)/oldval;
		changenum = ((number*oldval*SHOP_SALES_FRAC)-(newnum*oldval))/newval ;
		if (newnum==1) word="coin" ; else word="coins" ;
		write (obj->query("short")+" is worth "+newnum+" "+type+" "+word) ;
		if (changenum==0) {
			write (".\n") ;
		} else {
			if (changenum==1) word="coin" ; else word="coins" ;
			write (" and "+changenum+" "+changetype+" "+word+".\n") ;
		}
	}
	return 1 ;
}

int sell(string str) {

	int i, j, l, res ;
	int newnum, changenum ;
	int oldval, newval ;
	string changetype ;
	object ob ;
	string *types ;
	object *obs ;
	string type, word ;
	mixed *value ;
	int number ;

	if (!str) {
		notify_fail("What do you want to sell?\n") ;
		return 0 ;
	}
	if (str=="all") {
		obs = all_inventory(this_player()) ;
		for (i=0;i<sizeof(obs);i++) {
			value = obs[i]->query("value") ;
			if (!value) continue ;
			number = value[0] ;
			if (number<1) continue ;
			if (obs[i]->query("prevent_drop")) continue ;
			res=(int)obs[i]->move(storeroom) ;
			if (res!=MOVE_OK) continue ;
			type = value[1] ;
			res=(int)this_player()->query("wealth/"+type) ;
			types = cointypes() ;
			j = member_array(type,types) ;
			if (j==-1 || j==sizeof(types)-1) {
				newnum = number*SHOP_SALES_FRAC ;
				if (newnum==0) newnum=1 ;
				l = this_player()->query("capacity") ;
				if (l<newnum) {
					write ("You can't carry the coins from selling "+obs[i]->query("short")+".\n") ;
					obs[i]->move(this_player()) ;
					continue ;
				}
				if (newnum==1) word="coin" ; else word="coins" ;
				write ("You sell "+obs[i]->query("short")+" for "+newnum+" "+type+" "+word+".\n") ;
				say (this_player()->query("cap_name")+" sells a "+obs[i]->query("short")+".\n") ;
				this_player()->set("wealth/"+type,newnum+res) ;
				this_player()->set("capacity",l-newnum) ;
			} else {
				changetype = types[j+1] ;
				oldval = coinvalue(type) ;
				newval = coinvalue(changetype) ;
				newnum = (number*oldval*SHOP_SALES_FRAC)/oldval;
				changenum = ((number*oldval*SHOP_SALES_FRAC)-(newnum*oldval))/newval ;
				l = this_player()->query("capacity") ;
				if (l<newnum+changenum) {
					write ("You can't carry the coins from selling "+obs[i]->query("short")+".\n") ;
					obs[i]->move(this_player()) ;
					continue ;
				}
				if (newnum==1) word="coin" ; else word="coins" ;
				write ("You sell "+obs[i]->query("short")+" for "+newnum+" "+type+" "+word) ;
				say (this_player()->query("cap_name")+" sells a "+obs[i]->query("short")+".\n") ;
				this_player()->set("wealth/"+type,newnum+res) ;
				if (changenum==0) {
					write (".\n") ;
				} else {
					if (changenum==1) word="coin" ; else word="coins" ;
					write (" and "+changenum+" "+changetype+" "+word+".\n") ;
					res = this_player()->query("wealth/"+changetype) ;
					this_player()->set("wealth/"+changetype,res+changenum) ;
				}
				this_player()->set("capacity",l-newnum-changenum) ;
			}
		}
		return 1 ;
	}
	ob = present(str,this_player()) ;
	if (!ob) {
		notify_fail("You don't have one to sell!\n") ;
		return 0 ;
	}
	value = ob->query("value") ;
	if (value==0) {
		notify_fail ("That has no value.\n") ;
		return 0 ;
	}
	number=value[0] ;
	if (number<1) {
		notify_fail ("That has no value.\n") ;
		return 0 ;
	}
	if (ob->query("prevent_drop")) {
		notify_fail ("You cannot bear to part with it.\n") ;
		return 0 ;
	}
	type = value[1] ;
        res = ob->move(storeroom) ;
        if (res != MOVE_OK) {
                notify_fail ("You can't sell that!\n") ;
                return 0 ;
        }
	res = (int)this_player()->query("wealth/"+type) ;
	if (number==0) {
		notify_fail ("That object is not worth anything.\n") ;
		return 0 ;
	}
	types = cointypes() ;
	j = member_array(type,types) ;
	if (j==-1 || j==sizeof(types)-1) {
		newnum = number*SHOP_SALES_FRAC ;
		if (newnum==0) newnum=1 ;
		l = this_player()->query("capacity") ;
		if (l<newnum) {
			write ("You can't carry the coins you'd get for selling "+ob->query("short")+".\n") ;
			ob->move(this_player()) ;
			return 1 ;
		}
		if (newnum==1) word="coin" ; else word="coins" ;
		write ("You sell "+ob->query("short")+" for "+newnum+" "+type+" "+word+".\n") ;
		say (this_player()->query("cap_name")+" sells a "+ob->query("short")+".\n") ;
		this_player()->set("wealth/"+type,newnum+res) ;
		this_player()->set("capacity",l-newnum) ;
	} else {
		changetype = types[j+1] ;
		oldval = coinvalue(type) ;
		newval = coinvalue(changetype) ;
		newnum = (number*oldval*SHOP_SALES_FRAC)/oldval;
		changenum = ((number*oldval*SHOP_SALES_FRAC)-(newnum*oldval))/newval ;
		l = this_player()->query("capacity") ;
		if (l<newnum+changenum) {
                        write ("You can't carry the coins you'd get for selling "+ob->query("short")+".\n") ;
			ob->move(this_player()) ;
			return 1 ;
		}
		if (newnum==1) word="coin" ; else word="coins" ;
		write ("You sell "+ob->query("short")+" for "+newnum+" "+type+" "+word) ;
		say (this_player()->query("cap_name")+" sells a "+ob->query("short")+".\n") ;
		this_player()->set("wealth/"+type,newnum+res) ;
		if (changenum==0) {
			write (".\n") ;
		} else {
			if (changenum==1) word="coin" ; else word="coins" ;
			write (" and "+changenum+" "+changetype+" "+word+".\n");
			res = this_player()->query("wealth/"+changetype) ;
			this_player()->set("wealth/"+changetype,changenum+res) ;
		}
		this_player()->set("capacity",l-newnum-changenum) ;
	}
	return 1 ;
}

int enter_storeroom() {
	if (!wizardp(this_player())) return 0 ;
	this_player()->move(storeroom) ;
	return 1 ;
}
