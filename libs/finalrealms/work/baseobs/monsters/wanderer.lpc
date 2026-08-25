// The famous norwegian wanderer... :)

inherit "/obj/monster";

void setup() {
      set_name("wanderer");
      add_alias("wandering man");
      add_alias("tourist");
      set_al(-40+random(60));
      set_race("human");
      set_level(1+random(4));
      set_short("wanderer");
      set_plurals("wanderers");
      set_random_stats(6, 18);
      set_long("This is a wanderer from some distant country.\n"
         "He's busy acting like a tourist (gawking).\n");
      adjust_money(random(10), "copper");
      load_chat(10,
         ({
               1, "'Hvor er severdighetene her ?",
               1, "'Unnskyld, snakker De norsk ?",
               1, "'Vet du om de har Ringnes i pubene her ?",
               1, ":gawks around.",
               1, "@smile winningly $lname$",
               1, "@jump",
               1, "@stare $lname$",
               1, "@gaze adm $lname$",
          }));
      load_a_chat(30,
         ({
               1, "'Drittsekk!! Ligg unna!",
               1, "'UTLENDINGER, alltid skal dere sloss!",
               1, "'Slapp av litt da, din dritt!",
               1, ":starts to concentrate on the fighting instead of gawking.",
               1, "@gaze with wide innocent eyes $lname$",
          }));
      new("/baseobs/weapons/dagger")->move(this_object());
      this_object()->init_equip();

} /* setup() */
