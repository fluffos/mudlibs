/* The great timetable in Nightfall City Harbour */

#include <moving.h>
#include <properties.h>
#define ROOM_PATH  "/d/archwiz/common/room/port/"

inherit "std/thing";

string *quays;

int AddQuay(string str)
{
  if(catch(call_other(str,"???"))) return 0;
  if(member(quays, str) == -1) quays += ({str});
  return sizeof(quays);
}

void create()
{
  ::create();
  seteuid(getuid(this_object()));
  Set(P_IDS,({"table","timetable","time table","time-table"}));
  SetShort("The central time-table stands here");
  SetLong("This is the central time-table of the harbour of Nightfall City.\n");
  SetNoGet("It is secured at the ground.\n");
  quays = ({});
  AddQuay(ROOM_PATH + "quai1");
  AddQuay(ROOM_PATH + "quai2");
  AddQuay(ROOM_PATH + "quai3");
  AddQuay(ROOM_PATH + "quai4");
  AddQuay(ROOM_PATH + "quai5");
  AddQuay(ROOM_PATH + "quai6");
}

void init()
{
  ::init();
  if(living(environment())) move(environment(environment()),M_SILENT,0);
  add_action("table_look","read");
  add_action("table_look","exa");
  add_action("table_look","look");
  add_action("table_look","l");
}

int table_look(string str)
{
  mixed *ships;
  int i,j;
  if(!str) return 0;
  if((query_verb() == "l" || query_verb() == "look") && str[0..2] == "at ")
    str = str[3..];
  if(present(str) != this_object()) return 0;
  if(!sizeof(quays))
  {
    notify_fail("The table is empty.\n");
    return 0;
  }
  write(
"The central time-table of all ships servicing the Nightfall City Harbour\n" +
"------------------------------------------------------------------------\n");
  for(i=0;i<sizeof(quays);i++)
  {
    ships = ((mixed*)call_other(quays[i],"QueryTable"))[0];
    for(j=0;j<sizeof(ships);j++)
    {
      if(ships[j])
      {
        if(!j) write("Quay " + (i<9?" ":"") + (i+1) + ": ");
        else write("         ");
        write(ships[j]->QueryShort() + "\n");
      }
    }
  }
  return 1;
}

QueryQuays()
{ return quays; }
