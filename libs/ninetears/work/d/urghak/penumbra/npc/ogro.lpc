#include "../path.h"

inherit "/obj/civil";

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

void setup() {
  set_name("ogro");
  set_short("%^BLACK%^BOLD%^Ogro negro%^RESET%^");
  add_alias(({"ogro","negro"}));
  set_main_plural("%^BLACK%^BOLD%^Ogros negros%^RESET%^");
  add_plural(({"ogros","negros"}));
  set_long("%^BLACK%^BOLD%^Ogro negro%^RESET%^\n\n     "
  	"Una enorme criatura, casi mas ancha que larga, cuya unica "
  	"vestimenta es un burdo taparrabos. Posee una musculatura "
  	"enorme escondida detras de la enorme masa de carne que "
  	"lo cubre, y su cara esta marcada por un gesto de brutalidad " 
  	"que te pone los pelos de punta.\n");
  set_gender(1);
  set_level(30);
  set_str(30);
  set_thac0(-60);
  set_con(18);
  set_dex(14);
  set_wis(6);
  set_int(4);
  set_cha(10);
  set_alineamiento(0,-1);
  set_max_hp(500);
  set_max_gp(300);
  adjust_tmp_damage_bon(10+random(8));  
  set_ciudadania("penumbra");
  add_property("NO_BUDGE", 1);
  this_object()->init_command("proteger guerreros");
}

void event_enter(object enterer, string message)
{
  if (!enterer)
    return;
  if (enterer->query_dead())
    return;
  if (enterer->query_alineamiento()[1] == 1)
    this_object()->attack_ob(enterer);
  ::event_enter(enterer,message);
}

mixed valid_attack() {
 return([
   "knee"  :({AN+" golpea a "+DN+" con sus enormes punyos desnudos.\n",
            "Golpeas a "+DN+" con tus punyos.\n",
            AN+" te golpea con sus enormes punyos desnudos.\n"}),
   "punch" :({AN+" aplasta a "+DN+" con su cuerpo.\n",
            "Aplastas a "+DN+".\n",
            AN+" te aplasta con su enorme cuerpo.\n"}),
   "kick"  :({AN+" destroza a "+DN+" con una poderosa patada.\n",
            "Destrozas a "+DN+" con tu enorme pierna.\n",
            AN+" destroza tu torso con su poderosa patada!\n"})  ]);
}

int unarmed_attack(object target,object me) {
  object *atacante;
  atacante = (object*)me->query_attacker_list();
  civil::unarmed_attack(atacante[random(sizeof(atacante))],me);
  civil::unarmed_attack(atacante[random(sizeof(atacante))],me);  
}
