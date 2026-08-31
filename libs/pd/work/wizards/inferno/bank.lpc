//	/d/standard/bank.c
//	from the Nightmare mudlib
//	banking room
//	created by Descartes of Borg 28 february 1993

#include <std.h>
#include <daemons.h>
#include <money.h>
#include <bank.h>

#define BANK_ID "tirun"

inherit VAULT;

void init() {
    ::init();
    add_action("Bugga", "Bugga");
    add_action("read", "read");
    add_action("open", "open");
    add_action("close", "close");
    add_action("deposit", "deposit");
    add_action("withdraw", "withdraw");
    add_action("balance", "balance");
    add_action("exchange", "exchange");
}

void lookatvault() {
    write("A huge, secure door that protects the banks money.");
    if(query_open("vault"))
      write("But someone has managed to get it open!");
    else write("It is sealed shut right now.");
}

void create() {
    ::create();

    set_property("magic hold", 10);
    set_property("no castle", 1);
    set_property("light", 2);
    set_property("night light", 2);
    set("short", "Inferno's Master Bank");
    set("long",
	"Welcome to Inferno's Master Bank! All the money from the lands "
        "is stored in the vault here. A sign hangs by the teller window "
        "with a list of commands and modified commands that you can use. "
        "A door leads north into a post office.\n"
        "%^YELLOW%^Note to players:%^RESET%^ Please do not use this bank, "
        "it will result in a severe beating from Inferno if he catches "
        "you poking around in everyone's bank accounts!");
    set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "citizens" : "They are wandering about aimlessly.",
	  "account" : "Youre a damn loon.",
	  "sign" : "Reading it will give you a list of commands.",
	  "teller" : "The teller looks at you impatiently.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads into Inferno's workroom.",
	  "vault" : (: lookatvault :)
           ]) );
  
  set_exits( 
              (["down" : "/wizards/inferno/bank_vault",
                "north" : "/wizards/inferno/post",
                "up": "/wizards/inferno/workroom"]) );

    set_door("vault", "/wizards/inferno/bank_vault", "down", "bank key");
    set_func("vault", "unlock", "do_drunkard");
    present("guard")->force_me("close vault");
    present("guard")->force_me("lock vault with key");
}

void reset() {
    object mon, weapon, key;

    ::reset();
    if(!present("guard")) {
        mon = new(MONSTER);
	mon->set_name("guard");
	mon->set_id( ({ "guard", "giant" }) );
	mon->set("race", "giant");
	mon->set_gender("male");
	mon->set("short", "a huge bank guard");
	mon->set("long", "He hits harder than Hiroshima.");
	mon->set_level(34);
	mon->set_body_type("human");
	mon->set_class("fighter");
	mon->set_spell_chance(10);
	mon->set_spells( ({ "parry", "Bugga" }) );
	mon->set_skill("defense", 70);
	mon->set_skill("blade", 90);
	mon->set_emotes(9,
	  ({ "%^CYAN%^Guard says: %^RESET%^Goddamn thief!",
	     "Guard grunts.",
	     "%^CYAN%^Guard says: %^RESET%^No way youre getting past me!",
	     "%^CYAN%^Guard says: %^RESET%^You disgust me."}), 1);
	mon->set_emotes(3,
	  ({ "Guard munches on a rat pie.", 
	     "%^CYAN%^Guard says: %^RESET%^I hate rogues." }), 0);
	mon->set_wielding_limbs( ({ "right hand", "left hand" }) );
	mon->move(this_object());
        weapon = new(WEAPON);
	weapon->set_name("broadsword");
	weapon->set_id( ({ "broadsword", "sword" }) );
	weapon->set("short", "a broadsword");
	weapon->set("long", "A huge broadsword.");
	weapon->set_wc(93);
	weapon->set_type("blade");
	weapon->set_weight(70);
	weapon->set_value(911);
	weapon->move(mon);
	mon->force_me("wield broadsword");
        key = new(OBJECT);
	key->set_name("key");
	key->set_id( ({ "bank key", "key", "bronze key" }) );
	key->set("short", "Bronze key");
	key->set("long", "An unremarkable bronze key.");
	key->set_weight(29);
	key->set_value(35);
	key->move(mon);
    }
    if(query_reset_number() != 1) {
            present("guard")->force_me("close vault");
            present("guard")->force_me("lock vault with key");
    }
}

int do_drunkard() {
  if(present("guard") && !this_player()->query_invis()) {
    present("guard")->force_me("kill "+(string)this_player()->query_name());
    this_player()->add_follower(present("guard"));
    write("The guard foils you before you can slip the key in!");
    say(this_player()->query_cap_name()+" is foiled trying to break "
	"into the vault!");
	return 0;
    }
  if(this_player()->query_intox()) {
    write("You are fumble around drunkenly with the bank key.");
    say(this_player()->query_cap_name()+" fiddles around drunkenly "
	"with the bank key.");
    return 0;
  }
  return 1;
}

int exchange(string str) {
    string from, to;
    float val;
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
    val = amount/currency_rate(from);
    if(member_array(to, HARD_CURRENCIES) == -1)
      return notify_fail("The bank does not support "+to+".\n");
    this_player()->add_money(from, -(to_int(amount*0.01)+amount));
    amount = to_int(val * currency_rate(to));
    this_player()->add_money(to, amount);
    message("my_action", "You exchange your "+from+" coins for "+amount+" "+to,
      this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      " exchanges some money.", this_object(), ({ this_player() }));
    return 1;
}

/*************Start here******************************Start here*****/
/****Start here*********Start here**********Start here***************/
/*********************************Start here*************************/

int close(string str) {
  int i;
  mapping money;
  string who;
  
  if (str == "account") who = this_player()->query_name();
  else if (!sscanf(str, "%s's account", who)) return 0;

  money = (mapping)BANK_D->query_balance(
	    who, BANK_ID
      );
    if(!money || money == ([])) {
	write("The teller says: There is no account under that name here!");
	say(this_player()->query_cap_name()+" tries to close a "
	    "non-existent account!");
	return 1;
    }
    for(i=0; i<sizeof(HARD_CURRENCIES); i++) {
      if(money[HARD_CURRENCIES[i]]) 
	this_player()->add_money(HARD_CURRENCIES[i], money[HARD_CURRENCIES[i]]);
    }
    write("The teller hands you all your money.");
    say(sprintf("%s collects a lot of money from the teller.",
      (string)this_player()->query_cap_name()));
    BANK_D->close_account(who, BANK_ID);
    return 1;
}

int open(string str) {
    string who;
    int x;

    if(!str) return 0;
    if (str == "account") who = this_player()->query_name();
    else
      if (!sscanf(str, "account for %s", who)) return 0;
    x = (int)BANK_D->open_account(who, BANK_ID);
   
    if(x != TRANSACTION_OK) {
	write(capitalize(who)+" already has an account here!");
	return 1;
    }
    write("You open up an account for "+capitalize(who)+".");
    say(this_player()->query_cap_name()+" opens an account for "+capitalize(who)+".");
    return 1;
}

int balance(string str) {
    string who;
    mapping money;
    int i;

    if (!str) who = this_player()->query_name();
    else who = str;

    money = (mapping)BANK_D->query_balance(
	who, BANK_ID
    );
    if(!money || money == ([])) {
	write("The teller says: No such account.");
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
    string type, *cur, who;
    mapping money;
    int x, amount;

    if (!str) return 0;
    if (str=="all" || sscanf(str, "all for %s", who))
      {
       if (str == "all") who = this_player()->query_name();
       money = (mapping)BANK_D->query_balance(
            who, BANK_ID
      );
      if (!money || money == ([]) )
        return notify_fail("You do not have an account here.\n");
       money = ([]);
       cur = this_player()->query_currencies();
       if (!sizeof(cur)) return notify_fail("You do not have any money!\n");
        x = sizeof(cur);
        while(x--)
         {
           this_player()->force_me("deposit "+this_player()->query_money(cur[x])+" "+cur[x]+" for "+who);
         }
       return 1;
      }
    if (sscanf(str, "%d %s for %s", amount, type, who) != 3)
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    } else who = this_player()->query_name();
    if((int)this_player()->query_money(type) < amount) {
	notify_fail("The teller says: You do not have that much money!\n");
	return 0;
    }
    x = (int)BANK_D->deposit(
	who, BANK_ID, amount, type
    );
    if(x != TRANSACTION_OK) {
	switch(x) {
	    case NO_ACCOUNT:
		notify_fail("The teller says: "+capitalize(who)+" has no account here!\n");
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
    string type, who;
    int x, amount;

    if(!str) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if(sscanf(str, "%d %s from %s", amount, type, who) != 3)
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    } else who = this_player()->query_name();
    if(amount < 0) {
	notify_fail("The teller says: That would be a neat trick!\n");
	return 0;
    }
    x = (int)BANK_D->withdraw(
	who, BANK_ID, amount, type
    );
    if(x != TRANSACTION_OK) {
	switch(x) {
	    case NO_ACCOUNT:
		notify_fail("The teller says: "+capitalize(who)+" has no account here!\n");
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
      "You may do any of the following at Inferno's Master Bank:\n"
      "<open account>\nWill open an account for you.\n"
      "(*) <open account for bob>\n\n"
      "<close account>\nCloses your account.\n"
      "(*) <close bob's account\n\n"
      "<balance>\nGives you account balance information.\n"
      "(*) <balance bob>\n\n"
      "<deposit [#] [type]>\nDeposits # of currency of type.\n"
      "(*) <deposit 10 gold for bob>\n\n"
      "<withdraw [#] [type]>\nWithdraws # of currency of type.\n"
      "(*) <withdraw 10 gold from bob>\n\n"
      "<exchange [#] of [type1] for [type2]>\nExchanges currencies.  There is a 10% charge.\n\n",
      this_player()
    );
    return 1;
}

int pick_lock(string str) {
    if(present("guard") && this_player())
      present("guard")->force_me("kill "+(string)this_player()->query_name());
        this_player()->add_follower(present("guard"));
    return ::pick_lock(str);
}

int Bugga(string str) {
    string limb;
    object ob;
    int amount;

    if(this_player()->is_player()) return 0;
    ob = (object)this_player()->query_current_attacker();
    if(!ob) return 1;
    limb = (string)ob->return_limb();
    if((string)ob->query_class() == "rogue") amount = 24 + random(30);
    else amount = 20 + random(20);
    ob->do_damage(limb, amount);
        tell_object(ob, "The guard bashes your "+limb+" with his "
		    "left fist!");
    tell_room(this_object(), "The guard bashes "+ob->query_cap_name()+"'s "+
	limb+" with his left fist!", ({ ob }));
    return 1;
}


