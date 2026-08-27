
inherit "/obj/monster";


void setup()
  {
  set_name("hermit");
  set_short("Hermit");
  add_alias("man");
  set_long("This is a loner that wander around in the forest.\n");
  set_main_plural("hermits");
  set_gender(1);
  set_race("human");
  set_random_stats(6,18); //will set radom between 6 & 18.. for all stats..
  set_level(random(7)+3); 
  set_al(-10);
  set_wimpy(10);

  if(random(2)) new("/baseobs/weapons/quarterstaff")->move(this_object());
//  new("/baseobs/armours/leather")->move(this_object());
  this_object()->init_equip();

  
  /* Money? maybe.. */
  adjust_money(random(100), "copper");
} /* setup */
