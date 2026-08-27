// Eso mismo :)

inherit "/std/raiseroom";
#include "path.h";

object ayudante;

void setup()
{
   set_short("%^YELLOW%^Habitacion de levantamiento de muertos%^RESET%^");
   set_save_file(CARRETERA +"raise");
   set_helper_name("Darakanten");
   set_long("Has entrado en la habitacion de levantamiento de muertos. "
            "La habitacion esta un poco mal decorada. De todas formas "
            "poco importa para el proposito de esta habitacion. Puedes "
            "ver a muchos curanderos de aspecto serio moviendose por la "
            "sala atendiendo a los pacientes.\n"+
            "Un cartel cuelga de la pared.\n");
    set_percentage(100);
    set_light(60);

   add_item(({"curandero", "curanderos"}), "Son unos individuos de aspecto "+
   "excentrico que pasan sus dias levantando de la muerte a la gente. Se "+
   "mueven por la habitacion, sus movimientos son fluidos i organizados. Son "+
   "gente ocupada, y no parece que sonrian a menudo. \n");

   add_sign("Es un cartel metalico puesto en una de las paredes.\n", 
      "\r"
      "/----------------------------------------------------------\\\n" +
      "|                                                          |\n" +
      "|  Servicio de levantamiento de muertos.                   |\n" +
      "|  Necesitas una cuenta aqui para que te podamos cobrar.   |\n" +
      "|                                                          |\n" +
      "|  Pon 'crear' para abrir una cuenta.                      |\n" +
      "|  'ingresar' para ingresar dinero.                        |\n" +
      "|  'balance' para ver cuanto dinero te queda.              |\n" +
      "|  'raise me' cuando necesites resucitar.                  |\n" +
      "|  'raise <fantasma>' cuando uses tu cuenta para resucitar |\n" +
      "|  a otra persona.                                         |\n" +
      "|                                                          |\n" +
      "|  Un levantamiento cuesta 1 moneda de platino por cada    |\n" +
      "|  por cada nivel.                                         |\n" +
      "|                                                          |\n" +
      "| NOTA: Si tu nivel es superior a 9 perderas un punto de   |\n" +
      "| 'con' para siempre. Busca a un clerigo con 'resurrect'.  |\n" +
      "| De estas cuentas no se puede sacar dinero. Si te matan   |\n" +
      "| mucho, no podras resucitar mas aqui, tendras que buscar  |\n" +
      "| otros lugares.                                           |\n" +
      "|                                                          |\n" +
      "\\---------------------------------------------------------/\n" );

    add_exit("sur", CARRETERA+"pos_5","corridor");
   ayudante=clone_object(CARRETERA+"npcs/darakanten");
   ayudante->move(this_object());
}

void dest_me()
{
   if (ayudante)
      ayudante->dest_me();
}
