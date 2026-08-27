#include "path.h"

varargs void desc(int i, object ob)
{
   if (!ob)
      ob=this_object();

   ob->set_zone("catacumbas");
   if (random(2) && i!=7) ob->add_clone(NPC+"zombie", 1);
   
   switch (i)
   {

/* ****** */

      case 1:
      ob->set_long("La oscuridad en este sitio es tenebrosa, distingues "
      "poca cosa debido a que la luz solar no puede entrar aqui. Ves unas "
      "tumbas que te causan pavor y estremecimiento. Notas que el suelo "
      "esta hecho de piedra llena de grietas e impurezas lo que te hace "
      "tropezar a menudo. Hay mucha humedad aqui debido a la profundidad "
      "a la que se encuentra esta galeria y tiene pinta de no haber sido "
      "visitada en mucho tiempo.\n");
      
      ob->add_item(({"tumba", "tumbas"}), "Parecen unas tumbas de gran "
      "antiguedad, tienen unos grabados bastante desgastados de los "
      "cuales no logras distinguir casi nada.\n");
      
      ob->add_item("suelo", "Un suelo hecho de piedra cavernosa bastante "
      "agrietada. Decididamente esto hace bastante que no ha sido "
      "visitado.\n");

      ob->add_item(({"paredes", "pared"}), "Las paredes son fundamentalmente "
      "mausoleos de personas que han pasado a mejor vida con sus "
      "correspondientes lapidas.\n");
      
      ob->set_light(0);
      
      
      break;

/* ***** */

      case 2:
      ob->set_long("Estas en una amplia galeria bastante espaciosa. "
      "Hay diversas columnas perfectamente alineadas que consiguen dividir "
      "la galeria en partes iguales. En el techo hay abundante musgo de "
      "diversos colores debido a la gran humedad que hay aqui.\n");
      
      ob->add_item(({"columna", "columnas"}), "Son unas columnas de un material "
      "que no consigues reconocer ya que estan bastante deterioradas y "
      "llenas de musgo.\n");
      
      ob->add_item("musgo", "Un musgo normal y corriente de los que suelen "
      "crecer en las rocas.\n");

      ob->set_light(0);
      
      break;

/* ***** */
      
      case 3:
      ob->set_long("Estas en una gran sala, es enorme. Seguro que "
      "era utilizada por los antepasados de Anduar para esconderse de los "
      "ataques llevados a cabo por las razas oscuras. En el suelo se ven "
      "muchas lapidas sobresalir con inscripciones. Tambien hay muchas "
      "columnas, pero estas son mas gruesas y de aspecto mas resistente. "
      "El techo aqui es mas alto que en la galeria.\n    ");
      
      ob->add_item("suelo", "Es un suelo formado por baldosas de igual tamanyo "
      "con varias lapidas sobresalientes de el.\n");
      
      ob->add_item("lapidas", "Son las tipicas lapidas usadas para identificar "
      "a un muerto. Son de marmol negro bastante deteriorado.\n");
      
      ob->add_item(({"columnas", "columna"}), "Unas columnas de un material "
      "que no consigues reconocer ya que estan bastante deterioradas y "
      "llenas de musgo.\n");
      
      ob->add_item("musgo", "Un musgo normal y corriente de los que suelen "
      "crecer en las rocas.\n");

      ob->set_light(0);

      break;
      
/* ***** */

      case 4:
      ob->set_long("Estas al lado de una gran pared. De esto deduces "
      "que te encuentras en un extremo de las catacumbas. En las paredes "
      "ves algo que parece una fosa comun ya que tiene una gran placa con "
      "muchos nombres. Parece ser que en Anduar hubo una guerra hace mucho "
      "tiempo. El suelo esta lleno de lapidas y tumbas que te causan pavor. "
      "No parece este un sitio muy bonito que digamos.\n");
      
      ob->add_item("pared", "Una pared que parece una gran fosa comun con una "
      "placa con lo que parece una lista de fallecidos.\n");
      
      ob->add_item("placa", "Es una placa metalica que tiene una larga lista de "
      "nombres de personas, debe haber unas 100 mas o menos.\n");
      
      ob->add_item("lapidas", "Son lapidas normales y corrientes que suelen haber "
      "al lado de las tumbas.\n");

      ob->set_light(0);

      break;

/* ****** */

      case 5:
      ob->set_long("Estas en lo que parece el principio de un pasillo "
      "secreto. No hay nada de luz aqui, por lo que resulta dificil ver. "
      "Las paredes son muy estrechas, lo que te da una sensacion "
      "claustrofobica. En las pareces hay unas antorchas consumidas que "
      "sirvieron en alguna epoca para alumbrar este tunel. El suelo es "
      "de piedra completamente lisa, al igual que las paredes.\n");

      ob->add_item(({"pared", "paredes"}), "Una pared de un material muy "
      "rigido y solido. Esta pulida y tiene un aspecto completamente "
      "liso. La distancia de una pared a otra debe ser de un metro y "
      "medio aproximadamente.\n");
      
      ob->add_item(({"antorcha", "antorchas"}), "Son unas antorchas "
      "colocadas en ambas paredes que sirvieron para alumbrar este "
      "pasillo.\n");
      
      ob->add_item("suelo", "Es un suelo de piedra completamente liso. "
      "Parece que fue pulido a conciencia.\n");
      
      ob->set_light(0);
      
      break;

/* ****** */

      case 6:
      
      ob->set_long("Estas en lo que parece el un pasillo "
      "secreto. No hay nada de luz aqui, por lo que resulta dificil ver. "
      "Las paredes son muy estrechas, lo que te da una sensacion "
      "claustrofobica. En las pareces hay unas antorchas consumidas que "
      "sirvieron en alguna epoca para alumbrar este tunel. El suelo es "
      "de piedra completamente lisa, al igual que las paredes.\n");

      ob->add_item(({"pared", "paredes"}), "Una pared de un material muy "
      "rigido y solido. Esta pulida y tiene un aspecto completamente "
      "liso. La distancia de una pared a otra debe ser de un metro y "
      "medio aproximadamente.\n");
      
      ob->add_item(({"antorcha", "antorchas"}), "Son unas antorchas "
      "colocadas en ambas paredes que sirvieron para alumbrar este "
      "pasillo.\n");
      
      ob->set_light(0);
      
      break;       

/* ****** */

      case 7:
      
      ob->set_long("Te encuentras en el final de este pasillo. No hay "
      "salida aparente aqui, lo unico que hay delante de ti es un muro "
      "del mismo material que las paredes y el suelo. En el suelo hay "
      "unos restos que desprenden un resplandor fosforescente.\n");

      ob->add_item(({"pared", "paredes", "muro"}), "Una pared de un material "
      "muy rigido y solido. Esta pulida y tiene un aspecto completamente "
      "liso. La distancia de una pared a otra debe ser de un metro y "
      "medio aproximadamente.\n");
      
      ob->add_item(({"antorcha", "antorchas"}), "Son unas antorchas "
      "colocadas en ambas paredes que sirvieron para alumbrar este "
      "pasillo.\n");
      
      ob->add_item("restos", "Son unos restos viscosos de color verde que "
      "desprenden un resplandor fosforescente. Parecen restos "
      "ectoplasmicos.\n");
      
      ob->set_light(20);
      
      break;       
   }
}
