/*
** File: razor.c
** Author: Lady Nsd
** Inspired from :
** The infamous cream pie! By Chronos.
*/
#include <mudlib.h>

inherit OBJECT;


void create() {
    seteuid(getuid()) ;
    set("author", "nsd");
    set("short", "A barber's razor");
    set("long", @ENDLONG
A cool item to shave yourself or others ;)

Commands:
shaveme
shave <player>
ENDLONG
    );
    set("id", ({ "razor", "barber's razor" }) ) ;
}

void init() {
    add_action("shaveme", "shaveme");
    add_action("shave", "shave");
}

int shaveme(string str) {
    write("You shave yourself. You feel clean now ;)\n");
    say(TPN+" shaves "+objective(TP->query("gender"))+"self. "+
      subjective(TP->query("gender"))+" feels clean now ;)\n");
    return 1;
}

int shave (string str) {
    object target;
    if (!str) {
	write("Who you want to shave?\n") ;
	return 1; 
    }
    target = find_player(str) ;
    if (!target || target->query("invisible")) {
	write("Can't find that player online.\n") ;
	return 1;
    }
    if (target==TP) {
	write("You can't do that, idiot.\n") ;
	return 1;
    }
    if (target->query("busy")) {
	write("They have the busy flag set.  You can't fuck with them right now.\n") ;
	return 1;
    }
    str = capitalize(str) ;
    if (environment(TP) == environment(target)) {
	write("You shave your initials on the head of "+str+".\n");
	message("razor", TPN+
	  " shaves "+POSS+" initials on the head of "+str+"!\n",
	  environment(TP), ({ TP, target }) ) ;
	tell_object(target, TPN+ 
	  " shaves "+POSS+" initials on your head...:-P\n") ;
    } else {          
	write("You shave the head of "+str+"!\n") ;
	say(TPN+" shaves a random head of a mud player!\n") ;
	tell_object(target, "A razor matelializes in the air"+
	  " and shaves you bald!!!\n"+
	  "...You hear "+TPN+" chuckle softly from a distance.\n");
	message("cream pie", 
	  "A razor matelializes in the air and shaves "+str+
	  " bald!!!\n", environment(target), ({ target }) ) ;
    }
    TO->move(target) ;
    delete("short") ;
    delete("id") ;
    delete("long") ;
    set("extra_look", "$N's head is completely bald!!\n") ;
    call_out("remove_razor", 100);
    return 1;
}

int remove_razor() {
    message("blah", "The hair on "+environment()->query("cap_name")+
      "'s head finally grows back.\n",
      environment(environment()),
      ({ environment() }) ) ;
    tell_object(environment(), "Your hair finally grows back.\n") ;
    remove() ;
}

