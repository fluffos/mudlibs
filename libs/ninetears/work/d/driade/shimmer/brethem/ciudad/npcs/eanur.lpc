/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

#include "money.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Sacerdote Eanur");
   set_short("Sacerdote Eanur");
   set_al(-100);
   set_gender(1);
   set_main_plural("varios sacerdotes enanos parecidos a Eanur");
   add_alias("eanur");
   add_alias("sacerdote");
   add_alias("enano");
   add_alias("");
   add_plural("enanos");
   add_plural("sacerdotes");

   set_race_ob("/std/races/enano");

   add_property("NO_BUDGE", 1);

   set_max_hp(400 );
   set_hp(350);
   set_max_gp(100); 
   set_gp(100);
   set_wimpy(0);
   set_random_stats(18, 20);
   set_level(30+random(10));   
   
   set_long("Eanur, es un viejo enano que fue instruido por antiguos Clerigos enanos en las artes divinas de "
            "la curacion. Una barba blanca y larga le cuelga hasta la barriga, y sus pobladas cejas apenas dejan ver "
            "sus marrones ojos, que tienen un brillo especial, su mirada infunde armonia y tranquilidad. Es el encargado "
            "de la Catedral, de velar por la tranquilidad y de ensenyar a los nuevos sacerdotes las oraciones y plegarias. "
            "Va vestido con una tunica lisa y larga de color marron sin apenas adornos y con una gran capucha que le cuenga "
            "en la espalda.\n");
            
   set_aggressive(0);

   adjust_money(random(10), "platinum");

   load_a_chat(100,({
       1, "'Bienvenido a la Catedral de Brethem. Aqui podras encontrar paz y descanso.",
       1, ":reza unas palabas en voz baja.",
       1, "'Te agradeceriamos mucho un pequenyo donativo para la Catedral y los sacerdotes.",
       1, ":agacha la cabeza y ora unas palabra en una lenga que desconoces.",
   }));


   add_attack_spell(40, "curar heridas leves", ({"/std/spells/mago/curar_heridas_leves", "cast_spell",3,0}));   
   add_attack_spell(40, "curar heridas moderadas", ({"/std/spells/mago/curar_heridas_moderadas", "cast_spell",3,0}));  
   add_attack_spell(40, "bendicion", ({"/std/spells/mago/bendicion", "cast_spell",3,0}));  
   add_attack_spell(40, "plegaria", ({"/std/spells/mago/plegaria", "cast_spell",3,0}));  

   set_heart_beat(1);


   add_clone(BRETHEM+"equipo/tunica_sacerdote",1);
   add_clone(BRETHEM+"equipo/maza_eanur",1);
   ::init_equip();

}





void init() {
   ::init();
   add_action("do_heal", "donar");
}

int do_heal() {
   int Dark = (int)this_player()->query_value();

   switch((int)this_player()->query_level())
   {

   case 0..5:
    if(Dark >= 1000)
      {
       this_player()->pay_money((int)MONEY_HAND->create_money_array(1000));
       this_player()->adjust_hp(20);
       write_file(BRETHEM+"CURACIONES_CATEDRAL",
                  this_player()->query_short()+
                  " pago por curarse el "+
                  ctime(time())+" en la Catedral de Brethem.\n");
       write("\nTe acercas a Eanur y le entregas unas cuantas monedas como donativo, en ese momento se acerca a ti al tiempo "
             "que mueve las manos sobre tu frente rezando unas palabras calmadas, una gran sensacion de paz y tranquilidad "
             "se apodera de ti al tiempo que algunas de tus heridas mas levels desaparecen.\n\n");
       say("\n   El sacerdote pronuncia unas palabras al tiempo que toca a "+
           this_player()->query_cap_name()+" y algunas de sus heridas mas leves desaparecen.\n", ({ this_player() }));
       return (1);
       break;
      }
     else
      {
       write("\n   No tienes suficiente dinero para donar a los sacerdotes.\n\n");
       return (1);
     }

   case 6..15:
    if(Dark >= 2000)
      {
       this_player()->pay_money((int)MONEY_HAND->create_money_array(2000));
       this_player()->adjust_hp(20);
       write_file(BRETHEM+"CURACIONES_CATEDRAL",
                  this_player()->query_short()+
                  " pago por curarse el "+
                  ctime(time())+" en la Catedral de Brethem.\n");
       write("\nTe acercas a Eanur y le entregas unas cuantas monedas como donativo, en ese momento se acerca a ti al tiempo "
             "que mueve las manos sobre tu frente rezando unas palabras calmadas, una gran sensacion de paz y tranquilidad "
             "se apodera de ti al tiempo que algunas de tus heridas mas leves desaparecen.\n\n");
       say("\n   El sacerdote pronuncia unas palabras al tiempo que toca a "+
           this_player()->query_cap_name()+" y algunas de sus heridas mas leves desaparecen.\n", ({ this_player() }));
       return (1);
       break;
      }

   case 16..1000:
   if(Dark >= 4000)
     {
      this_player()->pay_money((int)MONEY_HAND->create_money_array(4000));
      this_player()->adjust_hp(20);
       write_file(BRETHEM+"CURACIONES_CATEDRAL",
                  this_player()->query_short()+
                  " pago por curarse el "+
                  ctime(time())+" en la Catedral de Brethem.\n");
       write("\nTe acercas a Eanur y le entregas unas cuantas monedas como donativo, en ese momento se acerca a ti al tiempo "
             "que mueve las manos sobre tu frente rezando unas palabras calmadas, una gran sensacion de paz y tranquilidad "
             " se apodera de ti al tiempo que algunas de tus heridas mas leves desaparecen.\n\n");
       say("\nEl sacerdote pronuncia unas palabras al tiempo que toca a "+
           this_player()->query_cap_name()+" y algunas de sus heridas mas leves desaparecen.\n", ({ this_player() }));
      return (1);
     }
   else
     {
       write("\n   No tienes suficiente dinero para donar a los sacerdotes.\n\n");
      return (1);
      break;
     }
   }
}


void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_brethem", 1, 300);
   ::attack_by(atacante);
}
