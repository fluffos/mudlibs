//	/adm/daemon/finger_d.c
//	from the Nightmare Mudlib
//	by Kalinash 18 Feb 94
//      Based on the old finger daemon by Descartes.

#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>

inherit OB_USER;

string query_hah(object ob, int verbose);
string query_ttl(string name);

void create() {
    ::create();
}

string user_finger_display(string who) {
    object ob;
    mapping mail_stat;
    string drow, name, level, tmp, where;
    int birth;
    string race, Class, guild, gender;

    if(!who) return "You must specify whom you wish to finger.";
    name = lower_case(who);
    if(!user_exists(name)) return "No such member of the Nightmare Reality.";
    who = sprintf("%s/%s/%s", DIR_USERS, name[0..0], name);
    unguarded((: restore_object, who :));
    mail_stat = (mapping)FOLDERS_D->mail_status(name);
    drow = sprintf("%s\n", query_ttl(name));
    race = "IdeaExchanger";
    Class = "coder";
    guild = "hacker";
    if(!gender=query_gender())
	gender = "neuter";
    if (guild)
	tmp = sprintf("%s %s %s %s",capitalize(gender),
	  capitalize(race), capitalize(Class), guild
	  == "assassin" ? "" : "of the " + capitalize(pluralize(guild)));
    else
	tmp = sprintf("%s %s %s",capitalize(gender),
	  capitalize(race), capitalize(Class));
    drow = sprintf("%s%s\n", drow, tmp);
    if(this_player() && adminp(this_player()))
	if(query_email())
	    tmp = sprintf("%sEmail : %s\n", drow, query_email());
	else
	    tmp = sprintf("%sNo email address.\n", drow);
    drow = tmp;
    if(!(ob = find_player(name)) || (int)ob->query_invis() ||
      hiddenp(ob)) {
	tmp = sprintf("%sLast on: ", drow);
	drow = tmp;
    }
    else {
	tmp = query_hah(find_player(name), 1);
	if(tmp != "") {
	    tmp = sprintf("%s%s\n", drow, tmp);
	    drow = tmp;
	}
	tmp = sprintf("%sOn since : ", drow);
	drow = tmp;
    }
    drow += ctime(query_login_time())+"\n";
    if(!mail_stat["unread"])
	tmp = sprintf("%sNo unread mail.\n", drow);
    else if(mail_stat["unread"] == 1)
	tmp = sprintf("%s1 unread piece of mail.\n", drow);
    else 
	tmp = sprintf("%s%d unread pieces of mail.\n", drow, mail_stat["unread"]);
    drow = tmp;
    who = user_path(name);
    if(unguarded((: file_exists, who+".project" :)))
	tmp = sprintf("%sProject: %s", drow,
	  unguarded((: read_file, who+".project" :)));
    drow = tmp;
    if(unguarded((: file_exists, who+".plan" :)))
	tmp = drow +"Plan:\n"+unguarded((: read_file, who+".plan" :));
    else
	tmp = sprintf("%sNo Plan.\n", drow);
    drow = tmp;
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

string query_ttl(string name) {
    string pre, post;
    if(!getenv("TITLE")) return capitalize(name);
    return replace_string(getenv("TITLE"), "$N", capitalize(name));
}

