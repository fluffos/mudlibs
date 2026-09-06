#include <const.h>
#include <item.h>
#include <desc.h>
#include <saveload.h>
#include <object.h>

NAME( "recipe" )
PLURAL( "recipes" )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 25 )
BULK( 1 )
TASTE( "Owth, a reawwy BAD babercud!" )

void create() {
  ::create();
  set_distant( "a blank recipe" );
  set_specific( "the blank recipe" );
  set_look("It is a blank recipe.");
  set_alt_name( "blank recipe" );
  set_alt_plural( "blank recipes" );
}

string recipe;
void set_recipe(string str) {
   if( RECIPE_DAEMON->query_recipe(str) ) {
      recipe = str;
      set_look("It is a recipe containing details on how to craft '"+str+"'.\n"+
               "If you have the right skills, you can ~CCOMlearn "+str+" from recipe~CDEF if you want to be able to make this item.");
      set_distant("a recipe {"+recipe+"}");
      set_specific("the recipe {"+recipe+"}");
      set_alt_name(recipe+" recipe");
      set_alt_plural(recipe+" recipes");
   } else {
      debug("attempt to create bad recipe "+str);
   }
}

string query_recipe() { return recipe; }

void remove() {
  destruct(this_object());
}

mapping query_aspects() {
   return ([ C_PAPER ]);
}
