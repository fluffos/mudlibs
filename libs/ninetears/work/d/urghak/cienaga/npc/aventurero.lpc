inherit "/obj/monster";

void setup () {

   set_name("aventurero");
   set_short("Aventurero");
   set_long("Es una persona que tiene como unico objetivo en su vida el afan de aventura, el demostrarse a si mismo que es capaz de afrontar los mayores peligros y vencer a todos los estupidos que osen ponerse en su camino. Su cara presenta algunas cicatrizes y sus ropajes necesitarian ser zurzidos y limpiados. Su cara es hosca, y esta sucia y descuidada.
");
   set_main_plural("aventureros");
   add_plural("humanos");
   add_plural("guerreros");
   add_alias("humano");
   add_alias("guerrero");
   set_gender (1);
   set_level(18+random(10));
   set_random_stats(16,18);
   set_race("humano");
   set_wimpy(0);
   set_max_hp(query_level() * 70);
   set_hp(query_max_hp());
   set_max_gp(query_level() * 50);
   set_gp(query_max_gp());
   set_max_ep(query_level() * 70);
   set_ep(query_max_ep());
   set_cha(11);
   load_chat(30,({
     1, "'Quieres que te ensenye a luchar?",
     2, ":acaricia el filo de su espada mirandote con aire desafiante",
     3, "'No necesito companyeros de aventuras; yo acabo con todo lo que me proponga",
     4, "'Si ves un buen monstruo o escuchas rumores de aventuras dimelo y te recompensare",
   }));
   load_a_chat(100,({
    1, "'Moriras antes de ver mi movimiento!",
    2, "'Como te atreves a desafiarme?",
    3, ":rie a carcajadas cuando el espiritu guerrero le anima a luchar",
    4, "'Con que quieres probar suerte, eh? Bien, entonces muere",
  }));
   add_clone("/baseobs/armas/espada_bastarda",1);
   add_clone("/baseobs/escudos/corporal",1);
   add_clone("/baseobs/armaduras/cota",1);
   add_clone("/baseobs/armaduras/manto",1);
   init_equip ();
   adjust_money(random(10),"oro");
 }
    
