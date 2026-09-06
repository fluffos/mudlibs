inherit "/obj/monster";
#include <script.h>

NAME( "creature" )
LOOK( "A small, furry creature. Its purpose in life is to be killed. ~Pron is $(HP)." )
DISTANT( "a creature" )
SPECIFIC( "the creature" )
ALT_PLURAL( ({ "creatures" }) )
TYPE( "monster" )
ALT_NAME( ({ "monster" }) )
WEIGHT( 68000 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_level( 3 );
   set_gender( 1 );
   set_spd( 8 );
   set_con( 12 );
   set_str( 9 );
   set_dex( 10 );
   set_wil( 7 );
   set_cha( 5 );
   set_int( 5 );
   set_emp( 5 );
   set_hp( 85 );
   set_race( "rodent" );

   clone_object("/ai/fight")->move(this_object());
}

ScriptBegin
   Script( "b" )
      Say( "b" )
      Delay(6)
   End
   Script( "abc" )
      Say( "a" )
      Delay(6)
      Gosub( "b" )
      Say( "c" )
      Delay(6)
   End
   Script( "bc" )
      Say( "bc" )
      Delay(6)
      Abort
      Say( "e" )
   End
   Script( "abcd" )
      Say( "a" )
      Delay(1)
      Gosub( "bc" )
      Say( "d" )
      Delay(1)
   End
End