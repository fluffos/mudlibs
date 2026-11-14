// made by MagicTCS 23 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include <skills.h>
#include "forest.h"

inherit GREENFOREST;

// for the skill handling:
//inherit "/obj/lib/skills";

int branch;

// property handling:
int QueryBranch() { return branch; }
int Setbranch(int b) { branch=b; return branch; }

// uses climb skill
int climb(string str) {
  int suc,percentage;
  string ret;
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    if (branch==0) {
      write(
      "You try to climb the tree, but there are no low branches left.\n");
      show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
      return 1;
    }
//    suc=UseSkill(this_player(),SK_CLIMB,(this_player()->QueryInt()+
//        branch*3)*20,&percentage,1);
    suc=1;
    if (suc==1) {
      write(
      "You catch one of the lower branches of the lonely tree and climb up.\n");
      this_player()->move(DFOREST("forest41"),M_GO,"into the branches");
      return 1;
    } else {
      switch (percentage) {
        case 0..30:  ret="You try to catch the lowest tree, but miss it.\n";
                     break;
        case 31..66: ret="You jump to catch the lowest branch, but miss it.\n";
                     break;
        default:     ret="You catch the lowest branch, but the branch is too "
                         "smooth and you slide down to the earth.\n";
      }
      write(ret);
      show(this_player()->QueryName()+
        " tries to climb thelonely tree, but fails.\n");
      return 1;
    }
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

// enhancement: use a saw or a weapon to cut the branches from the tree!
int cut(string str) {
  object ob;
  if (!str) { notify_fail("Cut what?\n"); return 0; }
  if (str=="branch from lonely tree") {
    if (branch!=0) {
      write(
      "You cut a branch from the tree.\n");
      show(this_player()->QueryName()+
        " cuts a branch from the lonely tree.\n");
      ob=clone_object("/std/thing");
      ob->SetProperties(([
        P_SHORT: "a branch",
        P_LONG:  "A brown branch, cut from a lonely tree.\n",
        P_IDS:   ({"branch"}),
        P_ADS:   ({"brown"}),
        P_WEIGHT: random(100)+800,
        P_VALUE: 5
      ]));
      ob->move(this_object(),M_TELEPORT,"falls down to the ground.");
      branch--;
      return 1;
    } else {
      write(
      "You try to reach the higher branches, but they are too high for you.\n"
      "You can't reach them.\n");
      show(this_player()->QueryName()+" tries to cut a branch, but fails.\n");
      return 1;
    }
  }
  if (strstr(str,"branch")!= -1) {
    notify_fail("Try: Cut branch from lonely tree\n");
    return 0;  
  }
  notify_fail("Cut what?\n");
  return 0;
}

string look_branch() {
  if (branch!=0) {
    return
    "They consists of brown wood, you can cut them from tree.\n";
  } else {
    return
   "They consists of brown wood, but you cannot reach them!\n";
  }
}

create() {
  ::create();
  branch=4;
  SetIntShort("A clearing in the forest");
  SetIntLong(
    "A clearing in the green forest. A lonely tree stands here. Only one way\n"
    "leads back.\n");
  AddDetail("clearing",#'QueryIntLong);
  AddDetail("way","There is only one way leading northwest.\n");
  AddDetail(({"pathes","different pathes"}),
    "You can go to the southwest and northeast.\n");
  AddDetail(({"forest","green forest"}),
    "Some huge trees are standing around.\n");
  AddDetail(({"trees","huge trees"}),
    "The tree looks unclimbable, but the lonely tree has some interesting\n"
    "branches.\n");
  AddDetail(({"lonely tree","tree","huge tree"}),
    "The lonely tree is a huge ones, but has some interesting branches.\n");
  AddDetail(({"branch","branches","some branches","interesting branch",
    "some interesting branches","interesting branches"}),
    #'look_branch);
  SetBright(20);
  AddExit("northwest",DFOREST("forest40"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Blacky",
       P_SHORT: "blacky",
       P_IDS: ({"blacky","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 53850,
       P_GENDER: 1,
       P_LONG: "A black liquorice bear looking at you.\n"
    ]) );

  // add skill 'climb'
//  AddSkill(SK_CLIMB,"tree",300,({"lonely tree"}));
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("cut",#'cut);
}

reset() {
  ::reset();
  branch=4;
}
