// Petrarch
// Merentha Lib 1.0
// login.c

#include <std.h>
#include <config.h>

void catch_tell(string str);
void logon();
void continue_logon();
void query_name();
void query_password();
int check_password();
void confirm_name();
void enter_password();
void confirm_password();
void name_format();

string __Name, __CapName, tmp;
object __User=0;

void remove() {
        destruct(this_object());
}

void catch_tell(string str) {
    receive(str);
}

void logon() {
    receive(wrap(read_file("/doc/news/welcome")+"%^RESET%^"));
    receive(center("Mudlib: "+mudlib()+"    Driver: "+driver(), 80));
    receive("\n");

    continue_logon();
}

void continue_logon() {
    receive("\nPlease enter a name to enter this world with: ");
    input_to("query_name");
}

void query_name(string name) {
    if (!name || name=="") remove();
    name=player_name(name);
    if (strlen(name)<3) {
        receive("\nYour name is too short.\nPlease enter a name of at least 3 characters in length.");
        continue_logon();
        return;
    }
    if (strlen(name)>12) {
        receive("\nYour name is too long.\nPlease enter a name of no longer then 12 characters in length.");
        continue_logon();
        return;
    }
    __Name=name;
    if (player_exists(name)) {
        receive("\nThe character of "+name+" exists in this world.");
        receive("\nPlease enter the password for "+name+": ");
        input_to("query_password", 1);
        return;
    }
    receive("\nWelcome to the world of "+mud_name()+".\nThis is a fantasy world filled with elves and dwarves and humans and
dragons.  This is also a role-playing world.  The name you choose is
imporant and should respect these guidelines.  You will be deleted if your
name is found unsuitable.  
Do you wish to keep the name "+name+"? (y/n): ");
    input_to("confirm_name");
}

int check_password(string passwd) {
    string err;
    if(!__User) {
        __User=new(USER);
        err=catch(__User->load_player(__Name));
        if(err) __User=0;
        if(!__User) return 0;
    }
    return (__User->query_password() == crypt(passwd, __User->query_password()));
}

void query_override(string val) {
   if(!val || member_array(val, ({"y","n"}))==-1) {
     receive("\nThe character "+__Name+" is already interactive.\nDo you wish to override the character? (y/n) : ");
     input_to("query_override");
     return;
   }
   if(val=="n") {
     destruct(this_object());
     return;
   }
   __User=find_player(player_name(__Name));
   if(__User) {
      log_file("login_passed", ""+ctime(time())+" - "+player_name(__Name)+" - override - "+query_ip_number(this_object())+"\n");
      message("system","\nYou are being overridden.\n\n", __User);
      remove_interactive(__User);
      receive("\n\n");
      exec(__User, this_object());
      __User->reconnect();
   }
   destruct(this_object());
}    

void query_password(string passwd) {
    if (!passwd || passwd=="") {
        receive("\n");
        continue_logon();
        return;
    }
    if (!check_password(passwd)) {
        log_file("login_failed", ""+ctime(time())+" - "+player_name(__Name)+" - "+query_ip_number(this_object())+"\n");
        receive("\nIncorrect Password.  Please try again.");    
        receive("\nPlease re-enter the password for "+__Name+": ");
        input_to("query_password", 1);
        return;
    }
    if(find_player(player_name(__Name))) {
        if(interactive(find_player(player_name(__Name)))) {
           receive("\nThe character "+__Name+" is already interactive.\nDo you wish to override the character? (y/n) : ");
           input_to("query_override");
           return;
        }
        __User=find_player(player_name(__Name));
        if(__User) {
            log_file("login_passed", ""+ctime(time())+" - "+player_name(__Name)+" - (ld)return - "+query_ip_number(this_object())+"\n");
            remove_interactive(__User);
            receive("\n\n");
            exec(__User, this_object());
            __User->reconnect();
            return;
        }
    }
    log_file("login_passed", ""+ctime(time())+" - "+player_name(__Name)+" - login - "+query_ip_number(this_object())+"\n");
    exec(__User, this_object());
    __User->setup();
    destruct(this_object());
}

void confirm_name(string confirm) {
    if(!confirm || member_array(lower_case(confirm), ({"y", "ya", "yes"}))==-1) {
      continue_logon();
      return;
    }
    receive("\nYou now must choose a password.\nPlease enter a password: ");
    input_to("enter_password", 1);
}

void enter_password(string passwd) {
    if(!passwd || passwd=="" || strlen(passwd)<4 || strlen(passwd)>8) {
        receive("\nYour password is invalid.\nA password needs to be between 4 and 8 chacters long.");
        receive("\nPlease enter a password: ");
        input_to("enter_password", 1);
        return;
    }
    receive("\nPlease re-enter your password to confirm: ");
    tmp=passwd;
    input_to("confirm_password", 1);
}

void confirm_password(string passwd) {
    if(!passwd || tmp!=passwd) {
        receive("\nYour passwords did not match.\nBe sure to type your password in exactly the same way every time.");
        receive("\nPlease enter a password: ");
        input_to("enter_password", 1);
        return;
    }
    receive("\n\nPlease enter the format of your name.\nYou may add ' and - and capitalization as you wish within your name.\nDefault is \""+capitalize(__Name)+"\": ");
    input_to("name_format");
}

void name_format(string name) {
    if(!name || name=="") name=capitalize(__Name);
    if (__Name!=player_name(name)) {
        receive("\nYour formatting is incorrect.  You may only add ' or - or capitalizations.");
        receive("\nPlease enter the format of your name.\nYou may add ' and - and capitalization as you wish within your name.\nDefault is \""+capitalize(__Name)+"\": ");
        input_to("name_format");
        return;
    }
    __User=new(USER);
    __User->set_password(crypt(tmp,0));
    __User->set_name(__Name);
    __User->set_cap_name(name);
    exec(__User, this_object());
    __User->setup();
    destruct(this_object());
}
