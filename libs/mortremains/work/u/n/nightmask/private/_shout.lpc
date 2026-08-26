/*
** File: _shout.c
** Purpose: Global communication...  etc.
** Credits:
**   10 Nov 92   Mobydick@TMI-2 created the file.
**   15 Jul 93   Megadeath@TMI-2 rewrote to suit languages.
**   13 Nov 94   Leto@TMI-2 fixed messed up vars and types.
**   12 Oct 97   Cyanide@Nightfall's Keep overhauled to make global and
**               to support for "quiet" rooms and "shoutblock".
**               Also, you do not hear shouts if you are "busy"
**   24 Mar 98   Cyanide made it so you can't shout until lvl 2.
**   25 Dec 98   Cyanide added iwraps. (Merry Xmas!)
*/


#include <mudlib.h>
#include <language.h>
#include <daemons.h>

inherit "/adm/daemons/timezone";

#define SHOUT_LOG "/log/shouts"

string g_string, g_lang;

void do_shout(object where, string str, string p_language, int success );

inherit DAEMON ;
int cmd_shout (string str) {

    mapping languages ;
    string *roomnames, p_language, ostr ;
    object ob, *users, *rooms;
    int i, p_chance, flag, success, loop, shoutblock;
    string nstr, how, what ;

    if (!str) {
	notify_fail("Shout what?\n");
	return 0;
    }

    /*
       if (TP->query_level() < 2) {
	  write("Sorry - due to abuse, you cannot shout until you reach\n"+
	    "level 2. If you REALLY need help, use the 'wizcall' command.\n");
	  return 1;
       }
    */

    if (TP->query("shoutblock")) {
	write("Sorry - your shoublock is on.\n");
	return 1;
    }

    nstr = str;

#ifdef LANGUAGES

    // Fetch the languages X speaks.

    languages=previous_object()->query("languages");
    if (!languages) languages = LANGUAGE_D->get_mapping() ;


    // filter out which language to use

    flag = 0 ;

    ostr = str;

    if ( sscanf (str, "in %s %s", how, what)==2) {
	p_language = lower_case(how) ;
	str = what ;
    } else {
	how = previous_object()->query("default_language") ;
	if (!how) how="common" ;
	p_language = lower_case(how) ;
    }

    if (languages[lower_case(how)] > 0 )
    {
	flag=1 ;
	p_language=lower_case(how);
	p_chance=languages[p_language];
    }

    if (flag==0)
    {
	p_language = "common";
	p_chance = languages[p_language];
	how = "common";
	str = ostr;
    }


    // Now we want to determine success or not, in speaking the language

    success=0;

    if ( random (100) < p_chance )
	success=1;

    if ( ! success ) 
	write ("You stumble out some words, "+
	  "unfamiliar with the tongue.\n");

    //   Now fetch the garbled versions of the string 
    //   from the language daemon.

    g_string=(string)LANGUAGE_D->garble_string(str, p_language);
    g_lang=(string)LANGUAGE_D->transform_string(str, p_language);


    ostr = "in " + capitalize(p_language) + ": " + str;
    str = ostr;

#endif
#ifndef LANGUAGES
    ostr =": " + str;
    str = ostr;
#endif

    write(iwrap("You shout "+str));
    ob = environment(this_player());
    if (!ob) {
	notify_fail("Your shouts go unheard in the void.\n");
	return 0;
    }

    do_shout (environment(previous_object()),nstr, p_language, success) ;

    users = users();
    rooms = ({});
    for (i=0;i<sizeof(users);i++) {
	ob = environment(users[i]);
	if (ob && !ob->query("quiet") && (member_array(ob, rooms)==-1)
	  && (ob!=environment(this_player()) ))
	    rooms += ({ ob });
    }

    for (i=0;i<sizeof(rooms);i++)
	do_shout(rooms[i], nstr, p_language, success);

    write_file(SHOUT_LOG, iwrap(TPN+" shouted: "+str+" at "+
	ctime(query_tzone("EST"))));

    return 1 ;
}


//  Added this for the possibility of a filtered, language based shout.

void do_shout(object where, string str, string p_language, int success )
{
    object *inv;
    int loop;

    inv=all_inventory(where);

    loop=sizeof(inv);
    while (loop--)
    {
	string nstr;
	if (interactive(inv[loop]) )
	{
	    nstr=str;
#ifdef LANGUAGES
	    nstr=(string)LANGUAGE_D->get_string(str, inv[loop],
	      p_language, success, g_string, g_lang );
#endif
	    if ((previous_object() != inv[loop]) &&
	      (!inv[loop]->query("shoutblock")) && (!inv[loop]->query("busy")))
		message("say", iwrap(previous_object()->query("cap_name") +
		    " shouts" +
#ifndef LANGUAGES
		    ": " +
#endif
		    nstr ),inv[loop]);
	}
    }
}

string help() {
    string str = ("Usage: shout <message>\n\n"+
      "Shout will broadcast <message> to everyone on the MUD. If you are\n"+
      "trapped by a bug and need help, use \"wizcall\" instead. Do NOT use\n"+
      "wizcall for any other reason.\n"+

#ifdef LANGUAGES
      "If <language> is passed, this will override your spoken language.\n"+
#endif

      "See also: say, tell, wizcall\n") ;
    return str ;
}

/* EOF */
