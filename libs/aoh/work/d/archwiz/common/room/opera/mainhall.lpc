  /* Coded by Charity 6/25/95 */
inherit "std/room";
#include "path.h"
    
int go_stage() {
   write("An usher politely informs you that you are not allowed onstage.\n\
He escorts you back to your chair. \n");
   return 1;
}

create() {
  ::create();
  SetIntShort("The Nightfall Operahouse Main Hall");
  SetIntLong(
"The inside of this hall is gorgeous. The room slopes downward from east\n\
to west where the stage is. There is an opera in progress, the performers\n\
dancing, moving and singing for the crowd. Rows of chairs are placed on the\n\
slope for the audience to sit and watch from. The hall is dimly lit by wall\n\
sconces. A large double door at the east end leads into the entrance hall.\n\
Above, at the east end, is a balcony.\n");
  SetIndoors(1);
  AddDetail("lights","This hall is dimly lit by wall sconces.\n");
  AddDetail(({"wall sconces","scones"}),"Fancy wall mounted lamps. \n");
  AddDetail("balcony","It's really too dark to see much there. \n");
  AddDetail(({"double doors","double door"}),
"The doors are made of very fine mahogany. They lead into the main hall. \n");
  AddDetail("door","The doors are made of very fine mahogany.\n");
  AddDetail("floor",
"It's a thick, plush carpet, and feels good to your feet. The floor slants\n\
down towards the stage to afford a good view to all.\n");
  AddDetail("chairs","Generously padded chairs which are quite comfortable.\n");
  AddDetail("carpet",
"It's a thick and plush carpet. It mush have cost a lot of money.\n");
  AddDetail("ceiling","High above you is the ceiling.\n");
  AddDetail("stage",
"A raised platform for the performers, at the far end of the hall.\n");
  AddDetail("crowd","Many people are sitting here enjoying the show.\n");
  AddDetail("audience","Many people are sitting here enjoying the show.\n");
  AddDetail("slope",
"The floor slants down towards the stage to afford a good view to all.\n");
  SetIntNoise("You can hear the beautiful singing coming from the stage.\n");
  AddExit("east",OPERA("entrance"));
  AddExit("stage",#'go_stage);
}
