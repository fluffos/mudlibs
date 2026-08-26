 
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

// Euh, this isn't the real Tmi-2 tell, but it works :)
// It's not using any tell daemons, but has all functionality
// within the cmd. 
// moved here on 3 nov 95 (5 minutes after i made the pre1 tar :)
// Leto
// 03/10/96 fixed visibility check Leto@Earth
// 03/10/96 later that day, Leto@Earth fixed muds with spaces in name

#include <net/daemons.h>
#include <daemons.h>
#include <mudlib.h>
#include <ansi.h>
#include <net/i3.h>

inherit DAEMON;

#define SYNTAX  "Usage: tell name <@mud> [message]\n"

#define NH " is not on "+MUD_NAME+"."
 
int cmd_tell(string str) {
    string tell_msg, who, msg, target, mud;
     int idlem, idles;
     string idlemsg;
		 string *ignore;
    object ob, act_ob;
    
    act_ob = this_player();
    
    if( !str || sscanf( str, "%s %s", who, msg ) != 2 ) {
       notify_fail( SYNTAX );
       return 0;  }
    
    notify_fail( capitalize(who) + NH + "\n" );
 
    if(sscanf(who, "%s@%s", target, mud) == 2) {
mud = replace_string(mud,"."," ");
    "/adm/daemons/network/I3/tell"->send_tell(this_player()->query("name"), this_player()->query("cap_name"), mud, target, msg);
       return 1;  }
 
    who = lower_case( who );
  ob = find_player(who);
 
  if ( (!ob) || !visible(ob,this_player()) ) {
        notify_fail(capitalize(who)+NH+"\n"); //Ok, crude hack, i know :) Leto
        return 0;}

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
	write(wrap(ob->query("cap_name")+
	" is busy right now, please try again later...\n"));
	return 1;
	}
	write("["+capitalize(who)+" has the busy flag set]\n");
       }

    if(ob == this_player()) 
			{
           message("tell",
           wrap("You tell yourself: "+msg), this_player() );
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
				  write(wrap(ob->query("cap_name")+ " is ignoring you.\n"));
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
       message("tell",wrap(ob->query("cap_name")+" has been idle for "+idlem+
         " minutes and "+idles+ " seconds, ") , this_player() );
       if (!idlemsg) message("tell",wrap("but "+subjective(ob->query("gender"))+
				 " left you no message at all :("), this_player() );
        else message("tell",wrap(possessive(ob->query("gender"))+
				 " idle message is : "+idlemsg), this_player() );
       }
     // Ok, we got our conditions, now do the actual tell.


// Leto: don't like the stuff below, it's ugly !
    if(!ob) 
			{
	     if(ob = find_living(who)) 
				 {
          message("tell",wrap(identify(ob)+" "+identify(this_player())+"\n"),
              this_player() ) ;
	        message("tell",iwrap(act_ob->query("cap_name") + 
		" tells you: " + msg) , ob );
	    message("tell",
             iwrap("You tell "+capitalize(who)+": "+msg) , this_player() );
        	ob->set("reply", act_ob->query("name"));
        	return 1;  
				}
 
     	 return 0; 
	    }
 
    // This is where TMI-2 used to send it to local tell_server 
    //write( TS_D->tell_user(act_ob->query("name"), 0, who, msg) );

      {
      message("tell",
       wrap("You tell "+ob->query("cap_name")+": "+msg+"\n"), this_player() );
      message("tell", iwrap(act_ob->query("cap_name")+
      " tells you: "+ msg+"\n"), ob );
    ob->set("reply", act_ob->query("name"));
      return 1;
   }
}
 

int help() {

write( @HelpText 
Usage: tell name[@mud] <message>

This command allows a user to tell a private message to another player or 
other living creature, no matter where they are located on the mud. It is
also possible to tell users on another mud a message by using the [@mudname] 
addition to the user's name (ie: tell leto@earthmud Hi).
(for muds with spaces in their name, replace the space with a dot, eg:
 tell leto@sodden.earth Hi)

See also: busy, ignore, idlemsg
HelpText
);
return 1;
}
