// Ferry connecting south quay and north quay in harbour of Silvere.

// Created by Taurec [18-Jan-1998]

#include <silvere.h>
#include <properties.h>

inherit "/obj/ship";

// Current harbours:
#define SIL_QUAY_NORTH  SIL_HARBOUR("quay1_2")
#define SIL_QUAY_SOUTH  SIL_HARBOUR("quay2_2")

// Current decks:
#define DECK_1  OBJ("transport/ferrydeck")

void create()
{
  ::create();
  SetShort("The Cydalus, a little harbourferry");
  SetLong(
    "This is just a small ferry that crosses the bay of Silvere. "
    "Enter it and get a little sightseeing tour through the harbour :-) ");
  SetIds(({"ship","boat","cydalus","ferry","harbourferry"}));
  SetNoGet("Not a chance.\n");
  AddDeck(DECK_1);
  AddPort("Northern Quay",SIL_QUAY_NORTH);
  AddPort("Southern Quay",SIL_QUAY_SOUTH);
}

varargs string QueryLong()
{
  string str;
  object *pass,deck;
  string *names;
  int s;
  str="This is just a small ferry that crosses the bay of Silvere. "+
      "Enter it and get a little sightseeing tour through the harbour :-) ";
  deck=find_object(DECK_1);
  if(!deck) return str+"There are currently no passengers on board.\n";
  pass = all_inventory(deck);
  if (!sizeof(pass)) 
    return str+"There are currently no passengers on board.\n";
  pass=filter_objects(pass,"QueryIsLiving");
  names=map_objects(pass,"QueryName");
  names-=({"Someone"});
  s = sizeof(names);
  if (!s) return str+"There are currently no passengers on board.\n";
  if (s==1) return str+"On the deck, you see "+names[0]+
                       " waving happily to you.\n";
  str+="On the deck, you see "+implode(names[0..s-2],", ");
  str+=" and "+names[s-1]+" waving happily to you.\n";
  return str;
}

