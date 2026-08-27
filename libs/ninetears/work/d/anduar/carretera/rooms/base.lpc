#include "path.h"
inherit "/std/outside";

int n, init=0;

void base_desc()
{
   set_long("Estas en el camino hacia Anduar, a ambos lados de la carretera"
            " hay arboles y arbustos. La gente no habla de"
            " este sitio como un lugar seguro, mas bien es la zona"
            " de trabajo de muchos bandidos, ladrones y rateros. "
            "Por las caracteristicas del terreno parece ideal para una "
            "emboscada.\n");
   set_dark_long("Apenas distingues el camino hacia Anduar.\n\n");
   set_short("%^ORANGE%^Camino hacia Anduar%^RESET%^");
   add_alias("arboles", "arbol");
   add_item("arboles", "Ves arboles a ambos lados de la carretera."
                       " Tambien hay arbustos.\n");
   add_item(({"arbustos","arbusto"}), "Unos arbustos caracteristicos de la "
                                      "zona, con espinas, naturalmente.\n");
   add_item("suelo", "El suelo esta formado por tierra endurecida.\n");
   set_light(60);
   set_zone("carretera");
   exit_color="%^YELLOW%^";
}

void crea_bichos()
{
   int tipo, i;

   n=random(5);
   for (i=0; i<n; i++)
   {
      tipo=random(11);
      switch (tipo)
      {
         case 0..3: add_clone(NPC+"bandido", 1);
                 break;
         case 4..5: add_clone(NPC+"ladron", 1);
                 break;
         case 6..8: add_clone(NPC+"viajero", 1);
                 break;
         case 9: add_clone(NPC+"jabali", 1);
                 break;
         case 10: add_clone(NPC+"oso", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}
