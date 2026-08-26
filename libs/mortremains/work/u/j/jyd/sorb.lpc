
#include "/u/d/dalceon/mydefines.h"
inherit OBJECT;
int player_knew;
string sensed;
object orbtag;
int sense_messages(int,int,object);
void create(){
    seteuid(getuid());
    sensed = "";
    player_knew=0;
    //id makes it able to be examined
    set("id", ({ "view screen", "screen"}) );

    //short is what you see w/o examineing it
    set("short", "a view screen");

   set("long","@@query_long");

    //value is how much you would get in the shop
    set("value", 1000);
}

void init() {
   add_action("do_sense", "watch");
   add_action("do_clear", "clear");
}

int do_sense(string player_name) {
    int objint,myint;
   object player;

   if(!player_name) {
     write("Sense whom??\n");
         return 1;
   }
   if(sensed != "") {
     write("You are already watching "+capitalize(sensed)+"'s movements!\n");
     write("You must clear the screen to sense another person.\n");
     return 1;
   }
   player = find_player(player_name);

   if(!player) {
     write("There is no one by the name of "+capitalize(player_name)+" playing.\n");
     return 1;
   }
   orbtag = clone_object("/u/d/dalceon/realms/tokyo/items/orbtag");
   orbtag->move(player);
   objint = player->query("base_stat/intelligence");
   myint = this_player()->query("base_stat/intelligence");
   sense_messages(myint,objint,player);
   sensed = player->query("name");
   return 1;
}

int sense_messages(int myint, int objint,object player) {
   int intdiff;
   string name;

   name = player->QN;

   intdiff = myint - objint;
   write("You begin sensing "+name+"'s every move.\n");
   switch(intdiff) {
     case -100..2:
        write(name+" knows you are watching!!\n");
        tell_object(player,PLAYER->QN+" is watching you!!\n");
        player_knew =1;
        break;
     case 3..7:
        if(random(10) < 5) {
          write(name+" knows you are watching!!\n");
          if(random(10) < 5)
            tell_object(player,PLAYER->QN+" is watching you!!\n");
          else
            tell_object(player,"You feel as if you are being watched.\n");
          player_knew = 1;
        }
        break;
     case 8..12:
        if(random(100) < 25) {
          write(name+" knows you are watching!!\n");
          tell_object(player, "You feel as if you are being watched.\n");
          player_knew =1;
        }
        break;
   }
}         

int orb_tell(string loc, object orb) {

     if(environment(orb)&&(living(environment(orb)))) {
         tell_object(environment(orb), capitalize(sensed)+" has just left "+loc+".\n");
         return 1;
   }

   return 1;
}

int do_clear() {
   if(sensed == "") {
     write("You are not sensing anyone!!\n");
     return 1;
   }
   else {
     write("You stop watching "+capitalize(sensed)+"'s movements.\n");
     if(player_knew)
       tell_object(find_player(lower_case(sensed)), "You feel free to go where you please!!\n");
     sensed = "";
     destruct(orbtag);
     player_knew = 0;
     return 1;
   }
}

string query_long() {
   string desc;
   string watched;

   desc = "A small portable screen.  It is used by Tulpa to watch anyone he\n"+
          "wants to, anywhere he wants to. Since you don't possess the power\n"+
          "of Tulpa, you can only watch one person at a time.\n";

   if(sensed != "")
     watched = "You can see "+capitalize(sensed)+" in the screen.\n";
   else
     watched = "The screen is currently blank.\n";

   return (desc + watched);

}
