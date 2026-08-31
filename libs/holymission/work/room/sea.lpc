inherit "players/cashimor/inherit/water";
#include "/obj/lw.h"
 
#define TP this_player() 
 
void reset(int arg) {
  if(arg) return; 
 
  short_desc="All at sea";
  long_desc = "\
You are at the corner of a wooden pier which leads west towards a small, \
dusty path, and north, from where you can hear the hussle and bussle of \
working people. Many ships can be seen out in the sea. This place looks like \
a good place to dive. There is a small wooden sign fixed to the stage.\n";
#if 0
    "You are on a small wooden pier which leads " + 
    "out into the sea. This place looks like a " +
    "good place to dive. There is a small wooden " + 
    "sign fixed to the stage.\n";
#endif
 
  items = ({ 
    "stage","A small wooden boat stage",
    "sign","This is a sign, maybe you should read it",
  });
 
  set_light(1);
  dest_dir=({
    "/room/jetty2", "west",
    "/players/brainsprain/bis/rooms/pier2", "north",
  });
 
  nodanger=1;
  floats="room/sea_bottom";
  ::reset(arg);
} 
 
void init() { 
  ::init();
  this_player()->set_smell("You smell of salty seawater.");
  add_action("dive","dive");
  add_action("read","read");  
} 
 
int read(string str) {
  if(str=="sign"){
    writelw(
      "This is the landing of the cargo junk to ezo island. "+
      "The ride is free but the captain asks that you refrain "+
      "from smoking and observe all safety precautions. "+
      "Have a safe and enjoyable voyage and try not to get "+
      "yourself killed on the island.\n"
    );
  }
 
  if(str=="read")
    write("Read what?!\n");
  return 1;
}
 
int dive() {
  TP->move_player("down#room/sea_bottom");
  return 1;
} 
