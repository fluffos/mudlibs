//	File	: /cmds/adm/_banish.c
//	Creator	: Buddha@TMI
//	Updated	: Mobydick  (5/26/93)  Added rudimentary argument checking.
//		  Karathan  (7/13/93)  Rewritten for unified banish code.
//		  Karathan  (8/12/93)  Updated with banish daemon.

// The command to banish or unbanish a site or name. Just an interface to the
// banish daemon.  Command from Buddha, daemon from Dainia@Dreamshadow.

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;


int fail()
{
    notify_fail("Usage: banish <site [[-] site ip]|name [[-] name]>\n");
    return 0;
}


int cmd_banish(string str)
{
    int i;
    string *words;
    mixed *sites, *names;

    if (!str || !stringp(str) || str == "")
	return fail();
    replace_string(str, "  ", " ", 0);
    if (str == "")
	return fail();
    words = explode(lower_case(str), " ");
    if (sizeof(words) < 1 || sizeof(words) > 3 ||
	(sizeof(words) == 3 && words[1] != "-"))
	return fail();
    if (words[0] == "site" || words[0] == "sites")
      { if (sizeof(words) == 1)
	  { sites = BANISH_D->query_banished_sites();
	    if (!sites || sites == ({ }))
		write("There are no banished sites.\n");
	    else
	      { if (sizeof(sites) == 1)
		    str = "There is one banished site: " + sites[0];
	 else
	     str = "There are " + sizeof(sites) + " banished sites: " +
	    implode(sites[0..<2], ", ") + " and " +
	    sites[<1];
		write(wrap(str + ".\n")); }
	    return 1; }
    if (!adminp(geteuid(previous_object())))
      { notify_fail("You are not permitted to use the banish command.\n");
	return 0; }
	if (sizeof(words) == 2)
	  { i = BANISH_D->banish_site(words[1]);
	    if (!i)
		write("Banish site: Command failed.\n");
	    else if (i < 0)
		write("Site '" + words[1] +
		      "' is already in the banish list.\n");
	    else
		write("Site '" + words[1] +
		      "' has been added to the banish list.\n"); }
	else
	  { i = BANISH_D->remove_banished_site(words[2]);
	    if (!i)
		write("Banish site (removal): Command failed.\n");
	    else if (i < 0)
		write("Site '" + words[2] +
		      "' is not in the banish list.\n");
	    else
		write("Site '" + words[2] +
		      "' has been removed from the banish list.\n"); }
	return 1; }
    if (words[0] == "name" || words[0] == "names")
      { if (sizeof(words) == 1)
	  { names = BANISH_D->query_banished_names();
	    if (!names || names == ({ }))
		write("There are no banished names.\n");
	    else
	      { if (sizeof(names) == 1)
		    str = "There is one banished name: " + names[0];
	 else
	     str = "There are " + sizeof(names) + " banished names: " +
	    implode(names[0..<2], ", ") + " and " +
	    names[<1];
		write(wrap(str + ".\n")); }
	    return 1; }
    if (!adminp(geteuid(previous_object())))
      { notify_fail("You are not permitted to use the banish command.\n");
	return 0; }
	if (sizeof(words) == 2)
	  { i = BANISH_D->banish_name(words[1]);
	    if (!i)
		write("Banish name: Command failed.\n");
	    else if (i < 0)
		write("Name '" + words[1] +
		      "' is already in the banish list.\n");
	    else
		write("Name '" + words[1] +
		      "' has been added to the banish list.\n"); }
	else
	  { i = BANISH_D->remove_banished_name(words[2]);
	    if (!i)
		write("Banish name (removal): Command failed.\n");
	    else if (i < 0)
		write("Name '" + words[2] +
		      "' is not in the banish list.\n");
	    else
		write("Name '" + words[2] +
		      "' has been removed from the banish list.\n"); }
	return 1; }
    return fail();
}


string help()
{
    return(
"Usage: banish <site [[-] site ip]|name [[-] name]>\n"
"The <site> string may be either an IP number of the form 123.123.123.123 or\n"
"it may be a partial, such as 123.123, which banishes all sites whose root\n"
"IP numbers starts with 123.123.  Guest logins are also site-checked.  The\n"
"<name> string may include any regexp wildcards (eg, '.*fuck.*').  Preceding\n"
"the site or name with a (space separated) '-' character will remove it from\n"
"the relevant list.  With no name or site ip given, the full list is shown.\n"
"NB To banish only \"at\" not \"cat\", \"satan\" & \"atan\", use \"^at$\".\n"+
"\nSee also: nuke\n");
}
