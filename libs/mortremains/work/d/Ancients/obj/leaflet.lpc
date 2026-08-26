/*
** A list of directions for shit in Decatur for newbies.
** Cyanide thought it would be a good idea.
** 13 October 97
** Briefly updated by Chronos.
*/
#include <mudlib.h>

inherit OBJECT;

void create() {
    seteuid(getuid()) ;
    set("id", ({ "leaflet", "brochure", "#NEWBIE#", "newbie_equipment" }) );
    set("short", "a leaflet entitled \"See Beautiful Decatur!\"");
    set("long", @EndLeaflet

                         Welcome, Newbie!!

      For your personal enjoyment and enrichment, here is a short 
       list of frequently most asked directions for newcomers to
                      the great city of Decatur
  
                   N = North              E = East
                   S = South              W = West
 From the Intersection:   
 Shop : 4 S, E (4 moves south, 1 east)       Armory : 4 S, W      
 Pub : S, W                                  Post Office : 2 N, W    
 Classhalls :  (Ask Alucard)                 Newbie Area(s) : 2 S, W  
 College:  4 E, N                                              -or-
 Bank: 2 E, N                                                 3 N, E    

For additional information, type "newbiehelp".
EndLeaflet
    );
}

void init() {
    object ob = environment(this_object());
    if (!living(ob)) call_out("remove", 1);
    add_action("newbiehelp", "newbiehelp");
}

void remove() {
    object ob = environment(this_object());
    if (ob) tell_room(environment(this_object()), 
	  "The newbie item crumbles to dust and blows away.\n");
    ::remove();
}

int newbiehelp(string str) {
    object link ;  
    mapping CLASS ;
    link = TP->query_link() ;
    if (!link) {
	write("leaflet#: error encountered, Notify a wizard.\n");
	return 1;
    }
    CLASS = link->query("Class") ;
    if (!CLASS) {
	write("#leaflet#: Error encountered, Notify a wizard.\n") ;
	return 1;
    }
    str = values(CLASS)[0];
    write (@ENDHELP
                       N e w b i e H e l p   v 1 . 0
                       -----------------------------
ENDHELP
    ) ;
    if (!str || str == "peasant") {
	write(@ENDHELP
The first thing you need to do is select a CLASS.  There are many CLASSes
available on this mud.  To select a CLASS, you must go to the guild of
that CLASS and 'join' it.  You can find the guild halls to the east of
the center of town, find Alucard, and type 'ask alucard about classhalls'.

Feel free to type newbiehelp again once you have selected a CLASS.
ENDHELP
	);
	return 1;
    }
    write("Congratulations on becoming a "+capitalize(str)+"!\n") ;
    if (!TP->query_skills()) {
	write(@ENDHELP
First of all, you don't have any skills yet!
You can type 'skills' to look at your skills and abilities.
You have to have some weapon skills before you go out and try to
fight things, or you will get your ass severely kicked.  You can
learn skills at some of the guild halls and at the College.   
Directions to the College are on this leaflet.
ENDHELP
	) ;
    }
    if (TP->query("wp_free")) {
	write("*** Did you know that you still have "+TP->query("wp_free")
	  +" weapon skills free?\n");
	write(@ENDHELP
Remember that some CLASSes can advance further than others in weapon
skills.  Warriors for example can advance further than most in almost
every weapons style/CLASS.  It's possible for you to train heavily
in one weapon type (Small arms, for example) and not at all in another
type.
ENDHELP
	);
    }
    if (TP->query("nwp_free")){
	write("*** Did you know that you still have "+TP->query("nwp_free")+
	  " non-weapon skills free?\n");
	write(@ENDHELP
Remember that various skills will help you during different aspects
if mudding. Also, keep in mind that your CLASS hall will offer
certain specialized CLASS skills, while the College will offer other,
more general skills.
ENDHELP
	);
    }
    if (!TP->query("wp_free") && !TP->query("nwp_free")){
	write(@ENDHELP
Basically, all that is left is to develop your character further by
gaining experience points through combat and advancing your level
and skills.  Good luck, Adventurer!
ENDHELP
	);
    }
    return 1;
}

/* EOF */

