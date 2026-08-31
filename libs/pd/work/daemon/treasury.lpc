//  Guild System 3
//  Whit
//  Updated Treasury System

#include <money.h>
#include <bank.h>
#include <guild.h>
#include <daemons.h>
#define DIR "/d/guilds/data/treasury/"

mapping summary;
mapping account;
int valid_access(string who);
int account_exists(string who);

void create() {
    seteuid(getuid());
   summary=([]);
    account = ([]);
}

int valid_access(string who) {
    if(GUILD_D->valid_master(who)) return 1;
	return GUILD_D->check_rights(who, GUILD_D->query_guild(who),
		({"leader"}) );
}

mapping query_balance(string guild) {
    if(!account_exists(guild)) return 0;
    else restore_object(DIR+"/"+guild);
    return account;
}

int deposit(string guild, int amount, string type) {
    if(!guild || !amount || !type) return BAD_DATA;
    restore_object(DIR+guild);
    if(member_array(type, HARD_CURRENCIES) == -1) return BAD_MONEY;
    if(amount < 1) return BAD_DATA;
    if(!account_exists(guild)) {
	return NO_ACCOUNT;
    }
    if(!account) return NO_ACCOUNT;
    if(!account[type]) account[type] = amount;
    else account[type] += amount;
    log_file("bank", this_player()->query_cap_name()+" deposited "+amount+
      " coins in "+guild+":"+ctime(time())+"\n");
    save_object(DIR+"/"+guild);
    return TRANSACTION_OK;
}

int withdraw(string who, string guild, int amount, string type) {
    if(!who || !guild || !amount || !type) return BAD_DATA;
    restore_object(DIR+guild);
    if(!valid_access(who)) return BAD_ACCESS;
    if(amount < 1) return BAD_DATA;
    if(member_array(type, HARD_CURRENCIES) == -1) return BAD_MONEY;
    if(!account_exists(guild)) {
	return NO_ACCOUNT;
    }
    if(!account) return NO_ACCOUNT;
    if(!account[type] || account[type] < amount)
	return INSF;
    else account[type] -= amount;
    log_file("bank", who+" withdrew "+amount+" coins in "+guild+
      ":"+ctime(time())+"\n");
    save_object(DIR+"/"+guild);
    return TRANSACTION_OK;
}

int open_account(string guild) {
    if(account_exists(guild)) {
	return ALREADY_EXISTS;
    }
    account = ([ "platinum":0, "gold":0, "electrum":0, "silver":0, 
      "copper":0 ]);
    save_object(DIR+"/"+guild);
    return TRANSACTION_OK;
}

int close_account(string guild) {
    if(!guild) return BAD_DATA;
    restore_object(DIR+guild);
    if(!account_exists(guild)) {
	return NO_ACCOUNT;
    }
    if(!account) return NO_ACCOUNT;
    rm(DIR+guild+".o");
    return TRANSACTION_OK;
}

int account_exists(string who) {
    if(!file_exists(DIR+"/"+who+".o")) return 0;
    else return 1;
}


int update_summary(string guild, string name, string cur, int amt) {
   restore_object(DIR+guild);
   if(!summary) summary = ([]);
   if(!summary[name]) summary[name]=([]);
   summary[name][cur] += amt;
   save_object(DIR+guild);
}

string read_summary(string guild) {
   int i, x;
   string *k, *k2, out="";

   restore_object(DIR+guild);
   out="--------------------- Treasury Summary Report ---------------------\n";
   if(!summary || summary == ([])) return "No reports.\n";
   i=sizeof(k=keys(summary));
   while(i--) {
      out += "%^BLUE%^%^BOLD%^"+k[i]+":\n";
      x=sizeof(k2=keys(summary[k[i]]));
      while(x--)
        out += "    "+summary[k[i]][k2[x]]+"\n";
   }
   return out;
}


