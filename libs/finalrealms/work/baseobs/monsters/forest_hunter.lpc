
inherit "/obj/monster";

void setup()
  {
  set_name("hunter");
  set_short("hunter");
  add_alias("hunter");
  set_long("Just a forest hunter.\n");
  set_main_plural("hunters");
  set_gender(1);
  set_race("half-orc");
//set_class("fighter");
  set_random_stats(6,18); //will set radom between 6 & 18.. for all stats..
  set_str(random(13)+6);
  set_level(random(10)+5); 
  set_al(random(200)-100);
  set_wimpy(0);
  if(random(2)) new("/baseobs/weapons/short_sword")->move(this_object());
  if(random(2)) new("/baseobs/armours/leather")->move(this_object());
  this_object()->init_equip();
  load_chat(10,
      ({
            1, "@search",
            1, "@grunt",
            1, "'These forests are MY hunting grounds!",
            1, "'I hope you haven't come for a deer-hunt.",
            1, "'What are you doing here ?"
       }));
  load_a_chat(30,
      ({
            1, "'Get outta here!",
            1, "@spit $lname$",
            1, "'Ughh!",
            1, "@drool"
       }));

  /* Money? maybe.. */ 
  adjust_money(random(70), "copper");
} /* setup */
