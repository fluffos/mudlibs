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

//  07 Dec 98   Cyanide de-carded this thing.
//  22 May 99   Cyanide converted coins to credits.


#include <move.h>
#include <mudlib.h>
#include <money.h>

string sign();

inherit ROOM ;

void create() {
	::create() ;
	seteuid(getuid()) ;
}

void init() {
	add_action ("open_account", "open") ;
	add_action ("deposit", "deposit") ;
	add_action ("withdraw", "withdraw") ;
	add_action ("balance", "balance") ;
	add_action ("read", "read") ;
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

	if (this_player()->query("bank_balance")) {
		write ("You already have an account.\n") ;
		return 1 ;
	}

	i = this_player()->query("wealth") ;
	if (i<25) {
		write ("You need to have 25 gold credits to open an account.\n") ;
		return 1 ;
	}
	this_player()->debit(25) ;
	//ob = clone_object (BANK_CARD_FILE) ;
	//ob -> assign(this_player()) ;
	write ("You now have an account with the Bank of "+MUD_NAME+".\n") ;
	say (this_player()->query("cap_name")+" opens a bank account.\n") ;
	this_player()->set("bank_balance", 1 ) ;
	return 1 ;
}

// Withdraw allows a player to withdraw money from his bank account. The
// player must have his card to permit this. The function checks his card
// to make sure he has enough money to make the withdrawal.
// The bank knows about conversion: if the player wants to withdraw 5 gold
// and has 0 gold and 50 silver in the bank, the bank withdraws his 50 silver
// and gives him the 5 gold. More comments on this below.

int withdraw (string str) {	
	int i, oldval, newval, newnum ;
	string type, word, newtype ;
	object card, credits ;
	string *types ;

	sscanf(str,"%d", i);

	if (!i) {
		notify_fail ("Usage: withdraw <number> \n") ;
		return 0 ;
	}

	if (i<1) {
		notify_fail ("You can only withdraw positive numbers of credits.\n") ;
		return 0 ;
	}

	oldval = TP->query("bank_balance");
	if (!oldval) {
		notify_fail ("You don't have any money in the bank!\n") ;
		return 0 ;
	}
	if (oldval>=i) {
	    oldval = i/20;
		this_player()->credit(i-oldval);
		TP->add("bank_balance", -1*i);
		if (i==1) word = "credit" ; else word="credits" ;
		write("The banker says, thats "+i+" credits minus 5 percent...\n");
		write ("The banker hands you "+(i-oldval)+" "+word+".\n") ;
		say (this_player()->query("cap_name")+" withdraws some credits.\n") ;
	} else {
// If the following lines (to the ending comment) are in place, if the player
// can't withdraw what he requests, the bank will give him the same amount
// of money in some other creditage if it can. For example, in the default
// credit system, if he requests 20 gold but doesn't have that, the bank will
// give him 2 platinum or 200 silver instead. This enables clever players
// to change creditage for free. If you have a credit exchange which charges
// a fee, you need to either rip this out, institute a fee on withdrawals,
// or allow smart players to get a free ride...

// Ending comment. If we get here, it means he didn't have enough of any
// kind of credit to make his requested withdrawal.
	write("You don't have enough credits to withdraw that amount of money.\n") ;
	}

	return 1 ;
}

// Deposit allows a player to put his money in the bank.

int deposit(string str) {
	int i, wealth;
	string type, word ;
	object card ;

	sscanf(str,"%d", i);
	if (!i) {
		notify_fail("Usage: deposit <number>\n") ;
		return 0 ;
	}

	if (i < 0){
		notify_fail("You can only deposit positive numbers of credits.\n") ;
		return 0 ;
	}

	wealth = this_player()->query("wealth") ;

	if (wealth<i) {
		notify_fail ("You haven't got that many credits to deposit.\n") ;
		return 0 ;
	}

	if (!TP->query("bank_balance")) {
		notify_fail ("You'll need to open an account first.\n") ;
		return 0 ;
	}
	this_player()->debit(i) ;
	if (i==1) word="credit" ; else word="credits" ;
	write ("You deposit "+i+" "+word+" in the bank.\n") ;
	say (this_player()->query("cap_name")+" deposits some credits.\n") ;
	TP->add("bank_balance", i);
	return 1 ;
}

int balance() {
    int i = TP->query("bank_balance");
    string word;

    if (i && i>0) {
        word = (i>1)?"credits":"credit";

        write("You currently have "+i+" "+word+
        " in your account.\n");
    } else {
        write("You have no money in the bank.\n");
    }

    return 1;
}

int read() {
    write(sign());
    return 1;
}

string sign() {
    string sign = (@EndSign
    open account    Open An Account

    balance         Check your balance
    withdraw #      Withdraw credits
    deposit #       Deposit credits

    * Note: There is a 5% surcharge on all withdrawals
EndSign
    );

    return sign;
}

/* EOF */
