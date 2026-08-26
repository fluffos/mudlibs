/*
 * The Morgol, a partly insectoid race.
 * Shiannar, 26/12/01.
 */

inherit "/std/races/humanoid";

void setup() {
   set_long("The Morgol race.  Partly insectoid, they came to this "
            "world during the sundering.\n");
   set_name("morgol");
   set_weight(2000);
   set_height(160);
   add_ac( "blunt", "blunt", ({ 5, 5 }) );
   add_ac( "pierce", "pierce", ({ 5, 10 }) );
   add_ac( "sharp", "sharp", ({ 5, 10 }) );
   add_ac( "fire", "fire", ({ 0, 2, 4 }) );  //Due to their shell, they have
                                             //some resistance.
   set_sight( ({ 5, 20, 200, 300 }) );
   set_stats( ({ 1, -1, -1, 1, 0 }) );
}

string query_desc( object thing ) {
  return CAP(thing->HE)+" is a young Morgol, safely enconsed in "+
     thing->HIS+" armoured shell.\n";
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
  case 0 .. 15:
    temperature_str = "";
    break;
  case -10 .. -1 :
    temperature_str = "rather cold";
    tell_object(thing, "You feel quite cold.\n");
    break;
  case -40 .. -11 :
    temperature_str = "very cold";
    tell_object(thing, "You feel cold to your bones.\n");
    break;
  case -70 .. -41 :
    temperature_str = "sick from hypothermia";
    tell_object(thing, "You're so cold you feel your energy being drained.\n");
    if(!random(2))
      thing->adjust_tmp_str(-1);
    if(!random(2))
      thing->adjust_tmp_con(-1);
    break;
  case -90 .. -71 :
    temperature_str = "close to death from extreme hypothermia";
    tell_object(thing, "You're so cold you feel as though you're about to "
                "expire.\n");
    thing->adjust_tmp_str(-1);
    thing->adjust_tmp_con(-1);
    break;
  case -1000 .. -91:
    thing->dest_hide_shadow();
    tell_object( thing, "The cold is just too much for you.\n" );
    tell_room( environment( thing ), "Frost riming "+
               (string)thing->query_possessive() +" skin in a thick crust, "+
               (string)thing->the_short() +" expires.\n", thing );
    thing->do_death();
    temperature_str = "";
    break;
  }

/*

Would a unique alien physiology sweat or get colds?
Life might be tough without sweating...?
  if(temperature /5 >  10) {
    thing->new_parser("sweat");
    thing->add_effect("/std/effects/other/wetness",
                      temperature);
  } else if(temperature/5 < -10) {
    thing->new_parser("shiver");

    if(temperature < -30 && !random(250))
      thing->add_effect( "/std/effects/disease/common_cold",
                         -(temperature*10));
  }
*/

  return temperature_str;
}
