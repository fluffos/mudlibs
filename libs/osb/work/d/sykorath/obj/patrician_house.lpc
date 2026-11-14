/*
 * the burned down house of the patrician for the inner city of sykorath
 * introduced by Magictcs - 22 Jan 98
 *
 * The house is burned down, but will rebuild by some carpenters,
 * but a stone dragon will spit fire to burn down it again!
 *
 * updates:
 *
 */

// TODO: burn_out sends a msg to the room
//       the message looks like that the dragon toldit, but the msg comes
//       from the house (!) - maybe move it to the dragon
//       make the dragon to an npc?!
// TODO: add msgs if the player enters the room!!!!

#include <properties.h>
#include <sykorath.h>
#include <moving.h>

inherit "/obj/inroom";

//**********
// variables
//**********
int state;
int finished;

int SetBuildState(int s) { return state=s; }
int QueryBuildState() { return state; }
int QueryFinished() { return finished; }        // read only!

//************************
// carpenters are finished
//************************
// called by the patrician room, if the carpenters are finished their work
int SetFinished(int f) {
  finished=1;
  call_out("burn_down",6);
}

//*****************
// reset the house!
//*****************
void burn_down() {
  show_room(ENV(TO),
    "The stone dragon comes to life again. He growls and start to spit "
    "fire at the newly built house.\n"
    "The house burns down up to their foundation.\n"
    "The dragon morphes back to the stone dragon - what for a mighty "
    "magic!\n");
  state=0;
  finished=0;
}

//************************
// we need a special short
//************************
string QueryShort() {
  if (!state) return 0;
  if (!finished)
    return "a partly finished house";
  return "a new house";
}

//*******************
// and a special long
//*******************
string QueryLong() {
  if (!state) return 0;
  if (!finished)
    return
      "The house isn't finished yet. Actually there is a door or an "
      "entry missing. The house itself consists mostly of oak-wood.\n";
  return
    "It is a newly built house. It is made of oak-wood. There is an "
    "entry, maybe you can get into it?\n";
}

//**********************************
// ads depends on several variables!
//**********************************
string *QueryAds() {
  if (!state) return 0;
  if (!finished) return ({"partly","partly finished"});
  return ({"new","newly","newly built"});
}

//********************************
// enter the house, when new built
//********************************
int enter_house(string str) {
  str=norm_id(str);
  if (strstr(str,"house")!=-1) {
    if (!finished) {
      write("You can't enter the not yet finished house!\n");
      return 1;
    }
    write("You enter the new house.\n");
    TP->move(TO,M_GO,"into the new house");
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Inside the new house");
  SetIntLong("This is the new built house.\n");

  AddId(({"house","__patrician_house__"}));
  SetNoGet("Taking a house? haha - nice joke!\n");

  AddRoomCmd("enter",#'enter_house);

  AddExit("leave",INNER("patrician"));  
}

