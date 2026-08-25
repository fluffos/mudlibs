/*    /cmds/mortal/_suicide.c
 *    from Nightmare IV
 *    a command to end it all for good
 *    created by Descartes of Borg 940303
 */

#include <std.h>
#include <flags.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_suicide(string unused) {
    string name;

    if(this_player(1) != previous_object() || !userp(previous_object())) {
        log_file("illegal", "suicide: "+ctime(time())+" "+(string)previous_object()->query_name()+"\n");
        notify_fail("Ok.\n");
        return 0;
    }
    if(this_player()->query_forced()) {
        log_file("illegal", "suicide: (forced): "+ctime(time())+" "+this_player()->query_name()+"\n");
        notify_fail("You must act of your own free will.\n");
        return 0;
    }
    if((name = (string)previous_object()->query_name()) == "guest")
      return notify_fail("Guest is not suicidal.\n");
    message("system", "Committing suicide means having your character "
      "completely erased from "+mud_name()+"'s database.  If you are certain "
      "this is what you want, enter in your correct password.  Otherwise "
      "enter in a wrong password.", this_player());
    message("prompt", "Password: ", this_player());
    input_to("check_password", I_NOECHO | I_NOESC);
    return 1;
}

nomask  private  void check_password(string pass) {
    string password;

    if(!pass) {
        message("system", "Suicide failed.", this_player());
        return;
    }
    password = (string) this_player()->query_password();
    if(password != crypt(pass, password)) {
        message("system", "Suicide failed.", this_player());
        return;
    }
    message("system", "Try again with another character sometime then!",
      this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      "ends "+possessive(this_player())+" miserable existence on "+mud_name()+".",
      this_player());
    USERS_D->suicide((string)this_player()->query_name());
}

void help() {
    message("help", "Syntax: <suicide>\n"
      "Ends your character's existence on "+mud_name()+" FOREVER.  "
      "It is non-reversible.  Once you issue this command, tyou will be asked "
      "for a password to confirm your identity.  Once password is confirmed, "
      "you will no longer exist in the MUD's database. "
"NOTE: If you suicide from a restricted site, you will have to reregister!",this_player());
}
