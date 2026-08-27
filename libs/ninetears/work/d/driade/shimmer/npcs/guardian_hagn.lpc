// Guardianes de Hagn by Shimmer

inherit "/obj/monster";

void setup() {
      set_name("guardian");
      set_short("Guardian de Hagn");
      set_main_plural("Guardianes de Hagn");
      add_plural("guardianes");
      set_long("Es un descendiente de los Guardianes del Reino de Hagn, su cometido es vigilar la entrada al reino con el fin de "
               "mantener alejados de los peligros que alli aguardan a los aventureros y exploradores que buscan "
               "los tesoros que se dice que alli aun aguardan.\n");
      set_race("humano");
      set_level(40+random(10));
      set_wimpy(0);
      set_random_stats(6, 18);
      set_al(-100+random(201));
      set_max_hp(500);
      set_hp(500);
      adjust_money(100+random(50), "gold");
      load_chat(30,
         ({
               1, "@sonrrie al verte llegar.",
               1, "'Las cienagas son peligrosas, hay muchos seres malignos alli dentro. ",
               1, "'Estoy aqui para vigilar la entrada al Reino.",
               1, "'Solo los locos irian mas alla de este Arco, pocos son los que vuelven. ",
               1, "'Hace mucho que nadie sabe nada sobre las Torres, se decia que alli habia muchos tesoros."
          }));
    
      new("/baseobs/armours/chainmail")->move(this_object());
      new("/baseobs/shields/corporal")->move(this_object());
      new("/baseobs/weapons/bastard_sword")->move(this_object());
      this_object()->init_equip();

}
