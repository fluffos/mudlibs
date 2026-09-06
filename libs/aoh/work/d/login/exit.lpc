//---------------------------------------------------------------------------
// Last room of the login procedurte for new players in OSB
//
// (c) Softbyte@OSB 10nov97
// [Softbyte] 10nov97   : Creation and basic functions
// [Mordrid] 14dec97    : Ship Description and Exits
// [Softbyte] 03feb98   : Colours
//
// TODO:  Details and long description
//
//---------------------------------------------------------------------------

#include <rooms.h>
#include <regions.h>
#include <coordinates.h>
#include <properties.h>
#include <macros.h>
#include <moving.h>
#include <msgclass.h>
#include <stdrooms.h>

inherit "/std/room";

int cmd_play(string str)
{
    msg_write(CMSG_GENERIC,
      "The captain gives you a couple of things ...\n");
    RACEMASTER->EquipPlayer(this_player());
    msg_write(CMSG_GENERIC,
     "...and then suddenly...\n");

    TP->move(STARTROOM,M_SPECIAL,({
    "is thrown overboard by the Captain",
    "climbs out of the cold water and jumps onto the street",
    "give the Captain your answer, with that he rushes toward you,\n"
    "picks you up,\n"
    "and throws you off the side of the ship. You fall into the cold water\n"
    "and barly manage to swim toward the shore.\n"
    "%^BOLD%^%^RED%^Enjoy your time in OSB!%^RESET%^",
    }));

    return 1;
}

public varargs void create()
{
  ::create();
  SetIntShort("One Step before entering One Step Beyond");
  SetIntLong(
  "After training your skills you wander around for a while and\n"
  "manage to find a stairway leading up. When you emerge, you see\n"
  "fog all around you. Somehow you sense that you aren't in a normal\n"
  "ship...\n"
  "The captain walks up to you and says, 'So, are you ready to %^BOLD%^%^GREEN%^'play'%^RESET%^\n"
  "or shall you %^BOLD%^%^GREEN%^'restart'%^RESET%^ and make a new character?\n"
  "\n");

  SetIndoors(1);
  SetIntLight(50);
  Set(P_REGION,REGION_DREAM);
  Set(P_TEMPERATURE,20);
  Set(P_COORDINATES,({ ({0,10000,0}),C_LOGIN }) );

  AddExit("play",#'cmd_play /*'*/, STARTROOM);
  AddExit("restart","./entrance");
  HideExit("restart",HIDE_ALWAYS);
  HideExit("play",HIDE_ALWAYS);
}



