// Senyor Comellas. Gestur 12-10-97

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("comellas");
   set_short("Senyor Comellas");
   set_al(-1000);
   set_gender(1);
   add_alias("senyor");
   add_alias("humano");
   add_alias("human");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(15, 17);
   set_str(17);
   set_dex(15);
   set_con(17); 
   set_cha(22);
   set_level(10+random(10));
   set_long("Es el Senyor Comellas, el duenyo de este hostal. Es "
            "un senyor de una altura mediana y con un poco de "
            "sobrepeso. Se comenta que puede que sea una de las "
            "personas mas amables y hospitalarias de este planeta por "
            "los continuos favores que realiza a la gente.\n");
   adjust_money(random(1000), "copper");
   set_aggressive(0);
   load_chat(30,
   ({
      1, "'Buenos dias senyor, deseaba tomar algo?.",
      1, "'Si deseais ir a Dendara, el camino es hacia el noreste.",
      1, "'En la taberna de Koskar en Anduar podreis encontrar"+
         " una gran variedad de asados.",
      1, ":limpia la barra."
   }));
}
