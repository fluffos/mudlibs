#include <object.h>
#include <saveload.h>
#include <coord.h>

/**
 * A marker placed in a particular location to indicate that there is a 'job opening'
 * for the spot. As long as the job is untaken, a suitable NPC will be allowed to fill
 * in for the job, as long as they meet various requirements.
 *
 * The initial version of this will require you to grab a hired worker and have them
 * stop and work somewhere. I intend for this method always to work. Within cities,
 * an additional option will be to simply use the city's local labor market, which
 * will fill the spots automatically. Cities "regenerate" better than independent
 * settlements do.
 *
 * It's possible to have multiple openings for a single job; a good example of this
 * would be a guardhouse, which can hire a variable number of guards depending on the
 * size of the station. Other than the number of spots, another variable is which
 * AI modules will be used to model the worker behavior.
 *
 * A typical way of using this object should look like this:
 *
 * object hire_obj = clone_object( "/obj/work_spot" );
 * hire_obj->set_num_positions( 1 );
 * hire_obj->set_work_ai( ({ "buy", "haggle" }) ); // Can leave out the ({ }) for single AI's.
 * hire_obj->set_work_name( "shopkeeper" );
 * hire_obj->set_home( this_object() );
 */

/// ID for debugging
string query_name() { return "work_spot"; }
object id( string s ) { return s == query_name()?this_object():0; }

/// The number of spots open for hire (default 1)
int num_positions;

/** Object REFERENCES for the people who work here (must survive reboot).
 * Cleared out on reset to handle casualties.
 */
symbol *employees;

/// The name of the job opening.
string work_name;

/** A list of AI's (often only needs one) that are added to the employee when they
 * take on the job.
 */
string *ai_list;

/** Where to set 'home' to. Most AI's need to have a home in order to function.
 */
symbol home;

/// Removes any casualties from the list of employees
void check_employees() {
   employees = filter( employees, (: find_objectref($1) :) );
   // Todo: if positions have opened up, check if we're in a city; if we are,
   // we can advertise the positions and hopefully get workers.
}

/// Set up default values.
void create() {
   ::create();
   num_positions = 1;
   employees = ({ });
   ai_list = ({ });
}

void set_work_ai( string *x )
{
   if( stringp(x) )
      ai_list = ({ x });
   else if( pointerp(x) )
      ai_list = x;
   else raise_error( "Invalid arg to set_work_ai in " + as_string(this_object()) );
}

string *query_work_ai() {
   return ai_list;
}

void set_work_name( string x ) { work_name = x; }
string query_work_name() { return work_name; }

void set_employees( symbol *x ) { employees = x; }
symbol *query_employees() { return employees; }

void set_home( object ob ) { if( !objectp(ob) ) home = 0; else home = to_objectref(ob); }
object query_home() { return find_objectref( home ); }

void add_employee( object ob ) {
   if( !objectp(ob) )
      raise_error( "add_employee called with invalid parameter." );
   if( ob->query_is_player() )
      raise_error( "Player's can't take NPC jobs." );
   symbol obref = to_objectref( ob );
   if( !employees ) employees = ({ });
   employees += ({ obref });
   if( query_home() )
      ob->set_home( query_home() );
}

void remove_employee( mixed ob ) {
   if( !member(employees,ob) >= 0 ) ob = to_objectref(ob);
   employees -= ({ ob });
}

int query_num_employees() {
   if( !employees ) return 0;
   return sizeof(employees);
}

void set_num_positions( int x ) { num_positions = x; }
int query_num_positions() { return num_positions; }

void reset() {
   check_employees();
}

// Attempt to hire ob. Returns true if the hire goes through.
int apply_for_job( object ob ) {
   string ai_name;

   check_employees();
   if( sizeof(query_employees()) >= query_num_positions() )
      return 0;
   add_employee( ob );
   foreach( ai_name : ai_list )
      ob->use_ai_module( ai_name );
   return 1;
}
