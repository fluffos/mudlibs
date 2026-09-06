inherit "/obj/scenery";
#include <container.h>
#include <item.h>

NAME( "burn barrel" )
SPECIFIC( "the burn barrel" )
DISTANT( "a burn barrel" )
LOOK( "The burn barrel contains anything you put in it.  Perhaps you can ~CCOMuse~CDEF it." )
ALT_NAME( ({"barrel", "burn barrel"}) )
GETTABLE(0)
DROPPABLE(0)

int burning;

void create() {
   ::create();
/* OBJEDIT { */
   set_phrase( "There is a burn barrel ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_paint( object painter ) { }

void on_map_paint( object painter ) {
   painter->paint( query_x(), query_y(), 'U', 0x03, LAYER_ITEMS );
}

void on_insert( object ob ) {
   if( ob->query_no_junk() ) {
      ob->move( environment(this_object()) );
      tell_room( environment(this_object()),
               "The burn barrel spits out " + ob->query_distant() + ".\n" );
   }
}

void heart_beat() {
   tell_room(environment(), "The burn barrel glows dull red as acrid smoke billows out of it.\n");

   for(int quota = 20; quota > 0; quota--) {
      object *obs = all_inventory(this_object());

      if (sizeof(obs)) {
         object ob = obs[ random( sizeof(obs) ) ];
         debug("Incinerating" + object_name(ob), "gp");
         destruct(ob);
      } else {
         tell_room(environment(), "The burn barrel goes out and the smoke dissipates.\n" );
         set_heart_beat(0);
         burning = -1;
         return;
      }
   }
}

int on_use( object who ) {

   switch(burning) {
   case 0:
      this_player()->msg_local("~Name ~verbignite the burn barrel, and the contents start smoking.");
      burning = 1;
      set_heart_beat(1);
      break;
   case 1:
      this_player()->msg_local("~Name ~verbextinguish the burn barrel, and the smoke dissipates.");
      burning = -1;
      set_heart_beat(0);
      break;
   case -1:
      this_player()->msg_local("~Name ~verbclean the ash out of the burn barrel.");
      burning = 0;
      break;
   }

   return 1;
}
