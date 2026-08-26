#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "Renfro the Adept") ;
  set("long", @ENDLONG
Renfro is a young man who has devoted himself to his god and become a 
cleric.  He looks like he thinks very high of himself.
ENDLONG
  );
  set("id", ({ "renfro", "man", "adept", "idiot" }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("renfro") ;
  credit(random(341)+ 898) ;
  set_level(24) ;
  set_alignment("ln") ;
  set_skill("Clubbing weapons", 2, "strength") ;
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  set("chat_chance", 3) ;
  set("chat_output", ({
    "Renfro says [to you]: Come find the Lord for yourself!\n",
    "Renfro says [to you]: You need Him.\n",
    "Renfro says [to you]: He is my Savior.\n",
    "Renfro says [to you]: Praise His name!\n",
    "Renfro says [to you]: Join me in prayer.\n",
    "Renfro says [to you]: You are going straight to Hell, you know.\n",
    "Renfro says [to you]: Your God is a devil.\n",
    "Renfro says [to you]: You will burn in Hell if you do not accept my God.\n",
    "Renfro says [to you]: You will learn the errors of your ways.\n",
    "Renfro says [to you]: Come clean, Sinner.  Accept Salvation!\n",
    "Renfro says [to you]: My God loves you!\n",
    "Renfro says [to you]  My God protects me.  I can not be defeated in battle.\n",
    "Renfro says [to you]  You pagans will burn in Hell!\n",
    "Renfro says [to you]: Join me in some worship.\n",
    "Renfro says [to you]: Worship my God or go to Hell!\n",
    "Renfro says [to you]: All sinners need salvation, even you.\n",
    "Renfro says [to you]: I have found the right way to get to Heaven!\n",
    "Renfro prays quietly.\n",
    "Renfro flips through the pages of his Bible.\n",
    "Renfro ponders the mysteries of his God's ways.\n",
    "Renfro smiles at you condescendingly.\n",
    "Renfro says [to you]: I have been forgiven for my sins.  Have you?\n",
    }) ) ;
  set("att_chat_output", ({
    "Renfro says: Take that, Sinner!\n",
    "Renfro says: I will defeat you through my prayers!\n",
    "Renfro says: It's time for you to die and realize you were wrong about your religion!\n",
    "Renfro says: I will convert you by force, Sinner!\n",
    "Renfro prays briefly before attacking.\n",
  }) ) ;
  set_verbs( ({ "swing at", "attack", "lunge at" }) );
  wear(ARM(chainmail), "chainmail") ;
  wear(ARM(slboots), "boots") ;
  arm(WEP(spiked_mace), "mace") ;
}
