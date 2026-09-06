// made by MagicTCS 09 march 97
// part of the eatcorpse quest
// updated on 8 jun 97
// TODO: if (say "I'm finished) then move josie to inner city (into house of
// TODO: Hurxel), wait there for 30 mins for the player
// TODO: if player comes there - set quest and vanish, if not in the next 30
// TODO: mins -> remove her.

#include <rooms.h>
#include <moving.h>
#include <combat.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <sykorath.h>

#define QLOG "magictcs/eatcorpse.log"

#define QUESTNAME "eatcorpse"

inherit "/std/npc";

int shrug;
string old_question;

// new shrug function :))
string do_shrug(string str) {
  if (old_question==str)
    return "Josie says: Hey I'm not stupid - you asked me that already!\n";
  old_question=str;
  // log questions: without answers
  log_file(QLOG,TP->QueryRealName()+
    " asks about "+str+"\n");
  switch (shrug) {
    case 0:
      shrug++;
      return "Josie says: Mmmh I didn't heared something about it.\n";
    case 1:
      shrug++;
      return "Josie shakes her head - I doesn't know anything about it.\n";
    case 2:
      shrug++;
      return "Josie murmurs some unknown gnomish words.\n";
    case 3:
      shrug++;
      return 
      "Josie says: Mmmh - maybe you should try to ask someone else?\n";
    default:
      shrug=0;
      return "Josie shrugs helplessly.\n";
  }
}

// called by solving the quest
void remove_me() {
  object ob;
  ob=present("amulet");
  if (ob) ob->remove();
  remove();
}

catch_tell(string str) {
  int num,killed;
  string name,what;
  if (sscanf(str,"%s says: %s",name,what)==2) 
  if (what=="I'm finished\n" || what=="i'm finished\n" || 
     what=="I am finished\n" || what=="i am finished\n") {
    num=TP->Query("NUMCORPSES");   // eaten corpses
    if (num >= 20) {
      if (!QUESTMASTER->QueryQuestSolved(QUESTNAME,TP)) {
//        QUESTMASTER->SetPlayerQuest(QUESTNAME,TP);
        QUESTMASTER->qshout("Josie is very happy that "+NAME+
        " cleaned the green forest.\n");
        write(
        "Josie thanx you with a big hug and gives some questpoints to you.\n"
        "And Josie vanishes into the forest.\n");
      }
      else {
        write("Josie thanks you for your help and vanishes into the forest.\n");
      }
      call_out("remove_me",1);
    } else {
      killed=TP->Query("KILLEDCORPSES");   // killed bears
      if (killed!=0) {
        if (num!=0) {
          write("Josie says: Oh there are some bears left. I'm afraid of the "
                "bears.\n");
          show("Josie speaks with "+NAME+".\n");
          return;
        }
        write(
          "Josie says: Oh you killed some bears. But what have you done with\n"
          "their corpses??\n");
        show("Josie speaks with "+NAME+".\n");
      } else {
        write("Josie says: Please clean the forest first!\n");
      }
    }
  }
}

create() {
  if (::create()) return 1;
  shrug=0;
  old_question="";
  SetRace("gnome");
  SetName("Josie");
  SetShort("Josie, the little gnome");
  SetLong(
    "Josie is a little, but very beautiful gnome girl.\n"
    "She needs your help.\n");
  SetGender(GENDER_FEMALE);
  SetLevel(10);
  SetHP(100);
  SetGoChance(0);
  Set(P_HELP_MSG,"Better ask her something.\n");
  InitChats(10,({"Josie says: I have a big problem.\n",
    "Josie cries.\n",
    "Some tears of Josie are falling down to the ground.\n",
    "Josie asks you for help.\n",
    "Josie hmms.\n"}));
  AddQuestion("amulet",
    "Josie shows you her amulet and says: Oh this is an amulet from my\n"
    "grandma. She gave it to me. I will never give it away.\n");
  AddQuestion(({"bushes"}),
    "Josie says: There are some bushes in this forest, some of them can you\n"
    "pass!\n");
  AddQuestion(({"bush"}),
    "Josie says: You can pass some bushes in this forest!\n");
  AddQuestion(({"quest","quests"}),
    "Josie says: Yes I know much about different quests, but I need\n"
    "your help!\n");
  AddQuestion(({"tear","tears","some tears"}),
    "Josie looks astonished: Yes my tears - what else did you expect?\n");
  AddQuestion(({"help","problem"}),
    "Josie says: Yes, I have a big problem. I have to go to my grandma to\n"
    "bring her some food. But there are some cruel liquorice bears in the\n"
    "green forest behind me.\n");
  AddQuestion(({"ma","mother"}),"Josie says: Yes, I have a mother too.\n");
  AddQuestion(({"grandma","grand mother"}),
    "Josie says: My grandma is named Hurxel and she lives somewhere in the\n"
    "inner city behind forest.\n");
  AddQuestion(({"city","inner city"}),
    "Josie says: Yes the inner city - my grandma likes them.\n");
  AddQuestion(({"Hurxel","hurxel"}),
    "Josie says: do you know my grandma? Hurxel is her name!\n");
  AddQuestion(({"food","some food"}),
    "Josie says: Yes my grandma is hungry. I have to bring her some food.\n");
  AddQuestion(({"forest","green forest"}),
    "Josie says: In this forest lives some cruel liquorice bears. I don't\n"
    "want to go there as long as the bears are living. I need a secure way\n"
    "through the forest.\n");
  AddQuestion(({"bear","liquorice bear"}),
    "Josie says: Yes I saw some of them. They are really consists of pure\n"
    "liquorice! Believe me or not.\n");
  AddQuestion(({"liquorice"}),
    "Josie says: Mmmh I like liquorice, tastes very well.\n");
  AddQuestion(({"cruel bear","cruel liquorice bears"}),
    "Josie says: I'm afraid of the bears. I don't want to go into this\n"
    "forest as long as the bears are there. The bears are really cruel and\n"
    "dangerous. They want to kill you if you go there.\n");
  AddQuestion(({"bears","liquorice bears"}),
    "Josie says: Yes there are unnumbered bears in the forest. You can help\n"
    "me to find a secure way through the forest.\n");
  AddQuestion(({"way","ways"}),
    "Josie says: Ways ? Hmm maybe you mean the secure way?\n");
  AddQuestion(({"secure ways"}),
    "Josie says: I think there is only ONE secure way?\n");
  AddQuestion(({"secret ways","secret way"}),
    "Josie says: Hmm do you mean the secure way, don't you?\n");
  AddQuestion(({"shortest way","shortest path"}),
    "Josie says: shortest way? I never run the shortest path - you forget\n"
    "that I'm a gnome.\n");
  AddQuestion("secure way",
    "Josie says: Yes - you can find a secure way, if you eat all the corpses\n"
    "of the cruel liquorice bears. If there is no bear left, blocking the way,\n"
    "I will have no problems walking through the forest, but don't forget,\n"
    "that I'm a gnome and sometimes we are a little bit stupid - so we don't\n"
    "use the shortest path - sometimes we are running around looking for the\n"
    "right way!\n"
    "If you are ready - come back and say that you are finished!\n"
    "But remember - you have to do a little bit more than stupid killing!\n");
  AddQuestion(({"kill","killing","stupid kill","stupid killing"}),
    "Josie says: Yes - you have to do more than a simple kill of the bears.\n"
    "You have to eat all corpses of the bears. If you don't eat them - they\n"
    "will reappear in a short time and the way will not be secure!\n");
  AddQuestion("gnome",
    "Josie points to herself and says: Yes I'm a gnome.\n");
  AddQuestion(({"corpse","corpses"}),
    "Josie says: Yes the corpses consists of liquorice too. You can eat these\n"
    "corpses! They are taste very well.\n");
  AddQuestion("eat","Josie says: Eat? Hmm everybody has to eat?!\n");
  AddQuestion(({"eat corpse","eat corpses"}),
    "Josie smiles: Yes you can eat the corpses - they taste really good.\n");
  AddQuestion("house",
    "Josie says: A house ? Here in the forest? NO!\n");
  AddQuestion("key",
    "Josie says: A magpie is flying around here - maybe the magpie\n"
    "has stolen it?\n");
  AddQuestion("magpie",
    "Josie says: I saw a magpie building her nest into the branches of a\n"
    "lonely tree.\n");
  AddQuestion("nest",
    "Josie says: the nest of a magpie - in the branches of a lonely tree.\n");
  AddQuestion("tree",
    "Josie says: Which tree do you mean? There are many of them here in this\n"
    "forest.\n");
  AddQuestion("trees",
    "Josie says: Tree, trees, trees - everybody asks about trees. Did you\n"
    "seen the trees here? Or are you blind?\n");
  AddQuestion("lonely tree",
    "Josie says: There is only one lonely tree in this forest.\n");
  AddQuestion(({"branch","branches"}),
    "Josie says: Each tree has branches normally.\n");
  AddQuestion("hedge",
    "Josie says: There are some hedges here in this forest. You can pass\n"
    "some of them and some not, because they are too dense.\n");
  AddQuestion("door",
    "Josie says: Ohh the door in the forest? It will lead back into the\n"
    "inner city, where my grandma lives.\n");
  AddQuestion("puddle",
    "Josie says: Puddles contain mostly dirty water.\n");
  AddQuestion("dirty water",
    "Josie says: I don't want to drink this!\n");
  AddQuestion("river",
    "Josie says: Rivers are filled with water (normally). You can normally\n"
    "enter or pass them.\n");
  AddQuestion("water",
    "Josie says: You can drink water? (what else do you want to do with it?).\n");
  AddQuestion(({"gnomish words","gnomish word","word","words"}),
    "Josie murmurs something.\n");
  SetShrugMsg(#'do_shrug);
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme, ({
    ([ P_STANDARD: ({ AT_AMULET,0,PSIZE_NORMAL }) ]),
    ([P_SHORT: "a small amulet",
      P_LONG: "This amulet is made of pure silver!\n",
      P_WEIGHT: 500,
      P_VALUE: 6000,
      P_ADS: ({"silver","small"}),
      P_IDS: ({"amulet"})]) }));
  SetAds(({"little","beautiful"}));
  AddId(({"girl"}));
}

