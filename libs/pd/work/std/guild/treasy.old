inherit "/std/room";
string guild;

#define TREASURY_D "/daemon/treasury"
#define DONATE 1
#define WITHDRAW 2
#include <bank.h>
#include <money.h>

void set_guild(string str) { guild = str; }
string query_guild() { return guild; }
int paydues(string str);

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

int do_scroll_write(string cname, int dtype, int amount, string mtype) {
    string tmp;
    tmp = "";
    switch(dtype) {
    case DONATE:

	if( file_exists("/d/guilds/data/scrolls/"+guild) ) {
	    tmp += read_file("/d/guilds/data/scrolls/"+guild);
	}
	if(file_exists("/d/guilds/data/scrolls/"+guild)) {
	    rm("/d/guilds/data/scrolls/"+guild);
	}
	write_file("/d/guilds/data/scrolls/"+guild,
	  align(cname, 20)+" %^GREEN%^%^BOLD%^donates%^RESET%^   : "+
	  align(amount+" "+mtype, 17)+" "+ctime(time())+"\n"+tmp);
	return 1;
	break;

    case WITHDRAW:
	if(file_exists("/d/guilds/data/scrolls/"+guild))
	    tmp += read_file("/d/guilds/data/scrolls/"+guild);
	if(file_exists("/d/guilds/data/scrolls/"+guild))
	    rm("/d/guilds/data/scrolls/"+guild);
	write_file("/d/guilds/data/scrolls/"+guild,
	  align(cname, 20)+" %^RED%^%^BOLD%^withdraws%^RESET%^ : "+
	  align(amount+" "+mtype, 17)+" "+ctime(time())+"\n"+tmp);
	return 1;
	break;
    default:
	return 0;
	break;
    }
}

void init() {

    ::init();
   if(this_player()->query_original_guild()!=lower_case(guild) && 
     !wizardp(this_player()) && guild != "The Guilds") return;
    add_action("read", "read");
    add_action("open", "open");
    add_action("close", "close");
    add_action("donate", "donate");
    add_action("withdraw", "withdraw");
    add_action("balance", "balance");
    add_action("paydues", "pay");
}

int close(string str) {
    int i;
    mapping money;
    if(!wizardp(this_player())) return 0;
    if(!str || str != "account") return 0;
    money = (mapping)TREASURY_D->query_balance(guild);
    if(!money || money == ([])) {
	write("There is currently no account for the guild "+guild+".\n");
	return 1;
    }
    for(i=0; i<sizeof(HARD_CURRENCIES); i++) {
	if(money[HARD_CURRENCIES[i]]) 
	    this_player()->add_money(HARD_CURRENCIES[i],
	      money[HARD_CURRENCIES[i]]);
    }
    write("Account closed.\n");
    TREASURY_D->close_account(guild);
    return 1;
}

int open(string str) {
    int x;
    if(!wizardp(this_player())) return 0;
    if(!str || str != "account") return 0;
    x = (int)TREASURY_D->open_account(guild);
    if(x != TRANSACTION_OK) {
	write("The guild "+guild+" already has an account.\n");
	return 1;
    }
    write("The treasury for the guild "+guild+" is ready and now active.\n");
    return 1;
}

int balance(string str) {
    mapping account;
    int i;
    int total;
    string out;
    account = (mapping)TREASURY_D->query_balance(guild);
    if(!account) {
	write("There is no account currently setup for your guild.\n");
	return 1;
    }
    say(this_player()->query_cap_name()+" asks for treasury balance "
      "information.");
    i = sizeof(HARD_CURRENCIES);
    out = "\n%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+%^BOLD%^(%^RESET%^%^BOLD%^"
    "Treasury of "+center_str(capitalize(guild), 10)+"%^BOLD%^%^BLUE%^)"
    "%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n";
    while(i--) {
	out += align(capitalize(HARD_CURRENCIES[i]), 9)+": "+
	account[HARD_CURRENCIES[i]]+" coins.\n";
    }
    total = account["gold"];
    total += account["platinum"]*2; 
    total += account["electrum"]/100;
    total += account["silver"]/500;
    total += account["copper"]/1000;
    if(total>0) out += "\nTotal: "+total+" in gold.\n";
    else out += "\nThe treasury is empty!\n";
    out += "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    "+=+=+=+=+=+=+=+=+=+=%^RESET%^";
    write(out);
    return 1;
}

int donate(string str) {
    string type, *cur, tmp;
    mapping money;
    int x, amount;
    if(!str) {
        notify_fail("Correct syntax: <donate [amount] [type]>\n");
	return 0;
    }
    if (str=="all")
    {
	money = (mapping)TREASURY_D->query_balance(guild);
	if (!money)
	    return notify_fail("There is currently no treasury made for your "
	      "guild.\n");
	cur = this_player()->query_currencies();
	if (!sizeof(cur)) return notify_fail("You have no money to donate!\n");
	x = sizeof(cur);
	while(x--)
            this_player()->force_me("donate "+this_player()->query_money(cur[x])
              +" "+cur[x]);
	return 1;
    }

    if(sscanf(str, "%d %s", amount, type) != 2) {
        notify_fail("Correct syntax: <donate [amount] [type]>\n");
	return 0;
    }
    if((int)this_player()->query_money(type) < amount) {
	notify_fail("You do not have that much money!\n");
	return 0;
    }
    x = (int)TREASURY_D->deposit(guild, amount, type);
    if(x != TRANSACTION_OK) {
	switch(x) {
	case NO_ACCOUNT:
	    notify_fail("There is no treasury set up for your guild.\n");
	    break;
	case BAD_MONEY:
	    notify_fail("That is not a real money type!\n");
	    break;
	default: notify_fail("Unknown error :"+x+".\n");
	}
	return 0;
    }
    this_player()->add_money(type, -amount);
    TREASURY_D->update_summary(this_player()->query_original_guild(), this_player()->query_name(), type, amount);
    write("You donate "+amount+" "+type+" coins into your guild's treasury.\n");
    say(this_player()->query_cap_name()+" donates some money.");
    if(this_player()->query_invis()) tmp = capitalize(this_player()->query_name());
    else tmp = this_player()->query_cap_name();
    if(!do_scroll_write(tmp, DONATE, amount, type)) 
    {
	write("Error writing to scroll.  Skipping.\n");
	write_file("/d/guilds/bugs", this_player()->query_cap_name()+" DONATE "+

	  amount+" "+type+"\n");
	return 1;
    }
    return 1;
}
int withdraw(string str) {
    string type, tmp;
    object tpname;
    int x, amount;
    tpname = this_player()->query_cap_name();
    if(!str) {
	notify_fail("Correct syntax: <withdraw [amount] [type]>\n");
	return 0;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <withdraw [amount] [type]>\n");
	return 0;
    }
    if(this_player()->query_guild() != query_guild() &&
      !wizardp(this_player())) {
	write_file("/d/guilds/ILLEGAL_TRANSACTION", 
	  this_player()->query_name()+" illegal withdraw from "+query_guild()
	  +" on "+ctime(time()))+"\n";
	write("You are not allowed to withdraw.\n");
	return 1;
    }
    if(amount < 0) {
	notify_fail("You must put in a positive integer of money!\n");
	return 0;
    }
    if(amount > 1000000) return notify_fail("You may not withdraw that "
	  "much at a time.\n");
    x = (int)TREASURY_D->withdraw(this_player()->query_name(), guild, amount, 
      type);
    if(x != TRANSACTION_OK) {
	switch(x) {
	case NO_ACCOUNT:
	    notify_fail("There is currently no treasury made for your guild."
	      "\n");
	    break;
	case BAD_MONEY:
	    notify_fail("That is not a real money type!\n");
	    break;
	case BAD_ACCESS:
	    say(this_player()->query_cap_name()+" tries to withdraw but fails."
	      "\n");
	    notify_fail("You are not permitted to do that!\n");
	    break;
	case NO_ACCOUNT:
	    notify_fail("There is no account currently setup for your guild.\n");
	    break;
	default: notify_fail("You are not permitted to do that!\n");
	}
	return 0;
    }
    this_player()->add_money(type, amount);
    TREASURY_D->update_summary(this_player()->query_original_guild(), this_player()->query_name(), type, -amount);
    write("You withdraw "+amount+" "+type+" coins.");
    say(this_player()->query_cap_name()+" withdraws some money.");
    if(this_player()->query_invis()) tmp = capitalize(this_player()->query_name());
    else tmp = this_player()->query_cap_name();
    if(!do_scroll_write(tmp, WITHDRAW, amount, type)

    ) {
	write("Error writing to scroll.  Skipping.\n");
	write_file("/d/guilds/bugs", this_player()->query_cap_name()+" DONATE "+
	  amount+" "+type+"\n");
	return 1;
    }
    return 1;
}

int read(string str) {
    if(str != "sign" && str != "scroll" && str != "scrolls" && str != "summary") 
        return notify_fail("Read what?\n");
    if(str == "sign") {
	message("info",
	  "The following commands may be used to use the treasury.\n\n"
	  "%^BLUE%^%^BOLD%^<balance>            %^RESET%^ |     "
	  "Gives you account balance information.\n"
	  "%^BLUE%^%^BOLD%^<donate [#] [type]> %^RESET%^  |     "
	  "Donate # of currency of type.\n"
	  "%^BLUE%^%^BOLD%^<withdraw [#] [type]>%^RESET%^ |     "
	  "Withdraws # of currency of type.\n"
	  "%^BLUE%^%^BOLD%^<read [sign]>%^RESET%^         |     "
	  "This will show this screen.\n"

          "%^BLUE%^%^BOLD%^<read [summary]>%^RESET%^      |     "
          "This will show a detailed list of \n         "
          "                   withdraw/donations.\n"


	  "%^BLUE%^%^BOLD%^<read [scroll]>%^RESET%^       |     "
	  "This will show you who has withdrew and \n         "
	  "                   deposited from the treasury\n\n", 
	  this_player());
	return 1;
    }
    if(str == "scroll" || str == "scrolls") {
	write(center("           The following people have withdrew/deposited "
	    "money\n\n"));
	if(!file_exists("/d/guilds/data/scrolls/"+guild)) {
	    write(center("There has been no transactions in this treasury.\n"));
	    return 1;
	}
	this_player()->more("/d/guilds/data/scrolls/"+guild);
	say(this_player()->query_cap_name()+" reads over the scroll.");
	return 1;
    }
    if(str == "summary") {
      write(TREASURY_D->read_summary(guild));
      return 1;
    }
}

int paydues(string str)
{
    return "/daemon/paydues_d.c"->cmd_pay(str);
}

