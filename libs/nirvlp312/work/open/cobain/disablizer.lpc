#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
   set_id("disablizer");
   set_long("Cobain's vocal disablizer (tm.)\n");
   set_weight(0);
   
}

init(){
   ::init();
   add_action("gag", "say");
   add_action("gag", "'");
   add_action("gag", "tell");

   add_action("gag", "gossip");
   add_action("gag", "risque");

   add_action("gag", "star");
   add_action("gag", "emote");
   add_action("gag", "farem");
   add_action("gag", "createchat");
   add_action("gag", "joinyes");

   add_action("gag", "sp");

}

drop(){ return 1; }
give(){ return 1; }
extra_look(){
  return ""+tpn+" is has a vocal disablizer (tm) attached to "+tpp+" neck \n"; 
}

gag(str) {

  write("\
You open your mouth to speak but only hear silence !\n\
Cobain has temporarily removed your vocal priviledges.\n");
    
  return 1;
}
