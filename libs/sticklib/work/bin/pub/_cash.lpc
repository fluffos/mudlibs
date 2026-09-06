#include <cmd.h>

nomask int
cash_cmd(string arg)
{
    object ob;

    ob = TP;

    /* Coders can "cash xxxx", where xxxx may be any living */
    if ((int)ob->query_coder_level() && arg)
    {
	ob = present(arg, environment(TP));
	if (!ob) ob = find_living(arg);
	if (!ob) {
	    TP->tell_me("Can't find any living named '"+arg+"'.");
	    return 1;
	}
    }

    if (TP == ob)
	ob->tell_me("You have " +
	  (int)ob->query_money() + " gold coins in your purse.");
    else
	TP->tell_me(capitalize((string)ob->query_real_name()) +
	  " has " + (int)ob->query_money() + " gold coins.");

    return 1;
}
