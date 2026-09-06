// drunken sailor in the harbour of Silvere
// created by Taurec [2-1-98]

// TODO:  Why is there a ghost when Sailor is killed?
// SOMETHING IS WRONG WITH THE AddAlcohol Fun

#include <properties.h>
#include <attributes.h>
#include <macros.h>

inherit "/std/npc";

int smell_me(string str)
{
  int currentalc;
  if (!TP) return 0;
  if (!str) return 0;
  if (!environment()) return 0;
  if ((strstr(lower_case(str),"sailor")==-1) &&
      (strstr(lower_case(str),"rednose")==-1) &&
      (strstr(lower_case(str),"seastorm")==-1)) return 0;
  currentalc = ({int})TP->Query(P_ALCOHOL);
  if (currentalc < 50) TP->AddAlcohol(10);
  write("Eeew, the strong smell of alcohol enters your nose. "
        "You start to feel dizzy.\n");
  show_room(environment(TO),CAP(NAME(TP))+" sniffs at the drunken "
    "sailor and turns up "+HISHER(TP)+" nose.\n",
    "You hear someone sniffing.\n",({TP}));
  return 1;
}

void create()
{
  ::create();
  Set(P_LEVEL,10);
  Set(P_GENDER,GENDER_MALE);
  Set(P_NAME,"Rednose");
  Set(P_RACE, "human");
  Set(P_ALIGN, 100);
  Set(P_IDS,({"sailor","sailorman","rednose",
              "seastorm","rednose seastorm"}));
  Set(P_ADS,({"drunken","strong"}));
  Set(P_SHORT,"Rednose Seastorm, the always drunken sailor");
  Set(P_LONG,"Short thick legs, powerful muscular arms, a barrel-like "
    "chest and hands that are used to pull heavy ropes, anchor-chains "
    "and other things tell you that this is a man who calls the sea "
    "his home. Rough weather and sunheat left their traces in his face. "
    "His cheeks and the nose are red from too much rum. He's "
    "surely a neat guy, with laughter lines around the eyes and mouth, "
    "but only when he's not in a drunken stupor. And that's rare indeed.\n");
  Set(P_NOISE,"He babbles, sings, hickups, burps and shouts.\n");

// *** ALCOHOL SETTINGS ***
  Set(A_MAX_ALCOHOL,500);
  Set(A_ALCOHOL,500);
  Set(A_DEG_ALCOHOL,1);
  Set(A_RATE_ALCOHOL,5);

// *** CHAT SETTINGS ***
// TODO:  What if player is invis?
  Set(P_CHAT_CHANCE,10);
  Set(P_CHATS,
    ({"Rednose utters: Damn, m-my bo-bottle is almossss ehh empty!\n",
      "Rednose stares dully at you and says: Wassup? Cocomeon, "
      "lesss d-drink somethin' together!\n",
      "Rednose watches you with an unsteady glance and shouts: "
      "Hey ya, have you got anythi..thing fffine to drrrink for me?\n",
      "Rednose says to himself: Oh I llllike those high-per... "
      "percen... damn whatwasss tha word? Wellll ya know, "
      "I mmmean that gutssskilling stuff!\n",
      "Rednose sings: Heey hoo and a bottle of RUM!\n",
      "Rednose sings: Whatcha shall we do with the drunken sssailor...\n",
      "Rednose stumbles and almost falls into the water.\n",
      "Rednose puts the bottle to his mouth and takes a long sip.\n",
      "Rednose pets his bottle and murmurs: \"Baby, youu are "
      "ssss.. ssss.. the bessst!\"\n"}));
}

void init()
{
  ::init();
  add_action("smell_me","smell");
}

varargs void Die(int silent)
{
  tell_room(environment(this_object()),"The sailorman stumbles, drops "
    "his precious bottle of rum and finally whispers with his last "
    "breath: \"I h..hope th-they've got rrrummm u- up there in "
    "heav.. heave.. heaven...\". Then he closes his eyes forever.\n");
  ::Die(silent);
}


