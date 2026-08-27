//Valdor '99

#include "path.h"

inherit "/std/room.c";

void setup()
{
   set_short("\n %^GREEN%^BOLD%^Camara %^RESET%^de los %^BOLD%^sentidos%^RESET%^\n\n");

   set_long("Entras en una habitacion esplendorosa, Una gran fuente en el centro revosa de un "
		" liquido muy peculiar. El zumbido del mosquito te hace perder los nervios e intentas "
		"desesperadamente que se vaya. Unas flores se alzan alrededor de la fuente como retando "
		"a quien sea a acercarse. En esta habitacion se pretende que explores tus sentidos...Tacto"
		", olfato, oidos, gusto, ...\n\n");

   set_light(50);

   add_item ("fuente","Impresionante, y con inscripciones rellenas por todos los lados, la fuente parece"
		 "viva ella misma.\n");
   add_item("inscripciones","se lee...Aquel que beba de la fuente sera eterno.\n");
   add_item("liquido","Como no.....es el nectar de la vida, con el cual te hicieron inmortal, solo de pensar"
		" en el se te hace la boca agua por su buen sabor.\n");
   add_item (({"flor","flores"}),"Son rosas de unos dos metros de altura y tulipanes cubriendo a estas.\n");
   add_item (({"rosa","rosas","tulipan","tulipanes"}),"Seguro que huelen maravillosamente, parecen muy bien cuidados"
			". Son impresionantes.\n");
   add_item("nectar","amarillo cobrizo, parece miel en estado liquido. El nectar suelta una especie de zumbido.\n");
   //Siempre que se pueda se ha de poner items para lo que sea..intenta preveer lo que intentara mirar el jugador
   // y haz un item de ello..a parte de los que quieras poner por necesidad.

   add_sound(({"zumbido","nectar"}),"El nectar suelta un ruidillo parecido a una tonadita angelical. Te quedarias toda la "
		           "eternidad escuchandolo.\n");
   add_sound("mosquito","Ese impertinente mosquito te esta destrozando los nervios...matalo.\n");

   add_smell(({"flor","flores","rosa","rosas","tulipan","tulipanes"}),"Huelen muy bien, te hacen sentir en la gloria.\n");
   add_smell(({"liquido","nectar"}),"al olerlo sientes un irremediable impulso de beber.\n");

   add_feel(({"nectar","liquido"}),"El calido tacto del nectar en tu piel te adormece.\n");
   add_feel(({"flor","flores","rosa","rosas","tulipan","tulipanes"}),"Auch!!,te has pinchado.\n");
   add_feel("fuente","rugosa, pero muy  bien pulida. Obra de un profesional.\n");

   add_taste("liquido","Sabe muuuuuy bien.\n");
 
   //Como veis no es tna dificil meter sentidos en una habitacion.
   add_clone(NPC+"mosquito",1);

   add_exit("sur",APRENDICES+"pasillo_1","door");

}

void init()
{
   ::init();
   add_action("beber","beber");
   add_action("trampa",({"go","goback","goto","dest","ed","home"}));
}

int beber(string str)
{
   if(str == "nectar" )
   {
      write("Bebes un poco del nectar de la inmortalidad.\n");
      TP->adjust_hp(50);
      TP->adjust_volume(9999);
      say(this_player()->query_cap_name()+" se acerca a la fuente y bebe un poco del nectar de la inmortalidad.\n");
      return(1);
   }
   notify_fail("No puedes beber nada que no sea el nectar aqui.\n");
   return(0);
   
}

int trampa()
{
  write("Nonono eres un trampos...sal cuando lo hayas comprendido.\n");
 return 1;
}



