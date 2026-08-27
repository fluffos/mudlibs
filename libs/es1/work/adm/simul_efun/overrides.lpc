// file:   /adm/obj/simul_efun/overrides.c
// mudlib: originally written for Basis, adapted by TMI-2
// Pallando (93-02-22) Allowed LOGIN_D to use exec.
// Buddha (93-04-21) made functions secure to protect against inheritance
// Watcher (93-06-28) made the mudlib snoop command the only allowed
// snoop originator.
// Buddha (93-07-30) Added entries for query_snoop() and query_snooping()

#include <config.h>
#include <commands.h>
#include <daemons.h>
#include <login.h>
#include <uid.h>

int
destruct(object destructee)
{
   string destee, dester;
   if (file_name(this_object()) != SIMUL_EFUN_OB) return 0;
	if (destructee && !nullp(destructee))
		return efun::destruct(destructee);
	return 0;
#if 0
   destee = geteuid(destructee);
   dester = geteuid(previous_object());
   /* let's see if we have the power... */
      if (!destee || dester == destee || dester == ROOT_UID || 
         member_group(dester, "admin"))
   return efun::destruct(destructee);
   /* if not, hopefully this message will go to the right place */
      else {
      write(capitalize(dester) + " is not allowed to destruct " +
         capitalize(destee) + "\n");
      return 0;
	 }
#endif

}

nomask varargs void
shutdown(int code)
{
   object prev;
   
   seteuid(getuid(this_object()));
   prev = previous_object();
   if (geteuid(prev) != ROOT_UID) {
      return;
   }
   log_file("SHUTDOWN", "Game shut down by " +
      (this_player() ? capitalize(geteuid(this_player())) : "Root") +
      " at " + ctime(time()) + "\n");
   efun::shutdown(code);
}

nomask varargs object snoop(object snooper, object snoopee) {
   
   if (file_name(this_object()) != SIMUL_EFUN_OB) return 0;
   if (file_name(previous_object()) != CMD_SNOOP) return 0;
   if (!snoopee) return efun::snoop(snooper);
   if (!wizardp(snooper))
      return 0;
   if (member_group(geteuid(snooper), "admin") ||
         snoopee->query("snoopable")) {
      //   Don't need this notification now that the snoop command does it.
#ifdef 0
         if (member_group(geteuid(snoopee), "admin"))
         tell_object(snoopee, "Game driver tells you: " +
         (string)snooper->query("cap_name") +
         " starts snooping you!\n");
#endif
         return efun::snoop(snooper, snoopee);
   }
   return 0;
}

nomask int exec(object to_obj, object from_obj) {
   string prev;
   
   if (file_name(this_object()) != SIMUL_EFUN_OB) return 0;
   prev = base_name(previous_object());
   if (prev == CONNECTION || prev == CMD_SU || prev == LOGIN_D) {
      return efun::exec(to_obj, from_obj);
   }
   return 0;
}

nomask int export_uid(object ob) {
   if (ob == master()) return 0;
   seteuid(geteuid(previous_object()));
   return efun::export_uid(ob);
}

nomask object query_snoop(object who) {
   string prev;
   prev = geteuid(previous_object());
   if (prev != ROOT_UID && !member_group(prev, "admin"))
      return 0;
   else return efun::query_snoop(who);
}

nomask object query_snooping(object who) {
   string prev;
   prev = geteuid(previous_object());
   if (prev != ROOT_UID && !member_group(prev, "admin"))
      return 0;
   else return efun::query_snooping(who);
}


