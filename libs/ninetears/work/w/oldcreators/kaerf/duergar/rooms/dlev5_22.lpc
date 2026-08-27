 //*This Room Re-worked by Ralkor*//

#include "path.h"
inherit "/std/underground";

object *npcs;
int mush;

void reset() {
int i;
   mush = 5;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dgoblin");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
   mush = 5;
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);

   set_short("Reinado Duergar:  Entrenamientos con Razas");

   set_long("\n  Reinado Duergar:  Entrenamientos con Razas.\n\n"
            "     En una esquina de la caverna ves unos musgos que  "
            "se extienden a lo largo de la base del muro.  Se parecen "
            "mucho a los mismos que solias comer de ninyo,cuando no "
            "tenias nada mejor para alimentarte.  Precavido, intentas "
            "decidir si arrancar uno y probarlo o dejarlo donde esta."
	    "\n\n");

   add_item(({"muro", "pared", "paredes"}),
	    "  Las paredes tienen varias marcas, dejadas por distintas "
	    "armas en las luchas que suelen tener lugar en esta zona."
	    "\n\n");

   add_item(({"musgo", "musgos"}),
            "   mirandolos con mas detenimiento podrias asegurar "
            "que son los mismos musgos que te comias anyos atras, "
            "y tambien recuerdas lo insipidos que eran."
            "\n\n");

   add_exit("sur",NEWBIE+"dlev5_28","path");
   add_exit("oeste",NEWBIE+"dlev5_21","path");
}

void init()
{
   ::init();
   add_action("pick_mushrooms","arrancar");
}
int pick_mushrooms(string str)
{
   if(str != "musgo")
   {
   return(0);
   }
   if(mush <= 0)
   {
      write("lo siento, no queda ningun musgo en este momento.\n");
      return 1;
   }
   {
     write("Arrancas un trozo de musgo del muro, lo miras un "
          "momento y te lo comes.  Mmm...no esta mal."
          "\n\n");
     this_player()->adjust_hp(random(3)+2);
   mush = mush -1;
     return(1);
   }
}
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
