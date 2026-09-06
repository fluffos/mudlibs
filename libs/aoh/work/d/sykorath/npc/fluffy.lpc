// the shopkeeper for the pipemaker shop
// made by magictcs - 17 sep 1998
// TODO: change thematches

#include <properties.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Fluffy");
  SetRace("human");
  SetShort("Fluffy the pipemaker");
  SetLong(
    "It's Fluffy, wellknown in the whole area. "
    "He provides you with best pipes and the pipe weed needed for it.\n");
  AddId(({"shopkeeper","pipemaker"}));
  SetLevel(20);
  SetGender(GENDER_MALE);

  AddQuestion(({"fluffy","name"}),
    "Fluffy grummels: Yes, Fluffy is my real name - it's not a joke!\n");
  AddQuestion(({"pipe","pipes"}),
    "Fluffy says: Oh I make the best pipes allover the world. They are "
    "beautiful, nice, best work you will ever see.\n"
    "Wanna buy some?\n");
  AddQuestion(({"weed","pipe weed"}),
    "Fluffy says: Well - I collect the best pipe weed all over the world. "
    "I own different type of weed, ranging from sweet to strong weed. "
    "Wanna buy some weed?\n");
  // add questions about pipe and weed

  // check for some special things:
  // type+match -> call fun
  InitMatch (
      // fun to call
        ({"ruffle","tickles","arrives","looks","looks"}),
      // types
        ({"ruffles","tickles","arrives","looks","examines"}),
      // matches
        ({"playfully the hair of you","you",0,"at sign.","sign." }),
      // delays
        ({    2,                         2,  2,   2,        2}) );
  // matches to:
  // smiles
  // ruffles playfully the hair of you
  // tickles you
  // arrives
}

// functions for InitMatch:
//-------------------------

// react to 'ruffle':
ruffle(str) {
  say("Fuffy sorts his hair.\n");
}

// react to 'tickle':
tickles() {
  say("Fluffy giggles happily.\n");
}

// react to new customers:
arrives(str) {
  say("Fluffy looks around and says: Hidiho - wanna buy s good pipe?\n");
}

looks() {
  say("Fluffy looks around and says: Oh are you interested in buying "
      "a nice pipe or some weed? I can help you a bit maybe?\n");
}

