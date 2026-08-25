/*
 * Changed to maintain an mapping of arrays of everyone on a channel
 * Also performed so major cleanups...more than doubled the efficiency
 *    -- Wahooka April '97
 */

//inherit "/global/remote_cre";
#include "standard.h"
#include <network.h>

#define GUILD this_player()->query_guild_ob()
#define GROUP this_player()->query_group_ob()
#define RACEG this_player()->query_race_group_ob()  

#define MAX_CHAN_HIST 50

mapping channels = ([ ]),
        history = ([ ]);

int query_channel_on(object ob, string chan);
int query_channel_permission(object ob, string chan);
varargs void do_channel(string verb, string str, string name, string mud, int flg);

void create() {
}

void init_player_channels(string *chans) {
    int i;
    for(i=0;i<sizeof(chans);i++) {
	if(!query_channel_permission(this_player(), chans[i])) continue;
	if(!channels[chans[i]]) channels[chans[i]] = ({ });
	if(query_channel_on(this_player(), chans[i])) continue;
	channels[chans[i]] += ({ this_player() });
    }
    if(this_player()->query_creator() &&
      !query_channel_on(this_player(), "emergency")) {
	if(!channels["emergency"]) channels["emergency"] = ({ });
	channels["emergency"] += ({ this_player() });
    }
}

int query_channel_on(object ob, string chan) {
  return member_array(ob, channels[chan]) != -1;
}

int query_channel_permission(object ob, string chan) {
    switch(chan) {
    case "cre":
    case "dwcre":
    case "geek":
    case "sport":
	if(ob->query_creator()) return 1;
    case "thane":
	if(ob->query_thane()) return 1;
    case "demi":
    case "dwadmin":
	if(ob->query_lord()) return 1;
	return 0;
    default: return 1;
    }
}

object *query_who_on(string chan) {
    object *ret = channels[chan];
    if(!this_player()->query_lord()) {
	int i;
	for(;i<sizeof(ret);i++)
	    if(ret[i]->query_invis() == 2) {
		ret -= ret[i..i];
		i--;
	    }
    }
    return ret;
}

protected void add_history(string chan, string mess) {
  if(!history[chan]) {
    history[chan] = ({ mess });
    return;
  }
  if(sizeof(history[chan]) >= MAX_CHAN_HIST) {
    history[chan] = history[chan][1..] + ({ mess });
    return;
  }
  history[chan] += ({ mess });
}

string get_history(string chan) {
  if(!history[chan]) return 0;
  return implode(history[chan], "\n");
}

int do_chat( string str, string verb ) {

    if (!verb)
      verb = query_verb();

    if(!str || str =="") {
	message("You must have a message too.\n","",TP);
	return 1;
    }
    if(verb == "emergency") {
	do_channel(verb, str, this_player()->query_cap_name());
	return 1;
    }
    if(verb == "guild") {
	if(!GUILD) {
	    message("You are not a member of any guild.\n","",TP);
	    return 1;
	}
	if(!GUILD->query_channel()) {
	    message("Your guild does not have that ability.\n","",TP);
	    return 1;
	}
	verb = (string)GUILD->query_name();
    }
    if(verb == "group") {
	if(!GROUP) {
	    message("You are not a member of any group.\n","",TP);
	    return 1;
	}
	if(!GROUP->query_channel()) {
	    message("Your group does not have that ability.\n","",TP);
	    return 1;
	}
	verb = (string)GROUP->query_name();
    }
    if(verb == "race") {
	if(!RACEG) {
	    message("You are not a member of any race group.\n","",TP);
	    return 1;
	}
	if(!RACEG->query_channel()) {
	    message("Your race group does not have that ability.\n","",TP);
	    return 1;
	}
	verb = (string)RACEG->query_name();
    }

    if(this_player()->query_property("chan_"+verb) == "nope") {
	message("Your channel has been removed.\n","",TP);
	return 1;
    }

    if(!query_channel_permission(this_player(), verb)) {
	message("You are not permitted to use the "+verb+"-channel.\n","",this_player());
	return 0;
    }

    switch( str ) {
    case "off" :
	if(!query_channel_on(this_player(), verb)) {
	    message("The "+verb+"-channel is already off!\n","",this_player());
	    return 0;
	}
	message("Ok, you turn off the "+verb+"-channel.\n","",TP);
	this_player()->adjust_property("channels",({verb}),-1);
	channels[verb] -= ({ this_player() });
	return 1;
    case "on" :
	if(query_channel_on(this_player(), verb)) {
	    message("The "+verb+"-channel is already on!\n","",this_player());
	    return 0;
	}
	if(!channels[verb]) channels[verb] = ({ });
	message("Ok, you turn on the "+verb+"-channel.\n","",TP);
	if(member_array(verb,this_player()->query_property("channels")) == -1)
	    this_player()->adjust_property("channels",({verb}));
	channels[verb] += ({ this_player() });
	return 1;
    }

    if(!query_channel_on(this_player(), verb)) {
	message("You don't have that channel on.\n","",TP);
	return 1;
    }

    do_channel(verb, str, this_player()->query_cap_name());

    if( (verb == "dwcre") || (verb == "dwadmin") 
         || (verb == "intergossip") || (verb == "intercre" )) {
	SERVICES_D->eventSendChannel(this_player()->query_short(), verb,
	  str, 0, 0, 0);
    }
    return 1;
}

string get_channel_help(string verb) {
  string ret;
  if(!verb) verb = "<channel>";
  ret = 
   "'"+verb+" <message>': Send a message to all people listening "
    "to the channel.\n"
   "'"+verb+" ?': This help message.\n"
   "'"+verb+" @': Emote across the channel.\n"
   "'"+verb+" !': See the last "+MAX_CHAN_HIST+" things sent to the channel.\n";
  if(this_player()->query_creator())
    ret += "'"+verb+" .': See a list of people listening to the channel.\n";
  return ret;
}   

#define chan_msg() message(str, name+" "+(flg?"(":"[")+CAP(verb)+(flg?")":"]")\
                    +": ", channels[verb]);\
              add_history(verb, name+" "+(flg?"(":"[")+CAP(verb)+(flg?")":"]")\
               +": "+str);
#define check_cmd() if(strlen(str) > 1) { chan_msg(); return; }

varargs void do_channel(string verb, string str, string name, string mud, int flg) {

  if(sizeof(channels[verb])) // Taniwha 01/05/97, make sure it exists
    channels[verb] -= ({ 0 });
  else channels[verb] = ({ });
  if(mud)
    name = name+"@"+mud;
  switch(str[0]) {
    case '!':
  //return; // Taniwha, just spams the fucking logs, it's gone
// added back by Randor, 20-mar-98 - on Illumitech it's
// kinda useful :)
      check_cmd();
      message(get_history(verb), verb+" history:\n", TP);
      return;
    case '?' :
      check_cmd();
      message(get_channel_help(verb), verb+" help:\n", TP);
      return;
    case '@' :
      message(name+" "+str[1..], (flg?"(":"[")+CAP(verb)+(flg?") ":"] "), 
        channels[verb]);
      add_history(verb,
        (flg?"(":"[")+CAP(verb)+(flg?") ":"] ")+name+" "+str[1..]);
      break;
    case '.' :
      check_cmd();
      if(!this_player() || !this_player()->query_creator()) {
        chan_msg();
        return;
      }
      message(nice_list(query_who_on(verb)->query_cap_name()), 
        "People on the "+verb+"-channel: ", TP);
      break;
    default  :
      chan_msg();
      break;
  }
}

varargs void received_cre(string s) {
    string verb, str, name, mud;

    if (sizeof(s))
      {
      sscanf(s,"%s %s %s %s", verb, name, mud, str);
      switch(verb) {
        case "dwcre":
        case "dwadmin":
        case "intercre":
        case "intergossip":
                    do_channel(verb, str, name, mud);
                    break;
        default:
          do_channel(verb, str, name, 0, 1);
	    }
	}
} /* received_cre() */

// Radix
int clean_up() { return 0; }
