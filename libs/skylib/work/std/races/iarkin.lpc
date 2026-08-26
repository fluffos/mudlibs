/*
 * The Iarkin, human, but dwelling underground. Good eyesite in the dark,
 * like colder temperatures than the Delsan.
 */

inherit "/std/races/humanoid";

void setup() {
   set_long("The Iarkin race.  Close to Delsan normal, though with "
            "some important differences.\n");
   set_name("iarkin");
   set_weight(1400);
   set_height(160);
   add_ac( "blunt", "blunt", 3 );
   add_ac( "pierce", "pierce", 2 );
   add_ac( "sharp", "sharp", 2 );
   set_sight( ({ 0, 10, 150, 250 }) );
   set_stats( ({ -1, 0, 0, 1, 0 }) );
}

string query_desc( object thing ) {
  return CAP(thing->HE)+" walks with a slight stoop and the pallor "
     "characteristic of the Iarkin.\n";
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
  case 96 .. 1000:
    thing->dest_hide_shadow();
    tell_object( thing, "The heat is just too much for you.\n" );
    tell_room( environment( thing ), "Sweating profusely and turning "
               "a nasty red-purple colour "+
               (string)thing->the_short() +" expires.\n", thing );
    thing->do_death();
    temperature_str = "";
    break;
  case 76 .. 95:
    temperature_str = "close to death from extreme heatstroke";
    thing->adjust_tmp_wis(-1);
    thing->adjust_tmp_int(-1);
    break;
  case 46 .. 75:
    temperature_str = "sick from heatstroke";
    if(!random(2))
      thing->adjust_tmp_wis(-1);
    if(!random(2))
      thing->adjust_tmp_int(-1);
    break;
  case 16 .. 45:
    temperature_str = "very hot";
    tell_object(thing, "You feel really hot.\n");
    break;
  case 6 .. 15:
    temperature_str = "rather warm";
    tell_object(thing, "You feel quite warm.\n");
    break;
  case -15 .. 5:
    temperature_str = "";
    break;
  case -25 .. -16 :
    temperature_str = "rather cold";
    tell_object(thing, "You feel quite cold.\n");
    break;
  case -55 .. -26 :
    temperature_str = "very cold";
    tell_object(thing, "You feel cold to your bones.\n");
    break;
  case -85 .. -56 :
    temperature_str = "sick from hypothermia";
    tell_object(thing, "You're so cold you feel your energy being drained.\n");
    if(!random(2))
      thing->adjust_tmp_str(-1);
    if(!random(2))
      thing->adjust_tmp_con(-1);
    break;
  case -105 .. -86 :
    temperature_str = "close to death from extreme hypothermia";
    tell_object(thing, "You're so cold you feel as though you're about to "
                "expire.\n");
    thing->adjust_tmp_str(-1);
    thing->adjust_tmp_con(-1);
    break;
  case -1000 .. -106:
    thing->dest_hide_shadow();
    tell_object( thing, "The cold is just too much for you.\n" );
    tell_room( environment( thing ), "Frost riming "+
               (string)thing->query_possessive() +" skin in a thick crust, "+
               (string)thing->the_short() +" expires.\n", thing );
    thing->do_death();
    temperature_str = "";
    break;
  }

  if(temperature /5 >  9) {
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
