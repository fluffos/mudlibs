#include "/players/francesco/univ/ansi.h"
inherit "obj/weapon";

int counter, median, hour1, lower, upper, protracted;
string hour;

short() {
   string tmp_short;
    if (call_other(this_player(), "query_level", 0) > 30) {
      tmp_short = short_desc + "  < wc " + class_of_weapon + ","+eff_wc + " >";
   if (broke) tmp_short = short_desc + " [BROKEN]";
      if (wielded)
         return tmp_short + " (wielded)";
      return tmp_short;
     }
 if(wielded && broke && protracted) return short_desc + " with a protracted blade [BROKEN] (wielded)";
 if(wielded && broke) return short_desc + " [BROKEN] (wielded)";
 if(broke) return short_desc + " [BROKEN]";
 if(wielded && protracted) 
   if(short_desc)
    return short_desc + " with a protracted blade (wielded)";
 if(protracted) 
   if(short_desc)
    return short_desc + " with a protracted blade";
 if(wielded)
    if(short_desc)
     return short_desc + " (wielded)";
  return short_desc;
}

reset(arg){
counter =0;
  ::reset(arg);
  if (arg) return;
   
 set_name("cane");
  set_alias("knife");
  set_alt_name("weapon");
  set_short("A walking cane"); 
  set_long("This cane is basically an inoffensive thin walking tool.  Yet, \n"+
           "it has a hidden blade which can be protracted and used for \n"+
           "personal defense.  In such a case it is a formidable weapon.\n"+
           "At a closer look, something to view is engraved in the handle.\n");
  set_type("knife");
  set_class(8);  
  set_weight(1);
  set_value(5500);
  set_hit_func(this_object());
  median = random(60);

}

id(str)    { return str=="walking cane" || str=="cane"; }
/*short() {if(protracted) return "A walking cane with a protracted blade";
             else return "A walking cane";}
*/

init() {
  ::init();
  add_action("trade","trade");
  add_action("protract","protract");
  add_action("view","view");
  add_action("read","read");
}

weapon_hit(attacker){  /* extra hit */
 if(call_other(this_player(), "query_attrib", "pie") > random(60))
  {
   write("You swish the blade of your cane along your opponent's neck.\n"+
         "Yessssss!  It did the job!\n");
   if(attacker->query_hp() > 15) { if(wielded && protracted) return random(3)+15; }
  }
 if(call_other(this_player(), "query_hp") > 250 &&
    call_other(this_player(), "query_attrib", "int") > random(60)) {
  { if(wielded && protracted) return random(4)+11; }
  }
 hour = extract(ctime(time()),14,15);
 hour1=atoi(hour);
 lower = hour1 - 6; upper = hour1 + 6;
 if(lower <= median && upper >= median) {
    if(wielded && protracted) { return 16; }
 }
if(wielded) return 10;
return;
}

protract(str) {       /* drawback #1.  player has to use the hidden blade for full WC*/
if(environment() != this_player()) {notify_fail("You must get the cane first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to protract?\n"); return 0; }
   if(str=="blade") {
    if(protracted) {
       write("The blade has been already protracted off the cane.\n");
       return 1;}   
    if(wielded) {
       write("The blade cannot be protracted when the cane is wielded already.\n");
       return 1;}   
      write("You protract the blade out of the walking cane.\n"); 
      protracted = 1;
   return 1;}
return 1;
}

trade(str){            /* drawback #2.  to make full price it must be sold to narrator */
if(environment() != this_player()) {notify_fail("You must get the cane first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to trade?\n"); return 0; }
    if(id(str)){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  'Thank you, thank you, I lost\n"+
            "this wonderful cane ages ago, and now I am very happy\n"+
            "that you brought it back to me.  Please, take these \n"+
            "coins as a sincere mark of thanks.'\n");
      call_other(this_player(),"add_money",(5500));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}    

view(str) {       
if(environment() != this_player()) {notify_fail("You must get the cane first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to view?\n"); return 0; }
   if(str=="handle")  {write("On the handle there are some engravings to read.\n"); return 1;}
   notify_fail("What do you want to view?\n"); return 0; 
return 1;
}

read(str) {       
if(environment() != this_player()) {notify_fail("You must get the cane first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to read?\n"); return 0; }
   if(str=="engravings")  {write("Property of Runi, the narrator.\n"); return 1;}
   notify_fail("What do you want to read?\n"); return 0; 
return 1;
}
