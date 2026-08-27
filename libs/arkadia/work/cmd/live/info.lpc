/*
 * /cmd/live/info.c
 *
 * General commands for giving and getting game information.
 * The following commands are defined:
 *
 * - bug	+ zglos.
 * - date	+ system.
 * - done	+ usuniete.
 * - help	+ ?
 * - idea	+ zglos.
 * - praise	+ zglos.
 * - sysbug	+ zglos.
 * - sysidea	+ zglos.
 * - syspraise	+ zglos.
 * - systypo	+ zglos.
 * - typo	+ zglos.
 * - ---        + wiesci.
 */

#pragma no_clone
#pragma no_inherit
#pragma save_binary
#pragma strict_types

inherit "/cmd/std/command_driver";

#include <cmdparse.h>
#include <language.h>
#include <log.h>
#include <macros.h>
#include <std.h>
#include <time.h>

/* These properties are only internal to this module, so we define them
 * here rather than in the properties file stdproperties.h.
 */
#define PLAYER_I_LOG_TYPE   "_player_i_log_type"
#define PLAYER_O_LOG_OBJECT "_player_o_log_object"

#define COMMON_BOARD        "/d/Standard/wiz/wiesciboard"
#define COMMON_BOARD_ROOM   "/d/Standard/wiz/wiesci"

object Common_Board = 0;

/* **************************************************************************
 * The constructor.
 */
void 
create()
{
    setuid();
    seteuid(getuid()); 
}

/* **************************************************************************
 * Return a proper name of the soul in order to get a nice printout.
 */
string
get_soul_id()
{
    return "info";
}

/* **************************************************************************
 * This is a command soul.
 */
int
query_cmd_soul()
{
    return 1;
}

/* **************************************************************************
 * The list of verbs and functions. Please add new in alfabetical order.
 */
mapping
query_cmdlist()
{
    return ([
	"?"        : "command_help",

	"bug"      : "report",

	"date"     : "date",
	"done"     : "report_done",

	"help"     : "help",

	"idea"     : "report",

	"pomoc"    : "pomoc",
	"pomocy"   : "pomoc",
	"praise"   : "report",

	"sysbug"   : "report",
	"sysidea"  : "report",
	"syspraise": "report",
	"system"   : "system",
	"systypo"  : "report",

	"typo"     : "report",

        "wiesci"   : "wiesci",

	"zglos"    : "zglos"]);
}

/*
 * Function name: using_soul
 * Description:   Called once by the living object using this soul. Adds
 *		  sublocations responsible for extra descriptions of the
 *		  living object.
 */
public void 
using_soul(object live)
{
}

/* **************************************************************************
 * Here follow some support functions. 
 * **************************************************************************/

/*
 * Function name: done_reporting
 * Descripiton  : This function is called from the editor when the player
 *                has finished the report he or she was writing. If any
 *                text was entered it is logged and the player is thanked.
 * Arguments    : string str - the text entered into the editor.
 */
public void
done_reporting(string str)
{
    int type = this_player()->query_prop(PLAYER_I_LOG_TYPE);

    if (!strlen(str))
    {
	write(LOG_ABORT_MSG(LOG_MSG(type)));
	return;
    }

    /* Log the note, thank the player and then clean up after ourselves. */
    SECURITY->note_something(str, type,
        this_player()->query_prop(PLAYER_O_LOG_OBJECT));
    write(LOG_THANK_MSG(LOG_MSG(type)));

    this_player()->remove_prop(PLAYER_I_LOG_TYPE);
    this_player()->remove_prop(PLAYER_O_LOG_OBJECT);
}

/* **************************************************************************
 * Now the actual commands. Please add new in the alphabetical order.
 * **************************************************************************/


/*
 * ? - Wyswietla pomoc na podany temat.
 */
int
command_help(string str)
{
    string dir = "general/";

    if (!str)
        str = "?";

    /* Wizards get to see the wizard help pages by default. */
    if (SECURITY->query_wiz_level(this_player()->query_real_name()))
    {
	/* ... unless they want to see the general page. */
	if (wildmatch("g *", str))
	{
	    str = extract(str, 2);
	}
	else if (file_size("/doc/help/wizard/" + str) > 0)
	{
	    dir = "wizard/";
	}
    }

    if (file_size("/doc/help/" + dir + str) > 0)
    {
    	setuid();
    	seteuid(getuid());

	this_player()->more(("/doc/help/" + dir + str), 1);
	return 1;
    }

    notify_fail("Nie ma pomocy na ten temat.\n");
    return 0;
}

/*
 * pomoc, pomocy - Podaje skladnie pomocy.
 */
int
pomoc(string str)
{
    return command_help("?");
}

/*
 * system - pobiera lokalny czas i date, oraz informacje o mudzie
 */
int
system()
{
    int runlevel;

    write("Swiat odrodzil sie  : " + ctime(SECURITY->query_start_time(), 1) + 
    					"\n");
    write("Lokalny czas        : " + ctime(time(), 1) + "\n");
    write("Swiat istnieje      : " + CONVTIME(time() - 
        SECURITY->query_start_time()) + "\n");
    write(SECURITY->query_memory_percentage() + "% swiata zostalo opanowane "+
        "przez Ciemnosc.\n");
#ifdef REGULAR_REBOOT
    write("Regularny restart: Codziennie po " + REGULAR_REBOOT + ":00\n");
#endif REGULAR_REBOOT

    /* Tell wizards some system data. */
    if (this_player()->query_wiz_level())
    {
#ifdef REGULAR_UPTIME
        write("Regular reboot: " +
            CONVTIME(SECURITY->query_irregular_uptime() +
            SECURITY->query_start_time() - time()) + " to go.\n");
#endif REGULAR_UPTIME

	write("Dane systemowe      : " + SECURITY->do_debug("load_average") + "\n");

        if (runlevel = SECURITY->query_runlevel())
        {
            write("Runlevel      : " + WIZ_RANK_NAME(runlevel) +
                " (and higher).\n");
        }
    }

    if (ARMAGEDDON->shutdown_active())
    {
	write("Do rozpoczecia Apokalipsy " + 
	    CONVTIME(ARMAGEDDON->shutdown_time()) + ".\n");
        if (!this_player()->query_wiz_level())
        return 1;
	    
	write("Wywolana przez      : " + capitalize(ARMAGEDDON->query_shutter()) +
	     ".\n");
	write("Powod               : " + ARMAGEDDON->query_reason() + "\n");
    }

    return 1;
}

/*
 * date - get local time & date + uptime information
 */
int
date()
{
    notify_fail("Komenda 'date' zostala wycofana. Zamiast " +
        "niej mozesz uzyc 'system'.\n");

    return 0;
}

/*
 * help - Get help on a subject
 */
int
help(string what)
{
    notify_fail("Komenda 'help' zostala wycofana. Zamiast " +
        "niej mozesz uzyc '?'.\n");

    return 0;
}

/*
 * Report - make a report of some kind.
 */
int
report(string str)
{
    notify_fail("Komenda '" + query_verb() + "' zostala wycofana. Zamiast " +
        "niej mozesz uzyc 'zglos'.\n");

    return 0;
}

/*
 * Zglos - zglos jakis raport, o byku, itp.
 */
int
zglos(string str)
{
    object *oblist;
    object target;
    int type = 0,
        przyp;
    string *slowa, slowo, przyimek, parse_string;
    
    notify_fail(
        "Prawidlowa skladnia: 'zglos [globalny] blad [w <obiekcie>]'\n" +
        "                     'zglos [globalny] pomysl [do <obiekt>]'\n" +
        "                     'zglos [globalna] pochwale [za <obiekt>]'\n");

    if (!strlen(str))
        return 0;

    slowa = explode(str, " ");
    
    if (slowa[0][0..6] == "globaln" && sizeof(slowa) > 1)
    {
        type = LOG_SYSBUG_ID - 1;
        slowo = slowa[1]; str = implode(slowa[2..], " ");
    }
    else
    {
        type = LOG_BUG_ID - 1;
        slowo = slowa[0]; str = implode(slowa[1..], " ");
    }

    if (!LOG_TYPES[slowo])
    {
        return 0;
    }
    
    type += LOG_TYPES[slowo];
    
    /* Player may describe the object to make a report about. */
    if (strlen(str))
    {
        switch(type)
        {
            case LOG_PRAISE_ID:
            case LOG_SYSPRAISE_ID: parse_string = "'za' %i:" + PL_BIE;
            			   przyimek = "za"; przyp = PL_BIE;
            			 break;
            case LOG_IDEA_ID:
            case LOG_SYSIDEA_ID:   parse_string = "'do' %i:" + PL_DOP;
            			   przyimek = "do"; przyp = PL_DOP;
            			 break;
            default:		   parse_string = "'w' / 'we' %i:" + PL_MIE;
            			   przyimek = "w"; przyp = PL_MIE;
            			 break;
        }
	/* Find the target. */
	if (!parse_command(str, environment(this_player()), parse_string,
			   oblist) ||
	    (!sizeof(oblist = NORMAL_ACCESS(oblist, 0, 0))))
	{
	    return 0;
	}

	/* One target at a time. */
	if (sizeof(oblist) > 1)
	{
	    notify_fail("Sprecyzuj, o ktory konkretnie obiekt ci chodzi.\n");
	    return 0;
	}

        this_player()->set_obiekty_zaimkow(oblist);
	target = oblist[0];
	write("Zglaszasz " + (type >= LOG_SYSBUG_ID ? slowa[0][0..7] : "")
	    + slowo + " " + przyimek + " " + 
	    target->short(this_player(), przyp) + ".\n");
    }
    else
    {
	target = environment(this_player());
	write("Zglaszasz " + slowo + " " + (type >= LOG_SYSBUG_ID ?
	    "odnoszac" + slowa[0][7..7] + " sie do calej Arkadii" :
	    "w pomieszczeniu, w ktorym stoisz") + ".\n");
    }

    /* Add the relevant data to the player. */
    this_player()->add_prop(PLAYER_I_LOG_TYPE, type);
    this_player()->add_prop(PLAYER_O_LOG_OBJECT, target);

    setuid();
    seteuid(getuid());

    clone_object(EDITOR_OBJECT)->edit("done_reporting", "");
    return 1;
}

/*
 * report_done - Report something as done (wizards only)
 */
int
report_done(string str)
{
    /* To mortal players, the command done does not exist so we do not
     * have to give a notify_fail message. Apprentices, pilgrims and
     * retired wizards cannot 'do' anything either.
     */
    if (WIZ_CHECK < WIZ_NORMAL)
    {
	return 0;
    }

    notify_fail("Komenda 'done' zostala calkowicie wycofana.\n");
    return 0;
}

/*
 * wiesci - system przegladania przez graczy tablicy poswieconej ogolnym
 *          wydarzeniom i zmianom na Arkadii.
 */
int
wiesci(string str)
{
    if (!Common_Board)
    {
        object *clones = object_clones(find_object(COMMON_BOARD));
        int index = sizeof(clones);

        while (index--)
            if (file_name(environment(clones[index])) == COMMON_BOARD_ROOM)
            {
                Common_Board = clones[index];
                break;
            }

        if (!Common_Board)
        {
            notify_fail("Z jakichs dziwnych powodow System Wiesci Arkadii "
                      + "jest chwilowo niedostepny.\n");
            return 0;
        }
    }

    return Common_Board->wiesci(str);
}