/*
 * The basic human type race. No disadvantages, no advantages. I don't
 * want this to be another mud where the automatic choice of human
 * is the best one. That said, roll on the Delsan!
 * Shiannar.
 */

inherit "/std/races/humanoid";

void setup() {
   set_long("The Delsan race.  The standard by which all the races are set, "+
           "this is race can be considered the norm.\n");
   set_name("delsan");
   set_weight(1600);
   set_height(175);
   add_ac( "blunt", "blunt", 3 );
   add_ac( "pierce", "pierce", 2 );
   add_ac( "sharp", "sharp", 2 );
   set_sight( ({ 5, 20, 200, 300 }) );
   set_stats( ({ 1, 0, -1, 1, -1 }) );  //Strong and hearty, but docile and dumb.
}

string query_desc( object thing ) {
  return CAP(thing->HE)+" stands tall and proud, and looks to be of strong "
     "build and hearty constitution.  "+CAP(thing->HE)+" is obviously one "
     "of the Delsan.\n";
} /* query_desc() */

void set_unarmed_attacks( object thing ) {
   int number;
   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->add_attack( "hands", 75, ({ 2 * number, 8, number }), "blunt",
         "unarmed", "unarmed_hands" );
   thing->add_attack( "feet", 25, ({ 3 * number, 11, number }), "blunt",
         "unarmed", 0 );
} /* set_unarmed_attacks() */

string temperature_effects(object thing, int temperature) {
  string temperature_str;

  // let creators survive whatever the weather :)
  // Shaydz - 10/03/01
  
  if(creatorp(thing) && thing->query_property("always warm"))
      return "";
        
  switch(temperature/3) {
  case 106 .. 1000:
    thing->dest_hide_shadow();
    tell_object( thing, "The heat is just too much for you.\n" );
    tell_room( environment( thing ), "Sweating profusely and turning "
               "a nasty red-purple colour "+
               (string)thing->the_short() +" expires.\n", thing );
    thing->do_death();
    temperature_str = "";
    break;
  case 86 .. 105:
    temperature_str = "close to death from extreme heatstroke";
    thing->adjust_tmp_wis(-1);
    thing->adjust_tmp_int(-1);
    break;
  case 56 .. 85:
    temperature_str = "sick from heatstroke";
    if(!random(2))
      thing->adjust_tmp_wis(-1);
    if(!random(2))
      thing->adjust_tmp_int(-1);
    break;
  case 26 .. 55:
    temperature_str = "very hot";
    tell_object(thing, "You feel really hot.\n");
    break;
  case 16 .. 25:
    temperature_str = "rather warm";
    tell_object(thing, "You feel quite warm.\n");
    break;
  case -5 .. 15:
    temperature_str = "";
    break;
  case -15 .. -6 :
    temperature_str = "rather cold";
    tell_object(thing, "You feel quite cold.\n");
    break;
  case -45 .. -16 :
    temperature_str = "very cold";
    tell_object(thing, "You feel cold to your bones.\n");
    break;
  case -75 .. -46 :
    temperature_str = "sick from hypothermia";
    tell_object(thing, "You're so cold you feel your energy being drained.\n");
    if(!random(2))
      thing->adjust_tmp_str(-1);
    if(!random(2))
      thing->adjust_tmp_con(-1);
    break;
  case -95 .. -76 :
    temperature_str = "close to death from extreme hypothermia";
    tell_object(thing, "You're so cold you feel as though you're about to "
                "expire.\n");
    thing->adjust_tmp_str(-1);
    thing->adjust_tmp_con(-1);
    break;
  case -1000 .. -96:
    thing->dest_hide_shadow();
    tell_object( thing, "The cold is just too much for you.\n" );
    tell_room( environment( thing ), "Frost riming "+
               (string)thing->query_possessive() +" skin in a thick crust, "+
               (string)thing->the_short() +" expires.\n", thing );
    thing->do_death();
    temperature_str = "";
    break;
  }

  if(temperature /5 >  11) {
    thing->new_parser("sweat");
    thing->add_effect("/std/effects/other/wetness",
                      temperature);
  } else if(temperature/5 < -10) {
    thing->new_parser("shiver");

    if(temperature < -30 && !random(250))
      thing->add_effect( "/std/effects/disease/common_cold",
                         -(temperature*10));
  }

  return temperature_str;
}
