#define MS(x) tell_object(find_player("goldsun"),x) 
#define TO this_object()
#define TP this_player()
#define TPN TP->query_name()
#define PATH "/players/goldsun/nottingham/room/"
#define MASTER "/players/goldsun/nottingham/monster/master"

inherit "/room/room";

#include "/players/whisky/genesis/sys/break_string.h"


void reset (int arg){

if (!arg){


set_light(1);
short_desc="In the training room";

     long_desc= break_string("@@query_desc@@",
	65);

items = ({"sign"," A wooden sign. There is something written on it",
          "floor", "It is a polished hardwood floor"
        });

smell = "You smell perspiration in the air";
property=({"no_teleport"});
no_obvious_msg="";
  }
 ::reset(arg);
}

query_desc(){
 return "/players/goldsun/nottingham/room/f_school"->query_long()+
	"    There is one obvious exit: north\n";
}


init(){
 ::init();
add_action("read","read"); 
add_action("no","north");
}

int no(){
 if (!present("student",TO) && !present("master",TO) ){
  TP->move_player("north#"+PATH+"f_cott");
  return 1;
 }
 write("You are not allowed to leave this room now.\n");
 return 1;
}

int read(string str){
  if (str=="sign"){
    write("Fence school\n");
    return 1;
  }
  notify_fail("Read what ?\n");
  return 0;
}

catch_tell(str){
 tell_room("/players/goldsun/nottingham/room/f_school",str);
}

