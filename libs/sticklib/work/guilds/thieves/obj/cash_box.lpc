/* Tax collector */
/* Originally written by Graah */
/* Code cleaned up and donate bug fixed by Colt */
#include <treasure.h>
#include <guild.h>
#include "dirs.h"

#include "/guilds/thieves/thief.h"

#define SAVE_FILE "guilds/thieves/TAX_BOX"

#define TP this_player()
#define QCL query_coder_level()
#define QN query_name()
#define QRN query_real_name()

int pile;

string query_long()
{
    object tm;
    string desc;

    desc =
    "This extremely strong metal chest is made of triply enchanted \
magical black eog.  It is totally unbreakable.";

    if((string)TP->query_guild() == GN_THIEF)
    {
	desc +=
	" Coins can be inserted through a slot on the top of it.  \
To pay taxes, use the command 'pay <amount>'.  To pay taxes for \
someone else, use 'pay <amount> for <name>'.  The friend you are \
paying taxes for has to be in the game.  To simply donate money, \
use 'donate <amount>'.  All donations are logged, currently \
however, the only reward for donations is you feel good about \
yourself!";
	tm = (object)TP->query_guild_object();
	if ((tm->query_guildmaster() >= 10) || (TP->QCL))
	{
	    desc +=
	    " As a Guildmaster you can take money from the box with \
the command 'collect <amount>'.  Currently the box holds " + pile +
	    " coins.";
	}
    }
    return desc;
}
void create_treasure()
{
    restore_object(SAVE_FILE);
    set_name("cash box");
    set_short("Cash box");
    set_id( ({ "box", "cash", "tax box", "chest" }) );
}
status get() { return 0; }

void init_treasure()
{
    add_action("pay", "pay");
    /*
      add_action("withdraw", "collect");
    */
    add_action("donate", "donate");
}

status pay(string arg)
{
    object tm, forwho;
    int tax_debt, howmuch;
    string who;


    if (!arg)
    {
	notify_fail("Usage: 'pay <amount>' or 'pay <amount> for \
<name>'.\n");
	return 0;
    }

    howmuch = who = forwho = 0;

    if (sscanf(arg, "%d for %s", howmuch, who) != 2)
	if (sscanf(arg, "%d", howmuch) != 1)
	{
	    notify_fail("Usage: 'pay <amount>' or 'pay <amount> for \
<name>'.\n");
	    return 0;
	}
    if (!(tm = present("tmark",TP)))
    {
	notify_fail("You're not a thief and don't have taxes!  \
Feel free to 'donate <amount>' though!\n");
	return 0;
    }

    if (howmuch < 0)
    {
	notify_fail("Thought you'd try to cheat eh?\n");
	return 0;
    }

    if (who)
    {
	if (!(forwho = find_player(who)))
	{
	    notify_fail("You can't pay for " + who + " because he's \
not in the game right now.\n");
	    return 0;
	}
	if (forwho == TP)
	{
	    notify_fail("Why don't you just 'pay <amount>' then?\n");
	    return 0;
	}
	if (!(tm = present("tmark", forwho)))
	{
	    notify_fail(who + " is not a thief or doesn't exist!\n");
	    return 0;
	}
    }

    tax_debt = (int) tm->query_tax();

    if (tax_debt < howmuch)
    {
	notify_fail("Hey, you don't have to pay that much!  "
	  + tax_debt + " is quite enough!\n");
	return 0;
    }

    if (TP->query_money() < howmuch)
    {
	notify_fail("You don't have enough money!\n");
	return 0;
    }

    if (forwho)
    {
	TP->tell_me("Ok.  You pay " + howmuch + " gold in taxes for "
	  + who + ".");
	environment(TP)->tell_here(TP->QN + " has paid " + howmuch
	  + " gold in taxes for " + who + ".",TP);
	tell_object(forwho, capitalize((string)TP->QRN) + " has paid "
	  + howmuch + " of your Guild taxes!\n");
    }
    else
    {
	TP->tell_me("Ok.  You pay " +howmuch + " gold in taxes.");
	environment(TP)->tell_here(TP->QN + " pays " + howmuch + " gold \
in taxes.",TP);
    }

    pile += howmuch;
    save_object(SAVE_FILE);

    tm->add_steal_tax(-(howmuch));
    tm->set_tax_time(time());
    TP->add_money(-(howmuch));

    if ((!forwho) && (!tm->query_tax()))
	TP->tell_me("All your taxes are now paid!");

    if (file_size(GDIR + "DONATE") > 50000)
	rename(GDIR+"TAX_PAYED",
	  GDIR+"TAX_PAYED_AS_OF_"+ctime()[4..6]+ctime()[8..9]);

    write_file(GDIR+"TAX_PAYED",
      this_player()->query_real_name() + "/" +
      ctime(time())[4..9] + ":" +
      howmuch + "\n");
    return 1;
}

status withdraw(string arg)
{
    object tm;
    int gm, howmuch;

    if ((TP->QCL))
    {
	notify_fail("Leave this money for mortals, please.\n");
	return 0;
    }

    if (!(tm = present("tmark", this_player())))
    {
	notify_fail("You're not a thief!  You can't figure out \
how money can be taken!\n");
	return 0;
    }

    gm = (int)tm->query_guildmaster();

    if (gm < TR_CO_GM)
    {
	notify_fail("Only the GM or Co-GM can withdraw money.\n");
	return 0;
    }

    if (gm >= TR_DEMON)
    {
	notify_fail("Demons can't withdraw money - ask a Co-gm or \
the GM to do that.\n");
	return 0;
    }

    if (!arg || sscanf(arg, "%d", howmuch) != 1)
    {
	notify_fail("Withdraw how much?  There are " + pile
	  + " coins in the box!\n");
	return 0;
    }

    if (howmuch > pile || howmuch < 0)
    {
	notify_fail("But there is only " + pile + " coins in the \
box!\n");
	return 0;
    }

    TP->tell_me("Ok.  You take " + howmuch + " coins from the box.");
    environment(TP)->tell_here(TP->QN + " takes " + howmuch + " coins \
from the box.");

    pile -= howmuch;
    TP->add_money(howmuch);


    /* Scar once paid taxes for cheated billions of gold, and thieves
       shared the loot. That was not logged :-( */

    if (file_size(GDIR+"WITHDRAW") > 50000)
	rename(GDIR+"WITHDRAW",
	  GDIR+"WITHDRAW_AS_OF_"+ctime()[4..6]+ctime()[8..9]);

    write_file(GDIR+"WITHDRAW",
      this_player()->query_real_name() + "/" +
      ctime(time())[4..9] + ":" +
      howmuch + "\n");

    save_object(SAVE_FILE);
    return 1;
}

/* Doesn't have to be a thief */
status donate(string arg)
{
    int howmuch;

    if (!arg)
    {
	notify_fail("Donate how much?\n");
	return 0;
    }

    howmuch = 0;

    if (sscanf(arg, "%d", howmuch) != 1) return 0;

    if (howmuch < 0)
    {
	notify_fail("Thought you'd cheat eh?\n");
	return 0;
    }

    if ((int) this_player()->query_money() < howmuch)
    {
	notify_fail("You don't have that much money to donate!\n");
	return 0;
    }
    TP->tell_me("Ok.  You donate " + howmuch + " gold.  Thanks!");
    environment(TP)->tell_here(TP->QN + " donates " + howmuch
      + " gold.  How nice!",TP);

    pile += howmuch;
    TP->add_money(-(howmuch));
    save_object(SAVE_FILE);


    if (file_size(GDIR+"DONATE")>50000)
	rename(GDIR+"DONATE",
	  GDIR+"DONATE_AS_OF_"+ctime()[4..6]+ctime()[8..9]);

    write_file(GDIR+"DONATE",
      (string)this_player()->query_real_name() + "/" +
      ctime()[4..9] + ":" + howmuch + "\n");

    return 1;
}
