/*
** FILE:    _gchat.c
** PURPOSE: A chat line, so people can chat with others in their gang.
** CREDITS:
**  9 Feb 2000  Cyanide created this file.
*/

#include <messages.h>

inherit DAEMON;

varargs int broadcast(string gang, string str, object exclude) {
    object *ob;
    int i, sz;

    str = "["+cap_all_words(gang)+"] " + str;

    ob = users();
    sz = sizeof(ob);

    for (i=0; i<sz; i++) {
    if (ob[i]==exclude) continue;
    if (!ob[i]->query("channels/gchat")) continue;

	if (ob[i]->query("gang") == gang)
	    message(MSG_CHANNEL, iwrap(str), ob[i]);
    } 
}

void toggle_gchat( object ob ) {
    int i = ob->query("channels/gchat");

    if (i) {
	write(
    "["+cap_all_words(ob->query("gang"))+"] Tuned out.\n");
	broadcast(ob->query("gang"), ob->query("cap_name")+
	    " has tuned out of gangchat.", ob);
	i = 0;
    } else {
	write("["+cap_all_words(ob->query("gang"))+"] Tuned in.\n");
	broadcast(ob->query("gang"), ob->query("cap_name")+
	    " has tuned into gangchat.", ob);
	i = 1;
    }

    ob->set("channels/gchat", i);
}

int cmd_gchat( string str ) {
    string mygang = TP->query("gang");

    if (!mygang) {
	write("You're not even in a gang, you poser!\n");
	return 1;
    }

    if (!str) {
	toggle_gchat(TP);
	return 1;
    }

    if (!TP->query("channels/gchat")) {
        write("You're not currently tuned into the gangchat.\n");
        return 1;
    }

    str = TPN + ": "+ str;

    broadcast(mygang, str);

    return 1;
}

string help() {
    return wrap("This is the basic chat for talking to your gang. "+
      "It is still very no-frills, but will get more advanced shortly.");
}

/* EOF */
