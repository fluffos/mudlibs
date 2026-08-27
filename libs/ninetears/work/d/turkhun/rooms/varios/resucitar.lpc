// Eso mismo :)

inherit "/std/raiseroom";
#include "/d/abarrach/path.h";

object ayudante;

void setup()
{
   set_short("Habitacion de levantamiento de muertos");
   set_save_file(CIUDAD +"raise");
   set_helper_name("Sjanten");
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
            "/---------------------------------------------\\\n" +
            "|                                             |\n" +
            "|  Servicio de levantamiento de muertos de    |\n" +
            "|  Anduar.                                    |\n" +
            "|  Necesitas una cuenta aqui para que te      |\n" +
            "|  podamos cobrar.                            |\n" +
            "|                                             |\n" +
            "|  Pon 'crear' para abrir una cuenta.         |\n" +
            "|  'ingresar' para ingresar dinero.           |\n" +
            "|  'balance' para ver cuanto dinero te queda. |\n" +
            "|  'raise me' cuando necesites resucitar.     |\n" +
            "|  'raise <fantasma>' cuando uses tu cuenta   |\n" +
            "|  para resucitar a otra persona.             |\n" +
            "|                                             |\n" +
            "|  Un levantamiento cuesta 1 moneda de        |\n" +
            "|  platino por cada nivel.                    |\n" +
            "|                                             |\n" +
//Esto pa que se vayan enterando. Gestur 9-8-97 /////////////////////
            "| NOTA: Si tu nivel es superior a 9 perderas  |\n" +  //
            "| un punto de 'con' para siempre. Busca a un  |\n" +  //
            "| clerigo con 'resurrect'.                    |\n" +  //
//Esto pa que se vayan enterando. Aokromes 21-6-99 //////////////////
            "| De estas cuentas no se puede sacar dinero.  |\n" +  //
            "| Si te matan mucho, no podras resucitar mas  |\n" +  //
            "| aqui, tendras que buscar otros lugares.     |\n" +  //
// //////////////////////////////////////////////////////////////////
            "|                                             |\n" +
            "\\---------------------------------------------/\n" );

   add_exit("fuera", CIUDAD+"f0305","corridor");
   ayudante=clone_object(NPCGE+"sjanten");
   ayudante->move(this_object());
}

void dest_me()
{
   if (ayudante)
      ayudante->dest_me();
}
