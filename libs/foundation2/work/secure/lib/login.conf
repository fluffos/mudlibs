#include <flags.h>
#include <daemons.h>
#include <objects.h>
#include <cfg.h>

object Admin;
string Name, CapName, Password;

static void logon() {
    receive("Welcome to the "+mudlib()+" "+mudlib_version()+" installation "
	    "process.\n");
    receive("You will be asked a series of questions aimed at customizing "
	    "your MUD.\n");
    receive("These questions are designed for the mudlib only.  You should "
	    "have already \nrun the installation script at the host level "
	    "which comes with the mudlib.\n");
    receive("\nWhat is the name of one person with full superuser access "
	    "(your MUD name)?\nName:  ");
	input_to("input_name");	
}

static void input_name(string str) {
    if(!((int)BANISH_D->valid_name(Name=convert_name(CapName=str)))) {
        receive("That is not a valid name.  Enter another: ");
        input_to("input_name");
        return;
    }
    Admin = (object)master()->player_object(Name);
    Admin->SetKeyName(Name);
    Admin->SetPosition("head arch");
    mkdir(DIR_PLAYERS+"/"+Name[0..0]);
    receive("\nPassword: ");
    input_to("input_password", I_NOECHO | I_NOESC);
}

static void input_password(string str) {
    if(strlen(str) < 5) {
        receive("An admin password of less than 5 letters?  Get real!\n");
        receive("Password: ");
        input_to("input_password", I_NOECHO | I_NOESC);
        return;
    }
    Password = str;
    receive("\nConfirm password: ");
    input_to("confirm_password", I_NOECHO | I_NOESC);
}

static void confirm_password(string str) {
    if(str != Password) {
        receive("\nPasswords do not match.  Password: ");
        input_to("input_password", I_NOECHO | I_NOESC);
        return;
    }
    Admin->SetPassword(crypt(Password, 0));
    CapName = capitalize(CapName);
    receive("\nEnter in your capitalized name ("+CapName+" is default): ");
    input_to("input_cap_name");
}

static void input_cap_name(string str) {
    if(str == "" || !str) str = CapName;
    else if(convert_name(str = capitalize(str)) != Name) {
        receive("\nYou can't do that! Capitalized name: ");
        input_to("input_cap_name");
        return;
    }
    Admin->SetCapName(CapName);
    receive("\nWhat is your gender? ");
    input_to("input_gender");
}

static void input_gender(string str) {
    Admin->SetGender(str);
    receive("\nWhat is "+possessive_noun(CapName)+" real name? ");
    input_to("input_rname");
}

static void input_rname(string str) {
    if(str == "" || !str) str = "Unknown";
    Admin->SetRealName(str);
    receive("\nWhat is the email address? ");
    input_to("input_email");
}

static void input_email(string str) {
    object ob;
    string tmp;

    if(str == "" || !str) str = "Unknown";
    Admin->SetEmail(str);
    Admin->save_player(Name);
    tmp = read_file(CFG_GROUPS);
    rm(CFG_GROUPS);
    mkdir(REALMS_DIRS+"/"+Name);
    cp(DIR_STANDARD_DOMAIN+"/xtra/workroom.c", REALMS_DIRS+"/"+Name+
      "/workroom.c");
    tmp = replace_string(tmp, "admin", Name);
    write_file(CFG_GROUPS, tmp);
    destruct(master());
    if(ob = find_object(OB_LOGIN)) destruct(ob);
    cp("/secure/lib/login.real", "/secure/lib/login.c");
    mkdir(DIR_CRES "/" + Name[0..0]);
#ifdef PLAYERS
    rename(DIR_PLAYERS "/" + Name[0..0] + "/" + Name + __SAVE_EXTENSION__,
      DIR_CRES "/" + Name[0..0] + "/" + Name + __SAVE_EXTENSION__);
#endif
    destruct(Admin);
    receive("You will be disconnected.  Login as your admin character.\n");
    destruct(master());
    destruct(this_object());
}

string GetKeyName() { return Name; }
