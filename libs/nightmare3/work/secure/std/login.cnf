#include <flags.h>
#include <daemons.h>
#include <objects.h>
#include <cfg.h>

object __Admin;
string __Name, __CapName, __Password;

protected void logon() {
    receive("Welcome to the "+mudlib()+" "+mudlib_version()+" installation "
      "process.\n");
    receive("You will be asked a series of questions aimed at customizing "
      "your MUD.\n");
    receive("These questions are designed for the mudlib only.  You should "
      "have already \nrun the installation script at the host level which "
      "comes with the mudlib.\n");
    receive("\nWhat is the name of one person with full superuser access? ");
    input_to("input_name");
}

protected void input_name(string str) {
    if(!((int)BANISH_D->valid_name(__Name=convert_name(__CapName=str)))) {
        receive("That is not a valid name.  Enter another: ");
        input_to("input_name");
        return;
    }
    __Admin = (object)master()->player_object(__Name);
    __Admin->set_name(__Name);
    __Admin->set_position("head arch");
    mkdir(DIR_USERS+"/"+__Name[0..0]);
    receive("\nPassword: ");
    input_to("input_password", I_NOECHO | I_NOESC);
}

protected void input_password(string str) {
    if(strlen(str) < 5) {
        receive("An admin password of less than 5 letters?  Get real!\n");
        receive("Password: ");
        input_to("input_password", I_NOECHO | I_NOESC);
        return;
    }
    __Password = str;
    receive("\nConfirm password: ");
    input_to("confirm_password", I_NOECHO | I_NOESC);
}

protected void confirm_password(string str) {
    if(str != __Password) {
        receive("\nPasswords do not match.  Password: ");
        input_to("input_password", I_NOECHO | I_NOESC);
        return;
    }
    __Admin->set_password(crypt(__Password, 0));
    __CapName = capitalize(__CapName);
    receive("\nEnter in your capitalized name ("+__CapName+" is default): ");
    input_to("input_cap_name");
}

protected void input_cap_name(string str) {
    if(str == "" || !str) str = __CapName;
    else if(convert_name(str = capitalize(str)) != __Name) {
        receive("\nYou can't do that! Capitalized name: ");
        input_to("input_cap_name");
        return;
    }
    __Admin->set_cap_name(__CapName);
    receive("\nWhat is your gender? ");
    input_to("input_gender");
}

protected void input_gender(string str) {
    __Admin->set_gender(str);
    receive("\nWhat is "+possessive_noun(__CapName)+" real name? ");
    input_to("input_rname");
}

protected void input_rname(string str) {
    if(str == "" || !str) str = "Unknown";
    __Admin->set_rname(str);
    receive("\nWhat is the email address? ");
    input_to("input_email");
}

protected void input_email(string str) {
    object ob;
    string tmp;

    if(str == "" || !str) str = "Unknown";
    __Admin->set_email(str);
    __Admin->save_player(__Name);
    tmp = read_file(CFG_GROUPS);
    rm(CFG_GROUPS);
    mkdir(REALMS_DIRS+"/"+__Name);
    cp(DIR_STANDARD_DOMAIN+"/xtra/workroom.c", REALMS_DIRS+"/"+__Name+
      "/workroom.c");
    tmp = replace_string(tmp, "ADMIN", __Name);
    write_file(CFG_GROUPS, tmp);
    destruct(master());
    if(ob = find_object(OB_LOGIN)) destruct(ob);
    rename("/secure/std/login.real", "/secure/std/login.c");
    destruct(__Admin);
    receive("You will be disconnected.  Login as your admin character.\n");
    destruct(master());
    destruct(this_object());
}

string query_name() { return __Name; }
