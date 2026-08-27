/* Helrek, Guild Master de los Ladrones */
/* Funciones de punyalada en combate, Oskuro i Paris MAY '98 */
/* Es un bastardo gracias a Guldan MAY '98 */
/* Y gracias a Valdor no le haran mucha pupa */
inherit "/obj/monster";
#include "../path.h"

int query_res(string str)
{
 return 70;
}
 

void setup()
{
      set_name("helrek");
      set_short("%^BOLD%^Helrek%^RESET%^ el Maestro Ladron");
      set_long("Helrek es el mejor ladron que el mundo ha conocido nunca. "
         "Sus hazanyas en el mundo oculto de los ladrones se cuentan por "
         "miles e innumerables paginas de libros estan escritas con su "
         "leyenda. Rapidisimo en combate, sigiloso en el robo, mortal con "
         "su punyalada. Helrek es sin duda el ladron en el que tu, aprendiz, "
         "debes fijarte.\nSi decides enfrentarte a el, seguramente entraras "
         "en su larga lista de victimas mortales.\n"); 
      add_alias("master");
      add_alias("ladron");
      add_alias("maestro");
      set_al(0);
      set_main_plural("Helreks");
      add_plural("Helreks");
      set_str(19);
      set_dex(25);
      set_con(20);
      set_int(20+random(21));
      set_wis(20+random(21)); // Para ke se salve de las punyaladas
      set_cha(20+random(21));
      set_race("Goblin");
      set_race_ob("/std/races/goblin");
      set_language("common");
      set_wimpy(0);
      set_guild_ob("/std/guilds/rogues/thief");
      set_gender(1);
      adjust_money(30+random(11),"platinum");
      set_aggressive(0);
      set_level(90);
      set_max_hp((query_max_hp()+250));
      adjust_gp(query_max_gp());
     set_align(100);
//      adjust_tmp_damage_bon(1+random(query_level()/10));
      set_ac(80);
      
      add_timed_property("poison",roll(9,10),90000000);
      add_property("nodisarm",1);
      add_property("nosteal",1);
      
      load_chat(30,
	 ({
	       1, "'Si, soy uno de los Grandes Ladrones.",
	       1, "'Soy el maestro de tu Gremio, preguntame lo que quieras, "
	          "pequenyo ladron.",
	       1, "'Si necesitas equiparte, habla con Galiak, uno de mis "
	          "mejores discipulos.",
               1, "'Si quieres saber lo que es el dolor, atacame.",
               1, "'Grandes batallas he vivido. En muchos ejercitos he "
                  "militado. Pero sobre todo, a muchas victimas he "
                  "apunyalado.",
/*
               1, "'Maldito aquel dia en que la Gran Daga fue rota en siete "
                  "pedazos y dispersada por todo el Continente.",
               1, "'Desde el dia que perdi mi preciosa Daga, mis punyaladas "
                  "no han vuelto a ser lo mismo.",
               1, "'El Dios Oskuro me impide hablarte ahora de como conseguir "
                  "la daga. Cuando El lo quiera, te dare alguna pista.",
*/
               1, ":se ajusta su equipo %^BLACK%^BOLD%^Itzalak%^RESET%^. "
                  "Con el, parece invencible!",
	  }));

      load_a_chat(65,
	 ({
	       1, "'Mmm, has resistido a mi punyalada... buen ladron...",
	       1, "'Esa no ha sido tu mejor ocurrencia.",
	       1, "'Pretendia ensenyarte todos mis conocimientos, quizas "
	          "hubieses llegado al nivel de Galiak... pero ya veo que "
	          "tan solo eres un cobarde rufian.",
	       1, "'No mereces pertenecer a este guild!! Ahora veras!",
               1, "'Soy uno de los Grandes Ladrones. De verdad pretendes "
                  "matarme?",
               1, ":sonrie maliciosamente. Parece seguro de su victoria.",
	  }));

      add_clone(ITEMS+"cota_itzalak",1);
      add_clone(ITEMS+"capa_itzalak",1);
      add_clone(ITEMS+"capucha_itzalak",1);
//      add_clone("/baseobs/weapons/dagger",2);
      add_clone("/baseobs/weapons/long_sword",2);
      set_join_fight_mess("Helrek te dice: Lo siento... hoy no es tu dia de "
         "suerte...\n");
      init_equip();
}

void init()
{
    add_attack_spell(40,"desarmar",({"/std/commands/desarmar","desarmar",0,0}));
   ::init();
}

int apunyalar(object atacante)
{
   int base1=atacante->query_hp();
   int base2=query_level()-atacante->query_level();
   int danyo=random(base1/2)+random(base2/2)+1;
   int tiempo=atacante->query_level();
   int tope=atacante->query_hp();
   
   if (query_property("apunyalo")) return 0;
   add_timed_property("apunyalo",1,2);
   
   danyo=danyo>tope?tope:danyo;
   atacante->adjust_hp(-danyo,TO);
   
   tell_object(atacante,"Convulsionas en agonia cuando %^BOLD%^Helrek%^RESET%^ "
       "clava su daga en tu espalda.\nEso realmente dolio!\n");
   tell_room(environment(TO),atacante->query_cap_name()+" convulsiona en "
       "agonia cuando %^BOLD%^Helrek%^RESET%^ clava su daga en su "
       "espalda!\n",({TO,atacante}));
       
//   adjust_tmp_damage_bon(1);
   
   tiempo=tiempo+danyo/10+2;
   
   if (atacante->query_guild_ob()!=query_guild_ob()) 
   {
       tiempo/=5;
       adjust_tmp_damage_bon(random(atacante->query_level()/10)+1);
   }

   add_timed_property(atacante->query_name(),1,tiempo);
   atacante->attack_by(TO);
   atacante->attack_ob(TO);
}

void attack_by(object att)
{
   if ( (!query_timed_property(att->query_name())) && 
        (!att->query_dead()) ) 
   {
     if (att->query_guild_ob()!=query_guild_ob()) apunyalar(att);
     else if (!random(5)) apunyalar(att);
   }
   ::attack_by(att);
}

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("mata_rufianes"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Vuelve a atacar a tus maestros y volveras a morir.");
         ob->remove_timed_property("mata_rufianes");
         remove_timed_property(ob->query_name());
      }
      else if (!query_property(ob->query_name())) apunyalar(ob);
      else attack_ob(ob);
   }
   ::event_enter(ob, mensaje, donde);
}
