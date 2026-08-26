//  Original write: Tzar@Earth
//
// Leto thinks that's highly unlikely. Even the tmi-2 0.9 lib
// probably didn't come without a say command :)
// Leto removed some silly arguments to say() and idented the code
// so it would be readable, and optimized Tzar's code quite a bit :)
// say() doesn't work correctly for amcp yet, Leto
// Leto removed iwraps, 160296
// Leto changed all message classes to "say", 030396
// MASSIVELY overhauled by Cyanide 28 August 1997 to support for invis 
//   shit - streamlined in the process..
// (04-23-98) Chronos changes the wrap()'s to iwrap()'s so things look 
//            prettier.  Also removed the extra \n from You say: line. :D
 
#include <mudlib.h>
#include <language.h>
#include <daemons.h>
 string g_string, g_lang;
inherit DAEMON;

 void do_say(object where, string str, string p_language, int success );

 int cmd_say(string str){
  int last, x, i, p_chance, flag, success, loop;
  object *people;
  mapping languages ;
  string nam, verb_a = "say", verb_b = "says", p_language, ostr, nstr, how, what;

  people = all_inventory(environment(this_player()));
//this_player()->block_attack(2) ;
  if ((!str) || (str == " ")) {
    message("error","[say] Usage: say <message>\n", this_player() );
    return 1;
  }

  nstr = str;

#ifdef LANGUAGES

    // Fetch the languages X speaks.

    languages=previous_object()->query("languages");
    if (!languages) languages = LANGUAGE_D->get_mapping() ;
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
 if ( ! success ) {
 str=g_lang;
}
if (p_language != "common"){
    ostr = "in " + capitalize(p_language) + ": " + str;
}
    //    str = ostr;

#endif

#ifndef LANGUAGES
 
 if (p_language != "common"){
    ostr =": " + str;
    }
    str = ostr;
#endif


  last = str[<1];

  if (last == '?') {
    verb_a = "ask";
    verb_b = "asks";
  }
  if (last == '!') {
    verb_a = "exclaim";
    verb_b = "exclaims";
  }

/*
  for (x=0;x<sizeof(people);x++) {
    if (!living(people[x])) continue;
    if (people[x]==this_player()) {
      message("say", iwrap("You "+verb_a+": "+str), TP) ;
    } else {
      if (visible(TP, people[x])) { 
   message("say", iwrap(TPN+" "+verb_b+": "+str), people[x]) ;
      } else {
        tell_object(people[x], iwrap("Somebody "+verb_b+": "+str) );
      }
    }
  }
  */


	do_say((environment(this_player())), str, p_language, success);


  return 1;
}
 void do_say(object where, string str, string p_language, int success )
{
    object *inv;
    int loop, last;
	string nstr, verb_a = "say", verb_b = "says";
    inv=all_inventory(where);
 
 last = str[<1];

  if (last == '?') {
    verb_a = "ask";
    verb_b = "asks";
  }
  if (last == '!') {
    verb_a = "exclaim";
    verb_b = "exclaims";
  }


    loop=sizeof(inv);
    while (loop--)
    {
	
	if (interactive(inv[loop]) )
	{
	    nstr=str;

	    
#ifdef LANGUAGES
	    nstr=(string)LANGUAGE_D->get_string(str, inv[loop],
	      p_language, success, g_string, g_lang );
#endif
/*
	    if ((previous_object() != inv[loop]) &&
	      (!inv[loop]->query("shoutblock")) && (!inv[loop]->query("busy")))
		message("say", iwrap(previous_object()->query("cap_name") +
		    " shouts" +
#ifndef LANGUAGES
		    ": " +
#endif
		    nstr ),inv[loop]);
*/


		if (previous_object() == inv[loop]){
  message("say", iwrap("You "+verb_a+": "+str), TP) ;
  }else{
 if (visible(TP, inv[loop])) { 
   message("say", iwrap(TPN+" "+verb_b+nstr), inv[loop]) ;
      } else {
        tell_object(inv[loop], iwrap("Somebody "+verb_b+nstr) );
      }
    }
	}
    }
}
string help() {

return @HelpText

Usage:  say <message>

The say command sends your <message> to everyone in the current room.

HelpText;
}


