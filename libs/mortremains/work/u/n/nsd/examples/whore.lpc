// The crack whore!
// Coded by Chronos, for the fun of it.
// (The same reason you Putt-Putt) ...

#include <mudlib.h>

inherit MONSTER ;

int acquire_hero(object who) ;
object hero ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("wimpy", 75) ;
    set("moving", 1) ;
    set("prevent_summon", 1) ;
    set("speed", 15) ;
    set("short", "a crack whore") ;
    set ("long", @ENDLONG
She's very ugly, and very Cracked Out.
ENDLONG
    );
    set("author", "Chronos - You're welcome.") ;
    set ("id", ({"crackwhore", "whore", "crack whore", "hooker"}) );
    set_name("Crack Whore");
    set("race", "human") ;
    set("smell", "She smells like vomit.") ;
    set ("gender", "female") ;
    set ("race", "human");
    enable_commands() ;
    set ("stat/constitution", 10);
    set ("stat/strength", 14);
    set ("base_ac", 8);
    set ("armor_class", 7);
    set ("damage", ({ 1, 4 }) ) ;
    set ("weapon_name", "fists");
    set ("CLASS", "warrior");
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
    set_size(5);
    set_level(1) ;
    set ("speed", 10);
    set("wealth", random(20) ) ;
}             

void init() {
    if (!hero) call_out("acquire_hero", 2, TP) ;
    else if (!random(5)) call_out("acquire_hero", 2, TP) ;
}

int acquire_hero(object who) {
    if (environment(who) != environment()) return 1;
    if (TP->query("invisible")) return 1;
    if (TP->query("gender") != "male") {
	tell_object(who, "Crack Whore says [to you]: Get outta here, bitch!  This is my corner!\n") ;
	message("Whore", "Crack Whore says [to "+
	  who->query("cap_name") + "]: Get outta here, bitch!\n       This is my corner!\n",
	  environment(who), ({ who }) ) ;
	return 1;
    }
    if  (!random(5)) {
	hero = who ;
	command("to "+who->query("name")+" Hey baby.. looking for a good time?") ;
	tell_object(who, "Crack Whore begins following you.\n") ;
	delete("moving") ;
	set("long", "She's very ugly, and very Cracked Out.\nShe is currently in love with "+hero->query("cap_name")+".\n") ;
	set("short", hero->query("cap_name")+"'s crack whore") ; 
	call_out("annoy", random(10)+3) ;
    }
    return 1;
}


void heart_beat() {
    if (hero && (!hero->query("dying")) && 
      (environment() != environment(hero))) {
	tell_object(environment(), "The Crack Whore stumbles away, following "+hero->query("cap_name")+".\n") ;
	TO->move(environment(hero)) ;
	tell_object(hero, "A Crack Whore stumbles in, following you.\n") ;
	message("whore", "A Crack Whore stumbles in, following "+
	  hero->query("cap_name")+".\n", environment(hero), ({ hero }) ) ;
    }
    heal_up();
    ::heart_beat() ;
}

int annoy() {
    string x, y,z ;
    z = hero->query("cap_name") ; 

    if (!hero || !environment() || (environment(hero) != environment()))
	return 0;

    switch(random(22)) {
    case 0:  x="Crack Whore tries to fondle you.\n";
	y="Crack Whore tries to fondle "+z+".\n";
	break ;
    case 1:  x="Crack Whore says [to you]: Hey baby...\n";
	y="Crack Whore says [to "+z+"]: Hey baby...\n";
	break ;
    case 2:  x="Crack Whore says [to you]: Come on baby..\n";
	y="Crack Whore says [to "+z+"]: Come on baby..\n";

	break ;
    case 3:  x="Crack Whore gropes you.\n";
	y="Crack Whore gropes "+z+".\n";
	break ;
    case 4:  x="Crack Whore harasses you.\n";
	y="Crack Whore harasses "+z+".\n";
	break ;
    case 5:  x="Crack Whore flashes you.\n";
	y="Crack Whore flashes "+z+".\n";
	break ;
    case 6:  x="Crack Whore stumbles.\n";
	y="Crack Whore stumbles.\n";
	break ;
    case 7: x="Crack Whore vomits on your shoe.\n";
	y="Crack Whore vomits on "+z+"'s shoes.\n";
	break ;
    case 8: x="Crack Whore trips and falls.\n";
	y="Crack Whore trips and falls.\n";
	break ;
    case 9: x="Crack Whore tries to take your clothes off.\n";
	y="Crack Whore tries to take "+z+"'s clothes off.\n";
	break ;
    case 10: x="Crack Whore dances for you.\n";
	y="Crack Whore dances for "+z+".\n";
	break ;
    case 11: x="Crack Whore teeters for a moment, but regains her balance.\n";
	y="Crack Whore teeters for a moment, but regains her balance.\n";
	break ;
    case 12: x="Crack Whore tries to hold your hand.\n";
	y="Crack Whore tries to hold "+z+"'s hand.\n";
	break ;
    case 13: x="Crack Whore shoots up in the corner of the room.\n";
	y="Crack Whore shoots up in the corner of the room.\n";
	break ;
    case 14: x="Crack Whore reapplies her makeup.\n";
	y="Crack Whore reapplies her makeup.\n";
	break ;
    case 15: x="Crack Whore grabs your ass.\n";
	y="Crack Whore grabs "+z+"'s ass.\n" ;
	break ;
    case 16: x="Crack Whore says [to you]: My pimp is gonna be mad at you if you don't pay me.\n";
	y="Crack Whore says [to "+z+"]: My pimp is gonna be mad at you if you don't pay me.\n" ;
	break ;
    case 17: x="Crack Whore says [to you]: I'll rock your world baby..\n";
	y="Crack Whore says [to "+z+"]: I'll rock your world baby..\n" ;
	break ;
    case 18: x="Crack Whore says [to you]: Me so horny..\n";
	y="Crack Whore says [to "+z+"]: Me so horny..\n" ;
	break ;
    case 19: x="Crack Whore says [to you]: Me love you long time..\n";
	y="Crack Whore says [to "+z+"]: Me love you long time..\n" ;
	break ;
    default: x="Crack Whore looks around, confused.\n";
	y="Crack Whore looks around, confused.\n";
	break ;
    }
    tell_object(hero, x ) ;
    message("Whore", y, environment(hero), ({ hero }) ) ;
    call_out("annoy", random(10) + 25) ;
    return 1;
}
