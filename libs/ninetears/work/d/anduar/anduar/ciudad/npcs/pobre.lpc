inherit "/obj/monster";

void setup() {
      set_name("pobre");
      set_race_ob("/std/races/human");
      add_alias("human");
      set_main_plural("pobres");
      add_plural("humans");
      set_al(-100);
      set_random_stats(5, 12);
      set_cha(6+random(8));
      set_level(1+random(2));
      set_wimpy(10);
      add_move_zone("anduar");
      adjust_money(random(10),"copper");
      set_short("pobre");
      set_long("Es un vagabundo que mora en algun lugar desconocido de "
      "Anduar, tal vez no tenga ni donde caerse muerto, por su aspecto no "
      "ha comido en dias y no se ha banyado en anyos.\n");
load_chat(15, ({ 1, "'Desde que ampliaron la ciudad los guardianes no "
      "dejan salir a los delincuentes, pero encontre un tunel en las cloacas "
      "quitando un perro muerto.", 
                       1, "'Una limosna para un pobre muerto de hambre."}));
      add_clone("/baseobs/armours/cape",1);
::init_equip();
} /* setup() */
