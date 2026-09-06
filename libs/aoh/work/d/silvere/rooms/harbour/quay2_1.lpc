// The way to the southern quay and the tower.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Taurec [10-Oct-1997] added improved roomdesc.
//                   Taurec [08-Jan-1998] added all details :)
//                   Taurec [09-Mar-1998] added NPC, comes only at night

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <weather.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>

inherit HARBOUR_BASEROOM;

int knock_barrel(string what);
mixed look_fishers();
mixed look_longshoremen();
mixed look_cargo();
object check_sailor();
object call_sailor(int timer);

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"A street");
   Set(P_INT_LONG,
    "Loads of barrels, boxes and other crates are stored up here along "
    "the quay. Smashed bottles on the ground make walking without boots "
    "really unpleasant. You guess that this is the favourite hang-out "
    "place for drunken sailors at night. @@TimeMsg@@\n");
   Set(P_TIME_MSG,([
     DAY_DEFAULT_MSG:
       "Longshoremen and fishermen are occupied with their daily "
       "jobs, ships are being loaded and unloaded with cargo. Happy "
       "whistling and singing is everywhere, the people seem to enjoy "
       "their work.",
     NIGHT_DEFAULT_MSG:
       "Besides staggering hiccuping drunkards, no one dares to go here "
       "after sunset. Peering into the darkness of the harbour, you can "
       "hardly make out the outlines of several boats and ships."
    ]));
   Set(P_INT_WIZMSG,
    "This is a street, running in from northeast. To the northwest "
    "is the water of the harbour.\n"
    "Northeast: City-Gates, Harbourmaster, Inn, quay #1\n"
    "West:      quay #2 and the southern defense tower\n");

// ***************** VITEMS *******************

   AddVItem(([
     P_IDS: ({"barrel","barrels"}),
     P_ADS: ({"wooden","brown"}),
     P_LONG:
      "You don't know what they contain... wine? beer? or just "
      "nothing? Knock with your knuckles at one of them and "
      "you'll know more.\n"
   ]));

   AddVItem(([
     P_IDS: ({"box","boxes"}),
     P_ADS: ({"wooden","brown"}),
     P_LONG:
      "Whatever is in there, it's surely living in a box ;-)\n"
   ]));

   AddVItem(([
     P_IDS: ({"crates"}),
     P_ADS: ({"wooden"}),
     P_LONG:
      "Barrels, boxes, all kinds of containers are "
      "waiting for their journeys all over the world.\n"
   ]));

   AddVItem(([
     P_IDS: ({"bottle","bottles"}),
     P_ADS: ({"smashed","littered"}),
     P_LONG:
       "Watch your step - or you'll be ...\n"
   ]));

   AddVItem(([
     P_IDS: ({"fishermen","fishers","fisher","fisherman"}),
     P_ADS: ({"happy","singing","whistling"}),
     P_LONG: #'look_fishers /*'*/
   ]));

   AddVItem(([
     P_IDS: ({"longshoremen","longshoreman"}),
     P_ADS: ({"happy","strong"}),
     P_LONG: #'look_longshoremen /*'*/
   ]));

   AddVItem(([
     P_IDS: ({"cargo"}),
     P_ADS: ({"smelly"}),
     P_LONG: #'look_cargo /*'*/
   ]));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -240,20,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run silly around and nearly fall in the water.\n");
   AddExit("west",      SIL_HARBOUR("quay2_2"));
   AddExit("northeast", SIL_HARBOUR("street3"));
   AddItem(#'check_sailor  /*'*/,REFRESH_HOME);
   AddRoomCmd("knock","knock_barrel");
}

/*** This checks for the daytime and decides whether cloning */
/*** the drunken_sailor(at nighttime) or not (at daytime)   */
/*** starts a callout that will clone the sailor to the right time then */
object check_sailor(){
  int i,daytime,state;
  mixed basedata;
  state=({int})NIGHTDAY->Query(P_STATE);
  basedata = ({mixed})NIGHTDAY->GetBaseData();
  for (i=0;i<state;i++) daytime+=basedata[i][WD_LENGTH];
  daytime+=basedata[state][WD_LENGTH]-(({int})NIGHTDAY->TimeLeft());
  daytime-=basedata[0][WD_LENGTH]/2;
  if (daytime<0) daytime=DAY_LENGTH+daytime;
  if (find_call_out("call_sailor")==-1){
    if (daytime>5190 && daytime<23010)
      call_out("call_sailor",23010-daytime,13530);
    else return call_sailor(DAY_LENGTH-daytime+5000);
  }
  return 0;
}

object call_sailor(int timer){
  object sailor;
  sailor=clone_object(NPC("drunken_sailor"));
  if (!sailor) return 0;
  sailor->call_go(timer);
  show_room(TO,CAP(NAME(sailor))+" sits down on a barrel "
   "and produces a bottle of rum immediately.\n");
  return sailor;
}

mixed look_fishers()
{
  if (({int})NIGHTDAY->IsDay()) return
   "The fishermen have got a hard work to do, keeping their ships in order, "
   "lifting heavy nets full of fish and bearing every weather (and rotten "
   "fish stench). Though, they enjoy their work and seem to be quite happy.\n";
  else return 0;
}

mixed look_longshoremen()
{
  if (({int})NIGHTDAY->IsDay()) return
   "The longshoremen help to load and unload cargo of the ships here. "
   "Their skin is bronzened from the work in the sunshine, and they are "
   "all heavily built and packed with muscles.\n";
  else return 0;
}

mixed look_cargo()
{
  if (({int})NIGHTDAY->IsDay()) return
   "All kinds of goods are to be seen... boxes full with "
   "foreign herbs, spice, strange fruits you've never seen before "
   "and there are even heavy boxes full of gold bars - but of "
   "course, those are guarded by well-armed cityguards.\n";
  else return 0;
}

int knock_barrel(string what)
{
  notify_fail("What do you want to knock?",NOTIFY_ILL_ARG);
  if (!what) return 0;
  if (!TP) return 0;
  if (strstr(lower_case(what),"barrel") == -1) return 0;
  write("Greedy for wine or some beer you knock with your knuckles "
        "against one of the barrels - K L O N K - it's empty.\n");
  show_room(TO,"-- K L O N K -- "+CAP(NAME(TP))+" knocks his knuckles "
    "against one of the barrels.\n","-- K L O N K --\n",({TP}));
  return 1;
}







