/* The former C.A.R.T. Station below South Plaza */

#include <rooms.h>

inherit "std/room";
inherit "lib/raceportal";

void create() {
	::create();
  /* --- Portal stuff --- */
  SetPortalRace("darkelf");
  SetPortalRoom("/d/atlantis/common/room/darkelf/templeback");
  SetPortalDetail(
({ "The graffiti depicts a spider.\n"
 , "The graffiti depicts a spider... at least it resembles a spider.\n"
 , "The graffiti is nothing but a pitch black spot.\n"
 , "Looking a the spider, its body figure melts and fades into the view of\n"
   "a dark temple room. Its floor is covered with eggshape things.\n"
  "It appears quite real, as if this graffiti were in fact a portal between\n"
  "here and there.\n"
  "It indeed could be possible to step into the graffiti, and perhaps even\n"
  "with other players.\n"
})
                  );
  SetPortalSingle(
({ "Something is definitely wrong, as you can't enter the graffiti.\n"
 , "You can't enter the graffiti right now, as it leads nowhere.\n"
 , ({ "vanishes into a graffiti", "leaves" })
 , ({ "appears out of a graffiti", "arrives" })
 , "step into the graffiti and find yourself climbing out of a spider egg"
})
                 );
  SetPortalMulti(
({ "Something is definitely wrong, as you can't enter the graffiti.\n"
 , "You can't enter the graffiti right now, as it leads nowhere.\n"
 , ({ " vanishes into a graffiti.\n", "Someone leaves.\n" })
 , ({ " drags %% into a graffiti.", "Some people leave.\n"})
 , ({ " drags a group of people into a graffiti.\n", "Some people leave.\n"})
 , ({ " appears out of a graffiti.\n", "Someone arrives.\n"})
 , ({ " appears with %% out of a graffiti.", "Some people arrive.\n"})
 , ({ " appears with a group of people out of a graffiti.\n", "Some people arrive.\n"})
 , "You step into the graffiti and find yourself emerging "
   "out of the egg of a spider.\n\n"
 , "You drag %% through the graffit and out of a spider egg.\n"
 , " drags %% through a graffiti and out of a spider egg.\n"
 , "You drag a group of people through the graffiti and out of a spider egg.\n\n"
 , " drags a group of people and you through a graffiti and out of a egg.\n\n"
})
                );
  /* --- Portal stuff --- */

	SetIntShort("The former C.A.R.T. Station South Plaza");
	SetIntLong(
"This is the C.A.R.T. Station below South Plaza. It once must have been "+
"Nightfall's Main Station, due to torn posters and old graffitis on the walls. "+
"But now this Station is full of dust and dirt. This surely is not a secure "+
"place if you are afraid of tough guys bullying around. Better watch your "+
"wallet! A rotten, wooden staircase leads up.\n");
        /* SetIntLight(1); */
        AddExit("up",     "/d/archwiz/randyandy/plaza");  

  AddExit("graffiti", PortalExit());
  HideExit("graffiti", HIDE_ALWAYS);

  AddRoomCmd( ({"enter", "step"})
        , PortalExit(({"into the spider graffiti", "in to the dark graffiti"}))
            );

  AddDetail("graffitis",
"Once colorful graffitis, now bleached out by time. Especially a spider-shaped "
"one is really dark.\n");
  AddDetail(({"graffiti", "spider", "spider graffiti", "dark graffiti"})
           , #'PortalDetail);
}
