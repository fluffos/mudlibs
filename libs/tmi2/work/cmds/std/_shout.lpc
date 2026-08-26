// _shout.c
// Command to have players shout. Shouts reach your room and the adjacent
// rooms only - this is NOT a global shout!
// Written by Mobydick, 11-10-92
// Rewritten to suit languages, Megadeath@TMI-2, 15/7 93
// Fixed messed up vars, and types
// Leto 94-13-11

#include <mudlib.h>
#include <language.h>
#include <daemons.h>

inherit DAEMON ;

string g_string, g_lang;

void do_shout(object where, string str, string p_language, int success );

int cmd_shout (string str) {

    mapping rooms, languages ;
    string *roomnames, p_language, ostr ;
	object ob ;
    int i, p_chance, flag, success, loop ;
    string nstr, how, what ;

        if (!str) {
            notify_fail("Shout what?\n");
            return 0;
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
	write ("You stumble out some words, unfamiliar with the tongue.\n");

   //   Now fetch the garbled versions of the string from the language daemon.

   g_string=(string)LANGUAGE_D->garble_string(str, p_language);
   g_lang=(string)LANGUAGE_D->transform_string(str, p_language);


   ostr = "in " + capitalize(p_language) + ": " + str;
   str = ostr;

#endif
#ifndef LANGUAGES
   ostr =": " + str;
   str = ostr;
#endif

    write ("You shout "+str+"\n") ;
        ob = environment(this_player());
        if (!ob) {
            notify_fail("Your shouts go unheard in the void.\n");
            return 0;
        }

    do_shout (environment(previous_object()),nstr, p_language, success) ;

    rooms = ob->query("exits");
roomnames = sizeof(rooms) ? keys(rooms) : ({});
	for (i=0;i<sizeof(roomnames);i++) {
		ob = find_object(rooms[roomnames[i]]) ;
        if (ob) do_shout (ob, nstr, p_language, success ) ;
	}
	return 1 ;
}

int help() {
	write ("Usage: shout <message>\n\n"+
"Shout will broadcast <message> to everyone in the room and in all\n"+
"adjacent rooms. It does not reach anyone else in the MUD. If you are\n"+
"trapped by a bug and need help, use \"wizcall\" instead. Do NOT use\n"+
"wizcall for any other reason.\n"+

#ifdef LANGUAGES
       "If <language> is passed, this will override your spoken language.\n"+
#endif

"See also: say, tell, wizcall\n") ;
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
          nstr=(string)LANGUAGE_D->get_string(str, inv[loop], p_language, success, g_string, g_lang );
#endif
          if (previous_object() != inv[loop] )
             message("say", wrap(previous_object()->query("cap_name") +
                     " shouts" +
#ifndef LANGUAGES
                     ": " +
#endif
                     nstr ),inv[loop]);
      }
   }
}

