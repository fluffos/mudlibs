// A shop of sorts, coded by Chronos from scratch.
// (04-15-98) Coded by Chronos@NK.
//            - Added WizInfo stats for wizards.
//            - Every (x) resets, a delivery is made and the stock is updated.
//              Basically there is a 20% chance that 1 - 2 items of each
//              type will be delivered.  20% per item, that is.
//            - Shop keeps track of how many items are left in stock.
//            - No transactions can be made without the shopkeeper present.
// (04-15-98) Chronos stole his own code from the Jester's shop cuz he
//            liked it so much. :)
// (04-18-98) Chronos decided to make it an inheritable shop for /std
//            New props for this room:
//                      - restock_msg
//                      - shopkeeper
//                      - shop_dir
// (06-20-99) Cyanide changed coins to credits.

#include <mudlib.h>
#include <move.h>

#define ITEM(x) (string)TO->query("shop_dir")+"x"

// How many room resets should happen before you restock some.
#define RESETS 2
inherit ROOM ;

// Prototypes.  yay.
int add_some_stock() ;

// This defines the stock of the store the first time it's loaded.
// Every time the store resets, it _might_ start replacing ITEMs
// or adding more to the stock.
mapping stock = ([  ]) ;

int reset_count ;

void create() {
    seteuid(getuid());
    set ("light", 1) ;
    set("short", "A generic shop.") ;
    // Default restock msg.
    set("restock_msg", @ENDRESTOCK
A delivery man enters the room and sets some packages on the counter.
He fills out some paperwork, nods at you, and leaves.
ENDRESTOCK
    );
    // default shopkeeper
    set("shopkeeper", "Habib") ;
    set("shop_dir", "/obj/obj") ;
    set ("long", @ENDLONG
You stand in a generic shop.

Commands are: list, buy <item>
ENDLONG
    );
    ::create();
    reset();
}

void init() {
    add_action("sell", "sell") ;
    add_action("buy_func", "buy");   
    add_action("list", "list") ;
}

int sell() {
    if (!present(TO->query("shopkeeper"), TO)) {
	write("There is no one here to sell to.\n") ;
	return 1;
    }
    write(capitalize(TO->query("shopkeeper"))+" shakes his head.\n"+capitalize(TO->query("shopkeeper"))+" says: We don't buy things here, we only sell.\n");
    return 1;
}

int list() {
    object ob ;
    int i, x, value ;
    string *Keys;
    int *How_many;
    if (!present(TO->query("shopkeeper"), TO) && !wizardp(TP)) {
	write("You can't do anything without the store owner!\n") ;
	return 1;
    }
    if (!stock || !sizeof(stock)) {
	write("You can't buy anything right now.\n") ;
	return 1;
    }
    write(
@ENDLONG
The following items are available to you:

Name                            Cost
-----------------------------------------
ENDLONG
    );
    Keys = keys(stock) ;
    How_many = values(stock) ;
    if (!Keys || !How_many) {
	write("Nothing.\n");
	return 1;
    }
    for(i=0;i<sizeof(Keys);i++) {
	if (!How_many[i]) continue ;
	ob=clone_object((string)TO->query("shop_dir") + Keys[i]) ;
	if (!ob) continue ;
	value = ob->query("value") ;
	printf("%-30s %d credit", capitalize(ob->query("short")),
	  value) ; 
	if (value != 1) write("s.") ;
	else write(".") ;
	if (wizardp(TP)) printf("  \t[WizInfo] %d in stock.", How_many[i]) ;
	write("\n") ;
	continue ;
    }
    if (wizardp(TP))
	write("\n[WizInfo] The stock will replenish itself in "+(RESETS-reset_count)+" resets.\n") ;
    return 1;
}

int buy_func(string str) {
    int i;
    int x;
    int cost ;
    int wealth;
    int * How_many ;
    string *Keys ;
    object ob;
    if (!present(TO->query("shopkeeper"), TO)) {
	write("You can't do that without the shopkeeper being here.\n") ;
	return 1;
    }
    if (!str) {
	write("Buy what?\n");
	return 1;
    }
    Keys = keys(stock) ;
    How_many = values(stock) ;
    if (!Keys || !How_many) {
	write("There is nothing available for you to buy right now.\n");
	return 1;
    }
    x = -1 ; // This lets us know we didn't find it in stock.
    for(i=0;i<sizeof(Keys);i++) {
	if (!How_many[i]) continue ;        // If there aren't any..
	ob=clone_object((string)TO->query("shop_dir")+Keys[i]) ;
	if (!ob) continue ;                 // Can't clone it.. can't buy it.
	if (ob->id(str)) {
	    x = i ;   // We want this item number.
	    break ;  // found out item, break out of the for loop.
	}
    }
    if (x==-1) {
	write(capitalize(TO->query("shopkeeper"))+" says: We aren't selling any of those right now.\n");
	return 1;
    }
    wealth = this_player()->query("wealth");
    if (!wealth) {
	write(capitalize(TO->query("shopkeeper"))+" says: You need money to buy things in this store.\n");
	return 1;
    }
    cost = ob->query("value");
    if (!cost) write(capitalize(TO->query("shopkeeper"))+" says: Guess this one is on the house.\n");
    if (wealth<cost) {
	write(capitalize(TO->query("shopkeeper")) + " says: You don't have enough money for that.\n") ;
	return 1;
    }
    switch(cost) {
    case 0: write(capitalize(TO->query("shopkeeper"))+" shrugs at you.\n"); break ;
    case 1: write("You toss a single credit to "+capitalize(TO->query("shopkeeper"))+".\n");  break ;
    default: write("You hand "+cost+" credits to "+capitalize(TO->query("shopkeeper"))+".\n"); break ;
    }
    say(TPN+ " hands some credits to "+capitalize(TO->query("shopkeeper"))+".\n");
    TP->add("wealth", -1 * cost) ; // take the credits.
    if (ob->move(TP) != MOVE_OK) {
	write(capitalize(TO->query("shopkeeper"))+" says: You can't hold this item right now.  Sorry.\n");
	say(capitalize(TO->query("shopkeeper"))+" shakes his head at "+TPN+" and hands back the money.\n");
	write(capitalize(TO->query("shopkeeper"))+" refunds your money.\n");
	TP->add("value", cost) ; // refund.
	return 1;
    }
    // If we make it here, we're home free.
    write(capitalize(TO->query("shopkeeper"))+" gives "+ob->query("short")+" to you.\n");
    say(capitalize(TO->query("shopkeeper"))+" gives "+ob->query("short")+" to "+TPN+".\n") ;
    // Remove the item from stock./
    stock[Keys[x]] = How_many[x]-1 ;
    return 1;
}

void reset() {
    reset_count++ ;
    if (reset_count == RESETS) {
	reset_count = 0 ;
	add_some_stock() ;
    }
    ::reset() ;
}

int add_some_stock() {
    int i;
    string *Keys;
    int *How_many;
    Keys = keys(stock) ;
    How_many = values(stock) ;
    if (!Keys || !How_many) return 1;  // Oops. Fuck it.
    for(i=0;i<sizeof(Keys);i++) {
	if (!random(5)) // 20% chance of restocking each item.
	    stock[Keys[i]] = How_many[i] + random(3) + 1;
	continue ;
    }
    message("store", (string)TO->query("restock_msg"), TO) ;
    return 1;
}

/* EOF */
