/**
 * This command allows players to learn crafting recipes from written
 * documents.
 */
string query_action_name() { return "Learn"; }

int main(string arg) {
   string recipe, object_name, skill;
   object ob;
   mapping details;
   int bad = 0, req;

   if( !arg || sscanf(arg,"%s from %s",recipe,object_name) != 2 )
      return notify_fail("Usage: learn <recipe> from <paper>\n");

   ob = single_present( object_name, this_player() );
   if (!ob) ob = single_present( object_name, environment(this_player()) );
   if( !ob ) {
      //This is counterproductive for alpha, makes it hard to make recipes
      //publicly available. -Malap, 2005-06-05
      //if( single_present( object_name, environment(this_player()) ) )
      //   return notify_fail("You must be carrying the recipe to learn it.\n");
      //else
         return notify_fail("I don't know what you mean by '"+arg+"'.\n");
   }

   if( !(details = RECIPE_DAEMON->query_recipe(recipe)) )
      return notify_fail("There is no such crafting recipe '"+recipe+"'.\n");

   if( recipe != ob->query_recipe() )
      return notify_fail(capitalize(ob->query_name())+" does not contain that recipe.\n");

   if( this_player()->query_recipe(recipe) )
      return notify_fail("You already know that recipe!\n");

   details = details["skills"];
   foreach( skill : m_indices(details) ) {
      req = 25 * (details[skill] / 25);
      if( this_player()->query_skill(skill) < req ) {
         bad = 1;
         msg("You do not have enough ~CTIT"+skill+"~CDEF to learn this recipe.");
      }
   }
   if( bad )
      return notify_fail("Try again after you have practiced your skills.\n");

   this_player()->push_action( ({
                                 1000,
                                 this_object(),
                                 this_player(),
                                 ST_STANDING,
                                 ([ "recipe": recipe, "object": ob ])
                               }) );
   return 1;
}

int query_is_interruptable() { return 1; }
void on_interrupt(mixed action) {
   msg("You will have to start learning this recipe over again.");
}

void on_action(object target, mixed param) {
   set_actor(this_player());
   set_target(param["object"]);

   this_player()->add_readiness(-750);

   if( param["done"] ) {
      this_player()->msg_local("~CACT~Name ~verbfinish studying ~targ.~CDEF");
      msg("You now know the ~CEMO"+param["recipe"]+"~CDEF recipe.");
      this_player()->add_recipe(param["recipe"]);
   } else {
      this_player()->msg_local("~CACT~Name ~verbbegin to study ~targ.~CDEF");
      this_player()->set_action( -1, ({
                                       1000,
                                       this_object(),
                                       this_player(),
                                       ST_STANDING,
                                       param + (["done":1])
                                     }) );
   }
}
