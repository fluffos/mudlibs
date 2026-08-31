#include <std.h>
inherit OBJECT;
int silencer(string str);

void create(){
 ::create();
   set_name("gag");
   set_short("");
   set_long("You do not notice that here.");
   set_weight(0);
   set_value(0);
   set_id(({ "gag" }));
}

void init(){::init(); add_action("silencer", "");}
int give(){if(wizardp(this_player()))return 0; return 1;}
int put(){return 1;}
int drop(){if(wizardp(this_player()))return 0; return 1;}
int bury(){return 1;}
int query_auto_load(){return 1;}

int silencer(string str){
   if(!str) return 0;
   if(wizardp(this_player()))return 0;
   switch(query_verb()){
     case "newbie":
     case "hm":
     case "elite":
     case "legend":
     case "say":
     case "fighter":
     case "rogue":
     case "mage":
     case "kataan":
     case "cleric":
     case "monk":
     case "council":
     case "gossip":
     case "dragon":
     case "assassin":
     case "berserker":
     case "tell":
     case "reply":
     case "emoteto":
     case "echo":
     case "party line":
     case "emote":
     case "echoto":
     case "echoall":
       write("You have been owned.");
       return 1;
     default:
       return 0;
   }
   return 0;
}
