//---------------------------------------------------------------------------
// Advanced skill configuration room for OSB
//
// (c) Softbyte@OSB 10nov97
// [Softbyte] 10nov97   : Creation and standard functions
// [Mordrid] 14dec97    : Ship Descriptions and Exits
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
#include <skills.h>
#include <string.h>

inherit "/std/room";

#define NEXT_ROOM  "/d/login/exit"
#define LAST_ROOM  "/d/login/advanced/stats"

#define P_ROLLEDSKILL "RolledSkill"
#define P_TRAINSKILL  "TrainSkill"

#define TP this_player()

int cmd_roll(string str)
{
int i,j;
string * classes;
string * skills;
int start,variance,bonus,value;
int learned;

  if (!str || -1==member(({"skill","skills"}),str) )
    return notify_fail("Roll what?\n");

  classes = ({string *})SKILLSERVER->QueryClasses()||({});

  for (i=0;i<sizeof(classes);i++)
  {
    skills = ({string *})SKILLSERVER->QuerySkills(classes[i])||({});
    learned=0;
    msg_write(CMSG_GENERIC,"Training "+capitalize(classes[i])+" skills:\n");

    for (j=0;j<sizeof(skills);j++)
    {
       // Can this skill been learned
       if (({int})SKILLSERVER->CanLearnSkill(skills[j],TP))
       {
         start=({int})SKILLSERVER->QuerySkillStart(skills[j],TP);
         variance=start/10;  // 10% variance
         bonus=({int})SKILLSERVER->QuerySkillBonus(skills[j],TP);
         value=start+random(variance*2)-variance+bonus;
         learned++;
         msg_write(CMSG_GENERIC,"   - "+capitalize(skills[j])+" learned.\n");
      }
      else
      {
        value=0;
      }
      TP->SetSkill(skills[j],value);
    } // end j

    if (learned==0)
        msg_write(CMSG_GENERIC,"   Nothing learned.\n");
  } // end i


  TP->Set(P_ROLLEDSKILL,1);
  TP->Set(P_TRAINSKILL,SK_TRAIN_NO);

  return 1;
}

int cmd_train(string str)
{
  int amount,value;

  if(!str)
  {
    msg_write(CMSG_GENERIC,
      "Try 'train <skill>' e.g.'train throwing'.\n");
    return 1;
  }
  str=lower_case(str);
  if (!({int})SKILLSERVER->IsSkill(str))
  {
    msg_write(CMSG_GENERIC,
      "This is no skill.\n");
    return 1;
  }
  if (!({int})TP->Query(P_ROLLEDSKILL))
  {
    msg_write(CMSG_GENERIC,
      "You have not yet rolled your skills. 'roll skills' first.\n");
    return 1;
  }
  if (({int})TP->Query(P_TRAINSKILL)<=0)
  {
    msg_write(CMSG_GENERIC,
      "You have used up your trainings hours.\n");
    return 1;
  }

  value=({int})TP->QuerySkill(str);
  if (value==0)
  {
    msg_write(CMSG_GENERIC,
      "You cannot train that skill. It is no general skill of yours.\n");
    return 1;
  }
  amount=random(2*SK_TRAIN_AMOUNT)+1;
  if (value+amount>({int})SKILLSERVER->QuerySkillMax(str,TP))
  {
    msg_write(CMSG_GENERIC,
      "You cannot train this skill any more.\n");
    return 1;
  }
  TP->SetSkill(str,value+amount);
  TP->Set(P_TRAINSKILL,({int})TP->Query(P_TRAINSKILL)-1);
  msg_write(CMSG_GENERIC,
    "You learn %^BOLD%^%^GREEN%^"+ capitalize(str) +
    "%^RESET%^ a little better.\nYou have still "+
    ({int})TP->Query(P_TRAINSKILL)+" trainings hours left.\n");

  return 1;
}

int cmd_info(string str)
{
  string s;

  if(!str)
  {
    msg_write(CMSG_GENERIC,
      "Try 'info <skill>' e.g.'info throwing'.\n");
    return 1;
  }
  str=lower_case(str);
  if (!({int})SKILLSERVER->IsSkill(str))
  {
    msg_write(CMSG_GENERIC,
      "This is no skill.\n");
    return 1;
  }
  s=({string})SKILLSERVER->QuerySkillInfo(str)||"Nothing known about that skill.";
  msg_write(CMSG_GENERIC,
    "That's what I know about %^BOLD%^%^GREEN%^"+ capitalize(str) +
    "%^RESET%^:\n\n"+s);

  return 1;
}

int CheckAction( string action, string verb, string arg, int method )
{
  // TODO: Make this check more intelligent...
  if ("exit" == action && "north" == verb &&
      ({int})this_player()->Query(P_ROLLEDSKILL) ==0  )
  {
      notify_fail(
       "You must roll your skills before you may continue.\n",1000);
      return 0;
  }
  if (({int})this_player()->Query(P_TRAINSKILL) >0  )
      msg_write(CMSG_GENERIC,
       "You can still train some more skills (e.g. train throwing).\n\n");

  TP->Set(P_ROLLEDSKILL,0);
  return ::CheckAction(action, verb, arg, method);
}

public varargs void create()
{
  ::create();
  seteuid(getuid());
  SetIntShort("Skill Selection");
  SetIntLong(
  "After you have strengthened your muscles in the ship's gym\n"
  "you move along into the ship's arena. This is where you find\n"
  "people working on their skills. You decide to join them.\n"
  "\n"
  "You can:\n"
  "- roll skills           : Get a set of skills\n"
  "- skills                : Show your current skills\n"
  "- train <skill>         : Improve a certain skill\n"
  "- info <skill>          : Show information about a skill\n"
  "\n"
  "After accepting a set of skills proceed to the north to continue with your "
  "character generation.\n"
  );

  SetIndoors(1);
  SetIntLight(50);
  Set(P_REGION,REGION_DREAM);
  Set(P_TEMPERATURE,20);
  Set(P_COORDINATES,({ ({0,400,0}),C_LOGIN }) );

  AddRoomCmd("roll","cmd_roll");
  AddRoomCmd("train","cmd_train");
  AddRoomCmd("info","cmd_info");

  // move back to the beginning
  AddExit("restart","../entrance");
  AddExit("return",LAST_ROOM);
  AddExit("north",NEXT_ROOM);
  CheckExit("north", DACT_CHECK);

  AddDetail("people","You can see many people training various skills.\n");
}



