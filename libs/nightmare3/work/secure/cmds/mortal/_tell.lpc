#include <std.h>
#include <daemons.h>
#include <tell.h>

inherit DAEMON;

int cmd_tell(string str) {
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
        for(i=0; i<maxi; i++) {
            tmp = lower_case(implode(words[0..i], "."));
            if((int)NETWORK_D->mud_exists(tmp)) {
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
    }
    else SERVICES_D->send_gtell(mud, who, msg);
    if(ob) {
        string frm;

        if(archp(ob)) frm = (string)this_player()->query_CapName();
        else frm = (string)this_player()->query_cap_name();
        message("tell", frm + " tells you: "+msg, ob);
        if((int)ob->query_invis(this_player()) || hiddenp(ob)) {
            ob->set_rproperty("reply", (string)this_player()->query_name());
            message("error", "Tell whom what?", this_player());
            return 1;
        }
        else if(userp(ob) && !interactive(ob))
          message("my_action", (string)ob->query_CapName()+
            " is net-dead.", this_player());
        else if(userp(ob) && (query_idle(ob) > 60))
          message("my_action", (string)ob->query_cap_name()+
            " is idle and may not have been paying attention.", this_player());
        else if((int)ob->query_blocked("tell")) { 
            message("my_action", (string)ob->query_cap_name()+" is blocking "+
            "all tells.", this_player());
            return 1;
        }
        else if(in_edit(ob) || in_input(ob))
          message("my_action", (string)ob->query_CapName()+" is in input "+
            "and may not be able to respond.", this_player());
        message("my_action", "You tell "+(string)ob->query_CapName()+
          ": "+msg, this_player());
        ob->set_property("reply", (string)this_player()->query_name());
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
      "See also: say, shout, yell, emote", this_player()
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
