//	/adm/daemon/bank_d.c
//	from the Nightmare mudlib
//	a daemon to keep track of all player accounts
//	created by Descartes of Borg 28 february 1993 (not a leap year)

#include <security.h>
#include <dirs.h>
#include <money.h>
#include <bank.h>
#include <std.h>

inherit DAEMON;

mapping account;
nosave string current;

int valid_access(string who);
int account_exists(string who);

void create() {
    daemon::create();
    set_no_clean(1);
    current = 0;
    account = ([]);
}

int valid_access(string who) {
    if(!who) return 0;
    if(!this_player()) return 0;
    if((string)this_player()->query_name() != who) return 0;
    return 1;
}

mapping query_balance(string who, string bank) {
    mapping ret;

    if(!who || !bank) return 0;
    if(current != who) {
	current = who;
	if(!account_exists(current)) {
	    current = 0;
	   account = 0;
	    return 0;
	}
        else unguarded((: restore_object, DIR_ACCOUNTS+"/"+current :));
    }
    if(!account) return 0;
    if(!account[bank]) return 0;
    else ret = account[bank];
    account[bank]["transaction"] = 0;
    account[bank]["time"] = time();
    unguarded((: save_object, DIR_ACCOUNTS+"/"+current :));
    return ret;
}

int deposit(string who, string bank, int amount, string type) {
    if(!who || !bank || !amount || !type) return BAD_DATA;
    if(!valid_access(who)) return BAD_ACCESS;
    if(member_array(bank, LISCENSED_BANKS) == -1) return BAD_BANK;
    if(member_array(type, HARD_CURRENCIES) == -1) return BAD_MONEY;
    if(amount < 1) return BAD_DATA;
    if(current != who) {
	current = who;
	if(!account_exists(current)) {
	    current = 0;
	    account = ([]);
	    return NO_ACCOUNT;
	}
        else unguarded((: restore_object, DIR_ACCOUNTS+"/"+current :));
    }
    if(!account) return NO_ACCOUNT;
    if(!account[bank]) return NO_ACCOUNT;
    if(!account[bank][type]) account[bank][type] = amount;
    else account[bank][type] += amount;
    account[bank]["transaction"] = amount;
    account[bank]["time"] = time();
    log_file("bank", sprintf("%s deposited %d %s in %s: (%s)\n",
      who, amount, type, bank, ctime(time())));
    unguarded((: save_object, DIR_ACCOUNTS+"/"+current :));
    return TRANSACTION_OK;
}

int withdraw(string who, string bank, int amount, string type) {
    if(!who || !bank || !amount || !type) return BAD_DATA;
    if(!valid_access(who)) return BAD_ACCESS;
    if(member_array(bank, LISCENSED_BANKS) == -1) return BAD_BANK;
    if(amount < 1) return BAD_DATA;
    if(member_array(type, HARD_CURRENCIES) == -1) return BAD_MONEY;
    if(current != who) {
	current = who;
	if(!account_exists(current)) {
	    current = 0;
	    account = ([]);
	    return NO_ACCOUNT;
	}
        else unguarded((: restore_object, DIR_ACCOUNTS+"/"+current :));
    }
    if(!account) return NO_ACCOUNT;
    if(!account[bank]) return NO_ACCOUNT;
    if(!account[bank][type] || account[bank][type] < amount)
	return INSF;
    else account[bank][type] -= amount;
    account[bank]["transaction"] = -amount;
    account[bank]["time"] = time();
    log_file("bank", who+" withdrew "+amount+" coins in "+bank+": "+ctime(time())+"\n");
    unguarded((: save_object, DIR_ACCOUNTS+"/"+current :));
    return TRANSACTION_OK;
}

int open_account(string who, string bank) {
    if(!who || !bank) return BAD_DATA;
    if(!valid_access(who)) return BAD_ACCESS;
    if(member_array(bank, LISCENSED_BANKS) == -1) return BAD_BANK;
    if(current != who) {
	current = who;
	if(!account_exists(current)) account = ([]);
        else unguarded((: restore_object, DIR_ACCOUNTS+"/"+current :));
    }
    if(!account) account = ([]);
    if(account) {
	if(account[bank] && account[bank] != ([]))
	  return ALREADY_EXISTS;
    }
    account[bank] = ([ "transaction":0, "time":0, "platinum":0, "gold":0, "electrum":0, "silver":0, "copper":0 ]);
    unguarded((: save_object, DIR_ACCOUNTS+"/"+current :));
    return TRANSACTION_OK;
}

int close_account(string who, string bank) {
    if(!who || !bank) return BAD_DATA;
    if(!valid_access(who)) return BAD_ACCESS;
    if(member_array(bank, LISCENSED_BANKS) ==-1) return BAD_BANK;
    if(current != who) {
	current = who;
	if(!account_exists(current)) {
	    current = 0;
	    account = ([]);
	    return NO_ACCOUNT;
	}
        else unguarded((: restore_object, DIR_ACCOUNTS+"/"+current :));
    }
    if(!account) return NO_ACCOUNT;
    if(!account[bank]) return NO_ACCOUNT;
    map_delete(account, bank);
    unguarded((: save_object, DIR_ACCOUNTS+"/"+current :));
    return TRANSACTION_OK;
}

int account_exists(string who) {
    if(!unguarded((: file_exists, DIR_ACCOUNTS+"/"+who+__SAVE_EXTENSION__ :)))
      return 0;
    else return 1;
}

string *query_bank_accounts(string who) {
    if(current != who) {
	current = who;
	if(!account_exists(current)) {
	    account = ([]);
	    current = 0;
	    return ({});
	}
        else unguarded((: restore_object, DIR_ACCOUNTS+"/"+current :));
    }
    if(!account) return ({});
    return keys(account);
}

mapping account_summary(string who) {
    mapping borg;
    string *banks, *currs;
    int i, j, x;

    if(!((int)master()->valid_apply(({})))) return ([]);
    if(current != who) {
        current = who;
        if(!account_exists(current)) {
            current = 0;
            account = ([]);
            return ([]);
        }
        else unguarded((: restore_object, DIR_ACCOUNTS+"/"+current :));
    }
    borg = ([]);
    i = sizeof(banks = keys(account));
    while(i--) {
        j = sizeof(currs = keys(account[banks[i]]));
        while(j--) {
            if(currs[j] == "time" || currs[j] == "transaction") continue;
            if(borg[currs[j]]) borg[currs[j]] += account[banks[i]][currs[j]];
            else borg[currs[j]] = account[banks[i]][currs[j]];
            x = currency_rate(currs[j]);
            if(x) borg["base"] += account[banks[i]][currs[j]]/x;
        }
    }
    return borg;
}
