/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust.
// Tsath expanded this into metric / imperical system.

private
float mass; // in kilograms internally with 2 decimals. No more.

//: FUNCTION set_mass
// Change the mass of an object
protected
void set_mass(float m)
{
   object env;

   mass = m;
   if (env = environment(this_object()))
      env->update_capacity();
}

//: FUNCTION set_weight
// calls set_mass() for compat reasons
void set_weight(float m)
// ### for back compat
{
   set_mass(m);
}

//: FUNCTION set_lbs_weight
// calls set_mass() for compat reasons
void set_lbs_weight(float m)
// ### for back compat
{
#ifdef METRIC
   set_mass(round(m / KG_TO_LBS * 100) / 100);
#endif
#ifndef METRIC
   set_mass(m);
#endif
}

//: FUNCTION set_kg_weight
// calls set_mass() for compat reasons
void set_kg_weight(float m)
// ### for back compat
{
#ifdef METRIC
   set_mass(m);
#endif
#ifndef METRIC
   set_mass(round(m / LBS_TO_KG * 100) / 100);
#endif
}

//: FUNCTION query_mass
// returns the mass of an object
float query_mass()
{
   return mass;
}

//: FUNCTION set_size
// set_size(s) sets the size of an object to 's'
void set_size(int s)
{
   TBUG("Deprecated: set_size() called in" + this_object());
}
