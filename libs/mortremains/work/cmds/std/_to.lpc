// Written by Chronos so people can't avoid busy flags by using the
// "to" emote.
// (06-12-96) Written by Chronos.
// (04-06-98) Chronos@NK - Updated for the NK lib.
// (02-05-00) Cyanide@MR removed the bug that allowed any wiz to
//            "to" invis admin.

#include <mudlib.h>

inherit DAEMON;

int cmd_to(string str) {
    string name, busy, msg;
    object target;
    /* Not needed in this lib.
      if ((int)TP->query_rest_status()==2) {
       write("You cannot speak while you are sleeping.\n");
       return 1;
     }
    */
    if (TP->query("mute")) {
	write("You are mute, and cannot speak.\n");
	return 1;
    }
    if (!str) {
	write("Usage: to <player> <msg>\n");
	return 1;
    }
    if (sscanf(str, "%s %s", name, msg) != 2) {
	write("Usage: to <player> <msg>\n");
	return 1;
    }
    name = lower_case(name);
    target = present(name, environment(TP));
    if (!target) target = find_player(name) ;
    if (target) {
	if (!visible(target, TP)) target = 0;
	/*
		if (!wizardp(TP) && target->query_invis()) target = 0 ;
		else {
		    if (!member_group(TPn, "arches") && (int)target->query_invis()==2)
			target = 0 ;
		}
	*/
    }
    if (!target) {
	write("Can't find anyone named '"+capitalize(name)+"'.\n");
	return 1;
    }
    if (target == TP) {
	write(iwrap("You say [to yourself]: "+msg)) ;
	message("say", iwrap(TPN+" says [to "+
	    subjective(TP->query("gender"))+"]: "+msg), environment(TP),
	  ({ TP }) ) ;
	return 1;
    }
    if (environment(target) != environment(TP)) {
	if (!wizardp(TP) && !wizardp(target)) {
	    write("That person isn't here.\n");
	    return 1;
	}
	busy = (string)target->query("busy");
	if (busy) {
	    write("You cannot reach that person because '"+busy+"'.\n");
     if (!adminp(TP)) 
	    return 1;
   else write("Well, okay.. *YOU* can.. but only cuz your an Admin.\n") ;
	}
	if (!wizardp(target)) {
	    tell_object(target, "The wind picks up.\n") ;
	    tell_object(target, iwrap("You hear the voice of "+TPN+
		" whisper: "+msg)) ;
	} else {
	    tell_object(target, iwrap(TPN+" tells you: "+msg)) ;
	}
	write(iwrap("From afar, you tell "+capitalize(name)+": "+msg)) ;
	return 1;
    }
    write(iwrap("You say [to "+capitalize(name)+"]: "+msg)) ;
    message("say", iwrap(TPN+" says [to "+capitalize(name)+"]: "+msg),
      environment(TP), ({ TP, target }) ) ;
    message("say", iwrap(TPN+" says [to you]: "+msg), target) ;
    return 1;
}

string help() {
    return @ENDHELP
Usage: to <player> <msg>

This command allows you to say things TO a player.

ie - You say [to Someone]: HI!
     Someone says [to you]: HI!

See also: say, tell, whisper, reply, wreply, yell, shout
ENDHELP
    ;
}
