// Cloaca. C2.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo secundario%^RESET%^");
   set_long("Bajo tus pies crujen los tipicos escarabajos de cloaca; cosa que te "
            "repugna. Notas como la luz ha bajado levemente su intensidad, piensas que "
            "es por la profundidad. Empiezas a notar la humedad. \n");

   add_item("suelo", "Ves pequenyos insectos correr a tu alrededor.\n");
   add_item("pared", "La pared es resbaladiza.\n");
    add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"murcielago",2);

   add_exit("norte", CLOACAS+"c1", "corridor");
   add_exit("sur", CLOACAS+"c3", "corridor");

   set_light(20);
}
