#include <object.h>
#include <coord.h>

/** A lair is where monsters spawn, and is also where they go to hang around
 * if they're not hungry and have nothing else to do.
 */

string animal_type;

string query_animal_type() {
   return animal_type;
}

void set_animal_type( string x ) {
   animal_type = x;
}

void on_exit( object who ) {
   who->move( environment(this_object() );
   who->set_coord( query_coord() );
   who->msg_local( "~Name ~verbcome out of ~poss lair." );
}

void reset() {
   // Used to do 'breed' on the reset; I'm shifting that down because we're tweaking
   // what lairs do right now.
}

void breed() {
   object ob, male, female;
   ::reset();

   // See if a well-fed male and female are present...
   male = female = 0;

   foreach( ob : all_inventory() ) {
      switch( ob->query_gender() ) {
         case 1: if( ob->query_food_percent() > 60 ) {
               if( !male || male->query_food() < ob->query_food() )
                  male = ob;
            }
            break;
         case 2: if( ob->query_food_percent() > 70 ) {
               if( !female || female->query_food() < ob->query_food() )
                  female = ob;
            }
            break;
      }
   }

   if( male && female ) {
      male->add_food( -male->query_max_food() / 10 );
      female->add_food( -female->query_max_food() / 40 );
      ob = clone_object( animal_type );
      ob->move(this_object());
      // Zarylse: Genetics goes here! Make "ob" into a cross
      // between "male" and "female".
   }
}

int query_is_lair() {
   return 1;
}
