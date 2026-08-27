/*  Room by Grimbrand 2-3-96  */

inherit "/std/raiseroom";
#include "path.h";

object helper;

void setup() {

   add_property("no_undead",1); set_light(10);
   
   set_short("Reinado Duergar:  Catedral de la Gran Oscuridad");

   set_long("\n   Reinado Duergar:  Catedral de la Gran Oscuridad."+
            "\n\n"+
            "     Lo primero que ves al entrar es oscuridad, pura y "+
            "diabolica, y notas un olor estranyo.  La oscuridad parece tener vida propia, una "+
            "sensacion de poder oculto.  La fria piedra,negra como "+
            "carbon,reluce bajo tus pies segun entras a este area.  "+
            "Columnas decoradas con simbolos y animales dan firmeza "+
            "a la gran sala.  Tienes la sensacion de ver sombras que "+
            "se mueven con una gracia salvaje y malefica, sientes un temor "+
            "inexplicable que te enfria hasta los huesos al presentir "+
            "una inteligencia malevola templada en el honor y fanatica "+
            "lealtad. Verdaderamente hay muchos rasgos representados "+
            "tallados en la piedra viva de esta catedral. Un gran altar "+
            "domina la sala, integrado en la piedra sutilmente, atrae "+
            "tu atencion inmediatamente.\n"
            "\n");

   add_smell(({"sala", "area", "maldad", "oscuridad"}),
             "   La sala huele a mustio y viejo, acentuado con el olor "+
             "de varias especias y el dulce olor con un toque metalico "+
             "que tiene la sangre fresca.\n"+
             "\n");

   add_feel(({"piedra"}),
            "   La piedra esta  fria al tacto .  Puedes sentir, como si "+
            "lo -tocaras-,el odio y maleficas intenciones vibrando en la piedra."+
            " El crudo poder en este area es como un peso enorme "+
            "y opresivo que te aplastara contra el frio suelo.\n"+
            "\n");

   add_feel(({"odio", "venganza", "maleficas"}),
            "   Poderosas emociones emanan de la mismisima piedra "+
            "de la Catedral.  Odio, venganza, guerra, destruccion, y "+
            "una inteligente maldad te agobia con un extraordinario "+
            "sentimiento de terror. Tambien notas adicionalmete un "+
            "gran sentido del honor y lealtad fanatica que fundamenta "+
            "todas estas sensaciones.\n"+
            "\n");

   add_item(({"oscuridad", "sombra", "sombras"}),
            "   La oscuridad parece estar viva y moverse con una gracia "+
            "salvaje y malefica.  Parece muy amenazante e intentas olvidarte "+
            "de su hipnotico movimiento, ya que te das cuenta de que "+
            "hay algo realmente horrible que prefieres no descubrir. "+
            "that you are unable to glance away.  Moviendose y oscilando, "+
            "las sombras parecen estar comprometidas en algun tipo de danza "+
            "arcana en culto al Dios de Mal y la Oscuridad, "+
            "Grimbrand.\n"+
            "\n");

   add_item(({"piedra"}),
            "   La piedra con que esta hecha la sala es obsidiana, y  "+
            "es negra como nunca habias visto. Parece absorver toda luz "+
            "con voraz apetito, creando una ilusion de oscuridad sin fin. "+
            "  Parece estar muy fria y ser extremadamente dura."+
            "\n"+
            "\n");

   add_item(({"columnas"}),
            "   Las  columnas se espacian uniformemente formando un ovalo "+
            "alrededor del altar.  Cada columna representa diferentes "+
            "criaturas escogidas por el mismo Grimbrand asi como los  "+
            "idolos que representan cada una de las clases, separadas, "+
            "albergadas dentro del dominio malvado. En una ves la imagen "+
            "del Chacal, en otra la del Rey Cobra, y en una mas alla "+
            "la de un viper fer-de-lance, cada uno ha sido incrustada en la "+
            "obsidiana con un raro metal conocido como Electrum.\n"+
            "\n");

   add_item(({"simbolo", "simbolos", "animal", "animales"}),
            "   El electrum incrustado en las columnas seem to emanar "+
            "un suave brillo aun mas oscuro que la oscuridad en si, como "+
            "si irradiara pura maldad.  Puedes ver al Chacal, al Rey Cobra, y "+
            "un viper Fer-de-lance, cada uno representado en primer plano "+
            "teniendo de fondo la imagen de un imponente tigre siberiano "+
            "de aspecto poderoso.  Cada uno de los animales adoptan varias "+
            "posturas lascivas de muerte y destruccion.\n"+
            "\n");

   add_item(({"altar", "Altar"}),
            "   Es un altar de grandes sacrificios, de altura aproximada "+
            "a la cintura de un duergar. Esta hecho con lo que parece un "+
            "bloque solido de estanyo y tiene adornos de electrum incrustados "+
            "en cada cara.  El altar esta equipado en la misma forma que "+
            "podrias esperar de la tabla de operaciones de un viviseccionista.  "+
            "Las esquinas del altar estan algo mas elevadas de manera que "+
            "permiten a la sangre de el sacrificio drenar hacia el centro"+
            ", donde se cuela por un hueco hacia el interior del altar. "+
            "  El altar en si mismo parece emitir un murmullo grave, y  "+
            "cuando lo tocas el murmullo desaparece.\n"+
            "\n");

add_sign("__________________________________________\n"
         "|                                        |\n"
         "|    Dendall, Sala de Resurreccion       |\n"
         "|                                        |\n"
         "|  Pon resucita <nombre_del_espiritu>    |\n"
         "|________________________________________|\n\n");

add_exit("norte",NEWBIE+"main03","door");
}

void reset() {

   if(!helper) 
     {
      helper = clone_object("/baseobs/monsters/healer");
      helper->move(this_object());
     }

   helper->set_name("Clerigo Duergar");
   helper->set_short("Clerigo");
   helper->add_alias("clerigo");
   helper->set_guild("fighter");
   helper->set_race("duergar");
   helper->set_level(55 + random(10));
   helper->set_thac0(-4);
   helper->set_max_hp(1500);
   helper->set_max_gp(1000);
   helper->set_gender(1);
   helper->set_kill_xp(5);
   helper->set_long("\n   El duergar que ves ante ti es un clerigo "
                    "del Dios de los Duergar, Grimbrand:  Dios "
                    "del Mal y la Oscuridad.  Este clerigo da auxilio "
                    "a los Duergar que necesitan ayuda, incluso a aquellos "
                    "que necesitan algo mas que vendajes y pociones.\n"
                    "\n");
}

void dest_me() {
if (helper) helper->dest_me();
::dest_me();
}
