//	/adm/simul_efun/overrides.c
//	from the Nightmare mudlib
//	efun overriding code
//	created by someone for Basis

#include <security.h>
#include <objects.h>
#include <commands.h>

void destruct(object destructee) {
    string destee, dester;

    destee = geteuid(destructee);
    dester = geteuid(previous_object());
    if(!destee || dester==destee || dester==UID_ROOT || dester==UID_DESTRUCT ||
      master()->query_member_group(dester, "superuser") ||
      master()->query_member_group(dester, "assist") ||
      master()->query_member_group(dester, "creator") )
        efun::destruct(destructee);
    else if(owner_euid(destee) == dester)
      efun::destruct(destructee);
    else write(capitalize(dester)+" is not allowed to destruct "+
	capitalize(destee)+"\n");
}

varargs void shutdown(int code) {
    if(geteuid(previous_object()) != UID_ROOT &&
      geteuid(previous_object()) != UID_SHUTDOWN) return;
    log_file("shutdowns", "Game shutdown by "+
	(this_player() ? capitalize(geteuid(this_player())) : "Root")+
	" at "+ctime(time())+"\n");
    seteuid(UID_SHUTDOWN);
    catch(call_other("/daemon/nameserver_d", "send_shutdown"));
    seteuid(getuid());
    efun::shutdown(code);
}

varargs object snoop(object snooper, object snoopee) {
    if(!snoopee) return efun::snoop(snooper);
    if(!wizardp(snooper)) return 0;
    if((int)master()->query_member_group(geteuid(snooper), "superuser") || 
	(int)master()->query_member_group(geteuid(snooper), "assist") ||
	snoopee->query_snoop()) {
	    if((int)master()->query_member_group(geteuid(snoopee), "superuser"))
		tell_object(snoopee, capitalize((string)snooper->query_name())+
		  " is now snooping you.\n");
	    return efun::snoop(snooper, snoopee);
    }
    return 0;
}

int exec(object to_obj, object from_obj) {
    string prev;

    prev = base_name(previous_object());
    if(prev == OB_LOGIN ) return efun::exec(to_obj, from_obj);
    return 0;
}

object query_snoop(object snoopee) {
    if(geteuid(previous_object()) != UID_SNOOP &&
      base_name(previous_object()) != OB_USER) return 0;
    return efun::query_snoop(snoopee);
}

object query_snooping(object ob) {
    if(geteuid(previous_object()) != UID_ROOT) return 0;
    return efun::query_snooping(ob);
}

void print(string str) {
   efun::write(str);
}
void write(string str) {
    if(this_player()) message("info", str, this_player());
    else efun::write(str);
}

string pluralize(string str) { return "/adm/simul_efun/pluralize"->pluralize(str); }

varargs void ed(string file, string exit_fn, int res) {
   if(!master()->valid_write(file, this_player())) {
     write("Write access denied.");
     seteuid(UID_LOG);
     write_file("/log/adm/hack", this_player()->query_name()+" tried to write to a restricted file using direct call. (File: "+file+")");
     seteuid(getuid());
     return;
   }
   if(file && exit_fn && !res)
     efun::ed(file, exit_fn); else
   if(file && exit_fn && res)
     efun::ed(file, exit_fn, res); else
   if(file && !exit_fn && !res) 
     efun::ed(file);
}

object *users() {
   return filter_array(efun::users(), "remove_logins");
}

int remove_logins(object o) {
   if(base_name(o) == "/adm/obj/login") return 0;
   return 1;
}

int notify_fail(string str) {
  if (str[<1..<1] != "\n")
    str += "\n";
  return efun::notify_fail(str);
}
