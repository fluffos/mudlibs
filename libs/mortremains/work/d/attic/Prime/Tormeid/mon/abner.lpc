#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "Abner the Minstrel") ;
  set("long", @ENDLONG
Abner is an old friend of the Royal Family, and the favorite
Minstrel of the King.
ENDLONG
  );
  set("id",({ "abner", "minstrel", "bard" }) ) ;
  set("gender", "male");
  set("race", "halfling") ;
  set("size", 3) ;
  set_name("Abner") ;
  credit( 400 * random(8)) ;
  set_level(26) ;
  set("stat", ([
   "strength" : 15, "dexterity" : 11, "intelligence" : 13,
   "wisdom" : 8, "charisma" : 17, "constitution" : 15
  ]) ) ;
  clone_object(OBJ(lute))->move(TO) ;
  set_skill("Two Weapon Style", 2, "strength") ;
  set_skill("Ambidexterity", 1, "dexterity") ;
  set_skill("Short Blades", 2, "strength") ;
  set_alignment("cg") ;
  arm(WEP(bardsword), "sword") ;
  wear(ARM(small_cap), "cap") ;
  wear(ARM(halfling_chain), "chain") ;
  wear(ARM(cloak), "cloak") ;
  wear(ARM(slboots), "boots") ;
  wear(ARM(see_invis_ring), "ring") ;
  set("damage", ({ 2, 5 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  set("chat_chance", 6);
  set("chat_output", ({
   "Abner sings: Fa la la!\n",
   "Abner tunes his instrument.\n",
   "Abner plays a couple notes on his instrument.\n",
   "Abner plucks a few notes on his lute.\n",
   "Abner sings: Dee dum dee la!\n",
   "Abner sings: La la la!\n",
   "Abner sings: Fa fa fa de la!\n",
   "Abner sings: Deedle dum de la!\n",
   "Abner sings: Dum dee deedle dee!\n",
   "Abner plays the theme from \"Deliverance\" on his lute.\n",
   "Abner sings: Do ray me fah so lah tee do!\n",
   "Abner sings: La-de-da!\n",
   "Abner sings: Dump rumpa rump-rump!\n",
   "Abner sings: Fa, fo, deedle-di-dum!\n",
   "Abner sings: Dum-di dum-di dum!\n",
  }) );
  set("att_chat_output", ({
    "Abner sings: Deedly dee, deedly doo - You get a big fuck you!\n",
    "Abner sings: Ho hum, feedly fi!  You need to die!\n",
    "Abner sings: Bum-biddly-bee, don't fuck with me!\n",
    "Abner sings: Of course, of course, I'll piss on your corpse.\n",
  }) ) ;
}
