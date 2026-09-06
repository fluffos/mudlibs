// The way to the northern quay and the tower.
// created:          Sonic [26-May-1997]
// last changed:     Tune  [28-May-1997]
//                   Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <nightday.h>
#include <weather.h>

inherit HARBOUR_BASEROOM;

object check_fisher();
object call_fisher(int timer);

varargs void create()
{
   ::create();

   Set(P_INT_SHORT,"A street");
   Set(P_INT_WIZMSG,
    "This is a street, running in from southeast. To the southwest is the "
    "water of the harbour.\n"
    "Southeast: City-Gates, Harbourmaster, Inn, quay #2\n"
    "West:      quay #1 and the northern defense tower\n");

   Set(P_INT_LONG,
    "Piled lobster traps lie in heaps along the quay. The smell of "
    "fish and salt hangs heavy in the air. Murky waves splash "
    "lightly against the docks, and the boats creak at their moorings. "
    "Silvere's shipyard lies to the north, boat ramps are leading out of "
    "it and dip gently down into the water.\n");

   AddDetail(({"lobster traps", "traps"}),
    "Open-sided wooden frames, covered in a rope net. One end is open, "
    "large enough for the poor unsuspecting lobsters to crawl in, but "
    "not large enough for them to get back out.\n");

   AddDetail(({"boat","boats"}),
    "Colorful painted fisherboats of all kinds and sizes bob up and down "
    "in their moorings.\n");

   AddDetail(({"ramp","ramps","boat ramps"}),
    "Newly built ships may be moved from the shipyard into the sea by "
    "these ramps.\n");

   AddDetail(({"shipyard","yard"}),"The royal shipyard lies to the north.\n");

   AddSmell("fish",
    "The smell of stale fish is worst around the docks.\n");

   AddSmell("salt",
    "The salty air is fresh and invigorating.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -240,0,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run silly around and nearly fall in the water.\n");
   AddItem(#'check_fisher /*'*/, REFRESH_HOME,2);
   AddExit("north",     SIL_HARBOUR("shipyard"));
   AddExit("west",      SIL_HARBOUR("quay1_2"));
   AddExit("southeast", SIL_HARBOUR("street3"));
}

object check_fisher() {
  int i,daytime,state;
  mixed basedata;
  state=({int})NIGHTDAY->Query(P_STATE);
  basedata = ({mixed})NIGHTDAY->GetBaseData();
  for (i=0;i<state;i++) daytime+=basedata[i][WD_LENGTH];
  daytime+=basedata[state][WD_LENGTH]-(({int})NIGHTDAY->TimeLeft());
  daytime-=basedata[0][WD_LENGTH]/2;
  if (daytime<0) daytime=DAY_LENGTH+daytime;
  if (find_call_out("call_sailor")==-1){
    if (daytime<5200){
      call_out("call_fisher",5200-daytime,17200);
      return 0;
    }
    if (daytime>22400){
      call_out("call_fisher",DAY_LENGTH-daytime+5200,17200);
      return 0;
    }
    return call_fisher(22400-daytime);
  }
  return 0;
}

object call_fisher(int timer){
  object fisher;
  fisher=clone_object(NPC("fisherman"));
  if (!fisher) return 0;
  fisher->call_go(timer);
  show_room(TO,CAP(NAME(fisher))+" walks over a plank from his fisherboat "
   "and greets you.\n");
  return fisher;
}
