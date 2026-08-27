// Cloaca. C13.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Cruce Pasillo auxiliar%^RESET%^");
   set_long("La pared de enfrente tuyo tiene unos extranyos dibujos "
            "grabados en ella, pero no puedes distinguir nada. El frio se hace "
            "casi insoportable. \n");

   add_item("suelo", "La fuerza del agua es mucho mayor debido al cruce. \n");
   add_item("pared", "Los dibujos parecen simbolos arcanos sin traduccion alguna. \n");

   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");
   add_clone(CLOACABICHO+"ho_rata",1);

   add_exit("norte", CLOACAS+"c12", "corridor");
   add_exit("este", CLOACAS+"c14", "corridor");
   add_exit("oeste", CLOACAS+"c26", "corridor");

   set_light(0);
}
