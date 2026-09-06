// the shopkeeper for the shoemaker shop
// made by magictcs - 31 aug 1998

#include <properties.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Karlos");
  SetRace("gnome");
  SetShort("Karlos the shoemaker");
  SetLong(
    "It's Karlos the world famous shoemaker. "
    "He creates the best shoes all over the worls. He looks very old - "
    "like all gnomes, even if he isn't that!\n");
  AddId(({"shopkeeper","shoemaker"}));
  SetLevel(20);
  SetGender(GENDER_MALE);

  AddItem("/std/thing",1,([
    P_SHORT: "an awle",
    P_LONG:  "A shoemaker can use it to create new shoes. It's nearly "
             "useless for someone who isn't experienced with it.\n",
    P_IDS:   ({"awle"}),
    P_WEIGHT: 105,
    P_VALUE:  10,
    ]) );
  AddItem("/std/thing",1,([
    P_SHORT: "some yarn",
    P_LONG:  "This is a pile of black yarn to create new shoes with it.\n",
    P_ADS:   ({"black","some","pile of"}),
    P_IDS:   ({"yarn"}),
    P_WEIGHT: 105,
    P_VALUE:  20,
    ]) );

  AddQuestion(({"karlos","name"}),
    "Karlos grummels: Yes, Karlos is my real name - why do you ask?\n");
  AddQuestion(({"shoe","shoes","boot","boots"}),
    "Karlos says: well I'm producing the best shoes in this whole world. "
    "Belive me or not, you will miss myshoes whenever you walk somewhere "
    "without them! Hey they are not that expensive as they look like! Buy "
    "a pair!\n");
  AddQuestion(({"pair"}),
    "Karlos shouts: Oh well - I never sell a single boot, I just sel only "
    "pairs of them!\n");
  AddQuestion(({"gnome","gnomes"}),
    "Karlos says: Oh well, I'm a small gnome, but I make the best shoes you "
    "ever seen!\n");

  // enable it later
  InitChats(3,({
    "Karlos looks concentrated on his work.\n",
    "Karlos looks at you and starts to praise his boots.\n",
    "Karlos works with his awle.\n",
    "Karlos asks you: Wanna buy some shoes?\n",
    "Karlos giggles at you.\n",
    "Karlos ruffles playfully the hair of you.\n",
    }) );

  // check for some special things:
  // type+match -> call fun
  InitMatch (
      // fun to call
        ({"smiles","ruffle","tickles","arrives","looks","looks"}),
      // types
        ({"smiles","ruffles","tickles","arrives","looks","examines"}),
      // matches
        ({    0,   "playfully the hair of you","you",0,"at sign.","sign." }),
      // delays
        ({    2,      2,                         2,  2,   2,        2}) );
  // matches to:
  // smiles
  // ruffles playfully the hair of you
  // tickles you
  // arrives
}

// functions for InitMatch:
//-------------------------

// react to 'smile':
smiles(str) {
  say("Karlos sighs and says: You lucky one. Noone will buy my shoes, but "
     "they are the best in this world!\n");
}

// react to 'ruffle':
ruffle(str) {
  say("Karlos grummels and sorts his hair.\n");
}

// react to 'tickle':
tickles() {
  say("Karlos giggles happily.\n");
}

// react to new customers:
arrives(str) {
  say("Karlos looks around and says: Oh a new customer - nice - wanna buy "
     "some shoes?\n");
}

looks() {
  say("Karlos looks around and says: Oh are you interested in buying "
      "some shoes?\n");
}

