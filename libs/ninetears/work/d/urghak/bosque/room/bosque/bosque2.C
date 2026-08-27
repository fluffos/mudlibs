// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(0,1);
      
      set_short("%^BLACK%^BOLD%^Cerca del bosque de %^RESET%^GREEN%^Urghak%^RESET%^");
      
      add_exit("este", BOSQUE + "bosque1.c", "path");
      // Esta salida es cosa de Jade, ella sabra donde lleva
      add_exit("noroeste"  , BOSQUE + "bosque3.c", "path");
	
} /* setup */
