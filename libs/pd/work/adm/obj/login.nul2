// Modified for gameinfo by Galgalon 940411
// Modified for pueblo
// Added ability to load a different user ob for chars in "usertest" group,
// and added help name policy when creating new char - Nulvect 20071102

#include <config.h> 
#include <news.h>
#include <flags.h>
#include <security.h> 
#include <daemons.h> 
#include <objects.h>
#define CHAT(s) CHAT_D->do_raw_chat("system", "Login <system> "+s);
#define NAME_POLICY "/doc/help/general/name policy"
//#define OB_USER_TEST "/std/usertest"

static private int __CrackCount; 
static private string __Name, __Ip; 
static private object __Player, playa; 
string pueb_ver, pueb_md5;
#define YELLOW     33

static void logon();
static void get_name(string str);
static void get_password(string str);
static private int locked_access();
static private int check_password(string str);
static private int valid_site(string ip);
static private int is_copy();
static void disconnect_copy(string str, object ob);
static private void exec_user();
static void new_user(string str);
static void choose_password(string str);
static void confirm_password(string str2, string str1);
static void choose_terminal(string str);
static void choose_gender(string str);
static void enter_email(string str);
static void enter_real_name(string str);
static void idle();
static void receive_message(string cl, string msg);
static private void internal_remove();
void remove();

void create() { 
    seteuid(UID_ROOT); 
    __Name = ""; 
    __CrackCount = 0; 
    __Player = 0; 
} 

string query_name() { return (__Name == ""?0:__Name); }
string query_ip() { return __Ip; }

static void display_logon() {
    int i,a, x;
    string *d;
    a = i = sizeof(users());
    while(a--)
	if (users()[a]->query_invis()) i--;

//  Get a random file from /news/login/
    x=sizeof(d=get_dir("/news/login/"));
    message("logon", "\n"+terminal_colour(read_file("/news/login/"+d[random(x)]), TERMINAL_D->query_term_info("ansi")), this_object());
    message("logon", center("Copyright (c) 1999-2008 Primal Darkness Productions."), this_object());
    if (!i)
	message("logon", "\n"+center("There is currently nobody in the realm.")+"\n",  this_object());
    else if (i==1)
	message("logon", "\n"+center("There is currently only one person in the realm.")+"\n", this_object());
    else
	message("logon", "\n"+center("There are currently "+i+" people in the realm.")+"\n", this_object());
    message("logon", center("Driver: "+version()+"      Mudlib: PD/NM v2.0/3.0\n"), 
      this_object()); 
    message("logon", "\nWhat name do you wish? ", this_object());

}
static void logon() { 
    int i, b=0;
    object *ob;
    __Ip = query_ip_number();
    if ((i=FPROT_D->add_connection(query_ip_number()))<1) {
	message("logon", "-------------[ Access Denied ]-------------\n"
	  "Your access has been denied for 30 seconds \n"
	  "for connecting too fast.\nPlease wait and try "
	  "again.\n",
	  this_object());
	if (i==0)
	    if (FPROT_D->firewall_ip(query_ip_number())==-1)
		CHAT_D->do_raw_chat("system", "Firewall <driver>"
		  ""+query_ip_number()+"'s access has been denied for "
		  "30 seconds for repeated connections.");
	internal_remove();
	return;
    }


    i = sizeof(ob = users());
    while(i--)
    {
	if (query_ip_number()==query_ip_number(ob[i])) b++;
    } 
    if (b>6)
    {
	this_object()->setenv("TERM", "ansi");
	message("logon",
	  "--------------[ Access Denied ]--------------\n"
	  " You are only allowed to have 3 characters on\n"
	  " simultaneously. Try getting off one character\n"
	  " and then logging on again.\n"
	  "---------------------------------------------\n",
	  this_object());
        CHAT("Denied access to "+query_ip_number()+" for too many simultaneous characters online.");
	internal_remove();
        return;
    }
    call_out("idle", LOGON_TIMEOUT); 
    if (BANISH_D->query_total_ban(query_ip_number()))
    {
	message("logon", "\n---------------------------[ Site Banished ]---------------------------\n"
	  " The site from where you are connecting has been banished.  You may \n"
	  " not create new characters, nor play old ones.  We are sorry, but some\n"
	  " people do not get the hint to leave.  If you feel this is in error, \n"
	  " please mail us at whit@primaldarkness.com\n"
          " This could have been caused by continuous auto connections in which \n"
          " case you will be unbanned eventually.  Please contact whit@primaldarkness.com \n"
          " for more information on this matter."
	  "-----------------------------------------------------------------------\n", 
	  this_object());
	catch(CHAT_D->do_raw_chat("system", "Login <system> TotalBan: Inbound connection from IP: "+query_ip_number()+" denied."));
	internal_remove();
	return;
    }

    if(!b || b==1)
	catch(CHAT_D->do_raw_chat("system", "Login <system> "
	    "Inbound connection from IP: "+query_ip_number()));
    else catch(CHAT_D->do_raw_chat("system", "Login "
	    "<system> Inbound connection from IP: "+
	    query_ip_number()+". Multiple ("+b+") connections."));

    display_logon();
    input_to("get_name"); 
} 

static void get_name(string str) { 
    int i, b;
    string userob;
    object * ob;
    if(!str || str == "") { 
	message("logon",
	  "--------------[ Invalid ]--------------\n"
	  " Please try entering something for a\n"
	  " character name. Please try again.\n"
	  "---------------------------------------\n", this_object());
        CHAT("Connection from "+query_ip_number()+" terminated for no username entered.");
	internal_remove();
	return; 
    } 
    __Name = lower_case(str); 

    if((int)master()->is_locked()) {
	message("logon", read_file(LOCKED_NEWS), this_object());
	if(locked_access())
	    message("logon", "\n               >>> Access allowed <<<\n",this_object());
	else {
	    message("logon", "\n               >>> Access denied <<<\n",this_object());
            CHAT("Access denied to "+str+" while mud is locked.");
	    internal_remove();
	    return;
	}
    }
    i = sizeof(ob = users());
    while(i--)
    {
        if (query_ip_number()==query_ip_number(ob[i])) b++;
    }
    if(b > 0 && !find_player(__Name) && !LAN_D->valid_lan(query_ip_number())) {
        this_object()->setenv("TERM", "ansi");
        message("logon",
          "--------------[ Access Denied ]--------------\n"
          " You currently have more than one character \n"
          " logged in from your IP.  If you have a LAN \n"
          " with multiple users playing from the same IP \n"
          " please contact an immortal to apply for LAN \n"
          " privileges.\n"
          "---------------------------------------------\n",
          this_object());
        CHAT("Denied access to "+query_ip_number()+" for no lan privs.");
        internal_remove();
        return;
    }

    if (member_group(__Name, "usertest")) userob = OB_USER_TEST;
    else userob = OB_USER;

    if(catch(__Player = new(userob))) {
	message("logon", 
	  "---------------[ Sorry! ]---------------\n"
          " I'm sorry but an error has occurred and \n"
          " access will not be allowed at this time.\n"
          "     We are working to resolve this \n"
          "       issue as soon as possible.      \n"
	  "----------------------------------------\n", this_object());
	internal_remove();
        CHAT("Error loading main user object. ("+userob+")");
	return; 
    }  

    if(!user_exists(__Name)) { 
	if(BANISH_D->query_banished_ip(query_ip_number())) {
	    message("logon", "\n------------------------[ Site Banished ]------------------------\n"
	      "The site from where you are connecting has been banished.  You may \n"
	      "not create new characters, but you may play old ones.  We are \n"
	      "sorry, but some people do not get the hint to leave.  If you feel \n"
	      "this is in error, please mail us at stormbringer@primaldarkness.com\n"
	      "-------------------------------------------------------------------\n", 
	      this_object());
            CHAT("Connection from a banished ip. Character: "+__Name+" IP: "+query_ip_number());
	    internal_remove();
	    return;


	}
	if(!((int)BANISH_D->valid_name(__Name))) { 
	   if(this_object()) {
	    message("logon",
	      "-----------------[ Invalid ]-----------------\n"
	      " The name you entered is invalid.\n"
	      " Please choose another name.\n"
	      " \n"
	      " * Your name must be in alphabetic characters\n"
	      " * It must be no longer than "+MAX_USER_NAME_LENGTH+" letters\n"
	      " * It must be no shorter than "+MIN_USER_NAME_LENGTH+" letters\n"
	      " * Please, no offensive names\n"
	      "---------------------------------------------\n", this_object());
	    message("logon", "\nPlease enter another name: ", this_object()); 
	    input_to("get_name"); 
            }
	    return; 
	} 

	if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) { 
	    message("logon", read_file(REGISTRATION_NEWS), this_object()); 
	    internal_remove();
	    return; 
	} 
	this_object()->setenv("TERM", "ansi");

	message("logon", terminal_colour(
	    "%^BOLD%^%^BLUE%^-------------------------%^WHITE%^[ %^CYAN%^New Name %^WHITE%^]%^BLUE%^------------------------------%^RESET%^\n"
            "    %^CYAN%^Welcome to Primal Darkness.  You are on the first step to \n"
            " entering the world of Primal Darkness.  We want your stay to be \n"
            "    as enjoyable as possible, so does [ %^RESET%^"+capitalize(__Name)+"%^CYAN%^ ] \n"
            "   sound good for a character name?  This name will be yours \n"
            "  throughout the time you spend with us.  Your name cannot be \n"
            "         changed after you create your character.\n"
            " Please type 'help name policy' to read our guidelines for character names.\n"
	    "%^BOLD%^%^BLUE%^-------------------------------------------------------------------%^RESET%^\n"
	    "Would you like to keep that name? [(y)es/(n)o/(h)elp]: ", 
	    TERMINAL_D->query_term_info("ansi-status"), 80, 0), 
	  this_object()); 
	input_to("new_user"); 
	return; 
    } 

    if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) { 
	message("logon", read_file(BANISHED_NEWS), this_object()); 
        
	internal_remove();
	return; 
    } 
    message("logon", "Welcome back to Primal Darkness, please enter your password: ", this_object()); 
    input_to("get_password", I_NOECHO | I_NOESC); 
} 

static void get_password(string str) { 
    if(!str || str == "") { 
	message("logon", "\nYou must enter a password.  Try again later.\n", 
	  this_object()); 
	internal_remove();
	return; 
    } 
    if(!check_password(str)) { 
	message("logon", "\nInvalid password.\n", this_object()); 
	if(++__CrackCount > MAX_PASSWORD_TRIES) { 
	    write_file("/failed/"+__Name, ctime(time())+"\n", 0);
	    write_file("/failed/"+__Name, ">>> Account hack attempt from, "+
	      query_ip_number()+" [ 3 pass attempts failed ] <<<\n", 0);

	    message("logon", "No more attempts allowed.\n", this_object()); 
            CHAT("Maximum password attempts reached for "+__Name+" at "+query_ip_number());
	    internal_remove();
	    return; 
	} 
	seteuid(UID_LOG); 
	log_file("watch/logon", sprintf("%s from %s\n", __Name, query_ip_number())); 
	seteuid(getuid()); 
	destruct(__Player);
	__Player = new(OB_USER);
	message("logon", "Password: ", this_object()); 
	input_to("get_password", I_NOECHO | I_NOESC); 
	return; 
    } 
    if(member_group(__Name, "superuser")) {
      message("logon", "Would you like to sign in [a]visible or [b]invisible: ", this_object());
      input_to("invis_select");
      return;
    } else
    if(!is_copy())
      exec_user(); 
} 

void invis_select(string s) {
   if(!s) {
     message("logon", "You must use a or b.  Choice ([a]visible [b]invisible): ", this_object());
     input_to("invis_select");
     return;
   }
   s=lower_case(s);
   switch(s) {
     case "a": if(__Player->query_invis()) __Player->set_invis(); break;
     case "b": if(!__Player->query_invis()) __Player->set_invis(); break;
     default: 
       message("logon", "Using your previous settings.", this_object()); 
       break;
   }
   if(!is_copy())
     exec_user();
   return;
}

static private int locked_access() { 
    int i; 

    if((int)BANISH_D->is_guest(__Name)) return 1; 
    i = sizeof(LOCKED_ACCESS_ALLOWED); 
    while(i--) if(member_group(__Name, LOCKED_ACCESS_ALLOWED[i])) return 1; 
    return 0; 
} 

static private int check_password(string str) { 
    string pass; 

    //    def = "$1$z/hIu/FHsdfiodsjfoiuhfiuh0";

    master()->load_player_from_file(__Name, __Player); 
    if((pass = (string)__Player->query_password()) != crypt(str, pass) &&
      (pass!=oldcrypt(str,pass))) return 0; 
    return valid_site(query_ip_number()); 
} 

static private int valid_site(string ip) { 
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

static private int is_copy() { 
    object ob; 

    if(!(ob = find_player(__Name))) return 0; 
    if(interactive(ob)) { 
	message("logon", "\nThere currently exists an interactive copy of you.\n", 
	  this_object()); 
	message("logon", "Do you wish to take over this interactive copy? (y/n) ", 
	  this_object()); 
	input_to("disconnect_copy", I_NORMAL, ob); 
	return 1; 
    } 
    seteuid(UID_LOG); 
    log_file("enter", sprintf("%s (exec): %s\n", __Name, ctime(time()))); 
    seteuid(getuid()); 
    if(exec(ob, this_object())) ob->restart_heart(); 
    else message("logon", "Problem reconnecting.\n", this_object()); 
    internal_remove();
    return 1; 
} 

static void disconnect_copy(string str, object ob) { 
    object tmp; 
    string ip1, ip2;
    if((str = lower_case(str)) == "" || str[0] != 'y') { 
	message("logon", "\nThen please try again later!\n", this_object()); 
	internal_remove();
	return; 
    } 
    message("info", "Your character is being overridden.", ob); 
    ip1=query_ip_number(ob);
    ip2=query_ip_number();
    if (interactive(ob))
      exec(tmp = new(OB_USER), ob); 
    exec(ob, this_object()); 
    destruct(tmp); 
    message("logon", "\nAllowing login.\n", ob); 
    if(ip1 != ip2)
      CHAT("Character override: Name="+__Name+" Old IP="+ip1+" New IP="+ip2);
    internal_remove();
} 

static varargs private void exec_user() { 
    int i, b;
    object *ob;
    i = sizeof(ob = users());
    while(i--)
    {
        if (query_ip_number()==query_ip_number(ob[i])) b++;
    }
    if(b > 0 && !find_player(__Name) && !LAN_D->valid_lan(query_ip_number())) {
        this_object()->setenv("TERM", "ansi");
        message("logon",
          "--------------[ Access Denied ]--------------\n"
          " You currently have more than one character \n"
          " logged in from your IP.  If you have a LAN \n"
          " with multiple users playing from the same IP \n"
          " please contact an immortal to apply for LAN \n"
          " privileges.\n"
          "---------------------------------------------\n",
          this_object());
        CHAT("Denied access to "+query_ip_number()+" for no lan privs.");
        internal_remove();
        return;
    }
    MULTI_D->check_user(__Name, query_ip_number());
    __Player->set_name(__Name); 
    if(!exec(__Player, this_object())) { 
	message("logon", "Problem connecting.\n", this_object()); 
	internal_remove();
	return; 
    } 
    //CHAT(__Name+" logged on from "+query_ip_number());
    __Player->setup(); 
    destruct(this_object()); 
} 

static void new_user(string str) { 
    str = lower_case(str);
    if (str[0] == 'h') {
      message("logon", read_file(NAME_POLICY), this_object());
      message("logon", "\n\nWhat name do you wish? ", this_object());
      input_to("get_name");
      return;
    }
    if (str == "" || str[0] != 'y') {
	message("logon", "\nOk, then enter the name you really want: ", this_object()); 
	input_to("get_name"); 
	return; 
    } 
    seteuid(UID_LOG); 
    log_file("new_players", sprintf("%s : %s : %s\n", query_ip_number(), __Name,  
	ctime(time()))); 
    CHAT("New character from IP "+query_ip_number()+" named "+__Name);
    seteuid(getuid());
    message("logon", terminal_colour(
	"\n%^BOLD%^%^BLUE%^-------------------------%^WHITE%^[ %^CYAN%^Personal Password %^WHITE%^]%^BLUE%^-------------------------%^RESET%^\n"
	"%^CYAN%^This prevents other users from playing your character. The only way you\n"
	"will be able to access this character is with your unique password you\n"
	"pick below. Make sure nobody knows about this password and do not make\n"
	"it too simple.\n"
	"\n* Tips:\n"
	"   - Mix numbers and letters with your password\n"
	"   - Change it every so often if you can\n"
	"%^BOLD%^%^BLUE%^-----------------------------------------------------------------------%^RESET%^\n",
	TERMINAL_D->query_term_info("ansi-status"), 80, 0),
      this_object());
    message("logon","\n[1/5] Please choose a password of at least 5 letters: ", 
      this_object()); 
    input_to("choose_password", I_NOECHO | I_NOESC); 
} 

static void choose_password(string str) { 
    if(strlen(str) < 5) {
	message("logon", terminal_colour(
	    "\n%^BOLD%^%^BLUE%^-------------------------%^WHITE%^[ %^CYAN%^Password too short %^WHITE%^]%^BLUE%^-------------------------%^RESET%^\n"
	    "%^CYAN%^Your password is shorter than 5 characters long. Please choose another\n"
	    "password that is at least 5 characters in length.\n"
	    "%^BOLD%^%^BLUE%^------------------------------------------------------------------------%^RESET%^\n",
	    TERMINAL_D->query_term_info("ansi-status"), 80, 0),
	  this_object());
	message("logon", "\n[1/5] Please choose a password of at least 5 letters:", 
	  this_object()); 
	input_to("choose_password", I_NOECHO | I_NOESC); 
	return;
    } 
    if (str=="password" || str== __Name)
    {
	message("logon", "Please choose a more unique password.\n", this_object());
	input_to("choose_password", I_NOECHO | I_NOESC);
	return;
    }
    message("logon", "\n[2/5] Please confirm your password choice: ", this_object()); 
    input_to("confirm_password", I_NOECHO | I_NOESC, str); 
} 

static void confirm_password(string str2, string str1) { 
    if(str1 == str2) { 
	__Player->set_password(str2 = oldcrypt(str2, 0)); 
	message("logon",terminal_colour(
	    "\n\n%^BOLD%^%^BLUE%^--------------------------%^WHITE%^[%^CYAN%^ Gender%^WHITE%^ ]%^BLUE%^--------------------------%^RESET%^\n"
	    "%^CYAN%^Here you can pick the type of gender of the character you wish\n"
	    "to role play. The only available genders are male and female.\n"
	    "%^BOLD%^%^BLUE%^--------------------------------------------------------------%^RESET%^\n",
	    TERMINAL_D->query_term_info("ansi-status"), 80, 0),
	  this_object());
	message("logon", "\n[3/5] Please choose an interesting gender (male or female): ", 
	  this_object()); 
	input_to("choose_gender"); 
	return; 
    } 
    else { 
	message("logon", "\n- Password entries do not match.\n[1/5]  Choose a password: ", 
	  this_object()); 
	input_to("choose_password", I_NOECHO | I_NOESC); 
	return; 
    } 
} 

static void choose_gender(string str) { 
    if(str != "male" && str != "female") { 
	message("logon", "\nCute, but pretend to be either male or female instead\n", 
	  this_object()); 
	message("logon", "\n[3/5] Please choose an interesting gender (male or female): ",
	  this_object());
	input_to("choose_gender"); 
	return; 
    } 
    __Player->set_gender(str); 
    message("logon", terminal_colour(
"\n%^BOLD%^%^BLUE%^----------------------------%^WHITE%^[ %^CYAN%^Email%^WHITE%^ ]%^BLUE%^----------------------------%^RESET%^\n"
        "%^CYAN%^We require users to have a valid email.  We do this for security \n"
        "purposes.  If you do not supply a valid email address you will not be \n"
        "allowed to play here.  Your email will only be visible to \n"
        "our administration unless you add a (*) to the front of \n"
        "your email.\n"
	"%^BOLD%^%^BLUE%^-----------------------------------------------------------------%^RESET%^\n",
	TERMINAL_D->query_term_info("ansi-status"), 80, 0), this_object());

    message("logon","\n[4/5] Please enter your email address: ", this_object());
    input_to("enter_email"); 
} 

static void enter_email(string str) { 
    string a, b; 

    if(!str || str == "" || (sscanf(str, "%s@%s", a, b) != 2 &&
	sscanf(str, "*%s@%s", a,b) != 2) && a != "" && b != "") { 
	message("logon", "\nEmail must be in the form user@host.\n",this_object()); 
	message("logon","\n[4/5] Please enter your email address: ", this_object());
	input_to("enter_email"); 
	return; 
    } 
    if (sscanf(str, "#%s@%s", a,b) == 2) {
	message("logon", "\n - Your email address will not be shown to other players.\n", this_object());
    }
    __Player->set_email(str); 
    message("logon", terminal_colour(
"\n%^BOLD%^%^BLUE%^--------------------------%^WHITE%^[%^CYAN%^ Real Name%^WHITE%^ ]%^BLUE%^--------------------------%^RESET%^\n"
	"%^CYAN%^If you wouldn't mind telling us your real name, please enter it below.\n"
	"It is optional for you to do so. You can always add it later in time.\n"
	"%^BOLD%^%^BLUE%^---------------------------------------------------------------------%^RESET%^\n",
	TERMINAL_D->query_term_info("ansi-status"), 80, 0), this_object());
    message("logon", "\n[5/5] Please enter your real name (optional): ", 
      this_object()); 
    input_to("enter_real_name"); 
} 

static void enter_real_name(string str) { 
    string stri;
    string res;
    res  = sprintf("%c[0;%d;%dm", 27, 0, 0);
    stri = sprintf("%c[0;%d;%dm",27,1,YELLOW);
    if(!str || str == "") str = "Unknown"; 
    __Player->set_rname(str);
    __Player->setenv("TERM", "ansi");
    seteuid(UID_LOG);
    log_file("enter", sprintf("%s (new player): %s\n", __Name, ctime(time())));
    seteuid(getuid());
    seteuid(UID_ROOT);
    __Player->set_initial_ip(query_ip_number(this_object()));
    seteuid(getuid());
    message("info", "%^BOLD%^%^WHITE%^<%^CYAN%^-%^WHITE%^>%^RESET%^%^CYAN%^ "+capitalize(__Name)+" descends from the sky to begin "+possessive(__Player)+" journey in life.", users());
    IP_D->last_on(__Name, time());
    MULTI_D->new_user(__Name, query_ip_number());
    exec_user(1);
} 

static void idle() { 
    message("logon", "\nLogin timed out.\n", this_object()); 
    CHAT("Login timeout from "+__Ip);
    internal_remove();
} 

static void receive_message(string cl, string msg) { 
    if(cl != "logon") return; 
    receive(msg); 
} 

static private void internal_remove() {
    if(__Player) destruct(__Player);
    destruct(this_object());
}

void remove() {
    if(previous_object() && geteuid(previous_object()) != UID_ROOT) return;
    internal_remove();
}

