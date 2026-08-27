#include "path.h"
inherit "/obj/monster";
string *types = ({"cerdo salvaje","cerdo gordo y sonrosado","sucio puerco","cochino atozinado"});
void  setup()
{
    int i;
    i = random(sizeof(types));
    set_name("cerdo");
    set_short("Cerdo");
   add_alias("gocho");
    set_long("  Un cerdo "+types[i]+". "
    "Parece estar olisqueando entre las hojas caidas,  "
    "buscando frutos caidos e insectos. "
    "\n");
   if(i == 2) gender = 2;
   if(i == 3) gender = 1;
   else gender = 1 + random(2);
    set_gender(gender);

    set_random_stats(2+i,5);
    set_str(5+(i*3));
    set_max_hp(10*i);
    set_dex(5+(10-i));

    load_chat(10,
       ({
        1,":resopla.",
        1,":mastica algo chorreante.",
        1,":hurga con el hocico por el suelo.",
        1,":se come un escarabajo.",
       }));
    load_a_chat(100,
      ({
       1,":grunye.",
       1,":se restriega en ti.",
    }));
    //set_wimpy(100-(10*i));
    set_level(3+random(3)*i);
}
//This is supposed to be code for modifying the unarmed combat
//of various creatures.  I am Talon; however, so not even the gods
//know how this will turn out...

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack () {

  int two,three,four,five;
  two=random(2);
  three=random(3);
  four=random(4);
  five=random(5);

  return ([
    "punch"   :({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c










