 
//	File	:  /cmd/xtra/_snoop.c
//	Created	:  Buddha@TMI  (2/19/92)
//	Help by	:  Mobydick@TMI
//	Updated	:  Watcher@TMI (3/27/93)
//
//	This is the standard wizard snoop command.
 

#include <mudlib.h>
#include <logs.h>

inherit DAEMON ;

protected int query_notify(object who);
 
 
int cmd_snoop(string str) {
   object ob, snooping;
   int flag;
 
   if(str == "-n") {  flag = 1;  str = "";  }
 
   if(str && sscanf(str, "-n %s", str) == 1)  flag = 1;
 
   snooping = query_snooping(this_player());
 
   if(!str || str == "") {
     if(snoop(this_player()))  write("Snoop disabled.\n");
     else write("Snoop: Could not disable snoop.\n");
 
    if(snooping && (query_notify(snooping) || flag))
     tell_object(snooping, bold((string)this_player()->query("cap_name") +
		 " stops snooping you.\n"));
   return 1; }
 
   if(!(ob = find_player(str = lower_case(str)))) {
    notify_fail("Snoop: No such player.\n");
   return 0; }
 
   if(ob == this_player()) {
    notify_fail("Snoop: You cannot snoop yourself.\n");
   return 0; }
 
   if(query_snoop(ob)) {
 
   	if(query_snoop(ob) == this_player()) {
	printf("Snoop: You are already snooping %s.\n", capitalize(str));
	return 1; }

    	if(adminp(geteuid(this_player()))) {
	write("\n" + capitalize(str) + " is presently being snooped by " +
	      (string)query_snoop(ob)->query("cap_name") + ".\n" +
	      "Do you wish to override? [y/n] ");
 	input_to("snoop_override", 0, ob, flag);
	return 1; }

    notify_fail("Snoop: Attempt to snoop " + capitalize(str) + " failed.\n");
   return 0; }
 
    if(snoop(this_player(), ob)) {
	write("Now snooping.\n");
	if(snooping && (query_notify(snooping) || flag))
	tell_object(snooping, bold((string)this_player()->query("cap_name") +
		    " stops snooping you.\n"));
	if(query_notify(ob) || flag)
	tell_object(ob, bold((string)this_player()->query("cap_name") +
		    " starts to snoop you.\n"));
    }

    else write("Snoop: Attempt to snoop " + capitalize(str) + " failed.\n");
 
#ifdef SNOOP_LOG
   log_file(SNOOP_LOG, (string)this_player()->query("cap_name") + 
	" snooped " + (string)ob->query("cap_name") + " [" +
	extract(ctime(time()), 4, 15) + "]\n");
#endif
 
return 1; }

protected int snoop_override(string str, object who, int flag) {
   object snooping;
 
   snooping = query_snooping(this_player());

   if(str != "yes" && str != "y") {
   write("Snoop: Attempt aborted.\n");
   return 1; }

   if(query_snoop(who))
     tell_object(query_snoop(who), "[Snoop channel closed]\n");

    if(snoop(this_player(), who)) {
        write("Now snooping.\n");
	if(snooping && (query_notify(snooping) || flag))
	tell_object(snooping, bold((string)this_player()->query("cap_name") +
                    " stops snooping you.\n"));
	if(query_notify(who) || flag)
	tell_object(who, bold((string)this_player()->query("cap_name") +
                    " starts to snoop you.\n"));
    }

    else write("Snoop: Attempt to snoop " + (string)who->query("cap_name") +
	       " failed.\n");
 
#ifdef SNOOP_LOG
   log_file(SNOOP_LOG, (string)this_player()->query("cap_name") +
        " snooped " + (string)ob->query("cap_name") + " [" +
        extract(ctime(time()), 4, 15) + "]\n");
#endif
 
return 1; }
 
//   This function decides if the snoopee should get notified when
//   the snooper starts and stops snooping.
 
protected int query_notify(object who) {
 
   if(!who || !wizardp(who))  return 0;
 
   if(adminp(geteuid(this_player()))) {
	if(adminp(geteuid(who)))  return 1;
   return 0; }
 
   if((int)who->query("snoopable"))  return 1;

return 0; }
 
 
 
int help() {
	write("Usage: snoop [-n] <player>\n\n" +
"The snoop command will let you overhear everything heard by the player\n"+
"specified in the argument. All messages received by that player get\n"+
"a % prepended and are echoed to the snooper.\n"+
"It is generally considered impolite to snoop players without their\n"+
"knowledge and consent. The principal two reasons to snoop a player are\n"+
"to let them demonstrate a bug, or verify that another player is harassing\n"+
"them. Other uses of the snoop command are frowned upon. Check with your\n"+
"administrators to see what their policy on snooping is.\n"+
"You can only snoop people who set themselves to be snoopable, unless you\n"+
"are an administrator. If the -n flag is used, the snoopee will notified\n" +
"that you are starting/stopping snooping them. This option is present for\n" +
"those, as a courtesy, wish to notify the snoopee.\n" +
"\nSee also: snoopable.\n") ;
	return 1 ;
}
