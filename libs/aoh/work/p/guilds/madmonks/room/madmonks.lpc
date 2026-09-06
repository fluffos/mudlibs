// Madmonks Guild
// made by Balgarion & MagicTCS

#include <guild.h>
#include "/p/guilds/madmonks/madmonks.h"

inherit G_GUILDOFFICE;

#include <rooms.h>
#include <guild.h>
#include <skills.h>
#include <config.h>

#ifdef ONESTEPBEYOND
#include <secure/wizlevels.h>
#else
#include <wizlevels.h>
#endif

#include <moving.h>

//********************
// notify the entering
//********************
public void notify_enter(mixed from,int method,mixed extra)
{
  ::notify_enter(from,method,extra);       // because returns void
  if (!interactive(PO)) return;
  tell_object(PO,"You enter the dojo and nod your head.\n");
}

//*****************************************************************
// give a description of all guild related functions available here
//*****************************************************************
string readsign() {
  return
  "You may use the following commands in here:\n"
  "join, message, title and correct.\n"
  "To get help about any of these commands type 'help <topic>'.\n"
  "You may get help about 'minstats' and 'maxstats', too.\n"
  "The creators of this guild are: Balgarion, Magictcs.\n"+
  (IS_IMMORTAL(TP)?"You may use the 'guild'-command in here. Just type\n"+
  "'guild help' to see its effects.\n"
    :"");
}

string lookflag() {
  return
  "+----------------------------+\n"
  "|                            |\n"
  "|        _a@@@@@@@a_         |\n"
  "|       d@@@@@@@@@@@b        |\n"
  "|      d@@@@@@@@@@@@@b       |\n"
  "|      @@@@@@@@@@@@@@@       |\n"
  "|      @@@@@@@@@@@@@@@       |\n"
  "|      Y@@@@@@@@@@@@@P       |\n"
  "|       Y@@@@@@@@@@@P        |\n"
  "|        ~@@@@@@@@@~         |\n"
  "|                            |\n"
  "+----------------------------+\n";
}

//********************************
// overload the guild help command
//********************************
// TODO: isn't working correctly!!
int cmd_help(string str) {
  if (!str)
    return (int)notify_fail("Help about what?\n",NOTIFY_NOT_OBJ)&&0;
  if (member(({"advance","banish","unbanish"}),lower_case(str))!=-1) {
    notify_fail("There's no help available about '"+str+"'.\n",
                NOTIFY_ILL_ARG);
    return TP->InformHelp(TP,str);
  }
  return ::cmd_help(str);
}

public void create() {
  ::create();
  /* description and details */
  SetIntShort("Dojo of the MADMONKS");
  SetIntLong(
    "This is a very impressive building! The floor is made of wood and the\n"
    "walls of wood and paper. Several list of papyrus are hanging on one of\n"
    "the paper walls. On another wall can be seen the traditional flag of\n"
    "Japan - a red filled circle on a white ground.\n"
    "There is a big sign which you read: \"Type 'join' to join this guild\".\n"
    "Another sign is above the flag: \"Take the way of honour! We can teach\n"
    "the art of fighting with bare hands or some special weapons.\n"
    "And we would be glad to have you as a member of this famous guild\n"
    "the guild of the MADMONKS.\"\n");
  AddDetail(({"list of papyrus","papyrus"}),
    "They are very old and not so interesting.\n");
  AddReadMsg(({"list of papyrus","papyrus"}),
    "You can't read the old papyrus, because you don't understand the\n"
    "foreign language.\n");
  AddDetail("flag",#'lookflag);
  AddDetail(({"wood","oak","oak wood","oak planks","planks","plank",
    "oak plank"}),
    "The floor is made of oak planks. But the walls consist of some\n"
    "wood too.\n");
  AddDetail(({"paper","brown paper","old paper","old brown paper"}),
    "Yes old and brown - the paper used in all japanese houses.\n");
  
  ChangeSign(({"plate","small plate"}),"not needed!","A small plate ");
  RemoveDetail(({"sign","wooden sign"}));         // standard sign
  RemoveReadMsg(({"sign","wooden sign"}));        // read msg for it
  AddDetail(({"plate","small plate","silver plate","small silver plate"}),
    "A small plate made of pure silver, you can read it.\n");
  AddReadMsg(({"plate","small plate","silver plate","small silver plate"}),
    #'readsign);

  /* guild specific */
  SetGuildfile(GUILD("log/madmonks"));
  SetGuildname(GC_MADMONKS);
  SetGuildclass(GC_MADMONKS);
  SetGuildobject(GUILDOBJ2);
  AddVotingbox();
//  SetSavefile(GUILD("log/madmonk.votes"));        // voting box
  AddMinStat(P_INT,2); AddMaxStat(P_INT,17); AddMaxHLPStat(P_INT,25);
  AddMinStat(P_DEX,3); AddMaxStat(P_DEX,18); AddMaxHLPStat(P_DEX,25);
  AddMinStat(P_CON,3); AddMaxStat(P_CON,18); AddMaxHLPStat(P_CON,25);
  AddMinStat(P_STR,4); AddMaxStat(P_STR,19); AddMaxHLPStat(P_STR,28);
// AddMinStat(P_CHA,7); AddMaxStat(P_CHA,20); AddMaxHLPStat(P_CHA,30);
// AddMinStat(P_GNO,4); AddMaxStat(P_GNO,16); AddMaxHLPStat(P_GNO,23);
  SetCreators(({"Balgarion","Magictcs"}));
  SetIndoors(1);
  AddLevelTitles( 1,"the new member of the madmonks guild");
  AddLevelTitles( 2,"the very clumsy madmonk beginner");
  AddLevelTitles( 3,"the clumsy madmonk");
  AddLevelTitles( 4,"the learner of karate");
  AddLevelTitles( 5,"the small madmonk");
  AddLevelTitles( 6,"the good madmonk");
  AddLevelTitles( 7,"the better karate fighter");
  AddLevelTitles( 8,"the very good karate fighter");
  AddLevelTitles( 9,"the very skillful karate fighter");
  AddLevelTitles(10,"the most skillful karate fighter");
  AddLevelTitles(11,"the dangerous madmonk");
  AddLevelTitles(12,"the very dangerous fighter");
  AddLevelTitles(13,"the user of the flying fists");
  AddLevelTitles(14,"the skillfuller karate fighter");
  AddLevelTitles(15,"the deadly killer");
  AddLevelTitles(16,"the very deadly killer");
  AddLevelTitles(16,"the wellknown madmonk");
  AddLevelTitles(17,"the honest madmonk");
  AddLevelTitles(18,"the killer with the honest soul");
  AddLevelTitles(19,"the glorious winner of some tournaments");
  AddLevelTitles(20,"the master on the way of open hands");

  /* exits */
  AddExit("north",MONKROOM("depot"));
  AddExit("east","/d/wasteland/common/room/plain/pass2");
  AddExit("west",MONKROOM("statstrain"));
  AddExit("south",MONKROOM("shop"));

  /* items */
  AddItem("/std/board",REFRESH_HOME,
   ([P_SHORT:"The Central Player Board",
     P_LONG:
       "This board is connected to the central player board of OSB.\n",
     "Groups":({"players","players.([^h]\\.*|(h[^l]\\.*|hl[^p]\\.*))"})
   ]));

  /* commands */
  AddRoomCmd("wjoin",#'cmd_join);         // wizard join!
  RemoveRoomCmd(({"banish","unbanish","advance","cost","list"}));
// AddRoomCmd("list",#'listminstats....);
}

