//.oO JaDe Oo.  Agosto'01 

inherit "obj/monster";

#define bicho attacker->query_cap_name()
#define pj defender->query_cap_name()

void setup()
{
  set_name("mole sombria");
  set_short("Mole Sombria");
  set_main_plural("Moles Sombrias");
  add_plural("moles");
  add_plural("moles sombrias");
  add_alias("mole");
  set_long("Tienes ante ti una bestia de 3 metros de estatura y de una fuerza tremenda. "
           "Sus musculos se abultan bajo su gruesa y escamosa piel y sus poderos brazos "
           "y piernas terminan en enormes garras duras como el hierro con las que son "
           "capaces de excavar la roca en busca de presas. No tiene nada parecido a un "
           "cuello, pero su cabeza presenta unas poderosas fauces con filas de dientes "                    "triangulares y unas potentes mandibulas capaces de morder cualquier tipo de "
           "cuero o hueso. Lo mas peculiar son sus cuatro ojos, alineados en la parte "
           "delantera de su cabeza.\n");
  add_move_zone("tun2");
  set_move_after(5,6);
  set_guild_ob("/d/gremios/guerreros/fighter");
  set_guild("fighter");
  set_wimpy(15);
  set_level(40);
  set_gender(1);
  set_str(45);
  set_int(8);
  set_con(20);
  set_wis(10);
  set_dex(16);
  set_cha(18);
  set_max_hp(800);
  set_hp(800);
  set_align(2000);
  set_aggressive(2);
  add_property("fire",0);
  add_property("electrical",10);
  add_property("cold",5);
  add_property("acid",10);
  add_property("poison",30);
  add_property("air",5);
  add_property("missile",5);
  add_property("magical",-5);

}  
int query_total_ac(){ return -70; }
int unarmed_attack(object target,object me)
{
	object *atacantes;
	atacantes=(object *)me->query_attacker_list();
	monster::unarmed_attack(atacantes[random(sizeof(atacantes))],me);
}
valid_attack() 
{
	return([
          "punch"  :({bicho+" desgarra la carne de "+pj+" con sus poderosas garras.\n",
                     "desgarras la carne a "+pj+" con tus poderosas garras.\n",
                     bicho+" desgarra tu carne con sus poderosas garras.\n"}),  
	  "headbutt"  :({bicho+" da un brutal cabezazo a "+pj+" dejandole la frente ensangrentada.\n",
                      "das un brutal cabezazo a "+pj+" dejandole la frente ensangrentada.\n",
                      bicho+" te da un brutal cabezazo dejandote la frente ensangrentada.\n"}),  
          "knee"   :({bicho+" levanta sus brazos y los deja caer furiosamente sobre "+pj+" haciendole perder el equilibrio.\n",
                      "levantas tus brazos y los dejas caer furiosamente sobre "+pj+" haciendole perder el equilibrio.\n",
                      bicho+" levanta sus brazos y los deja caer furiosamente sobre ti haciendote perder el equilibrio.\n"}),
          "kick"   :({bicho+" muerde con fuerza a "+pj+".\n",
                     "Muerdes con fuerza a "+pj+".\n",
                      bicho+" te muerde con fuerza.\n"})]);
}
  