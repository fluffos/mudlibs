//	/bin/adm/_rid.c
//	from the Nightmare mudlib
//	the administrators command to get rid of players
//	created by Descartes of Borg 01 March 1993
                     
#include <std.h>
#include <security.h>
#include <bank.h>
#include <daemons.h>
#include <dirs.h>

inherit DAEMON;

string admins;

int cmd_rid(string str) {
    object ob;
    string name;

    if(!archp(previous_object()) && previous_object() != find_object("/daemon/authenticate")) return 0; 
    if(!str) {
	notify_fail("Syntax: <rid [player]>\n");
	return 0;
    }
    str = lower_case(str);                                         
    if(member_group(str, "superuser")) {
        notify_fail("Shyeah...NOT.\n");
        return 0;
    }
    ob = find_player(str);
    if(!ob && !user_exists(str)) {
	notify_fail("No such player: "+capitalize(str)+".\n");
	return 0;
    }
    BANK_D->remove_all_bank_accounts(str);
    if(ob) ob->remove();
    if(ob) {
        seteuid(UID_DESTRUCT);
        destruct(ob);
        seteuid(getuid());
    }
    IDENTITY_D->manage_identity(0, ob, "deleting");
    MSQL_D->msql_delete_player("pd", "player_t", str);
    AUTH_D->remove_user(str);
    seteuid(UID_USERSAVE);
    rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o", DIR_USERS+"/rid/"+str+".o");
    if(file_size(ACCOUNTS_DIR+str+".o") > -1) rm(ACCOUNTS_DIR+str+".o");
    if(file_exists("/adm/save/boats/"+(string)str+".o"))
        rm("/adm/save/boats/"+(string)str+".o");
    write(capitalize(str)+" is removed from "+mud_name()+".\n");
    seteuid(UID_LOG);
    if(previous_object() == find_object("/daemon/authenticate")) name="Authentcation";
      else name = this_player()->query_name();
    log_file("rid", (string)name+" rid "+
	str+": "+ctime(time())+"\n");
    seteuid(getuid());
    return 1;
}

void help() {
  write( @EndText
Syntax: rid <name>
Effect: Deletes, nukes, wipes out and annhilates unwanted player <name>
See also: demote, promote, sponsor
EndText
  );
}
