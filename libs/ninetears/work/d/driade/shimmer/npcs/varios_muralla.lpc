/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(3))
  {
    case 0:
      set_name("lagartija");
      set_short("lagartija");
      set_long("Es una diminuta lagartija de color verde que se encuentra sobre una roca al lado del camino, "+
		      " intentando cazar alguna de las moscas que revolotean por aqui.\n");
      add_alias("lagartija");
      set_main_plural("lagartijas");
      add_plural("lagartijas");
      set_gender(1);
      ataque1="te aranya un poco la pierna";
      ataque2="te escupe a la cara una sustancia pegajosa";
      ataque3="sube por tu cuerpo y te muerde en el cuello";
      set_level(10);
      break;
    case 1:
      set_name("rata");
      set_short("rata");
      set_long("Es una rata de unos setenta centrimetos de grande, su morededura a veces "
               "llega a ser mortal. Estas ratas son especialmente frecuentes en estos "
               "bosques con follaje tan espeso.\n");
      add_alias("rata");
      set_main_plural("ratas");
      add_plural("ratas");
      set_gender(2);
      ataque1="muerde";
      ataque2="clava sus patas";
      ataque3="muerde";
      set_level(5+random(2));
      break;
    case 2:
      set_name("vibora");
      set_short("vibora");
      set_long("Una pequenya culebra venenosa que sisea por el camino buscando algo"
	"para comer.\n");
      set_main_plural("viboras");
	add_plural("viboras");
      set_gender(1);
      ataque1="se lanza hacia ti e inyecta su veneno en la pierna";
      ataque2="te lanza su veneno a la cara";
      ataque3="te clava sus colmillos en una pierna";
      set_level(10+random(5));
      break;
  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(20);
} /* setup */


#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
}