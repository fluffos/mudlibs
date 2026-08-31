#include <diran.h>

mapping factions;

mapping query_factions(){ return factions; }

void create(){
    if(!factions) factions = ([]);
    restore_object(MOB"faction_d.o");
}

string faction_status(string faction, string name){
    int i;
    i = factions[name];
    if(faction == "duergar") i *= -1;
    switch(i/25){
        case 3 : return faction + " exhalted";
        case 2 : return faction + " revered";
        case 1 : return faction + " honored";
        case 0 :
           if(i>0) return faction + " friendly";
           else return "neutral";
    }
}

string opposite_faction(string str){
    switch(str){
        case "duergar" : return "diran";
        case "diran" : return "duergar";
        default : return  "??";
    }
}

string my_faction(string name){
if(factions[name] > 0) return "diran";
else if(factions[name] < 0) return "duergar";
else return "neutral";
}

void add_points(string name, int points){
    if(member_array(name, keys(factions)) == -1) factions += ([name :
points]);
    else factions[name] += points;
    save_object(MOB"faction_d.o");
}

