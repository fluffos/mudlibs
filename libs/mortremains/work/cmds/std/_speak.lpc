// _speak.c
// Lets a player change his default language.
// Moby, 6-7-93
// Loose ends fixed by Megadeath 15/7 93
#include <mudlib.h>
#include <language.h>
#include <daemons.h>

inherit DAEMON ;

int help() ;

int cmd_speak (string str) {

	int i ;
	string lang ;
    mapping languages ;

	if (!str) {
        lang = this_player()->query("default_language") ;
        if (!lang)
           lang="common";
		write ("You are currently speaking "+lang+".\n") ;
		return 1 ;
	}
	languages = this_player()->query("languages") ;
	if (!languages) 
        languages = LANGUAGE_D->get_mapping() ;
	    if (languages[lower_case(str)] > 0) {
		write ("You set your default language to "+str+".\n") ;
		this_player()->set("default_language", str) ;
		return 1 ;
	    }
	notify_fail ("You don't speak the language "+str+"!\n") ;
	return 0 ;
}

int help() {
	write ("Usage: speak <language>\n\n"+
"Sets your default language to <language>. You will speak in that\n"+
"language unless you override it by using \"say in <language> <message>\"."+
"With no arguments, speak tells you what language you are currently\n"+
"speaking.\n") ;
	return 1 ;
}
