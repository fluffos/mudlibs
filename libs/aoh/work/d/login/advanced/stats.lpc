//---------------------------------------------------------------------------
// Advanced stats configuration room for OSB
//
// (c) Softbyte@OSB 10nov97
// [Softbyte] 10nov97   : Creation and standard functions
// [Mordrid] 14dec97    : Ship Descriptions and Exits
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

#define NEXT_ROOM  "/d/login/advanced/skills"
#define LAST_ROOM "/d/login/advanced/gender"
#define A_SHIFTSTAT  "ShiftStat"
#define P_ROLLEDSTAT "RolledStat"

// Set the stats in who

private int SetStats(object who,int *stats)
{
  int i;
  if (!who || !stats || sizeof(stats)!=NUMBER_STATS) return 0;
  for (i=0;i<NUMBER_STATS;i++)
  {
     who->SetAttr(STATS[i],stats[i]);
  }
  return 1;
}

// read out the stats of who
private int *GetStats(object who)
{
  int *stats;
  int i;
  if (!who) return 0;
  stats=allocate(NUMBER_STATS);
  for (i=0;i<NUMBER_STATS;i++)
  {
     stats[i]=({int})who->QueryAttr(STATS[i]);
  }
  return stats;
}

int cmd_show(string str)
{
  int *stats;
  int i,shift;
  int hp,sp,pep,mep;
  int *semi;

  if (!str || -1==member(({"stat","stats","statistics"}),str) )
    return notify_fail("Show what?\n");
  // It is intentional NOT to use notify_fail here
  if (!({int})this_player()->Query(P_ROLLEDSTAT))
  {
    msg_write(CMSG_ERROR,
    "You have not yet rolled your stats...please 'roll stats' first.\n");
    return 1;
  }
  stats=GetStats(this_player());
  shift=({int})this_player()->Query(A_SHIFTSTAT);
  msg_write(CMSG_GENERIC,
  "... your stats would be (average stat is "+STAT_AVERAGE+"):\n");

  msg_write(CMSG_GENERIC,({string})L_STR->mkstr(78,"-=")+"\n");
  for (i=0;i<NUMBER_STATS;i++)
  {
     msg_write(CMSG_GENERIC,
     sprintf("%-3.3s: %3d   ", STATS[i],stats[i]));
     this_player()->SetAttr(STATS[i],stats[i]);  // TODO remove
  }
  msg_write(CMSG_GENERIC,"\n");

  semi=({int *})this_player()->CalculateSemiStats(1);
  if (semi && sizeof(semi)==4)
  {
     hp=semi[0];
     sp=semi[1];
     pep=semi[2];
     mep=semi[3];
  }

  msg_write(CMSG_GENERIC,"\n"+
    "       "+
    sprintf("HP (hitpoints) : %3d      PEP (physical endurance): %3d\n",
	  hp,pep)+
    "       "+
    sprintf("SP spellpoints): %3d      MEP (mental endurance)  : %3d\n",
	  sp,mep));
  msg_write(CMSG_GENERIC,({string})L_STR->mkstr(78,"-=")+"\n");

  if (shift>1)
    msg_write(CMSG_GENERIC,
     "You can shift your stats "+shift+" more times.\n");
  else if (shift>0)
    msg_write(CMSG_GENERIC,
     "You can shift your stats one more time.\n");
  else
    msg_write(CMSG_GENERIC,
     "You can't shift your stats anymore.\n");

  return 1;
}


int cmd_roll(string str)
{
  int i,diff,rnd,cnt;
  int *stats;

  if (!str || -1==member(({"stat","stats","statistics"}),str) )
    return notify_fail("Roll what?\n");

  stats=allocate(NUMBER_STATS);
  cnt=0;

  do   // loop over reasonable stats
  {
	diff=0;
	for (i=0;i<NUMBER_STATS-1;i++)
	{
	  rnd=random(STAT_VARIANCE*2)-STAT_VARIANCE;
	  stats[i]=STAT_AVERAGE+rnd;
	  diff+=rnd;
	}

	stats[NUMBER_STATS-1]=STAT_AVERAGE-diff;
	cnt++;
	if (cnt>20)
	{
	  return notify_fail(
      "Strange, cannot roll your stats...Report this as a bug and try again.\n");
	}

  } while(diff>STAT_VARIANCE || diff<-STAT_VARIANCE);


  this_player()->Set(A_SHIFTSTAT,STAT_SHIFT_NO);  //  shifts
  this_player()->Set(P_ROLLEDSTAT,1);             // rolled
  SetStats(this_player(),stats);
  msg_write(CMSG_GENERIC,
  "%^BOLD%^%^GREEN%^You roll the dice ...%^RESET%^\n");
  cmd_show("stats");  // show the stats as well
  msg_write(CMSG_GENERIC,
  "\nType 'accept stats' to get this as your personal stats in OSB or\n"
  "type 'shift <stat-> <stat+>' to change some stat values.\n");

  return 1;
}

int cmd_accept(string str)
{
  int *stats;
  int i;
  int hp,sp,pep,mep;
  int *semi;

  if (!str || -1==member(({"stat","stats","statistics"}),str) )
    return notify_fail("Accept what?\n");
  if (!({int})this_player()->Query(P_ROLLEDSTAT)) return notify_fail(
    "You have not yet rolled your stats...please 'roll stats' first.\n");

  stats=GetStats(this_player());

  msg_write(CMSG_GENERIC,
  "\n%^BOLD%^%^GREEN%^We are now going to fix your stats...%^RESET%^\n");
  for (i=0;i<NUMBER_STATS;i++)
  {
     msg_write(CMSG_GENERIC,
	 "Your "+STATS[i]+" will be "+stats[i]);

	 if (stats[i]<=STAT_AVERAGE-STAT_VARIANCE*2/3)
       msg_write(CMSG_GENERIC,"%^ORANGE%^ ... which is quite low actually%^RESET%^\n");
	 else if (stats[i]>=STAT_AVERAGE+STAT_VARIANCE*2/3)
      msg_write(CMSG_GENERIC," %^ORANGE%^... far above average%^RESET%^\n");
	 else
       msg_write(CMSG_GENERIC,"\n");
  }
  msg_write(CMSG_GENERIC,"\n");

  semi=({int *})this_player()->CalculateSemiStats(1);
  if (semi && sizeof(semi)==4)
  {
     hp=semi[0];
     sp=semi[1];
     pep=semi[2];
     mep=semi[3];
  }

  msg_write(CMSG_GENERIC,
    sprintf("HP (hitpoints) : %3d   PEP (physical endurance): %3d\n",
	  hp,pep)+
    sprintf("SP spellpoints): %3d   MEP (mental endurance)  : %3d\n",
	  sp,mep));

   this_player()->SetSP(sp);
   this_player()->SetHP(hp);
   this_player()->SetPEP(pep);
   this_player()->SetMEP(mep);
   /*
   this_player()->SetMaxSP(sp);
   this_player()->SetMaxHP(hp);
   this_player()->SetMaxPEP(pep);
   this_player()->SetMaxMEP(mep);
   */

   msg_write(CMSG_GENERIC,"\n");
  this_player()->Set(A_SHIFTSTAT,0);  // no more shifts
  this_player()->Set(P_ROLLEDSTAT,0);  // not yet rolled
  return 1;
}


// Shift one stat to another if there are shift points left
int cmd_shift(string str)
{
  int *stats;
  int shift,l,h;
  int amt;
  string statL,statH;

  if (!str || 2!=sscanf(str,"%s %s",statL,statH) )
    return notify_fail("Shift what to what?\n");
  // It is intentional NOT to use notify_fail here
  if (!({int})this_player()->Query(P_ROLLEDSTAT))
  {
    msg_write(CMSG_ERROR,
    "You have not yet rolled your stats...please 'roll stats' first.\n");
    return 1;
  }

  stats=GetStats(this_player());
  shift=({int})this_player()->Query(A_SHIFTSTAT);
  if (shift<1)
  {
    msg_write(CMSG_ERROR,
    "You have used up your possibility to shift stats. Reroll them or "
	"accept them.\n");
    return 1;
  }

  statL=capitalize(lower_case(statL));
  statH=capitalize(lower_case(statH));
  l=member(STATS,statL);
  h=member(STATS,statH);

  if (l<0) return notify_fail(
    capitalize(statL)+" is no valid stat.\n");
  if (h<0) return notify_fail(
    capitalize(statH)+" is no valid stat.\n");

  if (l==h) return notify_fail(
    "This makes not much sense to me...\n");

  // shift by this amount
  amt=STAT_SHIFT_AMT/2+random(STAT_SHIFT_AMT);
  if (stats[l]-amt < 0) return notify_fail(
    "Sorry, can't do that as "+capitalize(statL)+" would get below zero.\n");
  if (stats[h]+amt > STAT_MAX) return notify_fail(
    "Sorry, can't do that as "+capitalize(statH)+" would get too high.\n");
  stats[l]-=amt;
  stats[h]+=amt;
  shift--;

  msg_write(CMSG_GENERIC,
  "\n%^BOLD%^%^GREEN%^You raise "+capitalize(statH)+" by "+amt+" at the cost of "+
  capitalize(statL)+".%^RESET%^\n");

  // write back to the player
  SetStats(this_player(),stats);
  this_player()->Set(A_SHIFTSTAT,shift);

  cmd_show("stats");  // show the stats as well

  return 1;
}

// Is the player allowed to leave the room?
int CheckAction( string action, string verb, string arg, int method )
{
  // TODO: MAke this check more intelligent...
  if("exit" == action && "north" == verb
      && ( (({int})this_player()->QueryAttr("Cha") <=1 )
           || ({int})this_player()->Query(P_ROLLEDSTAT) ) )
  {
    notify_fail(
     "You must 'roll' and 'accept' your stats before you may continue.\n",1000);
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

public varargs void create()
{
  ::create();
  SetIntShort("Stats choosing");
  SetIntLong(
  "As you walk into the ship's gym, you notice many machines\n"
  "designed to build your different muscles (including your brain).\n"
  "You see other people using the machines and decided to join in.\n"
  "This is where you will choose your stats, choose carefully.\n"
  "\n"
  "You can:\n"
  "- roll stats            : Get a set of stats\n"
  "- show stats            : Show the current stats\n"
  "- accept stats          : Accept the current stats as your personal stats.\n"
  "- shift <stat-> <stat+> : Raise the second stat on cost of the first\n"
  "\n"
  "After accepting a set of stats proceed to the north to continue with your "
  "character generation.\n"
  );

  SetIndoors(1);
  SetIntLight(50);
  Set(P_REGION,REGION_DREAM);
  Set(P_TEMPERATURE,20);
  Set(P_COORDINATES,({ ({0,300,0}),C_LOGIN }) );

  AddRoomCmd("roll","cmd_roll");
  AddRoomCmd("show","cmd_show");
  AddRoomCmd("accept","cmd_accept");
  AddRoomCmd("shift","cmd_shift");

  // move back to the beginning
  AddExit("restart","../entrance");
  AddExit("return",LAST_ROOM);
  AddExit("north",NEXT_ROOM);
  CheckExit("north", DACT_CHECK);

  AddDetail(({"machine","machines","gym"}),
  "You see many machines working the different muscles of the body. "
  "There are people using many of them.\n");
  Set(P_INT_SMELL, "You can smell the sweat forming on your brow.\n");
}


