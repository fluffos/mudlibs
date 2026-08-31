#include <std.h>
inherit ARMOUR;
void create(){
 ::create();
set_name("test hat");
set_properties(([ "no steal":1, "magic item":({"squishie"})]));
set_short("%^BOLD%^%^WHITE%^test hat%^CYAN%^!%^RESET%^");
set_long("This is a furry little white hat.");
set_id(({ "hat", "test hat" }));
set_mass(-1);
set_type("hat");
set_value(0);
set_limbs(({ "head" }));
set_ac(7);
}
void init(){
 ::init();
add_action("yeh", "testt");
}


string query_hah(object ob, int verbose) {
    int time, tmp;
    string line;

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
	    line += (string)tmp;
	}
	else line += tmp+ " minute"+(tmp>1 ? "s " : " ");
    }
    if(verbose) line += "idle time";
    else line += "idle";
    return line;
}
int yeh(string str){
message("info", query_hah(find_player(str), 1), this_player());
return 1;
}
