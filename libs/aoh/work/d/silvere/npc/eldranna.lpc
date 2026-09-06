#include <properties.h>
#include <msgclass.h>

inherit "/std/npc";

void create()
{
  ::create();

//  SetStandard(20,"human","Eldranna");
  SetName("Eldranna");
  SetLong("Eldranna owns the Bake Shoppe here in Silvere. She is a stout, "
    "middle-aged woman of medium stature, wears a simple blue dress and "
    "white apron, and has spots of flour in her hair. She appears pleasant "
    "and good-natured.\n");

  SetLevel(20);
  SetRace("human");

  AddId( ({ "shopkeeper", "baker" }));
  SetGender(2);

  SetAlign(200);

  InitChats(4, ({
    "Fianna bustles about the small shop, preparing dough for various types\n"+
      "of baked goodies.\n",
    "Fianna throws some wood onto the fire under the hot oven.\n",
    "Fianna rolls out some dough for bread loaves.\n",
    "Fianna looks at you briefly, wondering if you'd like to purchase\n"+
      "anything special.\n"
  }) );

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
          "Eldranna smiles: Welcome, "+
	       capitalize(({string})guest->QueryName()) + ". Don't forget to check "
	      "today's specials.\n");
  }
}
