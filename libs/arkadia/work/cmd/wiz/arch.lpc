/*
 * /cmd/wiz/arch.c
 *
 * This object holds the commands reserved for archwizards.
 * The following commands are supported:
 *
 * - all_spells
 * - arch
 * - arche
 * - block
 * - delchar
 * - draft
 * - global
 * - lockout
 * - mailadmin
 * - mkdomain
 * - mudstatus
 * - namechange
 * - newchar
 * - nopurge
 * - pingmud
 * - purge
 * - rmdomain
 * - startloc
 * - storemuds
 * - trace
 * - traceprefix
 * - unmadwand
 * - vip
 * - xpclear
 */

#pragma no_clone
#pragma no_inherit
#pragma save_binary
#pragma strict_types

inherit "/cmd/std/command_driver";

#include <adverbs.h>
#include <composite.h>
#include <files.h>
#include <macros.h>
#include <log.h>
#include <stdproperties.h>
#include <std.h>

#define CHECK_SO_ARCH 	if (WIZ_CHECK < WIZ_ARCH) return 0; \
			if (this_interactive() != this_player()) return 0

#define NOPURGE(s)	("/syslog/nopurge/" + extract((s), 0, 0) + "/" + (s))

/* **************************************************************************
 * Return a list of which souls are to be loaded.
 * The souls are listed in order of command search.
 */
nomask string *
get_soul_list()
{
    return ({ WIZ_CMD_ARCH,
	      WIZ_CMD_LORD,
	      WIZ_CMD_HELPER,
	      WIZ_CMD_NORMAL,
	      WIZ_CMD_PILGRIM,
	      WIZ_CMD_APPRENTICE,
	      MBS_SOUL });
}

/* **************************************************************************
 * Return a proper name of the soul in order to get a nice printout.
 */
nomask string
get_soul_id()
{
    return WIZNAME_ARCH;
}

/* **************************************************************************
 * The list of verbs and functions. Please add new in alfabetical order.
 */
nomask mapping
query_cmdlist()
{
    return ([
	     "all_spells":"all_spells",
	     "arch":"arch",
	     "arche":"arch",

	     "block":"block",

	     "delchar":"delchar",
	     "draft":"draft",

	     "global":"global",

	     "lockout":"lockout",

	     "mailadmin":"mailadmin",
	     "mkdomain":"mkdomain",
	     "mudstatus":"mudstatus",

	     "namechange":"namechange",
	     "newchar":"newchar",
	     "nopurge":"nopurge",

	     "pingmud":"pingmud",
	     "przeloguj":"przeloguj",
	     "purge":"purge",

             "rmdomain":"rmdomain",

	     "startloc":"startloc",
	     "storemuds":"storemuds",

	     "trace":"set_trace",
	     "traceprefix":"set_traceprefix",

	     "unmadwand":"unmadwand",
	     "vip":"vip",

	     "xpclear":"xpclear",
	 ]);
}

/* **************************************************************************
 * Here follows the actual functions. Please add new functions in the 
 * same order as in the function name list.
 * **************************************************************************/

/* **************************************************************************
 * all_spells - list all active spells
 */
nomask int
all_spells()
{
    CHECK_SO_ARCH;

    SECURITY->list_spells();
    
    return 1;
}

/* **************************************************************************
 * arch  - send a message on the archline
 * arche - emote a message on the archline
 */
nomask int
arch(string str)
{
    if (!stringp(str))
    {
	notify_fail(capitalize(query_verb()) + " what?\n");
	return 0;
    }

    return WIZ_CMD_APPRENTICE->line((WIZNAME_ARCH + " " + str),
	(query_verb() == "arche"));
}

/* **************************************************************************
 * block - arch managing of sites that are totally blocked
 */
nomask int
block(string str)
{
    CHECK_SO_ARCH;
    
    if (!stringp(str))
    {
	notify_fail("Block what?\n");
	return 0;
    }

    return SECURITY->block_site(str);
}


/* **************************************************************************
 * delchar - remove a playerfile
 */
nomask int
delchar(string str)
{
    string who, reason;

    CHECK_SO_ARCH;

    if ((!stringp(str)) ||
	(sscanf(str, "%s %s", who, reason) != 2))
        return notify_fail("Usage: delchar <player> <reason>\n");

    who = lower_case(who);

    if (objectp(find_player(who)))
    {
	notify_fail("The player " + capitalize(who) + " is logged in. It is " +
	    "useless to remove the file now.\n");
	return 0;
    }
    
    if (SECURITY->query_wiz_rank(who))
    {
	notify_fail("Wizards should be demoted.\n");
        return 0;
    }

    if (!SECURITY->remove_playerfile(who, reason))
    {
        notify_fail("Failed to delete the player.\n");
        return 0;
    }

    write("The player " + capitalize(who) + " has been removed.\n");
    return 1;
}

/* **************************************************************************
 * draft - add someone to a domain
 */
nomask int
draft(string str)
{
    string dname;
    string pname;

    CHECK_SO_ARCH;

    if ((!stringp(str)) ||
	(sscanf(str, "%s %s", dname, pname) != 2))
    {
	notify_fail("Usage: draft Domain player\n");
	return 0;
    }

    return SECURITY->draft_wizard_to_domain(dname, pname);
}


/* **************************************************************************
 * global - add/remove people from the global list
 */
nomask int
global(string str)
{
    string *cmds;
    string *wnames;
    int     index;
    int     size;
    mapping gread;

    CHECK_SO_ARCH;

    if (!stringp(str))
    {
	gread = SECURITY->query_global_read();
        wnames = sort_array(m_indices(gread));
	size = sizeof(wnames);

	if (!size)
	{
	    write("There are no wizards with global read rights.\n");
	    return 1;
	}

	index = -1;
	while(++index < size)
	{
	    write(sprintf("%-11s added by %-11s", capitalize(wnames[index]),
		capitalize(gread[wnames[index]][0])) + " (" +
		gread[wnames[index]][1] + ")\n");
	}
	return 1;
    }

    cmds = explode(str, " ");

    switch(cmds[0])
    {
    case "add":
	return SECURITY->add_global_read(cmds[1], implode(cmds[2..], " "));

    case "remove":
	return SECURITY->remove_global_read(cmds[1]);

    default:
	break;
    }

    notify_fail("Do which 'global' operation?\n");
    return 0;
}

/* **************************************************************************
 * lockout - arch managing of sites from which new players are locked out
 */
nomask int
lockout(string str)
{
    CHECK_SO_ARCH;
    
    if (!stringp(str))
    {
	notify_fail("lockout what?\n");
	return 0;
    }

    return SECURITY->lockout_site(str);
}

/* **************************************************************************
 * mailadmin - manage the mail system
 */
nomask int
mailadmin(string str)
{
    CHECK_SO_ARCH;

    return SECURITY->mailadmin(str);
}

/* **************************************************************************
 * mkdomain - make a new domain
 */
nomask int
mkdomain(string arg)
{
    string *args;

    CHECK_SO_ARCH;

    if (!stringp(arg) ||
	sizeof(args = explode(arg, " ")) != 3)
    {
	notify_fail("Syntax: mkdomain <Domain> <short> <liege>\n");
	return 0;
    }

    return SECURITY->make_domain(capitalize(args[0]),
				 lower_case(args[1]),
				 lower_case(args[2]));
}

/* **************************************************************************
 * mudstatus - Turn on and off /MUDstatistics
 */
nomask int
mudstatus(string arg)
{
    int ev, ti;
    string fl;

    CHECK_SO_ARCH;

    if (!stringp(arg) ||
	(sscanf(arg,"%s %d %d", fl, ev, ti) != 3))
    {
	if (fl != "off")
	{
	    notify_fail("SYNTAX: mudstatus on/off eval_limit time_limit(ms)\n");
	    return 0;
	}
	ev = 0; 
	ti = 0;
    }

    SECURITY->do_debug("mudstatus", fl, ev, ti / 10);
    write("Ok.\n");
    return 1;
}

/* **************************************************************************
 * namechange - change someones name.
 */
nomask int
namechange(string str)
{
    string *words;

    CHECK_SO_ARCH;

    if ((!stringp(str)) ||
	(sizeof(words = explode(str, "")) != 2))
    {
	notify_fail("Syntax: namechange <oldname> <newname>\n");
	return 0;
    }

    return SECURITY->change_player_name(words[0], words[1]);
}

/* **************************************************************************
 * newchar - create a new character
 */
nomask int
valid_name(string str)
{
    int index = -1;
    int length = strlen(str);

    if (length < 3)
    {
	notify_fail("\nImie jest za krotkie - musi miec przynajmniej 3 znaki.\n");
	return 0;
    }

    if (length > 11)
    {
	notify_fail("\nImie jest za dlugie - moze miec najwyzej 11 znakow.\n");
	return 0;
    }

    while (++index < length)
    {
	if ((str[index] < 'a') ||
	    (str[index] > 'z'))
	{
	    notify_fail("\nNiewlasciwy znak w imieniu '" + str + "'.\n");
	    return 0;
	}
    }

    return 1;
}


nomask int
newchar(string str)
{
    string *args, name;
    string passwd;
    int ix;
    mapping tmp_char;

    notify_fail("Poprawna skladnia: newchar <imie> <email>.\n");

    if (!strlen(str))
	return 0;

    args = explode(str, " ");
    if (sizeof(args) != 2)
	return 0;

    name = lower_case(args[0]);

    if (!valid_name(name))
	return 0;

    if (file_size(PLAYER_FILE(name) + ".o") != -1)
    {
	write(sprintf("Gracz o imieniu '%s' juz istnieje.\n",
	    capitalize(name)));
	return 1;
    }

    if (file_size(BANISH_FILE(name)) != -1)
    {
	write(sprintf("Imie '%s' jest zabanowane.\n", capitalize(name)));
	return 1;
    }

    if (file_size("/players/saved/" + name + ".o") != -1)
    {
	write(sprintf("Gracz o imieniu '%s' jest w przechowaniu.\n", 
	    capitalize(name)));
	return 1;
    }

    tmp_char = restore_map("/secure/proto_char");
    tmp_char["name"] = name;
//    tmp_char["imiona"] = odmiana;
    passwd = SECURITY->generate_password();
    tmp_char["password"] = crypt(passwd, 0);
    tmp_char["mailaddr"] = args[1];
    tmp_char["password_time"] = time();
    tmp_char["login_time"] = time();

    /*
     * NOTA BENE!
     * 
     * DO NOT CHANGE THE FORMAT OF THE NEWCHAR_LIST FILE!!!!
     * This file is read automatically by an external service which mails
     * the recipiants of the charater, messing with this will mess up that
     * service.
     */
    write_file("/syslog/log/NEWCHAR_LIST", sprintf(" %s#%s#%s\n",
	args[1], name, passwd));

    save_map(tmp_char, PLAYER_FILE(name));

    write(sprintf("Postac o imieniu '%s' ustworzona. Haslo: %s.\n" + 
	"Email: %s.\n", capitalize(name), passwd, args[1]));
    write_file(OPEN_LOG_DIR + "/CREATE_PLAYER",
	sprintf("%s %s (%s) created by %s.\n", ctime(time()), capitalize(name),
	args[1], capitalize(this_interactive()->query_real_name())));

    return 1;
}

/* **************************************************************************
 * nopurge - prevent someone from being purged.
 */
nomask int
nopurge(string str)
{
    string *words;
    string name;

    CHECK_SO_ARCH;

    if (!stringp(str))
    {
	notify_fail("No argument to nopurge. See the help page.\n");
	return 0;
    }

    words = explode(str, " ");

    switch(words[0])
    {
    case "-i":
    case "-info":
	/* Strip the first argument. */
	words = words[1..];
	break;

    case "-a":
    case "-add":
	if (sizeof(words) < 3)
	{
	    write("No reason added to 'purge -a[dd]'.\n");
	    return 1;
	}

	name = lower_case(words[1]);
	if (SECURITY->query_no_purge(name))
	{
	    write("Player '" + capitalize(name) +
		"' is already protected against purging.\n");
	    return 1;
	}

	if (!write_file(NOPURGE(name), implode(words[2..], " ")))
	{
	    write("Failed to write purge protection on '" + capitalize(name) +
		"'.\n");
	    return 1;
	}

	write("Purge protection added to '" + capitalize(name) + "'.\n");
	return 1;

    case "-r":
    case "-remove":
	name = lower_case(words[1]);
	if (!(SECURITY->query_no_purge(name)))
	{
	    write("Players '" + capitalize(name) +
		"' is not protected against purging.\n");
	    return 1;
	}

	if (!rm(NOPURGE(name)))
	{
	    write("Failed to remove purge protection from '" +
		capitalize(name) + "'.\n");
	    return 1;
	}

	write("Removed purge protection from '" + capitalize(name) + "'.\n");
	return 1;

    default:
	break;
    }

    name = lower_case(words[0]);
    if (!(SECURITY->query_no_purge(name)))
    {
	write("Player '" + name + "' is not purge-protected.\n");
	return 1;
    }

    write("Purge protection on '" + name + "':\n");

    if (!strlen(str = read_file(NOPURGE(name))))
    {
	write("    Error: unable to read purge protection.\n");
	return 1;
    }

    words = explode(str, "\n");
    write("Wizard: " + words[0] +
	"\nReason: " + words[1] +
	"\nDate  : " + ctime(file_time(NOPURGE(name)))+ "\n");
    return 1;
}
 
/* **************************************************************************
 * pingmud - send a udp ping to another mud
 */
nomask int
pingmud(string arg)
{
    CHECK_SO_ARCH;

#ifdef UDP_MANAGER    
    return UDP_MANAGER->cmd_ping(arg);
#else
    notify_fail("No udp manager active.\n");
    return 0;
#endif UDP_MANAGER
}

/* **************************************************************************
 * przeloguj - przepina osobe do nowego obiektu, tak, jakby dana osoba
 *             sie przelogowala.
 */
nomask int
przeloguj(string str)
{
    string plfile, imie;
    object nowy, stary, *gracze;
    int x;

    CHECK_SO_ARCH;

    if (!str)
    {
        notify_fail("Przeloguj kogo? Siebie?\n");
        return 0;
    }

    if (str != "sie" && str != "siebie" && str != "mnie")
    {
        str = lower_case(str);
        gracze = users();
        x = sizeof(gracze);
        
        while (--x >= 0)
            if (gracze[x]->query_real_name(PL_BIE) == str)
                break;
                
        if (x == -1)
        {
            write("Nie ma takiego gracza obecnie zalogowanego. Pamietaj, " +
                "ze imie trzeba podac w bierniku.\n");
            return 1;
        }
        
        stary = gracze[x];
        
        stary->catch_msg("\n\n\nZostajesz przelogowan" + 
            stary->koncowka("y", "a") + ".\n");
    }
    else
        stary = this_player();
        
    nowy = clone_object(stary->query_player_file());
    
    if (!nowy)
    {
        write(capitalize(stary->query_real_name()) + " ma nie istniejaca " +
           "rase. Nie dalo sie sklonowac playerfile'a.\n");
        return 1;
    }
    
    exec(nowy, stary);

    nowy->add_prop("just_created", 1); 
    stary->save_me(0);
    imie = stary->query_real_name();
    
    stary->quit();
    if (stary)
        SECURITY->do_debug("destroy", stary);

    if (!nowy->enter_game(imie))
    {
        write("Nie moge zaladowac tej postaci! Nie powiodl sie " +
           "enter_game().\n");
           
        stary->remove_object();
        nowy->remove_object();
    }

    nowy->update_hooks();
    nowy->save_me(0);

    SECURITY->notify(nowy, 0);
    
    return 1;
}


/* **************************************************************************
 * purge - remove all players that have been idle too long or remove one
 *         individual mortal.
 */
nomask int
purge(string str)
{
    CHECK_SO_ARCH;

    if (str == "players")
    {
        if (objectp(PURGE_OBJECT))
        {
            notify_fail("The general purger is already active.\n");
            return 0;
        }

        PURGE_OBJECT->purge_players();
        return 1;
    }

    return SECURITY->purge(lower_case(str));
}

/* **************************************************************************
 * rmdomain - remove an old domain
 */
nomask int
rmdomain(string arg)
{
    CHECK_SO_ARCH;

    return SECURITY->remove_domain(arg);
}

/* **************************************************************************
 * trace - trace the mud
 */
nomask int
set_trace(string str)
{
    int n;
    int o;

    CHECK_SO_ARCH;

    if (stringp(str) &&
	sscanf(str, "%d", n) == 1)
    {
	o = SECURITY->do_debug("trace", n);
	write("Trace was " + o + ", now " +
	      SECURITY->do_debug("trace", n) + "\n");
    }
    else
    {
	write("Bad argument to trace.\n");
    }
    return 1;
}

/* **************************************************************************
 * traceprefix - set the trace prefixes
 */
nomask int
set_traceprefix(string str)
{
    string o;

    CHECK_SO_ARCH;

    if (stringp(str))
	o = SECURITY->do_debug("traceprefix", str);
    else
	o = SECURITY->do_debug("traceprefix");
    write("Trace prefix was " + o + "\n");
    return 1;
}

/* **************************************************************************
 * startloc - handle starting locations
 */
nomask int
startloc(string str)
{
    string *sstr;
    int what;

    CHECK_SO_ARCH;

    notify_fail("Incorrect syntax for startloc.\n" +
        "Syntax: startloc list [def[ault]] / [temp[orary]]\n" +
        "        startloc add def[ault] / temp[orary] <loc>\n" +
        "        startloc rem[ove] def[ault] / temp[orary] <loc>\n");

    if (!stringp(str))
    {
	return 0;
    }

    sstr = explode(str, " ");

    switch(sstr[0])
    {
    case "list":
	if (sizeof(sstr) < 2)
	    what = 3;
	else
	{
	    switch (sstr[1])
	    {
	    case "default":
	    case "def":
		what = 1;
		break;

	    case "temporary":
	    case "temp":
		what = 2;
		break;

	    default:
		notify_fail("I don't know of any '" + sstr[1] +
			    "' start location.\n");
		return 0;
		break;
	    }
	}

	if (what == 1 ||
	    what == 3)
	{
	    write("Default start locations:\n");
	    write(sprintf("%-*#s\n", 76, 
		  implode(SECURITY->query_list_def_start(str), "\n")) + "\n");
	}

	if (what == 2 ||
	    what == 3)
	{
	    write("Temporary start locations:\n");
	    write(sprintf("%-*#s\n", 76, 
		  implode(SECURITY->query_list_temp_start(str), "\n")) + "\n");
	}
	break;
	
    case "add":
	if (sizeof(sstr) < 3)
	{
	    return 0;
	}

	switch(sstr[1])
	{
	case "default":
	case "def":
	    SECURITY->add_def_start_loc(sstr[2]);
	    break;

	case "temporary":
	case "temp":
	    SECURITY->add_temp_start_loc(sstr[2]);
	    break;

	default:
	    notify_fail("I don't know of any '" + sstr[1] +
			"' start location.\n");
	    return 0;
	    break;
	}
	break;

    case "remove":
    case "rem":
	if (sizeof(sstr) < 3)
	{
	    notify_fail("Remove what?\n");
	    return 0;
	}

	switch(sstr[1])
	{
	case "default":
	case "def":
	    SECURITY->rem_def_start_loc(sstr[2]);
	    break;

	case "temporary":
	case "temp":
	    SECURITY->rem_temp_start_loc(sstr[2]);
	    break;

	default:
	    notify_fail("I don't know of any '" + sstr[1] +
			"' start location.\n");
	    return 0;
	    break;
	}
	break;

    default:
	return 0;
    }

    write("Ok.\n");
    return 1;
}

/* **************************************************************************
 * storemuds - Store the mudlist currently in the UDP_MANAGER
 */
nomask int
storemuds(string arg)
{
    CHECK_SO_ARCH;

#ifdef UDP_MANAGER    
    if (UDP_MANAGER->update_masters_list())
    {
	write("Ok.\n");
	return 1;
    }
    notify_fail("Master did not allow the store.\n");
    return 0;
#else
    notify_fail("No udp manager active.\n");
    return 0;
#endif UDP_MANAGER
}

/* **************************************************************************
 * unmadwand - Turn a madwand into a normal wizard.
 */
nomask int
unmadwand(string str)
{
    CHECK_SO_ARCH;

    return SECURITY->madwand_to_wizard(str);
}

/* **************************************************************************
 * vip - Display the people with vip-access, grant vip access or revoke it.
 */
nomask int
vip(string str)
{
    string *vips = (string *)QUEUE->query_vip();

    CHECK_SO_ARCH;

    str = lower_case(str);
    if (!stringp(str))
    {
	if (!sizeof(vips))
	{
	    write("No people with VIP-access.\n");
	    return 1;
	}

	write("The following people have VIP-access: " +
	    COMPOSITE_WORDS(vips) + ".\n");
	return 1;
    }

    /* Remove vip-access from someone. */
    if (sscanf(str, "-r %s", str) == 1)
    {
	if (member_array(str, vips) == -1)
	{
	    write(capitalize(str) + " has no VIP access.\n");
	    return 1;
	}

	if (QUEUE->unvip(str))
	{
	    write("VIP access of " + capitalize(str) + " revoked.\n");
	    return 1;
	}

	write("VIP access of " + capitalize(str) + " is NOT revoked.\n");
	return 1;
    }

    if (!(SECURITY->exist_player(str)))
    {
	notify_fail("There is no player called " + capitalize(str) + ".\n");
	return 0;
    }

    if (member_array(str, vips) >= 0)
    {
	write(capitalize(str) + " already has VIP access.\n");
	return 1;
    }

    if (QUEUE->set_vip(str))
    {
	tell_object(this_interactive(), "VIP access of " + capitalize(str) +
	    " granted.\n");
	return 1;
    }

    write("VIP access of " + capitalize(str) + " was NOT granted.\n");
    return 1;    
}


/* **************************************************************************
 * xpclear - Clear the xp counters in master for a specific domain
 */
nomask int
xpclear(string dom)
{
    CHECK_SO_ARCH;

    return SECURITY->domain_clear_xp(dom);
}
