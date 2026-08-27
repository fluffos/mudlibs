// A bear...

inherit "/obj/monster";

void setup() {
      set_name("bear");
      set_short("bear");
      set_race("monster");
      set_level(2+random(2));
      set_wimpy(0);
      add_alias("brown bear");
      add_adjective("large");
      add_adjective("brown");
      set_long(
         "This is a large brown bear. It seems quite hungry.\n");
      load_a_chat(50,({1, "The bear roars.\n"}));
      set_join_fight_mess("A bear smells the blood of the fight and attacks.\n");
      load_chat(10,
         ({
               1, "@growl",
               1, "The bear raise up on it's hind legs.\n",
               1, ":bares it's teeth.",
               1, ":stalks you.",
               1, "@growl nastily $lname$",
         }));
      set_random_stats(6, 18);

} /* setup() */
