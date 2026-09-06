#include <const.h>

string query_action_name() { return "Craft"; }

int main( string param ) {
   int reps, count, i;
   string item, ingredients, container;
   string *args;
   object *obs, cobj;
   mapping recipe;

   if( !param ) {
      notify_fail("What do you want to craft?\n");
      return 0;
   }

   reps = 0;
   if( sscanf(param, "%d %s", reps, item) != 2 ) {
      reps = 1;
      item = param;
   }

   if( !reps )
      reps = 1;

   if( reps <= 0 || reps > 20 ) {
      notify_fail("You can only craft 1-20 items at a time.\n");
      return 0;
   }

   // parse input string
   args = regexplode( item, " using | into " );
   // extract recipe name from head
   item = args[0];
   args = args[1..];
   // validate remaining parameters
   if( sizeof(args)%2 ) {
      notify_fail("Something went wrong parsing '"+param+"':\n"+
                  as_lpc(args)+"\n");
      return 0;
   }
   // pick out container, ingredients
   if( (i = member(args, " into ")) != -1 )
      container = trim(args[i+1]);
   if( (i = member(args, " using ")) != -1 )
      ingredients = trim(args[i+1]);

   // locate container object
   if( container ) {
      cobj = single_present(container, this_player());
	  if( !cobj || !cobj->query_container() )
         return notify_fail("I can't find any such container '"+container+"'\n");
   }
   else cobj = 0;

   // locate specified ingredients
   if( ingredients ) {
      obs = all_present(ingredients, this_player());
      if( !obs ) {
         notify_fail("I can't find '"+ingredients+"'\n");
         return 0;
      }
      msg( "Available ingredients: " + inventory_string(obs) );
   }
   else obs = 0;

   if ( !(recipe = "/daemon/recipe"->query_recipe(item)) ) {
      notify_fail("There is no such recipe.\n");
      return 0;
   }

   if( !this_player()->query_recipe(item) )
      return notify_fail("You do not know that recipe.\n");

   // impose arbitrary 50 item crafting limit - Al - Sept, 1 '04
   if ( !mappingp(this_player()->query_env_var("crafting_cap")) )
      this_player()->set_env_var( "crafting_cap",([]) );
   count = this_player()->query_env_var("crafting_cap")[item];
   if ( count + reps > 50 ) {
      reps = 50 - count;
      if ( reps > 0 )
         msg("~CWRNSorry, you are only able to attempt to craft ~CBRT"+reps+"~CWRN more of this item for a while.~CDEF");
      else {
         msg("~CWRNSorry, you've made (or at least tried to make) too many of these recently, take a break or make something else for a while, eh?~CDEF");
         return 1;
      }
   }

   // make sure liquids specify a container, we can check it further later
   if( recipe["liquid"] && !container ) {
      msg("~CWRNSorry, but you'll need to tell me what container you plan on putting your finished product ~CBRTinto~CWRN.~CDEF");
      return 1;
   } else if( !recipe["liquid"] && container ) {
      msg("~CWRNSilly, you don't need to specify a container for this recipe.~CDEF");
   }

   WALK_ACTION_PARAM( 1250, this_player(), ({ item, obs, cobj, reps }) );

   return 1;
}

int on_action(object target, mixed param) {
   string item = param[0];
   object *obs = param[1];
   object cobj = param[2];
   int x, reps = param[3];
   mapping count = this_player()->query_env_var("crafting_cap");
   for (x = 0; x < reps; x++) {
      if( !"/daemon/recipe"->craft(item, obs, cobj) ) {
         msg("You can't craft that.");
	     return 1;
      } else {
         // count items crafted toward limit
         count[item]++;
         this_player()->set_env_var("crafting_cap",count);
         // require readiness, of course
         this_player()->add_readiness(-250);
         // break it into multiple actions if need be
         if (x+1 < reps && this_player()->query_readiness() < 500) {
            WALK_ACTION_PARAM( 1000, this_player(), ({ item, obs, cobj, reps - x - 1 }) );
            return 1;
         }
      }
   }
   return 1;
}
