//	File	: /cmds/adm/_mailreg.c
//	Creator	: Karathan  (8/12/93)

// The command to add or remove an email-registered character. Just an interface
// to the banish daemon.
// Command from Karathan, daemon from Dainia@Dreamshadow.

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int fail();


int cmd_mailreg(string str)
{
    int i, j;
    mixed *names;

    if (!adminp(geteuid(previous_object())))
      { notify_fail("You are not permitted to use the mailreg command.\n");
	return 0; }
    if (!str || !stringp(str) || str == "")
      { names = BANISH_D->query_mailreg_names();
	if (!names || names == ({ }))
	    write("There are no email-registration names.\n");
	else
	  { i = sizeof(names);
	    if (i < 4)
		str = "There is one email-registered name: " +
		      capitalize(names[0]);
	    else
	      { str = "There are " + (sizeof(names) / 2) +
		      " email-registered names: ";
		for (j = 0; j < i - 4; j += 2)
		    str += capitalize(names[j]) + ", ";
		str += capitalize(names[i - 4]) + " and " +
		       capitalize(names[i - 2]); }
	    write(wrap(str + ".\n")); }
	return 1; }
    names = explode(lower_case(str), " ");
    if (sizeof(names) == 2)
      { if (names[0] != "-")
	    return fail();
	i = BANISH_D->remove_mailreg_name(names[1]);
	if (!i)
	    write("Mailreg: Command failed.\n");
	else if (i < 0)
	    write("Mailreg: " + capitalize(names[1]) + " is not in the list " +
		  "of email-registered characters.\n");
	else
	    write("Mailreg: Removed " + capitalize(names[1]) + " from the " +
		  "list of email-registered characters.\n");
	return 1; }
    if (sizeof(names) != 1)
	return fail();
    write("Enter password for " + capitalize(names[0]) + ": ");
    input_to("getpass", 1, names[0], "", 0);
    return 1;
}


protected int getpass(string password, string name, string prev, int count)
{
    int i;

    if (prev == "")
      { if (!password || password == "")
	  { write("\nCan't have the null string as a password.\n");
	    if (count < 2)
	      { write("Re-enter password for " + capitalize(name) + ": ");
		input_to("getpass", 1, name, "", count + 1); }
	    return 1; }
	if (strlen(password) < 5)
	  { write("\nPassword must be over five characters in length.\n");
	    if (count < 2)
	      { write("Re-enter password for " + capitalize(name) + ": ");
		input_to("getpass", 1, name, "", count + 1); }
	    return 1; }
	write("\nConfirm password for " + capitalize(name) + ": ");
	input_to("getpass", 1, name, password, 0);
	return 1; }
    if (password != prev)
      { write("\nPasswords do not match.\n");
	return 1; }
    i = BANISH_D->add_mailreg_name(name, crypt(password, 0));
    if (!i)
	write("\nMailreg: Command failed.\n");
    else if (i < 0)
	write("\nMailreg: Password for " + capitalize(name) + " altered.\n");
    else
	write("\nMailreg: Added " + capitalize(name) + " to the list of " +
	      "email-registered characters.\n");
    return 1;
}


int fail()
{
    notify_fail("Usage: mailreg [[-] name]\n");
    return 0;
}


string help()
{
    return(
"Usage: mailreg [[-] name]\n"
"If <name> is given a password will be prompted for (silent entry).  Passwords\n"
"may be altered on existing email-registration characters.  With no argument\n"
"a list of email-registration characters is displayed.  All entries should be\n"
"automatically deleted at first signon, but can also be deleted using the '-'\n"
"option if necessary.\n");
}
