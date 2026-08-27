#include "../path.h"
inherit "/std/outside";

int n, init=0;

void base_desc()
{
   set_long("Estas en el camino hacia Anduar, a tu alrededor ves pocos"
            " arboles y el camino parece despejado. Dicen que por estos"
            " caminos se ve a toda clase de gente, tanto buena como mala. En"
            " estos casos lo mejor es tener cuidado.\n\n");
   set_dark_long("Apenas distingues el camino hacia Anduar.\n\n");
   set_short("%^ORANGE%^Camino hacia Anduar%^RESET%^");
   add_alias("arboles", "arbol");
   add_item("arboles", "Ves unos pocos arboles a los lados del camino."
                       " Parece que no hay mucha vegetacion aqui.\n");
   add_item("suelo", "El suelo esta formado por adoquines. Parece perfecto"
                     " para hacerse un esguince.\n");                    
   set_light(80);
   exit_color="%^YELLOW%^";
}

void crea_bichos()
{
   int tipo, i;

   n=random(5);
   for (i=0; i<n; i++)
   {
      tipo=random(5);
      switch (tipo)
      {
         case 0: add_clone(BASEMONSTER+"bandit", 1);
                 break;
         case 1: add_clone(BASEMONSTER+"goblin", 1);
                 break;
         case 2: add_clone(BASEMONSTER+"mercenary", 1);
                 break;
         case 3: add_clone(ANDUAR+"npcs/viajero", 1);
                 break;
         case 4: add_clone(ANDUAR+"npcs/oso", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}
