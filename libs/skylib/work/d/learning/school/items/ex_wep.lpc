/**
* The example weapon for item school
* Jan '02 by Avelan
*/

inherit WEAPON_OBJ;

void setup(){
    set_name("sword");
    set_short("dark sword");
    add_adjective("dark");
    set_long("The blade of this sword is made"
      " of some dark metal which seems to absorb"
      " light.  The hilt is covered with dried "
      " blood.  For some reason, the sword is "
      "warm to the touch.\n");
    set_weight(20);
    set_value(14000);

    new_weapon(5000);

    set_damage_chance(5);

    set_no_limbs(1);

    add_attack("slice", 90, ({ 27, 7, 10 }), "sharp", "sharp",0 );
    add_attack("cut", 90, ({ 10, 5, 50 }), "sharp", "sharp",0 );

} /* setup() */
