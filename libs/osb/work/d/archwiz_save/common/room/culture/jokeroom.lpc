/*
** The funny room of jokes
** Part of the Nightfall Culture Center
** Author: Thragor@Nightfall, 03apr97
** Update:
*/

#include <rooms.h>
#include <properties.h>

#define SF(x) #'x //'

inherit "/std/room";

public string detail_mirror(string what)
{
  object *u,pl;
  u = users();
  if (!sizeof(u = users()))
    return "The mirror is pitch black.\n";
  pl = u[random(sizeof(u))];
  if (pl->QueryInvis())
    return "You see a lot of dust in the mirror.\n";
  return ("First you have the feeling to see only dust in the mirror but "
	  "suddenly you see:\n")+pl->Long();
}

public void create()
{
  (::create());
  SetIntShort("Culture Center - Jokeroom");
  SetIntLong("The Jokeroom of the Culture Center is painted in very loud "
	     "colours. The ceiling is painted bright yellow, the walls are "
	     "green like a young frog and the floor is red as a van of "
	     "the fire-brigade.\n"
	     "To the west you'll find the entrance of the Culture Center.\n"
	     "A golden portal is placed at the northern wall. But although "
	     "you're sure that you can see the portal there, you can also see "
	     "the wall behind it. Perhaps the portal is just an illusion?\n");
  Set(P_CANSEE,1);
  SetIntNoise("You hear some hideous laughter.\n");
  SetIntSmell("It smells like sweet lollies.\n");
  AddDetail(({"jokeroom","room"}),
	    SF(QueryIntLong));
  AddDetail(({"colours","loud colours"}),
	    "They hurt in your eyes.\n");
  AddDetail(({"bright yellow","yellow","green","red"}),
	    "The colour is very bright.\n");
  AddDetail(({"entrance","entrance-hall"}),
	    "The entrance-hall of the Culture Center is to the west.\n");
  AddDetail("walls",
	    "They are painted in very loud colours.\n");
  AddDetail(({"northern wall","north wall","wall north","wall","green wall"}),
	    "There seems to be a huge portal in front of it. But you "
	    "can see the green wall behind it.\n");
  AddDetail(({"southern wall","south wall","wall south"}),
	    "The wall is painted in beautiful green. There's a mirror fixed "
	    "to it.\n");
  AddDetail(({"mirror","strange mirror"}),
	    SF(detail_mirror));
  AddExplorable(({"mirror","strange mirror"}));
  AddDetail(({"western wall","wall west","west wall"}),
	    "The wall smiles at you with its bright green bricks.\n"
	    "An exit invites you to leave the room.\n");
  AddDetail(({"eastern wall","wall east","east wall"}),
	    "The bricks look like teeth of a grinning face... but they are"
	    "completely green.\n");
  AddDetail(({"bricks","teeth"}),
	    "The bricks of the wall look like teeth of a grinning face.\n");
  AddExit("west","./culture");
  AddDoor("north",
	  "./cc_questroom",
	  ([
	    P_SHORT:"a golden portal",
	    P_LONG:("The portal looks heavy, although it seems not to be "
		    "here.\n"
		    "Perhaps someone thought it is funny to put it here.\n"),
	    P_DOORCODE:"cc_door",
	    P_LOCKSTATE:LOCK_LOCKED,
	    P_IDS:({"portal"}),
	    P_ADS:({"golden"}),
	    P_KEYCODE:"cc_key",
	    P_KEYIDS:({"cc_key"}),
	    P_PICK_CHANCE:0
	  ])
	 );
  AddItem("/std/board",
	  REFRESH_HOME,
	  ([
	    P_SHORT:"A pink board with jokes",
	    P_LONG:("Here you can find jokes for any taste and of course "
		    "you can write jokes for any taste.\n"
                    "To select bad jokes, type 'group a.bad_jokes' and to "
		    "select 'normal' jokes type 'group a.jokes'.\n"),
	    "Groups":({"a.bad_jokes","a.jokes"}),
          ]) );
}
