/*  Text alterations and replacement by Grimbrand 2-1-96                 */

#include "path.h"
inherit "/std/underground";

void setup() {
    add_property("no_undead",1); set_light(10);

   set_short("Reinado Duergar:     Zona Aprendices.");

   set_long("\n   Reinado Duergar:  Zona Aprendices.\n\n"
	 "     Has entrado en un cuarto de suelo y muros irregulares. "
	 " Suelo ,paredes y hasta el techo,son de un material granitico "
	 "de aspecto suave y fino ,sin embargo,excepto algunas marcas "
	 "diseminadas.  Los unicos objetos en el cuarto son unas pocas "
	 "rocas ,todas ellas de forma y tamanyo irregular.  No cabe "
	 "duda que las rocas han sido dejadas aqui para que las trabajes. "
	 "Cubriendo las paredes hay una especie  de extranyo musgo "
	 "que emite  su propia luz,iluminando la estancia .\n"
	 "\n");

   add_item("rocas",
	 "   Miras las rocas y ves que son todas rugosas e informes.  "
	 "Recuerdas lo que dijo Hewlen y piensas que mejor empezar "
	 "a picar las rocas si quieres tener esperanzas de progreso "
	 "aqui.\n\n");

   add_item("muros",
	 "   Al mirar los muros notas en varias zonas como si alguien "
	 "hubiera intentado hacer un tunel para traspasar la pared. "
	 "Te preguntas para que querria alguien molestarse en picar  "
	 "paredes para llegar probablemente a otro cuarto igual a "
	 "este.\n");

   add_item("musgo",
	 "   Te fijas que este musgo crece directamente sobre la  "
	 "roca.  Emite una suave luz azulada que ilumina lo suficiente "
	 "como para poder trabajar en la zona  cercana a el.\n");    

    add_exit("noreste",NEWBIE+"dlev1_01","path");
    add_exit("norte",NEWBIE+"dlev1_03","path");
    add_exit("oeste",NEWBIE+"dlev1_06","door");
    add_clone(DNPC+"rat",1);
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

   if((arg == "roca") || (arg == "rocas") || (arg == "muro") || 
      (arg == "muros") || (arg == "suelo") || (arg == "pared") || 
      (arg == "paredes")) 
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

   if(pick <= 30)
     {
      write("   Aqui aun no puedes picar,debes ganar un poco de experiencia "
    	    "picando antes en otro cuarto.\n"
	    "\n");
      this_player()->add_property("pick",pick);
      return 1;
     }
	    
   if(pick <= 32) 
     {
      write("   Haces oscilar el pico y lo alzas para dejarlo caer con "
	    "fuerza, aunque con mala punteria y solo arrancas un trocito " 
	    "de roca.\n"
	    "\n");
      xp = (16 + random(5));
      this_player()->adjust_xp(xp);
      pick = pick+1;
      this_player()->add_property("pick",pick); 
      return 1;
     }
    else 
      if(pick <= 34) 
	{
	 write("   En un movimiento mas controlado, apuntas bien, y "
	       "alzas el pico.  Tu golpe desgaja un trozo de roca "
	       "bastante grande, aunque su forma irregular no parece "
	       "ser muy aprovechable.\n"
	       "\n");
	 xp = (18 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}  

    else 
      if(pick <= 36) 
	{
	 write("   Con mano firme, haces un arco con el pico, que "
	       "golpea justo donde tu querias, y arrancas una pieza de "
	       "roca mas o menos aplanada.\n"
	       "\n");
	 xp = (20 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}

    else 
      if(pick <= 40) 
	{
	 write("   De un vistazo calibras la roca, y con unos rapidos "
	       "y expertos golpes de tu pico, trabajas la roca "
	       "transformandola en un bloque de piedra estupendo "
	       "para la construccion.\n"
	       "\n");
	 xp = (21 + random(5));
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

   if((arg == "estalagmita") || (arg == "estalagmitas") || 
      (arg == "estalagtita") || (arg == "estalagtitas")) 
     {
      pick = this_player()->query_property("pick");
      
      if(!present("pico", this_player()))
	{
	 return 0;
	}
   
      it = find_match("skiepick",this_player());
      if((int)it[0]->query_property("PICKUSED")!=1)
	{
	 write("   Debes empunyar el pico antes.\n\n");
	 return 1;
	}

      if(pick <= 25) 
	{
	 write("   De forma mas bien torpe alzas el pico, y "
	       "haces anyicos el unico bloque que casi estaba "
	       "listo para su uso.  Vaya chapuza!\n"
	       "\n");
	 xp = (18+random(10));
	 this_player()->adjust_xp(xp);
	 pick = pick + 1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}
      else 
	 if(pick <=50) 
	   {
	    write("    En un movimiento mas controlado, apuntas bien, y "
		  " alzas el pico.  Tu golpe desgaja un trozo de roca "
		  "bastante grande, aunque su forma irregular no parece "
		  "ser muy aprovechable.\n"
		  "\n");
	    xp = (19+random(10));
	    this_player()->adjust_xp(xp);
	    pick = pick +1;
	    this_player()->add_property("pick",pick);
	    return 1;
	   }
	 else 
	    if(pick <= 75) 
	      {
	       write("   Con mano firme, haces un arco con el pico, que "
	                       "golpea justo donde tu querias, y arrancas una pieza de "
	                       "roca mas o menos aplanada.\n"
	                       "\n");
	       xp = (20+random(10));
	       pick = pick + 1;
	       this_player()->add_property("pick",pick);
	       this_player()->adjust_xp(xp);
	       return 1;
	      }
	    else 
	       if(pick < 100) 
		 {
		  write("   De un vistazo calibras la roca, y con unos rapidos "
	      		"y expertos golpes de tu pico, trabajas la roca "
			"transformandola en un bloque de piedra estupendo "
			"para la construccion.\n"
			"\n");

		  xp = (21+random(10));
		  this_player()->adjust_xp(xp);
		  pick = pick + 1;
		  this_player()->add_property("pick",pick);
		  return 1;
		 }
	       else 
		  if(pick = 100) 
		    {
		     this_player()->remove_property("pick");
		     this_player()->add_property("no_pick",1);
		     write("    Al alzar tu pico notas que tiene una "
	    		  "gran raja que le recorre el mango. Imposible "
	    		  "usarlo ahora.\n"
			   "\n");
		     it[0]->dest_me();
		     return 1;
		    }
     }

   if(arg != "xyxyxy") 
     {
      write("   Juegas con tu pico.\n\n");
      return 1;
     }
return 0;
}


