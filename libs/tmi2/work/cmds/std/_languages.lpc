// _languages.c
// Tells a player what languages he speaks.
// Mobydick, 6-7-93.
// Loose ends fixed by Megadeath, 15/7 93

#include <mudlib.h>
#include <daemons.h>
#include <language.h>

inherit DAEMON ;

string help() ;

int cmd_languages (string str) {

	int i ;
	int skill ;
	mapping languages ;
	string *langu;

	languages = this_player()->query("languages") ;
	
	if (!languages) 
        languages = LANGUAGE_D->get_mapping() ;

    langu = keys(languages) ;

    for (i=0;i<sizeof(langu);i++) {
	    string lang;
	    lang = langu[i] ;
	    skill = languages[lang] ;
	    switch (skill) {
		case 91..100 : {
			write ("You are fluent in "+lang+".\n") ;
			break ;
		}
		case 61..90 : {
			write ("You speak "+lang+" very well.\n") ;
			break ;
		}
		case 41..60 : {
			write ("You speak "+lang+" passably.\n") ;
			break ;
		}
		case 11..40 : {
			write ("You can speak "+lang+" a little bit.\n") ;
			break ;
		}
		case 1..10 : {
			write ("You know a few words of "+lang+".\n") ;
			break ;
		}
		default : {
			write ("You can't speak "+lang+" at all.\n") ;
		}
	    }
	}
	return 1 ;
}

string help() {
	return ("Syntax: languages\n\n"+
"Tells you which languages you speak, and how well you speak them.\n"+
"\nSee also: speak, say\n");
}

// This one is for the MSDOS version :)

int cmd_lang (string str)
{
  return cmd_languages (str);
}

