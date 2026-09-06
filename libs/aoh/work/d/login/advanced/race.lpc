//---------------------------------------------------------------------------
// Advanced race selection room for OSB
//
// (c) Softbyte@OSB 14dec97
// [Softbyte] 14dec97   : Creation and standard functions
// [Mordrid] 14dec97    : Ship Description and Exits
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
#include <config.h>
#include <string.h>

inherit "/std/room";
private string *races; // available race

#define NEXT_ROOM "/d/login/advanced/gender"
#define LAST_ROOM "/d/login/entrance"

int cmd_select(string str)
{
  string *args;
  int i,found;

  if(!str)
  {
    msg_write(CMSG_GENERIC,
      "Try 'select race <race>' e.g.'select race human'.\n");
    return 1;
  }

  args = norm_id(str, 1);
  if ( sizeof(args) < 2 || args[0] != "race" )
  {
    msg_write(CMSG_GENERIC,
      "Try 'select race <race>' e.g.'select race human'.\n");
      return 1;
  }
  found=-1;
  // Handled arbitrary lower/upper case
  for (i=0;i<sizeof(races);i++)
  {
    if (lower_case(races[i])==lower_case(args[1]))
    {
      found=i;
      break;
    }
  }
  if (-1==found)
  {
    msg_write(CMSG_GENERIC,
      "There is no such race. Try another one.\n");
      return 1;
  }

  this_player()->Set(P_RACE, races[found]);
  this_player()->SetGhost(0);
  RACEMASTER->InitRace(this_player(),races[found]);

  msg_write(CMSG_GENERIC,
   "You are now %^BOLD%^%^GREEN%^" + add_a(races[found]) + "%^RESET%^.\n");
  return 1;
}

int cmd_info(string str)
{
int i,found;
string s;

  if(!str)
  {
    msg_write(CMSG_GENERIC,
      "Try 'info race <race>' e.g.'info human'.\n");
    return 1;
  }
  found=-1;
  // Handled arbitrary lower/upper case
  for (i=0;i<sizeof(races);i++)
  {
    if (lower_case(races[i])==lower_case(str))
    {
      found=i;
      break;
    }
  }
  if (-1==found)
  {
    msg_write(CMSG_GENERIC,
      "There is no such race. Try another one.\n");
      return 1;
  }
  s=({string})RACEMASTER->RaceInfo(races[found])||"";
  msg_write(CMSG_GENERIC,
  "That's what I know about %^BOLD%^%^GREEN%^"+ add_a(races[found]) + "%^RESET%^:\n"+s);
  return 1;
}

int CheckAction( string action, string verb, string arg, int method )
{
  if("exit" == action && "north" == verb
      && (({string})this_player()->Query(P_RACE) == 0  ||
          ({string})this_player()->Query(P_RACE) == "visitor") )
  {
    notify_fail("You must select a race before you may continue.\n",1000);
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

varargs void create(int repl)
{
  string s;
  int i;
  ::create();
  seteuid(getuid());
  races=({string *})RACEMASTER->AllRaceNames()||({});
  races -= ({ "visitor" });
  s="%^BOLD%^%^GREEN%^";
  for (i=0; i<(sizeof(races)+2)/3; i++)
  {
     if (3*i+2<sizeof(races))
       s+=sprintf("     %-20.20s   %-20.20s   %-20.20s\n",
         races[3*i],races[3*i+1],races[3*i+2]);
     else if (3*i+1<sizeof(races))
       s+=sprintf("     %-20.20s   %-20.20s\n",
         races[3*i],races[3*i+1]);
     else
       s+=sprintf("     %-20.20s\n",
         races[3*i]);
  }
  s+="%^RESET%^";

  SetIntShort("Race Selection");
  SetIntLong(
  "As soon as you enter this room, you are grabbed by the doctors "
  "and dragged onto an operation table. As the nurse is putting you "
  "to sleep, you hear the doctor ask you what you want to be. He offers "
  "you a choice between:\n"+
  s+
  "Now would be a good time to choose your race. Choose wisely -\n"
  "There can be only one!\n"
  "\n"
  "You can:\n"
  "- select race <race> (e.g. select race human) to morph into a new race.\n"
  "- info <race> (e.g. info human) to get more information about a race.\n"
  "\n"
  "Then proceed to the north to continue with the character setup.\n");

  SetIndoors(1);
  SetIntLight(50);
  Set(P_REGION,REGION_DREAM);
  Set(P_TEMPERATURE,20);
  Set(P_COORDINATES,({ ({0,100,0}),C_LOGIN }) );

  AddRoomCmd("select","cmd_select");
  AddRoomCmd("info","cmd_info");

 // move back to the beginning
 AddExit("return",LAST_ROOM);
 AddExit("north",NEXT_ROOM);
 CheckExit("north", DACT_CHECK);

}



