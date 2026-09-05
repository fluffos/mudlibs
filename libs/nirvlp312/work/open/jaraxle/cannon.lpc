#include "/players/fred/ansi.h"
inherit "obj/treasure";

reset(arg){
if(!arg){

  set_id("cannon");
  set_short(BOLD+"A"+HIY+" BIG"+RED+" ASS"+GRN+" Cannon"+NORM);
  set_long("A very large cannon to get your"+BOLD+RED+" REVENGE!!!"+NORM+"\n"+
                "Use "+GRN+"help_cannon"+NORM+" to see how!\n");
   } 
 }

init(){
 ::init();
  add_action("helpem","help_cannon");
  add_action("bombem","bomb");
 }

helpem(){
  write("To use this kick ass cannon simply:\n\n");
  write("1: bomb <name>\n");
  write("2: point and laugh at said <name>\n");
  return 1; }

bombem(str){
  object who;
  if(!str){ write("Fire the cannon at who?\n"); return 1; }
  who = find_player(str);
  if(!who){ write("You can't find that person.\n"); return 1;}
   write("You aim the cannon at "+capitalize(str)+ " and light the fuse!\n\n");
   tell_object(who,
   capitalize(this_player()->query_name())+" aims a BIG ASS cannon at you."+BOLD+"\n"+
   "            RUN!!"+NORM+"\n\n");
    tell_room(environment(who),
   capitalize(this_player()->query_name())+" fires the Cannon at "+capitalize(who)+"."+BOLD+"\n"+
  "         HERE IT COMES!!!"+RED+"\n\n"+
  "BBBBBBBBB            OOOOOOO           OOOOOOO       MM             MM\n"+
  "BB       BB        OO       OO       OO       OO     MM MM       MM MM\n"+
  "BB        BB      OO         OO     OO         OO    MM  MM     MM  MM\n"+
  "BB        BB     OO           OO   OO           OO   MM   MM   MM   MM\n"+
  "BB       BB      OO           OO   OO           OO   MM    MM MM    MM\n"+
  "BBBBBBBBB        OO           OO   OO           OO   MM     MM      MM\n"+
  "BB       BB      OO           OO   OO           OO   MM             MM\n"+
  "BB        BB      OO         OO     OO         OO    MM             MM\n"+
  "BB        BB       OO       OO       OO       OO     MM             MM\n"+
  "BBBBBBBBBB           OOOOOOO           OOOOOOO       MM             MM"+NORM+BOLD+"\n\n"+
  "                 AWW =(    "+capitalize(who)+" done got fucked up!"+NORM+"\n");
  destruct(who);
  write("You fire the cannon at "+capitalize(str)+BOLD+BLU+"\n\n"+
  "BBBBBBBBB            OOOOOOO           OOOOOOO       MM             MM\n"+
  "BB       BB        OO       OO       OO       OO     MM MM       MM MM\n"+
  "BB        BB      OO         OO     OO         OO    MM  MM     MM  MM\n"+
  "BB        BB     OO           OO   OO           OO   MM   MM   MM   MM\n"+
  "BB       BB      OO           OO   OO           OO   MM    MM MM    MM\n"+
  "BBBBBBBBB        OO           OO   OO           OO   MM     MM      MM\n"+
  "BB       BB      OO           OO   OO           OO   MM             MM\n"+
  "BB        BB      OO         OO     OO         OO    MM             MM\n"+
  "BB        BB       OO       OO       OO       OO     MM             MM\n"+
  "BBBBBBBBBB           OOOOOOO           OOOOOOO       MM             MM"+NORM+BOLD+"\n\n"+
  capitalize(str)+" is blown to bits!"+NORM+"\n\n");  
  return 1; }

      
