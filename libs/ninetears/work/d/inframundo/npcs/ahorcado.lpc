// Valar 23/11/02

    inherit "/obj/monster";

    void setup() {

     set_name("ahorcado");
     set_short("ahorcado");
     set_long("Te encuantras ante un alma condenada a morir ahorcado por las multiples victimas "
     " que asesino con sus propias manos y que sufrieron estrangulamientos.\n");


     set_main_plural("ahorcados");
     set_gender(0);
     set_level(10+random(5));
     set_random_stats(18, 20);

     load_chat(30,({
             1, "'Creeis que este es mi fin?. Pues seguid soando!!.",
                2, ":te mira fijamente. Yo te recuerdo!!", 
             1, "'Dadme otra oportunidad.",
 	     2, ":sonrie maliciosamente.", // con : es un emote

                     }));

load_a_chat(100,({
                     1, "'No  podreis conmigo!",
                     1, ":te mira con ojos llameantes.",
                     2, ":ve como se le va acercando su hora.",
				}));
}
