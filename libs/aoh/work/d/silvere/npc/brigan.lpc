#include <properties.h>
#include <msgclass.h>

inherit "/std/npc";

void create()
{
  ::create();

  SetName("Brigan");
  SetLong("Brigan is one of Silvere's wine merchants. He owns the wine shop "
	  "on Westway. Brigan is a rather short, wiry human who doesn't "
	  "look like someone who values good food and rare wines. Still, "
	  "he is quite convinced of his expertise on everything that has "
	  "to do with grapes and what to make of them. His wares are "
	  "usually of very high quality (and ditto prices).\n");

  SetLevel(20);
  SetRace("human");

  AddId( ({ "shopkeeper", "merchant", "wine merchant" }));
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
          "Brigan bows and says: Greetings, "+
               capitalize(({string})guest->QueryName())+ ". Welcome to Silvere's "
              "finest wine shop.\n");
  }
}

