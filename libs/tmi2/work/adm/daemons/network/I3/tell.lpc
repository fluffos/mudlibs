#include <commands.h>
#include <net/i3.h>
 
void send_tell(string from, string visname, string mud, string to, string message){
    if(base_name(previous_object()) != CMD_TELL) return;
    I3_DAEMON->send_packet(PRT_TELL, from, mud, to, ({ visname, message }));
}
 
void process_tell(mixed *info){
    object ob;
    int i;    
    mixed *data;
    string *ignore, mud_from, who_from,msg,idlemsg;
 
    if(base_name(previous_object()) != I3_DAEMON) return;
    if(sizeof(info) != SIZ_TELL) return
      I3_DAEMON->send_error(info[2] , info[3], "bad-pkt", MUD_NAME+": incorrect tell request received, notify your Mud administrator.\n" ,info );
    if( (!(ob = find_living(info[5]))) || (ob->query("invisible") ) || 
        (ob->query("hide") ) ) return
      I3_DAEMON->send_error(info[2] , info[3],"unk-user", capitalize(info[5]) 
        +" is nog logged on.\n" ,"");
    if (!interactive(ob)) return
      I3_DAEMON->send_error(info[2] , info[3], "unk-user", capitalize(info[5])+ " is currently net-dead.\n" ,"");

    mud_from = lower_case(info[2]);
    who_from = lower_case(info[6]);
    ignore = ob->query("ignore");
     if( pointerp( ignore ) )
      {
       if( ( member_array( "@" + mud_from, ignore ) != -1 ) )
   {
    I3_DAEMON->send_error(info[2],info[3],"unk-user",
      ob->query("cap_name") + " is ignoring everyone@" + info[2]+".\n","" );
    return;
   }
   if ( member_array(who_from+ "@"+ mud_from,ignore) != -1 )
   {
    I3_DAEMON->send_error(info[2],info[3], "unk-user",
     ob->query("cap_name")+ " is ignoring you.\n","" );
    return;
   }

 } //ignore
    if (ob->query("busy"))
   {
I3_DAEMON->send_error(info[2],info[3],"unk-user", ob->query("cap_name") +
  " is busy and can't be disturbed.\n","");
    return;
   }

// For Tmi-2 only
#if 1
    // Hmm, inactive seems obsolete with idlemsg
    if (ob->query("inactive"))
    I3_DAEMON->send_error(info[2],info[3], "unk-user",
     ob->query("cap_name")+ " is inactive right now, and might not respond.\n" ,"");
#endif

    if (ob->query("ghost")) 
    I3_DAEMON->send_error(info[2],info[3],"unk-user", 
     ob->query("cap_name")+ " is a ghost and cannot answer right now.\n" ,"");

    if (query_idle(ob) > 60) {

#if 1
   // This is the standard Tmi-2 stuff for idlemsg (they use getenv) 
    idlemsg = (string) ob -> getenv( "idlemsg" );
    msg = sprintf("%s has been idle for %s.\n%s",ob->query("cap_name"),
	      format_time(query_idle(ob)) ,
    ( (idlemsg && idlemsg != "") ? "Idlemsg: " + idlemsg + "\n" : "" )) ;
   
#else
   // This is our Earth stuff, we don't use env  ;)   Leto
     idlemsg = (string)ob->query("idlemsg");
     if (!idlemsg) 
      msg = sprintf("%s has been idle for %s, but %s left you no message.\n",
      ob->query("cap_name"), format_time(query_idle(ob)) ,
      subjective(ob->query("gender")) );
     else 
      msg = sprintf("%s has been idle for %s. %s idle message is:\n%s",
      ob->query("cap_name"), format_time(query_idle(ob)) ,
      capitalize(possessive(ob->query("gender"))),idlemsg );
#endif        
    I3_DAEMON->send_error(info[2],info[3], "unk-user",msg,"" );
}
    message("tell",sprintf("%s@%s tells you: %s\n",info[6], info[2], info[7]), ob);
 // convert some spaces in mudnames to dots
    ob->set("reply",info[3]+"@"+replace_string(info[2]," ","."));
}
 

