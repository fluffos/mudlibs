// North tower, level 2. A platform and some stairs are here.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [30-Jul-1997] added description/details
//                   Sonic [04-Aug-1997] platform handling added

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int rBoulder, rPlatform;

int QueryPlatform()  {  return  rPlatform; }
int QueryBoulder()   {  return rBoulder;  }

int SetPlatform(int nr)
{
   /* valid values for platform are:
    * 0: Platform is lowered and stays at ./ntower7.c
    * 1: Platform is raised and stays at ./ntower9.c
    * 2: Platform is moving down from ./ntower9.c to ./ntower7.c
    * 3: Platform is moving up from ./ntower7.c to ./ntower9.c
    * other values are ignored.
    */

   switch(nr)
   {
      case 0..3:  rPlatform=nr; break;
      default:    break;
   }
   return rPlatform;
}

int AddBoulder()
{
   rBoulder++;
   return rBoulder;
}

int SetBoulder(int nr)
{
   if(!nr) nr=0;
   rBoulder=nr;
   return rBoulder;
}

string Boulder_Amount()
{
   string desc;

   switch(rBoulder)
   {
      case 1:     desc="A boulder lies"; break;
      case 2..20: desc=CAP(itoa(rBoulder))+" boulders are lying"; break;
      default:    desc="Lots of boulders are lying"; break;
   }
   return desc;
}

string CheckBoulders()
{
   string desc;

   if(!rBoulder) return 0;
   desc=
      "The boulders are large rocks. @@Boulder_Amount@@ on the platform "
      "here.\n";
   return process_string(desc);
}

string CheckOpening()
{
   string desc;

   desc=
      "The opening leads through the ceiling on the top of the "
      "tower.";
   if(rBoulder==1)
      desc+=" A platform blocks the opening completly.";
   return desc+"\n";
}

string CheckPlatform()
{
   string desc;

   desc="";
   switch(rPlatform)
   {
      case 0:
         desc=
            "The platform is made out of wood. Ropes are leading up to "
            "the top of the tower. The opening in the ceiling is big "
            "enough for platform to fit through it.";
         if(rBoulder) desc+=" @@Boulder_Amount@@ on the platform.\n";
         break;
      case 1:
         desc=
            "The platform is made out of wood. Unfortunately, you can "
            "only see it from below, as the platform is moved to the "
            "opening in the ceiling.\n";
         break;
      case 2:
         desc=
            "The platform is made out of wood. It moves at the moment "
            "down from the opening in the ceiling.\n";
         break;
      case 3:
         desc=
            "The platform is made out of wood. At the moment it moves "
            "upward to the opening in the ceiling.\n";
         break;
      default:
         desc=
            "Something is wrong here. The platform has vanished somehow "
            "and there is no trace of it. It seems as if some strange "
            "magic has moved it somewhere else.\n";
         break;
   }
   return process_string(desc);
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"At a platform");
   Set(P_INT_LONG,
      "Stairs are leading here up to the top of the tower. Next to the "
      "stairs is a platform. Exits are leading to the north and east. "
      "Next to the stairs is a glowing globe, lighting the room.\n");

   Set(P_INT_WIZMSG,
" Up:    To the top of the tower\n"
" East:  To the crew waiting room\n"
" North: To the storeroom\n");

   AddDetail( ({"ground","floor","wooden floor"}),
      "The ground is made out of wooden beams. There is some dust, "
      "where you can see lots of footprints.\n");

   AddDetail( "dust",
      "Some dust is lying on the beams of the floor. You can see some "
      "footprints leading up the stairs and to the north and east.\n");

   AddDetail( ({"footprint","footprints"}),
      "Some footprints can be seen at the floor. They are leading up on "
      "the stairs and to the rooms to the north and east.\n");

   AddDetail( "ceiling",
      "The ceiling is made out of large wooden beams. They look very "
      "heavy. There is also an opening, where the stairs are leading "
      "on the top of the tower.\n");

   AddVItem(
   ([ P_IDS:({"beam","beams"}),
      P_ADS:({"wooden","heavy"}),
      P_LONG:
         "The beams are building the floor and the ceiling of the "
         "rooms here at the tower. Every now and then you hear "
         "someone walking by above you.\n",
      P_NOISE:
         "Every now and then someone seems to walk around above "
         "you.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing"}),
      P_LONG:
         "The globe is hanging on the southern wall. It is made out "
         "of glass and a small flame burns there in a friendly, "
         "yellow light. Below the globe is a small, locked box with "
         "a symbol on it.\n",
      P_SMELL:
         "The globe doesn't smell. But from the flame you sense "
         "the odor of burned oil.\n",
      P_NOISE:
         "You hear a muted crackling from the small flame inside "
         "the globe.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"box"}),
      P_ADS:({"small","locked"}),
      P_LONG:
         "The box is directly connected to the globe. A small "
         "symbol, that resembles a flame is painted on it. There"
         "is also a small lock, where the box can be opened.\n",
      P_SMELL:
         "The box doesn' smell. At least you are not able "
         "to sense something from it.\n",
      P_NOISE:
         "There is nothing, you can hear from the box. It is "
         "silent there.\n",
   ]) );

   AddDetail( "symbol",
      "The symbol shows you a single flame. It is painted on the "
      "box below the globe.\n");

   AddVItem(
   ([ P_IDS:({"flame"}),
      P_LONG:"The flame is burning inside the globe.\n",
      P_SMELL:"From the flame you smell the odor of burned oil.\n",
      P_NOISE:
         "You hear a muted crackling from the small flame.\n",
   ]) );

   AddDetail( ({"wall","walls"}),
      "The walls are made out of the same kind of stone as the whole "
      "tower. At the north and the east are exits in other rooms of "
      "this level, and a stair leads up to the top of the tower at the "
      "southern wall. There is also a glowing globe at the wall.\n");

   AddDetail( ({"stone","stones","grey stone","grey stones"}),
      "The stones are grey and there is nothing unusualy about them. "
      "The single stones are placed on each other to form the wall. "
      "After that was done, someone went over it and smoothed the wall "
      "to prevent people from hurting themself at the wall.\n");

   AddDetail( ({"north wall","northern wall"}),
      "At the north wall is an exit in another room of the level.\n");

   AddDetail( ({"south wall","southern wall"}),
      "At the southern wall is a glowing globe, that lights the room. "
      "There are also some stairs leading up on top of the tower.\n");

   AddDetail( ({"west wall","western wall"}),
      "A wooden platform is on the floor at the western wall. Ropes "
      "are leading up to the top of the tower.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "An exit leads into a small room to the east. Except of that, the "
      "wall is bare.\n");

   AddDetail( "opening",SF(CheckOpening));

   AddDetail( ({"stair","stairs"}),
      "The stairs are leading up through the ceiling on the top of "
      "the tower.\n");

   AddDetail( ({"tower","room","here","north defense tower",
                "north tower","defense tower","this level"}),
      "That's the room, you are standing in. If you want to know more "
      "about it, just have a look.\n");

   AddDetail( "platform",SF(CheckPlatform));

   AddDetail( ({"boulder","boulders"}),SF(CheckBoulders));

   AddDetail( ({"exit","exits"}),
      "There are three exits here. You can use the stairs to the top of "
      "the tower. To the north you can enter a small room and to the "
      "east you can enter the guardroom.\n");

   rBoulder=0;
   rPlatform=0;

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,0,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("up",   SIL_HARBOUR("ntower9"));
   AddExit("north",SIL_HARBOUR("ntower8"));
   AddExit("east", SIL_HARBOUR("ntower6"));
}
