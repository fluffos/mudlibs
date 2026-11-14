// made by Magictcs 08 mar 97
// Id for the giant wisdom potion

#include <sykorath.h>

#define TIMETOREMOVE 360

inherit "/std/thing";

//*******************************
// show the potion to outer space
//*******************************
// add description to the players long description
string QueryExtralook() {
  return CAP(environment()->QueryPronoun())+" is gigantic wise.\n";
}

//******************************
// overload remove to give a msg
//******************************
int remove() {
  if (environment()) {
    tell_object(environment(),"You gigantic wisdom fades away.\n");
  }
  return ::remove();
}

create() {
  ::create();
  AddId("potion_of_giant_wisdom");
  call_out("remove",TIMETOREMOVE);
}

