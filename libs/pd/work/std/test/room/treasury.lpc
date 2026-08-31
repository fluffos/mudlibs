//  Coded by Whit
//  Treasury for guilds
#include <teststd.h>
#include <daemons.h>
#include <money.h>
#include <bank.h>
#define BANK_ID "guild"
inherit ROOM;
void init() {
    ::init();
    add_action("read", "read");
    add_action("open", "open");
    add_action("close", "close");
    add_action("deposit", "deposit");
    add_action("withdraw", "withdraw");
    add_action("balance", "balance");
}
int close(string str) {
    int i;
    mapping money;
    if(!wizardp(this_player())) return 0;
    if(!str || str != "account") return 0;
    money = (mapping)BANK_D->query_balance(
      (string)this_player()->query_guild(), BANK_ID    );
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
    if(!wizardp(this_player())) return 0;
    if(!str || str != "account") return 0;
    x = (int)BANK_D->open_account((string)this_player()->query_guild(), BANK_ID);
    if(x != TRANSACTION_OK) {
        write("You already have an account here!");
        return 1;
    }
    write("You open up an account at the Tirun Merchants Bank.");
    say(this_player()->query_cap_name()+" opens an account.");
    return 1;
}
int balance(string str) {
    mapping money;
    int i;
    money = (mapping)BANK_D->query_balance(
      (string)this_player()->query_name(), BANK_ID
    );
    if(!money || money == ([])) {
        write("The teller says: You have no account here!");
        return 1;
    }
    say(this_player()->query_cap_name()+" asks for account information.");
    /* why does this not work?
        write("Last transaction: ");
        if(!money["time"]) write("Opening your account.\n");
        else {
            if(!money["transaction"]) write("Balance (");
            else if(money["transaction"] < 0) write("Withdrawal (");
            else write("Deposit: (");
            write(ctime(money["time"])+")");
        }
    */
    for(i=0; i<sizeof(HARD_CURRENCIES); i++) {
        write(capitalize(HARD_CURRENCIES[i])+": "+
          money[HARD_CURRENCIES[i]]+" coins");
    }
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
          (string)this_player()->query_name(), BANK_ID
        );
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
      (string)this_player()->query_name(), BANK_ID, amount, type
    );
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
        notify_fail("Correct syntax: <deposit [amount] [type]>\n");
        return 0;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
        notify_fail("Correct syntax: <deposit [amount] [type]>\n");
        return 0;
    }
    if(amount < 0) {
        notify_fail("The teller says: That would be a neat trick!\n");
        return 0;
    }
    x = (int)BANK_D->withdraw(
      (string)this_player()->query_name(), BANK_ID, amount, type
    );
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
      "You may do any of the following at Tirun Merchants Bank:\n"
      "<open account>\nWill open an account for you. "
      "\n\n"
      "<close account>\nCloses your account.\n\n"
      "<balance>\nGives you account balance information.\n\n"
      "<deposit [#] [type]>\nDeposits # of currency of type.\n\n"
      "<withdraw [#] [type]>\nWithdraws # of currency of type.\n\n"
      "<exchange [#] of [type1] for [type2]>\nExchanges currencies.\n"
      "There is a 10% charge.", this_player());
    return 1;
}
