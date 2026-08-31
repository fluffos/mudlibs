#include <std.h>
#include <security.h>
#include <bank.h>
#include <daemons.h>
#include <dirs.h>
inherit DAEMON;
string admins;
int cmd_unarrest(string str) {
    object ob;
  if(!wizardp(previous_object())) return 0;
    if(!member_group(geteuid(previous_object()), "law")) return 0;
    if(!str || str == "") {
        notify_fail("Syntax: <unarrest [player]>\n");
        return 0;
    }
    str=lower_case(str);
    seteuid(UID_USERSAVE);
    if(!file_exists(DIR_USERS+"/arrest/"+str+".o")) {
        notify_fail("No such player is arrested.  "+str+":"+DIR_USERS+"/arrest/"+str+".o\n");
        return 0;
    }
    rename(DIR_USERS+"/arrest/"+str+".o", DIR_USERS+"/"+str[0..0]+"/"+str+".o");
    if(file_size(ACCOUNTS_DIR+str+".o") > -1) rm(ACCOUNTS_DIR+str+".o");
    write(capitalize(str)+" is unarrested from "+mud_name()+".\n");
    seteuid(UID_BANISH);
    BANISH_D->set_illegal_substring(str);
    seteuid(UID_LOG);
    MSQL_D->msql_delete("pd", "arrest", "name=\""+str+"\"");
    seteuid(getuid());
    return 1;
}
void help() {
    message("help", "Syntax: <unarrest [player]>\n\n"
      "This will unarrest a player and update the MySQL database.\n\n"
      "See also: rid", this_player()
    );
}
