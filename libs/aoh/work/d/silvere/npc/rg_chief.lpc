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

void create()
{
  seteuid(getuid());
  ::create();
  Set(P_LEVEL,40);
  Set(P_GENDER,GENDER_MALE);
  Set(P_NAME,"Luminor Ayerson");
  Set(P_RACE, "human");
  Set(P_ALIGN, 400);
  Set(P_IDS,
   ({"chief","captain","cpt","soldier","luminor","ayerson","luminor ayerson"}));
  Set(P_ADS,({"royal"}));
  Set(P_SHORT,"Cpt. "+CAP(NAME(TO))+", chief of the Royal Guard.");  
  Set(P_LONG,CAP(NAME(TO))+" is the captain of the Royal Guard of "
   "Silvere. He's of middle-age, his beard and hair already showing "
   "first signs of grey. However, his greyish blue eyes still radiate "
   "determination and farsightedness, almost wisdom... For sure, he's "
   "an adequate head of the Guard. Under his blue-and-white robe "
   "appear columns of badges of honor, stars of bravery and such, "
   "just what one expects from a highly decorated officer like him.\n");    
  Set(P_MSGOUT,({"strides","Someone strides"}));
  Set(P_GO_CHANCE,0);

// *** EQUIPMENT ***
  AddItem(WEAPONS("sil_rgsword"), REFRESH_REMOVE, 
    ([P_SHORT: "a fine long sword",
      P_LONG:  
      "This is a blade of superior quality. It is made of the "
      "finest steel, glittering brightly in the light. The edges are "
      "so extremely sharp that looking at them almost hurts your eye. "
      "The hilt is blazoned with rubies and one mysteriously "
      "glimmering moonstone. Thin greenish rays of light come from "
      "within the stone, and flow over the hilt to the blade, where "
      "they form an image of four griffins. Near the griffins there "
      "are some engravings in a firm script that show: Capt. "
      +CAP(NAME(TO))+".\n",
      P_WC: 15,
      P_VALUE: 5000
     ]), SF(wieldme));
  AddItem(ARMOUR("sil_rgarmour"), REFRESH_REMOVE, SF(wearme));
  AddItem(ARMOUR("sil_rghelmet"), REFRESH_REMOVE, SF(wearme));

// *** CHAT SETTINGS ***
  Set(P_CHAT_CHANCE,5);
  Set(P_CHATS,({
    NAME(TO)+" watches you suspiciously.\n",
    NAME(TO)+" checks some administrative stuff on his desk.\n",
    NAME(TO)+" checks his swordbelt with an accurate movement.\n",
    NAME(TO)+" says: What's your business here? Speak up!\n",
    NAME(TO)+" sighs and says: Oh, all those young greenhorn"
             " guards of my division... Their foolish pride"
             " blurs their attention.\n",
    NAME(TO)+" says: I wish we'd finally find the hiding place"
             " of these hideous smugglers from the harbour!\n",
    NAME(TO)+" says: Is there no one of these SUPER-adventurers"
             " able to help me finding these criminal smugglers?\n",
    NAME(TO)+" hmpfs.\n",
    NAME(TO)+" salutes to you and says: Long live Lu'Meyn, our"
             " splendid leader!\n",
    NAME(TO)+" lets his glance roam through the windows over"
             " Silvere.\n",
    NAME(TO)+" looks at a map of the harbour and frowns.\n",
    NAME(TO)+" points at you and says: How about YOU? Would you"
             " like to help us?\n"
  }));
}

varargs void Die(int silent)
{
  tell_room(environment(),CAP(NAME(TO))+" trembles, spits some "
   "blood and falls to the floor. With the concentrated energy "
   "left in him he screams: MAY THE WRATH OF LU'MEYN DESTROY "
   "YOU!!!\n");
  ::Die(silent);
}




