//      /cmds/mortal/_suicide
//      -- seeker
//      crack for guilds  --  Whit
//      Logging added -- Nesoo
#include <std.h>
#include <security.h>
#include <bank.h>
#include <dirs.h>
#include <flags.h>
#include <daemons.h>
inherit DAEMON;
object ob;
string admins;
string *member, *council, *leader, *squire;

void sure_to_suicide(string pa)
{
    // mixed er;
    string pass, str;
    object ob;
    if(((pass = (string)this_player()->query_password()) != oldcrypt(pa, pass))
      &&
      ((string)this_player()->query_password() != crypt(pa, pass)))
    {
	message("info", "Suicide failed.", this_player());
	return 0;
    }
    ob = this_player();
    str = (string)ob->query_name();
    if (!str) return;
    message("info", "You terminate your existance on Primal Darkness.",ob);
    CHAT_D->do_raw_chat("system", "Suicide <system> "+this_player()->query_name()+" suicided.");

    seteuid(UID_LOG);
    log_file("suicide", "[ " + ctime(time()) + " ] " + capitalize(str)
        + " suicided from IP: " + ob->query_ip() + "\n");
    seteuid(getuid());

    seteuid(UID_USERSAVE);
    rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o",DIR_USERS+"/rid/"+str+".o");
    seteuid(geteuid());
    IDENTITY_D->manage_identity(0, this_player(), "deleting");
    MSQL_D->msql_delete_player("pd", "player_t", (string)ob->query_name());
    BANK_D->remove_all_bank_accounts((string)ob->query_name());
    if(file_exists("/adm/save/boats/"+(string)ob->query_name()+".o"))
        rm("/adm/save/boats/"+(string)ob->query_name()+".o");
    ob->remove();
    if (ob) destruct(ob);
    return;
}
int cmd_suicide(string str) {
    object ob;
    ob = this_player();
    message("info", "Acck eek!! This removes your existance from "
      "Primal Darkness, are you sure you want that? If so, "
      "enter your password", this_player());
    message("no_wrap", "Password: ", this_player());
    input_to("sure_to_suicide", I_NOECHO | I_NOESC);
    return 1;
}
void help() {
    write( @EndText
Syntax: suicide
Effect: Removes your character from our reality.
EndText
    );
}

