/* Editado por Shimmer */

inherit "/obj/monster";


void setup() {
         set_name("hiena");
         set_short("hiena");
         set_main_plural("hienas");
	 set_random_stats(6,14);
         set_long("Es una feroz hiena dispuesta a atacarte al menor movimiento,"
                  "su cuerpo esta cubierto de sucio pelo y no para de rascarse debido "
                  "a los numerosos parasitos que desprende. Las hienas suelen ir en manadas, "
                  "por lo que si te cruzas con una, seguro que las demas andaran rondando.\n");
         set_aggressive(1);
         set_race("hiena");
         set_level(4+random(2));
         set_gender(1);
         load_chat(50,
         ({
               1, ":te mira enrabietada.",
               1, ":te observa detenidamente.",
               1, ":babea mientras se fija en tu yugular.",
          }));
          add_move_zone("hagn");
          set_move_after(20+random(10), 20+random(10));

}