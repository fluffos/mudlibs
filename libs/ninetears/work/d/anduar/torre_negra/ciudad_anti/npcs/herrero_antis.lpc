// Herrero de la ciudad de los Antipaladines
// Sinister 28 Julio 00


inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("herrero");
      set_short("herrero");
      set_al(60);
      set_gender(1);
      add_alias("human");
      set_race_ob("/std/races/human");
      set_guild_ob("/std/guilds/warriors/fighter");
      set_wimpy(0);
      set_random_stats(16, 18);
      set_str(18);
      set_con(18);
      set_dex(18);
      set_cha(14+random(5));
      set_level(16+random(8));
      set_long("Anti esta esta un fornido trabajador del metal.\n"
      "Toda su vida se a dedicado a trabajar el mismo, siempre "
      "sudoroso y negro como el carbon, chamuscado por la forja "
      "que hay en la habitacion.\n");
      adjust_money(random(10), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Ni el mismisimo Oksuro aguantaria tanta calor!",
               1, ":golpea una barra de metal incandescente.",
               1, ":introduce en el agua una pieza recien forjada y empieza "
               "a salir vapor.",
               1, ":inspecciona una arma nueva.",
               1, "'Aqui podeis arreglar las armas, pagando, claro.",
          }));
      
      add_clone("/baseobs/weapons/short_sword",1);
      add_clone("/baseobs/armours/leather",1);
      add_clone("/baseobs/armours/helmet",1);
      ::init_equip();
}

