/*  Text edited by Grimbrand 2-2-96                                    */

inherit "/obj/monster";

void setup() {
      set_name("minotauro");
      add_adjective("brutal");
      add_adjective("gran");
      set_race("minotaur");
   set_level(4);
      set_wimpy(0);
      set_random_stats(12, 18);
      set_al(50);
   set_max_hp(16);
   set_kill_xp(94);
      set_short("gran minotaur");
      set_main_plural("grandes minotauros");
   set_long("   Es uno de los famosos minotauros.  Parece tener "
            "ganas de invitarte a luchar.  La verdad, su aspecto "
            "resulta increiblemente brutal, tal vez debieras "
            "tragarte tu orgullo e ir a molestar a algun otro."
            "\n\n");
      load_chat(10,
         ({
               1, "'Vemm akquii y pehleea commigoo.",
               1, "'Demmmueghtrammee cuommo eeregh dee buemmo enn cuommbatee.",
               1, "'Supjetah biiemm tu armma ii lugcha, cuobarde!",
               1, ":hace girar su hacha.",
               1, ":brama en reto a  $lname$",
          }));
      load_a_chat(20,
         ({
               1, "'Fimnalmuente uuma luugcha!",
               1, "'Mmmh.. ehres bruavoo!",
               1, "'pruomto habrhas mmuertuo! HUM!",
          }));
      new("/baseobs/weapons/hand_axe")->move(this_object());
      set_join_fight_mess("El minotauro, contento exclama: MMUEGRTEE!.\n");
      add_triggered_action("bing2", "event_death", this_object(), "death");
      this_object()->init_equip();
   adjust_money(3,"oro");
} /* setup() */
