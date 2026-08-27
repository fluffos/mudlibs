#include "/d/abarrach/path.h";

inherit "/std/bank";
//inherit "/std/room";
object placa;

int init=0, clientes=0;

void setup() 
{
   set_light(80);
   set_short("%^CYAN%^Banco de Abarrach%^RESET%^");
   set_long("Estas en el banco de Abarrach. No parece que tenga muchos clientes. "
            "Por su aspecto no parece de los mas importantes. El mostrador es "
            "mas bien pequenyo y no hay mucha gente por aqui. Desde aqui no "
            "ves ninguna caja fuerte, parece que esta escondida en algun lugar "
            "seguro.\n");

add_exit("fuera", CIUDAD+"f0607", "door");

   placa=clone_object("/std/object");
   placa->set_name("placa");
   placa->set_short("pequenya placa");
   placa->set_long("Es una bonita placa de metal.\n");
   placa->set_read_mess("\n  Bienvenido al banco de Abarrach.\n\n  Puedes usar"
      "los comandos \"crear\" para crear una cuenta, \"cancelar\" para cerrarla," 
      " \"depositar\" meter dinero, \"sacar\" sacar dinero y \"balance\" "
      "para ver tu cuenta.\n\n  NOTA: El banco aplica una deduccion del 5% en concepto "
      "de tasas, es decir, si depositas 100 monedas te quedaran 95.\n");
   placa->move(this_object());
   placa->reset_get();   
   
   set_percentage(95);
   set_save_file(CIUDAD + "banco");
   set_heart_beat(1);
}

