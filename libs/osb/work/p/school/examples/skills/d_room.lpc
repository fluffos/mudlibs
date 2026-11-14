/*     This is a demo room for OSB
*
*      It shows the use of variable Long Description
*      as well as Seasons, Daytime and Temperature
*      Some basic skill functions are demosntrated as well
*
*   (c) Softbyte@OSB 16oct97
*
*
*/


#include <rooms.h>
#include <skills.h>
#include <regions.h>
#include <moving.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <herbs.h>
#include <math.h>
#include <nightday.h>


inherit "/std/room";

#define IS_DAY()        NIGHTDAY->IsDay()
#define IS_WINTER()     (NIGHTDAY->Query(P_SEASON)=="winter")

//************************************************************************ 
//                   Special details        
//************************************************************************ 
string look_lake()
{
int temperature;
  temperature=Query(P_TEMPERATURE);
  if (temperature<=0) return 
    "A small frozen lake. Maybe you can walk over the ice.\n";
  else return
    "A small crystal clear lake.\n";
  
}
string look_trees()
{
  if (IS_WINTER()) return
     "The trees are covered by a thin layer of ice.\n";
  else return
     "The trees a small but glimmer in a lush green.\n";
}

// Demonstration only
string look_weather()
{
string s;
  s="Current Weather data:\n";
  if (IS_DAY()) s+="- It is day and "+NIGHTDAY->QueryTimeString()+"\n";
  else s+="- It is night and "+NIGHTDAY->QueryTimeString()+"\n";
  if (IS_WINTER()) s+="- It is winter\n";
  s+="- It is the "+NIGHTDAY-> QuerySeasonString()+" season\n";;
  s+="- Temperature is "+Query(P_TEMPERATURE)+" degree\n";
  return s;
}

//************************************************************************ 
//                   Nifty long description
//************************************************************************ 
string QueryIntLong()
{
string s;
int temperature;
  temperature=Query(P_TEMPERATURE);

  s=
    "You see a small clearing where dense bushes and smaller trees lead "
    "into the deeper forest to the west. ";
  if (IS_WINTER()&&temperature<=0&&IS_DAY()) s+=
    "A fine layer of snow and ice covers the trees and bushes glittering "
    "marvellous in the sun. ";
  else if (IS_WINTER()&&temperature<=0) s+=
    "In the moonlight you see the snow and ice glimmering on the trees and "
    "bushes giving them a strange magic aura. ";
  else if (IS_WINTER()&&temperature>0) s+=
    "Some ice covers the trees but water is already dripping down from the "
    "bushes. ";
  else if (IS_DAY()) s+=
    "All over the bushes small blossoms are blooming in the sunlight. ";
  else s+=
    "All over the bushes you see small buds which seem to be closed at "
	"at night. ";

  if (temperature>0 && IS_DAY()) s+=
    "To the east lies a small crystal lake. ";
  else if (temperature>0) s+=
    "To the east lies a small crystal lake. On its surface small waves "
	"refract the white light of the moon. ";
  else s+=
    "To the east lies a small frozen lake. ";

  return s+"\n";
}
//************************************************************************ 
//                   Special move over ice
//************************************************************************ 
int walk_on_ice()
{
int temperature;
  temperature=Query(P_TEMPERATURE);
  if (temperature<=0)
  {
    msg_write(
	"You carefully try out the stability of the ice and then start walking "
	"over the lake.\n");

    this_player()->move(resolve_file("./s_room"),M_GO);

    return 1;
  }
  else return (int)notify_fail("Walk on the lake?\n");
}
//************************************************************************ 
//                   Main create
//************************************************************************ 
create()
{
  ::create();
  SetIntShort("a small clearing");
  AddDetail(({"small clearing","clearing"}),#'QueryIntLong);
  AddDetail(({"bush","bushes","dens bushes"}),
	"A good couple of small dense bushes. At one part they look freshly "
	"cut, so they might be worth of being searched.\n");
  AddDetail(({"tree","trees","small tree","smaller trees","small trees"}),
	 #'look_trees);
  AddDetail(({"forest","deep forest","deeper forest"}),
	"A small way to the west leads deeper into the forest.\n");
  AddDetail(({"aura"}),"Looks nice, doesn't it?\n");
  AddDetail(({"blossom","blossoms"}),"They look really marvellous.\n");
  AddDetail(({"bud","buds"}),"They will become marvellous blossoms.\n");
  AddDetail(({"lake","small lake","small crystal lake","crystal lake",
	 "frozen lake","small frozen lake"}),#'look_lake);
  AddDetail(({"ice"}),"Frozen water.\n");

  AddDetail("weather",#'look_weather);

  SetIntLight(25);
  SetOutdoors(1);

  Set(P_REGION, REGION_FOREST | REGION_MEADOW);
  Set(P_TEMPERATURE,20);
  SetCoordinates( ({2000,2000,0}));


  AddSkill(SK_SEARCH,"herbs",750,({"herb","herbs"}),([WOODHERBS(1000,1000)]));
  AddSkill(SK_SEARCH,"bushes",250,({"bush","bushes"}));
  AddSkill(SK_SEARCH,"hole",250,({"hole","small hole"}));
  AddSkill(SK_SWIM,"lake",300,({"east","lake","small lake"}));

  AddExit("west","./f_room");
  AddExit("east",#'walk_on_ice);

}

//************************************************************************ 
//                   Swimming functions
//************************************************************************ 
string CannotSwimmingLake()
{
int temperature;
  temperature=Query(P_TEMPERATURE);
  if (temperature<=0) return "Do you really intend to swim the ICE...\n";
  return 0;
}
int OnSucceedSwimmingLake(object who)
{
  msg_write(CMSG_GENERIC,
  "You slowly enter the cold water and begin to swim...You soon reach " 
  "the other shore.\n");
  who->move(resolve_file("./s_room"),M_SPECIAL, 
        ({"swims in","swims out","swim out"}));
  return 1;
}
int OnFailSwimmingLake(object who)
{
  msg_write(CMSG_GENERIC,
  "You jump into the water and get a good load of cold water into your "
  "lungs. Coughing you climb back on the shore.\n");
  who->ReduceHP(5);
  return 1;
}

//************************************************************************ 
//                   Searching functions
//************************************************************************ 
string CannotSearchingHole()
{
  if (Query("can_search_hole")==0)
    return "What hole?\n";
  if (Query("can_search_hole")>1)
    return "Seems the hole is already empty.\n";
  return 0;
}
int OnSucceedSearchingBushes()
{
  msg_write(CMSG_GENERIC,
  "You search through the bushes but find nothing of interest. "
  "But just as you want to stop you notice a small hole in the ground.\n");
  Set("can_search_hole",1);
  return 1;
}
int OnFailSearchingBushes()
{
  msg_write(CMSG_GENERIC,
  "Ouch..there are some thornes...\n");
  return 1;
}

int OnSucceedSearchingHole()
{
object ob;
  msg_write(CMSG_GENERIC,
  "You search the hole and fine a small amulet.\n");
  ob=clone_object("/std/thing");
  ob->SetShort("a small amulet");
  ob->SetLong("A small amulet for demonstration purpose only.\n");
  ob->SetIds(({"amulet","small amulet"}));
  ob->move(this_object(),M_SILENT);
  Set("can_search_hole",2);
  return 1;
}

//************************************************************************ 
//                   Distance functions
//************************************************************************ 
public void notify_leave(mixed to, int method, mixed extra)
{ 
int d;
  ::notify_leave(to,method,extra);

  if (this_player()!=previous_object()) return;
  if (stringp(to)) to=load_object(to);

  if (to==this_object()) return;

  d=L_DISTANCE->dist(to,this_object());
  if (d>0)
    write("You walk "+d+" m.\n");
}
