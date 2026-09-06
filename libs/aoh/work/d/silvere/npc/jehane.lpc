#include <properties.h>
#include <msgclass.h>

inherit "/std/npc";

void create()
{
  ::create();


  SetName("Jehane");
  SetLong("Jehane owns the flower shop on Westway. She is an elderly lady, "
	  "slightly plump and with a ready smile for everyone. She wears a "
	  "green apron over a white blouse and black skirt.\n");

  SetLevel(20);
  SetRace("human");

  AddId( ({ "shopkeeper"}));
  SetGender(2);

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
          "Jehane  smiles: Welcome, "+
               capitalize(({string})guest->QueryName()) + ". Are you looking for a "
	       "nice present to give someone special?");
  }
}
