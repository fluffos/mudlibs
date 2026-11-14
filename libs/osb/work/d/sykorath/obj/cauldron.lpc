/*
 * a cauldron for the inner townwall
 * made by Magictcs
 *
 * updated:
 * Magictcs 08 feb 98 - first version
 *
 */

// TODO: add a heating possibility - maybe a mini quest to cook tar ?
//       need tar,cauldron,magic wand to heat the cauldron
//       (or wood to heat it?)

#include <properties.h>
#include <sykorath.h>

inherit "/std/container";

//**********
// variables
//**********
int heated;              // ==0 not heated, ==1 heated

//******************
// property handling
//******************
int QueryHeated() { return heated; }
int SetHeated(int h) { heated=h; return heated; }

//**************
// overload long
//**************
string QueryLong() {
  string ret;
  ret="This is a big black witch's cauldron. It is used to brew potions.\n";
  if (!heated) ret+="It is not heated yet.\n";
  else ret+="It is heated.\n";
  return ret;
}

//*******
// create
//*******
create() {
  ::create();
  heated=0;
  SetShort("a large cauldron");
  SetLong("\n");
  AddId("cauldron");
  AddAdjective("large");

  SetNoGet("The cauldron is too heavy to get.\n");
  SetWeight(45000);
  SetMaxWeight(125000);
}

//******
// reset
//******
reset() {
  if (heated) {
    show_room(TO,"The cauldron cools down.\n");
    heated=0;
  }
}

