// Orc...

inherit "/obj/monster";


void setup() {
      set_name("orco");
      set_short("orco");
      set_al(60);
      set_main_plural("orcos");
      add_alias("monstruo");
      set_race("orc");
      set_level(45+random(6));
      set_wimpy(0);
	set_max_hp(250);
	set_hp(400);
	set_max_gp(500);
	set_gp(500);
	add_clone("/baseobs/weapons/battle_axe",2);
      set_random_stats(18, 19);
      set_long("Esto es un orco, un agresivo mamifero carnivoro... incluso puede que canibal.\n");
      adjust_money(random(300), "plata");
      set_aggressive(1);
      load_a_chat(30,
         ({
               1, "'Eh humin! Niis itin! FODDER!!",
               1, "@growl",
               1, "@grin evilly $lname$",
               1, ":pokes it's teeth.",
               1, "@growls nastily $lname$",
               1, ":looks at you with big red eyes.",
          }));
      set_join_fight_mess("Un orco se dispone a atacar exclamando: Waaagh, muerte i deztrukzion!\n");
//      add_triggered_action("bing2", "event_death", this_object(), "death");
//      add_triggered_action("regen", "death", this_object(), "regen_after_death");
	set_kill_xp(2000000);
	set_guild("thief");
	add_attack_spell(60, "backstab", ({"/d/gremios/comandos/backstab", "backstab",0,0}));
	this_object()->init_equip();
} /* setup() */
