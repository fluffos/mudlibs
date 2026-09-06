/*     This is a demo room for OSB
*
*      It shows the use of the climbing skill
*
*   (c) Softbyte@OSB 18dec97
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
#include <math.h>


inherit "/std/room";


//************************************************************************ 
//                   Special details        
//************************************************************************ 

//************************************************************************ 
//                   Main create
//************************************************************************ 
create()
{
  ::create();
  SetIntShort("another small clearing");
  SetIntLong(
  "You are on yet another small clearing. A huge tree stands in its "
  "middle. Strange also a huge pole is standing here.\n");
  AddDetail(({"small clearing","clearing"}),#'QueryIntLong);
  AddDetail(({"tree","huge tree"}),
   "This is a huge tree. You can 'climb' on it.\n");
  AddDetail(({"pole","huge pole"}),
   "This is a huge pole. You can 'climb' on it.\n");

  SetIntLight(25);
  SetOutdoors(1);

  Set(P_REGION, REGION_FOREST | REGION_MEADOW);
  Set(P_TEMPERATURE,20);
  SetCoordinates( ({3000,2000,0}));


  // Climb the tree with 10% difficulty..see below (climbing) functions for 
  // the move handling
  AddSkill(SK_CLIMB,"tree",100,({"tree","huge tree"}));

  // Climb the pole, which does exactely the same as the tree but you
  // do not need extra functions as the default implementation in the
  // skillserver willhandle the standard climb
  // P_SK_CLIMB_MSG is the argument give to a M_SPECIAL. If ommitted a
  // standard M_GO is used
  // P_SK_CLIMB_DEST is the destination room, where the player will arrive
  // P_SK_CLIMB_HURTHP: is the amount of HP the player will loose on
  // failing the climb and falling to thr ground. It can be a closure
  // returning the amount of damage
  AddSkill(SK_CLIMB,"pole",100,({"pole","huge pole"}),
   ([P_SK_CLIMB_MSG:({"climbs the pole","climbs in","climb the pole"}),
     P_SK_CLIMB_DEST:"./climb2_room",
     P_SK_CLIMB_HURTHP:5]) );

  
}

//************************************************************************ 
//                   Climbing functions
//************************************************************************ 
string CannotClimbingTree()
{
  // Alwys be able to climb   
  return 0;
}
int OnSucceedClimbingTree(object who, int value,string id,string extra,mixed map,mixed props)
{
  msg_write(CMSG_GENERIC,
  "You climb up the huge tree.\n");
  who->move(resolve_file("./climb2_room"),M_SPECIAL, 
        ({"climbs the tree","climbs in","climb the tree"}));
  return 1;
}
int OnFailClimbingTree(object who)
{
  msg_write(CMSG_GENERIC,
  "You begin to climb the tree but fall back on the ground\n"
  "Ouch...that hurt.\n");
  who->ReduceHP(5);
  return 1;
}

