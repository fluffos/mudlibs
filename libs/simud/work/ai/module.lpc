#include <object.h>
#include <script.h>

int priority = 1, enabled = 0;

void on_death( object what ) {
   if( what == environment() && what->query_env_var("immortal") != 1 )
      destruct(this_object());
}

int query_enabled() {
   return enabled;
}

int query_priority() {
   return priority;
}

void set_priority( int x ) {
   priority = x;
   if( environment() ) environment()->update_modules();
}

string query_module_name() {
   string *s = explode( load_name(), "/" );
   return s[<1];
}

string query_name() {
   return "_ai_" + query_module_name();
}

object id( string param ) {
   if( param == "_ai_" + query_module_name() ) return this_object();
   return 0;
}

int query_is_ai_module() {
   return 1;
}

void enable() {
   enabled = 1;
}

void disable() {
   enabled = 0;
}

void on_move( object src ) {
   if( src ) src->remove_ai_module( this_object() );
   environment()->add_ai_module( this_object() );
   if( !environment()->query_is_living() )
      destruct(this_object());
   else
      call_out("setup", 0);
}

void _destructor_module( object src ) {
   if( environment() ) environment()->remove_ai_module(this_object());
}

void say( string s ) {
   command( "say " + s, environment() );
}

void emote( string s ) {
   command( "emote " + s, environment() );
}

/// Call out to perform a command
void delay_command(string cmd, int delay) {
   // nix debug spam
   // - gpfault
        //command("say delay_command: "+cmd+", "+delay, environment());
        call_out("execute_delayed_command",delay,cmd);
}
void execute_delayed_command(string cmd) {
        command("say execute_delayed_command: "+cmd, environment());
        command(cmd, environment());
}

object *find_food( object where ) {
   return filter( all_inventory(where), (: $1->query_is_edible() :) );
}

/** If where isn't specified, then it'll look for the larder in the AI's
 * home. If it is specified, it looks for a larder inside the given room.
 * If more than one larder is available, a random one is picked. Searching
 * home for a larder can be expensive, and this function doesn't currently
 * cache.
 */
varargs object find_larder( object where ) {
   object *larders;
   if( where ) {
      larders = filter( all_inventory(where), (: $1->query_is_larder() :) );
      if( sizeof(larders) ) return larders[random(sizeof(larders))];
      return 0;
   }
   object home = environment()->query_home();
   if( !home ) return 0;
   larders = filter( deep_inventory(home), (: $1->query_is_larder() :) );
   if( sizeof(larders) ) return larders[random(sizeof(larders))];
}

void eat_food_in_inventory() {
   environment()->push_action( ({ 1000, "/bin/eat", environment(), ST_STANDING | ST_SITTING | ST_LYING | ST_CROUCHING, ({ find_food(environment()), 1 }) }) );
}

object my_room() {
   if( environment() && environment(environment()) )
      return environment(environment());
}

object my_area() {
   object *envs = all_environment();
   if( !envs ) return 0;
   while( sizeof(envs) ) {
      if( envs[<1]->query_is_area() )
         return envs[<1];
      envs = envs[..<2];
   }
   return 0;
}

int query_hour() {
   return "/daemon/time"->query_hour();
}

int at_home() {
   return member( all_environment(environment()), environment()->query_home() ) != -1;
}

object home_room( string name ) {
   object home = environment()->query_home();
   if( !home )
      return 0;
   return present( name, home );
}
