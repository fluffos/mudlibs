  /* Coded by Charity 6/25/95 */
inherit "std/room";
#include "path.h"
#include <rooms.h>
    
create() {
  ::create();
  SetIntShort("The Nightfall Folk Club");
  SetIntLong(
"The inside of this clubroom is small, yet comfortable. There are many tables, "
"with chairs, placed around the room. A musician sits upon a stool, playing "
"his guitar, and singing ballads. Sometimes the crowd sings along or claps. "
"There is a real friendly atmosphere here, and you feel right at home. There "
"are little candles on each table providing a soft light. Posts rise up here "
"and there to meet beams. To the southeast, is a door leading out to the street.\n");
  AddItem(MONSTER("danny"),REFRESH_DESTRUCT);
  SetIndoors(1);
  AddDetail(({"light","lights"}),"This clubroom is dimly lit by table candles.\n");
  AddDetail(({"table candles","candles"}),"A small candle in a glass holder, on each table. \n");
  AddDetail(({"up","ceiling","roof"}),"It's really too dark to see much up there. \n");
  AddDetail(({"down","floor"}),"It's wood, dark with old stains.\n");
  AddDetail(({"posts","beams"}),"Rough hewn wood, used to support the roof.\n");
  AddDetail(({"musician","guitarist"}),"A smiling Irishman.\n");
  AddDetail("chairs","Wooden straight backed chairs which are not too comfortable.\n");
  AddDetail("crowd","Many people are sitting here enjoying the music.\n");
  AddDetail("stool","Just an ordinary stool for the guitarist to sit on.\n");
  AddDetail("guitar","A new folk guitar. Not Jimi Hendrix's.\n");
  AddDetail("door","A plain wooden door. \n");
  SetIntNoise("You can hear the guitarist play and sing old ballads. People also are talking quietly.\n");
  SetIntSmell("Smells a little smokey in here, but not bad.\n");
  AddExit("southeast",CITY("eastroad1"));
}
