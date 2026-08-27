/*  -*- LPC -*-
 *    /secure/cmds/player/tell.c
 *    from the Nightmare IV LPC Library
 *    the tell command
 *    created by Descartes of Borg 950523
 *
 *  10.23.95  Tim changed for this mudlib
 */

#include <command.h>
#include <net/daemons.h>

int
main(string str) {
    string *words;
    mixed mud;
    object ob;
    int i, maxi;
    string who, msg, tmp;

    if(!str) return notify_fail("Syntax: <tell [who] [message]>\n");
    mud = 0;
    if((maxi=sizeof(words = explode(str, "@"))) > 1) {
        who = convert_name(words[0]);
        if(maxi > 2) words[1] = implode(words[1..maxi-1], "@");
        maxi = sizeof(words = explode(words[1], " "));
        for(i=maxi - 1; i >= 0; i--) {
	    string *mts;
            tmp = lower_case(implode(words[0..i], " "));
	    
	    if( (string)INTERMUD_D->GetMudName(tmp) ) {
                mud = tmp;
                if(i+1 < maxi) msg = implode(words[i+1..maxi-1], " ");
                else msg = "";
                break;
            }
        }
        if(msg == "") return notify_fail("Syntax: <tell [who] [message]>\n");
        if(!mud) mud = -1;
    }
    if(!mud || mud == -1) {
        maxi = sizeof(words = explode(str, " "));
        who = 0;
        for(i=0; i<maxi; i++) {
            if(ob=find_living(tmp=convert_name(implode(words[0..i], " ")))) {
                who = tmp;
                if(i+1 < maxi) msg = implode(words[i+1..maxi-1], " ");
                else msg = "";
                break;
            }
        }
        if(!who) {
            if(!mud) return notify_fail("Tell whom what?\n");
            else return notify_fail(mud_name()+" is not aware of that mud.\n");
	}
        if(msg == "") return notify_fail("What do you wish to tell?\n");
    } else {
	SERVICES_D->eventSendTell(who, mud, msg+"\n");
	return 1;
    }

    if(ob) {
        string frm;

	frm = this_player()->query_cap_name();
        if(!ob->short()) {                                  // invisible
	  return notify_fail("Tell whom what?\n");
	}
        else if(userp(ob) && !interactive(ob))
          message("my_action", (string)ob->query_cap_name() +
		  " is net-dead.\n", this_player());
        else if(userp(ob) && (query_idle(ob) > 60))
          message("my_action", (string)ob->query_cap_name() + " is idle and"
		  "may not have been paying attention.\n", this_player());
        else if((int)ob->GetBlocked("tell")) { 
	  message("my_action", (string)ob->query_cap_name() + " is blocking "+
		  "all tells.\n", this_player());
	  return 1;
	} else if(in_edit(ob) || in_input(ob))
          message("my_action", (string)ob->query_cap_name() + " is in input "+
		  "and may not be able to respond.\n", this_player());
        
        message("tell", frm + " tells you: "+msg+"\n", ob);
        message("my_action", "You tell "+(string)ob->query_cap_name()+
          ": " + msg + "\n", this_player());
    }
    return 1;
}

void help() {
    message("help",
      "Syntax: <tell [player] [message]>\n"
      "        <tell [player]@[mud] [message]>\n\n"
      "Sends the message to the player named either on this mud if no "
      "mud is specified, or to the player named on another mud when "
      "another mud is specified.  For muds with more than one word in their "
      "names, use . (periods) to take place of spaces.  Example: tell "
      "descartes@realms.of.chaos hi\n\n"
      "See also: say, shout, yell, emote\n", this_player()
    );
}

string morse(string msg) {
mapping __Morse;
    string tmp;
    int x, i;
__Morse = ([ "a" : ".-", "b" : "-...", "c" : "-.-.",
"d" : "-..", "e" : ".", "f" : "..-.", "g" : "--.", "h" : "....", "i" : "..",
"j" : ".---", "k" : "-.-", "l" : ".-..", "m" : "--", "n" : "-.", "o" : "---", 
"p" : ".--.", "q" : "--.-", "r" : " .-.", "s" : "...", "t" : "-", "u" : "..-", 
"v" : "...-", "w" : ".--", "x" : "-..-", "y" : "-.--", "z" : "--..",
"1" : ".----", "2" : "..---", "3" : "...--", "4" : "....-", "5" : ".....",
"6" : " -....", "7" : "--...", "8" : "---..", "9" : "----.","0" : " -----" ]);
    for(tmp = "", x = strlen(msg), i=0; i< x; i++) {
        if(__Morse[msg[i..i]]) tmp += __Morse[msg[i..i]]+" ";
        else tmp += msg[i..i]+ " ";
    }
    return tmp;
}
