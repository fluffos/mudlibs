inherit "/obj/monster";

int ataque=0;

void event_fight_in_progress(object ob1, object ob2)
{
   if (ob1->query_name()=="jermlaine")
           call_out("atacar", random(3), ob2);
   
   else if (ob2->query_name()=="jermlaine")
        call_out("atacar", random(3), ob1);
   
   ::event_fight_in_progress(ob1, ob2);
}

void atacar(object quien)
{
   if (!ataque)
   {
      do_command("'whoroi wioie hepe. \n");
      ataque=1;
   }
   attack_ob(quien);
}

void setup()
  {
   set_name("jermlaine");
   set_short("jermlaine");
   set_long("      Ves a un diminuto humano vestido con una extranya ropa y unos "
            "extranyos cascos en realidad la ropa es su propia y colgante piel y "
            "el casco su puntiguda cabeza. Su cuerpo esta nudosamente musculado.\n");
   set_main_plural("jermlaines");
   set_guild("fighter");
   set_guild_ob("/std/guilds/warriors/fighter");
   set_gender(1);
   set_random_stats(9,18); 
   set_max_hp(this_object()->query_hp()+roll(4,4));
   set_wimpy(80);
   
set_level(roll(2,2));
   add_move_zone("nivel2");

}
