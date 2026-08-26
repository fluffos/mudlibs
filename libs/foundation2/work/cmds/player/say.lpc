/*    /cmds/player/say.c
 *    from the Foundation II LPC Library
 *    the say command for local communication
 *    created by Descartes of Borg 950412
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    string msg, punctuation, verb = "say";
    int punc;

    if( !environment(this_player()) ) return "You are nowhere.";
    if( !args || args == "" ) {
	message("my_action", "You mutter to yourself.", this_player());
	message("other_action", (string)this_player()->GetName() + 
	  " mutters to " + reflexive(this_player()) + ".",
	  environment(this_player()), ({ this_player() }));
	return 1;
    }
    args = capitalize(args);
    switch(punc = args[<1]) {
        case '?': verb = "ask"; punctuation = ""; break;
        case '!': verb = "exclaim"; punctuation = ""; break;
        default: 
	    if ((punc >= 'a' && punc <= 'z') || (punc >= 'A' && punc <= 'Z'))
	      punctuation = ".";
	    else punctuation = "";
	    break;
    }
    if( creatorp(this_player()) || avatarp(this_player()) )
      verb = ((string)this_player()->GetMessage(verb) || verb); 
    msg = "You " + verb + ", %^CYAN%^\"" + args + punctuation +
    "%^RESET%^CYAN%^\"%^RESET%^";
    message("my_action", msg, this_player());
    msg = (string)this_player()->GetName() + " " + pluralize(verb) + 
    ", %^CYAN%^\"" + args + punctuation + 
    "%^RESET%^CYAN%^\"%^RESET%^";
    message("other_action", msg, environment(this_player()), 
      ({ this_player() }));
    return 1;
}

void help() {
    message("help", "Syntax: <say [message]>\n\n"
      "Sends the message you specify to all people in the same room "
      "as you.  If you are an avatar, you have the ability to customize "
      "the way these messages come out through the \"message\" "
      "command.\n\n"
      "See also: message, page, shout, speak, tell", this_player());
}

