/**
* The cape of the womble
* Based heavily on Micael's doublemail_byrnie
* (Yes, i'm lazy, you all know that =P )
* Jan '02 by Avelan
*/

inherit ARMOUR_OBJ;

void setup() {

    /*
    * These work exactly like the ones in npc's
    * and rooms.
    */
    set_name("cape");
    set_short("cape");
    add_adjective("red");
    add_alias("red cape");
    set_main_plural("red capes");

    set_long("This cape is plain with no symbols or"
      " ornaments on it.  It is obviously meant to act as "
      " an example for the creator school.\n");

    /*
    * This is needed so the armour handler knows
    * which slots this armour takes.
    * There are a lot of different types,
    * You can see a list if you do:
    * 'exec return CLOTHING_H->query_all_clothing_types();'
    */
    set_type("cape");
    set_weight(50);
    /*
    * This determines how much damage the cape can
    * take before it breaks.
    */
    setup_armour(5000);
    set_value(12000);
    /*
    * The chance the cape will take damage when
    * hit.
    */
    set_damage_chance(10);

    /*
    * How much protection the cape gives against certain
    * damage types.
    */
    add_ac("sharp", "sharp", 90 );
    add_ac("blunt", "blunt", 40 );
    add_ac("pierce", "pierce", 60 );

} /* setup() */
