//---------------------------------------------------------------------------
// Advanced gender configuration room for OSB
//
// (c) Softbyte@OSB 10nov97
// [Softbyte] 11nov97   : Creation and standard functions
// [Mordrid] 13dec97    : Ship Description
// [Softbyte] 03feb98   : Colours
//
//
//---------------------------------------------------------------------------


#include <rooms.h>
#include <regions.h>
#include <moving.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <stats.h>
#include <string.h>

inherit "/std/room";

#define NEXT_ROOM "/d/login/advanced/stats"
#define LAST_ROOM "/d/login/advanced/race"

int do_gender_select(string str)
{
  string *args;
  int gender;

  if(!str)
  {
    msg_write(CMSG_GENERIC,
      "Try either 'select gender female' or 'select gender male'.\n");
    return 1;
  }

  args = norm_id(str, 1);
  if(sizeof(args) < 2 || args[0] != "gender" ||
     member(({"male","female"}),args[1]) == -1)
  {
     msg_write(CMSG_GENERIC,
       "Try either 'select gender female' or 'select gender male'.\n");
     return 1;
  }

  if(args[1] == "female") gender = GENDER_FEMALE;
  else gender = GENDER_MALE;

  this_player()->Set(P_GENDER, gender);

  msg_write(CMSG_GENERIC,
   "You are now %^BOLD%^%^GREEN%^" + args[1] + "%^RESET%^.\n");
  return 1;
}

int CheckAction( string action, string verb, string arg, int method )
{

  if("exit" == action && "north" == verb
      && (({int})this_player()->Query(P_GENDER) == GENDER_UNSET) )
  {
    notify_fail("You must select a gender before you may continue.\n",1000);
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

public varargs void create()
{
  ::create();
  SetIntShort("Gender Selection");
  SetIntLong(
  "As you wander around, you realize you are on a ship of some kind.\n"
  "You finally find yourself in an office. You sense a totally sterile\n"
  "smell. You know you are in a doctor's office. As you examine the\n"
  "diplomas on the wall, you realize this is a plastic surgeon's office.\n"
  "It's time you picked your gender. You have a 50/50 shot, let's hope you can get it right the first time.\n"
  "\n"
  "You can '%^BOLD%^%^GREEN%^select gender male%^RESET%^' or "
  "'%^BOLD%^%^GREEN%^select gender female%^RESET%^'.\n"
  "\n"
  "Then proceed to the north to continue with the character setup.\n");
  SetIndoors(1);
  SetIntLight(50);
  Set(P_REGION,REGION_DREAM);
  Set(P_TEMPERATURE,20);
  Set(P_COORDINATES,({ ({0,200,0}),C_LOGIN }) );

  AddRoomCmd("select","do_gender_select");

   // move back to the beginning
  AddExit("restart","../entrance");
  AddExit("return",LAST_ROOM);
  AddExit("north",NEXT_ROOM);
  CheckExit("north", DACT_CHECK);

  Set(P_INT_SMELL, "You smell gloves, latex gloves. Sterile and dry.\n");
  AddDetail(({"diploma","wall","diplomas","walls"}),
  "You see diplomas on the wall from top Medical Colleges around the world.\n");

}

