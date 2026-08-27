/*  Text alterations and additions by Grimbrand 2-3-96                 */

#include "path.h"
inherit "/std/underground";

void setup() {
   
   add_property("no_undead",1); set_light(10);
   
   set_short("Reinado Duergar:  Pasillo principal");
   
   set_long("\n   Reinado Duergar:  Pasillo principal.\n\n"
	    "     Estas en el pasillo principal de la Academia Duergar.  "
	    "Hasta aqui no ves nada que te impresione en gran   "
	    "manera.  La  habitacion esta vacia,con paredes de roca "
	    "descubierta,y algunas puertas.  Las puertas tienen  unas  "
	    "placas clavadas.\n"
	    "\n");

   add_item(({"placa", "placas"}),
            "\n"
            "     Cada puerta tiene su propia placa.\n\n"
	    "La placa en la puerta norte dice:  Oficina del Maestro de "
	    "Ciencias.\n"
	    "La placa en la puerta sur  dice:   RESURRECCION.\n"
	    "La placa en la puerta noreste dice:  Oficina del Maestro  "
	    "de la Caverna.\n"
	    "La placa en la puerta noroeste dice:  Oficina de  "
	    "Exploraciones de Superficie.\n"
	    "La placa en la puerta  que conduce abajo:  Oficina de "
	    "Maestro Minero.\n"
	    "\n");

   add_exit("norte",NEWBIE+"dlev5_00","door");
   add_exit("sur",NEWBIE+"raiserm","door");
   add_exit("noreste",NEWBIE+"dlev4_00","door");
   add_exit("noroeste",NEWBIE+"dlev3_00","door");
   add_exit("abajo",NEWBIE+"dlev1_00","stair");
   add_exit("arriba",NEWBIE+"main02","stair");
}

