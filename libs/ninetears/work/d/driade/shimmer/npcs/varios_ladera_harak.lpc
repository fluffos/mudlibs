/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(6))
  {
    case 0:
      set_name("oso");
      set_short("oso pardo");
      set_long("Es un bandido de los bosques de los que pasan por la "+
		      "ciudad cuando no hay mucho que robar fuera.\n");
      add_alias("oso");
      set_main_plural("osos pardos");
      add_plural("osos");
      set_gender(1);
      ataque1="se levanta sobre sus patas traseras y te cae encima rasgandote el cuerpo";
      ataque2="muerde una pierna";
      ataque3="golpea con sus zarpas en la cadera";
      set_level(20);
      break;
    case 1:
      set_name("antilope");
      set_short("antilope");
      set_long("Es un antilope de las montanyas, se caracteriza por su enorme cornamenta, "
               "de un metro y medio de largo aproximadamente y muy peligrosa si te ataca.\n");
      add_alias("antilope");
      set_main_plural("antilopes");
      add_plural("antilopes");
      set_gender(1);
      ataque1="estampa su cornamenta en la cintura";
      ataque2="clava su cornamenta en un costado";
      ataque3="muerde un brazo";
      set_level(10+random(2));
      break;
    case 2:
      set_name("ciervo");
      set_short("ciervo");
      set_long("Es un ciervo tranquilo que te mira atontado.\n");
      set_main_plural("ciervos");
      add_plural("ciervos");
      set_gender(1);
      ataque1="cocea las costillas";
      ataque2="desgarra la pierna de una cornada";
      ataque3="clava los cuernos en el estomago";
      set_level(7);
      break;
    case 3:
      set_name("aguila");
      set_short("aguila");
      set_long("Es uno de los molestos mosquitos fastidiosos de las alcantarillas. "
               "Su temible picadura se transmite en enfermedades alucinogenas que "
               "son bastante dificiles de curar.\n");
      add_alias("aguila");
      set_main_plural("aguilas");
      add_plural("aguilas");
      set_gender(1);
      ataque1="vuela en picado y te picotea en la cabeza";
      ataque2="te rabunya la cara con sus garras";
      ataque3="vuela sobre ti y deja caer una piedra en tu cabeza";
      set_level(3);
      break;
    case 4:
      set_name("puma");
      set_short("puma");
      set_long("Es un puma de color marron claro y anaranjado. Su cuerpo "
               "es largo y delgado y sus largas garras sobresalen en sus patas, "
               "cuando abre su boca puedes ver unos afilados colmillos.\n");
      set_main_plural("pumas");
      add_plural("pumas");
      set_gender(1);
      ataque1="te desgarra un brazo al golpearte con sus garras";
      ataque2="se abalanza sobre ti mordiendote en el cuello";
      ataque3="se lanza contra ti golpeandote en el costado";
      set_level(15);
      break;
    case 5:
      set_name("lobo");
      set_short("lobo");
      add_alias("lobo");
      set_long("Es un lobo gris tipico de las montanyas, suelen ir en manadas y"
               "atacar a todo lo que ven.\n");
      set_main_plural("lobos");
      add_plural("lobos");
      set_gender(1);
      ataque1="golpea con su cuerpo";
      ataque2="muerde con fuerza un brazo";
      ataque3="clava sus dientes y te desgarra la pierna";
      set_level(10);
      break;
  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(10);
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
