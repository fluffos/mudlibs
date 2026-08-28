//      /bin/user/_shout.c
//      from the Nightmare Mudlib
//      the shout command
//      created by Descartes of Borg september 1992
//      rewritten by Descartes 930823
//      rewritten by Valodin using Valodin's languages 930823

#include <std.h>
#include <security.h>

inherit DAEMON;

void tell_em(string prefix, string str, object *ob);
mapping make_speakers(object *ob, string lang);
mapping make_speech(mapping speakers, string str, int prof);
void shout_out(string lang, string str, int prof);

int cmd_shout(string str) {
    string lang, tmp;
    int sp_cost;
    object *who;

    if(this_player()->query_ghost()) {
        message("my_action", "You moan mournfully.", this_player());
        return 1;
    }
    if(!wizardp(this_player())) {
      message("my_action", @TEXT
The surgeon general has deemed that shouting is unhealthy for
the mortal throat and it has caused cancer in labratory animals.
TEXT
,this_player());
      return 1;
    }
    if(!str) {
        message("my_action", "Sore throat?", this_player());
        return 1;
    }
    sp_cost = 30;
    if(wizardp(this_player())) sp_cost = 0;
    else sp_cost -= (50 * (int)this_player()->query_skill("telepathy")) / 100;
    sp_cost = (sp_cost < 0)? 0:sp_cost;
    if(!wizardp(this_player()) && (int)this_player()->query_ppe() < sp_cost)
	return notify_fail("You do not have the strength of mind right now,\n");
//    if(environment(this_player())->query_property("no shout")) {
//        message("my_action", "Your voice does not travel very far.", 
//          this_player());
//        return 1;
//    }
    if((string)this_player()->query_name() == "guest") {
	notify_fail("No shouting priviledges for Guest.\n");
	return 0;
    }
    this_player()->add_mp(-sp_cost);
    who = filter_array(users(),"is_online", this_object());
    write("You shout: "+str);
    tell_em((string)this_player()->query_cap_name() + " shouts: ",
	str, who);
    if(strlen(str) > 250)
    {
         notify_fail("That is too much for other players to handle.\n");
         return 0;
    }
    
    return 1;
}

int is_online(object ob)
{
   if(!ob || ob->query_blocked("shout"))
     return 0;
   return 1;
}

void tell_em(string prefix, string str, object *ob)
{
   int i, obsz;

   for(i = 0, obsz = sizeof(ob); i < obsz; i++)
    message("shout", prefix+str, ob[i], this_player());
}


void help() {
    message("help",
      "Syntax: <shout [message]>\n\n"
      "Sends a telepathic shout to the entire mud.  "
      "Misuse of this power may result in action from law.  "
      "Telepathy skill reduces the cost of this.",
      this_player()
    );
}
