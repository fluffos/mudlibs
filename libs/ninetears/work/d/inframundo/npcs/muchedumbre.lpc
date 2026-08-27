// Valar 23/11/02

    inherit "/obj/monster";

    void setup() {

     set_name("muchedumbre");
set_short("muchedumbre");
     set_long("Estas son las victimas del asesino estrangulador. Es una muchedumbre enfurecida "
     " que por fin podra gozar de su merecido descanso eterno al hacerse justicia.\n");

     set_main_plural("muchedumbre");
     set_gender(0);
     set_level(10+random(5));
     set_random_stats(18, 20);

     load_chat(30,({
             1, "'Esta vez si que pagaras por tus crimenes!!!.",
             2, "'Creiste que podrias escapar a tu destino?",    
             1, "'Que lo ahorquen ya!!!!.",
 	     2, ":comienza a lanzar frutas podridas contra el ahorcado.", 
                     }));

     load_a_chat(100,({
                     1, "'Pronto recibiras tu merecido!!!",
                     2, ":se lanza contra el ahorcado.",
				}));
}
