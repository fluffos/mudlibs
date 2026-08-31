
#define	TP	this_player()
#define TPP     TP->query_possessive()
#define TPN	TP->query_name()
 
inherit "room/room";
#include "../garden.h" 

int vanz,aanz;
 
reset(arg) {

    vanz=aanz=5;		/* Number of vials and ampoules */ 
    if (arg) return;
    set_light(0);
    property = "no_teleport";
    short_desc = "In a strange kitchen";
    no_castle_flag = 0;
    long_desc = 
        "You entered the kitchen where the witch does her work. "+
        "You find some strange ampoules and vials on the table. "+
        "To the west and north you may enter hotter places and "+
        "to the east you see a door. It's really smelly here, so "+
        "it would be better if you left this place.\n";
    dest_dir = ({ ROOM+"/house2","west", 
                  ROOM+"/bedroom","north"
                });

   items = ({"table","A big brown wooden table",
             "door","An iron door with a sign on it",
             "keyhole","A small iron keyhole",
             "sign","An iron sign, there is something written on it",  
             "vials","Some strange vials",
             "ampoules","Some ampoules special for the witch"});
}
 
init() {
  ::init();
  add_action("get","get");
  add_action("read","read");
  add_action("unlock","unlock");
  add_action("open","open");
  add_action("east","east");
  add_action("search","search");
}
east() {
 write("You bang your head against the closed door.\n");
 say(TPN+" bangs "+TPP+" head against the closed door.\n");
 TP->hit_player(1+random(4));
 return 1;
 }
search(str) {
if (str=="pocket") { return; } 
if (str=="table") {
  write("You find some vials and strange ampoules.\n");
  return 1;
}
else {
  write("You find nothing special.\n");
 return 1;
}
} 

get(str) {
if (str=="ampoules") {
write("They are magically fixed on the table, you can't get them.\n");
say(TPN+ " wants to get one of the ampoules but fails.\n");
return 1;}
if (str=="vials") {
write("They are magically fixed on the table, you can't get them.\n");
say(TPN+ " wants to get one of the vials but fails.\n");
return 1; }
else {
return; }
}

read(str) {
if (str!="sign") return;
write("You can read: Ladies only.\n");
say(TPN+ " reads the sign.\n");
return 1; }
open(str) {
if (str!="door") {
write("You are a little bit confused, but you are on the right way.\n");
say(TPN+ " tries to open the something but fails.\n");
return 1; }
if (str=="door") {
write("You try to open the door but you fail, it's locked.\n");
say(TPN+ " tries to open the door but fails.\n");
return 1; }
}

unlock(str) {
if (str!="door") {
write("You are a little bit confuse, but you are on the right way.\n");
say(TPN+ " tries to unlock something but fails.\n");
return 1; }
if (present("toiletkey",TP)) {
write("As you unlock the door it turnes you round and moves you in a stinking room.\n");
say(TPN+ " unlocks the door and leaves.\n");
TP->move_player("through a toilet door#/players/whisky/garden/room/toilet");
return 1; }
else {
write("You don't have the proper key.\n");
say(TPN+ " tries to unlock the door but don't have the proper key.\n");
return 1;}
}
