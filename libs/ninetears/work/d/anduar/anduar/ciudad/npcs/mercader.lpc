inherit "/obj/monster";

void setup() {
      set_name("mercader");
      set_race_ob("/std/races/human");
      add_alias("human");
      set_main_plural("mercaderes");
      add_plural("mercaderes");
      add_plural("humans");
      set_al(10);
      set_random_stats(6, 17);
      set_cha(6+random(10));
      set_level(1+random(5));
      set_wimpy(10);
      adjust_money(random(20),"silver");
      set_short("mercader");
      set_long("Es un mercader que vende o intercambia bienes. Por la pinta "
               "que tiene parece mas un charlatan que un comerciante.\n");
      load_chat(50, ({ 1, "'Lo mio es mas barato.", 
        1, "'Ni cinco, ni cuatro, ni tres, ni dos, solo una moneda.",
       1, "'Ahora 3 por el precio de 2.",
                       1, "'Comprad, buen hombre."}));
      add_clone("/baseobs/armours/cape",1);
      ::init_equip();
   add_move_zone("anduar");
} /* setup() */
