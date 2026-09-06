
#include <properties.h>
#include <ansi.h>
#include <races.h>
#include <rooms.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL
#define TP      this_player()

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Race Selection");
  SetIntLong(
   "Now you'll choose a race.  Pretty much what this is entails is "
   "deciding what kind of attributes you wish your character to have, "
   "at least in the beginning.  Some races are better at magic, while "
   "others are better physically, for example, better at withstanding "
   "heavy blows from enemy attack. Some are a good blend of each, kind "
   "of the all-around good race.\n "
   "\n"
   "First you should read about the races we offer. Type 'info races' "
   "to see the list. Then use 'info <race name>' to learn more about "
   "a specific race, for example 'info elf'.\n"
   "\n"

   "When you have decided on a race, type 'select race <race name'> "
   "to select the race that you want. For example, 'select race elf' "
   "will make you an elf.\n"
   );


  AddExit("north","./room06");
  AddExit("south","./room04");
  CheckExit("north", DACT_CHECK);

  SetIndoors(1);

  AddRoomCmd("select", "do_race_select");
  AddRoomCmd("info", "cmd_info");

}

// took this from Frank for now...

string *QueryRacenames()
{
  string *rn;

  rn =  ({string *}) RACEMASTER->AllRaceNames();
  rn -= regexp(rn,"^visitor$");
  // these races should not occur in any list and the player should not
  // be able to morph into them
  return rn;
}

public int cmd_info(string str)
{
  string res;

  if (!str)
  {
    write(
      "Every player needs to select a race. We have a lovely selection "
      "for you to pick from - just type 'info races' to see the list.\n");
    return 1;
  }

  if(str == "race" || str == "races")
  {
    write(
      "We can offer you a selection of the finest races available in the "
      "multiverse, including:\n" +
       sprintf("    %-*#s\n",40, implode(
                    sort_array(map(QueryRacenames(), #'capitalize /*'*/), #'> /*'*/)
                     , "\n") ) +
      "For more information about a specific race, please type 'info <race>'. "
      "To select a race, type 'select race <race>'.\n");
    return 1;
  }

  if ( (member(QueryRacenames(),lower_case(str) ) == -1 ) ||
      ( !res = ({string})RACEMASTER->RaceDescr(lower_case(str)) ) )
  {
      notify_fail(
       "Well, " + str + " sounds like a lovely race, but I'm afraid that's "
       "not on the menu today. Please make another selection.\n");
      return 0;
   }

  write (" -- The "+capitalize(str)+" Race --\n" + res);
  return 1;
}

int do_race_select(string str)
{
  string race;

  if (!str || sscanf(lower_case(str), "race %s", race) != 1)
  {
    notify_fail("Please type 'select race <race>' to select a race.\n");
    return 0;
  }

  if (member(QueryRacenames(), race) == -1 ||
      (!({object})RACEMASTER->RaceObject(race)))
  {
     notify_fail(
      "Well, " + str + " sounds like a lovely race, but I'm afraid that's "
      "not on the menu today. Please make another selection.\n");
     return 0;
  }

  if (race == ({string})TP->QueryRace())
  {
     notify_fail(
      "How droll, you already happen to be " + add_a(race) + ".\n");
      return 0;
  }

  // this was in Frank...dunno why though...
  if (sizeof(({object *})TP->Query(P_WEAPONS)))
    TP->command_me("unwield all");
  if (sizeof(({object *})TP->Query(P_ARMOURS)))
    TP->command_me("unwear all");

  TP->SetGhost(0);
  RACEMASTER->InitRace(TP, race);
  RACEMASTER->AdjustStats(TP);
  TP->SetLevel(1);
  // rdata = RACEMASTER->RaceData(race, TP); -> used for the portals

  TP->SetHP(({int})TP->QueryMaxHP());
  //TP->SetFood(TP->QueryMaxFood());
  //TP->SetDrink(TP-TP>QueryMaxDrink());
  TP->SetAlcohol(0);

  // TP->SetHome(home);
  // RACEMASTER->EquipPlayer(TP);

  write("Your body slowly takes on a new form...\n");
  return 1;
}

// This makes sure we have chosen a race before we go north

int CheckAction( string action, string verb, string arg, int method )
{

  if("exit" == action && "north" == verb &&
      ({string})this_player()->Query(P_RACE) == "visitor" )
  {
    notify_fail("You must select a race before you may continue.\n",1000);
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

