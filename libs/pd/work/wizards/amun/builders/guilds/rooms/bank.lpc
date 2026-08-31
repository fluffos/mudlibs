#include <std.h>
#include <daemons.h>
#include <money.h>
#include <bank.h>
#include <guild.h>

#define BANK_ID "tirun"

inherit VAULT;

string center_str(string str, int size) {
    int a, b, c;
    string out;
    if(!size) size = 80;
    a = strlen(str);
    b = (size - a) / 2;
    c = b;
    out = "";
    while(b--) out += " ";
    out += str;
    while(c--) out += " ";
    return out;
}

string align(string what, int x) {
    int y;
    string out;
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
	out = what[0..x-1] + " ";
	return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}

void init() {
    ::init();
    add_action("read", "read");
    add_action("open", "open");
    add_action("close", "close");
    add_action("deposit", "deposit");
    add_action("withdraw", "withdraw");
    add_action("balance", "balance");
    add_action("exchange", "exchange");
}

void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set_short("Guild Town Bank");
    set_long("%^BOLD%^WHITE%^The Tirun Bank, Guild Town Branch.\n%^BOLD%^WHITE%^The bank is well kept by the Tirunian government, but is pretty old.  Both the walls and floor are a uniform white, with very little furnishing in the room at all.  Citizens of Tirun come here to deposit their life savings.  A sign by the teller details all commands.%^RESET%^");
    set_exits(([ "east": GROOM"board_room" ]));
}

void reset() {
    ::reset();
    if(!present("guard"))
	new(GMOB"bankguard")->move(this_object());
}

int exchange(string str) {
    string from, to;
    int amount;

    if(!str) {
	notify_fail("Correct syntax: <exchange # type for type>\n"+
	  "ex: <exchange 100 gold for copper>\n");
	return 0;
    }
    if(sscanf(str, "%d %s for %s", amount, from, to) !=3) {
	notify_fail("Correct syntax: <exchange # type for type\nex: "
	  "<exchange 100 gold for copper>\n");
	return 0;
    }
    if(amount < 1) {
	notify_fail("That would be a nifty trick indeed!\n");
	return 0;
    }
    if((int)this_player()->query_money(from) < amount) {
	notify_fail("You do not have that much of that currency.\n");
	return 0;
    }
    if(member_array(from, HARD_CURRENCIES) == -1)
	return notify_fail("The bank does not support "+from+".\n");
    if(member_array(to, HARD_CURRENCIES) == -1)
	return notify_fail("The bank does not support "+to+".\n");
    this_player()->add_money(from, -(to_int(amount*0.01)+amount));
    switch(from) {
    case "platinum": amount = amount*10;
    case "gold": amount = amount*10;
    case "electrum": amount = amount*5;
    case "silver": amount = amount*2;
    case "copper": break;
    default: write("Invalid currency.");
    }
    switch(to) {
    case "platinum": amount = amount/10;
    case "gold": amount = amount/10;
    case "electrum": amount = amount/5;
    case "silver": amount = amount/2;
    }
    this_player()->add_money(to, amount);
    message("my_action", "You exchange your "+from+" coins for "+amount+" "+to,
      this_player());
    message("other_action", (string)this_player()->query_cap_name()+" exchanges some money.", this_object(), ({ this_player() }));
    return 1;
}

int close(string str) {
    int i;
    mapping money;

    if(!str || str != "account") return 0;
    money = (mapping)BANK_D->query_balance(
      (string)this_player()->query_name(), BANK_ID);
    if(!money || money == ([])) {
	write("The teller says: You have no account here to close!");
	say(this_player()->query_cap_name()+" tries to close a "
	  "non-existent account!");
	return 1;
    }
    for(i=0; i<sizeof(HARD_CURRENCIES); i++) {
	if(money[HARD_CURRENCIES[i]]) 
	    this_player()->add_money(HARD_CURRENCIES[i], money[HARD_CURRENCIES[i]]);
    }
    write("The teller hands you all your money.");
    say(sprintf("%s collects all %s money from the teller.",
	(string)this_player()->query_cap_name(), possessive(this_player())));
    BANK_D->close_account((string)this_player()->query_name(), BANK_ID);
    return 1;
}

int open(string str) {
    int x;

    if(!str || str != "account") return 0;
    x = (int)BANK_D->open_account((string)this_player()->query_name(), BANK_ID);


    if(x != TRANSACTION_OK) {
	write("You already have an account here!");
	return 1;
    }
    write("You open up an account at the Tirun Merchants Bank, Guild Town Branch.");
    say(this_player()->query_cap_name()+" opens an account.");
    return 1;
}

int balance(string str) {
    mapping account;
    int i;
    int total;
    string out;

    account = (mapping)BANK_D->query_balance((string)this_player()->query_name(), BANK_ID);
    if(!account || account == ([])) {
	write("The teller says: You have no account here!");
	return 1;
    }
    say(this_player()->query_cap_name()+" asks for account information.");
    i = sizeof(HARD_CURRENCIES);
    out = "\n%^BLUE%^=+=+=+=+=+=+=+=+%^BOLD%^("
    "%^WHITE%^Bank of Tirun - Guild Town Branch%^BLUE%^)"
    "%^RESET%^BLUE%^=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n";
    while(i--) {
	out += align(capitalize(HARD_CURRENCIES[i]), 9)+": "+
	account[HARD_CURRENCIES[i]]+" coins.\n";
    }
    total = account["gold"];
    total += account["platinum"]*10; 
    total += account["electrum"]/10;
    total += account["silver"]/500;
    total += account["copper"]/1000;
    if(total>0) out += "\nTotal: "+total+" in gold.\n";
    else out += "\nYour acount is empty!\n";
    out += "%^RESET%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
    "+=+=+=+=+=+=+=+=+=+=%^RESET%^";
    write(out);
    return 1;
}

int deposit(string str) {
    string type, *cur;
    mapping money;
    int x, amount;

    if(!str) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if (str=="all")
    {
	money = (mapping)BANK_D->query_balance(
	  (string)this_player()->query_name(), BANK_ID);
	if (!money || money == ([]) )
	    return notify_fail("You do not have an account here.\n");
	money = ([]);
	cur = this_player()->query_currencies();
	if (!sizeof(cur)) return notify_fail("You do not have any money!\n");
	x = sizeof(cur);
	while(x--)
	{
	    this_player()->force_me("deposit "+this_player()->query_money(cur[x])+" "+cur[x]);
	}
	return 1;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if((int)this_player()->query_money(type) < amount) {
	notify_fail("The teller says: You do not have that much money!\n");
	return 0;
    }
    x = (int)BANK_D->deposit(
      (string)this_player()->query_name(), BANK_ID, amount, type);
    if(x != TRANSACTION_OK) {
	switch(x) {
	case NO_ACCOUNT:
	    notify_fail("The teller says: You have no account here!\n");
	    break;
	case BAD_MONEY:
	    notify_fail("The teller says: That is not a real money type!\n");
	    break;
	default: notify_fail("The teller says: You cant do that!\n");
	}
	return 0;
    }

    this_player()->add_money(type, -amount);
    write("The teller takes your "+amount+" "+type+" coins.");
    say(this_player()->query_cap_name()+" deposits some money.");
    return 1;
}

int withdraw(string str) {
    string type;
    int x, amount;

    if(!str) {
	notify_fail("Correct syntax: <withdraw [amount] [type]>\n");
	return 0;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <withdraw [amount] [type]>\n");
	return 0;
    }
    if(amount < 0) {
	notify_fail("The teller says: That would be a neat trick!\n");
	return 0;
    }
    x = (int)BANK_D->withdraw(
      (string)this_player()->query_name(), BANK_ID, amount, type);
    if(x != TRANSACTION_OK) {
	switch(x) {
	case NO_ACCOUNT:
	    notify_fail("The teller says: You have no account here!\n");
	    break;
	case BAD_MONEY:
	    notify_fail("The teller says: That is not a real money type!\n");
	    break;
	default: notify_fail("The teller says: You cant do that!\n");
	}
	return 0;
    }
    this_player()->add_money(type, amount);
    write("The teller gives you your "+amount+" "+type+" coins.");
    say(this_player()->query_cap_name()+" withdraws some money.");
    return 1;
}

int read(string str) {
    if(str != "sign") return notify_fail("Read what?\n");
    message("info",
      "You may do any of the following at Tirun Merchants Bank, Guild Town Branch:\n"
      "<open account>\nWill open an account for you. "
      "\n\n"
      "<close account>\nCloses your account.\n\n"
      "<balance>\nGives you account balance information.\n\n"
      "<deposit [#] [type]>\nDeposits # of currency of type.\n\n"
      "<withdraw [#] [type]>\nWithdraws # of currency of type.\n\n"
      "<exchange [#] [type1] for [type2]>\nExchanges currencies.\n"
      "There is a 10% charge.", this_player());
    return 1;
}
