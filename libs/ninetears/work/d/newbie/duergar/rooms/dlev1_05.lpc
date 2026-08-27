/*  Text alterations and replacement by Grimbrand 2-1-96                */

#include "path.h"
inherit "/std/underground";

void setup() {
  add_property("no_undead",1); set_light(10);
set_short("Reino Duergar:Zona Aprendices -Compartimento secreto-");
set_long("\n   Reinado Duergar: Zona Aprendices -Compartimento .\n\n"
	 "     . Este cuarto parece una de las cuevas que podrias ver "
	 "afuera,en la suboscuridad.  Las paredes,de aspera roca "
	 "naturalmente,lucen intensamente por el extranyo musgo de las " 
	 "paredes,esto le da un hermos efecto.  El cuarto,en comparacion "
	 "con el resto,parece no haber sido nunca tocado por ningun  "
	 "mortal.  Las formaciones de roca y cristal son del todo "
	 "impresionantes, ciertamente un trabajo solo para dioses. Las "
	 "estalagmitas y estalactitas estan perfectamente formadas "
	 "y resplandecen  gracias a la humedad,la misma que las hace  "
	 "crecer. Estas maravillas en piedra son perfectas para conver"
	 "tirlas en bloques por un experto minero.\n"
	 "\n");

add_item(({"formacion", "formaciones", "formaciones de roca", 
	   "formaciones de cristal"}),
	 "   Cuando miras el cuarto ves formaciones de todo tipo  "
	 "y forma.  Incluso hay algunas gemas destelleando  con "
	 "un abanico de colores,como solo verias en el exterior. "
	 "Parecen buen material para entrenar con tu pico.\n\n");
	 
add_item(({"roca", "rocas"}),
	 "  Ves muchas variedades diversas de roca y minerales "
	 ",tantas que te sientes incapaz de identificarlas todas.\n\n");
	 
add_item(({"cristales", "cristal"}),
	 "    Cristales de todos los colores pueden verse a todo lo "
	 "largo del cuarto.  Alguno incluso de un color oscuro "
	 "tan intenso que entra dentro del espectro de vision de "
	 "las criaturas de la suboscuridad.  Estos cristales oscuros "
	 "son de gran valor,aunque estos no son bastante  grandes "
	 "como para molestarse en cogerlos.\n\n");

add_item(({"muro", "muros","pared"}),
	 "  Los muros parecen hechos de algun tipo de pizarra, "
	 "aunque dificil de describir.\n\n");


add_item("moss",
	 "   Te fijas que este musgo crece directamente sobre la "
	 "roca.  Emite una suave luz azulada que ilumina lo suficiente "
	 "como para poder trabajar en la zona  cercana a el.\n");

add_item(({"estalactitas", "estalagmitas"}),
	 "Con ellas podrias hacer un estupendo trabajo y ganar "
	 "en experiencia.\n\n");

add_clone(DNPC+"rat",3);
   add_exit("este",NEWBIE+"dlev1_03","door");
   add_exit("norte",NEWBIE+"dlev1_10","door");
   add_exit("oeste",NEWBIE+"dlev1_08","door");
}

void init() {
   ::init();
   add_action("pickstuff", "picar");
   add_action("pickstuff","swing");
   if((!this_player()->query_property("no_pick"))&&
      (!this_player()->query_property("pick")))
	this_player()->add_property("pick");
}

int pickstuff(string arg) {
   object *it;
   int xp,pick;


   if(!arg) return 0;

   if((int)this_player()->query_property("no_pick")==1)
      return 0;

   if((arg == "estalactita") || (arg == "estalactitas") || (arg == "estalagmita") || 
      (arg == "estalagmitas") || (arg == "formacion") || (arg == "formaciones") || 
      (arg == "cristal") || (arg == "cristales")) 
     {
      pick=this_player()->query_property("pick");

   if(!present("pico", this_player()))
     {
      return 0;
     }
   
   it = find_match("skiepick",this_player());
   if(!sizeof(it)) return 0; // taniwha
 
   if((int)it[0]->query_property("PICKUSED")!=1)
     {
      write("   Necesitas empunyar el pico antes.\n\n");
      return 1;
     }

   if(pick <= 40)
     {
      write("   Aqui aun no puedes picar,debes ganar un poco de experiencia "
    	    "picando antes en otro cuarto.\n"
	    "\n");
      this_player()->add_property("pick",pick);
      return 1;
     }	    

   if(pick <= 41) 
     {
      write("   Haces oscilar el pico y lo alzas para dejarlo caer con "
	    "fuerza, aunque con mala punteria y solo arrancas un trocito " 
	    "de roca.\n"
	    "\n");
      xp = (20 + random(5));
      this_player()->adjust_xp(xp);
      pick = pick+1;
      this_player()->add_property("pick",pick); 
      return 1;
     }
    else 
      if(pick <= 43) 
	{
	 write("   En un movimiento mas controlado, apuntas bien, y "
	       "alzas el pico.  Tu golpe desgaja un trozo de estalactita "
	       "bastante grande, aunque su forma irregular no parece "
	       "ser muy aprovechable.\n"
	       "\n");
	 xp = (21 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}  

    else 
      if(pick <= 45) 
	{
	 write("   Con mano firme, haces un arco con el pico, que "
	       "golpea justo donde tu querias, y arrancas una pieza de "
	       "la formacion de roca mas o menos aplanada.\n"
	       "\n");
	 xp = (24 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}

    else 
      if(pick <= 50) 
	{
	 write("   De un vistazo calibras el punto ideal, y con unos rapidos "
	       "y expertos golpes de tu pico, trabajas la formacion cristalina "
	       "transformandola en un bloque de piedra estupendo para "
	       "para el uso ornamental en alguna catedral tal vez.\n"
	       "\n");
	 xp = (27 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}
    else
      if(pick <=100)
      {
       write("	 Al picar se ha levantado polvareda y no puedes ver bien, "
             "mejor cambiar de zona.\n"
    	     "\n");	 		
//	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	} 
   
   if(pick = 100) 
     {
      this_player()->remove_property("pick");
      this_player()->add_property("no_pick",1);
      write("   Al alzar tu pico notas que tiene una "
	    "gran raja que le recorre el mango. Imposible "
	    "usarlo ahora.\n"
	    "\n");
      it[0]->dest_me();
      return 1;
     }
   return 1;
}


   if(arg != "xyxyxy") 
     {
      write("   Juegas con tu pico.\n\n");
      return 1;
     }
return 0;
}


