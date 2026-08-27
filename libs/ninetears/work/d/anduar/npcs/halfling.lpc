inherit "/obj/monster";

void setup() {
      int i;
      set_race("halfling");
      i=random(3);
      if(i==0)
      {
         set_name("paseante");
         set_short("Paseante");         
         add_alias("paseante");
         set_main_plural("Paseantes");
         set_long("Un halfling que mata el tiempo paseando por las "
         "calles de su ciudad.\n"); 
         set_gender(1);    
      }
      else if(i==1)
      {
         if(random(2))
         {
           set_name("halfing simpatico");
           set_short("Halfling simpatico");
           set_main_plural("Halflings simpaticos");
           add_alias("simpatico");
           set_long("Es un halfling de una edad no muy avanzada, su "
           "rostro te muestra que se trata de un gracioso halfling.\n");
           set_gender(1);
         }
         else
         {
           set_name("halfling");
           set_short("Halfling");
           set_main_plural("Halflings");
           set_long("Es una halfling normal y corriente. Parece "
           "que esta ya muy acostumbrada a convivir con los humanos en "
           "esta ciudad.\n");
            set_gender(2);
         }
      }
      else
      {
         if(random(2))
         {
           set_name("viejo");
           set_short("Viejo");
           set_main_plural("Viejos");
           add_alias("viejo");
           set_long("Un halfling de muy avanzada edad cuenta sus historias "
           "a cualquiera que quiera escucharlas, pero tu no tienes tiempo de "
           "oirlas.\n");
           set_gender(1);
         }
         else
         {
           set_name("vieja");
           set_short("Vieja");
           set_main_plural("Viejas");
           add_alias("vieja");
           set_long("Una agradable anciana que debe estar esperando que "
           "llegue algien por la calle para charlar un rato con el.\n");
            set_gender(2);
         }
      }
      
          add_plural("halflings");
      set_race_ob("/std/races/halfling");
      set_level(random(5)+10);
      adjust_money(1+random(2),"silver");
      load_chat(10,
         ({
               1, ":te saluda.",
               1, ":te sonrie.",
          }));
      load_a_chat(30,
         ({
               1, "'pero porque me atacas?",
               1, "'Aaayyyyy!!!",
               1, ":intenta huir de ti."
          }));

} /* setup() */

