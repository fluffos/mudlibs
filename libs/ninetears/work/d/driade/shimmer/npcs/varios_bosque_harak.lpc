/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(6))
  {
    case 0:
      set_name("lechuza");
      set_short("lechuza");
      set_long("Es una pequenya lechuza de grandes ojos que te mira fijamente.\n");
      add_alias("lechuza");
      set_main_plural("lechuzas");
      add_plural("lechuzas");
      set_gender(2);
      ataque1="picotea la cara";
      ataque2="golpea levemente en la cabeza";
      ataque3="aranya un brazo";
      set_level(3);
      break;
    case 1:
      set_name("raton");
      set_short("raton");
      set_long("Es una raton de unos quince centrimetos de largo, su morededura apenas "
               "te hace cosquillas. Estos ratones son especialmente frecuentes en estos "
               "bosques.\n");
      add_alias("raton");
      set_main_plural("ratones");
      add_plural("ratones");
      set_gender(1);
      ataque1="rabunya la cara";
      ataque2="aranya una mano";
      ataque3="muerde la pierna";
      set_level(2+random(2));
      break;
    case 2:
      set_name("ciervo");
      set_short("ciervo");
      set_long("Es un ciervo tranquilo que disfruta del tiempo mordiendo las ramas"
	"bajas de los arboles.\n");
      set_main_plural("ciervos");
	add_plural("ciervos");
      set_gender(1);
      ataque1="cocea las costillas";
      ataque2="desgarra la pierna de una cornada";
      ataque3="clava los cuernos en el estomago";
      set_level(10+random(5));
      break;
    case 3:
      set_name("liebre");
      set_short("liebre");
      set_long("Es una pequenya liebre de color gris que busca algo de comida por los arrededores.\n");
      add_alias("liebre");
      set_main_plural("liebres");
      add_plural("liebres");
      set_gender(2);
      ataque1="muerde";
      ataque2="golpea una pierna";
      ataque3="aranya la pierna";
      set_level(3);
      break;
    case 4:
      set_name("lince");
      set_short("lince");
      set_long("Es un lince de color gris y marron.\n");
      set_main_plural("linces");
      add_plural("linces");
      set_gender(1);
      set_level(3);
      ataque1="aranya la cara";
      ataque2="muerde un brazo";
      ataque3="muerde una pierna";
      set_level(3+random(2));
      break;
    case 5:
      set_name("jabali");
      set_short("jabali");
      add_alias("jabali");
      set_long("Es un jabali, debes tener cuidado con sus embestidas ya que suelen ser animales "
               "bastante irascibles y suelen atacar con frecuencia a lo que se mueve.\n");
      set_main_plural("jabalies");
      add_plural("jabalies");
      add_plural("jabalis");
      set_gender(1);
      ataque1="da un fuerte mordisco";
      ataque2="embiste y te golpea en el estomago";
      ataque3="clava sus dientes";
      set_level(5);
      break;
  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(20);
} 
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
} 


valid_attack() 
{
   return([
      "kick"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "knee"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "punch"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"})]);


}
