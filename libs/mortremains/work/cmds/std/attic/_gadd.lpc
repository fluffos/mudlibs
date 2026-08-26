/*
** FILE:    _gadd.c
** PURPOSE: Adds a player to your gang.
** CREDITS:
**   10 Feb 2000   Cyanide created the file.
*/

#include <messages.h>
#include <daemons.h>

inherit DAEMON;

int cmd_gadd(string str) {
    object ob;
    mapping map;

    if (!str) {
	write("Add who to your gang?\n");
	return 1;
    }

    ob = present(str, environment(TP));

    if (!ob || !userp(ob)) {
	write(capitalize(str)+" is not a player in the room with you.\n");
	return 1;
    }

    if (ob->query("gang")) {
	write(ob->query("cap_name")+" is already in a gang!\n");
	return 1;
    }

    map = GANG_D->get_list_map();
    if (map[TP->query("gang")] != TP->query("name") ) {
	write("You aren't the leader of that gang!\n");
	return 1;
    }

    write("Your invitation has gone out to "+ob->query("cap_name")+".\n");
    tell_object(ob, wrap(TPN+" has just invited you to join "+
	capitalize(TP->query("gang"))+".")+"Will you join? [Y/N] ");

    ob->input_to("invite", 1, TP, ob);

    return 1;
}

int invite( string str, object ob1, object ob2 ) {
    object *ob;
    int i, sz;

    if (!str || lower_case(str[0..0])!="y") {
	tell_object(ob2, "You have declined "+ob1->query("cap_name")+
	  "'s offer\n");
	tell_object(ob1, ob2->query("cap_name")+
	  " politely declines your offer.\n");
	return 1;
    }

    str = ob1->query("gang");

    tell_object(ob2, "You have joined "+str+"!\n");
    tell_object(ob1, ob2->query("cap_name")+
      " has accepted your offer!\n");

    ob2->set("gang", str);

    ob = users();
    sz = sizeof(ob);

    for (i=0; i<sz; i++) {    
	if (ob[i]==ob2) continue;
	if (!ob[i]->query("channels/gchat")) continue;

	if ( (string)ob[i]->query("gang") == str)
	    message(MSG_CHANNEL, iwrap("[Gangchat] "+
		ob2->query("cap_name")+ " has just joined "+capitalize(str)+
		"!"), ob[i], ({}) );
    } 

    return 1;
}

string help() {
    return(@EndHelp
Usage: gadd <player>

This command allows the leader of a gang to invite other player to join
his gang.
EndHelp
    );
}

/* EOF */
