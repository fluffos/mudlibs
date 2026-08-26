/**
 * The Phaerin race. Playable. Extra wis and int, less con and dex.
 */

inherit "/std/races/humanoid";

void setup() {
   set_long("The Phaerin race.  Intelligent and wise.\n");
   set_name("phaerin");
   set_weight(1400);
   set_height(180);
   add_ac( "blunt", "blunt", 3 );
   add_ac( "pierce", "pierce", 2 );
   add_ac( "sharp", "sharp", 2 );
   set_sight( ({ 5, 20, 200, 300 }) );
   set_stats( ({ -1, -1, 1, 0, 1 }) );
}

string query_desc( object thing ) {
  return CAP(thing->HE)+" stands tall and thin, "+thing->HIS+" willowy "
         "form shows that "+thing->HE+" is one of the Phaerin.\n";
} /* query_desc() */

void set_unarmed_attacks( object thing ) {
   int number;
   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->add_attack( "hands", 75, ({ 2 * number, 8, number }), "blunt",
         "unarmed", "unarmed_hands" );
   thing->add_attack( "feet", 25, ({ 3 * number, 10, number }), "blunt",
         "unarmed", 0 );
} /* set_unarmed_attacks() */

string temperature_effects(object thing, int temperature) {
  string temperature_str;

  // let creators survive whatever the weather :)
  // Shaydz - 10/03/01
  
  if(creatorp(thing) && thing->query_property("always warm"))
      return "";
        
  switch(temperature/3) {
  case 101 .. 1000:
    thing->dest_hide_shadow();
    tell_object( thing, "The heat is just too much for you.\n" );
    tell_room( environment( thing ), "Sweating profusely and turning "
               "a nasty red-purple colour "+
               (string)thing->the_short() +" expires.\n", thing );
    thing->do_death();
    temperature_str = "";
    break;
  case 81 .. 100:
    temperature_str = "close to death from extreme heatstroke";
    thing->adjust_tmp_wis(-1);
    thing->adjust_tmp_int(-1);
    break;
  case 51 .. 80:
    temperature_str = "sick from heatstroke";
    if(!random(2))
      thing->adjust_tmp_wis(-1);
    if(!random(2))
      thing->adjust_tmp_int(-1);
    break;
  case 21 .. 50:
    temperature_str = "very hot";
    tell_object(thing, "You feel really hot.\n");
    break;
  case 11 .. 20:
    temperature_str = "rather warm";
    tell_object(thing, "You feel quite warm.\n");
    break;
  case -10 .. 10:
    temperature_str = "";
    break;
  case -20 .. -11 :
    temperature_str = "rather cold";
    tell_object(thing, "You feel quite cold.\n");
    break;
  case -50 .. -21 :
    temperature_str = "very cold";
    tell_object(thing, "You feel cold to your bones.\n");
    break;
  case -80 .. -51 :
    temperature_str = "sick from hypothermia";
    tell_object(thing, "You're so cold you feel your energy being drained.\n");
    if(!random(2))
      thing->adjust_tmp_str(-1);
    if(!random(2))
      thing->adjust_tmp_con(-1);
    break;
  case -100 .. -81 :
    temperature_str = "close to death from extreme hypothermia";
    tell_object(thing, "You're so cold you feel as though you're about to "
                "expire.\n");
    thing->adjust_tmp_str(-1);
    thing->adjust_tmp_con(-1);
    break;
  case -1000 .. -101:
    thing->dest_hide_shadow();
    tell_object( thing, "The cold is just too much for you.\n" );
    tell_room( environment( thing ), "Frost riming "+
               (string)thing->query_possessive() +" skin in a thick crust, "+
               (string)thing->the_short() +" expires.\n", thing );
    thing->do_death();
    temperature_str = "";
    break;
  }

  if(temperature /5 >  10) {
    thing->new_parser("sweat");
    thing->add_effect("/std/effects/other/wetness",
                      temperature);
  } else if(temperature/5 < -10) {
    thing->new_parser("shiver");

/*  They don't catch colds.
    if(temperature < -30 && !random(250))
      thing->add_effect( "/std/effects/disease/common_cold",
                         -(temperature*10));
*/
  }

  return temperature_str;
}
