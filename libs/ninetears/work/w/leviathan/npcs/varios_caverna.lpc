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
      set_name("murcielago");
      set_short("murcielago");
      set_long("Es un negro murcielago, como de un metro y medio de ala a ala, utilizan estas cuevas para anidar "+
	       "y dormir, y son tremendamente agresivos cuando se les molesta.\n");
      add_alias("murcielago");
      set_main_plural("murcielagos");
      add_plural("murcielagos");
      set_gender(1);
      set_level(10);
      break;
    case 1:
      set_name("rata");
      set_short("rata");
      set_long("Es una rata de unos setenta centrimetos de grande, su morededura a veces "
               "llega a ser mortal. Estas ratas son especialmente frecuentes en estas "
               "cuevas, puesto que se alimentan de las crias de murcielago mas debiles.\n");
      add_alias("rata");
      set_main_plural("ratas");
      add_plural("ratas");
      set_gender(2);
      set_level(5+random(2));
      break;
    case 2:
      set_name("murcielago gigante");
      set_short("murcielago gigante");
      set_long("Es un murcielago mas grande de lo normal, unos dos metros de envergadura, frente a su hermano "
		"pequenyo, pero igual de agresivo que este."
	"bajas de los arboles.\n");
      set_main_plural("murcielagos");
      set_gender(1);
      set_level(12+random(5));
      break;
    case 3:
      set_name("mosquito");
      set_short("mosquito");
      set_long("Es uno de los molestos mosquitos de las cuevas de trolls. "
               "Su temible picadura se transmite en enfermedades alucinogenas que "
               "son bastante dificiles de curar.\n");
      add_alias("mosquito");
      set_main_plural("mosquitos");
      add_plural("mosquitos");
      set_gender(0);
      set_level(2);
      break;
    case 4:
      set_name("serpiente");
      set_short("serpiente");
      set_long("Es una serpiente de colores oscuros que vive en los riachuelos frios de las grutas.\n");
      set_main_plural("serpientes");
      add_plural("serpientes");
      set_gender(1);
      set_level(3);
      set_level(2+random(2));
      break;
    case 5:
      set_name("troll");
      set_short("troll");
      add_alias("troll");
      set_long("Un joven troll que vagabundea por la zona en busca de presas faciles.\n");
      set_main_plural("trolls");
      add_plural("trolls");
      set_gender(random(1));
      set_level(10+random(10));
      break;
  }
  set_aggressive(3);
  set_random_stats(16,20); 
  set_al(-100);
  set_wimpy(0);
} /* setup */

