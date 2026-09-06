#include <item.h>
#include <desc.h>
#include <object.h>
// add quantity support later, right now, i'm too lazy
//#include <quantity.h>

ICON( '*', 11, LAYER_ITEMS )
ALT_PLURAL( ({"dice"}) )
WEIGHT( 50 )
BULK( 50 )
GETTABLE( 1 )
DROPPABLE( 1 )
TASTE( "It tastes... vaguely unreliable" )

int num_sides;

void set_num_sides(int x) {
   if (x < 4 || x > 20)
     return;
   num_sides = x;
   set_distant( "a "+num_sides+"-sided die" );
   set_look( "It is a "+(x==6?"simple ":"")+"wooden 6-sided die. You could "+
             "probably ~CBRTroll~CDEF it if you wanted to." );
   set_alt_name( ({"d"+num_sides,"die"}) );
   set_name(num_sides+"-sided die");
   set_specific(query_name());
   set_plural(num_sides+"-sided dice");
}

void create() {
   ::create();
   set_num_sides(6);
}

void init() {
   ::init();
   add_action("on_roll","roll");
}

int on_roll(string args) {
   object die, *dice = all_present(args, this_player());
   int total, roll;
   foreach ( die : dice ) {
      roll = die->do_roll();
      if (!roll)
         continue;
      set_actor(this_player());
      this_player()->msg_local("~CACT~Name ~verbroll "+die->query_distant()+" and ~verbget a "+roll+".~CDEF");
      if (sizeof(dice) == 1) {
         return 1;
      } else {
         total += roll;
      }
   }
   if (total) {
      this_player()->msg_local("~CTITThe dice total up to "+total+".~CDEF");
      return 1;
   } else {
      return 0;
   }
}

int do_roll() {
   return 1 + random(num_sides);
}

mapping query_aspects() {
   return ([ C_WOOD ]);
}
