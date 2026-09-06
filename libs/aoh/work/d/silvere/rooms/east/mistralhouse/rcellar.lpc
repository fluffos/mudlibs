/* testroom.c - edited September 4, 1997: Mistral and Joan    */
/* Notify_enter added 09/11/97 - Mistral                      */
/* Root cellar description added 09/12/97 - Mistral and Joan  */
/* Almost complete 09/30/97 - Mistral and Joan                */
/* Mordrid exit added 10/01/1997 - Joan                       */
/* Began working again on Xanadu Tunnels 8/5/2002             */
#include <stdrooms.h>
#include <properties.h>

inherit "/std/room";

void notify_enter(mixed from, int method, mixed extra)
{
  int ret;
  ret=::notify_enter(from,method,extra);

  tell_object(previous_object(),"You enter a root cellar. "
                                 "Dim light filters in the from "
                                 "above.\n");
  return ret;
}

varargs void create () {
 ::create();
 Set(P_INT_SHORT, "a root cellar");
 Set(P_INT_LONG,({
 "Dried herbs, roots and flowers hang from hooks in the ceiling. Several "
 "baskets are stacked in the corner. Massive oak beams reinforce the "
 "earthen walls and ceiling. The floor and walls are smooth and dry. "
 "When you look past the hanging herbs you see a tunnel leading to "
 "into the distance.\n"
 "  =========================\n"
 "  =========================\n"
 "  ||/ /               \\ \\||\n"
 "  || /  .          .   \\ ||\n"
 "  ||/     . _____ .     \\||\n"
 "  ||-!     |/ _ \\|     !-||\n"
 "  ||       | |_| |       ||\n"
 "  ||       |_____|       ||\n"
 "  ||     .        .      ||\n"
 "  ||   .            .    ||\n"
 "  -------------------------\n",
 "You are in a root cellar. Herbs, flowers and roots hang from the "
 "ceiling. Some baskets are in a corner. Oak beams line the walls and "
 "ceiling. The earthen floor and walls are smooth and dry. When you look "
 "past the herbs you see a tunnel stretching to the distance.\n" }));

  Set(P_INDOORS,1);

  SetIntSmell("The cellar smells of earth, dried herbs, "
  "flowers and roots.\n");
  SetIntNoise("You hear the muffled sounds of borrowing creatures "
  "making their way underground.\n");

  AddDetail("walls","They are made of hard packed earth and supported "
  "with wood beams.\n");
  AddDetail("floor","The floor is hard packed earth. "
  "It is dry and smooth.\n");
  AddDetail("ceiling","The dirt ceiling is supported by massive "
  "wood beams.\n");
  AddDetail("beams","The beams are 8x10 inches of solid oak. They "
  "are ancient but sturdy as the day they were cut.\n");
  AddDetail("herbs","You see a strong healing herb. Perhaps you should "
  "take it.\n");
  AddDetail("flowers","They are mostly wild flowers and they smell "
  "wonderful.\n");
  AddDetail("roots","You are sure one of them is poisonous. You decide "
  "to leave them alone.\n");
  AddDetail("baskets","They are broken. Perhaps their owner will mend "
  "them.\n");

 /* I would like to add a healing thingee here for a player to take */
   /*  AddItem   - CRANBERRIES  DUH ???? - */

  AddNoise(({"creatures","burrowing","underground"}),
             "You hear distant whimpering, scrambling and "
             "scratching sounds.\n");


/*  AddExit("tunnel",/players/joan/test/xtunnel1");  */
  AddExit("out","/players/joan/room/cliff");
  AddExit("up","/players/joan/stuff/mistral-Aug21/house/111");
/* removed Mordrid  */
}
