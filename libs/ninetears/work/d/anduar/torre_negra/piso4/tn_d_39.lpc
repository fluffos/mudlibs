// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 4.%^RESET%^");
   set_long("Estas en una de las multiples bibliotecas de la siniestra "
   "%^BOLD%^%^BLACK%^Torre Negra%^RESET%^, en la cual puedes observar por "
   "todos lados enormes volumenes de libros de magia negra, pero uno de ellos "
   "parece distinto, raro, fuera de lugar. \n");
   add_item("libro","No es un libro, mas bien son solo las pastas, por que "
   "estara aqui? \n");
   
   add_exit("oeste",TN4"tn_d_45","road");        
}

void init()
{
 ::init();
   add_action("coger_libro","coger");

}

int coger_libro(string str)
{
  if(str=="libro")
  {
   write("Empujas el libro y detras de la libreria se abre un agujero del "
         "tamanyo de un hombre. Sin pensartelo te metes por el.\n");
   say(this_player()->query_cap_name()+" de repente desaparece por el agujero.\n");
   this_player()->move(TN+"tn_59");
   this_player()->look_me();
   return(1);
  }
  notify_fail("empujar que?.\n");
  return(0);      
}

