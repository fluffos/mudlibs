/*
Apanyado por: MatatunoS
Fecha: 19/2/02
Descripcion: Este fichero genera aleatoriamente 1 npc de entre 7, npcs posibles para un bosque, 
	al que se podrian anyadir mas animales.. ardillas conejos osos lobos etc, permite 
	modificar nombres de ataques dependiendo del tipo de animal que se cree.
*/


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(6))
  {
    case 0:
      set_name("bandido");
      set_short("bandido");
      set_long("Es un bandido de los bosques de los que pasan por la "+
		      "ciudad cuando no hay mucho que robar fuera.\n");
      add_alias("bandido");
      set_main_plural("bandidos");
      add_plural("bandidos");
      set_gender(1);
      ataque1="espachurra la nariz";
      ataque2="patea el bazo";
      ataque3="quiebra una pierna";
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
      set_name("ciervo");
      set_short("ciervo");
      set_long("Es un ciervo tranquilo que disfruta del tiempo mordiendo las ramas"
	"bajas de los arboles.\n");
      set_main_plural("ciervos");
      set_gender(1);
      ataque1="cocea las costillas";
      ataque2="desgarra la pierna de una cornada";
      ataque3="clava los cuernos en el estomago";
      set_level(10+random(5));
      break;
    case 3:
      set_name("mosquito");
      set_short("mosquito");
      set_long("Es uno de los molestos mosquitos fastidiosos de las alcantarillas. "
               "Su temible picadura se transmite en enfermedades alucinogenas que "
               "son bastante dificiles de curar.\n");
      add_alias("mosquito");
      set_main_plural("mosquitos");
      add_plural("mosquitos");
      set_gender(0);
      ataque1="pica";
      ataque2="pica";
      ataque3="pica fuertemente";
      set_level(2);
      break;
    case 4:
      set_name("gato");
      set_short("gato");
      set_long("Es un gato de color gris y marron. Su piel es usada "
               "frecuentemente para fabricar trajes y demas ropajes y su "
               "carne es una de las mas sabrosas de estas tierras.\n");
      add_adjective("gato");
      set_main_plural("gato");
      add_plural("gato");
      set_gender(1);
      set_level(3);
      ataque1="aranya";
      ataque2="muerde";
      ataque3="muerde";
      set_level(2+random(2));
      break;
    case 5:
      set_name("perro");
      set_short("perro");
      add_alias("perro");
      set_long("Es un perro tipico de esta cuidad, solo se crian en esta "
               "zona ya que el clima es bastante favorable para que se "
               "reproduzcan.\n");
      set_main_plural("perro");
      add_plural("perros");
      set_gender(random(1));
      ataque1="da un mordisco";
      ataque2="muerde con fuerza";
      ataque3="clava sus dientes";
      set_level(4);
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
