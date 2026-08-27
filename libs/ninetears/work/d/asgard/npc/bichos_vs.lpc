inherit "/obj/monster";
#define TIEMPO 100

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(3))
  {
    case 0:
  set_name("oso");
  set_short("Oso");
  set_main_plural("Osos");
  set_random_stats(14,18);
  set_long(query_short()+"\n"+"Es un gran oso, gigante, mide por lo menos 2 metros  "
  "de alto y otro metro y medio de ancho, su pelaje es marron oscuro, y tiene una  "
  "pose atemorizadora, parece que va a atacarte de un momento a otro, asi que yo  " 
  "tendria cuidado con el.\n");
  set_aggressive(0);
  set_race("monster");
  set_level(10+random(10));
  set_gender(1);
  load_chat(10,
  ({
    1, ":te grunye amenazadoramente.",
	1, ":se levanta sobre sus patas.",
  }));
      break;
    case 1:
   set_name("serpiente");
   set_short("Serpiente");
   set_main_plural("Serpientes");
   set_random_stats(6,10);
   set_long(query_short()+"\n"+"Este pequenyo reptil se arrastra por el suelo "
            "lentamente. No parece ser agresivo, tampoco tiene pinta de , "
            "ser muy fuerte. Al mirarle los ojos, observas, no tiene. "
            "En su lugar, la zona parece haber sido quemada.\n");
   set_aggressive(0);
   set_race("monster");
   set_level(1+random(6));
   set_gender(1);
   load_chat(50,
   ({
     1, ":sisea levemente.",
     1, ":se arrastra lentamente por el suelo.",
   }));
      break;
    case 2:
  set_name("lobo");
  set_short("Lobo");
  set_main_plural("Lobos");
  set_random_stats(14,18);
  set_long(query_short()+"\n"+"Un temible lobo hambriento, es grande y fuerte y "
  "tiene una mirada fiera. Su piel es de color negra, anda sigiloso en busca de "
  "alguna presa que echarse a la boca, te mira fijamente parece como si ya hubiera 
  "encontrado su presa.\n");
  set_aggressive(0);
  set_race("monster");
  set_level(10+random(10));
  set_gender(1);
  load_chat(10,
  ({
    1, ":grunye.",
	1, ":te mira fijamente.",
  }));
      break;
	case 3:
  set_name("cuervo");
  set_short("Cuervo");
  set_main_plural("Cuervos");
  set_random_stats(6,14);
  set_long(query_short()+"\n"+"Es un cuervo de un oscuro plumaje, que vive de los "
           "restos descompuestos de los seres del bosque. No "
           "obstante. Una escalofriante sensacion te recorre la "
           "espina dorsal al fijarte en los ojos de la criatura, "
           "que te escudrinyan, y parecen leerte el alma. Te preguntas "
           "si este cuervo esconde dentro de si algo mas que lo que "
           "aparenta.\n");
  set_aggressive(0);
  set_race("monster");
  set_level(2+random(4));
  set_gender(1);
  set_wimpy(30);
  load_chat(80,
  ({
    1, ":mordisquea los ojos del cadaver de un pequenyo animal.",
    1, ":revolotea entre los arboles, desprendiendo una sinietra sombra sobre tu cabeza.",
    1, ":grazna vilmente.",
  }));
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

void attack_by(object atacante)
{
   atacante->add_timed_property("vaqueros_ormerod", 1, TIEMPO);
   ::attack_by(atacante);
}
