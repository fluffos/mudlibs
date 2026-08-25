/*    /cmds/mortal/_passwd.c
 *    from Nightmare IV
 *    command for password changing
 *    created by Descartes of Borg 940304
 */

#include <std.h>
#include <daemons.h>
#include <privs.h>
#include <flags.h>

inherit DAEMON;

int cmd_passwd(string str) {
    string nom, what;

    if(previous_object() != this_player(1) || !userp(previous_object()))
      return 0;
    if((int)previous_object()->query_forced()) return 0;
    if((nom = (string)previous_object()->query_name()) == "guest")
      return notify_fail("Guest has no such ability.");
    if(str && str != "") {
        if(sscanf(str, "%s %s", str, what) != 2) return 0;
        if(!user_exists(str)) return notify_fail("No such user.\n");
        if(!member_group(nom, "SECURE")) return 0;
        if(member_group(lower_case(str), "SECURE")) return 0;
        USERS_D->change_password(str, what);
        message("system", "Password changed.", this_player());
        return 1;
    }
    message("system", sprintf("Changing %s password on %s.",
      possessive_noun(capitalize(nom)), mud_name()), previous_object());
    message("prompt", "Old password: ", this_player());
    input_to("check_password", I_NOECHO | I_NOESC);
    return 1;
}

nomask  private  void check_password(string pass) {
    string password;

    if(!pass) {
        message("system", "Password change failed.", this_player());
        return;
    }
    password = (string) this_player()->query_password();
    if(password != crypt(pass, password)) {
        message("system", "Password change failed.", this_player());
        return;
    }
    message("prompt", "\nNew password: ", this_player());
    input_to("new_password", I_NOECHO | I_NOESC);
}

nomask  private  void new_password(string pass) {
    if(strlen(pass) < 5) {
        message("system", "\nPasswords must contain at least 5 characters.",
          this_player());
        return;
    }
    message("prompt", "\nConfirm password: ", this_player());
    input_to("confirm_password", I_NOECHO | I_NOESC, pass);
}

nomask  private  void confirm_password(string pass2, string pass1) {
    if(pass1 != pass2) {
        message("system", "\nPasswords do not match.", this_player());
        return;
    }
    if(this_player(1) != this_player()) {
        message("system", "\nThis is a bad thing.", this_player());
        return;
    }
    this_player()->set_password(crypt(pass2, 0));
    message("system", "\nPassword changed.", this_player());
}

void help() {
    message("help", "Syntax: <passwd>\n\n"
      "Command for changing your password.  You should do this every few "
      "months, or if you suspect someone else may have learned your "
      "password.  You are responsible for anything that happens with your "
      "character, so it is in your best interest to make sure others cannot "
      "access it.  Passwords must be at least 5 characters in length. "
      "It is recommended that your password contain a mix of numbers and "
      "both upper case and lower case letters.", this_player());
    if(member_group(this_player(), PRIV_SECURE))
      message("help", "\n\nSuperuser help for passwd command.\n"
        "In addition to changing your own password, the following "
        "syntax may be used to change the password of others:\n"
        "<passwd [user] [newpassword]>\n", this_player());
}
