// A crow for the cornfield newbie area
// created:          Tune     [13-May-1999]
// last changed:  

inherit "/std/npc";

#include <properties.h>
#include <msgclass.h>
#include <regions.h>

void create()
{
  ::create();
  
  Set(P_ALLOWED_REGIONS, REGION_SPECIAL1);

  Set(P_GENDER,GENDER_MALE);
  
  SetStandard(random(2)+2, "crow", "crow");
  Set(P_SHORT, "a large, black crow");
    
  Set(P_IDS, ({ "crow", "bird" }) );
  Set(P_ADS, ({ "big", "black", "large" }) );
  
  Set(P_HANDS, ({ ({"his right claw",0,1}), ({"his left claw",0,1}), ({"his beak",0,1}) }) );
  Set(P_GO_CHANCE,50);
  
  Set(P_ALIGN, -300);
 
  Set(P_LONG,
    "The crow has long been considered by Silvereans to be an omen of ill "
    "bodings. They are always unwelcome guests, but especially in corn or grain "
    "fields, where they usually wreak havoc upon the crops with an almost "
    "malicious efficiency. The sleak, oily black feathers, beady eyes "
    "and cold stare are enough to make anyone believe the old wives tales "
    "about their evil disposition and supernatural abilities.\n");
   
  Set(P_MSGOUT,({"flies","Something flies"}));
  Set(P_MSGIN, ({"flies", "Something flies"}));
  
  Set(P_CHAT_CHANCE, 2);
  Set(P_ACHAT_CHANCE, 1);
  
  Set(P_CHATS,
   ({ "The crow watches you suspiciously.\n",
      "The crow hops about, looking at you every few minutes.\n",
      "The crow cocks his head back and forth, while keeping his "
          "beady eyes on you.\n",
      "The crow lands on a cornstalk, pecking at the kernels through "
          "the husks.\n",
      "The crow flaps up into the air, lands on a stalk, and helps "
          "himself to an ear of corn.\n",
      "The crow silently preens his oily, jet black feathers.\n"
    }) );
  
  Set(P_ACHATS,
   ({ "The crow dives down at you, his sharp yellow beak aimed straight "
        "at your eyes.\n",
      "The crow, with malicious intent in his piercing eyes, flaps his "
        "wings in your face.\n",
      "The crow tries to land on your face with his sharp talons out.\n"
   }) );
   
  Set(P_SHRUG_MSG, "The crow cocks its head back, stares at you intently, "
    "but whether it understood your question is anyone's guess.\n");
  
}

varargs void Die (int silent)
{
  if (!silent)
  msg_room(environment(), CMSG_ROOM,
    "The crow heaves out a last squawk and expires, eyes staring "
    "at you blankly.\n");
  ::Die(silent);
}

