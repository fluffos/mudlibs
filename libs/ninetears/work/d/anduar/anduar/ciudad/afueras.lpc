#include "../path.h"
inherit "/std/outside";

int n, init=0;

void base_desc()
{
   set_dark_long("Lo unico que sabes es que estas en Anduar.\n\n");
   add_item("suelo", "El suelo esta formado por adoquines. Parece perfecto"
                     " para hacerse un esguince.\n");                    
   set_light(65);
   set_zone("anduar");
}

void long_desc()
{
 string *descripciones = ({"un arquero ","un gigantesco guerrero","un vigilante"

});
 string descripcion;
 string *descripciones2 = ({"una hilera de saeteras","unas almenas","de las peligrosas troneras"});
 string descripcion2;
 string *descripciones3 = ({"hombres lagarto","drows","duergars","orcos"});
 string descripcion3;
 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion=descripciones[random(sizeof(descripciones))];
 set_long("Estas en el camino que rodea la muralla de la ancestral ciudad de Anduar, cuna de la humanidad. En lo alto, observas como "+descripcion+" monta guardia encima de "+descripcion2+", oteando el horizonte para evitar posibles invasiones de "+descripcion3+".");
}

void crea_bichos()
{
   int tipo, i;

   n=random(5);
   for (i=0; i<n; i++)
   {
      tipo=random(7);
      switch (tipo)
      {
         case 0: add_clone(BASEMONSTER+"bandit", 1);
                 break;
         case 1: add_clone(BASEMONSTER+"goblin", 1);
                 break;
         case 2: add_clone(BASEMONSTER+"mercenary", 1);
                 break;
         case 3: add_clone(BICHOS+"viajero", 1);
                 break;
         case 4: add_clone(BICHOS+"oso", 1);
                 break;
         case 5: add_clone(BICHOS+"viajero", 1);
                 break;
         case 6: add_clone(BASEMONSTER+"mercenary", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}
