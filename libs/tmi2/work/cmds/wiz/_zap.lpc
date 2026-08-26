 
//	File	:  /cmds/xtra/_zap.c
//	Creator	:  Watcher@TMI  (03/27/93)
//
//	This is the wizard zap command which kills the intended target.

#include <mudlib.h>
#include <logs.h>

inherit DAEMON;
 
#define SYNTAX	"Syntax: zap [target]\n"
#define GUEST_NO_ZAP 1
 
int cmd_zap(string str) {
   object target, targetenv;
 
   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;

#ifdef GUEST_NO_ZAP
   if (getuid(this_player())=="guest") {
	notify_fail ("Guest is not permitted to zap.\n") ;
	return 0 ;
   }
#endif
 
   str = lower_case(str);

   targetenv = environment(this_player());
   if (!targetenv) {
       write("A flash of lightning is consumed in the dark void.\n");
       return 1;
   } 
   target = present(str, targetenv);
 
   if(!target) {
   write("Zap: There is no such living object here.\n");
   return 1; }
 
   if(!living(target)) {
   write("Zap: That object is not alive.\n");
   return 1; }
 
   if(target->link_data("dead") || target->query_dead() || 
      target->query("dead")) {
   write("Zap: That object is already dead.\n");
   return 1; }
 
   if(wizardp(target) && target->query("immortal")) {
   write("Zap: That wizard is immortal, and cannot be killed.\n");
   return 1; }

// Mobydick thinks this'll be really funny.

   if (interactive(target) && adminp(getuid(this_player()))==0)
	target = this_player() ;
 
   tell_room(environment(this_player()),
	(string)this_player()->query("cap_name") + " summons a flash " +
	"of lightning from the heavens, and " +
	(string)target->query("cap_name") + " is\nstruck down dead by its " +
	"destructive power.\n", ({ this_player(), target }));
 
   if(target != this_player())
   tell_object(target,
	(string)this_player()->query("cap_name") + " summons a flash " +
	"of lightning from the heavens. It strikes\nyou in the chest " +
	"and everything suddenly goes dark.\n");

   if(target != this_player())
   write("You zap " + (string)target->query("cap_name") + ".\n");
   else write("You zap yourself.\n");
 
   target->receive_damage( 1000 );	// Overkill  <grin>

#ifdef ZAP_LOG
   if(interactive(target))
   log_file(ZAP_LOG, (string)this_player()->query("cap_name") + 
	" zapped " + (string)target->query("cap_name") + " [" +
	extract(ctime(time()), 4, 15) + "]\n");
#endif
 
return 1; }
 
int help() {

   write( SYNTAX + "\n" +
    "This command allows a wizard to strike dead any living mortal object.\n" +
    "If a wizard has their \"immortal\" property set, they cannot be " +
    "killed.\nZapping players or other wizards without their permission"+
   " is a\nviolation of the rules, and may get your character dewizzed or "+
    "nuked, or\nyour site banned.\n") ;

return 1; }

