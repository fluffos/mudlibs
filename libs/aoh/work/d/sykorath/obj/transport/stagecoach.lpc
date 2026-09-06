// a special transport system - a stage coach (german: postkutsche)
// made by magictcs 18 jul 97

// TODO: update the port of silvere!!
// TODO: add a better description
// TODO: add more details (like the driver and horses and so on)
// TODO: and the whip of the driver :))
// TODO; make the move scenes nicer

#include <properties.h>
#include <sykorath.h>

inherit "/obj/ship";

// actually two stations:
#define SYKORATHSTATION   SYKORATH("coachport")
#define SILVERESTATION    SYKORATH("silvereport")

//*******
// create
//*******
create() {
  ::create();
  SetShort("a stage coach");
  SetLong("A nice stage coach which connects the cities.\n");
  SetIds(({"coach"}));
  SetAds(({"stage","nice stage"}));

  // update the ports!!!
  AddPort("Sykorath",SYKORATHSTATION);
  AddPort("Silvere",SILVERESTATION);

  // the stage coach has only one internal room for passengers:
  AddDeck("./stagecoach/coachdeck");

  // first string for the passengers internal
  // second string for the passengers waiting outside
  SetShipEnterMsgs( ({
    "The driver announces: We arrive at @@Harbour@@!\n"
    "You hear a loud 'Brrrr'.\n",
    "You hear a loud 'Brrrr'. A stage coach stops at the station.\n"
  }) );

  // first string for the passengers internal
  // second string for the passengers waiting outside
  SetShipLeaveMsgs( ({
    "The driver announces: We leave @@FromHarbour@@ and head\n"
                "  towards @@Harbour@@!\n"
    "The driver cracks with his whip.\n",
    "The driver cracks with his whip. The stage coach leaves the station.\n"
  }) );

  // message if passengers are in the stage coach and the stage
  // coach is moving from town to town:
  // first: some messages for moving from Sykorath to Silvere:
  AddMoveScene(SYKORATHSTATION,SILVERESTATION,"",1);
  AddMoveScene(SYKORATHSTATION,SILVERESTATION,
    "Some walls are passing by.\n",1);
  AddMoveScene(SYKORATHSTATION,SILVERESTATION,
    "The forest rushes by.\n",1);

  // second: some messages for moving from Silvere to Sykorath:
  AddMoveScene(SILVERESTATION,SYKORATHSTATION,"",1);
  AddMoveScene(SILVERESTATION,SYKORATHSTATION,
    "The forest rushes by.\n",1);
  AddMoveScene(SILVERESTATION,SYKORATHSTATION,
    "Some walls are passing by.\n",1);

  // enter stage coach from a station:
  SetEnterMsgs( ({
    "climbs into the stage coach",
    "arrives",
    "climb into the stage coach"
  }) );

  // leave the stage coach in a station:
  SetLeaveMsgs( ({
    "climbs out of the stage coach",
    "leaves",
    "climb out of the stage coach"
  }) );

  // overwrite the Noget (because ship is mentioned there)
  SetNoGet("Only Herkules can carry such a stage coach.\n");
}

