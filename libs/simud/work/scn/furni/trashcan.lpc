inherit "/obj/scenery";
#include <container.h>
#include <item.h>

NAME( "trashcan" )
SPECIFIC( "the trashcan" )
DISTANT( "a trashcan" )
LOOK( "The trashcan contains anything you put in it.  Perhaps you can ~CCOMuse~CDEF it." )
ALT_NAME( ({"can", "trash can"}) )
GETTABLE(0)
DROPPABLE(0)

void create() {
   ::create();
/* OBJEDIT { */
   set_phrase( "There is a trashcan ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_paint( object painter ) { }

void on_map_paint( object painter ) {
   painter->paint( query_x(), query_y(), 'U', 7, LAYER_ITEMS );
}

void on_insert( object ob ) {
   if( ob->query_no_junk() || this_object()->query_held_weight() > 20000 ) {
      ob->move( environment(this_object()) );
      tell_room( environment(this_object()),
               "The trashcan spits out " + ob->query_distant() + ".\n" );
   }
}

int on_use( object who ) {
   object ob, bag;
   int weight = this_object()->query_held_weight();

   foreach( ob : all_inventory() )
      destruct(ob);

   bag = clone_object("/items/trashbag");
   bag->set_weight(weight);
   bag->move(this_player());

   this_player()->msg_local("~CACT~Name ~verbtake the trashbag out of the trashcan, and ~verbput a new bag in the trashcan.~CDEF");

   return 1;
}
