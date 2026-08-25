/* File upgrade by Grimbrand 2-11-96                                    */

inherit "/obj/monster";

void setup() {
   set_name("old lady");
   set_short("Old lady");
   set_long("   This old duergar lady looks about as old as the kitchen "
            "that she works in.  Some say that has been the cook ever "
            "since it opened, having served every young duergar that "
            "has ever gone through the academy."
            "\n\n");
   add_alias("lady");
   set_race("duergar");
   set_gender(2);
   set_random_stats(6, 18);
   set_max_hp(200);
   set_kill_xp(100);
   set_guild("fighter");
   set_level(22);
   set_al(-150);
  load_chat(30, ({
     1,"' Come in and eat.",
     1,"' Have a nice bowl of stew.",
     1,"' Don't forget to close the oven!!",
  }));
  load_a_chat(60,  ({
     1, "' How dare you attack a poor little old lady!",
     1, ":hits you over the head with a frying pan.",
     1, ":pokes you in the eye with her cane.",
     1, ":slaps you in the face."
  }));
}
