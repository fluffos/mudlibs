/// Amount of fuel in this fire
int fuel;
/// Burning heat of fuel in this fire. Some things burn hotter than others.
int fuel_strength;
/// If true, this object has been lit.
int lit;

int query_is_burnable() {
   return 1;
}

void set_fuel( int x ) {
   fuel = x;
}

int query_fuel() {
   return fuel;
}

void set_fuel_strength( int x ) {
   fuel_strength = x;
}

int query_fuel_strength() {
   return fuel_strength;
}

int query_lit() {
   if( fuel <= 0 ) lit = 0;
   return lit;
}

void set_lit( int x ) {
   if( x == 0 && lit != 0 )
      this_object()->on_extinguish();
   else if( x != 0 && lit == 0 )
      this_object()->on_ignite();

   lit = x;

   call_out( "heat_contents", 0 );
}

/** Used to add fuel to the fire. Destroys the fuel. If you add non-fuel,
 * it will still destroy the object, but will also dampen the fire.
 *
 * The formula for averaging in the new item's strength is:
 *
 * ((curr_str * curr_fuel) + (ob_str * ob_fuel)) / (curr_fuel + ob_fuel);
 */
void add_fuel( object ob ) {
   int fuel_str, amount;

   fuel_str = ob->query_fuel_strength();
   amount = ob->query_fuel();
   if( !amount ) amount = ob->query_quantity();
   if( !amount ) amount = 1;

   set_fuel_strength( (query_fuel_strength() * query_fuel() + amount * fuel_str) / (query_fuel() + amount) );
   set_fuel( query_fuel() + amount );
   destruct( ob );
}

/** Burns some of the fuel, and returns the temperature emitted. This should
 * be called about every 30 seconds for typical burning.
 */
int burn() {
   if( fuel == 0 )
      return 0;
   fuel--;
   if( fuel == 0 )
      this_object()->on_extinguish();
   return fuel_strength;
}

/** If you want your own handler for burning things, you should
 * override this function. Generally this should do the job, though.
 */
void heat_contents() {
   object ob;
   int burn_temp;

   if( !query_lit() ) return;

   burn_temp = burn();
   if( !burn_temp ) return;

   remove_call_out( "heat_contents" );
   if( query_lit() )
      call_out( "heat_contents", 30 );

   foreach( ob : all_inventory(this_object()) ) {
      ob->on_heat( burn_temp );
      if( ob->add_condition(-query_fuel_strength() / 100) - 1 );
   }
}

void _create_fire() {
   // Make sure that we heat things properly even on restoring the object.
   call_out( "heat_contents", 30 );
}
