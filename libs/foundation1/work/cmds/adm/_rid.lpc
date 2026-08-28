//	/bin/adm/_rid.c
//	from the Nightmare mudlib
//	the administrators command to get rid of players
//	created by Descartes of Borg 01 March 1993
                     
#include <std.h>
//#include <bank.h>
#include <dirs.h>

inherit DAEMON;

string admins;

int cmd_rid(string str) {
    object ob;

    if(!adminp(previous_object())) return 0;
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
    if(ob) ob->remove();
    if(ob) destruct(ob);
    rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o", DIR_USERS+"/rid/"+str+".o");
#ifdef ACCOUNTS_DIR
    if(file_size(ACCOUNTS_DIR+str+".o") > -1) rm(ACCOUNTS_DIR+str+".o");
#endif
    write(capitalize(str)+" is removed from "+mud_name()+".\n");
    log_file("rid", (string)this_player()->query_name()+" rid "+
	str+": "+ctime(time())+"\n");
    return 1;
}

void help() {
    message("help", "Syntax: <rid [player]>\n\n"
      "Removes the player from the game for good.", this_player());
}


