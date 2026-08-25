//	/adm/daemon/advanced.c
//	from the Nightmare mudlib
//	the advancment daemon
//	created by Descartes of Borg 05 december 1992

#include <rooms.h>
#include <daemons.h>

#define MY_CLASS_HALL  DIR_STANDARD_DOMAIN+"/"+class+"_hall"

int get_exp(int lev);
int train_player(object tp, string which, int amount);
int get_stat_cost(int x, int lev);
string previous_title(object tp);
string get_new_title(object tp);


int get_exp(int lev) {
    int val;

    switch(lev) {
	case 0: val = 0; break;
	case 1: val = 1014; break;
	case 2: val = 2028; break;
	case 3: val = 3056; break;
	case 4: val = 4800; break;
	case 5: val = 6200; break;
	case 6: val = 9100; break;
	case 7: val = 12500; break;
	case 8: val = 15000; break;
	case 9: val = 20000; break;
	case 10: val = 28000; break;
	case 11: val = 40000; break;
	case 12: val = 55000; break;
	case 13: val = 72000; break;
	case 14: val = 104000; break;
	case 15: val = 150000; break;
	default: val = (lev-12)*(lev-15)*28000 + 150000;
    }
    return val;
}

int train_player(object tp, string which, int amount) {
    int exp, amt;
 
    if(amount < 1) {
        notify_fail("You cannot train that amount.\n");
        return 0;
    }
    exp = (int)tp->query_exp();
    if(exp-amount < get_exp((int)tp->query_level())) {
        notify_fail("You do not have the experience to train that much.\n");
        return 0;
    }
    amt = ( ((int)tp->query_level()) * ((int)tp->query_max_skill(which)))
	/ 20;
    if(amt <= (int)tp->query_skill(which) )
    {
        notify_fail("You must advance your level to train more in that skill"+
                    ".\n");
        return 0;
    }
    tp->add_skill_points(which, amount/4);
    tp->add_exp(-amount);
    tell_object(tp, "You train in the skill of "+which+".\n");
    return 1;
}

int get_stat_cost(int x, int lev) {
    int z;

    if(x==1) z = ((lev/10)*(lev/10)*10000) + (lev/3)*1000;
    else z = (lev/7)*(lev/7)*(lev*900);
    if(z < 1000) z = 1000;
    return z;
}

string get_new_title(object tp) {
    int lev;
    string gen, title, str_class;

    lev = (int)tp->query_level();
    gen = (string)tp->query_gender();
    str_class = (string)tp->query_class();
    if(tp->query_guild()) {
        if(present("nightmare_guild", tp)) {
	    if(lev > 19) title = "High mortal";
            else title = (string)present("nightmare_guild", tp)->get_title(
              (int)tp->query_level());
	    title += " $N";
	}
	else {
	    if(lev > 19) title = "High mortal $N";
	    else title = "$N";
	}
    }
    else {
	if(lev > 19) title = "High mortal $N";
	else title = "$N";
    }
    if(lev > 19) title += " "+previous_title(tp);
    else if(gen == "male"){
 title += " ";
//title += MY_CLASS_HALL->get_male(lev);
}
    //else title += " "+MY_CLASS_HALL->get_female(lev);
    return title;
}

int advance() {
    int lev, exp;

    if(creatorp(this_player())) {
	notify_fail("You must find another way.\n");
	return 0;
    }
    lev = (int)this_player()->query_level();
    exp = (int)this_player()->query_exp();
    if(get_exp(lev+1) > exp) {
	write("You are not experienced enough to advance to the next level.\n");
	return 1;
    }
    if(!ROOM_QUEST->check_quests(this_player(), lev+1)) {
	notify_fail("You do not have enough quest points for the next level.\n");
	return 0;
    }
    this_player()->set_level(lev+1);
    if(lev == 19) {
	this_player()->set_position("high mortal");
	this_player()->add_search_path("/bin/high_mortal");
	shout("All hail "+(string)this_player()->query_cap_name()+" the new high mortal!\n");
 	write("You are now a high mortal.\nIf you wish for immortality, you must find an immortal mentor to make you immortal.\n");
	log_file("high_mortal", this_player()->query_name()+" became a high mortal: "+ctime(time())+"\n");
	CASTLE_D->enable_high_mortal(this_player());
	return 1;
    }
    this_player()->setenv("TITLE", get_new_title(this_player()));
    write("You are now level "+(lev+1)+".\n");
    say(this_player()->query_cap_name()+" advances to level "+ (lev+1)+".\n");
    return 1;
}

string previous_title(object tp) {
    string pre, post, str;

    str = (string)tp->getenv("TITLE");
    if(sscanf(str, "%s $N %s", pre, post) != 2) {
	sscanf(str, "$N %s", post);
    }
    return post;
}

void log_death(string str) { log_file("kills", str); }
