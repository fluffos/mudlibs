/*  the Vampire */
/*    Archana   */
/*    12/12/99  */
/*  several things that all vampires
    should have are they should disintegrate
    into ash when killed. and if they are outdoors
    they should turn into mist or something else and run off
    however since these things will not work in the race itself
    they have to be placed in the npc's file  */

#include <weather.h>
#define SHADOW "/std/races/shadows/vamp_race"
#define BITE_EFFECT "/d/ram/Uberwald_dev/effects/vamp"

inherit "/std/races/humanoid";

void setup() {
   set_long("a vampire with sharp pointy teeth\n");
   set_name("vampire");
   set_weight(3000);
   set_height(250);
   set_desc( "a blood sucking monster");
   add_ac( "blunt", "blunt", 3 );
   add_ac( "pierce", "pierce", 2 );
   add_ac( "sharp", "sharp", 2 );
   set_sight( ({ 5, 20, 200, 300 }) );
   set_stats( ({ 13, 15, 9, 13, 0 }) );

}/* setup() */
void start_player( object thing ) {
   ::start_player( thing );
   clone_object( SHADOW )->setup_shadow( thing );
} /* start_player() */

void set_unarmed_attacks( object thing ) {
   thing->remove_attack( "claws" );
   thing->remove_attack( "bite" );
   thing->add_attack( "claws", 75, ({ 32, 5, 15 }),
       "sharp", "unarmed", 0 );
   thing->add_attack("bite", 30, ({20, 20, 30}),
       "pierce", "unarmed", ({"vamp_bite", this_object()}));

} /* set_unarmed_attacks() */

void vamp_bite( int damage, object him, object me, string a_type,string a_name ) {
   tell_room( ENV(me), me->one_short()+" viciously drives "+me->HIS+" fangs "
       "into "+him->poss_short() + " throat who screams in agony!\n", ({ him }) );
   tell_object( him, me->one_short()+" sinks "+me->HIS+" fangs into you!  You "
       "nearly collapse in blood loss.\n" );

   him->add_effect( BITE_EFFECT, 300 );

} /* vamp() */