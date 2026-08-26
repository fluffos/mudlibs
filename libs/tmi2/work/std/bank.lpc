// bank.c
// A basic bank object. Players can open an account, receiving a bank card.
// The bank card is an autoloading object that keeps track of how much
// money they have deposited. At the bank, players can withdraw or deposit
// funds.
// The bank has a create function which sets the euid of the object. Any
// file than inherits this file needs to ::create() in its create function.
// Note that the bank does not store the account data internally. Instead,
// each player's account data is stored in his bank card. This makes lookup
// faster but it does mean the player has to keep his card safe.

// Created by Mobydick@TMI-2, 8-28-92

#define SIGN "/obj/coinval_sign"

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit ROOM ;
inherit COINVALUE ;

void create() {

	object sign ;

	::create() ;
	seteuid(getuid()) ;
	sign = clone_object(SIGN) ;
	sign->set_location(file_name(this_object())) ;
}

void init() {
	add_action ("open_account", "open") ;
	add_action ("deposit", "deposit") ;
	add_action ("withdraw", "withdraw") ;
}

// Open_account lets the player open his bank account. It gives him a bank
// card which is where his account data is stored. The fee is set at 25
// gold pieces but you can change that very easily if you desire.

int open_account(string str) {

	int i ;
	object ob ;

	if (!str || str != "account") {
		notify_fail ("Open what?\n") ;
		return 0 ;
	}
	if (present("bank card", this_player())) {
		write ("You already have an account.\n") ;
		return 1 ;
	}
	if (this_player()->query("bank_balance")) {
		write ("Hm, you seem to have lost your card.. but you already have an account.\n"+"Let me give you a new card.\n") ;
		ob = clone_object(BANK_CARD_FILE) ;
		ob->assign(this_player()) ;
		return 1 ;
	}
	i = this_player()->query("wealth/gold") ;
	if (i<25) {
		write ("You need to have 25 gold coins to open an account.\n") ;
		return 1 ;
	}
	this_player()->set("wealth/gold",i-25) ;
	this_player()->set("capacity",this_player()->query("capacity")+25) ;
	ob = clone_object (BANK_CARD_FILE) ;
	ob -> assign(this_player()) ;
	write ("The banker hands you a shiny new bank card.\n"+
		"You now have an account with First Mudwide Bank of TMI.\n") ;
	say (this_player()->query("cap_name")+" opens a bank account.\n") ;
	this_player()->set("bank_balance", ([ ]) ) ;
	return 1 ;
}

// Withdraw allows a player to withdraw money from his bank account. The
// player must have his card to permit this. The function checks his card
// to make sure he has enough money to make the withdrawal.
// The bank knows about conversion: if the player wants to withdraw 5 gold
// and has 0 gold and 50 silver in the bank, the bank withdraws his 50 silver
// and gives him the 5 gold. More comments on this below.

int withdraw (string str) {

	int number, i  ;
	int oldval, newval, newnum ;
	string type, word, newtype ;
	object card, coins ;
	string *types ;

	if (!str) {
		notify_fail ("Usage: withdraw <number> <type>\n") ;
		return 0 ;
	}
	if (sscanf(str,"%d %s",number,type)!=2) {
		notify_fail ("Usage: withdraw <number> <type>\n") ;
		return 0 ;
	}
	if (number<1) {
		notify_fail ("You can only withdraw positive numbers of coins.\n") ;
		return 0 ;
	}
	card = present("bank card", this_player()) ;
	if (!card) {
		notify_fail ("You don't have an account!\n") ;
		return 0 ;
	}
	if ((int)card->query_val(type)>=number) {
		coins = clone_object(COINS) ;
		coins->set_number(number) ;
		coins->set_type(type) ;
		if (coins->move(this_player())==MOVE_OK) {
			if (number==1) word = "coin" ; else word="coins" ;
			write ("The banker hands you "+number+" "+type+" "+word+".\n") ;
			say (this_player()->query("cap_name")+" withdraws some "+type+".\n") ;
			card -> add_val (type,-number) ;
			return 1 ;
		}
		notify_fail ("You cannot carry that many more coins.\n") ;
		return 0 ;
		}
// If the following lines (to the ending comment) are in place, if the player
// can't withdraw what he requests, the bank will give him the same amount
// of money in some other coinage if it can. For example, in the default
// coin system, if he requests 20 gold but doesn't have that, the bank will
// give him 2 platinum or 200 silver instead. This enables clever players
// to change coinage for free. If you have a coin exchange which charges
// a fee, you need to either rip this out, institute a fee on withdrawals,
// or allow smart players to get a free ride...
	types = cointypes() ;
	i = member_array(type,types) ;
	if (i==-1) {
		notify_fail ("You don't have that many "+type+" and the bank cannot convert them.\n") ;
		return 0 ;
	}
	oldval = coinvalue(type) ;
	for (i=0;i<sizeof(types);i++) {
                newtype = types[i] ;
                newval = coinvalue(newtype) ;
                newnum = number*oldval/newval ;
// Check to see if it's exact change.
		if ((number*oldval)-(newval*newnum)>0) continue ;
// Check to see if he's got that many of the new type.
                if ((int)card->query_val(newtype)>=newnum) {
			coins = clone_object(COINS) ;
			coins->set_number(number) ;
			coins->set_type(type) ;
			if (coins->move(this_player())==MOVE_OK) {
				if (number==1) word = "coin" ; else word="coins" ;
				write ("You don't have that many "+type+" but you do have "+newnum+" "+newtype+".\n") ;
				write ("The banker withdraws "+newnum+" "+newtype+" from your account and hands you "+number+" "+type+" "+word+".\n") ;
				say (this_player()->query("cap_name")+" withdraws some "+type+".\n") ;
				card -> add_val (newtype,-newnum) ;
				return 1 ;
			}
		}
	}
// Ending comment. If we get here, it means he didn't have enough of any
// kind of coin to make his requested withdrawal.
	notify_fail ("You don't have enough coins of any type to withdraw that amount of money.\n") ;
	return 0 ;
}

// Deposit allows a player to put his money in the bank.

int deposit(string str) {

	int i, number ;
	string type, word ;
	object card ;

	if (!str) {
		notify_fail("Usage: deposit <number> <type>\n") ;
		return 0 ;
	}
	if (sscanf(str,"%d %s",number,type)!=2) {
		notify_fail("Usage: deposit <number> <type>\n") ;
		return 0 ;
	}
	if (number<1) {
		notify_fail("You can only deposit positive numbers of coins.\n") ;
		return 0 ;
	}
	i = this_player()->query("wealth/"+type) ;
	if (i<number) {
		notify_fail ("You haven't got that many "+type+" to deposit.\n") ;
		return 0 ;
	}
	card = present("bank card",this_player()) ;
	if (!card) {
		notify_fail ("You'll need to open an account first.\n") ;
		return 0 ;
	}
	this_player()->set("wealth/"+type,i-number) ;
	this_player()->set("capacity",this_player()->query("capacity")+number) ;
	card->add_val(type,number) ;
	if (number==1) word="coin" ; else word="coins" ;
	write ("You deposit "+number+" "+type+" "+word+" in the bank.\n") ;
	say (this_player()->query("cap_name")+" deposits some "+type+".\n") ;
	return 1 ;
}
