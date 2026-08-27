inherit "/obj/monster";


void setup()
{
   set_name("owlbear");
   add_alias("owl");
   add_adjective("feroscious");
   set_al(80);
   set_race("monster");
   set_level(random(4)+6);
   set_wimpy(0);
   set_short("owlbear");
   set_main_plural("owlbears");
   // add_attack("beak", 0, 30, 160, 0, 0, "sharp-beak");
   set_long("This is ferocious owlbear. It seems to be a crossbreed "
            "between an owl and a bear.\n");
   load_a_chat(20,
      ({
                1, ":roars loudly.",
                1, ":tries to bite you with its beak.",
       }));
   set_random_stats(8,18);

}
