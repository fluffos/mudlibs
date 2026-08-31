//	/adm/daemon/finger_d.c
//	from the Nightmare Mudlib
//	by Kalinash 18 Feb 94
//      Based on the old finger daemon by Descartes.
//      Rewritten by Nightshade

#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>

inherit OB_USER;

string query_hah(object ob, int verbose);
string query_ttl(string name);
string alig_str(string what, int x);

void create() {
    ::create();
}

string user_finger_display(string who) {
    object ob;
    mapping mail_stat;
    mixed birth;
    string drow, name, level, tmp, where;
    string race, clas, guild, gender, sub;

    if(!who) return "You must specify whom you wish to finger.";
    name = lower_case(who);
    if(!user_exists(name)) return "No such member of the Dreams of Dispair.";
    who = sprintf("%s/%s/%s", DIR_USERS, name[0..0], name);
    mail_stat = (mapping)FOLDERS_D->mail_status(name);
    drow = query_ttl(name);
    if(!race=query_race()) 
        race = "unborn";
    if(!clas=query_class())
        clas = "child";
    if(!sub=query_subclass())
        sub = "none";
    guild = query_guild();
    if(!gender=query_gender())
        gender = "neuter";
    birth = query_birthday();
    tmp = "%^CYAN%^[%^RESET%^*%^CYAN%^]%^BLUE%^------%^BOLD%^(%^WHITE%^Finger%^BLUE%^)%^RESET%^%^BLUE%^--------------------------------------------------[*]\n%^B_BLUE%^"+drow+" %^RESET%^%^CYAN%^(%^RESET%^"+capitalize(query_position())+"%^CYAN%^)%^CYAN%^\n";
    tmp += "%^B_BLUE%^Name: %^RESET%^";
    tmp += alig_str((string)query_cap_name(), 20);
    tmp += "%^BOLD%^%^BLUE%^Race: %^RESET%^";
    tmp += alig_str((string)capitalize(race), 20);
    if (!query_married())
        tmp += "%^BOLD%^%^BLUE%^Married: %^RESET%^Single";
    else
        tmp += "%^BOLD%^%^BLUE%^Married: %^RESET%^"+capitalize(query_married());
    tmp += "\n%^BOLD%^%^BLUE%^Gender: %^RESET%^";
    tmp += alig_str((string)capitalize(gender), 18);
    if(query_guild())
        tmp += "%^BOLD%^%^BLUE%^Guild: %^RESET%^"+pluralize(query_guild())+"\n";
    else
        tmp += "%^BOLD%^%^BLUE%^Guild: %^RESET%^None";
    ob = find_player(lower_case(who));
    tmp += "\n%^BOLD%^%^BLUE%^Class: %^RESET%^";
    tmp += alig_str((string)capitalize(clas), 19);
    tmp += "%^BOLD%^%^BLUE%^Subclass: %^RESET%^"+capitalize(sub);
    tmp += "\n%^BLUE%^--------------------------------------------------\n%^B_BLUE%^Birthday: %^RESET%^";
    tmp += capitalize(month(birth))+" "+date(birth)+", "+((year(birth)-18))+" BN\n";
    tmp += "%^BOLD%^%^BLUE%^Real Name: %^RESET%^"+query_rname()+"\n";
    if(ob){
    if(this_player() && archp(this_player()))
        if((drow = (string)ob->query_email()) != "")
           tmp += "%^BOLD%^%^BLUE%^Email: %^RESET%^"+drow+"\n";
        if(ob->query_invis())
            tmp += "%^BOLD%^%^BLUE%^Last on: %^RESET%^";
        else {
            drow = query_hah(ob, 1);
            if(drow != "") 
                tmp += drow+"\n";
            tmp += "%^BOLD%^%^BLUE%^On since: %^RESET%^";
        }
        tmp += query_last_on();
    }
    else{
        if((drow = query_email()) != "")
           tmp += "%^BOLD%^%^BLUE%^Email: %^RESET%^"+drow+"\n";
        tmp += "%^BOLD%^%^BLUE%^Last on: %^RESET%^" + query_last_on();
    }
    if(this_player() && archp(this_player()))
        tmp += " from "+query_ip()+"\n%^YELLOW%^";
    else
        tmp += "\n%^YELLOW%^";
    tmp += query_cap_name() + " has ";
    if(!mail_stat["unread"]) 
        tmp += "no unread mail.\n";
    else if(mail_stat["unread"] == 1) 
        tmp += "1 unread piece of mail.\n";
    else 
        tmp += mail_stat["unread"]+" unread pieces of mail.\n";
    drow = tmp+"%^BLUE%^--------------------------------------------------";
    return drow;
}

string query_hah(object ob, int verbose) {
    int time, tmp;
    string line;
 
    if(!interactive(ob)) {
	if(verbose) return "Disconnected.";
	else return "disconnected";
    }
    line = "";
    time = query_idle(ob);
    if(time < 60) return line;
    tmp = time / 86400;
    if(tmp) {   
	if(!verbose) return tmp + " d";
	else line += tmp + " day" + (tmp>1 ? "s " : " ");
    }
    tmp = (time%86400)/3600;
    if(tmp) {   
      if(!verbose) {
	if(tmp>9) return tmp+" h";
	else line += tmp+":";
      }
	else line += tmp + " hour"+(tmp>1 ? "s " : " ");
   }
     tmp = (time%3600)/60;
   if(tmp) {   
 	if(!verbose) {  
	    if(strlen(line)>0 && tmp < 10) line += "0";
	    line += tmp;
	}
	else line += tmp+ " minute"+(tmp>1 ? "s " : " ");
    }
    if(verbose) line += "idle time";
    else line += "idle";
    return line;
}
 
string query_last_on() { return last_on; }
 
string query_ttl(string name) {
    string pre, post;
    if(!getenv("TITLE")) return capitalize(name);
    return replace_string(getenv("TITLE"), "$N", capitalize(name));
}

string alig_str(string what, int x) {
    int y;
   string out;
  
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
        out = what[0..x-1] + " ";
        return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}

int remove() {
    destruct(this_object());
    return !(this_object());
}

int clean_up() {
    this_object()->remove();
    return 0;
}
