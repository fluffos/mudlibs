inherit "/obj/monster";

void setup() {
      add_alias("dendara");
      set_name("mercader");
      set_race_ob("/std/races/human");
      add_alias("human");
      set_main_plural("mercaderes de Dendara");
      add_plural("mercaderes");
      add_plural("humanos");
      set_al(-10);
      set_random_stats(8, 17);
      set_cha(8+random(8));
     set_level(15+random(5));
set_gender(1);
      set_wimpy(5);
      adjust_money(random(50),"silver");
      set_short("mercader de Dendara");
      set_long("Es un mercader que parece haber recorrido la gran distancia "
      "que separa Dendara de Anduar, lo mas seguro que venga a vender alguna "
      "exotica mercancia y comprar otras para venderlas en su ciudad de "
      "origen.\n");
      load_chat(10, ({ 1, "'Disculpe caballero sabrias vos si la ciudad de "
      "Anduar queda muy lejos de este lugar?", 
      1, "'Seria usted tan amable de indicarme una posada en la cual "
      "alojarme en Anduar?",
      1, "'Esta nueva ruta es mas segura que la antigua, ya que los ladrones "
      "no abundan tanto como en la antigua.",
   }));
   add_clone("/baseobs/armours/cape",1);
   init_equip();
}/*setup*/
