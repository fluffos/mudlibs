inherit "/obj/monster";

void setup() {
      set_name("nomada");
      set_race_ob("/std/races/human");
      add_alias("human");
      set_main_plural("nomadas");
      add_plural("nomadas");
      add_plural("humans");
      set_al(-10);
      set_random_stats(10, 17);
      set_cha(6+random(10));
      set_level(5+random(5));
      set_wimpy(10);
   add_move_zone("anduar");
      adjust_money(random(50),"silver");
      set_short("nomada");
      set_long("Es un nomada que viaja recorriendo el mundo sobreviviendoa base "
      "de comprar o intercambiar bienes.\n");
      load_chat(50, ({ 1, "'Esta zona es muy peligrosa, es mejor que te vayas.", 
                       1, "'No tengo casa fija, por eso viajo tanto.",
                       1, "'Si vas a la cienaga ten mucho cuidado",
                       1, "'Aquellas dos torres son preciosas, verdad?."}));
      add_clone("/baseobs/armours/cape",1);
      ::init_equip();
} /* setup() */