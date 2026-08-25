/*    /adm/obj/login.c
 *    from Nightmare IV
 *    the login object, connecting players to their objects
 *    created by Descartes of Borg 940115
 */

#include <config.h>
#include <news.h>
#include <flags.h>
#include <security.h>
#include <daemons.h>
#include <objects.h>

nosave private int __CrackCount, __CopyExists;
nosave private string __Name, __CapName, __Client;
nosave private object __Player;

protected void logon();
protected void get_name(string str);
string query_name();
protected void get_password(string str);
protected int locked_access();
protected int check_password(string str);
protected int valid_site(string ip);
protected int boot_copy();
protected void disconnect_copy(string str);
protected void exec_user();
protected void new_user(string str);
protected void choose_password(string str);
protected void confirm_password(string str2, string str1);
protected int register_client();
protected void continue_login();
protected void choose_gender(string str);
protected void enter_email(string str);
protected void enter_real_name(string str);
protected void idle();
protected void receive_message(string cl, string msg);
protected void internal_remove();
void remove();

void create() {
    __Name = "";
    __Client = 0;
    __CrackCount = 0;
    __Player = 0;
  }

protected void logon() {
    call_out("idle", LOGON_TIMEOUT);
    receive(read_file(WELCOME));
    receive("\n"+center("Driver: "+version()+"    Mudlib: "+mudlib()+" "+
      mudlib_version()+"    AMCP 1.1 compliant"));
    receive("\nWhat name do you wish? ");
    input_to("get_name");
}

protected void get_name(string str) {
    if(!str || str == "") {
        receive("\nInvalid entry.  Please try again.\n");
        internal_remove();
        return;
      }
    if(sscanf(str, "%s:%s", __CapName, __Client) != 2) {
        __Client = 0;
        __Name = convert_name(__CapName = str);
    }
    else {
        __Name = convert_name(__CapName);
        receive("\n");
        if(find_player(__Name)) __CopyExists = 1;
        else __CopyExists = 0;
        if(!register_client()) return;
    }
    if(find_player(__Name)) __CopyExists = 1;
    else __CopyExists = 0;
    continue_login();
}

protected void continue_login() {
    if((int)master()->is_locked()) {
        message("news", read_file(LOCKED_NEWS), this_object());
        if(locked_access())
          message("system", "\n    >>> Access allowed <<<\n", this_object());
        else {
            message("system", "\n    >>> Access denied <<<\n", this_object());
            internal_remove();
            return;
	  }
      }
    if(!user_exists(__Name)) {
        if(!((int)BANISH_D->valid_name(__Name))) {
            message("system", sprintf("\n%s is not a valid name choice for %s.\n",
              capitalize(__Name), mud_name()), this_object());
            message("system", sprintf("Names must be alphabetic characters no "
	      "longer than %d letters,\nand no less than %d letters.\n",
              MAX_USER_NAME_LENGTH, MIN_USER_NAME_LENGTH), this_object());
            message("prompt", "\nPlease enter another name: ", this_object());
            input_to("get_name");
            return;
	  }
        if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) {
            message("news", read_file(REGISTRATION_NEWS), this_object());
            internal_remove();
            return;
	  }
        message("prompt", sprintf("Do you really wish %s to be your name? (y/n) ",
          __CapName), this_object());
        __Player = (object)master()->player_object(__Name);
        input_to("new_user");
        return;
      }
    if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) {
        message("news", read_file(BANISHED_NEWS), this_object());
        internal_remove();
        return;
      }
    __Player = (object)master()->player_object(__Name);
    message("password", "Password: ", this_object());
    if(__Client) input_to("get_password");
    else input_to("get_password", I_NOECHO | I_NOESC);
  }

protected void get_password(string str) {
    if(!str || str == "") {
        message("system", "\nYou must enter a password.  Try again later.\n",
          this_object());
        internal_remove();
        return;
      }
    if(!check_password(str)) {
        message("system", "\nInvalid password.\n", this_object());
        if(++__CrackCount > MAX_PASSWORD_TRIES) {
            message("system", "No more attempts allowed.\n", this_object());
            internal_remove();
            return;
	  }
        log_file("watch/logon", sprintf("%s from %s\n", __Name, query_ip_number()));
        message("password", "Password: ", this_object());
        if(__Client) input_to("get_password");
        else input_to("get_password", I_NOECHO | I_NOESC);
        return;
      }
    if(!__CopyExists) exec_user();
    else boot_copy();
  }

protected int locked_access() {
    int i;

    if((int)BANISH_D->is_guest(__Name)) return 1;
    i = sizeof(LOCKED_ACCESS_ALLOWED);
    while(i--) if(member_group(__Name, LOCKED_ACCESS_ALLOWED[i])) return 1;
    return 0;
  }

protected int check_password(string str) {
    string pass;

    if((pass = (string)__Player->query_password()) != crypt(str, pass)) return 0;
    return valid_site(query_ip_number());
  }

protected int valid_site(string ip) {
    string a, b;
    string *miens;
    int i;

    if(!(i = sizeof(miens = (string *)__Player->query_valid_sites()))) return 1;
    while(i--) {
        if(ip == miens[i]) return 1;
        if(sscanf(miens[i], "%s.*s", a) && sscanf(ip, a+"%s", b)) return 1;
      }
    return 0;
  }

protected int boot_copy() {
    if(interactive(__Player)) {
        message("system", "\nThere currently exists an interactive copy of you.\n",
          this_object());
        message("prompt", "Do you wish to take over this interactive copy? (y/n) ",
          this_object());
        input_to("disconnect_copy", I_NORMAL);
        return 1;
      }
    log_file("enter", sprintf("%s (exec): %s\n", __Name, ctime(time())));
    if(exec(__Player, this_object())) __Player->restart_heart();
    else message("system", "Problem reconnecting.\n", this_object());
    internal_remove();
    return 1;
  }

protected void disconnect_copy(string str) {
    object tmp;

    if((str = lower_case(str)) == "" || str[0] != 'y') {
        message("system", "\nThen please try again later!\n", this_object());
        internal_remove();
        return;
      }
    message("system", "You are being taken over by hostile aliens!", __Player);
    exec(tmp = new(OB_USER), __Player);
    exec(__Player, this_object());
    __Player->set_client(__Client);
    destruct(tmp);
    message("system", "\nAllowing login.\n", __Player);
    internal_remove();
  }

protected void exec_user() {
    if(MULTI_D->query_prevent_login(__Name)) {
        internal_remove();
        return;
      }
    if(!exec(__Player, this_object())) {
        message("system", "\Problem connecting.\n", this_object());
        __Player->remove();
        destruct(this_object());
        return;
      }
    __Player->set_client(__Client);
    catch(__Player->setup());
    destruct(this_object());
  }

protected void new_user(string str) {
    if((str = lower_case(str)) == "" || str[0] != 'y') {
        message("prompt", "\nOk, then enter the name you really want: ", this_object());
        __Player->remove();
        input_to("get_name");
        return;
      }
    log_file("new_players", sprintf("%s : %s : %s\n", query_ip_number(), __Name,
      ctime(time())));
    message("password", "Please choose a password of at least 5 letters: ",
      this_object());
    if(__Client) input_to("choose_password");
    else input_to("choose_password", I_NOECHO | I_NOESC);
  }

protected void choose_password(string str) {
    if(strlen(str) < 5) {
        message("system", "\nYour password must be at least 5 letters long.\n",
          this_object());
        message("password", "Please choose another password: ", this_object());
        if(__Client) input_to("choose_password");
        else input_to("choose_password", I_NOECHO | I_NOESC);
      }
    message("password", "\nPlease confirm your password choice: ", this_object());
    if(__Client) input_to("confirm_password", str);
    else input_to("confirm_password", I_NOECHO | I_NOESC, str);
  }

protected void confirm_password(string str2, string str1) {
    if(str1 == str2) {
        __Player->set_password(str2 = crypt(str2, 0));
        message("prompt", "\nPlease choose an interesting gender (male or female): ",
          this_object());
        input_to("choose_gender");
        return;
      }
    else {
        message("password", "\nPassword entries do not match.  Choose a password: ",
          this_object());
        if(__Client) input_to("choose_password");
        else input_to("choose_password", I_NOECHO | I_NOESC);
        return;
      }
  }

protected void choose_gender(string str) {
    if(str != "male" && str != "female") {
        message("system", "\nCute, but pretend to be either male or female instead\n",
          this_object());
        message("prompt", "Gender: ", this_object());
        input_to("choose_gender");
        return;
      }
    __Player->set_gender(str);
    message("system", sprintf("You may format %s to appear however you want "
      "using alternative\ncapitalization, spaces, \"'\", or \"-\".\n", __CapName),
        this_object());
    message("prompt", sprintf("Please choose a display name (default: %s): ", __CapName), this_object());
    input_to("choose_cap_name");
}

protected void choose_cap_name(string str) {
    if(!str || str == "") str = capitalize(__CapName);
    if(!((int)BANISH_D->valid_cap_name(str, __Name))) {
        message("prompt", "Incorrect format.  Choose again: ", this_object());
        input_to("choose_cap_name");
        return;
    }
    __Player->set_cap_name(capitalize(str));
    message("system", sprintf("\nFor security reasons only, %s requires you to enter "
      "a valid email address\nin the form of user@host.  Only admins will have "
      "access to this information.\n", mud_name()), this_object());
    message("prompt", "Email: ", this_object());
    input_to("enter_email");
  }

protected void enter_email(string str) {
    string a, b;

    if(!str || str == "" || sscanf(str, "%s@%s", a, b) != 2) {
        message("system", "\nEmail must be in the form user@host.\n",
          this_object());
        message("prompt", "Email: ", this_object());
        input_to("enter_email");
        return;
      }
    __Player->set_email(str);
    message("prompt", "\nIf you do not mind, enter your real name (optional): ",
      this_object());
    input_to("enter_real_name");
  }

protected void enter_real_name(string str) {
    if(!str || str == "") str = "Unknown";
    __Player->set_rname(str);
    log_file("enter", sprintf("%s (new player): %s\n", __Name, ctime(time())));
    exec_user();
  }

protected void idle() {
    receive("\nLogin timed out.\n");
    internal_remove();
  }

void receive_message(string cl, string msg) {
    if(__Client) receive("<"+cl+">"+msg+"\n");
    else receive(msg);
  }

protected void internal_remove() {
    if(__Player && !__CopyExists) destruct(__Player);
    destruct(this_object());
}

void remove() {
    internal_remove();
}

protected int register_client() {
    string client, ver;

    if(sscanf(__Client, "%s/%s", client, ver) != 2) ver = 0;
    if(member_array(__Client, SUPPORTED_CLIENTS) == -1) {
        receive("<protocol>"+implode(SUPPORTED_CLIENTS, ",")+"\n");
        input_to("input_protocol");
        return 0;
    }
    receive("<connect>\n");
    return 1;
}

protected void input_protocol(string str) {
    string str_class, client;

    if(sscanf(str, "<%s>%s", str_class, client) != 2  || str_class != "protocol" ||
      member_array(client, SUPPORTED_CLIENTS) == -1 || client == "none")
        __Client = 0;
    else __Client = client;
    if(__Client) receive("<connect>\n");
    continue_login();
}

string query_name() {
    if(!interactive(this_object())) return 0;
    else if(__Name) return __Name;
    else return "";
}

string query_CapName() {
    string tmp;

    tmp = query_name();
    return (tmp ? capitalize(tmp) : "");
}
