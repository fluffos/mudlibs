
// Him messed abit with it, in the early days
//
// Updated interwiz tells at some point by Leto@Earth
// Cleaned it up a bit and added busy flag Leto@Earth 24/12/93
// Completely overhauled and updated by Leto@Earth 14-jan-94 
// (fixed idlemsg, busy, new remote tell)
// Highlighting experiment added by Vagabond@Earth 19-jan-94
// Ignore code added by Leto@Earth 26-feb-94
// Another major clean_up of code, added wrap() everywhere
//  Wiped ansi stuff again and moved it to user.c
//    Leto (29.04.94)
//   Leto added notify for break through busy for admins ;)
// Leto removed wrap code, since wrapping should only be done in receive_message
// these days, since it relies on the window size of users 160296
// Added /last backlog stuff Perrin@Earth 22-Mar-96
// Fixed uids to backlogs can be read/written again, Leto 03-may-96

#include <daemons.h>
#include <mudlib.h>
#include <ansi.h>
#include <net/i3.h>
#include <priv.h>
#include <uid.h>

inherit DAEMON;

#define SYNTAX "Usage: tell {/last | name [@mud] message}\n"

#define NH " is not on "+MUD_NAME+"."
#define BACKLOG_MAX 10

void add_backlog(string, object);

void create() { seteuid(ROOT_UID);} // needed for backlogs 

int cmd_tell(string str) {
    string tell_msg, who, msg, target, mud;
    int idlem, idles;
    string idlemsg;
    string *ignore;
    object ob, act_ob;
    int args,i;

    act_ob = this_player();

    if (!str) {
	notify_fail( SYNTAX );
	return 0;
    }
    args = sscanf(str,"/%s",who);
    if (!args) {
	if (sscanf(str,"%s %s",who,msg) != 2) {
	    notify_fail( SYNTAX );
	    return 0;  }

	notify_fail( capitalize(who) + NH + "\n" );

	if (sscanf(who,"%s@%s",target,mud) == 2) {
	    mud = replace_string(mud,"."," ");
	    if(!I3_DAEMON->query_network_name(mud))
		return notify_fail("I3 error: No such mud.\n");
	    "/adm/daemons/network/I3/tell"->send_tell(this_player()->query("name"), this_player()->query("cap_name"), mud, target, msg);
	    return 1;  }
    }
    else {
	// Perrin 22Mar96
  if(!sizeof(this_player()->query("tell_backlog")))
  {
     write("No logged tells yet, sorry.\n");
       return 1;
   }
	message("tell",sprintf("Backlog of tells:\n%s",
	implode(this_player()->query("tell_backlog"),"\n")+"\n"),act_ob);
	return 1;
    }
    who = lower_case( who );
    ob = find_player( who );

    if((!ob) || ( wizardp(ob) && (!visible(ob,this_player())) ) ) {
	notify_fail(capitalize(who)+NH+"\n"); //Ok, crude hack, i know :) Leto
	return 0;}
    //  if( ( (ob->query("invisible")-1) > wizardp(this_player()) ) || 
    //    (ob->query("hide")) )
    // On popoular demand, invis players can be told stuff.
#if 0
    if(wizardp(ob))
    {
	notify_fail( capitalize(who) + NH + "\n" );
	return 1;
    }
#endif
    if(!interactive(ob)) {
	write("That person is currently net-dead, sorry.\n");
	return 1;
    }
    if(ob && ob->query("npc") && who != (string)ob->query("name") &&
      !wizardp(act_ob))  return 0;

    if(ob->query("busy")) 
    {
	if(!member_group(this_player()->query("name"),"admin"))
	{ 
	    write(ob->query("cap_name")+
	      " is busy right now, please try again later...\n");
	    return 1;
	}
	write("["+capitalize(who)+" has the busy flag set]\n");
    }

    if(ob == this_player()) 
    {
	message("tell",
	  "You tell yourself: "+msg+"\n", this_player() );

	// backlog this, I guess :-)
	add_backlog("You told yourself: "+msg,ob);
	return 1;
    }

    // check ignore, Leto@Earth reinstated it from local ts @tmi-2 

    if(!member_group(this_player()->query("name"),"admin")) 
    {
	ignore = ob-> query( "ignore" );
	if( pointerp( ignore ) )
	{ 
	    if(-1 != member_array( this_player()->query("name"), ignore ))  
	    {
		write(ob->query("cap_name")+ " is ignoring you.\n");
		return 1;
	    }
	}
    }

    // Do we want an extra idle msg to be added ?

    idlem = query_idle(ob) / 60 ;
    if(idlem)
    {
	idles = query_idle(ob) - (idlem * 60);
	idlemsg = (string)ob->query("idlemsg");
	message("tell",ob->query("cap_name")+" has been idle for "+idlem+
	  " minutes and "+idles+ " seconds, " , this_player() );
	if (!idlemsg) message("tell","but "+subjective(ob->query("gender"))+
	      " left you no message at all :(\n", this_player() );
	else message("tell",possessive(ob->query("gender"))+
	      " idle message is : "+idlemsg, this_player() );
    }
    // Ok, we got our conditions, now do the actual tell.


    // Leto: don't like the stuff below, it's ugly !
    if(!ob) 
    {
	if(ob = find_living(who)) 
	{
	    message("tell",identify(ob)+" "+identify(this_player())+"\n",
	      this_player() ) ;
	    message("tell",(act_ob->query("cap_name") + 
		" tells you: " + msg) , ob );

	    add_backlog((act_ob->query("cap_name")+" tells you: "+msg),ob);
	    message("tell",
	      ("You tell "+capitalize(who)+": "+msg) , this_player() );
	    ob->set("reply", act_ob->query("name"));
	    return 1;  
	}

	return 0; 
    }

    // This is where TMI-2 used to send it to local tell_server 
    //write( TS_D->tell_user(act_ob->query("name"), 0, who, msg) );

    {
	message("tell",
	  ("You tell "+ob->query("cap_name")+": "+msg+"\n"), this_player() );
	message("tell", (act_ob->query("cap_name")+
	    " tells you: "+ msg+"\n"), ob );
	ob->set("reply", act_ob->query("name"));
	add_backlog( (act_ob->query("cap_name")+" tells you: "+
       msg),ob);
	return 1;
    }
}


string help() {

    return @HelpText 

Usage:  tell {</last> | <name>[@mud] <message>}

This command allows a user to tell a private message to another player or 
other living creature, no matter where they are located on the mud. It is
also possible to tell users on another mud a message by using the <@mudname>
addition to the user's name (ie: tell leto@earthmud Hi).
For mudnames with spaces in them, use dots instead of spaces. eg:
tell leto@some.mud Hi

See also: busy, ignore, idlemsg, harass, say, emote

HelpText;
}

// Emeradii's code to help with scrolling of backlog
// Perrin - March 1996
void add_backlog(string msg,object victim)
{
    string *backlog;
    int count ;

    backlog = victim->query("tell_backlog");
    count = sizeof(backlog);
  if(undefinedp(victim->query("tell_backlog")))
    victim->set("tell_backlog",({}),OWNER_ONLY);
  if(count >= BACKLOG_MAX) backlog = backlog[1..9];
    msg = replace_string(msg,"tells","told",1);
	if(!backlog) backlog = ({ msg }) ;
	else backlog = backlog + ({ msg }) ;

	victim->set("tell_backlog",backlog,OWNER_ONLY);
}
