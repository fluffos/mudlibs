// Royal Guard in the Palace of Silvere
// created by Taurec [11-May-98]

// TODO: Change names of the guards
// TODO: The sword desc, make it work.

#include <properties.h>
#include <macros.h>
#include <combat.h>
#include <npc.h>
#include <silvere.h>
#include <path.h>

inherit "/std/npc";

string choose_name(){
  string *names,name;
  names=({"fartigon","pollan","lance","castron","alan","fionn",
          "cocharno","indrian","helidar","wendar","cryol",
          "darlok","maniel","linus"});
  do {
    name=random_select(names);
    names-=({name});
  } while (find_living(name)&&(sizeof(names)));
  return CAP(name);
}

void create()
{
  seteuid(getuid());
  ::create();
  Set(P_LEVEL,20);
  Set(P_GENDER,GENDER_MALE);
  Set(P_NAME,choose_name());
  Set(P_RACE, "human");
  Set(P_ALIGN, 100);
  Set(P_IDS,({"guard","soldier"}));
  Set(P_ADS,({"royal","fierce","sturdy"}));
  Set(P_SHORT,CAP(NAME(TO))+", a royal guard");  
  Set(P_LONG,CAP(NAME(TO))+" looks like a huge mountain of steel and "
   "muscles, uppishly looking down on you with an arrogant glance. "
   "Colorful feathers are crowning his helmet, giving him an air of a "
   "proud cock :) "+CAP(HESHE(TO))+
   " seems to be quite selfconfident and he's surely "
   "aware of that most people watch "+HIMHER(TO)+" with much respect. "
   "This guard is a bold soldier whose loyalty can't be bribed "
   "by anything.\n"); 
  Set(P_MSGOUT,({"walks","Someone walks"}));
  Set(P_SMELL,CAP(HESHE(TO))+" smells of sweat coming from very much "
   "training lessons.\n");
  Set(P_NOISE,"Every movement, even the slightiest, is accompanied by "
   "the clattering noise of steel against steel.\n");

  Set(P_GO_CHANCE,0);

// *** EQUIPMENT ***
  AddItem(WEAPONS("sil_rgsword"), REFRESH_REMOVE, 
    ([P_LONG:  
      "This beautiful blade is made of the finest steel, glittering "
      "brightly in the light. On the hilt, there is an emblem "
      "that shows the four griffins, the insignia of the royal house of "
      "Lu'Meyn. The name of the possessor is engraved on the blade with "
      "sinous letters that show: "+CAP(NAME(TO))+".\n"
     ]), SF(wieldme));
  AddItem(ARMOUR("sil_rgarmour"), REFRESH_REMOVE, SF(wearme));
  AddItem(ARMOUR("sil_rghelmet"), REFRESH_REMOVE, SF(wearme));
  AddItem(ARMOUR("sil_rgtowshield"), REFRESH_REMOVE, SF(wearme));

// *** CHAT SETTINGS ***
  Set(P_CHAT_CHANCE,2);
  Set(P_CHATS,({
    NAME(TO)+" watches you suspiciously.\n",
    NAME(TO)+" stares at the wall attentively.\n",
    NAME(TO)+" checks his swordbelt with an accurate movement.\n",
    NAME(TO)+" says: What's your business here? Speak up!\n",
    NAME(TO)+" does some shadowfighting with his sword.\n",
    NAME(TO)+" grinds his blade with a grindstone.\n",
    NAME(TO)+" salutes to you and says: Long live Lu'Meyn, our"
             " splendid leader!\n",
    NAME(TO)+" tries to appear very impressively.\n"
  }));
}

varargs void Die(int silent)
{
  tell_room(environment(),"The guard trembles, spits some blood and falls "
   "to the floor. With the concentrated energy left in him he screams: "
   "MAY THE WRATH OF LU'MEYN DESTROY YOU!!!\n");
  ::Die(silent);
}




