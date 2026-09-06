#include <properties.h>
#include <msgclass.h>

inherit "/std/npc";

void create()
{
  ::create();


  SetName("Feridwyn");
  SetLong("Feridwyn is the proud owner of Silvere's fish shop. He used to "
	  "be a fisherman himself, until an accident forced him to leave "
	  "his trade and open this establishment. He is a middle-aged man "
	  "with very fair hair, blue eyes and a moustache. His left leg "
	  "is stiff and he walks with a noticeable limp.\n");

  SetLevel(20);
  SetRace("human");

  AddId( ({ "shopkeeper", "fishmonger" }));
  SetGender(1);

  SetAlign(200);
}

void init()
{
  ::init();
  if (interactive(this_player()))
    call_out("greet",2,this_player());
}

void greet(object guest)
{
  if(({string})this_player()->QueryName() != "Someone")
  {
      msg_room(environment(), CMSG_ROOM,
          "Feridwyn smiles: Welcome to Feridwyn's Seafood, "+
          capitalize(({string})guest->QueryName()) + ".\n");
  }
}
