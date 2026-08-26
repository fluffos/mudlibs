#include <tasks.h>
inherit OBJECT_OBJ;

int strength;

void set_strength( int number );

void setup() {
   set_name( "snowball" );
   add_alias( "ball" );
   add_adjective( "snow" );
   set_strength( 99 );
   set_heart_beat( 1 );
} /* setup() */

int query_strength() { return strength; }

void set_strength( int number ) { strength = number; }

string long( string word, int dark ) {
   return "This is a "+ ({
      "very small lump of slush",
      "small and rather soggy lump of snow",
      "small snowball",
      "smallish snowball",
      "vaguely small snowball",
      "decent sized snowball",
      "reasonably sized snowball",
      "snowball for throwing at someone",
      "good snowball for throwing at someone",
      "nice, big snowball, just right for throwing at someone"
      })[ strength / 10 ] +".\n";
} /* long() */

void init() {
   TP->add_command("throw", TO, "%D %p %I");
} /* init() */

void heart_beat() {
   strength--;
   if ( strength < 1 ) {
      set_heart_beat( 0 );
      move( "/room/rubbish" );
   }
} /* heart_beat() */

private object find_person(object ob) {
   if (living(ob)) {
      return ob;
   } else {
      while (ob && !living(ob)) {
         ob = environment(ob);
      }

      if (ob) {
         return ob;
      }
   }
   return 0;
} /* find_person() */

int do_throw( object *obs ) {
   object per;
   int chance;

   per = find_person(obs[ 0 ]);
   if (per) {
      // Make it harder if you are aiming at a specific bit rather than
      // the person.
      if (per != obs[ 0 ]) {
         chance = 0;
      } else {
         chance = 30;
      }
      if (per == TP) {
         per->add_effect( "/std/effects/external/snowball", strength );
         add_succeeded_mess( "$N throw$s $D at $I.\n", ({ per }) );
      }
      else {
         switch (TASKER->compare_skills(TP, "fighting.combat.range.thrown",
                 per, "fighting.combat.dodging.range", chance, TM_FREE, TM_FREE)) {
         case OFFAWARD :
            tell_object(TP, "%^YELLOW%^You feel more able to throw "
                                       "snowballs at people.\n%^YELLOW%^");
         case OFFWIN :
            per->add_effect( "/std/effects/external/snowball", strength );
            if (per != obs[ 0 ]) {
               add_succeeded_mess( "$N throw$s $D at $I and hit$s!\n",
                                   ({ obs[ 0 ] }) );
            } else {
               add_succeeded_mess( "$N throw$s $D at $I and hit$s!\n",
                                   ({ obs[ 0 ] }) );
            }
            break;
         case DEFAWARD :
            tell_object(TP, "%^YELLOW%^You feel more able to dodge "
                            "snowballs thrown by people.\n%^YELLOW%^");
         case DEFWIN :
            add_succeeded_mess( "$N throw$s $D at $I and miss$es!\n",
                                   ({ obs[ 0 ] }) );
            break;
         }
      }
   }
   else {
      add_succeeded_mess( "$N throw$s $D at $I.\n", ({ obs[ 0 ] }) );
   }
   move( "/room/rubbish" );
   return 1;
} /* do_throw() */

mapping query_dynamic_auto_load() {
   return ([
      "::" : ::query_dynamic_auto_load(),
      "strength" : strength
   ]);
} /* query_dynamic_auto_load() */

void init_dynamic_arg( mapping map ) {
   ::init_dynamic_arg( map[ "::" ] );
   strength = map[ "strength" ];
} /* init_dynamic_arg() */
